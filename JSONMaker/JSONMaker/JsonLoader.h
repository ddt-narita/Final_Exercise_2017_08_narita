#pragma once
#ifndef __JSON_LOADER
#define __JSON_LOADER

#include "JSONManager.h"

class JsonLoader :
	public JSONManager
{
public:
	JsonLoader();
	~JsonLoader();

	void run();
	void init();
	void job();

	std::string getJsonFilePath();

	void loadJson()
};


#endif // !__JSON_LOADER



