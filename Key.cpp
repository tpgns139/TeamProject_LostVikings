#include "stdafx.h"
#include "Key.h"


Key::Key()
{
}


Key::~Key()
{
}

HRESULT Key::init(const char * imageName, POINT position)
{
	_imageName = IMAGEMANAGER->findImage(imageName);

	_rc = RectMakeCenter(position.x, position.y,
		_imageName->getWidth(), _imageName->getHeight());
	return S_OK;
}

void Key::release()
{
}

void Key::update()
{
}

void Key::render()
{
	draw();
}

void Key::draw()
{
	_imageName->render(getMemDC(), _rc.left, _rc.top);

}
