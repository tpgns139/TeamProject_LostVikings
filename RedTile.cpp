#include "stdafx.h"
#include "RedTile.h"


RedTile::RedTile()
{
}


RedTile::~RedTile()
{
}

HRESULT RedTile::init(mapInfo info)
{
	MapObj::init(info);
	_mapInfo._image = IMAGEMANAGER->findImage("RedTile");
	return S_OK;
}

void RedTile::update()
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

void RedTile::render()
{
	_mapInfo._image->frameRender(_backBuffer->getMemDC(),
		_mapInfo._rc.left-CAMERA->getCameraXpos()
		, _mapInfo._rc.top-CAMERA->getCameraYpos(),
		_mapInfo.currentX, 0);
}
