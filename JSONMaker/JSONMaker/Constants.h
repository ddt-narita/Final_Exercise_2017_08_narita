#pragma once

#ifndef __Constants
#define __Constants

#include <string>
#include <fstream>
#include <iostream>

class Constants {
public:
	const std::string KEY_ISARRAY = "";
	static const int ROW_BUTTON_WIDTH = 20;
	static const int ROW_BUTTON_HEIGHT = 19;
	static const int CODE_UTF8 = 0;
	static const int CODE_SJIS = 1;

	static const int FROM_CELL_EDIT_FORM = 0;
	static const int FROM_PARENT_BUTTON  = 1;
	static const int FROM_CHILD_BUTTON	 = 2;
	static const int FROM_BIGBRO_BUTTON	 = 3;
	static const int FROM_BRO_BUTTON	 = 4;
	static const int LEVEL_PARENT = 0;


	void fileout(std::string str)
	{
		std::string filename = "debug.txt";
		std::ofstream ofs;
		ofs.open(filename, std::ios::app);
		ofs << str << std::endl;
		ofs.close();
	}
};

static Constants constants;

#endif // !__Constants
