#pragma once
#include"MapObj.h"
class ElectricFieldTwoType:public MapObj
{
public:
	ElectricFieldTwoType();
	~ElectricFieldTwoType();
	virtual HRESULT init(mapInfo info);
	virtual void update();
	virtual void render();
};

