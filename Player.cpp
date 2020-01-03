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
	_playerInfo.isGround = false;

	return S_OK;
}

void Player::MakeRect()
{
	//�÷��̾� �߷°�

	_playerInfo._topRC = RectMakeCenter(_playerInfo.position.x,
		_playerInfo.position.y - _playerInfo._image->getFrameHeight() / 2 - 7,
		_playerInfo._image->getFrameWidth()
		, RCSIZE);
	if (_playerInfo.isDrop)
	{
		_playerInfo._underRc = RectMakeCenter(_playerInfo.position.x,
			_playerInfo.position.y + _playerInfo._image->getFrameHeight() / 2 + 7,
			_playerInfo._image->getFrameWidth()
			, RCSIZE);
	}
	_playerInfo._leftRc = RectMakeCenter(_playerInfo.position.x-_playerInfo._image->getFrameWidth() / 2 - 7,
		_playerInfo.position.y ,
		RCSIZE,
		_playerInfo._image->getFrameWidth());

	_playerInfo._rightRc = RectMakeCenter(_playerInfo.position.x + _playerInfo._image->getFrameHeight() / 2 + 7,
		_playerInfo.position.y ,
		RCSIZE, 
		_playerInfo._image->getFrameWidth());

	_playerInfo._rc = RectMakeCenter(_playerInfo.position.x,
		_playerInfo.position.y,
		_playerInfo._image->getFrameWidth(),
		_playerInfo._image->getFrameHeight());
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

	//�÷��̾� ��Ʈ
	
	collsion();
	_playerInfo._underRcBottom = _playerInfo._underRc.bottom;

	//�÷��̾� �� ���� �浹
	for (int i = 0; i < _MapManager->getColWall().size(); i++)
	{
		RECT temp2;
		if (IntersectRect(&temp2, &_playerInfo._rc, &_MapManager->getColWall()[i]->getRect()))
		{

			_playerInfo._leftRc.left = _MapManager->getWall()[i]->getRect().right;
			


			if (_Direction == LEFT)
			{
				if ( _MapManager->getColWall()[i]->getRect().right < _playerInfo.position.x) 
				{
					_playerInfo.position.x = 
						_MapManager->getColWall()[i]->getRect().right+_playerInfo._image->getFrameWidth()/2;
				}
				else
				{
					_playerInfo.position.x = 
						_MapManager->getColWall()[i]->getRect().left - _playerInfo._image->getFrameWidth() / 2;
				}
			}
			else if(_Direction == RIGHT)
			{
				if (_MapManager->getColWall()[i]->getRect().right < _playerInfo.position.x)
				{
					_playerInfo.position.x =
						_MapManager->getColWall()[i]->getRect().right + _playerInfo._image->getFrameWidth() / 2;
				}
				else
				{
					_playerInfo.position.x = _MapManager->getColWall()[i]->getRect().left -
						_playerInfo._image->getFrameWidth() / 2;
				}
			}

		}
	}


	//KeyControl();
}

void Player::render()
{
	if(KEYMANAGER->isToggleKey('1'))
	{
		RectangleMake(getMemDC(),
			_playerInfo._topRC.left - CAMERA->getCameraXpos(),
			_playerInfo._topRC.top - CAMERA->getCameraYpos(),
			_playerInfo._image->getFrameWidth(), RCSIZE);			//ĳ���� �ٴڷ�Ʈ
		RectangleMake(getMemDC(), 
			_playerInfo._underRc.left-CAMERA->getCameraXpos(),
			_playerInfo._underRc.top-CAMERA->getCameraYpos(),
			_playerInfo._image->getFrameWidth(), RCSIZE);			//ĳ���� �ٴڷ�Ʈ
		RectangleMake(getMemDC(),
			_playerInfo._leftRc.left - CAMERA->getCameraXpos(),
			_playerInfo._leftRc.top - CAMERA->getCameraYpos(),
			RCSIZE, _playerInfo._image->getFrameHeight());
		RectangleMake(getMemDC(),
			_playerInfo._rightRc.left - CAMERA->getCameraXpos(),
			_playerInfo._rightRc.top - CAMERA->getCameraYpos(),
			RCSIZE, _playerInfo._image->getFrameHeight());
		//Rectangle(getMemDC(), _playerInfo._leftRc);				//ĳ���� ���� �浹��Ʈ
		//Rectangle(getMemDC(), _playerInfo._rightRc);			//ĳ���� ������ �浹��Ʈ
	}
	_playerInfo._image->frameRender(getMemDC(), 
		_playerInfo._rc.left - CAMERA->getCameraXpos(),
		_playerInfo._rc.top - CAMERA->getCameraYpos(),
		_playerInfo._CurrentFrameX, 
		_playerInfo._image->getFrameY());

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
			_playerInfo.position.y = _MapManager->getWall()[i]->getRect().top-_playerInfo._image->getFrameHeight()/2;
			_playerInfo._underRc.bottom = _MapManager->getWall()[i]->getRect().top;
			_playerInfo._underRc.top = _MapManager->getWall()[i]->getRect().top;
			_playerInfo.isDrop = false;
			_playerInfo.isGround = true;

			break;
		}
		else
		{
			_playerInfo.isDrop = true;
			_playerInfo.isGround = false;
		}
	}
}


void Player::move()
{

}