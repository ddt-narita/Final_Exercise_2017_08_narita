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

	//実際にJSONを作成する関数
	void job();
};

#endif // !__GRID_JSON_CREATOR