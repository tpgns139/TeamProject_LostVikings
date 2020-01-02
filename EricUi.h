#pragma once
#include "ui.h"

class EricUi : public ui
{
private:




public:
	EricUi();
	~EricUi();


	virtual HRESULT init(const char* imageName, POINT position);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void draw();

};

