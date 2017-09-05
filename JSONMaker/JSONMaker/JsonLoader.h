#pragma once
#ifndef __JSON_LOADER
#define __JSON_LOADER

#include "JSONManager.h"

class JsonLoader :
	public JSONManager
{
private:
	//再帰中に何階層目かを表す変数
	int jsonLevel = 0;
	//階層ごとのキーを入力するためのキー
	std::vector<std::string> hierarchy;

	std::vector<std::string> previousRowData;

	//セットする際にBOOST_EACHでループするため、ループ変数を外に置く
	//セットする際にどの行にセットするか指す変数
	int setGridRowN;
	//セットする際にどの列にセットするかを指す変数
	int setGridColN;

public:
	JsonLoader();
	~JsonLoader();

	void run();
	void init();
	void job();
	//
	std::string getJsonFilePath();
	//
	void loadJson(boost::property_tree::ptree json);
};

#endif // !__JSON_LOADER



