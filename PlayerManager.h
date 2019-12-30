#pragma once
#include "Player.h"
#include "Eric.h"
#include"Baleog.h"
class EnemyManager;
class PlayerManager
{
private:
	EnemyManager* _em;
	vector<Player*> _vPlayer;
public:
	PlayerManager();
	~PlayerManager();

	HRESULT init();
	void update();
	void render();
	void setAddressEnemyManager(EnemyManager* em) { _em = em; }
};

