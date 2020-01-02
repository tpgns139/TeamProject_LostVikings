#pragma once
#include "Enemy.h"


class Tower :public Enemy
{
public:
	Tower();
	~Tower();

	
	void update();
	virtual bool bulletCountFire();
};

