#include "stdafx.h"
#include "Elevator.h"


Elevator::Elevator()
{
}


Elevator::~Elevator()
{
}

HRESULT Elevator::init(mapInfo info)
{
	MapObj::init(info);
	return S_OK;
}

