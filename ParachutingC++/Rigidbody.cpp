#include "Rigidbody.h"

Rigidbody::Rigidbody(Vector2 startPos, float friction) : position(startPos), friction(friction) {}

void Rigidbody::addForce(Vector2 force)
{
	acceleration += force;
}

void Rigidbody::update(float delta)
{
	velocity += acceleration * delta;
	velocity *= friction;
	position += velocity * delta;
	acceleration = Vector2();
}

Vector2 Rigidbody::getPosition() const
{
	return position;
}

void Rigidbody::setPosition(const Vector2& pos)
{
	position = pos;
}

Vector2 Rigidbody::getVelocity() const
{
	return velocity;
}