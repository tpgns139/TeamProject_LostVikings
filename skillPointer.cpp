#include "stdafx.h"
#include "skillPointer.h"


skillPointer::skillPointer()
{
}


skillPointer::~skillPointer()
{
}

HRESULT skillPointer::init(const char * imageName, POINT position)
{
	_imageName = IMAGEMANAGER->findImage(imageName);
	_position.x = position.x;
	_position.y = position.y;

	return S_OK;
}

void skillPointer::release()
{
}

void skillPointer::update()
{
}

void skillPointer::render()
{
	draw();

}

void skillPointer::draw()
{
	_imageName->render(getMemDC(), _position.x, _position.y);

}
