#include "GridManager.h"
#include <vector>
#include <string>

using namespace std;


GridManager::GridManager()
{
}


GridManager::~GridManager()
{
}

void GridManager::init(int rowN, int colN)
{
	if (grid.size() < rowN) {
		for (int i = grid.size(); i < rowN; i++) {
			vector<string> temp(colN);
			grid.push_back(temp);

		}
	}
	vector<vector<string>> tempdata(colN);
	for (int i = 0; i < colN; i++) {
		
		vector<string> temp(4);
		tempdata[i] = temp;
	}
	for (int j = 0; j < rowN; j++) {
		gridData.push_back(tempdata);
	}
}

std::string GridManager::getGrid(int rowN, int colN)
{
	return grid[rowN][colN];
}

void GridManager::setGrid(int rowN, int colN, std::string value)
{
	if (grid.size() < rowN) {
		vector<string> tempRowVec(colN);
		grid.push_back(tempRowVec);
	}
	if (grid[rowN].size() < colN) {
		grid[rowN].push_back(value);
	}
	else {
		grid[rowN][colN] = value;
	}
}

std::vector<std::string> GridManager::getGridData(int rowN, int colN)
{
	vector<string>temp = gridData[rowN][colN];
	return temp;
}

void GridManager::setGridData(int rowN, int colN, std::vector<std::string> data)
{
	if (gridData.size() < rowN) {
		vector<vector<string>> tempRowVec(colN);
		gridData.push_back(tempRowVec);
	}
	if (gridData[rowN].size() < colN) {
		gridData[rowN].push_back(data);
	}
	else {
		gridData[rowN][colN] = data;
	}
}

std::vector<std::string> GridManager::getGridRowData(int rowN)
{
	return gridRowData[rowN];
}

void GridManager::setGridRowData(int rowN, std::vector<std::string> data)
{
	gridRowData[rowN] = data;
}

int GridManager::getGridRowLength()
{
	int rowLen = grid.size();
	return rowLen;
}

int GridManager::getGridColLength(int rowN)
{
	int colLen = grid[rowN].size();
	return colLen;
}
