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

	_rc = RectMakeCenter(position.x, position.y,
		_imageName->getWidth(), _imageName->getHeight());
	return S_OK;
}

void item::release()
{
}

void item::update()
{
}

void item::render()
{
	draw();
}

void item::draw()
{
	_imageName->render(getMemDC(), _rc.left, _rc.top);

}
