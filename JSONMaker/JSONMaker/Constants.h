#pragma once

#ifndef __Constants
#define __Constants

#include <string>


static class Constants {
public:
	
	static const int KEY_INDEX = 0;
	static const int CONTENT_KEY_INDEX = 1;
	static const int ROWSPAN_INDEX = 2;
	static const int ROW_INFO_ADJUSTER = 1;
	static const int CELL_INFO_NUMBER = 2;
	const std::string KEY_IS_ARRAY = "";
	static const int ROW_BUTTON_WIDTH = 20;
	static const int ROW_BUTTON_HEIGHT = 19;
};

static Constants constants;

#endif // !__Constants
