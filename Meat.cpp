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

	_rc = RectMakeCenter(position.x, position.y,
		_imageName->getWidth(), _imageName->getHeight());
	return S_OK;
}

void Meat::release()
{
}

void Meat::update()
{
}

void Meat::render()
{
	draw();
}

void Meat::draw()
{
	_imageName->render(getMemDC(), _rc.left, _rc.top);

}
