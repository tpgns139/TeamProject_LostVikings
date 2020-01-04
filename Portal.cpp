#include "stdafx.h"
#include "Portal.h"


Portal::Portal()
{
}


Portal::~Portal()
{
}

HRESULT Portal::init(mapInfo info)
{
	MapObj::init(info);
	return S_OK;
}

void Portal::render()
{
	RectangleMake(_backBuffer->getMemDC(),
		_mapInfo._x - CAMERA->getCameraXpos(),
		_mapInfo._y - CAMERA->getCameraYpos(),
		_mapInfo.width,
		_mapInfo.height);
}

