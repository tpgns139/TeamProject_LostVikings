#include "stdafx.h"
#include "Slime.h"


Slime::Slime()
{
}


Slime::~Slime()
{
}

void Slime::update()
{
	_count++;
	if (_count %8 == 0)
	{
		if (_currentFrameX > _enemy.img->getMaxFrameX()) _currentFrameX = 0;
		_enemy.img->setFrameX(_currentFrameX);
		_currentFrameX++;
		_count = 0;
	}
	_enemy.speed = 10;
	move();

	_enemy.rc = RectMakeCenter(_enemy.x - CAMERA->getCameraXpos() + _enemy.img->getFrameWidth() / 2,
	_enemy.y - CAMERA->getCameraYpos() + _enemy.img->getFrameHeight() / 2, _enemy.img->getFrameWidth(), _enemy.img->getFrameHeight());
}

void Slime::move()
{
	slimeMoveCount++;

	if (_count % 8 == 0)
	{
		_enemy.x += _enemy.speed;
	
	}
}

