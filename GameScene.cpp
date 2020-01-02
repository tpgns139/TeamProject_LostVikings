#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene()
{
}


GameScene::~GameScene()
{
}
HRESULT GameScene::init()
{
	/*IMAGEMANAGER->addFrameImage("ericIdle", "ericIdle.bmp", 0, 0, 336, 200, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("character", "character.bmp", 0, 0, 325, 200, 4, 2, true, RGB(255, 0, 255));


	IMAGEMANAGER->addFrameImage("character", "character.bmp", 0, 0, 325, 200, 4, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("묘비", "묘비.bmp", 0, 0, 891, 73, 11, 1, true, RGB(255, 0, 255));

	

	
	

	count = 0;
	IMAGEMANAGER->addImage("고기", "고기.bmp", 70, 75, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("과일", "과일.bmp", 50, 56, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("신발", "신발.bmp", 50, 56, true, RGB(255, 0, 255));

	*/
	IMAGEMANAGER->addImage("에너미불릿", "에너미불릿.bmp", 43, 19, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("배경", "Map.bmp", 4000, 1984, true, RGB(255, 0, 255));
	CAMERA->setBackGroundWidth(IMAGEMANAGER->findImage("배경")->getWidth());
	CAMERA->setBackGroundHeight(IMAGEMANAGER->findImage("배경")->getHeight());
	_im = new itemManager;
	_im->init();

	_mm = new MapManager;
	_mm->init();

	_pm = new PlayerManager;
	_pm->setAddressMapManager(_mm);
	_pm->init();

	_im->setPlayerMemoryAdrressLink(_pm);


	_em = new EnemyManager;
	_em->setMemoryAddressLink(_mm);
	_em->init();


	_ui = new uiManager;
	_ui->init();
	return S_OK;
}

void GameScene::update()
{

	CAMERA->update();
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		cout << CAMERA->getCameraXpos() + _ptMouse.x << "," << CAMERA->getCameraYpos() + _ptMouse.y << endl;
	}

	_im->update();
	_pm->update();

	_mm->update();
	_em->update();
	_ui->update();
}

void GameScene::render()
{

	IMAGEMANAGER->findImage("배경")->render(getMemDC(), 0, 0, CAMERA->getCameraXpos(), CAMERA->getCameraYpos(), WINSIZEX, WINSIZEY);
	_mm->render();
	_pm->render();
	_im->render();
	_mm->zOrderRender();
	_em->render();
	_ui->render();
}

void GameScene::release()
{

}


