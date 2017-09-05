#pragma once

#include <vector>



class GridManager
{
public:
	std::vector<std::vector<std::string>> grid;						//表示する情報を格納
	std::vector<std::vector<std::vector<std::string>>> gridData;	//セルごとの情報を格納
	std::vector<std::vector<std::string>> gridRowData;				//行ごとの情報を格納

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
	
	//行ごとの情報
	std::vector<std::string> getGridRowData(int rowN);
	void setGridRowData(int rowN, std::vector<std::string> data);

	//表の縦横の長さ
	int getGridRowLength();
	int getGridColLength(int rowN = 0);


};

