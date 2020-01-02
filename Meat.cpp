#include "stdafx.h"
#include "Meat.h"


Meat::Meat()
{
}


Meat::~Meat()
{
}

HRESULT Meat::init(const char * imageName, POINT position, itemKinds kinds)
{
	item::init(imageName, position, kinds);
	return S_OK;
}

void Meat::release()
{
}

void Meat::update()
{
	item::update();
}

void Meat::render()
{
	draw();
}

void Meat::draw()
{
	item::draw();

}
