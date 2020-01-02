#include "stdafx.h"
#include "Tower.h"


Tower::Tower()
{
}


Tower::~Tower()
{
}

void Tower::update()
{
	_count++;
	_enemy.img->setFrameX(_currentFrameX);
	if (_currentFrameX==0 &&_count % 50== 0)
	{
		
		
		_currentFrameX = 1;
		_count = 0;
		
	}
	else if (_currentFrameX == 1 && _count %20 == 0)
	{
		_currentFrameX = 2;
		_count = 0;
	}
	else if (_currentFrameX == 2 && _count % 2 == 0)
	{
		_currentFrameX = 0;
		_count = 0;
	}

	
	move();

	
	_enemy.rc = RectMakeCenter(_enemy.x - CAMERA->getCameraXpos()+ _enemy.img->getFrameWidth()/2,
		_enemy.y - CAMERA->getCameraYpos()+ _enemy.img->getFrameHeight()/2, _enemy.img->getFrameWidth(), _enemy.img->getFrameHeight());
}


