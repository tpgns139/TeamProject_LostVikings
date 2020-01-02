#pragma once
#include "Enemy.h"
class Slime :public Enemy

{
public:
	Slime();
	~Slime();


	virtual HRESULT init(const char* imagename, POINT position, int num);
	virtual void update();

	virtual void move();
	

};

