#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(Vector2 startPos);
	void handleInput() override;
	void update(float delta) override;
};