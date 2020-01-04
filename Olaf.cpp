#include "stdafx.h"
#include "Olaf.h"


Olaf::Olaf()
{
}


Olaf::~Olaf()
{
}

HRESULT Olaf::init(PlayerName playerName)
{
	//올라프//
	//olafImage
	IMAGEMANAGER->addFrameImage("O_front_idle1", "image/olafImage/front_idle1.bmp", 97, 200, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("O_front_idle2", "image/olafImage/front_idle2.bmp", 375, 200, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("O_front_idle3", "image/olafImage/front_idle3.bmp", 97, 200, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("O_top_idle1", "image/olafImage/top_idle1.bmp", 88, 200, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("O_top_idle2", "image/olafImage/top_idle2.bmp", 272, 200, 3, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("O_attcked1", "image/olafImage/attcked1.bmp", 100, 200, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("O_die", "image/olafImage/die.bmp", 637, 200, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("O_die_divide", "image/olafImage/die_divide.bmp", 194, 200, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("O_die_electric", "image/olafImage/die_electric.bmp", 194, 200, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("O_die_fall", "image/olafImage/die_fall.bmp", 400, 200, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("O_drop", "image/olafImage/drop.bmp", 200, 200, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("O_drop_after", "image/olafImage/drop_after.bmp", 500, 200, 5, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("O_fly1", "image/olafImage/fly1.bmp", 206, 200, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("O_fly2", "image/olafImage/fly2.bmp", 176, 200, 2, 2, true, RGB(255, 0, 255));

	//이거 수정
	IMAGEMANAGER->addFrameImage("O_front_run", "image/olafImage/front_run.bmp", 776, 198,8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("O_jump", "image/olafImage/jump.bmp", 200, 200, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("O_push", "image/olafImage/push.bmp", 413, 200, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("O_top_run", "image/olafImage/top_run.bmp", 848, 200, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("O_front_run", "image/olafImage/front_run.bmp", 776, 198, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("O_top_run", "image/olafImage/top_run.bmp", 848, 200, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("O_jump", "image/olafImage/jump.bmp", 200, 200, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("O_push", "image/olafImage/push.bmp", 413, 200, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("O_up", "image/olafImage/up.bmp", 352, 100, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("O_up_end", "image/olafImage/up_end.bmp", 200, 100, 2, 1, true, RGB(255, 0, 255));

	_playerInfo._playerName = PN_OLAF;
	_playerInfo._image = IMAGEMANAGER->findImage("O_front_idle2");
	_playerInfo.count = _playerInfo._CurrentFrameX = _playerInfo._CurrentFrameY = 0;

	_playerInfo.MaxHP = 3;
	_playerInfo.isDrop = true;
	_playerInfo.speed = 3.0f;
	_playerInfo.position.x = 1300;//WINSIZEX / 2 + 200;
	_playerInfo.position.y = 1116;//WINSIZEY / 2 - 45;

	_playerInfo._rc = RectMakeCenter(_playerInfo.position.x,_playerInfo.position.y,_playerInfo._image->getFrameWidth(),_playerInfo._image->getFrameHeight());

	Erik* _erikO = new Erik;
	Baleog* _baleogO = new Baleog;

	shieldPosision = false;



	Player::MakeRect();


	return S_OK;
}

void Olaf::update()
{
	if (_Ostate != O_up)
	{
		Frame(20);
	}
	//KeyControl();
	Player::update();
	//Player::move();

	if (_Direction == LEFT)
	{
		shieldX = _playerInfo.position.x -_playerInfo._image->getFrameWidth()/2- CAMERA->getCameraXpos();
	}
	if (_Direction == RIGHT)
	{
		shieldX = _playerInfo.position.x - CAMERA->getCameraXpos() + _playerInfo._image->getFrameWidth()/2;
	}
	shiedMake();


	//RECT temp;
	//if (IntersectRect(&temp, &shieldUp,
	
	setImage();
	

}

void Olaf::render()
{//디버깅용
	Player::render();
	
	

	if(shieldPosision)Rectangle(getMemDC(), shieldUp);
	if(!shieldPosision)Rectangle(getMemDC(), shieldFront);
}


void Olaf::KeyControl()
{
	if(_Ostate!=O_up)
	{
	//왼쪽//
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{	
		_Direction = LEFT;
		_playerInfo._image->setFrameY(2);
		
	
		if (!shieldPosision)_Ostate = O_front_run;
		if (shieldPosision)_Ostate = O_top_run;
		_playerInfo.position.x -= _playerInfo.speed;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_Direction = LEFT;
		_playerInfo._image->setFrameY(2);

	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_Direction = LEFT;
		_playerInfo._image->setFrameY(2);

		_playerInfo._CurrentFrameX = 0;
		if (!shieldPosision)_Ostate = O_front_idle1;
		if (shieldPosision)_Ostate = O_top_idle1;
		_playerInfo.position.x -= _playerInfo.speed;
	}

	//오른쪽
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_Direction = RIGHT;
		_playerInfo._image->setFrameY(0);

		if (!shieldPosision)_Ostate = O_front_run;
		if (shieldPosision)_Ostate = O_top_run;
		_playerInfo.position.x += _playerInfo.speed;

	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_Direction = RIGHT;
		_playerInfo._image->setFrameY(0);

	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_Direction = RIGHT;
		_playerInfo._image->setFrameY(0);

		_playerInfo._CurrentFrameX = 0;
		if (!shieldPosision)_Ostate = O_front_idle1;
		if (shieldPosision)_Ostate = O_top_idle1;
		_playerInfo.position.x += _playerInfo.speed;
	}

	if (_Direction == LEFT)
	{
		_playerInfo._image->setFrameY(1);
	}
	else if (_Direction == RIGHT)
	{
		_playerInfo._image->setFrameY(0);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE)&&(_Ostate!=O_up))
	{
		_playerInfo._CurrentFrameX = 0;
		shieldPosision = !shieldPosision;
		if(!shieldPosision)_Ostate = O_front_idle1;
		if(shieldPosision)_Ostate =  O_top_idle1;
	}


	}
	
	if (_playerInfo.isGround)
	{

		if (_Direction == LEFT)
		{
			_playerInfo._image->setFrameY(2);
			if ((_Ostate == O_jump) && (!_playerInfo.isLadder))_Ostate = O_front_idle1;
		}
		else if (_Direction == RIGHT)
		{
			_playerInfo._image->setFrameY(0);
			if ((_Ostate == O_jump) && (!_playerInfo.isLadder))_Ostate = O_front_idle1;
		}


	}
	
}



void Olaf::Frame(int FrameX)
{
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
					

				}

				_playerInfo.count = 0;
			}
			else if (_Direction == LEFT)
			{
				_playerInfo._CurrentFrameX--;
				if (_playerInfo._CurrentFrameX <= 0)
				{
					_playerInfo._CurrentFrameX = _playerInfo._image->getMaxFrameX();
					
				}
				_playerInfo.count = 0;
			}
		}
	}
}

void Olaf::_dis()
{
	if (_Direction == LEFT)
	{
		_playerInfo._image->setFrameY(2);
	}
	if (_Direction == RIGHT)
	{
		_playerInfo._image->setFrameY(0);
	}

}

void Olaf::shiedMake()
{
	if (shieldPosision)
	{
		shieldUp = RectMakeCenter(_playerInfo.position.x - CAMERA->getCameraXpos() ,
			_playerInfo.position.y -_playerInfo._image->getFrameHeight()/2- CAMERA->getCameraYpos(),
			_playerInfo._image->getFrameWidth(),
			SIZE);
	}
	if (!shieldPosision)
	{
		shieldFront = RectMakeCenter(shieldX,
			_playerInfo.position.y - CAMERA->getCameraYpos() ,
			SIZE,
			_playerInfo._image->getFrameWidth());
	}
}

void Olaf::setImage()
{
	switch (_Ostate)
	{
	case O_front_idle1:
		_playerInfo._image = IMAGEMANAGER->findImage("O_front_idle1");
		break;
	case O_front_idle2:
		_playerInfo._image = IMAGEMANAGER->findImage("O_front_idle2");
		break;
	case O_front_idle3:
		_playerInfo._image = IMAGEMANAGER->findImage("O_front_idle3");
		break;
	case O_top_idle1:
		_playerInfo._image = IMAGEMANAGER->findImage("O_top_idle1");
		break;
	case O_top_idle2:
		_playerInfo._image = IMAGEMANAGER->findImage("O_top_idle2");
		break;
	case O_attcked1:
		_playerInfo._image = IMAGEMANAGER->findImage("O_attcked1");
		break;
	case O_die:
		_playerInfo._image = IMAGEMANAGER->findImage("O_die");
		break;
	case O_die_divide:
		_playerInfo._image = IMAGEMANAGER->findImage("O_die_divide");
		break;
	case O_die_electric:
		_playerInfo._image = IMAGEMANAGER->findImage("O_die_electric");
		break;
	case O_die_fall:
		_playerInfo._image = IMAGEMANAGER->findImage("O_die_fall");
		break;
	case O_drop:
		_playerInfo._image = IMAGEMANAGER->findImage("O_drop");
		break;
	case O_drop_after:
		_playerInfo._image = IMAGEMANAGER->findImage("O_drop_after");
		break;
	case O_fly1:
		_playerInfo._image = IMAGEMANAGER->findImage("O_fly1");
		break;
	case O_fly2:
		_playerInfo._image = IMAGEMANAGER->findImage("O_fly2");
		break;
	case O_front_run:
		_playerInfo._image = IMAGEMANAGER->findImage("O_front_run");
		break;
	case O_jump:
		_playerInfo._image = IMAGEMANAGER->findImage("O_jump");
		break;
	case O_push:
		_playerInfo._image = IMAGEMANAGER->findImage("O_push");
		break;
	case O_top_run:
		_playerInfo._image = IMAGEMANAGER->findImage("O_top_run");
		break;
	case O_up:
		_playerInfo._image = IMAGEMANAGER->findImage("O_up");
		break;
	case O_up_end:
		_playerInfo._image = IMAGEMANAGER->findImage("O_up_end");
		break;
	}
}

void Olaf::ladder()
{
	if (_playerInfo.isLadder)
	{	
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			_Direction = LEFT;
			Frame(20);
			_Ostate = O_up;
			_playerInfo.position.y -= 2;

			
		}
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_Direction = RIGHT;
			Frame(20);
			_Ostate = O_up;
			_playerInfo.position.y += 2;
			

			
		}
		/*if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_Direction = LEFT;
			_Ostate = O_jump;
			_playerInfo.position.x -= 5;
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_Direction = RIGHT;
			_Ostate = O_jump;
			_playerInfo.position.x += 5;
		}*/
		
		
	}
}

void Olaf::dropState()
{
	if (shieldPosision)
	{
		_Ostate = O_fly2;
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_Direction = LEFT;
			Frame(20);
			_Ostate = O_fly1;
		}
		else if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_Direction = RIGHT;
			Frame(20);
			_Ostate = O_fly1;
		}
	}
	else if (!shieldPosision)_Ostate = O_jump;
	Frame(20);
}

