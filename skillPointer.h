#pragma once
#include "ui.h"


class skillPointer : public ui
{


public:
	skillPointer();
	~skillPointer();



	virtual HRESULT init(const char* imageName, POINT position);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void draw();
};


