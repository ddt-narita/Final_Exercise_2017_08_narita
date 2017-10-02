#pragma once
#ifndef __JSON_LOADER
#define __JSON_LOADER

#include "JSONManager.h"
#include <vector>
#include "ChainData.h"


class JsonLoader
{
private:

public:
	JSONManager* jsonmanager;

	JsonLoader();
	~JsonLoader();

	void init();
	void job(std::string jsonnode, ChainData* cell);

	//
	void loadJson(boost::property_tree::ptree json, ChainData* cell);
	void returnRow();
	std::vector<std::string> getNodes(boost::property_tree::ptree json);
};

#endif // !__JSON_LOADER



