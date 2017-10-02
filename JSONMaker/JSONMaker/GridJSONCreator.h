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

	void init(int rowN, int colN);

	void job(ChainData* cell);
	
	std::string createAcsessKey(std::vector<std::string> keyarray, int level);
	//é¿ç€Ç…JSONÇçÏê¨Ç∑ÇÈä÷êî
	void CreateJSON(ChainData* cell, boost::property_tree::ptree& json);
};

#endif // !__GRID_JSON_CREATOR