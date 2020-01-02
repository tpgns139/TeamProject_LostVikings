#pragma once
#include"MapObj.h"
class RedTile:public MapObj
{
public:
	RedTile();
	~RedTile();
	virtual HRESULT init(mapInfo info);
	virtual void update();
	virtual void render();
};

