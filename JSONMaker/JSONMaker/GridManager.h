#pragma once

#include <map>
#include <vector>

class GridManager
{
private:
	std::map <std::string, std::string> grid;						//�\����������i�[
	std::map <std::string, std::vector<std::string>> gridData;		//�Z�����Ƃ̏����i�[
	//std::map <std::string, std::vector<std::string>> gridRowData;	//�s���Ƃ̏����i�[
	
	int rowNum = 0;		//�s��
	int colMaxNum = 0;		//�ő��

public:
	//�R���X�g���N�^
	GridManager();
	//�f�X�g���N�^
	~GridManager();

	//�������֐�
	void init(int rowN, int colN);

	//�\���������
	std::string getGrid(int rowN, int colN);
	void setGrid(int rowN, int colN, std::string value);
	
	//�Z���̏��
	std::vector<std::string> getGridData(int rowN, int colN);
	void setGridData(int rowN, int colN, std::vector<std::string> data);

	//�\�̏c���̒���
	int getGridRowLength();
	int getGridColLength(int rowN = 0);
	void setRowLen(int rowN);
	void setColMaxLen(int colN);

	void adjustGridSize();
	void Clear();
};

