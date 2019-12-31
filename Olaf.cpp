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
	//¿Ã¶óÇÁ//
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

	IMAGEMANAGER->addFrameImage("O_front_run", "image/olafImage/front_run.bmp", 583, 200, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("O_jump", "image/olafImage/jump.bmp", 200, 200, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("O_push", "image/olafImage/push.bmp", 413, 200, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("O_top_run", "image/olafImage/top_run.bmp", 848, 200, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("O_up", "image/olafImage/up.bmp", 350, 100, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("O_up_end", "image/olafImage/up_end.bmp", 200, 100, 2, 1, true, RGB(255, 0, 255));

	_playerInfo._playerName = PN_OLAF;
	_playerInfo._image = IMAGEMANAGER->findImage("O_front_idle2");
	_playerInfo.count = _playerInfo._CurrentFrameX = _playerInfo._CurrentFrameY = 0;
	_playerInfo.HP = 3;
	_playerInfo.MaxHP = 3;
	_playerInfo.isDrop = false;
	_playerInfo.speed = 2.0f;
	_playerInfo.position.x = WINSIZEX / 2 + 200;
	_playerInfo.position.y = WINSIZEY / 2;
	_playerInfo._rc = RectMakeCenter(_playerInfo.position.x,
		_playerInfo.position.y,
		_playerInfo._image->getFrameWidth(),
		_playerInfo._image->getFrameHeight());

	





	return S_OK;
}

void Olaf::update()
{
	Frame(20);
	KeyControl();
	Player::update();
}

void Olaf::render()
{
	_playerInfo._image->frameRender(getMemDC(), _playerInfo._rc.left, _playerInfo._rc.top);
}

void Olaf::KeyControl()
{



}

void Olaf::Frame(int FrameX)
{
	_playerInfo.count++;
	if (_playerInfo.count % FrameX == 0)
	{
		if (_Direction == RIGHT)
		{
			_playerInfo._CurrentFrameX++;
			if (_playerInfo._CurrentFrameX >= _playerInfo._image->getMaxFrameX() - 1) _playerInfo._CurrentFrameX = 0;
			_playerInfo.count = 0;
		}
		else if (_Direction == LEFT)
		{
			_playerInfo._CurrentFrameX--;
			if (_playerInfo._CurrentFrameX < 0)_playerInfo._CurrentFrameX = _playerInfo._image->getMaxFrameX();
			_playerInfo.count = 0;
		}
	}
}
