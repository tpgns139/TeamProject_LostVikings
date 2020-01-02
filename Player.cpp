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
	//플레이어 중력값

	//_playerInfo.position.y += _playerInfo.gravity;

	_playerInfo._underRc = RectMake( _playerInfo.position.x - _playerInfo._image->getFrameWidth() / 2, _playerInfo._image->getFrameHeight() / 2 + _playerInfo.position.y ,80, 5);
	_playerInfo._leftRc = RectMake(_playerInfo.position.x  - _playerInfo._image->getFrameWidth() / 2, _playerInfo.position.y - _playerInfo._image->getFrameHeight() / 2  , 5,80);
	_playerInfo._rightRc = RectMake(_playerInfo.position.x + _playerInfo._image->getFrameWidth() / 2, _playerInfo.position.y - _playerInfo._image->getFrameHeight() / 2, 5, 80);
}

void Player::update()
{
	_playerInfo._rc = RectMakeCenter(_playerInfo.position.x, _playerInfo.position.y,
		_playerInfo._image->getFrameWidth(), _playerInfo._image->getFrameHeight());
	
	//캐릭터 충돌렉트 설정

	_playerInfo._underRc = RectMake(_playerInfo.position.x - _playerInfo._image->getFrameWidth() / 2, _playerInfo._image->getFrameHeight() / 2 + _playerInfo.position.y, 80, 5);
	_playerInfo._leftRc = RectMake(_playerInfo.position.x - _playerInfo._image->getFrameWidth() / 2, _playerInfo.position.y  - _playerInfo._image->getFrameHeight() / 2 , 5, 80);
	_playerInfo._rightRc = RectMake(_playerInfo.position.x + _playerInfo._image->getFrameWidth() / 2, _playerInfo.position.y - _playerInfo._image->getFrameHeight() / 2, 5, 80);
	KeyControl();
	move();
}

void Player::render()
{
	Rectangle(getMemDC(), _playerInfo._underRc);			//캐릭터 바닥렉트
	Rectangle(getMemDC(), _playerInfo._leftRc);				//캐릭터 왼쪽 충돌렉트
	Rectangle(getMemDC(), _playerInfo._rightRc);			//캐릭터 오른쪽 충돌렉트
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
