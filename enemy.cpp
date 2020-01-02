#include "stdafx.h"
#include "Enemy.h"
#include "MapManager.h"

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

HRESULT Enemy::init(const char* imagename, POINT position)
{
	IMAGEMANAGER->addFrameImage("SlimeMove", "슬라임이동.bmp", 336, 163, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("SlimeAtk", "슬라임공격.bmp", 168, 152, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("SecurityRobotMove", "경비로봇이동.bmp", 420, 132, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("SecurityRobotAtk", "경비로봇공격.bmp", 210, 135, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Tower", "포탑.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));

	_currentFrameX = _currentFrameY = 0;
	_enemy.x = position.x;
	_enemy.y = position.y;

	_enemy.img = IMAGEMANAGER->findImage(imagename);
	_enemy.rc = RectMakeCenter(position.x, position.y, _enemy.img->getFrameWidth(), _enemy.img->getFrameHeight());
	_enemy.leftcolcheckrc = RectMakeCenter(position.x- _enemy.img->getFrameWidth()/2, position.y, 3, _enemy.img->getFrameHeight()-10);
	_enemy.rightcolcheckrc = RectMakeCenter(position.x - _enemy.img->getFrameWidth() / 2, position.y, 3, _enemy.img->getFrameHeight()-10);
	_count = 0;


	_rndFireCount = RND->getFromIntTo(1, 100);

	return S_OK;
}

void Enemy::release()
{
}

void Enemy::update()
{
	/*_enemy.rc = RectMakeCenter(_enemy.x - CAMERA->getCameraXpos() + _enemy.img->getFrameWidth() / 2,
		_enemy.y - CAMERA->getCameraYpos() + _enemy.img->getFrameHeight() / 2, _enemy.img->getFrameWidth(), _enemy.img->getFrameHeight());*/
	_enemy.leftcolcheckrc = RectMakeCenter(_enemy.x , _enemy.y + _enemy.img->getFrameHeight() / 2
		, 10, _enemy.img->getFrameHeight()-10);
	_enemy.rightcolcheckrc = RectMakeCenter(_enemy.x + _enemy.img->getFrameWidth(), _enemy.y  + _enemy.img->getFrameHeight() / 2
		, 10, _enemy.img->getFrameHeight()-10);
	RECT temp;
	for (int i = 0; i < _mapManager->getWall().size(); i++)
	{
		if (IntersectRect(&temp, &_mapManager->getWall()[i]->getRect(), &_enemy.rightcolcheckrc))
		{
			_enemy.speed *= -1;
		}
		if (IntersectRect(&temp, &_mapManager->getWall()[i]->getRect(), &_enemy.leftcolcheckrc))
		{
			_enemy.speed *= -1;
		}
	
	}
}

void Enemy::render()
{
	_enemy.img->frameRender(getMemDC(), _enemy.x - CAMERA->getCameraXpos(), _enemy.y - CAMERA->getCameraYpos());
}

void Enemy::move()
{
}


