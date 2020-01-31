#pragma once
#include "ui.h"
class pointer : public ui
{
public:
	pointer();
	~pointer();


	virtual HRESULT init(const char* imageName, POINT position);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void draw();
};

