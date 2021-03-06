#pragma once
#include "Player.h"
#include "Erik.h"
#include"Baleog.h"
#include "Olaf.h"

#include "Bullet.h"
class MapManager;
class EnemyManager;


class PlayerManager
{
private:
	EnemyManager* _em;
	MapManager* _MapManager;
	vector<Player*> _vPlayer;


	Player* _nowPlayer;
	Bullet* _Pbullet;
	int PlayerNumber;
	bool _potalCheck;
	bool _potalCheckTwo;

public:
	PlayerManager();
	~PlayerManager();

	HRESULT init();
	void update();
	void render();
	void playerBulletFire();
	void setAddressEnemyManager(EnemyManager* em) { _em = em; }
	vector<Player*> get_vPlayer() { return _vPlayer; }
	void setAddressMapManager(MapManager* MapManager) { _MapManager = MapManager; }
	Player* get_nPlayer() { return _nowPlayer; }
	void setNowPlayer();
	void Bulletcollsion();
	void colErikWithEnemy();
	void Swordcollsion();
	void gravityzonecollsion();
	void potalcollsion();

};

