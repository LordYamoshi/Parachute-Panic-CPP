#include "Projectile.h"


Projectile::Projectile(Vector2 startPos, Vector2 speed) : GameObject(startPos, { 20,20 }, sf::Color::Red), speed(speed) {}

// Updates the projectile rigid body values so it can move
void Projectile::update(float delta)
{
	rigidbody.addForce(speed);
	rigidbody.update(delta);
	
	Vector2 pos = rigidbody.getPosition();
	rigidbody.setPosition(pos);
	shape.setPosition(rigidbody.getPosition().x, rigidbody.getPosition().y);
}

// Check if the projectile is out of bounds
bool Projectile::isOutOfBounds() const
{
	return rigidbody.getPosition().y <= 0;
}

void Projectile::onCollision(GameObject& other)
{
	// Do nothing
}