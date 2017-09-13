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

	//é¿ç€Ç…JSONÇçÏê¨Ç∑ÇÈä÷êî
	void job();
	bool isRowArray(int row);
	std::vector<std::string> getRowDataVer(int row);
};

#endif // !__GRID_JSON_CREATOR