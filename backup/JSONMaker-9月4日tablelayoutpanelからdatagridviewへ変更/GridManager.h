#pragma once

#include <vector>



class GridManager
{
public:
	std::vector<std::vector<std::string>> grid;						//�\����������i�[
	std::vector<std::vector<std::vector<std::string>>> gridData;	//�Z�����Ƃ̏����i�[
	std::vector<std::vector<std::string>> gridRowData;				//�s���Ƃ̏����i�[

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
	
	//�s���Ƃ̏��
	std::vector<std::string> getGridRowData(int rowN);
	void setGridRowData(int rowN, std::vector<std::string> data);

	//�\�̏c���̒���
	int getGridRowLength();
	int getGridColLength(int rowN = 0);


};

