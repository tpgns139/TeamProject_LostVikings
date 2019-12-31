#pragma once
#include"Player.h"

enum ERIKSTATE
{
	E_idle1,
	E_idle2,
	E_idle3,
	E_jump,
	E_up,
	E_drop,
	E_run,
	E_atk,
	E_attcked1,
	E_attack_after,
	E_up_end,
	E_push,
	E_die,
	E_die_divide,
	E_die_electric,
	E_die_falls
};


class Erik: public Player
{
private:

	ERIKSTATE _state;
	RECT test;
	RECT test2;

	int headingCount;
	int stunCount;

	float PlusSpeed;
	float jumpPower; //점프력
	bool isJump;	//점프중이니
	bool isAtk;	    //공격이니?
public:
	Erik();
	~Erik();
	 HRESULT init(PlayerName playerName);
	void update();
	void render();
	void KeyControl();
	void Frame(int FrameX);
	
	
};

