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
	
	_shoes = IMAGEMANAGER->addImage("Shoes", "신발.bmp", 50, 56, true, RGB(255, 0, 255));
	_shoesX = _pm->get_vPlayer()[0]->getRect().left - 100 ;
	_shoesY = _pm->get_vPlayer()[0]->getRect().top ;
	IMAGEMANAGER->addImage("Key", "키.bmp", 50, 48, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Fruit", "과일.bmp", 50, 56, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("Meat", "고기.bmp", 70, 75, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addImage("0", "0.bmp", 15, 13, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("1", "1.bmp", 15, 13, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("2", "2.bmp", 15, 13, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("3", "3.bmp", 15, 13, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("4", "4.bmp", 15, 13, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("5", "5.bmp", 15, 13, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("6", "6.bmp", 15, 13, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("7", "7.bmp", 15, 13, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("8", "8.bmp", 15, 13, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("9", "9.bmp", 15, 13, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("상자", "상자.bmp", 54, 50, true, RGB(255, 0, 255));
	boxX = WINSIZEX / 2 + 300;
	boxY = WINSIZEY / 2 + 100;
	itemBox = IMAGEMANAGER->addFrameImage("상자열림", "상자열림.bmp", 328, 90,5,1, true, RGB(255, 0, 255));
	_currentFrameX = 0;
	
	itembox = new animation;
	itembox->init(itemBox->getWidth(), itemBox->getHeight(), itemBox->getFrameWidth(), itemBox->getFrameHeight());
	itembox->setPlayFrame(1, 5, false, false);
	itembox->setFPS(1);

	//count1 = 0;
	/*_action = new action;
	_action->init();*/

	

	actionTest = _action;

	for (int j = 0; j < _pm->get_vPlayer().size(); j++)
	{
		

		test = RectMakeCenter(_pm->get_vPlayer()[2]->getPlayerInfo()->position.x ,
			_pm->get_vPlayer()[2]->getPlayerInfo()->position.y,
			400, 400);

	}
	char score1[100];
	for (int i = 0; i < 10; i++)
	{
		sprintf_s(score1, "%d.bmp", i);
		_number[i] = new image;
		_number[i]->init(score1, 15, 13, true, RGB(255, 0, 255));
	}


	_rndItemCount = RND->getFromIntTo(1, 10);
	_rndItemCount = 0;
	move = false;

	setItem();
	return S_OK;
}

void itemManager::release()
{
}

void itemManager::update()
{

	itembox->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);




	if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
	{
		cout << "x : " << _ptMouse.x << "y : " << _ptMouse.y << endl;
	}
	
	//cout << _meat->getX() << endl;
	//cout << _fruit->getX() << endl;
	for (_viItem = _vItem.begin(); _viItem != _vItem.end(); ++_viItem)
	{
		(*_viItem)->setPos((*_viItem)->getPos().x, (*_viItem)->getPos().y);
		//(*_viItem)->setPos(_fruit->getX(), _fruit->getY());
		(*_viItem)->update();
		
	/*	cout << "x : " << (*_viItem)->getImage()->getX() << endl;
		cout << "y : " << (*_viItem)->getImage()->getY() << endl;*/

	}
	
	
	test = RectMakeCenter(_pm->get_vPlayer()[2]->getPlayerInfo()->position.x,
		_pm->get_vPlayer()[2]->getPlayerInfo()->position.y,
		400, 400);

	_currentFrameX++;

	if (_currentFrameX > 4)
	{
		_currentFrameX = 0;
	}
	//_action->moving();
	//_action->update();



			for (int i = 0; i < _vItem.size(); i++)
			{
				//angle = RND->getFromFloatTo(0, 1);

				

				if (getDistance(_vItem[i]->getPos().x, _vItem[i]->getPos().y, _pm->get_vPlayer()[0]->getPlayerInfo()->position.x, _pm->get_vPlayer()[0]->getPlayerInfo()->position.y) < 100)
				{
				
							POINT XXX;

							switch (i)
							{
							case 0:
								XXX.x = _vItem[i]->getPos().x + cosf(DO * 130)  * 5.0f;
								XXX.y = _vItem[i]->getPos().y - sinf(DO* 130) * 5.0f;
								_vItem[i]->setPos(XXX.x, XXX.y);
								break;
							case 1:
								XXX.x = _vItem[i]->getPos().x + cosf(DO * 150)  * 5.0f;
								XXX.y = _vItem[i]->getPos().y - sinf(DO * 150) * 5.0f;
								_vItem[i]->setPos(XXX.x, XXX.y);
								break;
							case 2:
								XXX.x = _vItem[i]->getPos().x + cosf(DO * 250)  * 5.0f;
								XXX.y = _vItem[i]->getPos().y - sinf(DO * 250) * 5.0f;
								_vItem[i]->setPos(XXX.x, XXX.y);
								break;
							case 3:
								XXX.x = _vItem[i]->getPos().x + cosf(DO * 190)  * 5.0f;
								XXX.y = _vItem[i]->getPos().y - sinf(DO * 190) * 5.0f;
								_vItem[i]->setPos(XXX.x, XXX.y);
								break;
							case 4:
								XXX.x = _vItem[i]->getPos().x + cosf(DO * 10)  * 5.0f;
								XXX.y = _vItem[i]->getPos().y - sinf(DO * 10) * 5.0f;
								_vItem[i]->setPos(XXX.x, XXX.y);
								break;
							
			
						}
					
				}
			}
	

			//cout << _pm->get_vPlayer()[2]->getPlayerInfo()->HP << " " << endl;
			//cout << score << "" << endl;
			

	collision();
}

void itemManager::render()
{

	//Rectangle(getMemDC(), _rc2);
	
	//box->render(getMemDC(), WINSIZEX / 2+300 - CAMERA->getCameraXpos(), WINSIZEY / 2+100 - CAMERA->getCameraYpos());
	/*if (box1 == false)
	{
		itemBox->frameRender(getMemDC(), WINSIZEX / 2 + 600 - CAMERA->getCameraXpos(), WINSIZEY / 2 + 40 - CAMERA->getCameraYpos(), 0, 0);
	}
	if (box1 == true)
	{
		itemBox->frameRender(getMemDC(), WINSIZEX / 2 + 600 - CAMERA->getCameraXpos(), WINSIZEY / 2 + 40 - CAMERA->getCameraYpos(), _currentFrameX, 0);
		
	}*/

	itemBox->aniRender(getMemDC(), WINSIZEX / 2 + 600 - CAMERA->getCameraXpos(), WINSIZEY / 2 + 40 - CAMERA->getCameraYpos(), itembox);
	if (start == true)
	{
		int _rndItemCount = RND->getFromIntTo(1, 2);

	
		if (_rndItemCount == 1)
		{
			item* item1;
			item1 = new Meat;
			item1->init("Meat", PointMake(_rc2.left, _rc2.top), meat);
			_itemNum = 4;
			_vItem.push_back(item1);
			start = false;
		}

		

		if (_rndItemCount == 2)
		{
			item* item3;
			item3 = new Fruit;
			item3->init("Fruit", PointMake(_rc2.left, _rc2.top), fruit);
			_itemNum = 2;
			_vItem.push_back(item3);
			start = false;
		}

		
	}


	for (_viItem = _vItem.begin(); _viItem != _vItem.end(); ++_viItem)
	{
		//(*_viItem)->render();
		/*for (int i = 0; i < _vItem.size(); i++)
		{
			if (_vItem[i]->getItemKinds() == box)
			{
				itemBox->frameRender(getMemDC(), (*_viItem)->getRect().left - CAMERA->getCameraXpos(), (*_viItem)->getRect().top - 200 - CAMERA->getCameraYpos()
					, _currentFrameX, 0);
			}*/

			//(*_viItem)->getImage()->render(getMemDC(), _meat->getX() - CAMERA->getCameraXpos(), _meat->getY() - CAMERA->getCameraYpos());
		
		
				(*_viItem)->getImage()->render(getMemDC(), (*_viItem)->getRect().left - CAMERA->getCameraXpos(), (*_viItem)->getRect().top - CAMERA->getCameraYpos());
		
		//}
		//Rectangle(getMemDC(), *(*_viItem)->getRect());
		if (KEYMANAGER->isStayKeyDown(VK_F11))
		{
			Rectangle(getMemDC(), (*_viItem)->getRect().left - CAMERA->getCameraXpos(), (*_viItem)->getRect().top - CAMERA->getCameraYpos(),
				(*_viItem)->getRect().right - CAMERA->getCameraXpos(), (*_viItem)->getRect().bottom - CAMERA->getCameraYpos());
		}
	}

	

	/*if (score >= 0)
	{
		if (score > 9) {
			int a = score / 10;
			int b = score % 10;
			_number[a]->render(getMemDC(), 30, 30);
			_number[b]->render(getMemDC(), 35, 35);
		}
		else {
			_number[score]->render(getMemDC(), 35, 30);
		}
	}*/
	if (_um->getStay() == true)
	
	{
		int tempscore = score;
		int cnumber; 
		int cx = WINSIZEX / 2 + 220;
		int cy = 137;
		while (tempscore > 0) {
			cnumber = tempscore % 10;
			tempscore /= 10;
			image* nimage = new image;
			nimage = _number[cnumber];
			nimage->render(getMemDC(), cx, cy);
			cx -= 20;
		}
	}


	
	//_shoes->render(getMemDC(), _shoesX - CAMERA->getCameraXpos(), _shoesY - CAMERA->getCameraYpos());

	
	

}

void itemManager::setItem()
{/*
	


	item* item2;
	item2 = new Key;
	item2->init("Key", PointMake(3790, 1722),key);
	_itemNum = 1;
	_vItem.push_back(item2);
	*/

	

	/*item* item4;
	item4 = new Meat;
	item4->init("Meat", PointMake(594, 1226),meat);
	_itemNum = 3;
	_vItem.push_back(item4);*/
	int _rndItemCount = RND->getFromIntTo(1, 5);

	for (int i = 0; i < _rndItemCount; i++)
	{
		item* item2;
		item2 = new Shoes;
		item2->init("Shoes", PointMake(_pm->get_vPlayer()[0]->getRect().left - 100, _pm->get_vPlayer()[0]->getRect().top + 100), shoes);
		_itemNum = 0;
		_vItem.push_back(item2);

	}
		for (int i = 0; i < _rndItemCount; i++)
		{
			item* item1;
			item1 = new Meat;
			item1->init("Meat", PointMake(_pm->get_vPlayer()[0]->getRect().left - 100, _pm->get_vPlayer()[0]->getRect().top + 200), meat);
			_itemNum = 4;
			_vItem.push_back(item1);
		}
	
		for (int i = 0; i < _rndItemCount; i++)
		{
			item* item3;
			item3 = new Fruit;
			item3->init("Fruit", PointMake(_pm->get_vPlayer()[0]->getRect().left - 100, _pm->get_vPlayer()[0]->getRect().top+200), fruit);
			_itemNum = 2;
			_vItem.push_back(item3);

		}
		/*if (box1 == false)
		{
			item* item4;
			item4 = new Box;
			item4->init("상자열림", PointMake(boxX, boxY), box);
			_vItem.push_back(item4);
		}*/
}

void itemManager::collision()
{
	for (int i = 0; i < _vItem.size(); i++)
	{
		for (int j = 0; j < _pm->get_vPlayer().size(); j++)
		{
	
	
			RECT temp1;
			if (IntersectRect(&temp1, &test, &_vItem[i]->getRect()))
			{
				
				

				//if (_vItem[i]->getItemKinds() != box)
				//{
					itemfire = true;

					/*_action->moveTo(_shoes, _pm->get_vPlayer()[0]->getPlayerInfo()->position.x,
						_pm->get_vPlayer()[1]->getPlayerInfo()->position.y, 1.0f);*/


					_angle = getAngle(_vItem[i]->getPos().x, _vItem[i]->getPos().y, _pm->get_vPlayer()[2]->getPlayerInfo()->position.x, _pm->get_vPlayer()[2]->getPlayerInfo()->position.y);




					if (itemfire)
					{
						POINT XX;

						XX.x = (_vItem[i]->getPos().x + cosf(_angle) * 5.0f);
						XX.y = (_vItem[i]->getPos().y - sinf(_angle) * 5.0f);

						_vItem[i]->setPos(XX.x, XX.y);


					}
			//	}
				
				/*if (KEYMANAGER->isOnceKeyDown('Z'))
				{
					if (_vItem[i]->getItemKinds() == box)
					{

						
						itemBox->frameRender(getMemDC(), boxX, boxY, 0, 0);
					

							removeItem(i);
						
					}
				}*/


			}
		}
		

	}

	for (int j = 0; j < _pm->get_vPlayer().size(); j++)
	{
		for (int i = 0; i < _vItem.size(); i++)
		{
			RECT temp;
			if (IntersectRect(&temp, &_vItem[i]->getRect(), &_pm->get_vPlayer()[2]->getPlayerInfo()->_rc))
			{
				if (_vItem[i]->getItemKinds()!=shoes  )
				{
					_pm->get_vPlayer()[2]->getPlayerInfo()->_vPlayerItem.push_back(_vItem[i]);
				}
				else
				{
					score += 10;
					_pm->get_vPlayer()[2]->getPlayerInfo()->HP += 1;
				}
			
				//if (_vItem[i]->getItemKinds() != box)
				//{
					
					removeItem(i);
				//}
				break;
			}
		}
	}

	for (int j = 0; j < _pm->get_vPlayer().size(); j++)
	{
		RECT temp2;
		_rc2 = RectMakeCenter(WINSIZEX / 2 + 600 - CAMERA->getCameraXpos(), WINSIZEY / 2 + 40 - CAMERA->getCameraYpos(), itemBox->getWidth() / 5, itemBox->getHeight());
		if (IntersectRect(&temp2, &_pm->get_vPlayer()[2]->getPlayerInfo()->_rc, &_rc2))
		{
			if (KEYMANAGER->isOnceKeyDown('Z'))
			{
				//box1 = true;

				itembox->start();

				start = true;			
			
				
			}
		}
	}
			
	
	


}


void itemManager::removeItem(int arrNum)
{
	_vItem.erase(_vItem.begin() + arrNum);
	
}






