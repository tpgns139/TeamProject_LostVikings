#pragma once
#include "gameNode.h"
#include"GameScene.h"
#include"IntroScene.h"
class playGround : public gameNode
{
private:
	//gameNode* _star;
	//gameNode* _select;
	//gameNode* _currentScene;

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ ���� �Լ�
	virtual void release();			//�޸� ���� �Լ�
	virtual void update();			//���� ���� �Լ�
	virtual void render();	//�׸��� ���� �Լ�

};

