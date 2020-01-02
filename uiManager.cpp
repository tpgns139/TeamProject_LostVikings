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
	 
	IMAGEMANAGER->addImage("에릭활성", "에릭활성.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("에릭죽음", "에릭죽음.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("에릭흑백", "에릭흑백.bmp", 82, 65, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("벨로그흑백", "벨로그흑백.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("벨로그죽음", "벨로그죽음.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("벨로그활성", "벨로그활성.bmp", 82, 65, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("울라프흑백", "울라프흑백.bmp", 82, 65, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("울라프활성", "울라프활성.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("울라프죽음", "울라프죽음.bmp", 82, 65, true, RGB(255, 0, 255));

	_ui = IMAGEMANAGER->addImage("UI틀", "UI틀.bmp", 800, 156, true, RGB(255, 0, 255));
	_selectUi = IMAGEMANAGER->addFrameImage("선택UI", "선택UI.bmp",39, 41,1,1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("선택UI", "선택UI.bmp", 39, 41, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("체력", "체력.bmp", 14, 15, true, RGB(255, 0, 255));

	_selectUi = new image;
	_selectUi = IMAGEMANAGER->findImage("선택UI");
	_selectUiX = 198;
	_selectUiY = 639;
	_selectUi1 = IMAGEMANAGER->findImage("선택UI");
	_selectUi2 = IMAGEMANAGER->findImage("선택UI");


	setUi();

	/*_ui = new image;
	_ui = IMAGEMANAGER->findImage("UI틀");*/
	return S_OK;
}    

void uiManager::release()
{

}

void uiManager::update()
{
	for (_viUi = _vUi.begin(); _viUi != _vUi.end(); ++_viUi)
	{
		(*_viUi)->update();
	}
}

void uiManager::render()
{
	_ui->render(getMemDC(), 0, WINSIZEY);

	for (_viUi = _vUi.begin(); _viUi != _vUi.end(); ++_viUi)
	{
		(*_viUi)->render();
	}
	
}

void uiManager::setUi()
{
	ui* ui1;
	ui1 = new EricUi;
	ui1->init("에릭활성", PointMake(117, 641));
	_vUi.push_back(ui1);

	ui* ui2;
	ui2 = new BaleogUi;
	ui2->init("벨로그흑백", PointMake(296, 641));
	_vUi.push_back(ui2);


	ui* ui3;
	ui3 = new OlafUi;
	ui3->init("울라프흑백", PointMake(475, 641));
	//ui3->init("울라프활성", 475, WINSIZEY - 115);
	_vUi.push_back(ui3);


	for (int i = 0; i < 3; i++)
	{
			ui* ui4;
			ui4 = new PlayerHpUi;
			ui4->init("체력", PointMake(121 + i * 20, 706));
			_vUi.push_back(ui4);
	}
	for (int i = 0; i < 3; i++)
	{
		ui* ui5;
		ui5 = new PlayerHpUi;
		ui5->init("체력", PointMake(300 + i * 20, 706));
		_vUi.push_back(ui5);
	}

	for (int i = 0; i < 3; i++)
	{
		ui* ui6;
		ui6 = new PlayerHpUi;
		ui6->init("체력", PointMake(479 + i * 20, 706));
		_vUi.push_back(ui6);
	}

	ui* ui7;
	ui7 = new SelectUi;
	ui7->init("선택UI", PointMake(_selectUiX, _selectUiY));
	_vUi.push_back(ui7);

	ui* ui8;
	ui8 = new SelectUi;
	ui8->init("선택UI", PointMake(378, 639));
	_vUi.push_back(ui8);

	ui* ui9;
	ui9 = new SelectUi;
	ui9->init("선택UI", PointMake(556, 639));
	_vUi.push_back(ui9);
	
}

void uiManager::setState()
{
	switch (_Erik1)
	{
	case E_ON:
		Erik = IMAGEMANAGER->findImage("에릭활성");
		break;
	case E_OFF:
		Erik = IMAGEMANAGER->findImage("에릭흑백");
		break;
	case E_DEATH:
		Erik = IMAGEMANAGER->findImage("에릭죽음");
		break;
	
	default:
		break;
	}

	switch (_Baleog2)
	{
	case B_ON:
		Baleog = IMAGEMANAGER->findImage("벨로그활성");
		break;
	case B_OFF:
		Baleog = IMAGEMANAGER->findImage("벨로그흑백");
		break;
	case B_DEATH:
		Baleog = IMAGEMANAGER->findImage("벨로그죽음");
		break;
	default:
		break;
	}

	switch (_Olaf3)
	{
	case O_ON:
		Olaf = IMAGEMANAGER->findImage("울라프활성");
		break;
	case O_OFF:
		Olaf = IMAGEMANAGER->findImage("울라프흑백");
		break;
	case O_DEATH:
		Olaf = IMAGEMANAGER->findImage("울라프죽음");
		break;
	default:
		break;
	}
}
