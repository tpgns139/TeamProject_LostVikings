#pragma once
#include "gameNode.h"
#include "Slime.h"
#include "SecurityRobot.h"
#include "Tower.h"
#include "Enemy.h"
#include "Bullet.h"
#include <vector>
#include "MapManager.h"
#include "PlayerManager.h"


class PlayerManager;
class MapManager;
class EnemyManager : public gameNode
{

private:

	typedef vector<Enemy*>           vEnemy;
	typedef vector<Enemy*>::iterator viEnemy;
	PlayerManager* _playerManager;
	MapManager* _mapManager;
	Bullet* _Ebullet;
	vEnemy _vEm;
	viEnemy _viEm;
	
	RECT collisionTestRect;
	bool EnemyAtk;

public:
	EnemyManager();
	~EnemyManager();

	HRESULT init();
	void release();
	void update();
	void render();
	void setEnemy(); //에너미 세팅
	
	void enemyBulletFire(Enemy* enemy,Direction _direction);
	
	void removeEnemy(int arrNum);
	void collision();
	vector<Enemy*> getEnemy() { return _vEm; }
	vector<Enemy*>::iterator getViEnemy() { return _viEm; }

	void setMemoryAddressLink(MapManager* mm) { _mapManager = mm; }
	void setplayerMemoryAddressLink(PlayerManager* pm) { _playerManager = pm; }
};

