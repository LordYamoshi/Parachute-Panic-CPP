#pragma once
#include <vector>
#include "Enemy.h"

class Inventory
{
private:
	std::vector<Enemy> storedEnemies;

public:

	void addEnemy(const Enemy& enemy);

	Enemy ShootEnemy();

	bool isEmpty() const;

	int getStoredEnemies() const;

	void clearInventory();
};

