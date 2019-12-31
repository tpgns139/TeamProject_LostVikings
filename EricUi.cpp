#include "stdafx.h"
#include "EricUi.h"


EricUi::EricUi()
{
}


EricUi::~EricUi()
{
}

HRESULT EricUi::init(const char * imageName, POINT position)
{
	_imageName = IMAGEMANAGER->findImage(imageName);
	_position.x = position.x;
	_position.y = position.y;

	return S_OK;
}

void EricUi::release()
{

}

void EricUi::update()
{

}
void EricUi::render()
{
	draw();
}

void EricUi::draw()
{
	_imageName->render(getMemDC(), _position.x, _position.y);

}