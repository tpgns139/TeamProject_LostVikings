#include "stdafx.h"
#include "MapObj.h"
#include"gameNode.h"

MapObj::MapObj()
{
}


MapObj::~MapObj()
{
}

HRESULT MapObj::init(float x, float y, string imageName)
{
	_x = x;
	_y = y;
	_image = IMAGEMANAGER->findImage(imageName);
	//_rc= RectangleMake(gameNode::getMemDC(),)
	return S_OK;
}
