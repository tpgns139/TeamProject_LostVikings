#pragma once
#include"gameNode.h"
enum PlayerName {
	PN_ERIK,
	PN_BALEOG,
	PN_OLAF
};
struct Playerinfo
{
	image* _image;
	RECT _rc;
	POINT position;
	int HP;
	int MaxHP;
	int count;
	int _CurrentFrameX, _CurrentFrameY;
	PlayerName _playerName;
};
class Player :public gameNode
{
protected:

	Playerinfo _playerInfo;

public:
	Player();
	~Player();
	virtual HRESULT init(PlayerName playerName);
	virtual void update();
	virtual void render();
};