#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}

HRESULT Bullet::init(const char * imagename)
{
	
	_imgname = imagename;
	EFFECTMANAGER->addEffect("EnemyBulletDestroy", "¿¡³Ê¹ÌºÒ¸´ÀÌÆåÆ®.bmp", 150, 50, 50, 50, 1.0f, 0.2f, 50);
	EFFECTMANAGER->addEffect("PlayerBulletDestroy", "brokenarrow.bmp", 150, 20, 30, 20, 1.0f, 0.2f, 50);
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

		if (KEYMANAGER->isToggleKey(VK_F1))
		{
			
			(_backBuffer->getMemDC(), _viBullet->rc);
		}
		_viBullet->img->render(getMemDC(), _viBullet->rc.left - CAMERA->getCameraXpos(),_viBullet->rc.top - CAMERA->getCameraYpos());
		
	}
}

void Bullet::frameRender()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (KEYMANAGER->isToggleKey(VK_F1))
		{

			(_backBuffer->getMemDC(), _viBullet->rc);
		}
		_viBullet->img->frameRender(getMemDC(), _viBullet->rc.left - CAMERA->getCameraXpos(), _viBullet->rc.top - CAMERA->getCameraYpos(),_viBullet->img->getFrameX(), _viBullet->img->getFrameY());




	}
}
void Bullet::bulletFire(float x, float y, float speed)
{
	

	tagBullet bullet;	ZeroMemory(&bullet, sizeof(tagBullet));
	bullet.img = IMAGEMANAGER->findImage(_imgname);
	bullet.speed = speed;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;

	bullet.rc = RectMakeCenter(bullet.x, bullet.y, bullet.img->getWidth(), bullet.img->getHeight());
	_vBullet.push_back(bullet);
}
void Bullet::FramebulletFire(float x, float y, float speed,int frameX,int frameY)
{


	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	bullet.img = IMAGEMANAGER->findImage(_imgname);
	bullet.img->setFrameX(frameX);
	bullet.img->setFrameY(frameY);
	bullet.speed = speed;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;

	bullet.rc = RectMakeCenter(bullet.x, bullet.y, bullet.img->getWidth(), bullet.img->getHeight());
	_vBullet.push_back(bullet);
}
void Bullet::bulletMove()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		_viBullet->x -= _viBullet->speed;
		
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->img->getWidth(), _viBullet->img->getHeight());
		if (_viBullet->x - CAMERA->getCameraXpos() >WINSIZEX || _viBullet->x - CAMERA->getCameraXpos() <0)
		{
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;
	}
}

void Bullet::removeEnemyBullet(int arrNum)
{
	EFFECTMANAGER->play("EnemyBulletDestroy", (_vBullet.begin() + arrNum)->x, (_vBullet.begin() + arrNum)->y);
	_vBullet.erase(_vBullet.begin() + arrNum); 
}

void Bullet::removePlayerBullet(int arrNum)
{
	EFFECTMANAGER->play("PlayerBulletDestroy", (_vBullet.begin() + arrNum)->x, (_vBullet.begin() + arrNum)->y-10);
	_vBullet.erase(_vBullet.begin() + arrNum);
}

void Bullet::removeBullet(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum);
}
