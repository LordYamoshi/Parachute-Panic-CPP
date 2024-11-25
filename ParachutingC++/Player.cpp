#include "Player.h"

Player::Player(Vector2 startPos) : GameObject(startPos, sf::Vector2f(50, 20), sf::Color::Green) {}

void Player::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		rigidbody.addForce(Vector2(-500, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rigidbody.addForce(Vector2(500, 0));
	}
}

void Player::update(float delta)
{
	rigidbody.update(delta);

	Vector2 pos = rigidbody.getPosition();
	float width = 800;
	float playerWidth = shape.getSize().x;

	if (pos.x < 0) {
		pos.x = 0;
	}
	if (pos.x > width - playerWidth) {
		pos.x = width - playerWidth;
	}

	rigidbody.setPosition(pos);
	shape.setPosition(pos.x, pos.y);
}