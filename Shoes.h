#pragma once
#include "item.h"
class Shoes :public item
{
private:



public:
	Shoes();
	~Shoes();


	virtual HRESULT init(const char* imageName, POINT position, itemKinds kinds);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void draw();
};

