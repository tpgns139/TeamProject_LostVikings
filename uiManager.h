#pragma once
#include "gameNode.h"
#include "ui.h"
#include "Shoes.h"
#include "Key.h"
#include "Meat.h"
#include "Fruit.h"
#include "item.h"
#include "BaleogUi.h"
#include "EricUi.h"
#include "OlafUi.h"
#include "PlayerHpUi.h"
#include "SelectUi.h"
#include "Inven.h"


class uiManager : public gameNode
{
private:
	vector<ui*>				_vUi;
	vector<ui*>::iterator	_viUi;


	image* _ui;
	image* _playerHp;
	image* _Olaf;
	image* _Eric;
	image* _Baleog;
	image* _selectUi;
	image* _selectUi1;
	image* _selectUi2;
	int _currentPoint;
	int _currentHP;
	int _selectUiX, _selectUiY;

	POINTS pos;

public:
	uiManager();
	~uiManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void setUi();
	virtual image* getUiImage() { return _ui; }
	int setSelectUi() { int _SelectUiX; }
};

