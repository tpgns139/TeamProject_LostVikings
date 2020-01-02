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
	_playerInfo.speed = 3.0f;
	PlusSpeed = 0;
	_playerInfo.isLadder = false;
	_playerInfo.isDrop = false;
	isJump = false;
	


	_playerInfo.gravity = 0;
	jumpPower = 0;
	PlusSpeed = 0;
	stunCount =headingCount = 0;
	

	_playerInfo._image = IMAGEMANAGER->findImage("E_run");
	_playerInfo._rc = RectMakeCenter(_playerInfo.position.x, _playerInfo.position.y,
		_playerInfo._image->getFrameWidth(), _playerInfo._image->getFrameHeight());

	//test = RectMake(WINSIZEX / 2, WINSIZEY / 2-50, 100, 100);
	//test2 = RectMakeCenter(WINSIZEX / 2-300, WINSIZEY / 2 - 50, 100, 300); //사다리용


	return S_OK;
}

void Erik::update()
{
	//_playerInfo.isDrop = true;
	//test = RectMake(WINSIZEX / 2 + 300, WINSIZEY / 2 - 50, 100, 100);
	//test2 = RectMakeCenter(WINSIZEX / 2 - 300, WINSIZEY / 2 - 50, 100, 300); //사다리용
	

	if((_state != E_up)&&(_state != E_attack_after))
	{
		Frame(20);
	}

	
	
	if(_state != E_attack_after)
	{
		KeyControl();
	Player::update();
	}

	if (_state == E_attack_after)
	{
		_playerInfo.count++;
		if (_playerInfo.count % 20 == 0)
		{

			_playerInfo._CurrentFrameX++;
			if (_playerInfo._CurrentFrameX > _playerInfo._image->getMaxFrameX() - 1)
			{
				_playerInfo._CurrentFrameX = 0;
				_state = E_idle2;
			}
		}
	}

	

}

void Erik::render()
{
	if (KEYMANAGER->isToggleKey('1'))
	{
	RectangleMake(getMemDC(), _playerInfo._rc.left, _playerInfo._rc.top, _playerInfo._image->getFrameWidth(), _playerInfo._image->getFrameHeight());
	}
	//Rectangle(getMemDC(), test);
	//Rectangle(getMemDC(), test2);
	char str[128];
	sprintf_s(str, "%d", headingCount);
	TextOut(getMemDC(), WINSIZEX / 2, 100, str, strlen(str));

	_playerInfo._image->frameRender(getMemDC(), _playerInfo._rc.left, _playerInfo._rc.top, _playerInfo._CurrentFrameX, _playerInfo._image->getFrameY());
	Player::render();
}

void Erik::KeyControl()
{
	//왼쪽
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		headingCount++;

		_Direction = LEFT;
		_playerInfo._image->setFrameY(2);

		if (_state != E_atk) _state = E_run;

		if (KEYMANAGER->isOnceKeyDown('F'))
		{
			//if (headingCount >= 50)
			//{
			_state = E_atk;
			//}
		}
	}
		if (KEYMANAGER->isOnceKeyUp('A'))
		{
			_Direction = LEFT;
			headingCount = 0;
			_state = E_idle1;
			_playerInfo._CurrentFrameX = 0;
		}
	//오른쪽
	if ((_state != E_up) && (KEYMANAGER->isStayKeyDown('D')))
	{
		_Direction = RIGHT;
		headingCount++;

		if (KEYMANAGER->isOnceKeyDown('F'))
		{
			//if (headingCount >= 50)
			//{
			_state = E_atk;
			//}

		}
		_playerInfo._image->setFrameY(0);

		if (_state != E_atk) _state = E_run;
		RECT temp;
		if ((_state != E_atk) && (IntersectRect(&temp, &_playerInfo._rc, &test)))
		{
			headingCount = 0;
			_state = E_push;
			_playerInfo.position.x -= _playerInfo.speed;
		}
		 if ((_state == E_atk) && (IntersectRect(&temp, &_playerInfo._rc, &test)))
		{
			headingCount = 0;

			_state = E_attack_after;
			_playerInfo._rc.left -= 100;
			_playerInfo._rc.right -= 100;

			_playerInfo.position.x -= 100;
		}
	}


		if (KEYMANAGER->isOnceKeyUp('D')) //떼면
		{
			_Direction = RIGHT;
			headingCount = 0;
			PlusSpeed = 0;
			_playerInfo._image->setFrameY(0);
			_state = E_idle1;
			_playerInfo._CurrentFrameX = 0;
			_playerInfo.position.x += PlusSpeed;
		}

		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			_state = E_jump;
			isJump = true;
			jumpPower = 3;
			_playerInfo.gravity = 0.05f;
		}
		//사다리 충돌
		RECT temp;
		if (IntersectRect(&temp, &_playerInfo._rc, &test2))
		{
			headingCount = 0;
			if (KEYMANAGER->isStayKeyDown('W'))
			{
				_state = E_up;
				Frame(30);
				_playerInfo.position.y -= 1;
			}
			if (KEYMANAGER->isStayKeyDown('S'))
			{
				_state = E_up;
				Frame(30);
				_playerInfo.position.y += 1;
			}
			if (KEYMANAGER->isStayKeyDown('D'))
			{
				_Direction = RIGHT;
				_state = E_drop;
				_playerInfo.position.x += 2;
			}
		}

		//상태정의 스위치문//
	switch (_state)
	{
	case E_idle1:
		_playerInfo._image = IMAGEMANAGER->findImage("E_idle1");
		
		break;
	case E_idle2:
		_playerInfo._image = IMAGEMANAGER->findImage("E_idle2");
	
		break;
	case E_idle3:
		_playerInfo._image = IMAGEMANAGER->findImage("E_idle3");
	
		break;
	case E_jump:
		_playerInfo._image = IMAGEMANAGER->findImage("E_jump"); //ㅇㅋ
	
		break;
	case E_up:
		_playerInfo._image = IMAGEMANAGER->findImage("E_up"); //ㅇㅋ;
		break;
	case E_drop:
		_playerInfo._image = IMAGEMANAGER->findImage("E_drop");
		break;
	case E_run:
		_playerInfo._image = IMAGEMANAGER->findImage("E_run"); //ㅇㅋ
		break;
	case E_atk:
		_playerInfo._image = IMAGEMANAGER->findImage("E_atk"); //ㅇㅋ
		
		break;
	case E_attcked1:
		_playerInfo._image = IMAGEMANAGER->findImage("E_attcked1");
		break;
	case E_attack_after:
		_playerInfo._image = IMAGEMANAGER->findImage("E_attack_after");//ㅇㅋ
		break;
	case E_up_end:
		_playerInfo._image = IMAGEMANAGER->findImage("E_up_end");
		break;
	case E_push:
		_playerInfo._image = IMAGEMANAGER->findImage("E_push"); //ㅇㅋ
		break;
	case E_die:
		_playerInfo._image = IMAGEMANAGER->findImage("E_die");
		break;
	case E_die_divide:
		_playerInfo._image = IMAGEMANAGER->findImage("E_die_divide");
		break;
	case E_die_electric:
		_playerInfo._image = IMAGEMANAGER->findImage("E_die_electric");
		break;
	case E_die_falls:
		_playerInfo._image = IMAGEMANAGER->findImage("E_die_falls");
		break;
	}
	//점프용//
	if (isJump)
	{
		_playerInfo.position.y -= jumpPower;
		jumpPower -= _playerInfo.gravity;
		if (jumpPower <= 0)
		{
			isJump = false;
			_state = E_idle2;
		}
	}
	//중력값용//
	if (_playerInfo.isDrop)
	{
		_playerInfo.position.y -= jumpPower; //위와 동일
		jumpPower -= _playerInfo.gravity; //중력값만큼 파워를 빼줌
		_playerInfo.gravity += 0.0002f; // 중력값을 ++해서 더빨리떨어지게
	}
}

void Erik::Frame(int FrameX)
{
	_playerInfo.count++;
	if (_playerInfo.count % FrameX == 0)
	{
		if (_Direction == RIGHT)
		{
			_playerInfo._CurrentFrameX++;
			if (_playerInfo._CurrentFrameX > _playerInfo._image->getMaxFrameX() - 1) _playerInfo._CurrentFrameX = 0;
		}
		else if (_Direction == LEFT)
		{
			_playerInfo._CurrentFrameX--;
			if (_playerInfo._CurrentFrameX < 0)_playerInfo._CurrentFrameX = _playerInfo._image->getMaxFrameX();
		}
	}
	//_count++;

	//if (_count % 5 == 0)
	//{
	//	if (_currentFrameX >= _img->getMaxFrameX()) _currentFrameX = 0;

	//	_img->setFrameX(_currentFrameX);			// setFrameX에 봐야하는 프레임 x값을 매개변수로 보내준다. 
	//	_currentFrameX++;								// 다음 이미지를 보기 위해 값을 증가시킨다.
	//	_count = 0;										// 카운트를 초기화 해준다.
	//}
}


