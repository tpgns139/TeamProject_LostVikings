#pragma once
#include "Enemy.h"

class SecurityRobot :public Enemy

{
public:
	SecurityRobot();
	~SecurityRobot();

	virtual HRESULT init(const char* imagename, POINT position, int num);
	virtual void update();

};

