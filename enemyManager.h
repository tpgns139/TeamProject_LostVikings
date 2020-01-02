#pragma once
#include "gameNode.h"
#include "Slime.h"
#include "SecurityRobot.h"
#include "Tower.h"
#include "Enemy.h"
#include "Bullet.h"
#include <vector>
#include "MapManager.h"

class MapManager;
class EnemyManager : public gameNode
{

private:

	typedef vector<Enemy*>           vEnemy;
	typedef vector<Enemy*>::iterator viEnemy;
	MapManager* _mapManager;
	Bullet* _Ebullet;
	vEnemy _vEm;
	viEnemy _viEm;
	RECT collisionTestRect;

public:
	EnemyManager();
	~EnemyManager();

	HRESULT init();
	void release();
	void update();
	void render();
	void setEnemy(); //에너미 세팅
	void enemyBulletFire();
	void towerBulletFire();
	void collision();
	vector<Enemy*> getEnemy() { return _vEm; }
	vector<Enemy*>::iterator getViEnemy() { return _viEm; }

	void setMemoryAddressLink(MapManager* mm) { _mapManager = mm; }
};

