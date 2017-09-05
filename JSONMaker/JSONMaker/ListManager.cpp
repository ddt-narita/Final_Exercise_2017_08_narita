#include "ListManager.h"



ListManager::ListManager()
{
}


ListManager::~ListManager()
{
}

void ListManager::init(int rowN)
{

}

std::string ListManager::getList(int rowN)
{
	return list[rowN];
}

void ListManager::setList(int rowN, std::string value)
{
	if (list.size() < rowN) {
		list.push_back(value);
	}
	else {
		list[rowN] = value;
	}
}


int ListManager::getRowLength()
{
	return list.size();
}
