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
	
	//���� �������ִ� �������� 0��
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
	//�÷��̾� �߷°�

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
	
	
	//ĳ���� �浹��Ʈ ����

	_playerInfo._underRc = RectMakeCenter(_playerInfo.position.x - CAMERA->getCameraXpos() + _playerInfo._image->getFrameWidth() / 2, _playerInfo.position.y - CAMERA->getCameraYpos() + _playerInfo._image->getFrameHeight(), _playerInfo._image->getFrameWidth(), 5);
	_playerInfo._leftRc = RectMakeCenter(_playerInfo.position.x - CAMERA->getCameraXpos(),
		_playerInfo.position.y - CAMERA->getCameraYpos() + _playerInfo._image->getFrameHeight()/2,
		5, _playerInfo._image->getFrameWidth());
	_playerInfo._rightRc = RectMakeCenter(_playerInfo.position.x - CAMERA->getCameraXpos() + _playerInfo._image->getFrameWidth(),
		_playerInfo.position.y - CAMERA->getCameraYpos() + _playerInfo._image->getFrameHeight() / 2,
		5, _playerInfo._image->getFrameWidth());

	//_playerInfo.position.x - CAMERA->getCameraXpos(), _playerInfo.position.y - CAMERA->getCameraYpos();


	//�߷°���//
	if (_playerInfo.isDrop)
	{
		_playerInfo.position.y -= _playerInfo.jumpPower;			//���� ����
		_playerInfo.jumpPower -= _playerInfo.gravity;				//�߷°���ŭ �Ŀ��� ����
		_playerInfo.gravity += 0.01f;								// �߷°��� ++�ؼ� ��������������
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
	Rectangle(getMemDC(), _playerInfo._underRc);			//ĳ���� �ٴڷ�Ʈ
	Rectangle(getMemDC(), _playerInfo._leftRc);				//ĳ���� ���� �浹��Ʈ
	Rectangle(getMemDC(), _playerInfo._rightRc);			//ĳ���� ������ �浹��Ʈ
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
