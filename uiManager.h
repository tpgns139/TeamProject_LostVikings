#pragma once
#include "gameNode.h"
#include "ui.h"

class uiManager : public gameNode
{
private:
	image* _ui;


public:
	uiManager();
	~uiManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


};

