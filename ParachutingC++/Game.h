#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "Enemy.h"

class Game {
private:
	sf::RenderWindow window;
	Player player;
	std::vector<Enemy> enemies;
	sf::Font font;
	sf::Text scoreText;
	sf::Text livesText;
	int score;
	int lives = 3;

	void spawnEnemy();
	void handleCollisions();

public:
	Game();
	void run();
};