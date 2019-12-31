#include "stdafx.h"
#include "SelectUi.h"


SelectUi::SelectUi()
{
}


SelectUi::~SelectUi()
{
}

HRESULT SelectUi::init(const char * imageName, POINT position)
{
	_imageName = IMAGEMANAGER->findImage(imageName);
	_position.x = position.x;
	_position.y = position.y;

	return S_OK;
}

void SelectUi::release()
{

}

void SelectUi::update()
{
	
}

void SelectUi::render()
{
	draw();
}

void SelectUi::draw()
{
	_imageName->render(getMemDC(), _position.x, _position.y);

}