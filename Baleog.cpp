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
	_playerInfo._image = IMAGEMANAGER->addFrameImage("B_idle1", "image/baleogImage/idle1.bmp", 0, 0, 325, 200, 4, 2, true, RGB(255, 0, 255));
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

	_playerInfo.position.x = WINSIZEX / 2;		//벨로그 x좌표
	_playerInfo.position.y = WINSIZEY / 2;		//벨로그 y좌표
	_playerInfo.count = 0;						//벨로그 프레임 카운트0;
	_playerInfo._CurrentFrameX = _playerInfo._CurrentFrameY = 0;		//벨로그 프레임 x,y 초기화
	_playerInfo._playerName = playerName;		//캐릭터 이미지 설정
	_playerInfo._rc = RectMakeCenter(_playerInfo.position.x, _playerInfo.position.y, _playerInfo._image->getFrameWidth(), _playerInfo._image->getFrameHeight());		//벨로그 렉트
	return S_OK;

}
void Baleog::update()
{
	_playerInfo._rc = RectMakeCenter(_playerInfo.position.x, _playerInfo.position.y, _playerInfo._image->getFrameWidth(), _playerInfo._image->getFrameHeight());
}

void Baleog::render()
{
	Rectangle(getMemDC(), _playerInfo._rc);
}