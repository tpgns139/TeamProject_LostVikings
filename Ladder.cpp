#include "stdafx.h"
#include "Ladder.h"


Ladder::Ladder()
{
}


Ladder::~Ladder()
{
}

HRESULT Ladder::init(mapInfo info)
{
	MapObj::init(info);
	return S_OK;
}

void Ladder::update()
{
	_mapInfo._rc = RectMake(_mapInfo._x ,
		_mapInfo._y ,
		_mapInfo.width,
		_mapInfo.height);
}

void Ladder::render()
{
	RectangleMake(_backBuffer->getMemDC(), _mapInfo._rc.left-CAMERA->getCameraXpos()
		,_mapInfo._rc.top-CAMERA->getCameraYpos(),
		_mapInfo.width,
		_mapInfo.height);
}


