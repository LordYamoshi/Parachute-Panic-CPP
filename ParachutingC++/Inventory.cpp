#include "Inventory.h"


// Adds an enemy to the inventory
void Inventory::addEnemy(const Enemy& enemy)
{
	storedEnemies.push_back(enemy);
}

// Takes the last enemy stored in the array and returns that enemy so it can be shot
Enemy Inventory::ShootEnemy()
{
	if (!isEmpty()) {
		Enemy enemy = storedEnemies.back();
		storedEnemies.pop_back();
		return enemy;
	}
	return Enemy(Vector2(0, 0), 0);
}

// Checks if the inventory is empty
bool Inventory::isEmpty() const
{
	return storedEnemies.empty();
}

int Inventory::getStoredEnemies() const {
	return storedEnemies.size();
}

void Inventory::clearInventory() {
	storedEnemies.clear();	
}