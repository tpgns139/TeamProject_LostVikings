#pragma once
#include"gameNode.h"



class EndScene : public gameNode
{
private:
	image* background;
	image* Erik;
	image* Baleog;
	image* Olaf;
	image* Ship;

	animation* anibackground;
	animation* aniErik;
	animation* aniBaleog;
	animation* aniOlaf;
	animation* aniShip;

	bool Olafrender; // 캐릭터들 처음에 안보이게 할려고 넣은 불값
	bool Erikrender;
	bool Baleogrender;
	bool NO1;        //캐릭터들 순서대로 나오게하는 불값
	bool NO2;
	bool NO3;
	
public :
	EndScene();
	~EndScene();

	HRESULT init();
	void update();
	void render();
	void release();
};

