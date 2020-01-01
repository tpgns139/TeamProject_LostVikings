#pragma once
#include "gameNode.h"


struct ENEMY
{
	image* img;
	float  x, y;

	float speed;
	float angle;
	RECT rc;
	int count;
	bool leftMove = false;
};


class Enemy : public gameNode

{

protected:



	ENEMY _enemy;
	int _bulletMax;
	float _range;
	int _currentFrameX, _currentFrameY;  //읽어들이는 현재 프레임 위치
	int _count; //프레임 재생 속도
	int _rndFireCount; //총알발사 랜덤 주기
	int _enemyfirecount;
public:
	Enemy();
	~Enemy();

	virtual HRESULT init(const char* imagename, POINT position);

	void release();
	virtual void update();
   	void render();
	virtual void move();
	
	float getX() { return _enemy.x; }
	float getY() { return _enemy.y; }
	ENEMY getEnemyInfo() { return _enemy; }
	RECT getEnemyRect() { return _enemy.rc; }
};

