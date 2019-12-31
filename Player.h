#pragma once
#include"gameNode.h"

enum PlayerName {
	PN_ERIK,
	PN_BALEOG,
	PN_OLAF
};
enum Direction
{
	RIGHT,
	LEFT
};
struct Playerinfo
{
	image* _image;
	PlayerName _playerName;
	RECT _rc, _underRc;
	
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
	Direction _Direction;

public:
	Player();
	~Player();
	
	virtual HRESULT init(PlayerName playerName);
	void MakeRect();
	virtual void update();
	virtual void render();
	virtual void KeyControl();	//각자 입력받을 KeyControl()함수
	void move();				//공통으로 움직일 함수;
};