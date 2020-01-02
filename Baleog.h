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
	BALEOG_LEFTBOWATTACK,
	BALEOG_PUSH,
	BALEOG_UP,

};

class Baleog :public Player
{
private:
	BALEOGSTATE _BaleogState;
public:
	Baleog();
	~Baleog();
	virtual HRESULT init(PlayerName playerName);
	virtual void update();
	virtual void render();
	void clickedFbutton();
	void KeyControl();
	void Frame();
};

