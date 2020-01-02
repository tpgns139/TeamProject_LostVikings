#include "stdafx.h"
#include "OlafUi.h"


OlafUi::OlafUi()
{
}


OlafUi::~OlafUi()
{
}

HRESULT OlafUi::init(const char * imageName, POINT position)
{
	_imageName = IMAGEMANAGER->findImage(imageName);
	_position.x = position.x;
	_position.y = position.y;

	return S_OK;
}



void OlafUi::release()
{

}

void OlafUi::update()
{

}

void OlafUi::render()
{
	draw();
}

void OlafUi::draw()
{
	_imageName->render(getMemDC(), _position.x, _position.y);

}