#pragma once
#include "gameNode.h"
enum itemKinds
{
	fruit,
	meat,
	key,
	shoes
};
class item : public gameNode
{
protected:
	image* _imageName;
	image* _item;
	RECT _rc;
	POINT _position;
	itemKinds _kinds;
public:
	item();
	~item();


	virtual HRESULT init(const char* imageName, POINT position,itemKinds kinds);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void draw();
	virtual RECT getRect() { return _rc; }
	itemKinds getItemKinds() { return _kinds; }
	//virtual image* getItemImage() { return _item; }
	
};