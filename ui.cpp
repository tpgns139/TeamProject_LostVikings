#include "stdafx.h"
#include "ui.h"


ui::ui()
{
}


ui::~ui()
{
}

HRESULT ui::init(const char * imageName, POINT position)
{
	_imageName = IMAGEMANAGER->findImage(imageName);
	_position.x = position.x;
	_position.y = position.y;

	return S_OK;
}

void ui::release()
{
}

void ui::update()
{
}

void ui::render()
{
	_imageName->render(getMemDC(),_imageName->getWidth(), _imageName->getHeight());
}
