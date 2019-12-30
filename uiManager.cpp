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
	IMAGEMANAGER->addImage("벨로그죽음", "벨로그죽음.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("벨로그활성", "벨로그활성.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("벨로그흑백", "벨로그흑백.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("선택UI", "선택UI.bmp", 39, 41, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("에릭죽음", "에릭죽음.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("에릭활성", "에릭활성.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("에릭흑백", "에릭흑백.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("올라프죽음", "올라프죽음.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("올라프활성", "올라프활성.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("올라프흑백", "올라프흑백.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("체력", "체력.bmp", 14, 15, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("UI틀", "UI틀.bmp", 800, 156, true, RGB(255, 0, 255));


	_ui = new image;
	_ui = IMAGEMANAGER->findImage("UI틀");
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
}
