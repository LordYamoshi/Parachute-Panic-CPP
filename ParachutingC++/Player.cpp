#include "Player.h"
#include "Enemy.h"
#include "Game.h"

extern Game* gameInstance;

Player::Player(Vector2 startPos) : GameObject(startPos, sf::Vector2f(50, 20), sf::Color::Green) {}


// Handles the input for the playerm, if the left key is pressed, the player moves left, if the right key is pressed, the player moves right
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
	rigidbody.setUseGravity(false);
	

	Vector2 pos = rigidbody.getPosition();
	float screenWidth = 800;
	float playerWidth = shape.getSize().x;

	// Check if the player touches the left or right wall, if it does reset the position and velocity, so the player doesn't go out of bounds 
	//And so the player doesn't need need to wait until speed accelerates again
	if (pos.x <= 0)
	{
		pos.x = 0;
		rigidbody.setVelocity(Vector2(0, rigidbody.getVelocity().y));
	}
	if (pos.x >= screenWidth - playerWidth) {
		pos.x = screenWidth - playerWidth;
		rigidbody.setVelocity(Vector2(0, rigidbody.getVelocity().y));
	}

	rigidbody.setPosition(pos);
	shape.setPosition(pos.x, pos.y);
}

void Player::onCollision(GameObject& other)
{
	Enemy* enemy = dynamic_cast<Enemy*>(&other);
	if (enemy != nullptr)
	{
		gameInstance->addToInventory(*enemy);
	}
}