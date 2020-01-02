#include "stdafx.h"
#include "Player.h"
#include "MapManager.h"


Player::Player()
{
}


Player::~Player()
{
}

HRESULT Player::init(PlayerName playerName)
{
	
	//현재 가지고있는 아이템은 0개
	_itemKind.Fruit = 0;
	_itemKind.Key = 0;
	_itemKind.Meat = 0;
	_itemKind.Shoes = 0;

	_playerInfo.gravity = 0;
	_playerInfo.isDrop = true;

	

	return S_OK;
}

void Player::MakeRect()
{
	//플레이어 중력값

	//_playerInfo.position.y += _playerInfo.gravity;

	/*_playerInfo._underRc = RectMake(_playerInfo.position.x - CAMERA->getCameraXpos() - _playerInfo._image->getFrameWidth() / 2, _playerInfo._image->getFrameHeight() / 2 + _playerInfo.position.y - CAMERA->getCameraYpos(), 80, 5);
	_playerInfo._leftRc = RectMake(_playerInfo.position.x - CAMERA->getCameraXpos() - _playerInfo._image->getFrameWidth() / 2, _playerInfo.position.y - CAMERA->getCameraYpos() - _playerInfo._image->getFrameHeight() / 2, 5, 80);
	_playerInfo._rightRc = RectMake(_playerInfo.position.x - CAMERA->getCameraXpos() + _playerInfo._image->getFrameWidth() / 2, _playerInfo.position.y - CAMERA->getCameraYpos() - _playerInfo._image->getFrameHeight() / 2, 5, 80);
*/

	_playerInfo._underRc = RectMakeCenter(_playerInfo.position.x - CAMERA->getCameraXpos() + _playerInfo._image->getFrameWidth() / 2, _playerInfo.position.y - CAMERA->getCameraYpos() + _playerInfo._image->getFrameHeight(), _playerInfo._image->getFrameWidth(), 5);
	_playerInfo._leftRc = RectMakeCenter(_playerInfo.position.x - CAMERA->getCameraXpos(),
		_playerInfo.position.y - CAMERA->getCameraYpos() + _playerInfo._image->getFrameHeight() / 2,
		5, _playerInfo._image->getFrameWidth());
	_playerInfo._rightRc = RectMakeCenter(_playerInfo.position.x - CAMERA->getCameraXpos() + _playerInfo._image->getFrameWidth(),
		_playerInfo.position.y - CAMERA->getCameraYpos() + _playerInfo._image->getFrameHeight() / 2,
		5, _playerInfo._image->getFrameWidth());
}

void Player::update()
{
	
	
	//캐릭터 충돌렉트 설정

	_playerInfo._underRc = RectMakeCenter(_playerInfo.position.x - CAMERA->getCameraXpos() + _playerInfo._image->getFrameWidth() / 2, _playerInfo.position.y - CAMERA->getCameraYpos() + _playerInfo._image->getFrameHeight(), _playerInfo._image->getFrameWidth(), 5);
	_playerInfo._leftRc = RectMakeCenter(_playerInfo.position.x - CAMERA->getCameraXpos(),
		_playerInfo.position.y - CAMERA->getCameraYpos() + _playerInfo._image->getFrameHeight()/2,
		5, _playerInfo._image->getFrameWidth());
	_playerInfo._rightRc = RectMakeCenter(_playerInfo.position.x - CAMERA->getCameraXpos() + _playerInfo._image->getFrameWidth(),
		_playerInfo.position.y - CAMERA->getCameraYpos() + _playerInfo._image->getFrameHeight() / 2,
		5, _playerInfo._image->getFrameWidth());

	//_playerInfo.position.x - CAMERA->getCameraXpos(), _playerInfo.position.y - CAMERA->getCameraYpos();


	//중력값용//
	if (_playerInfo.isDrop)
	{
		_playerInfo.position.y -= _playerInfo.jumpPower;			//위와 동일
		_playerInfo.jumpPower -= _playerInfo.gravity;				//중력값만큼 파워를 빼줌
		_playerInfo.gravity += 0.01f;								// 중력값을 ++해서 더빨리떨어지게
	}



	for (int i = 0;i < _MapManager->getWall().size();i++)
	{
		RECT temp;
		if(IntersectRect(&temp, &_playerInfo._rc, &_MapManager->getWall()[i]->getRect()))
		{
		_playerInfo._rc.bottom = _MapManager->getWall()[i]->getRect().top;
			_playerInfo.isDrop = false;
			break;
		}
		else
		{
			_playerInfo.isDrop = true;
		}
	}
	_playerInfo._rc = RectMakeCenter(_playerInfo.position.x - CAMERA->getCameraXpos(), _playerInfo.position.y - CAMERA->getCameraYpos(), _playerInfo._image->getFrameWidth(), _playerInfo._image->getFrameHeight());



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
