#include "stdafx.h"
#include "Tower.h"


Tower::Tower()
{
}


Tower::~Tower()
{
}

HRESULT Tower::init(mapInfo info)
{
	MapObj::init(info);
	return S_OK;
}


