#include "GameObject.h"


GameObject::GameObject(Vector2 startPos, sf::Vector2f size, sf::Color color) : rigidbody(startPos)
{
	shape.setSize(size);
	shape.setFillColor(color);
	shape.setPosition(startPos.x, startPos.y);
}


void GameObject::render(sf::RenderWindow& window)
{
	window.draw(shape);
}

sf::FloatRect GameObject::getBounds() const
{
	return shape.getGlobalBounds();
}

Vector2 GameObject::getPosition() const
{
	return rigidbody.getPosition();
}

void GameObject::setPosition(Vector2 position)
{
	rigidbody.setPosition(position);
	shape.setPosition(position.x, position.y);
}