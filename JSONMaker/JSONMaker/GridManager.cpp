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
関数名:CreateMapKey
概要:引数の座標値をマップのキーにアクセスするための文字列に変換する
引数:int rowN, colN　座標値
返却値:	string str 返還後の文字列
作成者:成田修之
作成日:9月6日
*/
string GridManager::CreateMapKey(int rowN, int colN)
{
	//"行：列"のキーを作って返却
	return to_string(rowN) + ":" + to_string(colN);
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
			grid[CreateMapKey(i, j)] = "";
			//一時オブジェクトのコピーで初期化
			gridData[CreateMapKey(i, j)] = data;
		}
	}
	//行数列数を設定
	this->setRowLen(rowN);
	this->setColLen(colN);
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
	//引数の位置の値を返却する
	return grid[CreateMapKey(rowN, colN)];
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
	//引数の位置に値をセット
	grid[CreateMapKey(rowN, colN)] = value;
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
	//引数の位置のセルの情報配列を返却
	return gridData[CreateMapKey(rowN, colN)];
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
	//引数の位置にその位置のセルの情報配列をセット
	gridData[CreateMapKey(rowN, colN)] = data;
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
	//行数を返却
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
	//列数を返却
	return colMaxNum;
}

void GridManager::setRowLen(int rowN)
{
	//行数をセット
	rowNum = rowN;
}

void GridManager::setColLen(int coln)
{
	//列数をセット
	colMaxNum = coln;
}

void GridManager::adjustGridSize()
{
	//表のタテヨコの最大値を取得
	int rowMax = this->getGridRowLength()+1;
	int colMax = this->getGridColLength()+1;

	//最大の行数、列数分すべて繰り返す
	for (int i = 0; i < rowMax; i++) {
		for (int j = 0; j < colMax; j++) {
			//その行、列のキーがない
			if (gridData.count(CreateMapKey(i, j)) != 1) {
				//初期値を入力
				gridData[CreateMapKey(i, j)] = vector<string>(2);
			}
		}
	}
}

void GridManager::Clear()
{
	//セルの値のマップをクリア
	GridClear();
	//セルの情報配列を格納するマップをクリア
	GridDataClear();
}

void GridManager::GridClear()
{
	//セルのマップをクリア
	grid.clear();
}

void GridManager::GridDataClear() {
	//セルの情報配列のマップをクリア
	gridData.clear();
}
