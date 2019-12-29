#pragma once
#include "singletonBase.h"
#include <vector>

class txtData : public singletonBase<txtData>
{
private:
	char* _text;
	vector<string> textLine;
public:
	txtData();
	~txtData();

	HRESULT init();
	void release();

	void txtSave(const char* saveFileName, vector<string> vStr);
	char* vectorArrayCombine(vector<string> vArray);

	vector<string> txtLoad(const char* loadFileName);
	vector<string> charArraySeparation(char charArray[]);
	long GetFileSize(std::string filename);
};

