#pragma once
#include <vector>
#include "EnemyAI.h"

class EnemyAIManager
{
public:
	EnemyAIManager(int enemyCount);
	~EnemyAIManager();

private:

	std::vector<EnemyAI> mEnemies;
};

