#pragma once
#include"MapObj.h"
class Ladder:public MapObj
{
public:
	Ladder();
	~Ladder();
	virtual HRESULT init(mapInfo info);
	virtual void update();
	virtual void render();
};

