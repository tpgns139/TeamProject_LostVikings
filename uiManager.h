#pragma once
#include "gameNode.h"
#include "ui.h"
#include "Shoes.h"
#include "Key.h"
#include "Meat.h"
#include "Fruit.h"
#include "item.h"


class uiManager : public gameNode
{
private:
	image* _ui;
	image* _playerHp;
	image* _Olaf;
	image* _Eric;
	image* _Baleog;
	image* _selectUi;



public:
	uiManager();
	~uiManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


};

