#pragma once

#ifndef __JSONManager
#define __JSONManager

#include <vector>
#include "GridManager.h"
#include "ListManager.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>

class JSONManager
{
protected:
	boost::property_tree::ptree json;
	GridManager* grid;
	ListManager* list;

public:
	JSONManager();
	~JSONManager();

	//�\�����̒l�擾
	std::string getGrid(int rowN, int colN);
	void setGrid(int rowN, int colN, std::string value);

	//�Z���̏��
	std::vector<std::string> getGridData(int rowN, int colN);
	void setGridData(int rowN, int colN, std::vector<std::string> data);

	//�s���Ƃ̏��
	std::vector<std::string> getGridRowData(int rowN);
	void setGridRowData(int rowN, std::vector<std::string> data);

	//�O���b�h�̒���
	int getGridRowLength();
	int getGridColLength();

	//���X�g�Ɋւ������
	int getListNumber();
	void setListNumber(int num);
	std::string getList(int rowN);
	void setList(int rowN, std::string value);

	//���ݒ�Ɋւ��郁�\�b�h
	std::string getJSONName();
	std::string getJSONSavePath();
	std::string getQuery();
	std::string getJsonFilePath();
	std::string getDBName();

	//�����o��json���N���A
	void jsonClear();
	
};


#endif // !__JSONManager