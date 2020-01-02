#pragma once
#include"MapObj.h"
enum imageKinds 
{
	LongSize,
	ShortSize,
	middleSize
};
class column:public MapObj
{
public:
	column();
	~column();
	virtual HRESULT init(mapInfo info);
	virtual void update();
	virtual void render();
	void setImage(imageKinds size);
};

