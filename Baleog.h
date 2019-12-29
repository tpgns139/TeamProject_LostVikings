#pragma once
#include"Player.h"

enum BALEOGSTATE
{
	BALEOG_RIGHTIDLE,
	BALEOG_LEFTIDLE,
	BALEOG_RIGHTMOVE,
	BALEOG_LEFTMOVE,
	BALEOG_LEFTATTACK,
	BALEOG_RIGHTATTACK
};
class Baleog:public Player
{
public:
	Baleog();
	~Baleog();
	virtual HRESULT init(PlayerName playerName);
	virtual void update();
	virtual void render();
};

