#pragma once
#include"MapObj.h"
class GravityZone:public MapObj
{
public:
	GravityZone();
	~GravityZone();
	virtual HRESULT init(mapInfo info);
	virtual void update();
	virtual void render();
};

