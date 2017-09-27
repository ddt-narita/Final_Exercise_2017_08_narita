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
	
	//実際にJSONを作成する関数
	boost::property_tree::ptree CreateJSON();
};

#endif // !__GRID_JSON_CREATOR