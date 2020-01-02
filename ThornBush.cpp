#include "stdafx.h"
#include "ThornBush.h"


ThornBush::ThornBush()
{
}


ThornBush::~ThornBush()
{
}

HRESULT ThornBush::init(mapInfo info)
{
	MapObj::init(info);
	_mapInfo._image = IMAGEMANAGER->findImage("ThornBush");
	return S_OK;
}

void ThornBush::update()
{
	_mapInfo._rc = RectMake(_mapInfo._x ,
		_mapInfo._y ,
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

void ThornBush::render()
{
	_mapInfo._image->frameRender(_backBuffer->getMemDC(),
		_mapInfo._rc.left-CAMERA->getCameraXpos()
		, _mapInfo._rc.top-CAMERA->getCameraYpos(),
		_mapInfo.currentX, 0);
}


