#include "stdafx.h"
#include "item.h"


item::item()
{
}


item::~item()
{
}

HRESULT item::init(const char * imageName, POINT position)
{
	_imageName = IMAGEMANAGER->findImage(imageName);
	_position.x = position.x;
	_position.y = position.y;
	_rc = RectMakeCenter(position.x, position.y,
		_imageName->getWidth(), _imageName->getHeight());
	return S_OK;
}

void item::release()
{
}

void item::update()
{
	_rc = RectMakeCenter(_position.x - CAMERA->getCameraXpos(),
		_position.y - CAMERA->getCameraYpos(),
		_imageName->getWidth(), _imageName->getHeight());
}

void item::render()
{
	draw();
}

void item::draw()
{
	_imageName->render(getMemDC(), _rc.left, _rc.top);

}
