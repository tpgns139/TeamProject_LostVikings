#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}

HRESULT Bullet::init()
{
	


	return S_OK;
}

void Bullet::release()
{
}

void Bullet::update()
{
	bulletMove();
}

void Bullet::render()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		
		Rectangle(_backBuffer->getMemDC(), _viBullet->rc);
		
		
	}
}

void Bullet::bulletFire(float x, float y, float speed)
{
	

	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	
	bullet.speed = speed;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;

	bullet.rc = RectMakeCenter(bullet.x, bullet.y,10,10);
	_vBullet.push_back(bullet);
}

void Bullet::bulletMove()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		_viBullet->x += _viBullet->speed;
		
		_viBullet->rc = RectMakeCenter(_viBullet->x - CAMERA->getCameraXpos(), _viBullet->y - CAMERA->getCameraYpos(),
			10,10);
		if (_viBullet->x - CAMERA->getCameraXpos() >WINSIZEX || _viBullet->x - CAMERA->getCameraXpos() <0)
		{
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;
	}
}

void Bullet::removeBullet(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum); 
}

