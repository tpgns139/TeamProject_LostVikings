#pragma once
#include "Player.h"
#include "Erik.h"
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

	vector<Player*> get_vPlayer() { return _vPlayer; }
};

