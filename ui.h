#pragma once
#include "gameNode.h"
class ui :public gameNode
{
protected:
	image* _imageName;

	POINT _position;
public:
	ui();
	~ui();

	virtual HRESULT init(const char* imageName, POINT position);
	virtual void release();
	virtual void update();
	virtual void render();

};

