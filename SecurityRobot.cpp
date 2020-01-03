#include "stdafx.h"
#include "SecurityRobot.h"


SecurityRobot::SecurityRobot()
{
}


SecurityRobot::~SecurityRobot()
{
}

HRESULT SecurityRobot::init(const char * imagename, POINT position, int num,float speed)
{
	IMAGEMANAGER->addFrameImage("SecurityRobotMove1", "���κ��̵�.bmp", 420, 132, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("SecurityRobotAtk1", "���κ�����.bmp", 210, 135, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("SecurityRobotMove2", "���κ��̵�.bmp", 420, 132, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("SecurityRobotAtk2", "���κ�����.bmp", 210, 135, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("SecurityRobotMove3", "���κ��̵�.bmp", 420, 132, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("SecurityRobotAtk3", "���κ�����.bmp", 210, 135, 3, 2, true, RGB(255, 0, 255));
	Enemy::init(imagename, position, num, speed);
	_enemy.speed = speed;
	_enemy.name = robot;
	return S_OK;
}

void SecurityRobot::update()
{
	Enemy::update();

	_count++;

	if (_count %24 == 0)
	{

		if (_enemy.speed < 0)
		{
			_enemy.img->setFrameY(1);
			if (_currentFrameX <0) _currentFrameX =5;
			_enemy.img->setFrameX(_currentFrameX);
			_currentFrameX--;
			_count = 0;
			
		}
		else
		{
			_enemy.img->setFrameY(0);
			if (_currentFrameX > _enemy.img->getMaxFrameX()) _currentFrameX = 0;
			_enemy.img->setFrameX(_currentFrameX);
			_currentFrameX++;
			_count = 0;

		}
	}
	_enemy.x += _enemy.speed;

	
}

bool SecurityRobot::bulletCountFire()
{

	_firecount++;

	if (_firecount % 70 == 0)
	{
		_firecount = 0;
		return true;
	}
	return false;
	
}
