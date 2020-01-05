#include "stdafx.h"
#include "EndScene.h"

EndScene::EndScene()
{
}

EndScene::~EndScene()
{
}

HRESULT EndScene::init()
{
	background = IMAGEMANAGER->addFrameImage("배경", "GameOver_BackGround.bmp", 5600, 756, 7, 1, false, RGB(0, 0, 0));
	Erik = IMAGEMANAGER->addFrameImage("에릭", "GameOver_Player_Eric.bmp", 1251, 337, 9, 1, true, RGB(255, 0, 255));
	Baleog = IMAGEMANAGER->addFrameImage("벨로그", "GameOver_Player_Baleog.bmp", 1024, 337, 8, 1, true, RGB(255, 0, 255));
	Olaf = IMAGEMANAGER->addFrameImage("울라프", "GameOver_Player_Olaf.bmp", 1390, 337, 10, 1, true, RGB(255, 0, 255));
	Ship = IMAGEMANAGER->addFrameImage("배", "Ship.bmp", 600, 178, 5, 1, true, RGB(255, 0, 255));

	anibackground = new animation;
	anibackground->init(background->getWidth(), background->getHeight(), background->getFrameWidth(), background->getFrameHeight());
	anibackground->setPlayFrame(1, 7, false, true);
	anibackground->setFPS(1);

	aniErik = new animation;
	aniErik->init(Erik->getWidth(), Erik->getHeight(), Erik->getFrameWidth(), Erik->getFrameHeight());
	aniErik->setPlayFrame(1, 9, false, false);
	aniErik->setFPS(2);

	aniBaleog = new animation;
	aniBaleog->init(Baleog->getWidth(), Baleog->getHeight(), Baleog->getFrameWidth(), Baleog->getFrameHeight());
	aniBaleog->setPlayFrame(1, 8, false, false);
	aniBaleog->setFPS(2);

	aniOlaf = new animation;
	aniOlaf->init(Olaf->getWidth(), Olaf->getHeight(), Olaf->getFrameWidth(), Olaf->getFrameHeight());
	aniOlaf->setPlayFrame(1, 10, false, false);
	aniOlaf->setFPS(2);

	aniShip = new animation;
	aniShip->init(Ship->getWidth(), Ship->getHeight(), Ship->getFrameWidth(), Ship->getFrameHeight());
	aniShip->setPlayFrame(1, 5, false, true);
	aniShip->setFPS(1);

	anibackground->start();
	aniShip->start();
	



	return S_OK;
}

void EndScene::update()
{
	if (!NO1)
	{
	  if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	  {
	  	aniOlaf->start();
	  	Olafrender = true;
		NO1 = true;
		NO2 = true;
	  }

	}
	if (NO2)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			aniErik->start();
			Erikrender = true;
			NO2 = false;
			NO3 = true;
		}
	}
	if (NO3)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			aniBaleog->start();
			Baleogrender = true;
			
		}
	}
	
	
	
	anibackground->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	aniShip->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	aniErik->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	aniOlaf->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	aniBaleog->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
}

void EndScene::render()
{
	background->aniRender(getMemDC(), 0, 0, anibackground);
	Ship->aniRender(getMemDC(), WINSIZEX / 2 + 100, WINSIZEY / 2, aniShip);
	if (Olafrender)
	{
	  Olaf->aniRender(getMemDC(), WINSIZEX / 2 + 100, WINSIZEY / 2, aniOlaf);
	}
	if (Erikrender)
	{
		Erik->aniRender(getMemDC(), WINSIZEX / 2 - 300, WINSIZEY / 2, aniErik);
	}
	if (Baleogrender)
	{
		Baleog->aniRender(getMemDC(), WINSIZEX / 2 - 100, WINSIZEY / 2 - 50, aniBaleog);
	}
}

void EndScene::release()
{
}
