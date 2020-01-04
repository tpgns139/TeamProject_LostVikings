#include "stdafx.h"
#include "column.h"


column::column()
{
}


column::~column()
{
}

HRESULT column::init(mapInfo info)
{
	MapObj::init(info);
	_mapInfo._rc = RectMake(_mapInfo._x,
		_mapInfo._y,
		_mapInfo.width,
		_mapInfo.height);
	return S_OK;
}

void column::update()
{
	_mapInfo._rc = RectMake(_mapInfo._x ,
		_mapInfo._y ,
		_mapInfo.width,
		_mapInfo.height);
}

void column::render()
{
	//Rectangle(_backBuffer->getMemDC(), _mapInfo._rc);
	_mapInfo._image->render(_backBuffer->getMemDC(),
		_mapInfo._rc.left-CAMERA->getCameraXpos()
		, _mapInfo._rc.top-CAMERA->getCameraYpos());
}

void column::setImage(imageKinds size)
{
	switch (size)
	{
	case LongSize:
		_mapInfo._image = IMAGEMANAGER->findImage("LongSizeColumn");
		break;
	case ShortSize:
		_mapInfo._image = IMAGEMANAGER->findImage("ShortSizeColumn");
		break;
	case middleSize:
		_mapInfo._image = IMAGEMANAGER->findImage("MiddleSizeColumn");
		break;
	}
}
