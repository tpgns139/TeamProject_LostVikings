#include "stdafx.h"
#include "MapManager.h"


MapManager::MapManager()
{
}


MapManager::~MapManager()
{
}

HRESULT MapManager::init()
{
	IMAGEMANAGER->addFrameImage("BlueTile", "BlueTile.bmp", 0, 0, 212, 53, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("RedTile", "RedTile.bmp", 0, 0, 212, 53, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ElectricField", "ElectricField.bmp", 0, 0, 600, 27, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("GravityZone", "GravityZone.bmp", 0, 0, 400, 350, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ThornBush", "ThornBush.bmp", 0, 0, 600, 97, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ElectricFieldTwoType", "ElectricFieldTwoType.bmp", 0, 0, 12300, 50, 6, 1, true, RGB(255, 0, 255));


	_textData =TXTDATA->txtLoad("MapInfo.txt");
	for (int i = 0;i < _textData.size();i++)
	{
		const int size = _textData[i].size();
		char* ins= (char *)_textData[i].c_str();
		charArraySeparationforMap(ins);
	}
	return S_OK;
}
void MapManager::update()
{
	for (int i = 0;i < _notColObj.size();i++)
	{
		_notColObj[i]->update();
	}
	for (int i = 0;i < _colObj.size();i++)
	{
		_colObj[i]->update();
	}
	
	for (int i = 0;i < _gravityZone.size();i++)
	{
		_gravityZone[i]->update();
	}
	for (int i = 0;i < _elevator.size();i++)
	{
		_elevator[i]->update();
	}
}
void MapManager::render()
{
	for (int i = 0;i < _notColObj.size();i++)
	{
		_notColObj[i]->render();
	}
	for (int i = 0;i < _colObj.size();i++)
	{
		_colObj[i]->render();
	}
	for (int i = 0;i < _gravityZone.size();i++)
	{
		_gravityZone[i]->render();
	}
	for (int i = 0;i < _elevator.size();i++)
	{
		_elevator[i]->render();
	}
}
void MapManager::charArraySeparationforMap(char charArray[])
{
	int dataNum = 0;
	char* temp;
	const char* separator = ",";	//±¸ºÐÀÚ
	char* token;
	mapInfo ins;
	MapObj* mapIns;
	token = strtok_s(charArray, separator, &temp);
	ins._x = atoi(token);

	while (NULL != (token = strtok_s(NULL, separator, &temp)))
	{
		switch (dataNum)
		{
		case 0:
			ins._y = atoi(token);
			break;

		case 1:
			ins.width = atof(token);
			break;

		case 2:
			ins.height = atof(token);
			break;

		case 3:
			ins._mapkinds = (mapKinds)atoi(token);
			break;
		}
		dataNum++;

	}
	ins._rc = RectMake(ins._x, ins._y, ins.width, ins.height);
	switch (ins._mapkinds)
	{
	case wall:
		mapIns = new Wall;
		mapIns->init(ins);
		_wall.push_back(mapIns);
		break;
	case elevator:
		mapIns = new Elevator;
		mapIns->init(ins);
		_elevator.push_back(mapIns);
		break;
	case portal:
		mapIns = new Portal;
		mapIns->init(ins);
		_portal.push_back(mapIns);
		break;
	case thornbush:
		mapIns = new ThornBush;
		mapIns->init(ins);
		_colObj.push_back(mapIns);
		break;
	case blueTile:
		mapIns = new BlueTile;
		mapIns->init(ins);
		_notColObj.push_back(mapIns);
		break;
	case redTile:
		mapIns = new RedTile;
		mapIns->init(ins);
		_notColObj.push_back(mapIns);
		break;
	case electricField:
		mapIns = new ElectricField;
		mapIns->init(ins);
		_colObj.push_back(mapIns);
		break;
	case gravityZone:
		mapIns = new GravityZone;
		mapIns->init(ins);
		_gravityZone.push_back(mapIns);
		break;
	case electricFieldTwoType:
		mapIns = new ElectricFieldTwoType;
		mapIns->init(ins);
		_colObj.push_back(mapIns);
		break;
	}

}