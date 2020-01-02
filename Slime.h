#pragma once
#include "Enemy.h"
class Slime :public Enemy

{
public:
	Slime();
	~Slime();
	int slimeMoveCount = 0;

	virtual HRESULT init(const char* imagename, POINT position);
	virtual void update();

	virtual void move();
	

};

