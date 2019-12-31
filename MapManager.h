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

class MapManager
{
private:
	vector<string> _textData;
	vector<MapObj*> _notColObj;
	vector<MapObj*> _portal;
	vector<MapObj*> _ladder;
	vector<MapObj*> _colObj;
	vector<MapObj*> _elevator;
	vector<MapObj*> _gravityZone;
	vector<MapObj*> _wall;
public:
	MapManager();
	~MapManager();

	HRESULT init();
	void update();
	void render();
	void charArraySeparationforMap(char charArray[]);
};

