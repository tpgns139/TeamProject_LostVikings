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
	_textData =TXTDATA->txtLoad("MapInfo.txt");
	for (int i = 0;i < _textData[i].size();i++)
	{
		cout << _textData[i] << endl;
	}
	return S_OK;
}
