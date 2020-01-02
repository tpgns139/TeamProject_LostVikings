#include "stdafx.h"
#include "Key.h"


Key::Key()
{
}


Key::~Key()
{
}

HRESULT Key::init(const char * imageName, POINT position, itemKinds kinds)
{
	item::init(imageName, position, kinds);
	return S_OK;
}

void Key::release()
{
}

void Key::update()
{

	item::update();
}

void Key::render()
{
	draw();
}

void Key::draw()
{
	item::draw();

}
