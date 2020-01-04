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
#include"column.h"
#include "EnemyManager.h"
#include"ColWall.h"

class EnemyManager;
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
	vector<MapObj*> _colWall;

	int colCount;


public:
	MapManager();
	~MapManager();

	HRESULT init();
	void update();
	void render();
	void charArraySeparationforMap(char charArray[]);
	void zOrderRender();
	vector<MapObj*> getWall() { return _wall; }
	vector<MapObj*> getLadder() { return _ladder; }
	vector<MapObj*> getColWall() { return _colWall; }
	vector<MapObj*> getgravityZone() { return _gravityZone; }
	vector<MapObj*> getportal() { return _portal; }
};

