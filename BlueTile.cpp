#include "stdafx.h"
#include "BlueTile.h"


BlueTile::BlueTile()
{
}


BlueTile::~BlueTile()
{
}

HRESULT BlueTile::init(mapInfo info)
{
	MapObj::init(info);
	_mapInfo._image = IMAGEMANAGER->findImage("BlueTile");
	return S_OK;
}

void BlueTile::update()
{
	_mapInfo._rc=RectMake(_mapInfo._x - CAMERA->getCameraXpos(),
		_mapInfo._y - CAMERA->getCameraYpos(),
		_mapInfo.width, 
		_mapInfo.height);
	if (_mapInfo.timeCount % 20 == 0)
	{
		_mapInfo.currentX++;
		if (_mapInfo.currentX > _mapInfo._image->getMaxFrameX())
		{
			_mapInfo.currentX = 0;
		}
	}
	_mapInfo.timeCount++;
}

void BlueTile::render()
{
	
	_mapInfo._image->frameRender(_backBuffer->getMemDC(),
		_mapInfo._rc.left
		, _mapInfo._rc.top,
		_mapInfo.currentX,0);
}
