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
	//_playerInfo.gravity = 5.0f;
	_playerInfo.position.x = WINSIZEX / 2;
	

	
	return S_OK;
}

void Player::update()
{
	//공동키 업데이트
	CyKeycontrol();   

}

void Player::render()
{
	
}

void Player::CyKeycontrol()
{

	//_playerInfo.count++;
	//if (_playerInfo.count % 10 == 0)
	//{
	//	if (_playerInfo._CurrentFrameX > _playerInfo._image->getMaxFrameX()) _playerInfo._CurrentFrameX = 0;

	//	_playerInfo._image->setFrameX(_playerInfo._CurrentFrameX);			// setFrameX에 봐야하는 프레임 x값을 매개변수로 보내준다. 
	//	_playerInfo._CurrentFrameX++;										// 다음 이미지를 보기 위해 값을 증가시킨다.
	//	_playerInfo.count = 0;												// 카운트를 초기화 해준다.
	//}

	if (KEYMANAGER->isStayKeyDown('A'))
	{
		_playerInfo.position.x -= 2;
	}
	if (KEYMANAGER->isOnceKeyUp('A'))
	{
		_playerInfo.position.x -= 2;
	}

	if (KEYMANAGER->isStayKeyDown('D'))
	{
		_playerInfo.position.x += 2;
	}
	if (KEYMANAGER->isOnceKeyUp('D'))
	{
		_playerInfo.position.x -= 2;
	}
	_playerInfo._rc = RectMakeCenter(_playerInfo.position.x, _playerInfo.position.y,
		_playerInfo._image->getFrameWidth(), _playerInfo._image->getFrameHeight());
}
