#pragma once

#ifndef __JSONManager
#define __JSONManager

#include <vector>
#include "GridManager.h"
#include "Environment.h"


class JSONManager
{
public:
	boost::property_tree::ptree json;
	GridManager* grid;
	Environmental env;

public:
	JSONManager();
	~JSONManager();

	//表示部の値取得
	std::string getGrid(int rowN, int colN);
	void setGrid(int rowN, int colN, std::string value);

	//セルの情報
	boost::property_tree::ptree getGridData(int rowN, int colN);
	void setGridData(int rowN, int colN, boost::property_tree::ptree data);

	//グリッドの長さ
	int getGridRowLength();
	int getGridColLen();
	void setGridRowLen(int rown);
	void setGridColLen(int coln);

	//環境設定に関するメソッド
	std::string getQuery();
	bool isQuerySet();
	void setQuery(std::string query);
	std::string getJsonFilePath();
	void setJsonFilePath(std::string path);
	bool isJSONFilePathSet();

	//メンバのjsonをクリア
	void jsonClear();
	
	
};


#endif // !__JSONManager