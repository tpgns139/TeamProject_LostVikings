#include "stdafx.h"
#include "Shoes.h"


Shoes::Shoes()
{
}


Shoes::~Shoes()
{
}

HRESULT Shoes::init(const char * imageName, POINT position)
{
	_imageName = IMAGEMANAGER->findImage(imageName);

	_rc = RectMakeCenter(position.x, position.y,
		_imageName->getWidth(), _imageName->getHeight());
	return S_OK;
}

void Shoes::release()
{
}

void Shoes::update()
{
}

void Shoes::render()
{
	draw();
}

void Shoes::draw()
{
	_imageName->render(getMemDC(), _rc.left, _rc.top);

}
