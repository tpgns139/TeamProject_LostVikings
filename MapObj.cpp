#include "stdafx.h"
#include "MapObj.h"
#include"gameNode.h"

MapObj::MapObj()
{
}


MapObj::~MapObj()
{
}

HRESULT MapObj::init(mapInfo info)
{
	_mapInfo = info;
	_mapInfo.currentX = 0;
	_mapInfo.timeCount = 0;
	return S_OK;
}

void MapObj::update()
{
}

void MapObj::render()
{
}
