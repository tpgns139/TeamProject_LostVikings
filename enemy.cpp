#include "stdafx.h"
#include "Enemy.h"


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
	_count = 0;


	_rndFireCount = RND->getFromIntTo(1, 100);

	return S_OK;
}

void Enemy::release()
{
}

void Enemy::update()
{

}

void Enemy::render()
{
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		Rectangle(getMemDC(), _enemy.rc);
	}
	_enemy.img->frameRender(getMemDC(), _enemy.x - CAMERA->getCameraXpos(), _enemy.y - CAMERA->getCameraYpos());
}

void Enemy::move()
{
}


