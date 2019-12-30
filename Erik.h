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

	

	float PlusSpeed;
	float jumpPower; //점프력
	bool isJump;	//점프중이니
	ERIKSTATE _state;
public:
	Erik();
	~Erik();
	virtual HRESULT init(PlayerName playerName);
	virtual void update();
	virtual void render();
	void state();
};

