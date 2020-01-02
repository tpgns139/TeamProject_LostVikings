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

class PlayerManager;
class itemManager :public gameNode
{
private:
	vector<item*>				_vItem;
	vector<item*> ::iterator	_viItem;

	vector<Inven*> _vInven;
	vector<Inven*> ::iterator _viInven;
		


	PlayerManager* _pm;


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


