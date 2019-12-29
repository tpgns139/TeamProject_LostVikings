#pragma once
class MapObj
{
private:
	float _x, _y;
	RECT _rc;
	image* _image;
public:
	MapObj();
	~MapObj();

	HRESULT init(float x, float y, string imageName);
};

