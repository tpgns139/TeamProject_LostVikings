#pragma once
#include"MapObj.h"
class ColWall:public MapObj
{
public:
	ColWall();
	~ColWall();
	virtual HRESULT init(mapInfo info);
	virtual void update();
	virtual void render();

	RECT getWallRect() { return _mapInfo._rc; }
};

