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
	_position.x = position.x;
	_position.y = position.y;
	_rc = RectMakeCenter(position.x, position.y,
		_imageName->getWidth(), _imageName->getHeight());
	return S_OK;
}

void Key::release()
{
}

void Key::update()
{

	_rc = RectMakeCenter(_position.x-CAMERA->getCameraXpos(),
		_position.y-CAMERA->getCameraYpos(),
		_imageName->getWidth(), _imageName->getHeight());
}

void Key::render()
{
	draw();
}

void Key::draw()
{
	_imageName->render(getMemDC(), _rc.left, _rc.top);

}
