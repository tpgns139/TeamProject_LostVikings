#pragma once
#include "gameNode.h"
#include "Wall.h"


class MapManager;
enum enemyName
{
	slime,
	redtower,
	robot
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
	bool isMove = false;
};


class Enemy : public gameNode

{

protected:


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
	virtual void move();
	virtual bool bulletCountFire();

	float getX() { return _enemy.x; }
	float getY() { return _enemy.y; }
	ENEMY getEnemyInfo() { return _enemy; }
	RECT getEnemyRect() { return _enemy.rc; }

	void setMemoryAddressLink(MapManager* mm) { _mapManager = mm; }
	

};

