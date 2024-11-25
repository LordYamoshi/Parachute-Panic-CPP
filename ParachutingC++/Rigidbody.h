#pragma once
#include "Vector2.h"

class Rigidbody
{
private:
	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;
	float friction;

public:
	Rigidbody(Vector2 startPos, float friction = 1.0);

	void addForce(Vector2 force);
	void update(float delta);

	Vector2 getPosition() const;
	void setPosition(const Vector2& pos);
	Vector2 getVelocity() const;

};

