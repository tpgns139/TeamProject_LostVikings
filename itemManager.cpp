#include "stdafx.h"
#include "itemManager.h"
#include"PlayerManager.h"

itemManager::itemManager()
{
}


itemManager::~itemManager()
{
}

HRESULT itemManager::init()
{

	IMAGEMANAGER->addImage("Shoes", "신발.bmp", 50, 56, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Key", "키.bmp", 50, 48, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Fruit", "과일.bmp", 50, 56, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Meat", "고기.bmp", 70, 75, true, RGB(255, 0, 255));

	



	setItem();
	return S_OK;
}

void itemManager::release()
{
}

void itemManager::update()
{
	for (_viItem = _vItem.begin(); _viItem != _vItem.end(); ++_viItem)
	{
		(*_viItem)->update();
	}

	collision();
}

void itemManager::render()
{
	for (_viItem = _vItem.begin(); _viItem != _vItem.end(); ++_viItem)
	{
		(*_viItem)->render();
	}
}

void itemManager::setItem()
{
	item* item1;
	item1 = new Shoes;
	item1->init("Shoes", PointMake(1300, 186));
	_vItem.push_back(item1);

	item* item2;
	item2 = new Key;
	item2->init("Key", PointMake(3790, 1722));
	_vItem.push_back(item2);

	item* item3;
	item3 = new Fruit;
	item3->init("Fruit", PointMake(1355, 1476));
	_vItem.push_back(item3);

	item* item4;
	item4 = new Meat;
	item4->init("Meat", PointMake(594, 1226));
	_vItem.push_back(item4);
}

void itemManager::collision()
{
	for (int i = 0; i < _vItem.size(); i++)
	{
		for (int j = 0; j < _pm->get_vPlayer().size(); j++)
		{
			RECT temp;
			if (IntersectRect(&temp, &_vItem[i]->getRect(), &_pm->get_vPlayer()[j]->getRect()))
			{
				removeItem(i);
			}	
		}
	}
}

void itemManager::removeItem(int arrNum)
{
	_vItem.erase(_vItem.begin() + arrNum);

}
