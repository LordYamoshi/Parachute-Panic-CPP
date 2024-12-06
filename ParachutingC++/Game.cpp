#include "Game.h"

Game* gameInstance = nullptr;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int PLAYER_START_X = 375;
const int PLAYER_START_Y = 550;
const int MAX_ENNEMIES = 3;
const int SCORE_TEXT_SIZE = 24;
const int LIVES_TEXT_SIZE = 24;
const int BULLET_TEXT_SIZE = 24;
const int GAME_OVER_TEXT_SIZE = 48;
const int SCORE_TEXT_X = 10;
const int SCORE_TEXT_Y = 10;
const int LIVES_TEXT_X = 10;
const int LIVES_TEXT_Y = 30;
const int BULLET_TEXT_X = 10;
const int BULLET_TEXT_Y = 50;
const int GAME_OVER_TEXT_X = 300;
const int GAME_OVER_TEXT_Y = 300;


Game::Game() : window(sf::VideoMode(800, 600), "Parachuting C++"), player(Vector2(375, 550)), score(0), lives(3), bullets(0), gameState(GameState::PLAYING), timeSinceLastSpawn(0.0f)
{
	gameInstance = this;
	font.loadFromFile("arial.ttf");
	
	configureText(scoreText, SCORE_TEXT_SIZE, sf::Color::White, sf::Vector2f(SCORE_TEXT_X, SCORE_TEXT_Y));
	configureText(livesText, LIVES_TEXT_SIZE, sf::Color::White, sf::Vector2f(LIVES_TEXT_X, LIVES_TEXT_Y));
	configureText(bulletText, BULLET_TEXT_SIZE, sf::Color::White, sf::Vector2f(BULLET_TEXT_X, BULLET_TEXT_Y));
	configureText(gameOverText, GAME_OVER_TEXT_SIZE, sf::Color::White, sf::Vector2f(GAME_OVER_TEXT_X, GAME_OVER_TEXT_Y), "Game Over");
}

void Game::configureText(sf::Text& text, int size, sf::Color color, sf::Vector2f position, const std::string& str) {
	text.setFont(font);
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setPosition(position);
	if (!str.empty()) {
		text.setString(str);
	}
}

// Spawns an enemy if there are less than 3 enemies on the screen
void Game::spawnEnemy() {
	if (enemies.size() < MAX_ENNEMIES) { 
		int x = rand() % (WINDOW_WIDTH - 40) + 20;
		int speed = rand() % 200 - 100;
		enemies.emplace_back(Vector2(x, 0), speed);
	}
}

void Game::addToInventory(Enemy& enemy) {
	inventory.addEnemy(enemy);
}

void Game::incrementScore() {
	score++;
}

void Game::decreaseLives() {
	lives--;
	if (lives <= 0) {
		gameState = GameState::GAME_OVER;
	}
}

// Handles the collisions between the player, enemies and projectiles
void Game::handleCollisions() {
	handleProjectileCollisions();
	handlePlayerCollisions();
}

void Game::handleProjectileCollisions() {
	for (auto projectileIt = projectiles.begin(); projectileIt != projectiles.end();) {
		bool destryodProjectile = false;

		for (auto enemyIt = enemies.begin(); enemyIt != enemies.end();) {
			if (projectileIt->checkCollision(*enemyIt)) {
				projectileIt->onCollision(*enemyIt);
				enemyIt->onCollision(*projectileIt);

				enemyIt = enemies.erase(enemyIt);
				projectileIt = projectiles.erase(projectileIt);
				destryodProjectile = true;
				break;
			}
			else {
				enemyIt++;
			}
		}
		if (!destryodProjectile) projectileIt++;
	}
}

void Game::handlePlayerCollisions() {
	for (auto enemyIt = enemies.begin(); enemyIt != enemies.end();) {
		if (player.checkCollision(*enemyIt)) {
			player.onCollision(*enemyIt);

			enemyIt = enemies.erase(enemyIt);
		}
		else if (enemyIt->isKilled()) {
			decreaseLives();
			enemyIt = enemies.erase(enemyIt);
		}
		else {
			enemyIt++;
		}
	}
}

void Game::resetGame() {
	score = 0;
	lives = 3;
	bullets = 0;
	gameState = GameState::PLAYING;

	enemies.clear();
	projectiles.clear();
	inventory.clearInventory();

	player.setPosition(Vector2(PLAYER_START_X, PLAYER_START_Y));
}


void Game::run() {
	sf::Clock clock;
	while (window.isOpen()) {
		handleEvents();
		float delta = clock.restart().asSeconds();

		if (gameState == GameState::PLAYING) {
			updateGame(delta);
		}

		updateText();
		renderGame();
	}
}

void Game::handleEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			window.close();

		if (gameState == GameState::PLAYING) {
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && !inventory.isEmpty()) {
				Enemy enemyProjectile = inventory.ShootEnemy();
				projectiles.emplace_back(player.getPosition(), Vector2(0, -500));
			}
		}
		else if (gameState == GameState::GAME_OVER) {
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
				resetGame();
			}
		}
	}
}

void Game::updateGame(float delta) {
	player.handleInput();
	player.update(delta);


	timeSinceLastSpawn += delta;
	if (timeSinceLastSpawn >= SPAWN_RATE) {
		spawnEnemy();
		timeSinceLastSpawn = 0;
	}

	for (auto& enemy : enemies) {
		enemy.update(delta);
	}

	for (auto it = projectiles.begin(); it != projectiles.end();) {
		it->update(delta);
		if (it->isOutOfBounds()) {
			it = projectiles.erase(it);
		}
		else {
			++it;
		}
	}

	handleCollisions();
}

void Game::updateText() {
	scoreText.setString("Score: " + std::to_string(score));
	livesText.setString("Lives: " + std::to_string(lives));
	bulletText.setString("Bullets: " + std::to_string(inventory.getStoredEnemies()));
}

void Game::renderGame() {
	window.clear();

	if (gameState == GameState::PLAYING) {
		player.render(window);
		for (auto& enemy : enemies) {
			enemy.render(window);
		}
		for (auto& projectile : projectiles) {
			projectile.render(window);
		}

		window.draw(scoreText);
		window.draw(livesText);
		window.draw(bulletText);
	}
	else if (gameState == GameState::GAME_OVER) {
		window.draw(gameOverText);
	}

	window.display();
}