#include "stdafx.h"
#include "Erik.h"


Erik::Erik()
{
}


Erik::~Erik()
{
}

HRESULT Erik::init(PlayerName playerName)
{
	//에릭 이미지//
	IMAGEMANAGER->addFrameImage("E_idle1", "image/erikImage/idle1.bmp", 336, 200, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("E_idle2", "image/erikImage/idle2.bmp", 563, 200, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("E_idle3", "image/erikImage/idle3.bmp", 260, 200, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("E_jump", "image/erikImage/jump.bmp", 388, 200, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("E_up", "image/erikImage/up.bmp", 327, 100, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("E_drop", "image/erikImage/drop.bmp", 300, 200, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("E_run", "image/erikImage/run.bmp", 800, 200, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("E_atk", "image/erikImage/atk.bmp", 800, 200, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("E_attcked1", "image/erikImage/attcked1.bmp", 97, 200, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("E_attack_after", "image/erikImage/attack_after.bmp", 1133, 200, 11, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("E_die", "image/erikImage/die.bmp", 637, 200, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("E_die_divide", "image/erikImage/die_divide.bmp", 0, 0, 763, 200, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("E_up_end", "image/erikImage/up_end.bmp", 194, 100, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("E_die_electric", "image/erikImage/die_electric.bmp", 194, 200, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("E_push", "image/erikImage/push.bmp", 388, 200, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("E_die_fall", "image/erikImage/die_fall.bmp", 640, 200, 6, 2, true, RGB(255, 0, 255));


	_playerInfo._playerName = PN_ERIK;
	_playerInfo.count = _playerInfo._CurrentFrameX = _playerInfo._CurrentFrameY = 0;
	_playerInfo.HP = 3;
	_playerInfo.MaxHP = 3;
	_playerInfo.position.x = WINSIZEX / 2 - 100;
	_playerInfo.position.y = WINSIZEY / 2;
	_playerInfo.isDrop = false;
	_playerInfo.speed = 3.0f;
	//_playerInfo.gravity = 5.0f;
	jumpPower = 0;
	isJump = false;
	PlusSpeed = 0;

	_playerInfo._image = IMAGEMANAGER->findImage("E_idle1");
	_playerInfo._rc = RectMakeCenter(_playerInfo.position.x, _playerInfo.position.y,
		_playerInfo._image->getFrameWidth(), _playerInfo._image->getFrameHeight());






	return S_OK;
}

void Erik::update()
{
	_playerInfo.count++;
	if (_playerInfo.count %10 == 0)
	{
		if (_playerInfo._CurrentFrameX > _playerInfo._image->getMaxFrameX()) _playerInfo._CurrentFrameX = 0;

		_playerInfo._image->setFrameX(_playerInfo._CurrentFrameX);			// setFrameX에 봐야하는 프레임 x값을 매개변수로 보내준다. 
		_playerInfo._CurrentFrameX++;										// 다음 이미지를 보기 위해 값을 증가시킨다.
		_playerInfo.count = 0;												// 카운트를 초기화 해준다.
	}

	Player::update();

	_playerInfo.isDrop = true;

	/*if (KEYMANAGER->isStayKeyDown('A'))
	{
		_playerInfo._image->setFrameY(2);
		_playerInfo._image = IMAGEMANAGER->findImage("E_run");
		_playerInfo.position.x -= 3;
	}
	if (KEYMANAGER->isOnceKeyUp('A'))
	{
		_playerInfo._image->setFrameY(2);
		_playerInfo._image = IMAGEMANAGER->findImage("E_idle1");
		_playerInfo.position.x -= 3;
	}

	if (KEYMANAGER->isStayKeyDown('D'))
	{
		_playerInfo._image->setFrameY(0);
		_playerInfo._image = IMAGEMANAGER->findImage("E_run");
		_playerInfo.position.x += 3;
	}
	if (KEYMANAGER->isOnceKeyUp('D'))
	{
		_playerInfo._image->setFrameY(0);
		_playerInfo._image = IMAGEMANAGER->findImage("E_idle2");
		_playerInfo.position.x -= 3;
	}*/
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_playerInfo._image = IMAGEMANAGER->findImage("E_jump");
		jumpPower = 5;
		_playerInfo.gravity = 0.07f;
		isJump = true;	
	}
 	




	if (isJump)
	{
		_playerInfo.position.y -= jumpPower;
		jumpPower -= _playerInfo.gravity;
		if (jumpPower <= 0)
		{
			isJump = false;
		}
	}

	if (_playerInfo.isDrop)
	{
		_playerInfo.position.y -= jumpPower; //위와 동일
		jumpPower -= _playerInfo.gravity; //중력값만큼 파워를 빼줌
		_playerInfo.gravity += 0.0002f; // 중력값을 ++해서 더빨리떨어지게
	}
}




void Erik::render()
{
	_playerInfo._image->frameRender(getMemDC(), _playerInfo.position.x, _playerInfo.position.y);
}

void Erik::state()
{
	switch (_state)
	{
	case E_idle1:
		break;
	case E_idle2:
		break;
	case E_idle3:
		break;
	case E_jump:
		break;
	case E_up:
		break;
	case E_drop:
		break;
	case E_run:
		break;
	case E_atk:
		break;
	case E_attcked1:
		break;
	case E_attack_after:
		break;
	case E_up_end:
		break;
	case E_push:
		break;
	case E_die:
		break;
	case E_die_divide:
		break;
	case E_die_electric:
		break;
	case E_die_falls:
		break;

	}
}


