#pragma once
#include"gameNode.h"

enum PlayerName {
	PN_ERIK,
	PN_BALEOG,
	PN_OLAF
};
enum direction
{
	RIGHT,
	LEFT
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
	bool isLadder; //사다리 상태니?

};
class Player :public gameNode
{
protected:

	Playerinfo _playerInfo;
	direction _dir; //왼쪽 오른쪽 방향

public:
	Player();
	~Player();
	virtual HRESULT init(PlayerName playerName);
	virtual void update();
	virtual void render();
	virtual void KeyControl();	//각자 입력받을 KeyControl()함수
	void move();				//공통으로 움직일 함수;

	virtual RECT getRect() { return _playerInfo._rc; }
};