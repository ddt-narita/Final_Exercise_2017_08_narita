#pragma once
#ifndef __GRID_JSON_CREATOR
#define __GRID_JSON_CREATOR

#include "JSONManager.h"

class GridJSONCreator
{
private:
	
public:
	JSONManager* jsonmanager;
	GridJSONCreator();
	~GridJSONCreator();

	void init(int rowN, int colN);

	std::string createAcsessKey(std::vector<std::string> eachCellKeys, int isArray);
	//é¿ç€Ç…JSONÇçÏê¨Ç∑ÇÈä÷êî
	void CreateJSON();
};

#endif // !__GRID_JSON_CREATOR