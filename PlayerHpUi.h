#pragma once
#include "ui.h"
class PlayerHpUi : public ui
{
private:




public:
	PlayerHpUi();
	~PlayerHpUi();


	virtual HRESULT init(const char* imageName, POINT position);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void draw();

};

