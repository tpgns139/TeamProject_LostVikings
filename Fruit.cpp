#include "stdafx.h"
#include "Fruit.h"


Fruit::Fruit()
{
}


Fruit::~Fruit()
{
}

HRESULT Fruit::init(const char * imageName, POINT position)
{

	_imageName = IMAGEMANAGER->findImage(imageName);
	_position.x = position.x;
	_position.y = position.y;
	_rc = RectMakeCenter(position.x, position.y,
		_imageName->getWidth(), _imageName->getHeight());
	return S_OK;
}

void Fruit::release()
{
}

void Fruit::update()
{
	_rc = RectMakeCenter(_position.x-CAMERA->getCameraXpos(),
		_position.y-CAMERA->getCameraYpos(),
		_imageName->getWidth(), _imageName->getHeight());
}

void Fruit::render()
{
	draw();
}

void Fruit::draw()
{
	_imageName->render(getMemDC(), _rc.left, _rc.top);

}
