#include "stdafx.h"
#include "txtData.h"


txtData::txtData()
{
	_text = new char;
}


txtData::~txtData()
{
}

HRESULT txtData::init()
{

	return S_OK;
}

void txtData::release()
{
}

void txtData::txtSave(const char * saveFileName, vector<string> vStr)
{
	HANDLE file;
	DWORD write;

	char str[128];

	strncpy_s(str, 128, vectorArrayCombine(vStr), 126);

	file = CreateFile(saveFileName, GENERIC_WRITE, NULL, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, str, 128, &write, NULL);

	CloseHandle(file);
}

//문자열을 조합하기 위한 함수
char* txtData::vectorArrayCombine(vector<string> vArray)
{
	char str[128];
	ZeroMemory(str, sizeof(str));

	for (int i = 0; i < vArray.size(); ++i)
	{
		strncat_s(str, 128, vArray[i].c_str(), 126);
		//만약에 배열사이즈보다 작을때까지 문자를 더해라(?)
		if (i + 1 < vArray.size()) strcat_s(str, ",");
	}

	return str;
}

vector<string> txtData::txtLoad(const char* loadFileName)
{
	HANDLE file;
	DWORD read;
	file = CreateFile(loadFileName, GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _text, GetFileSize(loadFileName), &read, NULL);

	CloseHandle(file);
	return charArraySeparation(_text);
}

vector<string> txtData::charArraySeparation(char charArray[])
{
	vector<string> vArray;

	char* temp;
	const char* separator = "\n";	//구분자
	char* token;

	token = strtok_s(charArray, separator, &temp);
	vArray.push_back(token);

	while (NULL != (token = strtok_s(NULL, separator, &temp)))
	{
		vArray.push_back(token);
	}

	return vArray;
}
long txtData::GetFileSize(std::string filename)
{
	struct stat stat_buf;
	int rc = stat(filename.c_str(), &stat_buf);
	return rc == 0 ? stat_buf.st_size : -1;
}
