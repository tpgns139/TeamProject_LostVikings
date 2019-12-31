#include "stdafx.h"
#include "Slime.h"


Slime::Slime()
{
}


Slime::~Slime()
{
}

HRESULT Slime::init(const char * imagename, POINT position)
{
	Enemy::init(imagename,position);
	_enemy.speed = 3        ;
	return S_OK;
}

void Slime::update()
{
	Enemy::update();
	_count++;
	_enemy.img->setFrameX(_currentFrameX);
	move();

	_count++;
	_enemy.img->setFrameX(_currentFrameX);
	if (_currentFrameX == 0 && _count % 40 == 0)
	{

		_currentFrameX = 2; 
		_count = 0;

	}
	else if (_currentFrameX == 2 && _count % 20 == 0)
	{
		_currentFrameX =3;
		_count = 0; 
	}
	else if (_currentFrameX == 3 && _count %18 == 0)
	{
		_currentFrameX = 0;
		_count = 0;
	}
	if (_currentFrameX>=1)
	{
		_enemy.x += _enemy.speed;
	}
	
}

void Slime::move()
{
	
}

