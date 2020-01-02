#include "stdafx.h"
#include "Fruit.h"


Fruit::Fruit()
{
}


Fruit::~Fruit()
{
}

HRESULT Fruit::init(const char * imageName, POINT position, itemKinds kinds)
{
	item::init(imageName, position, kinds);
	return S_OK;
}

void Fruit::release()
{
}

void Fruit::update()
{
	item::update();
}

void Fruit::render()
{
	draw();
}

void Fruit::draw()
{
	item::draw();

}
