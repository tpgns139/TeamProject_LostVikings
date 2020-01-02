#include "stdafx.h"
#include "SecurityRobot.h"


SecurityRobot::SecurityRobot()
{
}


SecurityRobot::~SecurityRobot()
{
}

HRESULT SecurityRobot::init(const char * imagename, POINT position, int num)
{

	Enemy::init(imagename, position, num);
	_enemy.speed = 3;
	return S_OK;
}

void SecurityRobot::update()
{
	Enemy::update();
	_count++;
	if (_count % 25 == 0)
	{
		if (_currentFrameX > _enemy.img->getMaxFrameX()) _currentFrameX = 0;
		_enemy.img->setFrameX(_currentFrameX);
		_currentFrameX++;
		_count = 0;


	}
	move();

	
	
}
