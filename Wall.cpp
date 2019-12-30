#include "stdafx.h"
#include "Wall.h"


Wall::Wall()
{
}


Wall::~Wall()
{
}

HRESULT Wall::init(mapInfo info)
{
	MapObj::init(info);
	return S_OK;
}
