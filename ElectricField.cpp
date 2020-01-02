#include "stdafx.h"
#include "ElectricField.h"


ElectricField::ElectricField()
{
}


ElectricField::~ElectricField()
{
}

HRESULT ElectricField::init(mapInfo info)
{
	MapObj::init(info);
	_mapInfo._image = IMAGEMANAGER->findImage("ElectricField");

	return S_OK;
}

void ElectricField::update()
{
	_mapInfo._rc = RectMake(_mapInfo._x - CAMERA->getCameraXpos(),
		_mapInfo._y - CAMERA->getCameraYpos(),
		_mapInfo.width,
		_mapInfo.height);
	if (_mapInfo.timeCount % 10 == 0)
	{
		_mapInfo.currentX++;
		if (_mapInfo.currentX > _mapInfo._image->getMaxFrameX())
		{
			_mapInfo.currentX = 0;
		}
	}
	_mapInfo.timeCount++;
}

void ElectricField::render()
{
	_mapInfo._image->stretchFrameRender(_backBuffer->getMemDC(),
		_mapInfo._rc.left
		, _mapInfo._rc.top,
		_mapInfo.width,
		_mapInfo.height,
		_mapInfo.currentX, 0);
}
