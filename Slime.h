#pragma once
#include "Enemy.h"
class Slime :public Enemy

{
public:
	Slime();
	~Slime();


	virtual HRESULT init(const char* imagename, POINT position, int num, float speed);
	virtual void update();


	virtual void AttackStart();
	virtual bool bulletCountFire();

};

