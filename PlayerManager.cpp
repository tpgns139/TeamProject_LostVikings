#include "stdafx.h"
#include "PlayerManager.h"
#include "MapManager.h"
#include "enemyManager.h"


PlayerManager::PlayerManager()
{
}


PlayerManager::~PlayerManager()
{
}

HRESULT PlayerManager::init()
{
	Player* _Erik = new Erik;	
	_Erik->init(PN_ERIK);
	_Erik->setLink(_MapManager);
	_vPlayer.push_back(_Erik);

	Player* _Baleog = new Baleog;	
	_Baleog->init(PN_BALEOG);
	_Baleog->setLink(_MapManager);
	_vPlayer.push_back(_Baleog);

	Player* _Olaf =  new Olaf;
	_Olaf->init(PN_OLAF);
	_Olaf->setLink(_MapManager);
	_vPlayer.push_back(_Olaf);
	

	_Pbullet = new Bullet;
	_Pbullet->init("화살");


	

	PlayerNumber = 0; 

	_nowPlayer = _vPlayer[PlayerNumber];
	CAMERA->setCameraPos(_nowPlayer->getPlayerPos().x, _nowPlayer->getPlayerPos().y);
	 //에릭->벨로그->올라프

	return S_OK;
}

void PlayerManager::update()
{

	if (KEYMANAGER->isOnceKeyDown(VK_CONTROL))
	{
		setNowPlayer();
		CAMERA->moveTo(_nowPlayer->getPlayerPos().x, _nowPlayer->getPlayerPos().y, 0.5f);
	}


	
	
	_Pbullet->update();
	_nowPlayer->KeyControl();
	colErikWithEnemy();

	if (KEYMANAGER->isOnceKeyDown('P'))
	{
		playerBulletFire();
	}
	if (!CAMERA->isMoving()) 
	{
		_nowPlayer->KeyControl();
		CAMERA->setCameraPos(_nowPlayer->getPlayerPos().x, _nowPlayer->getPlayerPos().y);
	}

	Bulletcollsion();

		
	                                                                                                                                              

	for (int i = 0;i < _vPlayer.size();i++)
	{
		_vPlayer[i]->update();		
	}
	
		RECT temp;
		if (IntersectRect(&temp, &((Olaf*)(_vPlayer[2]))->getShieldUp(), &_vPlayer[0]->getRect()))
		{
			_vPlayer[0]->setPlayerPosY(((Olaf*)(_vPlayer[2]))->getShieldUp().top);
			
		}

	
}

void PlayerManager::render()
{
	for (int i = 0; i < _vPlayer.size(); i++)
	{
		_vPlayer[i]->render();
	}


	_Pbullet->frameRender();
}

void PlayerManager::playerBulletFire()
{
	for (int i = 0; i < _vPlayer.size(); i++)
	{
		if (_vPlayer[i]->getPlayerInfo()->_playerName == PN_BALEOG)
		{
			RECT rc = _vPlayer[i]->getRect();
			if (_vPlayer[i]->getPlayerDirection() == LEFT) 
			{
				_Pbullet->FramebulletFire(_vPlayer[i]->getPlayerInfo()->position.x,
					_vPlayer[i]->getPlayerInfo()->position.y, 5.0f,0,1);
			}
			else
			{
				_Pbullet->FramebulletFire(_vPlayer[i]->getPlayerInfo()->position.x,
					_vPlayer[i]->getPlayerInfo()->position.y, -5.0f,0,0);
			}
		}
	}
}

void PlayerManager::setNowPlayer()
{
	PlayerNumber++;
	if (PlayerNumber >= _vPlayer.size())
	{
		PlayerNumber = 0;
	}

	_nowPlayer = _vPlayer[PlayerNumber];
	
}

void PlayerManager::Bulletcollsion()
{
	for (int i = 0; i < _MapManager->getColWall().size(); i++)
	{
		for (int j = 0; j < _Pbullet->getVBullet().size(); j++)
		{
			RECT temp;
			if (IntersectRect(&temp, &_Pbullet->getVBullet()[j].rc, &_MapManager->getColWall()[i]->getRect()))
			{
				_Pbullet->removePlayerBullet(j);

			}

		}
	}
	for (int i = 0; i < _em->getEnemy().size(); i++)
	{
		for (int j = 0; j < _Pbullet->getVBullet().size(); j++)
		{
			RECT temp;
			if (IntersectRect(&temp, &_Pbullet->getVBullet()[j].rc, &_em->getEnemy()[i]->getEnemyRect()))
			{
				_Pbullet->removeBullet(j); 
				_em->removeEnemy(i);
			}
		}
	}
	
}

void PlayerManager::colErikWithEnemy()
{
	if (_nowPlayer->getPlayerInfo()->_playerName == PN_ERIK)
	{
		if (((Erik*)_nowPlayer)->getState() == E_atk)
		{
			for (int i = 0;i < _em->getEnemy().size();i++)
			{
				RECT temp;
				if (IntersectRect(&temp, &_nowPlayer->getPlayerInfo()->_rc, &_em->getEnemy()[i]->getEnemyRect()))
				{
					_em->removeEnemy(i);
					((Erik*)_nowPlayer)->colAction();
				}
			}
		}
	}
}
