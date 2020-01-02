#pragma once
#include"Player.h"

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
	


public:
	Olaf();
	~Olaf();
	virtual HRESULT init(PlayerName playerName);
	virtual void update();
	virtual void render();
	void KeyControl();
	void Frame(int FrameX);
};

