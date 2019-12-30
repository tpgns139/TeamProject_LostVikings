#include "stdafx.h"
#include "EnemyBullet.h"


EnemyBullet::EnemyBullet()
{
}


EnemyBullet::~EnemyBullet()
{
}

HRESULT EnemyBullet::init(int bulletMax)
{
	_bulletMax = bulletMax;


	return S_OK;
}

void EnemyBullet::release()
{
}

void EnemyBullet::update()
{
	bulletMove();
}

void EnemyBullet::render()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		//_viBullet-> (getMemDC(), _viBullet->rc.left, _viBullet->rc.top);
		 
		if (KEYMANAGER->isToggleKey(VK_F1))
		{
			Rectangle(getMemDC(), _viBullet->rc);
		}
	}
}

void EnemyBullet::bulletFire(float x, float y, float speed)
{
	if (_bulletMax < _vBullet.size()) return;

	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	//bullet.img = IMAGEMANAGER->findImage()
	bullet.speed = speed;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;

	bullet.rc = RectMakeCenter(bullet.x, bullet.y,10,10);
	_vBullet.push_back(bullet);
}

void EnemyBullet::bulletMove()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->x += _viBullet->speed;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			10,10);
		
	}
}

void EnemyBullet::removeBullet(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum); 
}

