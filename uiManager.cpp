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
	for (int i = 0;i < _pm->get_vPlayer().size();i++)
	{
		_playerItemVector.push_back(new uiInfo);
	}
	
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
	uiInfo* ins = new uiInfo;
	for (int i = 0;i < _pm->get_vPlayer().size();i++)
	{
		switch (_pm->get_vPlayer()[i]->getPlayerInfo()->_playerName)
		{
		case PN_ERIK:
			for (int j = 0;j < _pm->get_vPlayer()[i]->getPlayerInfo()->_vPlayerItem.size();j++)
			{
				ins->_itemList.push_back(_pm->get_vPlayer()[i]->getPlayerInfo()->_vPlayerItem[j]);
				ins->_itemPos.push_back(PointMake(198 + (j % 2) * 39, 639 + (j / 2) * 20));
				_playerItemVector[0] = ins;
				cout << j << endl;
			}
				break;
		case PN_BALEOG:
			for (int j = 0;j < _pm->get_vPlayer()[i]->getPlayerInfo()->_vPlayerItem.size();j++)
			{
				ins->_itemList.push_back(_pm->get_vPlayer()[i]->getPlayerInfo()->_vPlayerItem[j]);
				ins->_itemPos.push_back(PointMake(378 + (j % 2) * 39, 639 + (j / 2) * 20));
				_playerItemVector[1] = ins;
			}
			break;
		case PN_OLAF:
			for (int j = 0;j < _pm->get_vPlayer()[i]->getPlayerInfo()->_vPlayerItem.size();j++)
			{
				ins->_itemList.push_back(_pm->get_vPlayer()[i]->getPlayerInfo()->_vPlayerItem[j]);
				ins->_itemPos.push_back(PointMake(556 + (j % 2) * 39, 639 + (j / 2) * 20));
				_playerItemVector[2] = ins;
			}
			break;

		

		}

	}
	keyControl();
}

void uiManager::render()
{
	_ui->render(getMemDC(), 0, WINSIZEY);
	setState();
	for (_viUi = _vUi.begin(); _viUi != _vUi.end(); ++_viUi)
	{
		(*_viUi)->render();
	}
	for (int i = 0;i < _playerItemVector.size();i++)
	{
		
		for (int j = 0;j < _playerItemVector[i]->_itemList.size();j++)
		{
			switch (_playerItemVector[i]->_itemList[j]->getItemKinds())
			{
			case fruit:
				IMAGEMANAGER->findImage("FruitFrame")->frameRender(getMemDC(),
					_playerItemVector[i]->_itemPos[j].x,
					_playerItemVector[i]->_itemPos[j].y,
					0,0);
				
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
	
	//������ ���° ������
	




	Erik->render(getMemDC(), 117, 641);
	Baleog->render(getMemDC(), 296, 641);
	Olaf->render(getMemDC(), 475, 641);

	if (_select)
	{
		for (int i = 0;i < _vSelctUi.size();i++)
		{
			if (_selectNum == i)
			{
				_vSelctUi[i]->getImage()->frameRender(getMemDC(),
					_vSelctUi[i]->get_position().x,
					_vSelctUi[i]->get_position().y,
					_currentFrameX, 0
				);
			}
			else
			{
				_vSelctUi[i]->getImage()->frameRender(getMemDC(),
					_vSelctUi[i]->get_position().x,
					_vSelctUi[i]->get_position().y,
					0, 0
				);
			}
		}
		if (_timeTick % 10 == 0)
		{
			_currentFrameX++;
		}
		if (_currentFrameX > IMAGEMANAGER->findImage("����uiFrame")->getMaxFrameX())
		{
			_currentFrameX = 0;
		}
		_timeTick++;
		
	}
	else
	{
		for (int i = 0;i < _vSelctUi.size();i++)
		{
			_vSelctUi[i]->getImage()->frameRender(getMemDC(),
				_vSelctUi[i]->get_position().x,
				_vSelctUi[i]->get_position().y,
				0, 0
			);
		}
	}
	keyControl();
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

	ui* ui7;
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
	_vSelctUi.push_back(ui9);

	


	
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


	switch (_selectNum)
	{
	case 0:
		for (int i = 0;i < _vSelctUi.size();i++)
		{
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
			{
				_vSelctUi[i]->set_position().x;
				

				
			}
		}
		break;

	case 1:

		break;

	case 2:

		break;

	}
}
