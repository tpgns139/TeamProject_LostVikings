#pragma once
#include "Enemy.h"

class SecurityRobot :public Enemy

{
private:
	
public:
	SecurityRobot();
	~SecurityRobot();

	virtual HRESULT init(const char* imagename, POINT position, int num, float speed);
	virtual void update();
	virtual void AttackStart();
	virtual bool bulletCountFire();
	
};

