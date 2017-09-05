#pragma once
#ifndef __LIST_MANAGER
#define __LIST_MANAGER

#include <vector>

class ListManager
{
private:
	std::vector<std::string> list;


public:
	ListManager();
	~ListManager();

	void init(int rowN);

	std::string getList(int rowN);
	void setList(int rowN, std::string value);

	int getRowLength();
};


#endif // !__LIST_MANAGER



