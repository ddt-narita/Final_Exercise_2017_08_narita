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
�֐���:CreateMapKey
�T�v:�����̍��W�l���}�b�v�̃L�[�ɃA�N�Z�X���邽�߂̕�����ɕϊ�����
����:int rowN, colN�@���W�l
�ԋp�l:	string str �ԊҌ�̕�����
�쐬��:���c�C�V
�쐬��:9��6��
*/
string GridManager::CreateMapKey(int rowN, int colN)
{
	//"�s�F��"�̃L�[������ĕԋp
	return to_string(rowN) + ":" + to_string(colN);
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
			grid[CreateMapKey(i, j)] = "";
			//�ꎞ�I�u�W�F�N�g�̃R�s�[�ŏ�����
			gridData[CreateMapKey(i, j)] = data;
		}
	}
	//�s���񐔂�ݒ�
	this->setRowLen(rowN);
	this->setColLen(colN);
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
	//�����̈ʒu�̒l��ԋp����
	return grid[CreateMapKey(rowN, colN)];
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
	//�����̈ʒu�ɒl���Z�b�g
	grid[CreateMapKey(rowN, colN)] = value;
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
	//�����̈ʒu�̃Z���̏��z���ԋp
	return gridData[CreateMapKey(rowN, colN)];
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
	//�����̈ʒu�ɂ��̈ʒu�̃Z���̏��z����Z�b�g
	gridData[CreateMapKey(rowN, colN)] = data;
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
	//�s����ԋp
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
	//�񐔂�ԋp
	return colMaxNum;
}

void GridManager::setRowLen(int rowN)
{
	//�s�����Z�b�g
	rowNum = rowN;
}

void GridManager::setColLen(int coln)
{
	//�񐔂��Z�b�g
	colMaxNum = coln;
}

void GridManager::adjustGridSize()
{
	//�\�̃^�e���R�̍ő�l���擾
	int rowMax = this->getGridRowLength()+1;
	int colMax = this->getGridColLength()+1;

	//�ő�̍s���A�񐔕����ׂČJ��Ԃ�
	for (int i = 0; i < rowMax; i++) {
		for (int j = 0; j < colMax; j++) {
			//���̍s�A��̃L�[���Ȃ�
			if (gridData.count(CreateMapKey(i, j)) != 1) {
				//�����l�����
				gridData[CreateMapKey(i, j)] = vector<string>(2);
			}
		}
	}
}

void GridManager::Clear()
{
	//�Z���̒l�̃}�b�v���N���A
	GridClear();
	//�Z���̏��z����i�[����}�b�v���N���A
	GridDataClear();
}

void GridManager::GridClear()
{
	//�Z���̃}�b�v���N���A
	grid.clear();
}

void GridManager::GridDataClear() {
	//�Z���̏��z��̃}�b�v���N���A
	gridData.clear();
}
