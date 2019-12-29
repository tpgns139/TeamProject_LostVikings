#pragma once
class MapManager
{
private:
	vector<string> _textData;
public:
	MapManager();
	~MapManager();

	HRESULT init();
};

