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

enum Erik1
{
	E_ON,
	E_OFF,
	E_DEATH,
};
enum Baleog2
{
	B_ON,
	B_OFF,
	B_DEATH
};
enum Olaf3
{
	O_ON,
	O_OFF,
	O_DEATH
};
struct uiInfo 
{
	vector<item*> _itemList;
	vector<POINT> _itemPos;
};
class PlayerManager;
class uiManager : public gameNode
{
private:
	vector<ui*>				_vUi;
	vector<ui*>::iterator	_viUi;

	vector<ui*>				_vSelctUi;
	vector<ui*>::iterator	_viSelctUi;

	Erik1 _Erik1;
	Baleog2 _Baleog2;
	Olaf3 _Olaf3;

	image* _ui;
	image* _playerHp;
	image* Olaf;
	image* Erik;
	image* Baleog;
	image* _selectUi;
	image* _selectUi1;
	image* _selectUi2;
	int _selectUiX, _selectUiY;
	int _selectUiX1, _selectUiY1;
	int _selectUiX2, _selectUiY2;
	image* _selectUiFrame;
	int _currentPoint;
	int _currentFrameX;

	bool _select;
	int _selectNum;
	int _timeTick;

	POINTS pos;
	PlayerManager* _pm;

	vector<uiInfo*> _playerItemVector;

public:
	uiManager();
	~uiManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void setUi();
	virtual void setState();
	virtual image* getUiImage() { return _ui; }
	int setSelectUi() { int _SelectUiX; }
	void setPlayerManager(PlayerManager* pm) { _pm = pm; }
	void setSelect(bool select) { _select = select; }
};

