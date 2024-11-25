#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "Parachuting C++"), player(Vector2(375, 550)), score(0)
{
	font.loadFromFile("arial.ttf");
	scoreText.setFont(font);
	scoreText.setCharacterSize(24);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(10, 10);
	livesText.setFont(font);
	livesText.setCharacterSize(24);
	livesText.setFillColor(sf::Color::White);
	livesText.setPosition(10, 30);
}

void Game::spawnEnemy() {
	if (enemies.size() < 3) { 
		float x = rand() % 760 + 20;
		float speed = rand() % 200 - 100;
		enemies.emplace_back(Vector2(x, 0), speed);
	}
}

void Game::handleCollisions() {
	for (auto it = enemies.begin(); it != enemies.end();) {
		if (player.getBounds().intersects(it->getBounds())) {
			it = enemies.erase(it);
			score++;
		}
		else if (it->getPosition().y > 600) {
			lives--;
			it = enemies.erase(it);
		}
		else {
			it++;
		}
	}
}

void Game::run() {
	sf::Clock clock;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		float delta = clock.restart().asSeconds();

		player.handleInput();
		player.update(delta);

		if (rand() % 100 < 2) {
			spawnEnemy();
		}

		for (auto& enemy : enemies) {
			enemy.update(delta);
		}

		handleCollisions();

		scoreText.setString("Score: " + std::to_string(score));
		livesText.setString("Lives: " + std::to_string(lives));

		window.clear();
		player.render(window);
		for (auto& enemy : enemies) {
			enemy.render(window);
		}

		window.draw(scoreText);
		window.draw(livesText);
		window.display();
	}

}
