#pragma once
#include"MapObj.h"
class Portal :public MapObj
{
public:
	Portal();
	~Portal();
	virtual HRESULT init(mapInfo info);
	virtual void render();
};

