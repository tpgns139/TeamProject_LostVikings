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
#include "pointer.h"
#include "itemManager.h"
#include "skillPointer.h"
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

	/*vector<ui*>				_vSelctUi;
	vector<ui*>::iterator	_viSelctUi;*/

	vector<ui*>				_vPointer;
	vector<ui*>::iterator	_viPointer;

	vector<ui*>				_vSkillPointer;
	vector<ui*>::iterator	_viSkillPointer;

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
	bool _eric;
	bool _baleog;
	bool _olaf;
	
	bool _select;
	int _selectNum;
	int _timeTick;
	int _itemNum;
	POINTS pos;
	PlayerManager* _pm;

	RECT _rc[3][4];
	int _box[3]; 
	int _box2[3];

	vector<uiInfo*> _playerItemVector;

	bool _goSelect;


	image* _inven;
	bool stay = false;
	image* _itemBox;
	image* _pointer;
	image* _pointer1;
	image* _pointer2;
	int _pointerX, _pointerY;
	int _pointerX1, _pointerY1;
	RECT _rc2[12];
	int box[11];
	int num;
	int count;
	bool item;
	bool stay2;
	bool stay3;
	image* _list1;
	image* _list2;
	image* _skillInven;
	image* itemOn;
	image* itemOff;
	image* wizardOn;
	image* wizardOff;
	image* worriorOn;
	image* worriorOff;
	image* weapon;
	image* armor;
	image* hat;
	image* glasses;
	image* shoes1;
	image* shield;
	image* accessories;
	image* skillPointer1;
	image* itemPointer;
	RECT _rc3[12];
	int box1[12];
	int num1;
	RECT _rc4[10];
	int box2[10];
	int num2;
	image* goldBar;
	image* worriorSkill1;
	image* worriorSkill2;
	image* worriorSkill3;
	image* worriorSkill4;
	image* hpUi;
	image* frontHp;
	image* mpBar;
	image* backHp;
	bool skill;
public:
	uiManager();
	~uiManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void setUi();
	virtual void setState();
	virtual void keyControl();
	virtual image* getUiImage() { return _ui; }
	int setSelectUi() { int _SelectUiX; }
	void setPlayerManager(PlayerManager* pm) { _pm = pm; }
	void setSelect(bool select) { _select = select; }
	void set_goSelect() { _goSelect = !_goSelect; }

	bool getStay();
	
};

