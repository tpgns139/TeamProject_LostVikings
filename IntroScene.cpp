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
	IMAGEMANAGER->addImage("intro1", "Intro_0 - backup.bmp", 800, 600, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("intro2", "Intro_1 - backup.bmp", 635, 479, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("intro3", "Intro_2 - backup.bmp", 635, 479, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("intro4", "Intro_4 - backup.bmp", 635, 479, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("intro1sizeUp", "Intro_1.bmp", 800, 600, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("intro2siezeUp", "Intro_2.bmp", 800, 600, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("intro4sizeUp", "Intro_4.bmp", 800, 600, true, RGB(255, 0, 255));
	_nowScene = IMAGEMANAGER->findImage("intro1");
	_fadeout = 255;
	_fadein = 0;
	_changeFadeState = false;
	_changeScene = false;
	return S_OK;
}

void IntroScene::update()
{
	if (_startState != intro4) 
	{
		if (!_changeScene) 
		{
			if (!_changeFadeState)
			{
				if (_fadein < 255)
				{
					_fadein += 1;
				}
				else
				{
					
					_changeFadeState = true;
				}
			}
			else
			{
				if (_fadeout > 0)
				{
					_fadeout -= 1;
				}
				else
				{
					_changeScene = true;
				}
			}
		}
		else
		{
			switch (_startState)
			{
			case intro1:
				_nowScene = IMAGEMANAGER->findImage("intro1sizeUp");
				_startState = intro2;
				_fadeout = 255;
				_fadein = 0;
				_changeFadeState = false;
				_changeScene = false;
				break;
			case intro2:
				_nowScene = IMAGEMANAGER->findImage("intro2siezeUp");
				_startState = intro3;
				_fadeout = 255;
				_fadein = 0;
				_changeFadeState = false;
				_changeScene = false;
				break;
			
			case intro3:
				_nowScene = IMAGEMANAGER->findImage("intro4sizeUp");
				_startState = intro4;
				_fadeout = 255;
				_fadein = 0;
				_changeFadeState = false;
				_changeScene = false;
			
			
			case intro4:
			
				

				break;

			}
		}
	}
	else
	{
		_changeFadeState = true;
	}
}

void IntroScene::render()
{
	if (_changeFadeState) 
	{
		_nowScene->alphaRender(getMemDC(), 0, 0, _fadeout);
	}
	else
	{
		_nowScene->alphaRender(getMemDC(), 0, 0, _fadein);
	}
}

void IntroScene::release()
{
}
