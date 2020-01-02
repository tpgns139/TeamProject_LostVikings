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
	float _endX, _endY;			//도착좌표

	float _angle;				//가야하는 각도
	float _travelRange;			//가야하는 거리
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

