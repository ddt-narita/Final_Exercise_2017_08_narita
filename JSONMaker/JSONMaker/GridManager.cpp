#include "GridManager.h"
#include <vector>
#include <string>

using namespace std;

//�R���X�g���N�^
GridManager::GridManager()
{
}

//�f�X�g���N�^
GridManager::~GridManager()
{
}

string coordinateToStr(int rowN, int colN) {
	string retStr = to_string(rowN) + ":" + to_string(colN);
	return retStr;
}


/*
�֐���:init
�T�v:�������֐�
����:int rowN,colN �s����
�ԋp�l:�Ȃ�
�쐬��:���c�C�V
�쐬��:9��4��(��)
*/
void GridManager::init(int rowN, int colN)
{
}

/*
�֐���:getGrid
�T�v:�Z���̒l�擾
����:int rowN,colN
�ԋp�l:string value �l
�쐬��:���c�C�V
�쐬��:9��4��(��)
*/
std::string GridManager::getGrid(int rowN, int colN)
{
	return grid[rowN][colN];
}

/*
�֐���:setGrid
�T�v:�Z���̒l���Z�b�g����
����:int rowN,colN string value
�ԋp�l:�Ȃ�
�쐬��:���c�C�V
�쐬��:9��4��(��)
*/
void GridManager::setGrid(int rowN, int colN, std::string value)
{
	if  (grid.size() <= rowN) {
		vector<string> tempRowVec(colN);
		grid.push_back(tempRowVec);
	}
	if (grid[rowN].size() <= colN) {
		grid[rowN].push_back(value);
	}
	else {
		grid[rowN][colN] = value;
	}
}


/*
�֐���:getGridData
�T�v:�Z���̏��z����擾
����:int rowN,colN�@�s����
�ԋp�l:vector<string>data�@���z��
�쐬��:���c�C�V
�쐬��:9��4��(��)
*/
std::vector<std::string> GridManager::getGridData(int rowN, int colN)
{
	vector<string>temp = gridData[rowN][colN];
	return temp;
}


/*
�֐���:setGridData
�T�v:�Z���̏��z����i�[����
����:int rowN,colN�@�s���� vector<string>data ���z��
�ԋp�l:�Ȃ�
�쐬��:���c�C�V
�쐬��:9��4��(��)
*/
void GridManager::setGridData(int rowN, int colN, std::vector<std::string> data)
{
	if (gridData.size() <= rowN) {
		vector<vector<string>> tempRowVec(colN);
		gridData.push_back(tempRowVec);
	}
	if (gridData[rowN].size() <= colN) {
		gridData[rowN].push_back(data);
	}
	else {
		gridData[rowN][colN] = data;
	}
}

/*
�֐���:getGridRowData
�T�v:�s���Ƃ̏��擾
����:int rowN �s��
�ԋp�l:vector<string>data ���z��
�쐬��:���c�C�V
�쐬��:9��4��(��)
*/
std::vector<std::string> GridManager::getGridRowData(int rowN)
{
	return gridRowData[rowN];
}

/*
�֐���:setGridRowData
�T�v:�s���Ƃ̏��z����i�[����
����:int rowN, vector<string>data
�ԋp�l:�Ȃ�
�쐬��:���c�C�V
�쐬��:9��4��(��)
*/
void GridManager::setGridRowData(int rowN, std::vector<std::string> data)
{
	if (gridRowData.size() <= rowN) {
		gridRowData.push_back(data);
	}
	else {
		gridRowData[rowN] = data;
	}
}

/*
�֐���:getGridRowLength
�T�v:�\�̍s�̒������擾����
����:�Ȃ�
�ԋp�l:int len
�쐬��:���c�C�V
�쐬��:9��4��(��)
*/
int GridManager::getGridRowLength()
{
	int rowLen = grid.size() - 1;
	return rowLen;
}

/*
�֐���:getGridColLength
�T�v:��̒��������߂�
����:int rowN�@���s�ڂ̗�
�ԋp�l:int len
�쐬��:���c�C�V
�쐬��:9��4��(��)
*/
int GridManager::getGridColLength(int rowN)
{
	int colLen = grid[rowN].size();
	return colLen;
}
