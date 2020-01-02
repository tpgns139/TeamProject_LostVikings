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
	_isMoving = false;
	return S_OK;
}

void Camera::update()
{
	if (_isMoving) 
	{
		movingPoint();
	}
	
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

	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		cout << "카메라 X : " << CAMERA->getCameraXpos() << endl;
		cout << "카메라 Y : " << CAMERA->getCameraYpos() << endl;
	}
}

void Camera::moveTo(float endX, float endY, float time)
{
	if (!_isMoving)
	{
		if (endX - WINSIZEX / 2 > 0&& endX + WINSIZEX / 2 < _backgroundWidth)
		{
			_endX = endX - WINSIZEX / 2;
		}
		else if (endX + WINSIZEX / 2 > _backgroundWidth)
		{
			_endX = _backgroundWidth - WINSIZEX;
		}
		else
		{
			_endX = 0;
		}

		if (endY - WINSIZEY / 2 > 0&& endX + WINSIZEY / 2 < _backGroundHeight)
		{
			_endY = endY - WINSIZEY / 2;
		}
		else if (endY + WINSIZEY / 2 > _backGroundHeight)
		{
			_endY = _backGroundHeight -WINSIZEY;
		}
		else if(endY - WINSIZEY / 2 < 0)
		{
			_endY = 0;
		}


		_travelRange = getDistance(_cameraXPos, _cameraYPos, _endX, _endY);

		_angle = getAngle(_cameraXPos, _cameraYPos , _endX, _endY);

		_worldTimeCount = TIMEMANAGER->getWorldTime();

		_time = time;

		_isMoving = true;

	}
}
void Camera::movingPoint()
{
	if (!_isMoving) return;
	float elapsedTime = TIMEMANAGER->getElapsedTime();

	//200정도의 거리를 2초에 걸쳐서 도달해야한다면 속도값을 구해줌
	float moveSpeed = (elapsedTime / _time) * _travelRange;

	//포인트를 도착지점까지 각도와 속도를 맞춰서 원하는 시간에 도달케 한다
	_cameraXPos = _cameraXPos + cosf(_angle) * moveSpeed;
	_cameraYPos=_cameraYPos + (-sinf(_angle) * moveSpeed);

	if (_time + _worldTimeCount <= TIMEMANAGER->getWorldTime())
	{
		_worldTimeCount = TIMEMANAGER->getWorldTime();
		_cameraXPos = _endX;
		_cameraYPos = _endY;

		_isMoving = false;

	}
}

void Camera::setCameraPos(float x,float y)
{
	if (x - WINSIZEX / 2 > 0&& x + WINSIZEX / 2 < _backgroundWidth)
	{
		_cameraXPos = x - WINSIZEX / 2;
	}
	else if (x + WINSIZEX / 2 > _backgroundWidth)
	{
		_cameraXPos = _backgroundWidth - WINSIZEX;
	}
	else if(x - WINSIZEX / 2 < 0)
	{
		_cameraXPos = 0;
	}

	if (y - WINSIZEY / 2 > 0&& y + WINSIZEY / 2 < _backGroundHeight)
	{
		_cameraYPos = y - WINSIZEY / 2;
	}
	else if (y + WINSIZEY / 2 > _backGroundHeight)
	{
		_cameraYPos = IMAGEMANAGER->findImage("배경")->getHeight() - WINSIZEY;
	}
	else if(y - WINSIZEY / 2 < 0)
	{
		_cameraYPos = 0;
	}
}
