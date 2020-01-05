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

	bool Olafrender; // ĳ���͵� ó���� �Ⱥ��̰� �ҷ��� ���� �Ұ�
	bool Erikrender;
	bool Baleogrender;
	bool NO1;        //ĳ���͵� ������� �������ϴ� �Ұ�
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

