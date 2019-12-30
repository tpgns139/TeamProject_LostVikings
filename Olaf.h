#pragma once
#include"Player.h"
class Olaf:public Player
{
public:
	Olaf();
	~Olaf();
	virtual HRESULT init(PlayerName playerName);
	virtual void update();
	virtual void render();
};

