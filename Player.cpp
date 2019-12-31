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
	_playerInfo.gravity = 5.0f;
	_playerInfo.position.x = WINSIZEX / 2;
	

	
	return S_OK;
}

void Player::update()
{
	_playerInfo._rc = RectMakeCenter(_playerInfo.position.x, _playerInfo.position.y,
		_playerInfo._image->getFrameWidth(), _playerInfo._image->getFrameHeight());
	KeyControl();
	move();
}

void Player::render()
{
	
}



void Player::KeyControl()
{

}



void Player::move()
{
	if (KEYMANAGER->isStayKeyDown('A'))
	{

		_playerInfo.position.x -= _playerInfo.speed;
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
