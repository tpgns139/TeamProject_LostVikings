#pragma once
#include "Enemy.h"
class Slime :public Enemy

{
public:
	Slime();
	~Slime();
	int slimeMoveCount = 0;
	void update();
	void move();
	

};

