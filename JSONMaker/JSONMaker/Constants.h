#pragma once

#ifndef __Constants
#define __Constants

#include <string>
#include <fstream>
#include <iostream>

static class Constants {
public:
	const std::string KEY_ISARRAY = "";
	static const int ROW_BUTTON_WIDTH = 20;
	static const int ROW_BUTTON_HEIGHT = 19;

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
