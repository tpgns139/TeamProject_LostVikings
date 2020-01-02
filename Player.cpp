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
	//�÷��̾� �߷°�


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
	//ĳ���� �浹��Ʈ ����

	MakeRect();


	//�߷°���//
	if (_playerInfo.isDrop)
	{
		_playerInfo.position.y -= _playerInfo.jumpPower;			//���� ����
		_playerInfo.jumpPower -= _playerInfo.gravity;				//�߷°���ŭ �Ŀ��� ����
		_playerInfo.gravity += 0.01f;								// �߷°��� ++�ؼ� ��������������
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
			_playerInfo._image->getFrameWidth(),5);			//ĳ���� �ٴڷ�Ʈ
		RectangleMake(getMemDC(),
			_playerInfo._leftRc.left - CAMERA->getCameraXpos(),
			_playerInfo._leftRc.top - CAMERA->getCameraYpos(),
			5, _playerInfo._image->getFrameHeight());
		RectangleMake(getMemDC(),
			_playerInfo._rightRc.left - CAMERA->getCameraXpos(),
			_playerInfo._rightRc.top - CAMERA->getCameraYpos(),
			5, _playerInfo._image->getFrameHeight());

		//Rectangle(getMemDC(), _playerInfo._leftRc);				//ĳ���� ���� �浹��Ʈ
		//Rectangle(getMemDC(), _playerInfo._rightRc);			//ĳ���� ������ �浹��Ʈ
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