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
	_playerInfo.isPush = false;
	_playerInfo.isLadderEnd = false;

	return S_OK;
}

void Player::MakeRect()
{
	//플레이어 중력값

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

	_playerInfo._ladderRC = RectMakeCenter(_playerInfo.position.x,
		_playerInfo.position.y + _playerInfo._image->getFrameHeight() / 2 + 7,
		_playerInfo._image->getFrameWidth()
		, RCSIZE);

	_playerInfo._midRC = RectMakeCenter(_playerInfo.position.x,
		_playerInfo.position.y + _playerInfo._image->getFrameHeight() / 4-30,
		_playerInfo._image->getFrameWidth()
		, RCSIZE);




	_playerInfo._rc = RectMakeCenter(_playerInfo.position.x,
		_playerInfo.position.y,
		_playerInfo._image->getFrameWidth(),
		_playerInfo._image->getFrameHeight());
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

	//플레이어 렉트
	
	collsion();
	_playerInfo._underRcBottom = _playerInfo._underRc.bottom;

	//플레이어 옆 벽면 충돌
	for (int i = 0; i < _MapManager->getColWall().size(); i++)
	{
		RECT temp2;
		if (IntersectRect(&temp2, &_playerInfo._rc, &_MapManager->getColWall()[i]->getRect()))
		{
			switch (_playerInfo._playerName)
			{
			case PN_ERIK:
				if ((((Erik*)(this))->getState() == E_run))
				{
					((Erik*)(this))->setState(E_push);
				}
				else if ((((Erik*)(this))->getState() == E_atk))
				{
					((Erik*)(this))->colAction();
				}
				break;
			case PN_BALEOG:
				if (((Baleog*)(this))->getState() == BALEOG_RIGHTMOVE||
					((Baleog*)(this))->getState() == BALEOG_LEFTMOVE)
				{
					((Baleog*)(this))->setState(BALEOG_PUSH);
				}
				break;
			case PN_OLAF:
				if (((Olaf*)(this))->getState() == O_front_run||
					((Olaf*)(this))->getState() == O_top_run)
				{
					((Olaf*)(this))->setState(O_push);
				}
				break;
			}
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
			_playerInfo._image->getFrameWidth(), RCSIZE);			//캐릭터 탑렉트
		RectangleMake(getMemDC(),
			_playerInfo._ladderRC.left - CAMERA->getCameraXpos(),
			_playerInfo._ladderRC.top - CAMERA->getCameraYpos(),
			_playerInfo._image->getFrameWidth(), RCSIZE);			//캐릭터 사다리 렉트
		//RectangleMake(getMemDC(), 
		//	_playerInfo._underRc.left-CAMERA->getCameraXpos(),
		//	_playerInfo._underRc.top-CAMERA->getCameraYpos(),
		//	_playerInfo._image->getFrameWidth(), RCSIZE);			//캐릭터 바닥렉트
		RectangleMake(getMemDC(),
			_playerInfo._leftRc.left - CAMERA->getCameraXpos(),
			_playerInfo._leftRc.top - CAMERA->getCameraYpos(),
			RCSIZE, _playerInfo._image->getFrameHeight());
		RectangleMake(getMemDC(),
			_playerInfo._rightRc.left - CAMERA->getCameraXpos(),
			_playerInfo._rightRc.top - CAMERA->getCameraYpos(),
			RCSIZE, _playerInfo._image->getFrameHeight());

		RectangleMake(getMemDC(),
			_playerInfo._midRC.left - CAMERA->getCameraXpos(),
			_playerInfo._midRC.top - CAMERA->getCameraYpos(),
			_playerInfo._image->getFrameWidth(), RCSIZE);
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
{//땅충돌
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

	
	
	//사다리충돌 미완성
	for (int i = 0;i < _MapManager->getLadder().size();i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &_playerInfo._ladderRC, &_MapManager->getLadder()[i]->getRect()))
		{
			if (KEYMANAGER->isStayKeyDown(VK_UP) || (KEYMANAGER->isStayKeyDown(VK_DOWN)))
			{
				_playerInfo.position.x = _MapManager->getLadder()[i]->getRect().right - _playerInfo._image->getFrameWidth() / 2;


				if (_playerInfo._midRC.bottom < _MapManager->getLadder()[i]->getRect().top)
				{
					_playerInfo.isLadderEnd = true;
				}
				if (_playerInfo._midRC.bottom > _MapManager->getLadder()[i]->getRect().top)
				{
					_playerInfo.isLadderEnd = false;
				}
				else if (_playerInfo._ladderRC.bottom >= _MapManager->getLadder()[i]->getRect().top)
				{
					_playerInfo.isLadderEnd = true;
				}
				else
					_playerInfo.isLadderEnd = false;
			}
			_playerInfo.isLadder = true;
			_playerInfo.isDrop = false;
			_playerInfo.isGround = true;
		}
		else
			_playerInfo.isLadder = false;

	
		

	}
		
		

	

	
}


void Player::move()
{

}

