#pragma once

#ifndef __JSONManager
#define __JSONManager

#include <vector>
#include "GridManager.h"
#include "Environment.h"


class JSONManager
{
public:
	boost::property_tree::ptree json;
	GridManager* grid;
	Environmental env;

public:
	JSONManager();
	~JSONManager();

	//�\�����̒l�擾
	std::string getGrid(int rowN, int colN);
	void setGrid(int rowN, int colN, std::string value);

	//�Z���̏��
	boost::property_tree::ptree getGridData(int rowN, int colN);
	void setGridData(int rowN, int colN, boost::property_tree::ptree data);

	//�O���b�h�̒���
	int getGridRowLength();
	int getGridColLen();
	void setGridRowLen(int rown);
	void setGridColLen(int coln);

	//���ݒ�Ɋւ��郁�\�b�h
	std::string getQuery();
	bool isQuerySet();
	void setQuery(std::string query);
	std::string getJsonFilePath();
	void setJsonFilePath(std::string path);
	bool isJSONFilePathSet();

	//�����o��json���N���A
	void jsonClear();
	
	
};


#endif // !__JSONManager