#pragma once
#include"singletonBase.h"
enum CameraMoveDir
{
	updir,
	downdir,
	leftdir,
	rightdir
};
class Camera:public singletonBase<Camera>
{
private:
	float _cameraXPos, _cameraYPos;
public:
	Camera();
	~Camera();
	HRESULT init(float x, float y);
	void update();
	void cameraMove(CameraMoveDir dir, float speed);
	float getCameraXpos() { return _cameraXPos; }
	float getCameraYpos() { return _cameraYPos; }
};

