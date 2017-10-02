#pragma once

#ifndef __JSONManager
#define __JSONManager

#include <vector>
#include "Environment.h"
#include "boost\property_tree\ptree.hpp"


class JSONManager
{
public:
	boost::property_tree::ptree json;
	Environmental env;

public:
	JSONManager();
	~JSONManager();

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