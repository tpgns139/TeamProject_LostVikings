#include "stdafx.h"
#include "Tower.h"


Tower::Tower()
{
}


Tower::~Tower()
{
}

HRESULT Tower::init(const char * imagename, POINT position, int num, float speed)
{
	IMAGEMANAGER->addFrameImage("Tower", "��ž.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));
	Enemy::init(imagename, position, num, speed);
	_enemy.name = redtower;
	return S_OK;
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

	
}

bool Tower::bulletCountFire()
{
	_firecount++;

	if (_firecount % 72 == 0)
	{
		_firecount = 0;
		return true;
	}
	return false;
}


