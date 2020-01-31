#pragma once
#include "gameNode.h"
#include "Shoes.h"
#include "Key.h"
#include "Meat.h"
#include "Fruit.h"
#include "item.h"
//#include "uiManager.h"
#include "Inven.h"
#include <vector>
#include "ui.h"

#include "action.h"


#define PI 3.14
#define DO PI/180

static image* _meat = NULL;
static action* actionTest;

class PlayerManager;
class uiManager;
class itemManager :public gameNode
{
private:
	vector<item*>				_vItem;
	vector<item*> ::iterator	_viItem;
	PlayerManager* _pm;
	uiManager* _um;
	image* _shoes;
	int _shoesX, _shoesY;
	image* _meat;
	image* _fruit;
	int _itemNum;
	RECT test;
	int _rndItemCount;
	action* _action;
	bool itemfire = false;
	float _x;
	float _y;
	float _angle;
	float angle;
	bool move;
	int score;
	image* _number[10];
	
	image* itemBox;
	animation* itembox;
	int boxX, boxY;
	int _currentFrameX;
	RECT _rc2;
	bool start;


public:
	itemManager();
	~itemManager();



	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void setItem();
	virtual void collision();
	virtual void removeItem(int arrNum);



	
	void setPlayerMemoryAdrressLink(PlayerManager* player) { _pm = player; }
	void setuiMemoryAdrressLink(uiManager* ui) { _um = ui; }


};


