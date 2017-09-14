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

/*
関数名:coordinateToStr
概要:引数の座標値をマップのキーにアクセスするための文字列に変換する
引数:int rowN, colN　座標値
返却値:	string str 返還後の文字列
作成者:成田修之
作成日:9月6日
*/
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
	//セルごとのキーデータを格納させるのに使う一時オブジェクト
	vector<string> data(1);
	//全行列の要素分
	for (int i = 0; i < rowN; i++) {
		for (int j = 0; j < colN; j++) {
			//空文字で初期化
			grid[coordinateToStr(i, j)] = "";
			//一時オブジェクトのコピーで初期化
			gridData[coordinateToStr(i, j)] = data;
		}
	}
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
	return grid[coordinateToStr(rowN, colN)];
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
	grid[coordinateToStr(rowN, colN)] = value;
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
	return gridData[coordinateToStr(rowN, colN)];
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
	gridData[coordinateToStr(rowN, colN)] = data;
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
	return rowNum;
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
	return colMaxNum;
}

void GridManager::setRowLen(int rowN)
{
	rowNum = rowN;
}

void GridManager::setColMaxLen(int coln)
{
	colMaxNum = coln;
}

void GridManager::adjustGridSize()
{
	//表のタテヨコの最大値を取得
	int rowMax = this->getGridRowLength();
	int colMax = this->getGridColLength();

	//最大の行数、列数分すべて繰り返す
	for (int i = 0; i < rowMax; i++) {
		for (int j = 0; j < colMax; j++) {
			//その行、列のキーがない
			if (gridData.count(coordinateToStr(i, j)) != 1) {
				//初期値を入力
				gridData[coordinateToStr(i, j)] = vector<string>(2);
			}
		}
	}
}

void GridManager::Clear()
{
	grid.clear();
	gridData.clear();
}
