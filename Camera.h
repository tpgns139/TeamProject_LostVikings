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
	float _backgroundWidth, _backGroundHeight;

public:
	Camera();
	~Camera();
	HRESULT init(float x, float y);
	void update();
	float getCameraXpos() { return _cameraXPos; }
	float getCameraYpos() { return _cameraYPos; }
	void moveTo(float endX, float endY, float time);
	void movingPoint();
	bool isMoving() { return _isMoving; }
	void setCameraPos(float x, float y);

	void setBackGroundWidth(float width) { _backgroundWidth = width; }
	void setBackGroundHeight(float height) { _backGroundHeight = height; }

};

