#pragma once
#include"gameNode.h"
enum startState
{
	intro1,
	intro2,
	intro3,
	intro4,
	base
};
class IntroScene:public gameNode
{
private:
	startState _startState;
public:
	IntroScene();
	~IntroScene();

	HRESULT init();
	void update();
	void render();
	void release();
};

