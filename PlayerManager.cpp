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

	_nowPlayer = _vPlayer[PlayerNumber];

	
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
		//CAMERA->moveTo(_nowPlayer->getPlayerPos().x+CAMERA->getCameraXpos(),
			//_nowPlayer->getPlayerPos().y+CAMERA->getCameraYpos(),
			//2.0f);
		CAMERA->moveTo(WINSIZEX, WINSIZEY, 2.0f);
	}
	

	_nowPlayer->update();

}

void PlayerManager::render()
{
	for (int i = 0; i < _vPlayer.size(); i++)
	{
		_vPlayer[i]->render();
	}

}