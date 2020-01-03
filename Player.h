#pragma once
#include"gameNode.h"
#include "item.h"
#define RCSIZE 15
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
	RECT _rc, _underRc, _leftRc, _rightRc, _topRC, _ladderRC,_midRC;

	POINT position;
	int HP;
	int MaxHP;
	int count;
	int _CurrentFrameX, _CurrentFrameY;
	float gravity;
	float speed;
	float jumpPower;
	bool isDrop; //떨어지는중이니
	bool isGround; //땅이니?
	bool isLadder; //사다리 상태니?
	bool isJump;
	bool isPush;
	bool isLadderEnd;
	bool isLadderEnd2;
	float _underRcBottom;

	vector<item*> _vPlayerItem;
};

class MapManager;

class Player :public gameNode
{
protected:
	
	Playerinfo _playerInfo;
	Direction _Direction;
	MapManager* _MapManager;

	


public:
	Player();
	~Player();
	
	virtual HRESULT init(PlayerName playerName);
	void MakeRect();
	virtual void update();
	virtual void render();
	virtual void KeyControl();	//각자 입력받을 KeyControl()함수
	void move();				//공통으로 움직일 함수;


	virtual RECT getRect() { return _playerInfo._rc; }
	void collsion();
	void Jumpcollsion();
	void setLink(MapManager* MapManager) { _MapManager = MapManager; }
	POINT getPlayerPos() { return _playerInfo.position; }

	void setPlayerPosY(float y) { _playerInfo.position.y = y; }
	

	void setDrop(bool check) { _playerInfo.isDrop = check; }
	void setGround(bool check) { _playerInfo.isGround = check; }


	Playerinfo* getPlayerInfo() { return &_playerInfo; }
	Direction getPlayerDirection() { return _Direction; }
	

};