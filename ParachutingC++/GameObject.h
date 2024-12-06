#pragma once
#include <SFML/Graphics.hpp>
#include "Rigidbody.h"


class GameObject
{
protected:
	Rigidbody rigidbody;
	sf::RectangleShape shape;

public:
	GameObject(Vector2 startPos, sf::Vector2f size, sf::Color color);
	virtual void update(float delta) = 0;
	virtual void handleInput() {}
	void render(sf::RenderWindow& window);
	sf::FloatRect getBounds() const;
	Vector2 getPosition() const;
	void setPosition(Vector2 position);
	bool checkCollision(const GameObject& other) const;
	virtual void onCollision(GameObject& other);
};

