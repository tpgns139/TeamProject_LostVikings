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
	_Baleog = IMAGEMANAGER->addImage("���α����", "���α����.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���α�����", "���α�����.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���α�Ȱ��", "���α�Ȱ��.bmp", 82, 65, true, RGB(255, 0, 255));
	 
	_Eric = IMAGEMANAGER->addImage("����Ȱ��", "����Ȱ��.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��������", "��������.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�������", "�������.bmp", 82, 65, true, RGB(255, 0, 255));

	_Olaf = IMAGEMANAGER->addImage("��������", "��������.bmp", 82, 65, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("�����Ȱ��", "�����Ȱ��.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���������", "���������.bmp", 82, 65, true, RGB(255, 0, 255));

	_playerHp = IMAGEMANAGER->addImage("ü��", "ü��.bmp", 14, 15, true, RGB(255, 0, 255));
	_ui = IMAGEMANAGER->addImage("UIƲ", "UIƲ.bmp", 800, 156, true, RGB(255, 0, 255));
	_selectUi = IMAGEMANAGER->addFrameImage("����UI", "����UI.bmp",39, 41,1,1, true, RGB(255, 0, 255));

	/*_ui = new image;
	_ui = IMAGEMANAGER->findImage("UIƲ");*/
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
	_ui->render(getMemDC(), 0, WINSIZEY);
	_Eric->render(getMemDC(),117,WINSIZEY +41);
	_Baleog->render(getMemDC(), 296, WINSIZEY+41);
	_Olaf->render(getMemDC(), 475, WINSIZEY + 41);
	_selectUi->render(getMemDC(), 198, WINSIZEY+39);
	_playerHp->render(getMemDC(), 121, WINSIZEY +106);
	_playerHp->render(getMemDC(), 141, WINSIZEY + 106);
	_playerHp->render(getMemDC(), 161, WINSIZEY + 106);
}
