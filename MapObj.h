#pragma once
#include"gameNode.h"
enum mapKinds
{
	wall,
	elevator,
	tower,
	portal,
	thornbush,
	blueTile,
	redTile,
	electricField,
	gravityZone,
	electricFieldTwoType,
	ladder,
	Column,
	colWall
};
struct mapInfo
{
	float _x, _y;
	float width, height;
	mapKinds _mapkinds;
	int currentX;
	RECT _rc;
	image* _image;
	int timeCount;
};
class MapObj
{
protected:
	mapInfo _mapInfo;
public:
	MapObj();
	~MapObj();

	virtual HRESULT init(mapInfo info);
	virtual void update();
	virtual void render();
	mapKinds getMapType() { return _mapInfo._mapkinds; }
	RECT getRect() { return _mapInfo._rc; }
};

