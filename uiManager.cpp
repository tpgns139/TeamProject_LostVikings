#include "stdafx.h"
#include "uiManager.h"


uiManager::uiManager()
{
}


uiManager::~uiManager()
{
}

HRESULT uiManager::init()
{
	_Baleog = IMAGEMANAGER->addImage("벨로그흑백", "벨로그흑백.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("벨로그죽음", "벨로그죽음.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("벨로그활성", "벨로그활성.bmp", 82, 65, true, RGB(255, 0, 255));
	 
	_Eric = IMAGEMANAGER->addImage("에릭활성", "에릭활성.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("에릭죽음", "에릭죽음.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("에릭흑백", "에릭흑백.bmp", 82, 65, true, RGB(255, 0, 255));

	_Olaf = IMAGEMANAGER->addImage("울라프흑백", "울라프흑백.bmp", 82, 65, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("울라프활성", "울라프활성.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("울라프죽음", "울라프죽음.bmp", 82, 65, true, RGB(255, 0, 255));

	_playerHp = IMAGEMANAGER->addImage("체력", "체력.bmp", 14, 15, true, RGB(255, 0, 255));
	_ui = IMAGEMANAGER->addImage("UI틀", "UI틀.bmp", 800, 156, true, RGB(255, 0, 255));
	_selectUi = IMAGEMANAGER->addImage("선택UI", "선택UI.bmp", 39, 41, true, RGB(255, 0, 255));

	/*_ui = new image;
	_ui = IMAGEMANAGER->findImage("UI틀");*/
	return S_OK;
}    

void uiManager::release()
{

}

void uiManager::update()
{

}

void uiManager::render()
{
	_ui->render(getMemDC(), 0, WINSIZEY - 156);
	_Eric->render(getMemDC(),117,WINSIZEY -115);
	_Baleog->render(getMemDC(), 296, WINSIZEY - 115);
	_Olaf->render(getMemDC(), 475, WINSIZEY - 115);
	_selectUi->render(getMemDC(), 198, WINSIZEY- 117);
	_playerHp->render(getMemDC(), 121, WINSIZEY - 50);
	_playerHp->render(getMemDC(), 141, WINSIZEY - 50);
	_playerHp->render(getMemDC(), 161, WINSIZEY - 50);
	//_selectUi X 좌표 198,378,556
}
