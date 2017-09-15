#pragma once
#ifndef __JSON_LOADER
#define __JSON_LOADER

#include "JSONManager.h"
#include <vector>

class JsonLoader
{
private:

	
	//再帰中に何階層目かを表す変数
	int jsonLevel = 0;

	//セットする際にBOOST_EACHでループするため、ループ変数を外に置く
	//セットする際にどの行にセットするか指す変数
	int setGridRowN = 0;
	//セットする際にどの列にセットするかを指す変数
	int setGridColN = 0;

public:
	JSONManager* jsonmanager;
	//階層ごとのキーを入力するためのキー
	std::vector<std::string> hierarchyKeys;
	std::vector<std::string> cellKeys;
	std::vector<std::string> preCellKeys;

	JsonLoader();
	~JsonLoader();

	void run();
	void init();
	void job(std::string jsonnode);

	//
	void loadJson(boost::property_tree::ptree json);
	void returnRow();
	std::vector<std::string> getNodes();
	bool isSameRow(const std::vector<std::string> &thistime, const std::vector<std::string> &pre);
};

#endif // !__JSON_LOADER



