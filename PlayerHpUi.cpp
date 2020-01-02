#include "stdafx.h"
#include "PlayerHpUi.h"


PlayerHpUi::PlayerHpUi()
{
}


PlayerHpUi::~PlayerHpUi()
{
}

HRESULT PlayerHpUi::init(const char * imageName, POINT position)
{
	_imageName = IMAGEMANAGER->findImage(imageName);
	_position.x = position.x;
	_position.y = position.y;

	return S_OK;
}

void PlayerHpUi::release()
{

}

void PlayerHpUi::update()
{

}

void PlayerHpUi::render()
{
	draw();
}

void PlayerHpUi::draw()
{
	_imageName->render(getMemDC(), _position.x, _position.y);

}