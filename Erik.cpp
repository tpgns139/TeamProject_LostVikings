#include "stdafx.h"
#include "Erik.h"
#include "MapManager.h" //이거



HRESULT Erik::init(PlayerName playerNme)
{
	Player::init(playerNme);
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
	IMAGEMANAGER->addFrameImage("E_push", "image/erikImage/push2.bmp", 400, 200, 4, 2, true, RGB(255, 0, 255));
	

	IMAGEMANAGER->addFrameImage("E_die_fall", "image/erikImage/die_fall.bmp", 640, 200, 6, 2, true, RGB(255, 0, 255));

	_playerInfo._playerName = PN_ERIK;

	_playerInfo.count = _playerInfo._CurrentFrameX = _playerInfo._CurrentFrameY = 0;

	_playerInfo.MaxHP = 3;
	_playerInfo.position.x = 1300;
	_playerInfo.position.y = 1116;
	_playerInfo.speed = 0.0f;

	PlusSpeed = 0;
	PlusJump = 0;
	jumpCount = 0;
	SuperJumpCount = 0;

	_playerInfo.isLadder = false;
	isJump = false;

	stunCount =headingCount = 0;

	_playerInfo._image = IMAGEMANAGER->findImage("E_idle2");

	_playerInfo._rc = RectMakeCenter(
		_playerInfo.position.x,
		_playerInfo.position.y,
		_playerInfo._image->getFrameWidth(),
		_playerInfo._image->getFrameHeight());

	
	

	Player::MakeRect();


	return S_OK;
}

void Erik::update()
{

	if((_state != E_up)&&(_state != E_attack_after)&&(_state != E_jump))
	{
		Frame(10);
	}


	
	if (_state == E_attack_after)
	{
		_playerInfo.count++;
		if (_playerInfo.count % 10 == 0)
		{
			if (_Direction == LEFT)
			{
				_playerInfo.position.x += 3.0f;
				_playerInfo._CurrentFrameX--;

				if (_playerInfo._CurrentFrameX < 0)
				{
					_state = E_idle1;
					_playerInfo._CurrentFrameX = IMAGEMANAGER->findImage("E_idle1")->getMaxFrameX();
				}
			}
			else
			{
				_playerInfo.position.x -= 3.0f;
				_playerInfo._CurrentFrameX++;

				if (_playerInfo._CurrentFrameX > _playerInfo._image->getMaxFrameX())
				{
					_playerInfo._CurrentFrameX = 0;
					_state = E_idle1;
				}
			}
		}
	}

	Player::update();
	stateImage();
}

void Erik::render()
{

	Player::render();
}

void Erik::KeyControl()
{

	if (_state != E_attack_after&&_state!=E_up)
	{
		if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
		{
			_Direction = LEFT;
		
			_playerInfo._image->setFrameY(2);
			headingCount = 0;
			if (_state == E_push)
			{
				setSpeed(0.0f);
			}
			if (_state != E_jump)_state = E_idle1;
			
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			PlusSpeed = 0;
			_Direction = LEFT;
			_playerInfo._image->setFrameY(2);
			_playerInfo._CurrentFrameX = _playerInfo._image->getMaxFrameX();

		}
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			PlusSpeed = 0;
			_Direction = RIGHT;
			_playerInfo._image->setFrameY(0);
		}
		if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
		{
			_Direction = RIGHT;
			_playerInfo._CurrentFrameX = 0;
			_playerInfo._image->setFrameY(0);
			headingCount = 0;
			if (_state == E_push)
			{
				setSpeed(0.0f);
			}
			if (_state != E_jump)_state = E_idle1;
			
		}
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_Direction = LEFT;
			_playerInfo._image->setFrameY(2);
			if (PlusSpeed > -3)PlusSpeed -= 0.2f;
			headingCount++;
			

			if (_playerInfo.isPush)
			{
				_state = E_push;
			}

			if ((_state != E_atk) && (_state != E_jump) && (_state != E_push)) _state = E_run;

			_playerInfo.position.x += PlusSpeed;
			if ((_state != E_jump) && (headingCount > 100) && (KEYMANAGER->isOnceKeyDown('F')))
			{
				_state = E_atk;
				_playerInfo._CurrentFrameX = IMAGEMANAGER->findImage("E_atk")->getMaxFrameX();
			}
		}
		if(KEYMANAGER->isStayKeyDown(VK_RIGHT) && !KEYMANAGER->isStayKeyDown(VK_LEFT))
		{

			if (PlusSpeed < 3)PlusSpeed += 0.2f;

			_Direction = RIGHT;
			_playerInfo._image->setFrameY(0);
			headingCount++;
			_playerInfo.position.x += PlusSpeed;
			if ((_state != E_atk) && (_state != E_jump)) _state = E_run;
			if ((headingCount > 100) && (KEYMANAGER->isOnceKeyDown('F'))) //박치기하려면 움직임 카운트가 100이상
			{
				_state = E_atk;
				_playerInfo._CurrentFrameX = 0;

			}
		}


		
		//점프
		if (jumpCount == 0)
		{
			jumpCount = 1;
			if (KEYMANAGER->isStayKeyDown(VK_SPACE))
			{
				headingCount = 0;
				_playerInfo._CurrentFrameX = 0;
				_state = E_jump;
				isJump = true;
				if (_playerInfo.isLadder)
				{
					_playerInfo.jumpPower = 2.0f;
				}
				else
				{
					PlusJump++;
					_playerInfo.jumpPower = 3.0f + PlusJump;
				}
					_playerInfo.gravity = 0.02f;
			}
		}
		//점프용//
		if (isJump)
		{
			_playerInfo.position.y -= _playerInfo.jumpPower;
			_playerInfo.jumpPower -= _playerInfo.gravity;
			if (_playerInfo.jumpPower <= 0)
			{
				isJump = false;
			}
		}
	}

	//예외처리
	if (_playerInfo.isGround)
	{
		jumpCount = 0;
		PlusJump = 0;

		if (_Direction == LEFT)
		{
			_playerInfo._image->setFrameY(2);
		}
		else if (_Direction == RIGHT)
		{
			_playerInfo._image->setFrameY(0);
		}

		if ((_state == E_jump)&&(!_playerInfo.isLadder))_state = E_idle1;
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
				if (_playerInfo._CurrentFrameX > _playerInfo._image->getMaxFrameX())
				{
					_playerInfo._CurrentFrameX = 0;
					if (_state == E_atk)
					{
						_state = E_run;
						headingCount = 0;
					}

				}

				_playerInfo.count = 0;
			}
			else if (_Direction == LEFT)
			{
				_playerInfo._CurrentFrameX--;
				if (_playerInfo._CurrentFrameX <= 0)
				{
					_playerInfo._CurrentFrameX = _playerInfo._image->getMaxFrameX();
					if (_state == E_atk)
					{
						_state = E_run;
						headingCount = 0;
					}
				}
				_playerInfo.count = 0;
			}
		}
	}




void Erik::stateImage()
{
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
		_playerInfo._image = IMAGEMANAGER->findImage("E_jump");			
		break;
	case E_up:
		_playerInfo._image = IMAGEMANAGER->findImage("E_up");			
		break;
	case E_drop:
		_playerInfo._image = IMAGEMANAGER->findImage("E_drop");
		break;
	case E_run:
		_playerInfo._image = IMAGEMANAGER->findImage("E_run");			
		break;
	case E_atk:
		_playerInfo._image = IMAGEMANAGER->findImage("E_atk");			
		break;
	case E_attcked1:
		_playerInfo._image = IMAGEMANAGER->findImage("E_attcked1");
		break;
	case E_attack_after:
		_playerInfo._image = IMAGEMANAGER->findImage("E_attack_after");	
		break;
	case E_up_end:
		_playerInfo._image = IMAGEMANAGER->findImage("E_up_end");
		break;
	case E_push:
		_playerInfo._image = IMAGEMANAGER->findImage("E_push");			
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
}

void Erik::colAction()
{
	setState(E_attack_after);
	if (_Direction == LEFT)
	{
		setFrameX(IMAGEMANAGER->findImage("E_attack_after")->getMaxFrameX());
		IMAGEMANAGER->findImage("E_attack_after")->setFrameY(1);
	}
	else
	{
		setFrameX(0);
		IMAGEMANAGER->findImage("E_attack_after")->setFrameY(0);
	}
	setSpeed(0.0f);
}

void Erik::ladder()
{
	if (_playerInfo.isLadder)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			_playerInfo._CurrentFrameX = _playerInfo._image->getMaxFrameX();
		}
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			_playerInfo.count = 0;

		}
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			_Direction = LEFT;			
			Frame(20);
			_state = E_up;
			_playerInfo.position.y -= 2;

			if (KEYMANAGER->isStayKeyDown(VK_LEFT))
			{
				
				_Direction = LEFT;
				_state = E_jump;
				_playerInfo.position.x -= 5;
			}
			if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
			{
				_Direction = RIGHT;
				_state = E_jump;
				_playerInfo.position.x += 5;
			}
		}
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_Direction = RIGHT;
			Frame(20);
			_state = E_up;
			_playerInfo.position.y += 2;

			if (KEYMANAGER->isStayKeyDown(VK_LEFT))
			{
				_Direction = LEFT;
				_state = E_jump;
				_playerInfo.position.x -= 5;
			}
			if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
			{
				_Direction = RIGHT;
				_state = E_jump;
				_playerInfo.position.x += 5;
			}
		}

		
	}
}




