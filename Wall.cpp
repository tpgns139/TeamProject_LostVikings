#include "stdafx.h"
#include "Wall.h"


Wall::Wall()
{
}


Wall::~Wall()
{
}

HRESULT Wall::init(mapInfo info)
{
	MapObj::init(info);
	return S_OK;
}

void Wall::update()
{
	_mapInfo._rc = RectMake(_mapInfo._x - CAMERA->getCameraXpos(),
		_mapInfo._y - CAMERA->getCameraYpos(),
		_mapInfo.width,
		_mapInfo.height);
}
void Wall::render()
{
}
