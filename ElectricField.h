#pragma once
#include "MapObj.h"
class ElectricField:public MapObj
{
public:
	ElectricField();
	~ElectricField();
	virtual HRESULT init(mapInfo info);
	virtual void update();
	virtual void render();
};

