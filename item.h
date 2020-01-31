#pragma once
#include "gameNode.h"

//#define PI 3.14
//#define DO PI/180
enum itemKinds
{
	fruit,
	meat,
	key,
	shoes,
	
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
	virtual void setRectLeft(float left) { _rc.left = left; }
	virtual void setRectRight(float top) { _rc.top = top; }
	virtual image* getImage() { return _imageName; }
	itemKinds getItemKinds() { return _kinds; }
	//virtual image* getItemImage() { return _item; }

	// 임시 포지션 수정 함수
	void setPos(long x, long y) { _position.x = x; _position.y = y; }
	virtual POINT getPos() { return _position; }
	
};