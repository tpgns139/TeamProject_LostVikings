#pragma once
#include "gameNode.h"

typedef void(*CALLBACK_FUNCTION)(void);


class action : public gameNode
{
private:
	image* _image;				//�̹���
	float _startX, _startY;		//�����ǥ
	float _endX, _endY;			//������ǥ

	float _angle;				//�����ϴ� ����
	float _travelRange;			//�����ϴ� �Ÿ�
	float _worldTimeCount;
	float _time;		
	bool _imageMoving;
	bool _pointMoving;
	
	POINT _chasePoint;

	CALLBACK_FUNCTION _callbackFunction;

	//

	/*float* _x;
	float* _y;

	float _endX;
	float _endY;
	float _startX;
	float _startY;*/



	
public:
	action();
	~action();

	HRESULT init();
	void release();
	void update();
	void render();

	void moveTo(image* image, float endX, float endY, float time);
	void moveTo(image* image, float endX, float endY, float time, CALLBACK_FUNCTION cbFunction);
	void moveTo(float startX, float startY, float endX, float endY, float time);

	void moving();
	bool getimageMoving() { return _imageMoving; }
	bool getPointMoving() { return _pointMoving; }

	//
	void moveTo(float* startX, float* startY, float startx, float starty, float endX, float endY, float time);
	void itemMoving();

};

