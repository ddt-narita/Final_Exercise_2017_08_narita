#pragma once

#include <map>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>


class GridManager
{
private:
	std::map <std::string, std::string> grid;						//�\����������i�[
	std::map <std::string, boost::property_tree::ptree> gridData;		//�Z�����Ƃ̏����i�[

	int rowNum = 0;		//�s��
	int colNum = 0;		//�ő��

public:
	//�R���X�g���N�^
	GridManager();
	//�f�X�g���N�^
	~GridManager();

	//�������֐�
	void init(int rowN, int colN);
	//���W����L�[�ւ̕ϊ�
	std::string CreateMapKey(int rowN, int colN);
	//�\���������
	std::string getGrid(int rowN, int colN);
	void setGrid(int rowN, int colN, std::string value);
	
	//�Z���̏��
	boost::property_tree::ptree getGridData(int rowN, int colN);
	void setGridData(int rowN, int colN, boost::property_tree::ptree data);

	//�\�̏c���̒���
	int getGridRowLength();
	int getGridColLen(int rowN = 0);
	void setRowLen(int rowN);
	void setColLen(int colN);

	void Clear();
	void GridClear();
	void GridDataClear();
};

