#pragma once
#include "Enemy.h"


class Tower :public Enemy
{
public:
	Tower();
	~Tower();
	virtual HRESULT init(mapInfo info);

	
	void update();

};

