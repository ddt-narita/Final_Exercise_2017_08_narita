#pragma once
#ifndef __GRID_JSON_CREATOR
#define __GRID_JSON_CREATOR

#include "JSONManager.h"

class GridJSONCreator: public JSONManager
{
private:
public:
	GridJSONCreator();
	~GridJSONCreator();

	void init(int rowN, int colN);

	//���ۂ�JSON���쐬����֐�
	void job();
};

#endif // !__GRID_JSON_CREATOR