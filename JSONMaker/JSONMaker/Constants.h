#pragma once

#ifndef __Constants
#define __Constants

#include <string>
#include <fstream>
#include <iostream>
#include "boost\property_tree\ptree.hpp"
#include "boost\property_tree\json_parser.hpp"

class Constants {
public:
	const std::string KEY_ISARRAY = "";
	static const int ROW_BUTTON_WIDTH = 20;
	static const int ROW_BUTTON_HEIGHT = 19;
	static const int CODE_UTF8 = 0;
	static const int CODE_SJIS = 1;
	static const int LEVEL_PARENT = 0;
	static const int COLUMN_ONE = 0;

	static const int FROM_MAINFORM = 0;
	static const int FROM_PARENT_BUTTON = 1;
	static const int FROM_CHILD_BUTTON = 2;
	
	static const int IS_SUB_FORM = 1;

	void fileout(std::string str)
	{
		std::string filename = "debug.txt";
		std::ofstream ofs;
		ofs.open(filename, std::ios::app);
		ofs << str << std::endl;
		ofs.close();
	}

	void jsonfileout(boost::property_tree::ptree json) {
		std::stringstream ss;
		boost::property_tree::write_json(ss, json);
		fileout(ss.str());
	}
};

static Constants constants;

#endif // !__Constants
