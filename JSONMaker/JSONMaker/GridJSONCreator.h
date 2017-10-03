#pragma once
#ifndef __GRID_JSON_CREATOR
#define __GRID_JSON_CREATOR

#include "JSONManager.h"
#include "ChainData.h"

class GridJSONCreator
{
private:
	std::vector<std::string> keyHierarchy;
	int level;
public:
	JSONManager* jsonmanager;
	GridJSONCreator();
	~GridJSONCreator();


	void job(ChainData* cell);
	
	std::string createAcsessKey(std::vector<std::string> keyarray, int level);
	//配列のJSONを作成する
	void createArrayJson(std::string acsessKey, ChainData* cellToArray, boost::property_tree::ptree& json);
	//オブジェクト配列のJSONを作成する
	void createObjectArrayJson(std::string acsessKey, ChainData* cellToObjectArray, boost::property_tree::ptree& json);
	//実際にJSONを作成する関数
	void CreateJSON(ChainData* cell, boost::property_tree::ptree& json);
};

#endif // !__GRID_JSON_CREATOR