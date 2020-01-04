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
	return S_OK;
}

void IntroScene::update()
{
	if (_startState != intro4) 
	{
		if (_fadein <= 256)
		{
			_fadein += 3;
		}
		if (_fadeout >= 1)
		{
			_fadeout -= 3;
		}
			/*if (_fadeout >= 0 && _fadeout <= 254)
			{
				start = false;
			}
			else
			{
				start = true;
			}
			if (_fadeout <= 255 && _fadeout >=1)
			{
				start1 = false;
			}
			else
			{
				start1 = true;
			}
				if (start1 == true)
				{
					if (_fadeout >= 1)
					{
						_fadeout -= 3;
					}
				}

				if (start = true)
				{
					if (_fadeout <= 254)
					{
						_fadeout += 3;
					}
				}*/



		/*if (_fadeout >= -1 &&_fadeout <= 254)
		{
			start = true;
		}

		else
		{
			start = false;
		}
		if (_fadeout < 256 && _fadeout >= 1)
		{
			start1 = true;
		}
		else
		{
			start1 = false;
		}

			if (start = true)
			{
				if (_fadeout > -1)
				{
					_fadeout += 3;
				}
			}
			if (start1 = true)
			{
				if (_fadeout > 254)
				{
					_fadeout -= 3;
				}
			}*/
				/*if (start == true && _fadeout <= 1)
				{
				
					_fadeout += 3;
				}
				if (start1 == true)
				{
				
					_fadeout -= 3;
				}*/
			

		
		else
		{
			switch (_startState)
			{
			case intro1:
				_nowScene = IMAGEMANAGER->findImage("intro1sizeUp");
				_startState = intro2;
				_fadeout = 255;
		
				break;
			case intro2:
				_nowScene = IMAGEMANAGER->findImage("intro2siezeUp");
				_startState = intro3;
				_fadeout = 255;
		
				break;
			
			case intro3:
				_startState = intro4;
				_nowScene = IMAGEMANAGER->findImage("intro4sizeUp");
				_fadeout = 255;
			
			
			case intro4:
			
				

				break;

			}
		}
	}
}

void IntroScene::render()
{
	
	_nowScene->alphaRender(getMemDC(), 0, 0, _fadeout);

}

void IntroScene::release()
{
}
