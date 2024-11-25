#pragma once
#include "GameObject.h"


class Enemy : public GameObject
{
private:
	Vector2 horizontalSpeed;

public:
	Enemy(Vector2 startPos, float speed);
	void update(float delta) override;
};