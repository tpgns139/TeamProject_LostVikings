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
	
	
	IMAGEMANAGER->addImage("에너미불릿", "에너미불릿.bmp", 43, 19, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("배경", "Map.bmp", 4000, 1984, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("화살", "arrow.bmp", 37, 40,1,2, true, RGB(255, 0, 255));
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
	_em->setplayerMemoryAddressLink(_pm);
	_em->init();
	
	_selectUi = false;


	_ui = new uiManager;
	_ui->setPlayerManager(_pm);
	_ui->init();


	_pm->setAddressEnemyManager(_em);
	_changeNowPlayer = false;

	return S_OK;
}

void GameScene::update()
{




	if (!_selectUi)
	{

		CAMERA->update();
		if (_changeNowPlayer)
		{
			CAMERA->moveTo(_pm->get_nPlayer()->getPlayerPos().x, _pm->get_nPlayer()->getPlayerPos().y, 0.5f);
			_changeNowPlayer = false;
		}

		_im->update();
		_pm->update();

		_mm->update();
		_em->update();
		_ui->setSelect(_selectUi);
		if (KEYMANAGER->isOnceKeyDown(VK_TAB))
		{
			_selectUi = true;
		}
	}
	else
	{
		_ui->setSelect(_selectUi);
		if (KEYMANAGER->isOnceKeyDown(VK_TAB))
		{
			_selectUi = false;
		}

		if (KEYMANAGER->isOnceKeyDown(VK_CONTROL))
		{
			_pm->setNowPlayer();
			_changeNowPlayer = true;
		}
			
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		 
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


