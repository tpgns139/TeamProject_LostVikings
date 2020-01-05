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


	string ins = imagename+ to_string(num);
	string atkIns = "SlimeAtk" + to_string(num);
	IMAGEMANAGER->addFrameImage(imagename, "�������̵�.bmp", 336, 163, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(atkIns, "�����Ӱ���.bmp", 168, 152, 2, 2, true, RGB(255, 0, 255));

	Enemy::init(atkIns.c_str(), position, num, speed);

	
	_enemy.name = slime;
	_enemy.isMove = true;
	return S_OK;
}

void Slime::update()
{
	Enemy::update();
	_count++;
	_count2++;
	RECT temp;
	_enemy.img->setFrameX(_currentFrameX);
	

	if (_enemy._enemyDirection == e_Left)
	{
		_enemy.img->setFrameY(1);
		if ((_currentFrameX == 2 || _currentFrameX == 3) && _count2 % 20 == 0)
		{

			_currentFrameX = 1;
			_count2 = 0;

		}
		else if (_currentFrameX == 1 && _count2 % 12 == 0)
		{
			_currentFrameX = 0;
			_count2 = 0;
		}
		else if (_currentFrameX == 0 && _count2 % 12 == 0)
		{
			_currentFrameX = 2;
			_count2 = 0;
		}
		if (_currentFrameX <= 1)
		{
			_enemy.x += _enemy.speed;
		}
	}

	else
	{
		_enemy.img->setFrameY(0);

		if ((_currentFrameX == 0 || _currentFrameX == 1) && _count % 20 == 0)
		{

			_currentFrameX = 2;
			_count = 0;

		}
		else if (_currentFrameX == 2 && _count % 12 == 0)
		{
			_currentFrameX = 3;
			_count = 0;
		}
		else if (_currentFrameX == 3 && _count % 12 == 0)
		{
			_currentFrameX = 0;
			_count = 0;
		}
		if (_currentFrameX >= 1)
		{
			
				_enemy.x += _enemy.speed;
		
		}

	}
	
		
		

		
	
	
}



void Slime::AttackStart()
{
	/*RECT temp;
	if (IntersectRect(&temp, &_enemy.rc, & _playerManager->get_vPlayer*/
}

bool Slime::bulletCountFire()

{

	_firecount++;

	if (_firecount % 44 == 0)
	{
		_firecount = 0;
		return true;
	}
	return false;

}

