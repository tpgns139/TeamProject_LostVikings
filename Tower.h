#pragma once
#include"MapObj.h"
class Tower:public MapObj
{
public:
	Tower();
	~Tower();
	virtual HRESULT init(mapInfo info);
};

