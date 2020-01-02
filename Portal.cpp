#include "stdafx.h"
#include "Portal.h"


Portal::Portal()
{
}


Portal::~Portal()
{
}

HRESULT Portal::init(mapInfo info)
{
	MapObj::init(info);
	return S_OK;
}

