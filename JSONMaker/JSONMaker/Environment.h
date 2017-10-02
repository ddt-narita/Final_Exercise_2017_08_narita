#pragma once

#ifndef __Environmental
#define __Environmental

#include <string>

class Environmental
{
public:
	
	std::string Query = "";
	std::string JSONFilePath = "";
	std::string JsonNodeName = "";

	/*std::string getJSONName() {
		return JSONName;
	}

	void setJSONName(std::string jsonname) {
		JSONName = jsonname;
	}*/

	std::string getJSONFilePath() {
		return JSONFilePath;
	}

	void setJSONFilePath(std::string path) {
		std::string pa = path;
		JSONFilePath = pa;
	}

	std::string getQuery() {
		return Query;
	}

	void setQuery(std::string query) {
		Query = query;
	}

	void setNodeName(std::string node) {
		JsonNodeName = node;
	}
	std::string getNodeName() {
		return JsonNodeName;
	}

};

#endif // !__Environmental
