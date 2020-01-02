#include "stdafx.h"
#include "Shoes.h"


Shoes::Shoes()
{
}


Shoes::~Shoes()
{
}

HRESULT Shoes::init(const char * imageName, POINT position,itemKinds kinds)
{
	item::init(imageName,position,kinds);
	return S_OK;
}

void Shoes::release()
{
}

void Shoes::update()
{
	item::update();
}

void Shoes::render()
{
	draw();
}

void Shoes::draw()
{
	item::draw();

}
