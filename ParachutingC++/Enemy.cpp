#include "Enemy.h"

Enemy::Enemy(Vector2 startPos, float speed) : GameObject(startPos, sf::Vector2f(40, 40), sf::Color::Red),  horizontalSpeed(Vector2(speed, 0)) {}

void Enemy::update(float delta)
{
	rigidbody.addForce(Vector2(0,100));
	rigidbody.update(delta);

	Vector2 pos = rigidbody.getPosition();
	float screenWidth = 800;
	float enemyWidth = shape.getSize().x;



	if (pos.x <= 0 || pos.x >= screenWidth - enemyWidth)
	{
		horizontalSpeed.x = -horizontalSpeed.x;
	}

	pos += horizontalSpeed * delta;
	rigidbody.setPosition(pos);
	shape.setPosition(pos.x, pos.y);

}