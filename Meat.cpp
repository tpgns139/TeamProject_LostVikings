#include "stdafx.h"
#include "Meat.h"


Meat::Meat()
{
}


Meat::~Meat()
{
}

HRESULT Meat::init(const char * imageName, POINT position)
{
	_imageName = IMAGEMANAGER->findImage(imageName);
	_position.x = position.x;
	_position.y = position.y;
	_rc = RectMakeCenter(position.x, position.y,
		_imageName->getWidth(), _imageName->getHeight());
	return S_OK;
}

void Meat::release()
{
}

void Meat::update()
{
	_rc = RectMakeCenter(_position.x - CAMERA->getCameraXpos(),
		_position.y - CAMERA->getCameraYpos(),
		_imageName->getWidth(), _imageName->getHeight());
}

void Meat::render()
{
	draw();
}

void Meat::draw()
{
	_imageName->render(getMemDC(), _rc.left, _rc.top);

}
