#pragma once
#ifndef __GRID_JSON_CREATOR
#define __GRID_JSON_CREATOR

#include "JSONManager.h"
#include "ChainData.h"
#include "CLIConstants.h"

class GridJSONCreator
{
private:
	std::vector<std::string> keyHierarchy;
	int level;
public:
	JSONManager* jsonmanager;
	GridJSONCreator();
	~GridJSONCreator();

	//JSON作成を行う関数
	void job(ChainData* cell);
	//アクセスするためのキー文字列を作成する
	std::string createAcsessKey(std::vector<std::string> keyarray, int level, std::string delimiter);
	std::string createErrorMessage(ChainData* cell, std::string errorMessage);
	//兄弟のセルをチェックする
	void checkBroKey(ChainData* cell);
	//配列のJSONを作成する
	void createArrayJson(std::string acsessKey, ChainData* cellToArray, boost::property_tree::ptree& json);
	//オブジェクト配列のJSONを作成する
	void createObjectArrayJson(std::string acsessKey, ChainData* cellToObjectArray, boost::property_tree::ptree& json);
	//実際にJSONを作成する関数
	void CreateJSON(ChainData* cell, boost::property_tree::ptree& json);
};

#endif // !__GRID_JSON_CREATOR