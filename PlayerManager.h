#pragma once
#include "Player.h"
#include "Erik.h"
#include"Baleog.h"
#include "Olaf.h"


class EnemyManager;
class MapManager;

class PlayerManager
{
private:
	EnemyManager* _em;
	MapManager* _MapManager;
	vector<Player*> _vPlayer;
	Player* _nowPlayer;
	Playerinfo _playerinfo;

	int PlayerNumber;
	
public:
	PlayerManager();
	~PlayerManager();

	HRESULT init();
	void update();
	void render();

	void setAddressEnemyManager(EnemyManager* em) { _em = em; }
	vector<Player*> get_vPlayer() { return _vPlayer; }
	void setAddressMapManager(MapManager* MapManager) { _MapManager = MapManager; }
};

