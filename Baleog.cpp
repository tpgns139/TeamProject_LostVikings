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
	
	//밸로그 이미지//
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
	_playerInfo.position.x = WINSIZEX / 2;		//벨로그 x좌표
	_playerInfo.position.y = WINSIZEY / 2-45;		//벨로그 y좌표
	_playerInfo.count = 0;						//벨로그 프레임 카운트0;
	_playerInfo._CurrentFrameX = _playerInfo._CurrentFrameY = 0;		//벨로그 프레임 x,y 초기화
	_playerInfo._playerName = playerName;		//캐릭터 이미지 설정
	_playerInfo._rc = RectMakeCenter(_playerInfo.position.x, _playerInfo.position.y, _playerInfo._image->getFrameWidth(), _playerInfo._image->getFrameHeight());
	_playerInfo.speed = 2.0f;
	_playerInfo.gravity = 0;
	isAttack = false;
	_playerInfo.HP = 3;
	_playerInfo.MaxHP = 3;
	_isshoot = false;
	_isSword = false;
	Player::MakeRect();

	return S_OK;
}
void Baleog::update()
{
	Frame();
	
	Player::update();
	Player::move();
	//setImage();
}

void Baleog::render()
{
	Player::render();	//벨로그 사다리충돌 렉트
}

void Baleog::setImage()
{
	switch (_BaleogState)											//벨로그 스테이트 
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
	if (_Direction == LEFT)
	{
		_playerInfo._CurrentFrameX = _playerInfo._image->getMaxFrameX();
		_playerInfo._image->setFrameY(1);
	}
	else
	{

		_playerInfo._CurrentFrameX = 0;
		_playerInfo._image->setFrameY(0);
	}
}

void Baleog::KeyControl()
{

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		if (_BaleogState == BALEOG_RIGHTIDLE || _BaleogState == BALEOG_RIGHTMOVE)							//벨로그 공격키 
		{
			_Direction = RIGHT;
			_BaleogState = BALEOG_RIGHTATTACK;
			setImage();
			_isSword = true;
		}
		if (_BaleogState == BALEOG_LEFTIDLE || _BaleogState == BALEOG_LEFTMOVE)
		{
			_Direction = LEFT;
			_BaleogState = BALEOG_LEFTATTACK;
			setImage();
			_isSword = true;
		}
		isAttack = true;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_SPACE))					//벨로그 공격키 눌렀다 떼었을때
	{
		if (_BaleogState == BALEOG_RIGHTATTACK)
		{
			if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
			{
				_BaleogState = BALEOG_RIGHTMOVE;
				_isSword = false;
			}
			else
			{
				_BaleogState = BALEOG_RIGHTIDLE;
				_isSword = false;
			}
			setImage();


		}
		if (_BaleogState == BALEOG_LEFTATTACK)
		{

			if (KEYMANAGER->isStayKeyDown(VK_LEFT))
			{
				_BaleogState = BALEOG_LEFTMOVE;
				_isSword = false;
			}
			else
			{
				_BaleogState = BALEOG_LEFTIDLE;
				_isSword = false;
			}
			setImage();
		}
		isAttack = false;
	}

	
	if (KEYMANAGER->isOnceKeyDown('D'))							//벨로그 화살공격
	{

		if (_BaleogState == BALEOG_RIGHTIDLE || _BaleogState == BALEOG_RIGHTMOVE  )
		{
			
			_BaleogState = BALEOG_RIGHTBOWATTACK;
			setImage();
		}
		if (_BaleogState == BALEOG_LEFTIDLE || _BaleogState == BALEOG_LEFTMOVE)
		{
			
			_BaleogState = BALEOG_LEFTBOWATTACK;
			setImage();
			
		}
		isAttack = true;
	}


	if (!isAttack)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			_Direction = LEFT;
			_BaleogState = BALEOG_LEFTMOVE;
			setImage();
		}
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			_Direction = RIGHT;
			_BaleogState = BALEOG_RIGHTMOVE;
			setImage();
		}
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_Direction = LEFT;
			_playerInfo.position.x -= _playerInfo.speed;

		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_Direction = RIGHT;
			_playerInfo.position.x += _playerInfo.speed;
		}
	

	
		if (KEYMANAGER->isOnceKeyUp(VK_LEFT) && _BaleogState != BALEOG_RIGHTMOVE)
		{
			_Direction = LEFT;
			_BaleogState = BALEOG_LEFTIDLE;
			setImage();
		}
		if (KEYMANAGER->isOnceKeyUp(VK_RIGHT)&&_BaleogState!=BALEOG_LEFTMOVE)
		{
			_Direction = RIGHT;
			_BaleogState = BALEOG_RIGHTIDLE;
			setImage();
		}
	}
}

void Baleog::Frame()
{
	_playerInfo.count++;
	if (_playerInfo.count % 10 == 0)
	{
		if (_Direction == RIGHT)
		{
			_playerInfo._CurrentFrameX++;
			if (_BaleogState != BALEOG_LEFTBOWATTACK && _BaleogState != BALEOG_RIGHTBOWATTACK)
			{
				if (_playerInfo._CurrentFrameX > _playerInfo._image->getMaxFrameX()) _playerInfo._CurrentFrameX = 0;
			}
			else
			{
				if (KEYMANAGER->isStayKeyDown('D'))
				{
					if (_playerInfo._CurrentFrameX > 5) 
					{
						_playerInfo._CurrentFrameX = 5;
					}
				}
				else
				{
					if (_playerInfo._CurrentFrameX == 6)
					{
						_isshoot = true;
					}
					
					if (_playerInfo._CurrentFrameX > _playerInfo._image->getMaxFrameX())
					{
						if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
						{
							_BaleogState = BALEOG_RIGHTMOVE;
						}
						else
						{
							_BaleogState = BALEOG_RIGHTIDLE;
						}
						setImage();
					
						isAttack = false;
					}
				}
			}
		}
		else if (_Direction == LEFT)
		{
			_playerInfo._CurrentFrameX--;
			if (_BaleogState != BALEOG_LEFTBOWATTACK && _BaleogState != BALEOG_RIGHTBOWATTACK)
			{
				if (_playerInfo._CurrentFrameX < 0)_playerInfo._CurrentFrameX = _playerInfo._image->getMaxFrameX();
			}
			else
			{
				if (KEYMANAGER->isStayKeyDown('D'))
				{
					if (_playerInfo._CurrentFrameX < 2)
					{
						_playerInfo._CurrentFrameX = 2;
					}
				}
				else
				{
					if (_playerInfo._CurrentFrameX == 1)
					{
						_isshoot = true;
					}
					if (_playerInfo._CurrentFrameX < 0)
					{
						
						if (KEYMANAGER->isStayKeyDown(VK_LEFT))
						{
							_BaleogState = BALEOG_LEFTMOVE;
						}
						else
						{
							_BaleogState = BALEOG_LEFTIDLE;
						}
						setImage();
						isAttack = false;
					}
				}
			}
		}
	}
	else
	{
		_isshoot = false;
	}
}

