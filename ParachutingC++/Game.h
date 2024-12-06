#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"
#include "Inventory.h"

enum class GameState {
	PLAYING,
	GAME_OVER
};

class Game {
public:
	void addToInventory(Enemy& enemy);
	void incrementScore();
	void decreaseLives();

	Game();
	void run();

private:
	void configureText(sf::Text& text, int size, sf::Color color, sf::Vector2f position, const std::string& str = "");
	void spawnEnemy();
	void handleCollisions();
	void handlePlayerCollisions();
	void handleProjectileCollisions();
	void resetGame();
	void handleEvents();
	void updateGame(float delta);
	void updateText();
	void renderGame();

	sf::Font font;
	sf::Text scoreText;
	sf::Text livesText;
	sf::Text bulletText;
	sf::Text gameOverText;

	sf::RenderWindow window;
	Player player;
	std::vector<Enemy> enemies;
	std::vector<Projectile> projectiles;
	Inventory inventory;

	int score;
	int lives = 3;
	int bullets = 0;
	GameState gameState;

	float timeSinceLastSpawn = 0;
	const float SPAWN_RATE = 1;

};