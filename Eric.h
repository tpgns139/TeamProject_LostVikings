#pragma once
#include"Player.h"
class Eric:public Player
{
public:
	Eric();
	~Eric();
	virtual HRESULT init(PlayerName playerName);
	virtual void update();
	virtual void render();
};

