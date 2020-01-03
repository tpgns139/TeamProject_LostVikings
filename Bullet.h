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

class Bullet : public gameNode
{

private:
	vector<tagBullet>			 _vBullet;
	vector<tagBullet>::iterator  _viBullet;

	const char* _imgname;
	int _bulletMax;
	float _range;
public:
	Bullet();
	~Bullet();

	HRESULT init(const char * imagename);
	void release();
	void update();
	void render();

	void bulletFire(float x, float y, float speed);
	void bulletMove();
	void removeBullet(int arrNum);
	void frameRender();
	void FramebulletFire(float x, float y, float speed, int frameX, int frameY);
	
	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet> ::iterator getViBullet() { return _viBullet; }
	
};

