#pragma once

#include "Character.h"
class Enemy : public Character
{
public:
	Enemy(sf::Texture texture, sf::Vector2f position, float speed);
	void Move(float delta) override;
};

