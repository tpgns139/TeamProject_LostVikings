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



	_playerInfo.gravity = 0;
	_playerInfo.isDrop = true;

	return S_OK;
}

void Player::MakeRect()
{
	//플레이어 중력값


	_playerInfo._underRc = RectMakeCenter(_playerInfo.position.x  + _playerInfo._image->getFrameWidth() / 2,
		_playerInfo.position.y  + _playerInfo._image->getFrameHeight() + 7,
		_playerInfo._image->getFrameWidth(), 5);
	_playerInfo._leftRc = RectMakeCenter(_playerInfo.position.x ,
		_playerInfo.position.y  + _playerInfo._image->getFrameHeight() / 2,
		5, _playerInfo._image->getFrameWidth());

	_playerInfo._rightRc = RectMakeCenter(_playerInfo.position.x  + _playerInfo._image->getFrameWidth(),
		_playerInfo.position.y + _playerInfo._image->getFrameHeight() / 2,
		5, _playerInfo._image->getFrameWidth());
}

void Player::update()
{
	//캐릭터 충돌렉트 설정

	MakeRect();


	//중력값용//
	if (_playerInfo.isDrop)
	{
		_playerInfo.position.y -= _playerInfo.jumpPower;			//위와 동일
		_playerInfo.jumpPower -= _playerInfo.gravity;				//중력값만큼 파워를 빼줌
		_playerInfo.gravity += 0.01f;								// 중력값을 ++해서 더빨리떨어지게
	}

	_playerInfo._rc = RectMakeCenter(_playerInfo.position.x, _playerInfo.position.y,
		_playerInfo._image->getFrameWidth(), _playerInfo._image->getFrameHeight());



	collsion();

	for (int i = 0;i < _MapManager->getWall().size();i++)
	{
		RECT temp;
		if(IntersectRect(&temp, &_playerInfo._underRc, &_MapManager->getWall()[i]->getRect()))
		{
			_playerInfo._underRc.bottom = _MapManager->getWall()[i]->getRect().top;
			_playerInfo.isDrop = false;
			break;
		}
		else
		{
			_playerInfo.isDrop = true;
		}
	
	}
	for (int i = 0; i < _MapManager->getWall().size(); i++)
	{
		
		RECT temp2;
		if (IntersectRect(&temp2, &_playerInfo._leftRc, &_MapManager->getWall()[i]->getRect()))
		{
			_playerInfo._leftRc.left = _MapManager->getWall()[i]->getRect().right;
			
		}

	}
	//KeyControl();
}

void Player::render()
{
	if(KEYMANAGER->isToggleKey('1'))
	{
		RectangleMake(getMemDC(), 
			_playerInfo._underRc.left-CAMERA->getCameraXpos(),
			_playerInfo._underRc.top-CAMERA->getCameraYpos(),
			_playerInfo._image->getFrameWidth(),5);			//캐릭터 바닥렉트
		RectangleMake(getMemDC(),
			_playerInfo._leftRc.left - CAMERA->getCameraXpos(),
			_playerInfo._leftRc.top - CAMERA->getCameraYpos(),
			5, _playerInfo._image->getFrameHeight());
		RectangleMake(getMemDC(),
			_playerInfo._rightRc.left - CAMERA->getCameraXpos(),
			_playerInfo._rightRc.top - CAMERA->getCameraYpos(),
			5, _playerInfo._image->getFrameHeight());

		//Rectangle(getMemDC(), _playerInfo._leftRc);				//캐릭터 왼쪽 충돌렉트
		//Rectangle(getMemDC(), _playerInfo._rightRc);			//캐릭터 오른쪽 충돌렉트
	}
}

void Player::KeyControl()
{
}



void Player::collsion()
{
	for (int i = 0;i < _MapManager->getWall().size();i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &_playerInfo._underRc, &_MapManager->getWall()[i]->getRect()))
		{
			_playerInfo._underRc.bottom = _MapManager->getWall()[i]->getRect().top;
			_playerInfo.isDrop = false;

			break;
		}
		else
		{
			_playerInfo.isDrop = true;
		}
	}
}

void Player::move()
{

}