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
struct itemKind
{
	int Fruit;
	int Meat;
	int Key;
	int Shoes;
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
	float jumpPower;
	bool isDrop; //�����������̴�
	bool isLadder; //��ٸ� ���´�?

};


class MapManager;

class Player :public gameNode
{
protected:

	Playerinfo _playerInfo;
	Direction _Direction;
	itemKind _itemKind;

	MapManager* _MapManager;

public:
	Player();
	~Player();
	
	virtual HRESULT init(PlayerName playerName);
	void MakeRect();
	virtual void update();
	virtual void render();
	virtual void KeyControl();	//���� �Է¹��� KeyControl()�Լ�
	void move();				//�������� ������ �Լ�;
	virtual RECT getRect() { return _playerInfo._rc; }
	void collsion();
	void setLink(MapManager* MapManager) { _MapManager = MapManager; }

};