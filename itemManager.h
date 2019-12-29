#pragma once
#include "gameNode.h"
#include "Shoes.h"
#include "Key.h"
#include "Meat.h"
#include "Fruit.h"
#include "item.h"
#include <vector>

class itemManager :public gameNode
{
private:
	vector<item*>				_vItem;
	vector<item*> ::iterator	_viItem;



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
	//void setPlayerMemoryAdrressLink(player* player) { _player = player; }

};


