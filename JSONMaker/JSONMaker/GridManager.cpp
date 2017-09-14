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

/*
�֐���:coordinateToStr
�T�v:�����̍��W�l���}�b�v�̃L�[�ɃA�N�Z�X���邽�߂̕�����ɕϊ�����
����:int rowN, colN�@���W�l
�ԋp�l:	string str �ԊҌ�̕�����
�쐬��:���c�C�V
�쐬��:9��6��
*/
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
	//�Z�����Ƃ̃L�[�f�[�^���i�[������̂Ɏg���ꎞ�I�u�W�F�N�g
	vector<string> data(1);
	//�S�s��̗v�f��
	for (int i = 0; i < rowN; i++) {
		for (int j = 0; j < colN; j++) {
			//�󕶎��ŏ�����
			grid[coordinateToStr(i, j)] = "";
			//�ꎞ�I�u�W�F�N�g�̃R�s�[�ŏ�����
			gridData[coordinateToStr(i, j)] = data;
		}
	}
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
	return grid[coordinateToStr(rowN, colN)];
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
	grid[coordinateToStr(rowN, colN)] = value;
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
	return gridData[coordinateToStr(rowN, colN)];
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
	gridData[coordinateToStr(rowN, colN)] = data;
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
	return rowNum;
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
	return colMaxNum;
}

void GridManager::setRowLen(int rowN)
{
	rowNum = rowN;
}

void GridManager::setColMaxLen(int coln)
{
	colMaxNum = coln;
}

void GridManager::adjustGridSize()
{
	//�\�̃^�e���R�̍ő�l���擾
	int rowMax = this->getGridRowLength();
	int colMax = this->getGridColLength();

	//�ő�̍s���A�񐔕����ׂČJ��Ԃ�
	for (int i = 0; i < rowMax; i++) {
		for (int j = 0; j < colMax; j++) {
			//���̍s�A��̃L�[���Ȃ�
			if (gridData.count(coordinateToStr(i, j)) != 1) {
				//�����l�����
				gridData[coordinateToStr(i, j)] = vector<string>(2);
			}
		}
	}
}

void GridManager::Clear()
{
	grid.clear();
	gridData.clear();
}
