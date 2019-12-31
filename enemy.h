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
	int _currentFrameX, _currentFrameY;  //�о���̴� ���� ������ ��ġ
	int _count; //������ ��� �ӵ�
	int _rndFireCount; //�Ѿ˹߻� ���� �ֱ�
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

