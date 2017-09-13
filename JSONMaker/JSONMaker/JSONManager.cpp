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

int JSONManager::getGridRowLength()
{
	return grid->getGridRowLength();
}

int JSONManager::getGridColLength()
{
	return grid->getGridColLength();
}

void JSONManager::setGridRowLen(int rown)
{
	grid->setRowLen(rown);
}

void JSONManager::setGridMaxColLen(int coln)
{
	grid->setColMaxLen(coln);
}



std::string JSONManager::getJSONName()
{
	return "json";
}

std::string JSONManager::getJSONSavePath()
{
	return std::string();
}

void JSONManager::setJSONSavePath(std::string path)
{
	
}


std::string JSONManager::getQuery()
{
	return std::string();
}

std::string JSONManager::getJsonFilePath()
{
	return env.getJSONFilePath();
}

void JSONManager::setJsonFilePath(std::string path)
{
	env.setJSONFilePath(path);
}

bool JSONManager::isJSONFilePathSet()
{
	//環境クラスからJSONのパスを取得して、空でないかの真理値を返す
	return (env.getJSONFilePath() != "");
}

//JSONの初期化を行う
void JSONManager::jsonClear()
{
	json.clear();
}

void JSONManager::adjustGridDataSize()
{
	grid->adjustGridSize();
}
