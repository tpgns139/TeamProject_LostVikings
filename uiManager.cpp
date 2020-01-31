#include "stdafx.h"
#include "uiManager.h"
#include"PlayerManager.h"

uiManager::uiManager()
{
}


uiManager::~uiManager()
{
}

HRESULT uiManager::init()
{
	IMAGEMANAGER->addFrameImage("MeatFrame", "���2.bmp", 70, 39, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("FruitFrame", "����2.bmp", 70, 39, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("KeyFrame", "Ű2.bmp", 70, 36, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ShoesFrame", "�Ź�2.bmp", 70, 39, 2, 1, true, RGB(255, 0, 255));
	Erik = IMAGEMANAGER->addImage("����Ȱ��", "����Ȱ��.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��������", "��������.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�������", "�������.bmp", 82, 65, true, RGB(255, 0, 255));

	Baleog = IMAGEMANAGER->addImage("���α����", "���α����.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���α�����", "���α�����.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���α�Ȱ��", "���α�Ȱ��.bmp", 82, 65, true, RGB(255, 0, 255));

	Olaf = IMAGEMANAGER->addImage("��������", "��������.bmp", 82, 65, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("�����Ȱ��", "�����Ȱ��.bmp", 82, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���������", "���������.bmp", 82, 65, true, RGB(255, 0, 255));

	_ui = IMAGEMANAGER->addImage("UIƲ", "UIƲ.bmp", 800, 156, true, RGB(255, 0, 255));

	_selectUiFrame = IMAGEMANAGER->addFrameImage("����uiFrame", "������������2.bmp", 78, 41, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ü��", "ü��.bmp", 14, 15, true, RGB(255, 0, 255));



	//�����̹���
	_inven = IMAGEMANAGER->addImage("Inven", "�κ�.bmp", 697, 526, true, RGB(255, 0, 255));
	_pointer = IMAGEMANAGER->addImage("�Ϲ�������", "�Ϲ�������.bmp", 60, 58, true, RGB(255, 0, 255));
	_pointer1 = IMAGEMANAGER->addImage("����������", "����������.bmp", 60, 58, true, RGB(255, 0, 255));
	_pointerX = 140;
	_pointerY = 200;
	_itemBox = IMAGEMANAGER->addImage("������â", "������â.bmp", 117, 106, true, RGB(255, 0, 255));
	_pointer2 = IMAGEMANAGER->addFrameImage("������", "������.bmp", 120, 58,2,1, true, RGB(255, 0, 255));
	_pointerX1 = 100;
	_pointerY1 = 206;
	_list1 = IMAGEMANAGER->addFrameImage("�κ�â", "�κ�â.bmp", 200, 91, 2, 1, true, RGB(255, 0, 255));
	_list2 = IMAGEMANAGER->addFrameImage("���â", "���â.bmp", 202, 90, 2, 1, true, RGB(255, 0, 255));
	_skillInven = IMAGEMANAGER->addImage("��ųâ ���", "��ųâ ���.bmp", 697, 526, true, RGB(255, 0, 255));
	itemOn = IMAGEMANAGER->addImage("���â Ȱ��", "���â Ȱ��.bmp", 619, 212, true, RGB(255, 0, 255));
	itemOff = IMAGEMANAGER->addImage("���â ��Ȱ��", "���â ��Ȱ��.bmp", 619, 213, true, RGB(255, 0, 255));
	worriorOn = IMAGEMANAGER->addImage("���罺ųâ Ȱ��", "���罺ųâ Ȱ��.bmp", 542, 174, true, RGB(255, 0, 255));
	worriorOff = IMAGEMANAGER->addImage("���罺ųâ ��Ȱ��", "���罺ųâ ��Ȱ��.bmp", 542, 175, true, RGB(255, 0, 255));
	wizardOn = IMAGEMANAGER->addImage("���罺ų Ȱ��", "���罺ų Ȱ��.bmp", 542, 176, true, RGB(255, 0, 255));
	wizardOff = IMAGEMANAGER->addImage("���罺ų ��Ȱ��", "���罺ų ��Ȱ��.bmp", 542, 176, true, RGB(255, 0, 255));
	weapon = IMAGEMANAGER->addImage("����", "����.bmp", 28, 28, true, RGB(255, 0, 255));
	armor = IMAGEMANAGER->addImage("��", "��.bmp", 38, 30, true, RGB(255, 0, 255));
	shoes1 = IMAGEMANAGER->addImage("�Ź�", "�Ź�.bmp", 34, 32, true, RGB(255, 0, 255));
	shield = IMAGEMANAGER->addImage("����", "����.bmp", 24, 28, true, RGB(255, 0, 255));
	glasses = IMAGEMANAGER->addImage("�Ȱ�", "�Ȱ�.bmp", 48, 12, true, RGB(255, 0, 255));
	accessories = IMAGEMANAGER->addImage("��������", "��������.bmp", 30, 30, true, RGB(255, 0, 255));
	hat = IMAGEMANAGER->addImage("����", "����.bmp", 32, 22, true, RGB(255, 0, 255));
	skillPointer1 = IMAGEMANAGER->addFrameImage("��ų������", "��ų������.bmp",116 , 58,2,1, true, RGB(255, 0, 255));
	itemPointer = IMAGEMANAGER->addImage("������������", "������������.bmp", 60, 58, true, RGB(255, 0, 255));
	goldBar = IMAGEMANAGER->addImage("���â", "���â.bmp", 120, 29, true, RGB(255, 0, 255));
	worriorSkill1 = IMAGEMANAGER->addImage("���罺ų1", "���罺ų1.bmp", 65, 69, true, RGB(255, 0, 255));
	worriorSkill2 = IMAGEMANAGER->addImage("���罺ų2", "���罺ų2.bmp", 65, 69, true, RGB(255, 0, 255));
	worriorSkill3 = IMAGEMANAGER->addImage("���罺ų3", "���罺ų3.bmp", 65, 69, true, RGB(255, 0, 255));
	worriorSkill4 = IMAGEMANAGER->addImage("���罺ų4", "���罺ų4.bmp", 65, 69, true, RGB(255, 0, 255));
	hpUi = IMAGEMANAGER->addImage("ü��ui", "ü��ui.bmp",401, 177, true, RGB(255, 0, 255));
	frontHp = IMAGEMANAGER->addImage("hpBar", "hpBar.bmp", 252, 14, true, RGB(255, 0, 255));
	mpBar = IMAGEMANAGER->addImage("mpBar", "mpBar.bmp", 226, 14, true, RGB(255, 0, 255));
	backHp = IMAGEMANAGER->addImage("backHp", "backHp.bmp", 252, 14, true, RGB(255, 0, 255));

	

	box1[num1] = 0;


	
	_selectUi = new image;
	_selectUi = IMAGEMANAGER->findImage("����UI");
	_selectUiX = 198;
	_selectUiY = 639;
	_selectUi1 = IMAGEMANAGER->findImage("����UI");
	_selectUiX1 = 378;
	_selectUiY1 = 639;
	_selectUi2 = IMAGEMANAGER->findImage("����UI");
	_selectUiX2 = 556;
	_selectUiY2 = 639;

	_Erik1 = E_ON;
	_Baleog2 = B_OFF;
	_Olaf3 = O_OFF;
	_select = false;
	_selectNum = 0;
	setUi();

	//���� ��� ��Ʈ
	for (int i = 0;i < _pm->get_vPlayer().size();i++)
	{
		_playerItemVector.push_back(new uiInfo);
	}
	
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (j < 2)
			{
				_rc[i][j] = RectMake(198 + (j * 43) + (i * 178),  639, 39, 41);
			}
			else if(j < 4)
				_rc[i][j] = RectMake(198 + ((j - 2) * 43) + (i * 178),   682, 39, 41);
			

			
		}
	}

	
	//�κ�â ��Ʈ
	for (int i = 0; i < 12; ++i)
	{
			if (i < 4)
			{
				
				_rc2[i] = RectMake(140 + i * 150, 200, 60, 58);
			}
			if (i >=4 && i <8)
			{
				_rc2[i] = RectMake(140 + (i-4) * 150, 350, 60, 58);
			}
			if (i >= 8 && i < 12)
			{
				_rc2[i] = RectMake(140 + (i - 8) * 150, 500, 60, 58);
			}
	}

	//������â ��Ʈ
	for (int i = 0; i < 12; ++i)
	{
		if (i < 4)
		{
			_rc3[i] = RectMake(100 + i * 105, 206, 60, 58);
		}
		if (i >= 4 && i < 6)
		{
			_rc3[i] = RectMake(528 + (i-4) * 90, 206, 60, 58);
		}
		if (i >= 6 && i < 10)
		{
			_rc3[i] = RectMake(100 + (i-6) * 105, 293, 60, 58);
		}
		if (i >= 10 && i < 12)
		{
			_rc3[i] = RectMake(528 + (i-10) * 90, 293, 60, 58);
		}
	}

	//��ųâ ��Ʈ
	for (int i = 0; i < 10; ++i)
	{
		if (i < 5)
		{
			_rc4[i] = RectMake(150 + i * 96, 420, 58, 58);
		}
		if (i >= 5 && i < 10)
		{
			_rc4[i] = RectMake(150 + (i-5) * 96, 488, 58, 58);
		}
	}
	

	count = 0;



	return S_OK;
}    

void uiManager::release()
{

}

void uiManager::update()
{
	//������ �κ��̵�
	//===============================================================
	for (_viUi = _vUi.begin(); _viUi != _vUi.end(); ++_viUi)
	{
		(*_viUi)->update();
	}
	uiInfo* ins = new uiInfo;
	for (int i = 0;i < _pm->get_vPlayer().size();i++)
	{
		switch (_pm->get_vPlayer()[i]->getPlayerInfo()->_playerName)
		{
		/*case PN_ERIK:
			for (int j = 0;j < _pm->get_vPlayer()[i]->getPlayerInfo()->_vPlayerItem.size();j++)
			{
				ins->_itemList.push_back(_pm->get_vPlayer()[i]->getPlayerInfo()->_vPlayerItem[j]);
				ins->_itemPos.push_back(PointMake(198 + (j % 2) * 39, 639 + (j / 2) * 20));
				_playerItemVector[0] = ins;
				cout << j << endl;
			}
				break;*/
		/*case PN_BALEOG:
			for (int j = 0;j < _pm->get_vPlayer()[i]->getPlayerInfo()->_vPlayerItem.size();j++)
			{
				ins->_itemList.push_back(_pm->get_vPlayer()[i]->getPlayerInfo()->_vPlayerItem[j]);
				ins->_itemPos.push_back(PointMake(378 + (j % 2) * 39, 639 + (j / 2) * 20));
				_playerItemVector[1] = ins;
			}
			break;*/
		/*case PN_OLAF:
			for (int j = 0;j < _pm->get_vPlayer()[i]->getPlayerInfo()->_vPlayerItem.size();j++)
			{
				ins->_itemList.push_back(_pm->get_vPlayer()[i]->getPlayerInfo()->_vPlayerItem[j]);
				ins->_itemPos.push_back(PointMake(556 + (j % 2) * 39, 639 + (j / 2) * 20));
				_playerItemVector[2] = ins;
			}
			break;*/
		case PN_OLAF:
			for (int j = 0;j < _pm->get_vPlayer()[i]->getPlayerInfo()->_vPlayerItem.size();j++)
			{
				
				ins->_itemList.push_back(_pm->get_vPlayer()[i]->getPlayerInfo()->_vPlayerItem[j]);
				ins->_itemPos.push_back(PointMake(150 + (j%4) * 150, 210 + (j/4)*150));
				_playerItemVector[0] = ins;
			}
			
			break;
		}
		
	}





	/*if (_goSelect)
	{*/
		keyControl();
	//}
		//===========================================================================
}

void uiManager::render()
{
	_ui->render(getMemDC(), 0, WINSIZEY);
	setState();
	for (_viUi = _vUi.begin(); _viUi != _vUi.end(); ++_viUi)
	{
		(*_viUi)->render();
	}
	
	
	

	Erik->render(getMemDC(), 117, 641);
	Baleog->render(getMemDC(), 296, 641);
	Olaf->render(getMemDC(), 475, 641);

	//=======================================================


	//��ųui  bool��
	if (skill == false)
	{
		worriorSkill1->render(getMemDC(), 400, 20);
		worriorSkill2->render(getMemDC(), 480, 20);
		worriorSkill3->render(getMemDC(), 560, 20);
		worriorSkill4->render(getMemDC(), 640, 20);
	}
	hpUi->render(getMemDC(), 0, 10);
	frontHp->render(getMemDC(), 124, 44);
	mpBar->render(getMemDC(), 150, 82);


	if (KEYMANAGER->isOnceKeyDown('Y'))
	{
		count += 1;
		
			stay = true;
			skill = true;
		stay2 = true;
	}
	if (count >= 2)
	{
		stay = false;
		stay2 = false;
		skill = false;
		count = 0;
	}

	if (stay2 == true)
	{
		
		if (item == false)
		{
			_list1->frameRender(getMemDC(), WINSIZEX / 2 - 100, 10, 1, 0);
			_list2->frameRender(getMemDC(), WINSIZEX / 2, 10, 0, 0);

			
		}

		if (item == true)
		{
			_list1->frameRender(getMemDC(), WINSIZEX / 2 - 100, 10, 0, 0);
			_list2->frameRender(getMemDC(), WINSIZEX / 2, 10, 1, 0);
			

			_skillInven->render(getMemDC(), 50, 100);
			
			if (stay3 == false)
			{

				
				itemOn->render(getMemDC(), 80, 150);
				worriorOff->render(getMemDC(), 100, 390);

			//������������
				for (int k = 0; k < _vPointer.size(); k++)
				{
					if (num1 == k)
					{
						_vPointer[k]->getImage()->frameRender(getMemDC(), _rc3[box1[num1]].left, _rc3[box1[num1]].top, 1, 0);
						//cout << box1[num1] << endl;
					}
					
					
				}
			
				weapon->render(getMemDC(), 116, 220);
				shield->render(getMemDC(), 223, 220);
				armor->render(getMemDC(), 320, 220);
				hat->render(getMemDC(), 427, 225);
				accessories->render(getMemDC(), 116, 310);
				accessories->render(getMemDC(), 220, 310);
				shoes1->render(getMemDC(), 320, 305);
				glasses->render(getMemDC(), 420, 315);
				weapon->render(getMemDC(), 545, 220);
				shield->render(getMemDC(), 638, 220);
				hat->render(getMemDC(), 546, 308);
				glasses->render(getMemDC(), 626, 315);
				//itemPointer->render(getMemDC(), 100, 206);
				/*itemPointer->render(getMemDC(), 205, 206);
				itemPointer->render(getMemDC(), 310, 206);
				itemPointer->render(getMemDC(), 415, 206);
				itemPointer->render(getMemDC(), 528, 206);
				itemPointer->render(getMemDC(), 618, 206);
				itemPointer->render(getMemDC(), 100, 293);*/

				


			}
			if (stay3 == true)
			{
				itemOff->render(getMemDC(), 80, 145);
				worriorOn->render(getMemDC(), 100, 390);

				//��ųâ ������
				for (int k = 0; k < _vSkillPointer.size(); k++)
				{
					if (num2 == k)
					{
						_vSkillPointer[k]->getImage()->frameRender(getMemDC(), _rc4[box2[num2]].left, _rc4[box2[num2]].top, 1, 0);

					}
					/*else
					{
						_vSkillPointer[k]->getImage()->frameRender(getMemDC(), _rc4[k].left, _rc4[k].top, 0, 0);
					}*/
				}


				weapon->render(getMemDC(), 116, 220);
				shield->render(getMemDC(), 223, 220);
				armor->render(getMemDC(), 320, 220);
				hat->render(getMemDC(), 427, 225);
				accessories->render(getMemDC(), 116, 310);
				shoes1->render(getMemDC(), 320, 305);
				glasses->render(getMemDC(), 420, 315);
				weapon->render(getMemDC(), 545, 220);
				shield->render(getMemDC(), 638, 220);
				hat->render(getMemDC(), 546, 308);
				glasses->render(getMemDC(), 626, 315);

				/*skillPointer->frameRender(getMemDC(), 150, 420);
				skillPointer->frameRender(getMemDC(), 246, 420);
				skillPointer->frameRender(getMemDC(), 246, 488);*/

				/*skillPointer->render(getMemDC(), 143, 417);
				skillPointer->render(getMemDC(), 239, 417);
				skillPointer->render(getMemDC(), 335, 417);
				skillPointer->render(getMemDC(), 431, 417);
				skillPointer->render(getMemDC(), 527, 417);*/


			}
		}

	}
	


	if (stay == true)
	{
		_inven->render(getMemDC(), 50, 100);
	
		
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				_itemBox->render(getMemDC(), 110 + i * 150, 180 + j * 150);
				_pointer->render(getMemDC(), 140 + i * 150, 200 + j * 150);
				goldBar->render(getMemDC(), WINSIZEX / 2 + 150, 130);

			}
		}
		
		//�κ�������
		for (int k = 0; k < _vPointer.size(); k++)
		{
				if (num == k)
				{
					
					_vPointer[k]->getImage()->frameRender(getMemDC(), _rc2[box[num]].left, _rc2[box[num]].top, 1, 0);
					//cout << _rc2[box[num]].left << endl;
				}
			
		}
	}


	if (KEYMANAGER->isOnceKeyDown('H'))
	{
		item = true;
		stay = false;
		stay2 = true;
	}
	if (KEYMANAGER->isOnceKeyDown('F'))
	{
		item = false;
		stay = true;
	}
	if (KEYMANAGER->isOnceKeyDown('G'))
	{
		stay3 = true;
	}
	if (KEYMANAGER->isOnceKeyDown('T'))
	{
		stay3 = false;
	}



	//=========================================================
/*	for (int i = 0;i < _vSelctUi.size();i++)
	{
	
		if (_selectNum == i && _goSelect)
		{
			_vSelctUi[i]->getImage()->frameRender(getMemDC(), _rc[_selectNum][_box[_selectNum]].left, _rc[_selectNum][_box[_selectNum]].top,
				_currentFrameX, 0);
		}
		else
		{
			_vSelctUi[i]->getImage()->frameRender(getMemDC(), _rc[i][_box[i]].left, _rc[i][_box[i]].top,
				0, 0);
		}

		if (_timeTick % 15 == 0)
		{
			_currentFrameX++;
		}
		if (_currentFrameX > IMAGEMANAGER->findImage("����uiFrame")->getMaxFrameX())
		{
			_currentFrameX = 0;
		}
		if (_currentFrameX > IMAGEMANAGER->findImage("FruitFrame")->getMaxFrameX())
		{
			_currentFrameX = 0;
		}
		_timeTick++;

	}*/


	//=========================================================================

	if (stay == true)
	{
	
		for (int i = 0;i < _playerItemVector.size();i++)
		{

			for (int j = 0;j < _playerItemVector[i]->_itemList.size();j++)
			{
				for (int l = 0;l < _pm->get_vPlayer().size();l++)
				{	
						switch (_playerItemVector[i]->_itemList[j]->getItemKinds())
						{
							
						case fruit:

							IMAGEMANAGER->findImage("FruitFrame")->frameRender(getMemDC(),
								_playerItemVector[i]->_itemPos[j].x,
								_playerItemVector[i]->_itemPos[j].y,
								0, 0);

							break;
						case meat:
							IMAGEMANAGER->findImage("MeatFrame")->frameRender(getMemDC(),
								_playerItemVector[i]->_itemPos[j].x,
								_playerItemVector[i]->_itemPos[j].y,
								0, 0);

							break;
						case key:
							IMAGEMANAGER->findImage("KeyFrame")->frameRender(getMemDC(),
								_playerItemVector[i]->_itemPos[j].x,
								_playerItemVector[i]->_itemPos[j].y,
								0, 0);

							break;
						case shoes:
							IMAGEMANAGER->findImage("ShoesFrame")->frameRender(getMemDC(),
								_playerItemVector[i]->_itemPos[j].x,
								_playerItemVector[i]->_itemPos[j].y,
								0, 0);
							break;
							
						}
					
				}
				
			}
		}
	}

	/*for (int i = 0; i < 12; ++i)
	{
		Rectangle(getMemDC(), _rc3[i]);
	}*/
	//======================================================================================
}

void uiManager::setUi()
{


	for (int i = 0; i < 3; i++)
	{
		ui* ui4;
		ui4 = new PlayerHpUi;
		ui4->init("ü��", PointMake(121 + i * 20, 706), Hp);
		_vUi.push_back(ui4);
	}
	for (int i = 0; i < 3; i++)
	{
		ui* ui5;
		ui5 = new PlayerHpUi;
		ui5->init("ü��", PointMake(300 + i * 20, 706), Hp);
		_vUi.push_back(ui5);
	}

	for (int i = 0; i < 3; i++)
	{
		ui* ui6;
		ui6 = new PlayerHpUi;
		ui6->init("ü��", PointMake(479 + i * 20, 706), Hp);
		_vUi.push_back(ui6);
	}

	/*ui* ui7;
	ui7 = new SelectUi;
	ui7->init("����uiFrame", PointMake(_selectUiX, _selectUiY), Pointer);
	_vSelctUi.push_back(ui7);

	ui* ui8;
	ui8 = new SelectUi;
	ui8->init("����uiFrame", PointMake(_selectUiX1, _selectUiY1), Pointer);
	_vSelctUi.push_back(ui8);

	ui* ui9;
	ui9 = new SelectUi;
	ui9->init("����uiFrame", PointMake(_selectUiX2, _selectUiY2), Pointer);
	_vSelctUi.push_back(ui9);*/

	//��������
	ui* ui10;
	ui10 = new pointer;
	ui10->init("������", PointMake(_pointerX, _pointerY), Pointer);
	_vPointer.push_back(ui10);

	ui* ui11;
	ui11 = new pointer;
	ui11->init("������", PointMake(_pointerX1, _pointerY1), Pointer);
	_vPointer.push_back(ui11);


	ui* ui12;
	ui12 = new skillPointer;
	ui12->init("��ų������", PointMake(150, 420), Pointer);
	_vSkillPointer.push_back(ui12);
	
}

void uiManager::setState()
{

	

	
	switch (_pm->get_nPlayer()->getPlayerInfo()->_playerName)
	{
		
	case PN_ERIK:
		Erik = IMAGEMANAGER->findImage("����Ȱ��");
		if (_baleog == false)
		{
			Baleog = IMAGEMANAGER->findImage("���α����");
		}
		if (_olaf== false)
		{
			Olaf = IMAGEMANAGER->findImage("��������");
		}
		if (KEYMANAGER->isOnceKeyDown(VK_F1))
		{
			_pm->get_nPlayer()->getPlayerInfo()->HP = 0;
		}

		_selectNum = 0;
		break;
	case PN_BALEOG:
		
			Baleog = IMAGEMANAGER->findImage("���α�Ȱ��");
			if (_eric == false)
			{
				Erik = IMAGEMANAGER->findImage("�������");
			}
			if (_olaf==false)
			{
				Olaf = IMAGEMANAGER->findImage("��������");
			}
			
			if (KEYMANAGER->isOnceKeyDown(VK_F2))
			{
				_pm->get_nPlayer()->getPlayerInfo()->HP = 0;
			}
			_selectNum = 1;
			break;

		
	case PN_OLAF:
			if (_baleog == false)
			{
				Baleog = IMAGEMANAGER->findImage("���α����");
			}
			if (_eric == false)
			{
				Erik = IMAGEMANAGER->findImage("�������");
			}
			Olaf = IMAGEMANAGER->findImage("�����Ȱ��");
			
			if (KEYMANAGER->isOnceKeyDown(VK_F3))
			{
				_pm->get_nPlayer()->getPlayerInfo()->HP = 0;
			}
			_selectNum = 2;
			break;
		
		
		
	}





	switch (_pm->get_nPlayer()->getPlayerInfo()->_playerName)
	{
	case PN_ERIK:

		if (_pm->get_nPlayer()->getPlayerInfo()->HP == 0)
		{
			_eric = true;
			if (_eric == true)
			{
				Erik = IMAGEMANAGER->findImage("��������");	
			}
		}
		break;

	case PN_BALEOG:
		if (_pm->get_nPlayer()->getPlayerInfo()->HP == 0)
		{
			_baleog = true;
			if (_baleog = true)
			{
				Baleog = IMAGEMANAGER->findImage("���α�����");
			}
			
		}
		break;
	case PN_OLAF:
		if (_pm->get_nPlayer()->getPlayerInfo()->HP == 0)
		{
			_olaf = true;
			if (_olaf==true)
			{
				Olaf = IMAGEMANAGER->findImage("���������");
			}
		}
		break;
	}
}

void uiManager::keyControl()
{

	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		if (_box[_selectNum] == 2 || _box[_selectNum] == 3) _box[_selectNum] -= 2;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		if (_box[_selectNum] == 0 || _box[_selectNum] == 1) _box[_selectNum] += 2;

	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		if (_box[_selectNum] == 0 || _box[_selectNum] == 2) _box[_selectNum] += 1;
		//if (box1[num1] == 0) box1[num1] += 1;
		
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		if (_box[_selectNum] == 1 || _box[_selectNum] == 3) _box[_selectNum] -= 1;
		//if (box2[num2] == 1) box2[num2] -= 1;

	}



	//���� �̵�Ű
	//==================================================================
	if (item == false )
	{
		if (KEYMANAGER->isOnceKeyDown('I'))
		{
			if (box[num] >= 4 && box[num] <= 11) box[num] -= 4;

		}
		if (KEYMANAGER->isOnceKeyDown('K'))
		{
			if (box[num] >= 0 && box[num] <= 7) box[num] += 4;

		}
		if (KEYMANAGER->isOnceKeyDown('J'))
		{
			if (box[num] != 0) box[num] -= 1;

		}
		if (KEYMANAGER->isOnceKeyDown('L'))
		{
			if (box[num] != 11) box[num] += 1;
		}
	}

	if (item == true && stay3 == false)
	{
		
		if (KEYMANAGER->isOnceKeyDown('I'))
		{
			if (box1[num1] >= 6 && box1[num1] <= 11) box1[num1] -= 6;

		}
		if (KEYMANAGER->isOnceKeyDown('K'))
		{
			if (box1[num1] >= 0 && box1[num1] <= 5) box1[num1] += 6;

		}
		if (KEYMANAGER->isOnceKeyDown('J'))
		{
			if (box1[num1] != 0) box1[num1] -= 1;

		}
		if (KEYMANAGER->isOnceKeyDown('L'))
		{
			if (box1[num1] != 11) box1[num1] += 1;
		}
	}

	if (item == true && stay3 == true)
	{

		if (KEYMANAGER->isOnceKeyDown('I'))
		{
			if (box2[num2] >= 5 && box2[num2] <= 9) box2[num2] -= 5;

		}
		if (KEYMANAGER->isOnceKeyDown('K'))
		{
			if (box2[num2] >= 0 && box2[num2] <= 4) box2[num2] += 5;

		}
		if (KEYMANAGER->isOnceKeyDown('J'))
		{
			if (box2[num2] != 0) box2[num2] -= 1;

		}
		if (KEYMANAGER->isOnceKeyDown('L'))
		{
			if (box2[num2] != 9) box2[num2] += 1;
		}
	}
	//======================================================================

	//cout << _box[0] << " " << _box[1] << " " << _box[2] << endl;
}

bool uiManager::getStay()
{
	return stay;
}
