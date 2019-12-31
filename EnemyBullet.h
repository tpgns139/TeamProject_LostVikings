#pragma once
#include "gameNode.h"
#include <vector>

struct tagBullet
{
	image* img;
	RECT rc;
	float x, y;
	float speed;
	float fireX, fireY;
	bool isFire;

};

class EnemyBullet : public gameNode
{

private:
	vector<tagBullet>			 _vBullet;
	vector<tagBullet>::iterator  _viBullet;

	const char* _name;
	int _bulletMax;
	float _range;
public:
	EnemyBullet();
	~EnemyBullet();

	HRESULT init();
	void release();
	void update();
	void render();

	void bulletFire(float x, float y, float speed);
	void bulletMove();
	void removeBullet(int arrNum);
	
	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet> ::iterator getViBullet() { return _viBullet; }
	
};

