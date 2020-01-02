#pragma once
#include "ui.h"
class BaleogUi : public ui
{
private:

	int _currentHP;


public:
	BaleogUi();
	~BaleogUi();


	virtual HRESULT init(const char* imageName, POINT position);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void draw();
};

