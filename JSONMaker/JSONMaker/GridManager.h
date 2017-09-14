#pragma once

#include <map>
#include <vector>

class GridManager
{
private:
	std::map <std::string, std::string> grid;						//表示する情報を格納
	std::map <std::string, std::vector<std::string>> gridData;		//セルごとの情報を格納
	//std::map <std::string, std::vector<std::string>> gridRowData;	//行ごとの情報を格納
	
	int rowNum = 0;		//行数
	int colMaxNum = 0;		//最大列数

public:
	//コンストラクタ
	GridManager();
	//デストラクタ
	~GridManager();

	//初期化関数
	void init(int rowN, int colN);

	//表示するもの
	std::string getGrid(int rowN, int colN);
	void setGrid(int rowN, int colN, std::string value);
	
	//セルの情報
	std::vector<std::string> getGridData(int rowN, int colN);
	void setGridData(int rowN, int colN, std::vector<std::string> data);

	//表の縦横の長さ
	int getGridRowLength();
	int getGridColLength(int rowN = 0);
	void setRowLen(int rowN);
	void setColMaxLen(int colN);

	void adjustGridSize();
	void Clear();
};

