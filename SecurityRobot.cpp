#include "stdafx.h"
#include "SecurityRobot.h"


SecurityRobot::SecurityRobot()
{
}


SecurityRobot::~SecurityRobot()
{
}

HRESULT SecurityRobot::init(const char * imagename, POINT position, int num, float speed)
{
	string ins = imagename + to_string(num);
	string atkIns = "SecurityRobotAtk" + to_string(num);


		IMAGEMANAGER->addFrameImage(imagename, "경비로봇이동.bmp", 420, 132, 6, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage(atkIns, "경비로봇공격.bmp", 210, 135, 3, 2, true, RGB(255, 0, 255));
	
	
		Enemy::init(atkIns.c_str(), position, num, speed);
	
		 
		
	_enemy.name = robot;
	_enemy.isMove = true;
	return S_OK;
}

void SecurityRobot::update()
{
	Enemy::update();
 
	_count++;
	if (_enemy.isMove)
	{
		if (_count % 20 == 0)
		{

			if (_enemy._enemyDirection==e_Left)
			{
				_enemy.img->setFrameY(1);
				if (_currentFrameX < 0) _currentFrameX = _enemy.img->getMaxFrameX();
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
	}
	_enemy.x += _enemy.speed;


}

void SecurityRobot::AttackStart()
{
	
}

bool SecurityRobot::bulletCountFire()
{

	_firecount++;

	if (_firecount % 60 == 0)
	{
		_firecount = 0;
		return true;
	}
	return false;
	
}
