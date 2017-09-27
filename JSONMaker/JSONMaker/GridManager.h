#pragma once

#include <map>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>


class GridManager
{
private:
	std::map <std::string, std::string> grid;						//表示する情報を格納
	std::map <std::string, boost::property_tree::ptree> gridData;		//セルごとの情報を格納

	int rowNum = 0;		//行数
	int colNum = 0;		//最大列数

public:
	//コンストラクタ
	GridManager();
	//デストラクタ
	~GridManager();

	//初期化関数
	void init(int rowN, int colN);
	//座標からキーへの変換
	std::string CreateMapKey(int rowN, int colN);
	//表示するもの
	std::string getGrid(int rowN, int colN);
	void setGrid(int rowN, int colN, std::string value);
	
	//セルの情報
	boost::property_tree::ptree getGridData(int rowN, int colN);
	void setGridData(int rowN, int colN, boost::property_tree::ptree data);

	//表の縦横の長さ
	int getGridRowLength();
	int getGridColLen(int rowN = 0);
	void setRowLen(int rowN);
	void setColLen(int colN);

	void Clear();
	void GridClear();
	void GridDataClear();
};

