#pragma once
#include"singletonBase.h"

enum CameraMoveDir
{
	updir,
	downdir,
	leftdir,
	rightdir
};
class action;
class Camera:public singletonBase<Camera>
{
private:
	float _cameraXPos, _cameraYPos;


	bool _isMoving;
	float _endX, _endY;			//������ǥ

	float _angle;				//�����ϴ� ����
	float _travelRange;			//�����ϴ� �Ÿ�
	float _worldTimeCount;
	float _time;


public:
	Camera();
	~Camera();
	HRESULT init(float x, float y);
	void update();
	float getCameraXpos() { return _cameraXPos; }
	float getCameraYpos() { return _cameraYPos; }
	void moveTo(float endX, float endY, float time);
	void movingPoint();
	
};

