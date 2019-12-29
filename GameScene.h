#pragma once
#include"gameNode.h"
#include "itemManager.h"
#include"PlayerManager.h"
class GameScene:public gameNode
{
private:
	int count;

	int currentX;
	itemManager* _im;
	PlayerManager* _pm;
public:
	
	GameScene();
	~GameScene();
	HRESULT init();
	void update();
	void render();
	void release();
};

