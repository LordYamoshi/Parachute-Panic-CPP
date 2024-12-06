#pragma once
#include "Vector2.h"

class Rigidbody
{
private:
	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;
	Vector2 force;
	Vector2 friction;
	float gravity;
	float maxVelocity;
	bool canUseGravity;

public:
	Rigidbody(Vector2 startPos = {}, bool canUseGravity = true);

	void addForce(const Vector2& force);

	void addGravity();

	void setUseGravity(bool useGravity);
	bool isUsingGravity() const;

	void update(float delta);

	Vector2 getPosition() const;
	void setPosition(const Vector2& pos);

	Vector2 getVelocity() const;
	void setVelocity(const Vector2& vel);


};

