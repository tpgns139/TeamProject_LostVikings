#pragma once
#include "item.h"
class Meat : public item
{
private:



public:
	Meat();
	~Meat();

	virtual HRESULT init(const char* imageName, POINT position);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void draw();
};

