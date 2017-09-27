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

	void job();
	
	//é¿ç€Ç…JSONÇçÏê¨Ç∑ÇÈä÷êî
	boost::property_tree::ptree CreateJSON();
};

#endif // !__GRID_JSON_CREATOR