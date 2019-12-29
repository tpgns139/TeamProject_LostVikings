#pragma once
#include "item.h"

class Fruit :public item
{
private:



public:
	Fruit();
	~Fruit();


	virtual HRESULT init(const char* imageName, POINT position);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void draw();
};

