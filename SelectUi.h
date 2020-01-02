#pragma once
#include "ui.h"
class SelectUi : public ui
{
private:




public:
	SelectUi();
	~SelectUi();


	virtual HRESULT init(const char* imageName, POINT position);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void draw();

};

