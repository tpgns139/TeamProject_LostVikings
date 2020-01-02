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
	/*Player* _Baleog = new Baleog;
	_Baleog->init(PN_BALEOG);
	_Baleog->setLink(_MapManager);
	_vPlayer.push_back(_Baleog);*/

	Player* _Erik = new Erik;
	_Erik->init(PN_ERIK);
	_Erik->setLink(_MapManager);
	_vPlayer.push_back(_Erik);


	Player* _Olaf =  new Olaf;
	_Olaf->init(PN_OLAF);
	_Olaf->setLink(_MapManager);
	_vPlayer.push_back(_Olaf);

	_nowPlayer = _Erik;
	return S_OK;
}

void PlayerManager::update()
{
	_nowPlayer->update();
}

void PlayerManager::render()
{
	for (int i = 0; i < _vPlayer.size(); i++)
	{
		_vPlayer[i]->render();
	}

}