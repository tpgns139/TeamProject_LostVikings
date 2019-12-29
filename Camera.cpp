#include "stdafx.h"
#include "Camera.h"


Camera::Camera()
{
}


Camera::~Camera()
{
}

HRESULT Camera::init(float x, float y)
{
	_cameraXPos = x;
	_cameraYPos = y;
	return S_OK;
}

void Camera::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{

		_cameraXPos -= 10;
		if (_cameraXPos < 0)
		{
			_cameraXPos = 0;
		}
	
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{

		_cameraXPos += 10;
	
		if (_cameraXPos + WINSIZEX > IMAGEMANAGER->findImage("배경")->getWidth())
		{
			_cameraXPos = IMAGEMANAGER->findImage("배경")->getWidth() - WINSIZEX;
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_cameraYPos -= 10;
	
		if (_cameraYPos < 0)
		{
			_cameraYPos=0;
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_cameraYPos += 10;
		if (_cameraYPos + WINSIZEY > IMAGEMANAGER->findImage("배경")->getHeight())
		{
			_cameraYPos = IMAGEMANAGER->findImage("배경")->getHeight()-WINSIZEY;
		}
	
	}
}

void Camera::cameraMove(CameraMoveDir dir, float speed)
{
	switch (dir)
	{
	case updir:
		_cameraYPos += speed;
		break;
	case downdir:
		_cameraYPos -= speed;
		break;
	case leftdir:
		_cameraXPos -= speed;
		break;
	case rightdir:
		_cameraXPos += speed;
		break;
	default:
		break;
	}
}
