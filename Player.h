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
	PlayerName _playerName;
	RECT _rc;
	POINT position;
	int HP;
	int MaxHP;
	int count;
	int _CurrentFrameX, _CurrentFrameY;
	float gravity;
	float speed;
	bool isDrop; //떨어지는중이니
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