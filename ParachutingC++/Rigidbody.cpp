#include "Rigidbody.h"

Rigidbody::Rigidbody(Vector2 startPos, bool canUseGravity) : position(startPos) , velocity(), acceleration(),gravity(3), maxVelocity(100.0f), canUseGravity(canUseGravity){}


// Adds a force to the object
void Rigidbody::addForce(const Vector2& force)
{
	acceleration += force;
}


// If the current object is allowed to use gravity, then add gravity to the object
void Rigidbody::addGravity()
{
	if (!canUseGravity) return;
	addForce(Vector2(0, gravity));
}

// Uses delta to increase the acceleration every second to make the object move
void Rigidbody::update(float delta)
{
	addGravity();
	velocity += acceleration * delta;
	position += velocity * delta;
	acceleration = {}; 
}


void Rigidbody::setUseGravity(bool useGravity)
{
	canUseGravity = useGravity;
}

bool Rigidbody::isUsingGravity() const
{
	return canUseGravity;
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

void Rigidbody::setVelocity(const Vector2& vel)
{
	velocity = vel;
}
