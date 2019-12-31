#pragma once
#include"MapObj.h"
class BlueTile:public MapObj
{
public:
	BlueTile();
	~BlueTile();
	virtual HRESULT init(mapInfo info);
	virtual void update();
	virtual void render();
};

