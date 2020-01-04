#pragma once
#include "Enemy.h"


class Tower :public Enemy
{
public:
	Tower();
	~Tower();

	virtual HRESULT init(const char* imagename, POINT position, int num, float speed);
	void update();
	virtual bool bulletCountFire();
	
};

