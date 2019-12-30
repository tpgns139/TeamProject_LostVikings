#pragma once
#include"MapObj.h"
class Elevator:public MapObj
{
public:
	Elevator();
	~Elevator();
	virtual HRESULT init(mapInfo info);
};

