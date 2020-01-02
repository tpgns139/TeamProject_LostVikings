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
	movingPoint();
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
	
		if (_cameraXPos + WINSIZEX > IMAGEMANAGER->findImage("���")->getWidth())
		{
			_cameraXPos = IMAGEMANAGER->findImage("���")->getWidth() - WINSIZEX;
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
		if (_cameraYPos + WINSIZEY > IMAGEMANAGER->findImage("���")->getHeight())
		{
			_cameraYPos = IMAGEMANAGER->findImage("���")->getHeight()-WINSIZEY;
		}
	
	}

	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		cout << "ī�޶� X : " << CAMERA->getCameraXpos() << endl;
		cout << "ī�޶� Y : " << CAMERA->getCameraYpos() << endl;
	}
}

void Camera::moveTo(float endX, float endY, float time)
{
	if (!_isMoving)
	{

		_endX = endX-WINSIZEX/2;
		_endY = endY-WINSIZEY/2;

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

	//200������ �Ÿ��� 2�ʿ� ���ļ� �����ؾ��Ѵٸ� �ӵ����� ������
	float moveSpeed = (elapsedTime / _time) * _travelRange;

	//����Ʈ�� ������������ ������ �ӵ��� ���缭 ���ϴ� �ð��� ������ �Ѵ�
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
