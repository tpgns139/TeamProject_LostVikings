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
	 IMAGEMANAGER->addImage("���α����", "���α����.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���α�����", "���α�����.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���α�Ȱ��", "���α�Ȱ��.bmp", 82, 65, true, RGB(255, 0, 255));
	 
	IMAGEMANAGER->addImage("����Ȱ��", "����Ȱ��.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��������", "��������.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�������", "�������.bmp", 82, 65, true, RGB(255, 0, 255));

	 IMAGEMANAGER->addImage("��������", "��������.bmp", 82, 65, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("�����Ȱ��", "�����Ȱ��.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���������", "���������.bmp", 82, 65, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("ü��", "ü��.bmp", 14, 15, true, RGB(255, 0, 255));
	_ui = IMAGEMANAGER->addImage("UIƲ", "UIƲ.bmp", 800, 156, true, RGB(255, 0, 255));
	_selectUi = IMAGEMANAGER->addFrameImage("����UI", "����UI.bmp",39, 41,1,1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����UI", "����UI.bmp", 39, 41, true, RGB(255, 0, 255));

	_selectUi = new image;
	_selectUi = IMAGEMANAGER->findImage("����UI");
	_selectUiX = 198;
	_selectUiY = WINSIZEY - 117;
	_selectUi1 = IMAGEMANAGER->findImage("����UI");
	_selectUi2 = IMAGEMANAGER->findImage("����UI");


	setUi();

	/*_ui = new image;
	_ui = IMAGEMANAGER->findImage("UIƲ");*/
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
	/*_ui->render(getMemDC(), 0, WINSIZEY);
	_Eric->render(getMemDC(),117,WINSIZEY +41);
	_Baleog->render(getMemDC(), 296, WINSIZEY+41);
	_Olaf->render(getMemDC(), 475, WINSIZEY + 41);
	_selectUi->render(getMemDC(), 198, WINSIZEY+39);
	_playerHp->render(getMemDC(), 121, WINSIZEY +106);
	_playerHp->render(getMemDC(), 141, WINSIZEY + 106);*/
	_playerHp->render(getMemDC(), 161, WINSIZEY + 106);
	for (_viUi = _vUi.begin(); _viUi != _vUi.end(); ++_viUi)
	{
		(*_viUi)->render();
	}

	
	/*_Eric->render(getMemDC(),117,WINSIZEY -115);
	_Baleog->render(getMemDC(), 296, WINSIZEY - 115);
	_Olaf->render(getMemDC(), 475, WINSIZEY - 115);
	_selectUi->render(getMemDC(), _selectUiX , _selectUiY);
	_selectUi1->render(getMemDC(), 378, WINSIZEY - 117);
	_selectUi2->render(getMemDC(), 556, WINSIZEY - 117);
	_playerHp->render(getMemDC(), 121, WINSIZEY - 50);
	_playerHp->render(getMemDC(), 141, WINSIZEY - 50);
	_playerHp->render(getMemDC(), 161, WINSIZEY - 50);*/

	//_selectUi X ��ǥ 198,378,556
}

void uiManager::setUi()
{
	ui* ui1;
	ui1 = new BaleogUi;
	ui1->init("���α�����", PointMake(296, WINSIZEY - 115));
	_vUi.push_back(ui1);

	ui* ui2;
	ui2 = new EricUi;
	ui2->init("�������", PointMake(117, WINSIZEY - 115));
	_vUi.push_back(ui2);

	ui* ui3;
	ui3 = new OlafUi;
	ui3->init("�����Ȱ��", PointMake(475, WINSIZEY - 115));
	//ui3->init("�����Ȱ��", 475, WINSIZEY - 115);
	_vUi.push_back(ui3);


	for (int i = 0; i < 3; i++)
	{
			ui* ui4;
			ui4 = new PlayerHpUi;
			ui4->init("ü��", PointMake(121 + i * 20, WINSIZEY - 50));
			_vUi.push_back(ui4);
	}
	for (int i = 0; i < 3; i++)
	{
		ui* ui8;
		ui8 = new PlayerHpUi;
		ui8->init("ü��", PointMake(300 + i * 20, WINSIZEY - 50));
		_vUi.push_back(ui8);
	}

	for (int i = 0; i < 3; i++)
	{
		ui* ui9;
		ui9 = new PlayerHpUi;
		ui9->init("ü��", PointMake(479 + i * 20, WINSIZEY - 50));
		_vUi.push_back(ui9);
	}

	ui* ui5;
	ui5 = new SelectUi;
	ui5->init("����UI", PointMake(_selectUiX, _selectUiY));
	_vUi.push_back(ui5);

	ui* ui6;
	ui6 = new SelectUi;
	ui6->init("����UI", PointMake(378, WINSIZEY - 117));
	_vUi.push_back(ui6);

	ui* ui7;
	ui7 = new SelectUi;
	ui7->init("����UI", PointMake(556, WINSIZEY - 117));
	_vUi.push_back(ui7);
	
}
