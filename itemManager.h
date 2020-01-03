#pragma once
#include "gameNode.h"
#include "Shoes.h"
#include "Key.h"
#include "Meat.h"
#include "Fruit.h"
#include "item.h"
#include "uiManager.h"
#include "Inven.h"
#include <vector>

#include "uiManager.h"
#include "ui.h"
#include "Inven.h"
class PlayerManager;

class itemManager :public gameNode
{
private:
	vector<item*>				_vItem;
	vector<item*> ::iterator	_viItem;
	PlayerManager* _pm;
	image* _shoes;

	int _itemNum;
	RECT test;
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

};


