#include "stdafx.h"
#include "Enemy.h"
#include "MapManager.h"

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

HRESULT Enemy::init(const char* imagename, POINT position, int num,float speed)
{
	
	_currentFrameX = _currentFrameY = 0;
	
	_enemy.speed = speed;
	_enemy.img = IMAGEMANAGER->findImage(imagename);
	_enemy.x = position.x;
	_enemy.y = position.y+_enemy.img->getFrameHeight()/2;
	_enemy.rc = RectMakeCenter(_enemy.x, _enemy.y, _enemy.img->getFrameWidth(), _enemy.img->getFrameHeight());
	_enemy.leftcolcheckrc = RectMakeCenter(_enemy.x- _enemy.img->getFrameWidth()/2, _enemy.y, 3, _enemy.img->getFrameHeight()-10);
	_enemy.rightcolcheckrc = RectMakeCenter(_enemy.x - _enemy.img->getFrameWidth() / 2, _enemy.y, 3, _enemy.img->getFrameHeight()-10);
	_count = 0;
	_count2 = 0;
	_enemy._enemyDirection = e_Left;
	

	return S_OK;
}

void Enemy::release()
{
}

void Enemy::update()
{

	_enemy.rc = RectMakeCenter(_enemy.x ,
		_enemy.y, _enemy.img->getFrameWidth(), _enemy.img->getFrameHeight());
	_enemy.leftcolcheckrc = RectMakeCenter(_enemy.x , _enemy.y + _enemy.img->getFrameHeight() / 2
		, 10, _enemy.img->getFrameHeight()-10);
	_enemy.rightcolcheckrc = RectMakeCenter(_enemy.x + _enemy.img->getFrameWidth(), _enemy.y + _enemy.img->getFrameHeight() / 2
		, 10, _enemy.img->getFrameHeight()-10);
	RECT temp;
	for (int i = 0; i < _mapManager->getColWall().size(); i++)
	{
		if (IntersectRect(&temp, & _mapManager->getColWall()[i] ->getRect(), &_enemy.rightcolcheckrc))//||_enemy.x + (_enemy.img->getFrameWidth()) >WINSIZEX+CAMERA->getCameraXpos()) <-플레이어 무브랑 같이 처리해야함,카메라가 움직이지 않는 조건 추가
		{
			_enemy._enemyDirection = e_Left;
			_enemy.speed *= -1;
			_currentFrameX = 1;
		}
		if (IntersectRect(&temp, &_mapManager->getColWall()[i]->getRect(), &_enemy.leftcolcheckrc))//||_enemy.x<0+CAMERA->getCameraXpos())
		{
			_enemy._enemyDirection = e_Right;
			_enemy.speed *= -1;
			_currentFrameX = 2;
		}
	
	}

}

void Enemy::render()
{
	

	_enemy.img->frameRender(getMemDC(), _enemy.rc.left - CAMERA->getCameraXpos(), _enemy.rc.top - CAMERA->getCameraYpos());


}

void Enemy::AttackStart()
{
}



bool Enemy::bulletCountFire()
{
	
	return false;
}


