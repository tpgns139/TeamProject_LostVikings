#include "stdafx.h"
#include "ColWall.h"


ColWall::ColWall()
{
}


ColWall::~ColWall()
{
}

HRESULT ColWall::init(mapInfo info)
{
	MapObj::init(info);
	return S_OK;
}

void ColWall::update()
{
	_mapInfo._rc = RectMake(_mapInfo._x,
		_mapInfo._y,
		_mapInfo.width,
		_mapInfo.height);
}

void ColWall::render()
{
	RectangleMake(_backBuffer->getMemDC(),
		_mapInfo._x - CAMERA->getCameraXpos(),
		_mapInfo._y - CAMERA->getCameraYpos(),
		_mapInfo.width,
		_mapInfo.height);
}
