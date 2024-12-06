#include "GameObject.h"


// Constructor for the GameObject
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

// Get the bounds of the object
sf::FloatRect GameObject::getBounds() const
{
	return shape.getGlobalBounds();
}

// Get the position of the object
Vector2 GameObject::getPosition() const
{
	return rigidbody.getPosition();
}

// Set the position of the object
void GameObject::setPosition(Vector2 position)
{
	rigidbody.setPosition(position);
	shape.setPosition(position.x, position.y);
}

// Check if this object collides with another object
bool GameObject::checkCollision(const GameObject& other) const
{
	return shape.getGlobalBounds().intersects(other.getBounds());
}

void GameObject::onCollision(GameObject& other)
{
	// Do nothing by default
}