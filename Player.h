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
	bool isDrop; //�����������̴�
	bool isLadder; //��ٸ� ���´�?

};
class Player :public gameNode
{
protected:

	Playerinfo _playerInfo;
	direction _dir; //���� ������ ����

public:
	Player();
	~Player();
	virtual HRESULT init(PlayerName playerName);
	virtual void update();
	virtual void render();
	virtual void KeyControl();	//���� �Է¹��� KeyControl()�Լ�
	void move();				//�������� ������ �Լ�;

	virtual RECT getRect() { return _playerInfo._rc; }
};