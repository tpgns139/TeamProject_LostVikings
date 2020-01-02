#pragma once
#include "item.h"
class Key :public item
{
private:



public:
	Key();
	~Key();

	virtual HRESULT init(const char* imageName, POINT position, itemKinds kinds);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void draw();
};

