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
	PlayerNumber = 0;

	_Pbullet = new Bullet;
	_Pbullet->init("왼쪽화살");

	PlayerNumber = 2; //일단 올라프테스트하기위에 넣음 나중에지워야함

	_nowPlayer = _vPlayer[PlayerNumber];
	CAMERA->setCameraPos(_nowPlayer->getPlayerPos().x, _nowPlayer->getPlayerPos().y);
	 //에릭->벨로그->올라프

	return S_OK;
}

void PlayerManager::update()
{

	if (KEYMANAGER->isOnceKeyDown(VK_CONTROL))
	{
		PlayerNumber++;
		if (PlayerNumber >= _vPlayer.size())
		{
			PlayerNumber = 0;
		}
	
		_nowPlayer = _vPlayer[PlayerNumber];
		CAMERA->moveTo(_nowPlayer->getPlayerPos().x, _nowPlayer->getPlayerPos().y, 0.5f);
	}

	_Pbullet->update();
	if (_nowPlayer->getPlayerInfo()->_playerName == PN_BALEOG)
	{
		cout << _nowPlayer->getPlayerDirection() << endl;
	}
	if (KEYMANAGER->isOnceKeyUp('F'))
	{
		
		if (_nowPlayer->getPlayerInfo()->_playerName == PN_BALEOG) 
		{
			playerBulletFire();
			((Baleog*)_nowPlayer)->clickedFbutton();
			cout << _nowPlayer->getPlayerDirection() << endl;
		}

	}
	_nowPlayer->KeyControl();
	if (!CAMERA->isMoving()) 
	{
		_nowPlayer->KeyControl();
		CAMERA->setCameraPos(_nowPlayer->getPlayerPos().x, _nowPlayer->getPlayerPos().y);
	}


	

	for (int i = 0;i < _vPlayer.size();i++)
	{
		_vPlayer[i]->update();
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

	RECT rc = _nowPlayer->getRect();
	if (_nowPlayer->getPlayerDirection() == RIGHT) 
	{
		_Pbullet->bulletFire(rc.right,
			(rc.top + rc.bottom) / 2 + 50, -5.0f);
	}
	else if (_nowPlayer->getPlayerDirection() == LEFT)
	{
		_Pbullet->bulletFire(rc.left,
			(rc.top + rc.bottom) / 2 + 50, 5.0f);
	}
	
}
