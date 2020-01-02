#pragma once
#include "ui.h"
class OlafUi : public ui
{
private:



public:
	OlafUi();
	~OlafUi();


	virtual HRESULT init(const char* imageName, POINT position);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void draw();

};

