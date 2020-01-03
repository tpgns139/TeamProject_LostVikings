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
	setEnemy(); //에너미를 세팅해주는 함수
	_Ebullet = new Bullet;
	_Ebullet->init("에너미불릿");
	
	
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

		if ((*_viEm)->getEnemyInfo().name == slime)
		{
			
			if ((*_viEm)->getEnemyInfo().speed < 0)
			{
				enemyBulletFire((*_viEm),RIGHT);
			}
			else
			{
				enemyBulletFire((*_viEm),LEFT);
			}


			cout << (*_viEm)->getEnemyInfo().speed << endl;
		}

		
	}

	_Ebullet->update();
	collision();

	
	
	
	
	
	
}

void EnemyManager::render()
{
	for (_viEm = _vEm.begin(); _viEm != _vEm.end(); ++_viEm)
	{
		(*_viEm)->render();
	}
	_Ebullet->render();
	
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
		To->init("Tower", PointMake(3850, 1760),0,-3);
		To->setMemoryAddressLink(_mapManager);
		_vEm.push_back(To);
	}
	

}



void EnemyManager::enemyBulletFire(Enemy* enemy, Direction _direction)
{

	if (enemy->bulletCountFire())

	{
		RECT rc = enemy->getEnemyRect();

		if (_direction == LEFT)
		{
			_Ebullet->bulletFire(enemy->getX(),
				enemy->getY(), -5.0f);
		}
		else
		{
			_Ebullet->bulletFire(enemy->getX(),
				enemy->getY(), 5.0f);
		}
	}
}


void EnemyManager::collision()
{
	RECT temp;
	for (int j = 0; j < _mapManager->getColWall().size(); j++)
	{

	
		for (int i = 0; i < _Ebullet->getVBullet().size(); i++)
		{
			if (IntersectRect(&temp, &_Ebullet->getVBullet()[i].rc, &_mapManager->getColWall()[j]->getRect()))
			{
				cout << i << endl;
				_Ebullet->removeBullet(i);
			}

		}
	}

}
