#pragma once
#ifndef __LIST_JSON_MANAGER
#define __List_JSON_MANAGER

#include <vector>
#include "ListManager.h"
#include "JSONManager.h"

class ListJSONCreator :public JSONManager
{
private:

public:
	ListJSONCreator();
	~ListJSONCreator();

	void init(int rowN);

	std::string getList(int rowN);
	void setList(int rowN, std::string value);

	int getListLength();

	void job();


};

#endif // !__LIST_JSON_MANAGER