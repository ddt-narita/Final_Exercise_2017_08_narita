#include "JSONManager.h"



JSONManager::JSONManager()
{
	grid = new GridManager();
	list = new ListManager();
}


JSONManager::~JSONManager()
{
	delete grid;
	delete list;
}

std::string JSONManager::getGrid(int rowN, int colN)
{
	return grid->getGrid(rowN, colN);
}

void JSONManager::setGrid(int rowN, int colN, std::string value)
{
	grid->setGrid(rowN, colN, value);
}

std::vector<std::string> JSONManager::getGridData(int rowN, int colN)
{
	return grid->getGridData(rowN, colN);
}

void JSONManager::setGridData(int rowN, int colN, std::vector<std::string> data)
{
	grid->setGridData(rowN, colN, data);
}

std::vector<std::string> JSONManager::getGridRowData(int rowN)
{
	return grid->getGridRowData(rowN);
}

void JSONManager::setGridRowData(int rowN, std::vector<std::string> data)
{
	grid->setGridRowData(rowN, data);
}

int JSONManager::getGridRowLength()
{
	return grid->getGridRowLength();
}

int JSONManager::getGridColLength()
{
	return grid->getGridColLength();
}

std::string JSONManager::getJSONName()
{
	return "json";
}

std::string JSONManager::getJSONSavePath()
{
	return std::string();
}

std::string JSONManager::getQuery()
{
	return std::string();
}

std::string JSONManager::getJsonFilePath()
{
	return std::string();
}

void JSONManager::jsonClear()
{
	json.clear();
}
