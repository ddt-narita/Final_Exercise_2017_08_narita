#pragma once

#ifndef __Environmental
#define __Environmental

#include <string>

class Environmental
{
private:
	std::string rowN;
	std::string colN;
	std::string JSONName;
	std::string a;

public:
	std::string getRowN() {
		return rowN;
	}
	
	std::string getColN() {
		return colN;
	}

	std::string getJSONName() {
		return JSONName;
	}


};

#endif // !__Environmental
