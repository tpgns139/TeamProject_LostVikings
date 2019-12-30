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
	_Ebullet = new EnemyBullet;
	_Ebullet->init(50);


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

	//Enemy* Sl;
	//Sl = new Slime;

	//Sl->init("SlimeMove", PointMake(3560,1310));

	//_vEm.push_back(Sl);
	for (int i = 0; i < 2; i++)
	{
		Enemy* Sl;
		Sl = new Slime;

		Sl->init("SlimeMove", PointMake(1900+300*i, 1460));

		_vEm.push_back(Sl);
	}
//
////	collisionTestRect = RectMakeCenter(WINSIZEX / 2 + 200, WINSIZEY - 50, 20, 80);
//
//	Enemy* Sr;
//	Sr = new SecurityRobot;
//	Sr->init("SecurityRobotMove", PointMake(500,1375));
//	_vEm.push_back(Sr);
//
//	for (int i = 0; i < 2; i++) 
//	{
//		Enemy* Sr;
//		Sr = new SecurityRobot;
//		Sr->init("SecurityRobotMove", PointMake(2200+900*i,375));
//		_vEm.push_back(Sr);
//	}
//
//	Enemy* To;
//	To = new Tower;
//	To->init("Tower", PointMake(3850,1760));
//	_vEm.push_back(To);
//	

}

void EnemyManager::enemyBulletFire()
{
	for (int i = 0; i < _vEm.size(); i++)
	{
		RECT rc = _vEm[i]->getEnemyRect();

		_Ebullet->bulletFire(rc.left, (rc.top + rc.bottom) / 2, 5.0f);
	}
}
