#include "stdafx.h"
#include "playGround.h"
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

playGround::playGround()
{
}


playGround::~playGround()
{
}

//초기화는 여기다 해라!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
HRESULT playGround::init()
{
	gameNode::init(true);


	SCENEMANAGER->addScene("GameScene", new GameScene);
	SCENEMANAGER->changeScene("GameScene");
	
	return S_OK;
}

//메모리 해제는 여기다 해라!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void playGround::release()
{
	gameNode::release();
	
}

//연산은 여기다 해라!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void playGround::update()
{
	gameNode::update();
	

	SCENEMANAGER->update();
}

//여기다 그려라!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==================================================


	SCENEMANAGER->render();
	
	


	//_currentScene->render();
	//SCENEMANAGER->render();
	//===================================================
	//딱 말했다
	_backBuffer->render(getHDC(), 0, 0);
}
