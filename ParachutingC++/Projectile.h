#pragma once
#include "GameObject.h"


class Projectile : public GameObject
{
private:
	Vector2 speed;

public:
	Projectile(Vector2 startPos, Vector2 speed);
	void update(float delta) override;

	bool isOutOfBounds() const;
};

