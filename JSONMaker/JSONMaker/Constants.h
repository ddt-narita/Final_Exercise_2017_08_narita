#pragma once

#ifndef __Constants
#define __Constants

#include <string>


static class Constants {
public:
	
	const int KEY_INDEX = 0;
	const int CONTENT_KEY_INDEX = 1;
	const int ROWSPAN_INDEX = 2;
	const int ROW_INFO_ADJUSTER = 1;
	const int CELL_INFO_NUMBER = 2;
	const std::string KEY_IS_ARRAY = "";
};

static Constants constants;

#endif // !__Constants
