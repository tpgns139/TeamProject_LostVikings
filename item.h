#pragma once
#include "gameNode.h"

class item : public gameNode
{
protected:
	image* _imageName;
	image* _item;
	RECT _rc;
	POINT _position;
public:
	item();
	~item();


	virtual HRESULT init(const char* imageName, POINT position);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void draw();
	virtual RECT getRect() { return _rc; }
	//virtual image* getItemImage() { return _item; }
	
};