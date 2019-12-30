#pragma once
#include"gameNode.h"
#include "itemManager.h"
#include"PlayerManager.h"
#include"MapManager.h"
#include "EnemyManager.h"
class GameScene:public gameNode
{
private:
	int count;

	int currentX;
	itemManager* _im;
	PlayerManager* _pm;
	MapManager* _mm;
	EnemyManager* _em;
public:
	
	GameScene();
	~GameScene();
	HRESULT init();
	void update();
	void render();
	void release();
};

