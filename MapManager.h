#pragma once
#include"MapObj.h"
#include"Wall.h"
#include"Elevator.h"
#include"ThornBush.h"
#include"Portal.h"
#include"Tower.h"
#include"BlueTile.h"
#include"RedTile.h"
#include"ElectricField.h"
#include"GravityZone.h"
#include"ElectricFieldTwoType.h"
#include"Ladder.h"


class Player;

class MapManager
{
private:
	vector<string> _textData;


	vector<MapObj*> _notColObj;
	vector<MapObj*> _colObj;


	vector<MapObj*> _portal;
	vector<MapObj*> _ladder;
	vector<MapObj*> _wall;
	vector<MapObj*> _elevator;
	vector<MapObj*> _gravityZone;
	
	Player* _player;



public:
	MapManager();
	~MapManager();

	HRESULT init();
	void update();
	void render();
	void charArraySeparationforMap(char charArray[]);

	vector<MapObj*> getWall() { return _wall; }
};

