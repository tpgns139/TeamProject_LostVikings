#include "stdafx.h"
#include "PlayerManager.h"
#include "MapManager.h"


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
	_Pbullet->init("왼쪽화살");


	

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
	

	if (KEYMANAGER->isOnceKeyDown('P'))
	{
		playerBulletFire();
	}
	if (!CAMERA->isMoving()) 
	{
		_nowPlayer->KeyControl();
		//CAMERA->setCameraPos(_nowPlayer->getPlayerPos().x, _nowPlayer->getPlayerPos().y);
	}

		
	

	for (int i = 0;i < _vPlayer.size();i++)
	{
		_vPlayer[i]->update();
		//static_cast<Olaf*>(_vPlayer[2])->getShield();
		
	}

}

void PlayerManager::render()
{
	for (int i = 0; i < _vPlayer.size(); i++)
	{
		_vPlayer[i]->render();
	}
	_Pbullet->render();
	

}

void PlayerManager::playerBulletFire()
{
	for (int i = 0; i < _vPlayer.size(); i++)
	{
		if (_vPlayer[i]->getPlayerInfo()->_playerName == PN_BALEOG)
		{
			RECT rc = _vPlayer[i]->getRect();

			_Pbullet->bulletFire(rc.left,
				(rc.top + rc.bottom) / 2 + 50, 5.0f);
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
