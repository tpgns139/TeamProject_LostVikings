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
	IMAGEMANAGER->addImage("���α�����", "���α�����.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���α�Ȱ��", "���α�Ȱ��.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���α����", "���α����.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����UI", "����UI.bmp", 39, 41, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��������", "��������.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����Ȱ��", "����Ȱ��.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�������", "�������.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ö�������", "�ö�������.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ö���Ȱ��", "�ö���Ȱ��.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ö������", "�ö������.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ü��", "ü��.bmp", 14, 15, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("UIƲ", "UIƲ.bmp", 800, 156, true, RGB(255, 0, 255));


	_ui = new image;
	_ui = IMAGEMANAGER->findImage("UIƲ");
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
