#pragma once
#include"Player.h"
#include "Erik.h"
#include "Baleog.h"
#define SIZE 15

enum OLAFSTATE
{
	O_front_idle1,
	O_front_idle2,
	O_front_idle3,
	O_top_idle1,
	O_top_idle2,

	O_attcked1,
	O_die,
	O_die_divide,
	O_die_electric,
	O_die_fall,
	O_drop,
	O_drop_after,
	O_fly1,
	O_fly2,

	O_front_run,
	O_jump,
	O_push,
	O_top_run,
	O_up,
	O_up_end
};

class Olaf:public Player
{
private:

	OLAFSTATE _Ostate;

	RECT shield;
	bool shieldPosision; //true일때 top //false일때 정면
	


	RECT shieldUp;	//방패
	RECT shieldFront;	//방패
	
	int shieldX; //방패x좌표값


public:
	Olaf();
	~Olaf();
	virtual HRESULT init(PlayerName playerName);
	virtual void update();
	virtual void render();
	void KeyControl();
	void Frame(int FrameX);
	void _dis();
	void shiedMake();

	RECT getShieldUp() { return shieldUp; }
	RECT getShieldFront() { return shieldFront; }
	
};


