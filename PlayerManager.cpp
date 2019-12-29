#include "stdafx.h"
#include "PlayerManager.h"


PlayerManager::PlayerManager()
{
}


PlayerManager::~PlayerManager()
{
}

HRESULT PlayerManager::init()
{
	Player* _Baleog = new Baleog;
	_Baleog->init(PN_BALEOG);
	_vPlayer.push_back(_Baleog);

	return S_OK;
}

void PlayerManager::update()
{
	for (int i = 0; i < _vPlayer.size(); i++)
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
}