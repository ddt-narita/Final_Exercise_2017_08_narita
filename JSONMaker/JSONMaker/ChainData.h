#pragma once
#include <string>
#include "boost\property_tree\ptree.hpp"
#include "Constants.h"

class ChainData
{
public:
	//�R���X�g���N�^
	ChainData();
	//�f�X�g���N�^
	~ChainData();

	//�L�[
	std::string key;
	//�l
	std::string value;
	//�L���ȃZ�����ǂ���������
	bool valid;
	//�O�ɑ}�����邩���ɑ}�����邩
	enum FrontBack {
		Front,
		Back
	};

	//��ւ̃|�C���^(�Z)
	ChainData* upper;
	//���ւ̃|�C���^(��)
	ChainData* under;
	//�E�ւ̃|�C���^(�q)
	ChainData* right;
	//���ւ̃|�C���^(�e)
	ChainData* left;

	//�O�ɑ}������֐�
	ChainData* insertFront();
	//���ɑ}������֐�
	ChainData* insertBack();
	//�}��������(�����őO��댈��)
	ChainData* insert(FrontBack);
	//�폜����
	void remove();
	//�s��}������
	ChainData* insertRow(int row, FrontBack);
	//���}������
	void insertCol(int col, FrontBack);
	//�s���폜����
	void removeRow(int row);
	//����폜����
	void removeCol(int col);
	//�e���쐬����
	ChainData* createParent();
	//�q���쐬����
	ChainData* createChild();
	//�e����菜���ČZ���e�̌Z��֌J��グ
	void removeParent();

	//�s��w�肵�Ă��̈ʒu�̃Z�����擾����
	ChainData* getCell(int row, int col);
	//���j�̃Z�����擾����֐�
	ChainData* getFirstBro();
	//���̒���擾����֐�
	ChainData* getLastBro();
	//�s�Ɨ�w�肵���Z���̃L�[���擾
	std::string getKey(int row, int col);
	//
	void setKey(int row, int col, std::string value);
	//
	std::string getValue(int row, int col);
	//
	void setValue(int row, int col, std::string value);
	
	//�Z���̉E�ɒǉ�����
	void addRight(ChainData* temp);
	//�Z���̍��ɒǉ�����
	void addLeft(ChainData* temp);
	//�Z���̏�ɒǉ�����
	void addUpper(ChainData* temp);
	//�Z���̉��ɒǉ�����
	void addUnder(ChainData* temp);
	//�q�̐����擾����
	int getChildCount();
	//�e�̐����擾����
	std::vector<ChainData*> getParents();

	//�I�u�W�F�N�g���ǂ����𔻒肷��
	bool isObject();
	//�L���ȃZ�����ǂ������肷��
	bool isValid();
	//�Z�����z��ւ̂��̂��ǂ������肷��
	bool isCellToArray();
	//�Z�����I�u�W�F�N�g�z��ւ̂��̂��ǂ�������
	bool isCellToObjectArray();
	//
	bool isEmptyCellToObjectArray();
};

