#pragma once
#include"MapObj.h"
class Wall:public MapObj
{
public:
	Wall();
	~Wall();

	virtual HRESULT init(mapInfo info);
};

