#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

HRESULT Player::init(PlayerName playerName)
{
	
	return S_OK;
}

void Player::MakeRect()
{
	_playerInfo._underRc = RectMake( _playerInfo.position.x - _playerInfo._image->getFrameWidth() / 2, _playerInfo._image->getFrameHeight() / 2 + _playerInfo.position.y ,80, 10);
}

void Player::update()
{
	_playerInfo._rc = RectMakeCenter(_playerInfo.position.x, _playerInfo.position.y,
		_playerInfo._image->getFrameWidth(), _playerInfo._image->getFrameHeight());

	
	_playerInfo._underRc = RectMake(_playerInfo.position.x - _playerInfo._image->getFrameWidth() / 2, _playerInfo._image->getFrameHeight() / 2 + _playerInfo.position.y, 80, 10);
	KeyControl();
	move();
}

void Player::render()
{
	Rectangle(getMemDC(), _playerInfo._underRc);
}



void Player::KeyControl()
{
}



void Player::move()
{
	if (KEYMANAGER->isStayKeyDown('A'))
	{

		_playerInfo.position.x -= _playerInfo.speed;
		RECT temp;
		//if(IntersectRect(&temp, &_playerInfo._rc, ))
	}
	if (KEYMANAGER->isOnceKeyUp('A'))
	{
	
		_playerInfo.position.x -= _playerInfo.speed;
	}

	if (KEYMANAGER->isStayKeyDown('D'))
	{
	
		_playerInfo.position.x += _playerInfo.speed;
	}
	if (KEYMANAGER->isOnceKeyUp('D'))
	{
		_playerInfo.position.x -= _playerInfo.speed;
	}
}
