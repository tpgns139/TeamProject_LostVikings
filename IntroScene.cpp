#include "stdafx.h"
#include "IntroScene.h"


IntroScene::IntroScene()
{
}


IntroScene::~IntroScene()
{
}

HRESULT IntroScene::init()
{
	IMAGEMANAGER->addImage("intro1", "Intro_0 - backup.bmp", 635, 479, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("intro2", "Intro_1 - backup.bmp", 635, 479, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("intro3", "Intro_2 - backup.bmp", 635, 479, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("intro4", "Intro_4 - backup.bmp", 635, 479, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("intro1", "Intro_4 - backup.bmp", 635, 479, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("intro4", "Intro_4 - backup.bmp", 635, 479, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("intro4", "Intro_4 - backup.bmp", 635, 479, true, RGB(255, 0, 255));

	return S_OK;
}

void IntroScene::update()
{
}

void IntroScene::render()
{
	switch (_startState)
	{
	case intro1:
		
			break;
	case intro2:

		break;
	case intro3:

		break;
	case intro4:

		break;
	}
}

void IntroScene::release()
{
}
