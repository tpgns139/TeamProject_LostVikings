#pragma once
#include"Player.h"

enum BALEOGSTATE
{
	BALEOG_RIGHTIDLE,
	BALEOG_LEFTIDLE,
	BALEOG_RIGHTMOVE,
	BALEOG_LEFTMOVE,
	BALEOG_LEFTATTACK,
	BALEOG_RIGHTATTACK,
	BALEOG_RIGHTBOWATTACK,
	BALEOG_LEFTBOWATTACK
};

class Baleog:public Player
{
private:
	BALEOGSTATE _BaleogState;
	Direction _Direction;
	RECT rc;
public:
	Baleog();
	~Baleog();
	virtual HRESULT init(PlayerName playerName);
	virtual void update();
	virtual void render();

	void Keycontrol();
	void Frame();
};

