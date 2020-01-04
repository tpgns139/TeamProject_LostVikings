#pragma once
#include"gameNode.h"
enum startState
{
	intro1,
	intro2,
	intro3,
	intro4,

};
class IntroScene:public gameNode
{
private:
	startState _startState;
	int _fadeout, _fadein;
	bool start;
	bool start1;
	image* _nowScene;
public:
	IntroScene();
	~IntroScene();

	HRESULT init();
	void update();
	void render();
	void release();
};

