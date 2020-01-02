#include "stdafx.h"
#include "BaleogUi.h"


BaleogUi::BaleogUi()
{
}


BaleogUi::~BaleogUi()
{
}

HRESULT BaleogUi::init(const char * imageName, POINT position)
{
	_imageName = IMAGEMANAGER->findImage(imageName);
	_position.x = position.x;
	_position.y = position.y;

	return S_OK;
}

void BaleogUi::release()
{

}

void BaleogUi::update()
{
/*	_currentHP = 3;
	if (_currentHP == 0)
	{
		
	}*/
}


void BaleogUi::render()
{
	draw();
}

void BaleogUi::draw()
{
	_imageName->render(getMemDC(), _position.x, _position.y);

}
