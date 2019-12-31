#include "stdafx.h"
#include "Baleog.h"


Baleog::Baleog()
{
}


Baleog::~Baleog()
{
}

HRESULT Baleog::init(PlayerName playerName)
{
	
	//��α� �̹���//
	//IMAGEMANAGER->addFrameImage("Bidle3", "image/baleogImage/idle3.bmp", 0, 0, 79, 200, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("B_idle1", "image/baleogImage/idle1.bmp", 0, 0, 325, 200, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("B_idle2", "image/baleogImage/idle2.bmp", 0, 0, 484, 200, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("B_attak1", "image/baleogImage/attak1.bmp", 400, 200, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("B_attack2", "image/baleogImage/attack2.bmp", 400, 200, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("B_attack_bow", "image/baleogImage/attack_bow.bmp", 800, 200, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("B_attacked", "image/baleogImage/attcked1.bmp", 94, 200, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("B_die", "image/baleogImage/die.bmp", 637, 200, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("B_die_electric", "image/baleogImage/die_electric.bmp", 200, 200, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("B_die_fall", "image/baleogImage/die_fall.bmp", 300, 200, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("B_drop", "image/baleogImage/drop.bmp", 103, 100, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("B_drop_after", "image/baleogImage/drop_after.bmp", 500, 200, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("B_fly", "image/baleogImage/fly.bmp", 175, 200, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("B_push", "image/baleogImage/push.bmp", 400, 200, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("B_run", "image/baleogImage/run.bmp", 772, 200, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("B_teleport", "image/baleogImage/teleport.bmp", 677, 200, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("B_up", "image/baleogImage/up.bmp", 325, 100, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("B_up_end", "image/baleogImage/up_end.bmp", 200, 100, 2, 1, true, RGB(255, 0, 255));
	_playerInfo._image = IMAGEMANAGER->findImage("B_idle1");
	_playerInfo.position.x = WINSIZEX / 2;		//���α� x��ǥ
	_playerInfo.position.y = WINSIZEY / 2;		//���α� y��ǥ
	_playerInfo.count = 0;						//���α� ������ ī��Ʈ0;
	_playerInfo._CurrentFrameX = _playerInfo._CurrentFrameY = 0;		//���α� ������ x,y �ʱ�ȭ
	_playerInfo._playerName = playerName;		//ĳ���� �̹��� ����
	_playerInfo._rc = RectMakeCenter(_playerInfo.position.x, _playerInfo.position.y, _playerInfo._image->getFrameWidth(), _playerInfo._image->getFrameHeight());
	_playerInfo.speed = 1.0f;

	Player::MakeRect();

	return S_OK;
}
void Baleog::update()
{
	Frame();
	Keycontrol();
	Player::update();
	//���α� ��Ʈ ������Ʈ
	//_playerInfo._rc = RectMakeCenter(_playerInfo.position.x-CAMERA->getCameraXpos(), _playerInfo.position.y-CAMERA->getCameraYpos(), _playerInfo._image->getFrameWidth(), _playerInfo._image->getFrameHeight());

	rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2 + 50, 100, 100);
}

void Baleog::render()
{

	_playerInfo._image->frameRender(getMemDC(), _playerInfo._rc.left,_playerInfo._rc.top,_playerInfo._CurrentFrameX,_playerInfo._CurrentFrameY);
	if (KEYMANAGER->isToggleKey('1'))
	{
		Rectangle(getMemDC(), _playerInfo._rc);		//���α׷�Ʈ ����
	}
	
	Player::render();	//���α� ��ٸ��浹 ��Ʈ
}

void Baleog::Keycontrol()
{
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		_Direction = LEFT;
		_playerInfo._CurrentFrameY = 1;																									//���α� �����̵�
		_BaleogState = BALEOG_LEFTMOVE;
	}
	if (KEYMANAGER->isOnceKeyUp('A'))
	{
		_Direction = LEFT;
		_playerInfo._image->getMaxFrameX();																								//���α� ���� ������ ��������
		_playerInfo._CurrentFrameX = 0;
		_playerInfo._CurrentFrameY = 1;
		_BaleogState = BALEOG_LEFTIDLE;

	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		_Direction = RIGHT;																												//���α� �������̵�
		_playerInfo._CurrentFrameY = 0;
		_BaleogState = BALEOG_RIGHTMOVE;
	}
	if (KEYMANAGER->isOnceKeyUp('D'))
	{
		_Direction = RIGHT;
		_playerInfo._CurrentFrameX = 0;																									//���α� ������ ������ ��������
		_playerInfo._CurrentFrameY = 0;
		_BaleogState = BALEOG_RIGHTIDLE;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		if (_BaleogState == BALEOG_RIGHTIDLE || _BaleogState == BALEOG_RIGHTMOVE)														//���α� ����Ű 
		{
			_Direction = RIGHT;
			_playerInfo._CurrentFrameX = 0;
			_playerInfo._CurrentFrameY = 0;
			_BaleogState = BALEOG_RIGHTATTACK;

		}
		if (_BaleogState == BALEOG_LEFTIDLE || _BaleogState == BALEOG_LEFTMOVE)
		{
			_Direction = LEFT;
			_playerInfo._CurrentFrameX = -1;
			_playerInfo._CurrentFrameY = 1;
			_BaleogState = BALEOG_LEFTATTACK;

		}
	}
	if (KEYMANAGER->isOnceKeyUp(VK_SPACE))																								//���α� ����Ű ������ ��������
	{
		if (_BaleogState == BALEOG_RIGHTATTACK)
		{
			_playerInfo._image->setFrameY(0);
			_playerInfo._CurrentFrameX = 0;
			_BaleogState = BALEOG_RIGHTIDLE;
		}
		if (_BaleogState == BALEOG_LEFTATTACK)
		{
			_playerInfo._image->setFrameY(1);
			_playerInfo._CurrentFrameX = 0;
			_BaleogState = BALEOG_LEFTIDLE;
		}
	}
	if (KEYMANAGER->isOnceKeyDown('F'))																										//���α� ȭ�����
	{
		if (_BaleogState == BALEOG_RIGHTIDLE || _BaleogState == BALEOG_RIGHTMOVE)
		{
			_playerInfo._image->setFrameY(0);
			_BaleogState = BALEOG_RIGHTBOWATTACK;
		}
		if (_BaleogState == BALEOG_LEFTIDLE || _BaleogState == BALEOG_LEFTMOVE)
		{
			_playerInfo._image->setFrameY(1);
			_BaleogState = BALEOG_LEFTBOWATTACK;
		}
	}

	if (KEYMANAGER->isOnceKeyUp('F'))																										//���α� ȭ����� ��������
	{
		if (_BaleogState == BALEOG_RIGHTBOWATTACK)
		{
			_playerInfo._image->setFrameY(0);
			_playerInfo._CurrentFrameX = 0;
			_BaleogState = BALEOG_RIGHTIDLE;

		}
		if (_BaleogState == BALEOG_LEFTBOWATTACK)
		{
			_playerInfo._image->setFrameY(1);
			_playerInfo._CurrentFrameX = 0;
			_BaleogState = BALEOG_LEFTIDLE;
		}	
	}
	switch (_BaleogState)																													//���α� ������Ʈ 
	{
	case BALEOG_RIGHTIDLE:
		_playerInfo._image = IMAGEMANAGER->findImage("B_idle1");
		break;
	case BALEOG_LEFTIDLE:
		_playerInfo._image = IMAGEMANAGER->findImage("B_idle1");
		break;
	case BALEOG_RIGHTMOVE:
		_playerInfo._image = IMAGEMANAGER->findImage("B_run");
		break;
	case BALEOG_LEFTMOVE:
		_playerInfo._image = IMAGEMANAGER->findImage("B_run");
		break;
	case BALEOG_LEFTATTACK:
		_playerInfo._image = IMAGEMANAGER->findImage("B_attak1");
		break;
	case BALEOG_RIGHTATTACK:
		_playerInfo._image = IMAGEMANAGER->findImage("B_attak1");
		break;
	case BALEOG_RIGHTBOWATTACK:
		_playerInfo._image = IMAGEMANAGER->findImage("B_attack_bow");
		break;
	case BALEOG_LEFTBOWATTACK:
		_playerInfo._image = IMAGEMANAGER->findImage("B_attack_bow");
		break;
	case BALEOG_PUSH:
		_playerInfo._image = IMAGEMANAGER->findImage("B_push");
		break;
	case BALEOG_UP:
		_playerInfo._image = IMAGEMANAGER->findImage("B_up");
	default:
		break;
	}

	}


void Baleog::Frame()
{
	_playerInfo.count++;
	if (_playerInfo.count % 20 == 0)
	{
		if (_Direction == RIGHT)
		{
			_playerInfo._CurrentFrameX++;
			if (_playerInfo._CurrentFrameX > _playerInfo._image->getMaxFrameX()) _playerInfo._CurrentFrameX = 0;
		}
		else if (_Direction == LEFT)
		{
			_playerInfo._CurrentFrameX--;
			if (_playerInfo._CurrentFrameX < 0)_playerInfo._CurrentFrameX = _playerInfo._image->getMaxFrameX();

		}
	}
	cout << _playerInfo._CurrentFrameX << "," << _playerInfo._image->getMaxFrameX() << endl;
}


