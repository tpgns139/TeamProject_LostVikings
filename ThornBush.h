#pragma once
#include"MapObj.h"
class ThornBush:public MapObj
{
public:
	ThornBush();
	~ThornBush();
	virtual HRESULT init(mapInfo info);
	virtual void update();
	virtual void render();
};

