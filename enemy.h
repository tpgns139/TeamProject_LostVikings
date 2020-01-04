#pragma once
#include "gameNode.h"
#include "Wall.h"



class PlayerManager;
class MapManager;
enum enemyName
{
	slime,
	slimeatk,
	redtower,
	robot,
	robotatk
};
enum enemyDirection
{
	e_Left,
	e_Right
};
struct ENEMY
{
	image* img;
	float  x, y;
	enemyName name;
	float speed;
	float angle;
	RECT rc, leftcolcheckrc, rightcolcheckrc;
	int count;
	bool isMove;
	enemyDirection _enemyDirection;
};


class Enemy : public gameNode

{

protected:

	PlayerManager* _playerManager;
	MapManager* _mapManager;
	ENEMY _enemy;
	int _bulletMax;
	float _range;
	int _currentFrameX, _currentFrameY;  //읽어들이는 현재 프레임 위치
	int _count, _count2; //프레임 재생 속도
	
	int _firecount;
	
	
public:
	Enemy();
	~Enemy();

	virtual HRESULT init(const char* imagename, POINT position, int num, float speed);

	void release();
	virtual void update();
   	void render();
	virtual void AttackStart();
	virtual bool bulletCountFire();
	
	float getX() { return _enemy.x; }
	float getY() { return _enemy.y; }
	ENEMY getEnemyInfo() { return _enemy; }
	RECT getEnemyRect() { return _enemy.rc; }
	RECT getRightRect() { return _enemy.rightcolcheckrc; }
	RECT getLeftRect() { return _enemy.leftcolcheckrc; }

	void setEnemySpeed(float speed) { _enemy.speed = speed;}
	void setMemoryAddressLink(MapManager* mm) { _mapManager = mm; }
	virtual void setplayerMemoryAddressLink(PlayerManager* pm) { _playerManager = pm; }
	enemyDirection getenemyDir() { return _enemy._enemyDirection; }
};

