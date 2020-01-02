#include "stdafx.h"

#include "EnemyManager.h"



EnemyManager::EnemyManager()
{
}


EnemyManager::~EnemyManager()
{
}

HRESULT EnemyManager::init()
{
	setEnemy(); //���ʹ̸� �������ִ� �Լ�
	_Ebullet = new Bullet;
	_Ebullet->init("���ʹ̺Ҹ�");
	collisionTestRect = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 30, 30);

	return S_OK;
}

void EnemyManager::release()
{
}

void EnemyManager::update()
{

	for (_viEm = _vEm.begin(); _viEm != _vEm.end(); ++_viEm)
	{
		(*_viEm)->update();
	}
	_Ebullet->update();
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		enemyBulletFire();
	}
	collision();
	
}

void EnemyManager::render()
{
	for (_viEm = _vEm.begin(); _viEm != _vEm.end(); ++_viEm)
	{
		(*_viEm)->render();
	}
	_Ebullet->render();
	//Rectangle(getMemDC(),collisionTestRect);
}

void EnemyManager::setEnemy()
{
	{
		Enemy* Sl;
		Sl = new Slime;
		Sl->init("SlimeMove", PointMake(3560, 1310), 0,3);
		Sl->setMemoryAddressLink(_mapManager);
		_vEm.push_back(Sl);
	}

	{
		Enemy* Sl;
		Sl = new Slime;
		Sl->init("SlimeMove1", PointMake(2200, 1460), 1,3);
		Sl->setMemoryAddressLink(_mapManager);
		_vEm.push_back(Sl);
	}

	{
		Enemy* Sl;
		Sl = new Slime;
		Sl->init("SlimeMove2", PointMake(1400, 1460), 2,-3);
		Sl->setMemoryAddressLink(_mapManager);
		_vEm.push_back(Sl);
	}

	{
		Enemy* Sr;
		Sr = new SecurityRobot;
		Sr->init("SecurityRobotMove", PointMake(500, 1375), 0,3);
		Sr->setMemoryAddressLink(_mapManager);
		_vEm.push_back(Sr);
	}


	{
		Enemy* Sr;
		Sr = new SecurityRobot;
		Sr->init("SecurityRobotMove1", PointMake(3400, 375), 1,-3);
		Sr->setMemoryAddressLink(_mapManager);
		_vEm.push_back(Sr);
	}

	{
		Enemy* Sr;
		Sr = new SecurityRobot;
		Sr->init("SecurityRobotMove2", PointMake(2700, 375), 2,-3);
		Sr->setMemoryAddressLink(_mapManager);
		_vEm.push_back(Sr);
	}

	{
		Enemy* Sr;
		Sr = new SecurityRobot;
		Sr->init("SecurityRobotMove3", PointMake(2000, 375), 3,3);
		Sr->setMemoryAddressLink(_mapManager);
		_vEm.push_back(Sr);
	}
	{
		Enemy* To;
		To = new Tower;
		To->init("Tower", PointMake(3850, 1760),0,0);
		To->setMemoryAddressLink(_mapManager);
		_vEm.push_back(To);
	}
	

}

void EnemyManager::enemyBulletFire()
{
	for (int i = 0; i < _vEm.size(); i++)
	{
		RECT rc = _vEm[i]->getEnemyRect();

		_Ebullet->bulletFire(_vEm[i]->getX() + _vEm[i]->getEnemyInfo().img->getFrameWidth(), _vEm[i]->getY() + _vEm[i]->getEnemyInfo().img->getFrameHeight()/2, 2.0f);
	}
}

void EnemyManager::collision()
{
	RECT temp;

	for (int i = 0; i <_Ebullet->getVBullet().size();i++)
	{
		if (IntersectRect(&temp, &_Ebullet->getVBullet()[i].rc, &collisionTestRect))
		{
			_Ebullet->removeBullet(i);
		}
	}


}
