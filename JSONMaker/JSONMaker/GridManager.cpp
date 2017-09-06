#include "GridManager.h"
#include <vector>
#include <string>

using namespace std;

//コンストラクタ
GridManager::GridManager()
{
}

//デストラクタ
GridManager::~GridManager()
{
}

string coordinateToStr(int rowN, int colN) {
	string retStr = to_string(rowN) + ":" + to_string(colN);
	return retStr;
}


/*
関数名:init
概要:初期化関数
引数:int rowN,colN 行数列数
返却値:なし
作成者:成田修之
作成日:9月4日(月)
*/
void GridManager::init(int rowN, int colN)
{
}

/*
関数名:getGrid
概要:セルの値取得
引数:int rowN,colN
返却値:string value 値
作成者:成田修之
作成日:9月4日(月)
*/
std::string GridManager::getGrid(int rowN, int colN)
{
	return grid[rowN][colN];
}

/*
関数名:setGrid
概要:セルの値をセットする
引数:int rowN,colN string value
返却値:なし
作成者:成田修之
作成日:9月4日(月)
*/
void GridManager::setGrid(int rowN, int colN, std::string value)
{
	if  (grid.size() <= rowN) {
		vector<string> tempRowVec(colN);
		grid.push_back(tempRowVec);
	}
	if (grid[rowN].size() <= colN) {
		grid[rowN].push_back(value);
	}
	else {
		grid[rowN][colN] = value;
	}
}


/*
関数名:getGridData
概要:セルの情報配列を取得
引数:int rowN,colN　行数列数
返却値:vector<string>data　情報配列
作成者:成田修之
作成日:9月4日(月)
*/
std::vector<std::string> GridManager::getGridData(int rowN, int colN)
{
	vector<string>temp = gridData[rowN][colN];
	return temp;
}


/*
関数名:setGridData
概要:セルの情報配列を格納する
引数:int rowN,colN　行数列数 vector<string>data 情報配列
返却値:なし
作成者:成田修之
作成日:9月4日(月)
*/
void GridManager::setGridData(int rowN, int colN, std::vector<std::string> data)
{
	if (gridData.size() <= rowN) {
		vector<vector<string>> tempRowVec(colN);
		gridData.push_back(tempRowVec);
	}
	if (gridData[rowN].size() <= colN) {
		gridData[rowN].push_back(data);
	}
	else {
		gridData[rowN][colN] = data;
	}
}

/*
関数名:getGridRowData
概要:行ごとの情報取得
引数:int rowN 行数
返却値:vector<string>data 情報配列
作成者:成田修之
作成日:9月4日(月)
*/
std::vector<std::string> GridManager::getGridRowData(int rowN)
{
	return gridRowData[rowN];
}

/*
関数名:setGridRowData
概要:行ごとの情報配列を格納する
引数:int rowN, vector<string>data
返却値:なし
作成者:成田修之
作成日:9月4日(月)
*/
void GridManager::setGridRowData(int rowN, std::vector<std::string> data)
{
	if (gridRowData.size() <= rowN) {
		gridRowData.push_back(data);
	}
	else {
		gridRowData[rowN] = data;
	}
}

/*
関数名:getGridRowLength
概要:表の行の長さを取得する
引数:なし
返却値:int len
作成者:成田修之
作成日:9月4日(月)
*/
int GridManager::getGridRowLength()
{
	int rowLen = grid.size() - 1;
	return rowLen;
}

/*
関数名:getGridColLength
概要:列の長さを求める
引数:int rowN　何行目の列か
返却値:int len
作成者:成田修之
作成日:9月4日(月)
*/
int GridManager::getGridColLength(int rowN)
{
	int colLen = grid[rowN].size();
	return colLen;
}
