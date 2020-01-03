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
	IMAGEMANAGER->addFrameImage("SlimeMove", "�������̵�.bmp", 336, 163, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("SlimeAtk", "�����Ӱ���.bmp", 168, 152, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("SecurityRobotMove", "���κ��̵�.bmp", 420, 132, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("SecurityRobotAtk", "���κ�����.bmp", 210, 135, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Tower", "��ž.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));

	_currentFrameX = _currentFrameY = 0;
	

	_enemy.img = IMAGEMANAGER->findImage(imagename);
	_enemy.x = position.x;
	_enemy.y = position.y+_enemy.img->getFrameHeight()/2;
	_enemy.rc = RectMakeCenter(_enemy.x, _enemy.y, _enemy.img->getFrameWidth(), _enemy.img->getFrameHeight());
	_enemy.leftcolcheckrc = RectMakeCenter(_enemy.x- _enemy.img->getFrameWidth()/2, _enemy.y, 3, _enemy.img->getFrameHeight()-10);
	_enemy.rightcolcheckrc = RectMakeCenter(_enemy.x - _enemy.img->getFrameWidth() / 2, _enemy.y, 3, _enemy.img->getFrameHeight()-10);
	_count = 0;
	_count2 = 0;

	

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
		if (IntersectRect(&temp, & _mapManager->getColWall()[i] ->getRect(), &_enemy.rightcolcheckrc))//||_enemy.x + (_enemy.img->getFrameWidth()) >WINSIZEX+CAMERA->getCameraXpos()) <-�÷��̾� ����� ���� ó���ؾ���,ī�޶� �������� �ʴ� ���� �߰�
		{
			_enemy.speed *= -1;
			_currentFrameX = 1;
		}
		if (IntersectRect(&temp, &_mapManager->getColWall()[i]->getRect(), &_enemy.leftcolcheckrc))//||_enemy.x<0+CAMERA->getCameraXpos())
		{
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


