#pragma once
#include "gameNode.h"
enum uiName 
{
	Hp,
	Pointer
};
class ui :public gameNode
{
protected:
	image* _imageName;
	uiName _name;
	POINT _position;

public:
	ui();
	~ui();

	virtual HRESULT init(const char* imageName, POINT position,uiName name);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void draw();
	image* getImage() { return _imageName; }
	POINT get_position() { return _position; }
	POINT set_position() { return _position; }
};

