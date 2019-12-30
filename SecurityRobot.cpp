#include "stdafx.h"
#include "SecurityRobot.h"


SecurityRobot::SecurityRobot()
{
}


SecurityRobot::~SecurityRobot()
{
}

void SecurityRobot::update()
{
	_count++;
	if (_count % 25 == 0)
	{
		if (_currentFrameX > _enemy.img->getMaxFrameX()) _currentFrameX = 0;
		_enemy.img->setFrameX(_currentFrameX);
		_currentFrameX++;
		_count = 0;


	}
	move();

	
	_enemy.rc = RectMakeCenter(_enemy.x - CAMERA->getCameraXpos() + _enemy.img->getFrameWidth() / 2, 
		_enemy.y - CAMERA->getCameraYpos() + _enemy.img->getFrameHeight() / 2, _enemy.img->getFrameWidth(), _enemy.img->getFrameHeight());
}
