#include "stdafx.h"
#include "Slime.h"


Slime::Slime()
{
}


Slime::~Slime()
{
}

HRESULT Slime::init(const char * imagename, POINT position, int num, float speed)
{
	IMAGEMANAGER->addFrameImage("SlimeMove1", "슬라임이동.bmp", 336, 163, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("SlimeAtk1", "슬라임공격.bmp", 168, 152, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("SlimeMove2", "슬라임이동.bmp", 336, 163, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("SlimeAtk12", "슬라임공격.bmp", 168, 152, 2, 2, true, RGB(255, 0, 255));
	Enemy::init(imagename,position,num,speed);
	_enemy.speed = speed;
	_enemy.name = slime;

	return S_OK;
}

void Slime::update()
{
	Enemy::update();
	_count++;
	_count2++;
	
	_enemy.img->setFrameX(_currentFrameX);
	move();

	if (_enemy.speed > 1)
	{
		_enemy.img->setFrameY(0);

		if ((_currentFrameX == 0 ||_currentFrameX ==1 )&& _count % 18 == 0)
		{

			_currentFrameX = 2;
			_count = 0;

		}
		else if (_currentFrameX == 2 && _count % 10 == 0)
		{
			_currentFrameX = 3;
			_count = 0;
		}
		else if (_currentFrameX == 3 && _count % 10 == 0)
		{
			_currentFrameX = 0;
			_count = 0;
		}
		if (_currentFrameX >= 1)
		{
			_enemy.x += _enemy.speed;
		}

	}
	else
	{
	
		_enemy.img->setFrameY(1);

		if ((_currentFrameX == 2 ||_currentFrameX ==3 )&& _count2 % 18 == 0)
		{

			_currentFrameX =1;
			_count2 = 0;

		}

		else if (_currentFrameX == 1 && _count2 % 10 == 0)
		{
			_currentFrameX = 0;
			_count2 = 0;
		}
		else if (_currentFrameX == 0 && _count2 % 10 == 0)
		{
			_currentFrameX = 2;
			_count2 = 0;
		}
		if (_currentFrameX <=1)
		{
			_enemy.x += _enemy.speed;
		}
	}

	
}

void Slime::move()
{
	
}

bool Slime::bulletCountFire()
{

	_firecount++;

	if (_firecount % 42 == 0)
	{
		_firecount = 0;
		return true;
	}
	return false;

}

