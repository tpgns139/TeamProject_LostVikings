#pragma once
#include "gameNode.h"
#include "uiManager.h"
#include "PlayerManager.h"
#include "itemManager.h"
class Inven : public gameNode
{
private:
	vector<Inven*>				_vInven;
	vector<Inven*>::iterator	_viInven;




public:
	Inven();
	~Inven();



	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void draw();

	vector<Inven*> get_vInven() { return _vInven; }
	vector<Inven*>::iterator get_viInven() { return _viInven; }

};

