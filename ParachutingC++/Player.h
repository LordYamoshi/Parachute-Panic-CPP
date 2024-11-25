#pragma once

#include "Character.h"

class Player : public Character
{
public: Player(sf::Texture texture, sf::Vector2f position);
	  void Move(float delta) override;
};

