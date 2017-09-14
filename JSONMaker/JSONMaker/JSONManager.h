#pragma once

#ifndef __JSONManager
#define __JSONManager

#include <vector>
#include "GridManager.h"
#include "ListManager.h"
#include "Environment.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>

class JSONManager
{
public:
	boost::property_tree::ptree json;
	GridManager* grid;
	ListManager* list;
	Environmental env;

public:
	JSONManager();
	~JSONManager();

	//�\�����̒l�擾
	std::string getGrid(int rowN, int colN);
	void setGrid(int rowN, int colN, std::string value);

	//�Z���̏��
	std::vector<std::string> getGridData(int rowN, int colN);
	void setGridData(int rowN, int colN, std::vector<std::string> data);

	//�O���b�h�̒���
	int getGridRowLength();
	int getGridColLength();
	void setGridRowLen(int rown);
	void setGridMaxColLen(int coln);

	//���X�g�Ɋւ������
	int getListNumber();
	void setListNumber(int num);
	std::string getList(int rowN);
	void setList(int rowN, std::string value);

	//���ݒ�Ɋւ��郁�\�b�h
	std::string getJSONName();
	std::string getJSONSavePath();
	void setJSONSavePath(std::string path);
	std::string getQuery();
	bool isQuerySet();
	void setQuery(std::string query);
	std::string getJsonFilePath();
	void setJsonFilePath(std::string path);
	std::string getDBName();
	bool isJSONFilePathSet();

	//�����o��json���N���A
	void jsonClear();
	void adjustGridDataSize();
	
};


#endif // !__JSONManager