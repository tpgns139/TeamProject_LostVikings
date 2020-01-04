#pragma once
#include"Player.h"
#include "MapManager.h"

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
	MapManager* _mm;

	int headingCount;
	int stunCount;
	int jumpCount;

	int SuperJumpCount;
	float PlusJump;

	float PlusSpeed;
	
	
	bool isJump;	//점프중이니
	bool isAtk;	    //공격이니?
	
	


public:
	Erik() {};
	~Erik() {};
	 HRESULT init(PlayerName playerName);
	void update();
	void render();
	void KeyControl();
	void Frame(int FrameX);
	void stateImage();
	ERIKSTATE getState() { return _state; }
	void setState(ERIKSTATE state) { _state = state; }
	void setSpeed(float speed) { PlusSpeed = speed; }
	void setFrameX(int x) { _playerInfo._CurrentFrameX = x; }
	void setFrameY(int y) { _playerInfo._CurrentFrameY; }
	void colAction();
};

