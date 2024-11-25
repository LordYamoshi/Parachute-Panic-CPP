#pragma once

#include <SFML/Graphics.hpp>

class Character
{
public:	
	virtual ~Character() = default;
	virtual void Move(float delta) = 0;
	void setVelocity(sf::Vector2f velocity);
	sf::Vector2f GetVelocity();
	sf::Sprite GetSprite();


protected:
	sf::Sprite sprite;
};

