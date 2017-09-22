#include "CellChain.h"

using namespace System;
using namespace System::Collections;

/*
�֐���:�R���X�g���N�^
�T�v:�R���X�g���N�^
����:����
�ԋp�l:����
�쐬��:���c�C�V
�쐬��:9��20��(��)
*/
CellChain::CellChain()
{
	//�Z���̃L�[�Q�Ƃ��Ă̔z����i�[����
	CellKey = gcnew array<String^>(1);
	//���̃Z���̈�ԏ��߂̃L�[�Ƃ��ċ󕶎��i�[����
	CellKey[0] = gcnew String("");
	//���̃Z���̒l�Ƃ��ċ󕶎����i�[����
	Value = gcnew String("");
}

/*
�֐���:insert
�T�v:�s�Ɨ�w�肵���Z���̍��ɑ}��
����:int row �s��, int col ��
�ԋp�l:CellChain insertCell�@�}�������Z��
�쐬��:���c�C�V
�쐬��:9��20��(��)
*/
CellChain^ CellChain::insert(int row, int col)
{
	//�w�肳�ꂽ�Z�����擾����
	CellChain^ temp = getCell(row, col);
	//���̃Z���̍��̃Z�����擾
	CellChain^ left = temp->left;

	//�}���������Z�����쐬����
	CellChain^ insertCell = gcnew CellChain();
	//���̃Z���ɂ��̃Z����ǉ�����
	left->addRight(insertCell);
	//���̃Z���̉E�Ɏw��̃Z����ǉ�����
	insertCell->addRight(temp);
				
	//�}�������Z����Ԃ�
	return insertCell;
}

/*
�֐���:remove
�T�v:�w�肵���Z�����폜����֐�
����:int row �s��, int col ��
�ԋp�l:����
�쐬��:���c�C�V
�쐬��:9��20��(��)
*/
void CellChain::remove(int row, int col)
{
	//�w��̃Z�����擾����
	CellChain^ cell = getCell(row, col);
	//���̃Z���̉E�̃Z�����擾����
	CellChain^ cellRight = cell->right;
	//���̃Z���̍��̃Z�����擾����
	CellChain^ cellLeft = cell->left;

	//�w��̃Z�����폜����
	delete cell;
	//�E�̃Z���ƍ��̃Z�������т���
	cellRight->addLeft(cellLeft);
}

/*
�֐���:insertRow
�T�v:�s��}������֐�
����:int row�@�s
�ԋp�l:rowHead �}�������s�̐擪�̃Z��
�쐬��:���c�C�V
�쐬��:9��20��(��)
*/
CellChain^ CellChain::insertRow(int row)
{
	//�w��̍s�̈��ڂ̃Z�����擾����
	CellChain^ cell = getCell(row, 0);
	//���̃Z���̏�̃Z�����擾
	CellChain^ cellupper = cell->upper;
	//�}�����邽�߂̃Z��
	CellChain^ insert = gcnew CellChain();
	//���̃Z������Ɋi�[����
	cell->addUpper(insert);
	//�Z���̉��Ɋi�[����
	cellupper->addUnder(insert);
	//�s�̐擪�̃Z���Ƃ��ĕۊǂ��Ă���
	CellChain^ rowHead = insert;
	//�񐔕��J��Ԃ�
	for (int i = 0; i < colCount; i++) {
		//�}������s�̃Z�����쐬
		CellChain^ insertCell = gcnew CellChain();
		//���̃Z�����s�̃Z���̉E�ɒǉ�
		insert->addRight(insertCell);
		//���̃Z���ֈړ�
		insert = insert->right;
	}
	//�s��ǉ������̂ōs����+1����
	rowCount++;
	//�s�̐擪�̃Z����ԋp����
	return rowHead;
}

/*
�֐���:removeRow
�T�v:�s����菜��
����:int row�@�폜����s
�ԋp�l:����
�쐬��:���c�C�V
�쐬��:9��20��(��)
*/
void CellChain::removeRow(int row)
{
	//�w�肳�ꂽ�s�̈�Ԑ擪�̃Z�����擾����
	CellChain^ rowCell = getCell(row, 0);
	//���̃Z���̏�̃Z�����擾
	CellChain^ cellupper = rowCell->upper;
	//���̃Z���̉��̃Z�����擾
	CellChain^ cellunder = rowCell->under;
	//��̃Z���̉��ɉ��̃Z�����i�[
	cellupper->addUnder(cellunder);
	//��s��菜�����̂ōs����1���炷
	rowCount--;
	//�w��̃Z�����폜
	delete  rowCell;
}

/*
�֐���:insertCol
�T�v:�w��̗�̍��ɗ��}������֐�
����:int col
�ԋp�l:����
�쐬��:���c�C�V
�쐬��:9��20��(��)
*/
void CellChain::insertCol(int col)
{
	//�s�����J��Ԃ�
	for (int i = 0; i < rowCount; i++) {
		//�e��̈����̗�ɃZ����}������
		this->insert(i, col);
	}
}

/*
�֐���:removeCol
�T�v:�w��̗���폜����
����:int col
�ԋp�l:����
�쐬��:���c�C�V
�쐬��:9��20��(��)
*/
void CellChain::removeCol(int col)
{
	//�s�����J��Ԃ�
	for (int i = 0; i < rowCount; i++) {
		//�e�s�̈����̗�̃Z�����폜����
		this->remove(i, col);
	}
}

void CellChain::init(int row, int col)
{
	//�ړ����Ȃ��悤�Ɏ����̃R�s�[�����
	CellChain^ cell = this;
	int n = 0;

	//�w��̍s�����J��Ԃ�
	for (int i = 0; i < row; i++) {
		//�s�̈�ԏ��߂̃Z�����m��
		CellChain^ cellRowHead = cell;
		cellRowHead->Value = (n++).ToString();
		//�w��̗񐔕��J��Ԃ�
		for (int j = 0; j < col-1; j++) {
			//�ǉ�������Z��
			CellChain^ temp = gcnew CellChain();
			temp->Value = (n++).ToString();
			//�R�s�[��������Z���̉E�ɍ쐬�����Z����ǉ�����
			cell->addRight(temp);
			//�E�̃Z���Ɉړ�����
			cell = cell->right;
		}
		//�s�̐擪�ɖ߂�
		cell = cellRowHead;
		//�Ō�̍s�łȂ����
		if (i < row - 1) {
			//���̍s�ɂ�������Z�����쐬
			CellChain^ rowCell = gcnew CellChain();
			//rowCell->Value = (n++).ToString();
			//�Z���̉��ɒǉ�
			cell->addUnder(rowCell);
			//���̍s�Ɉړ�
			cell = cell->under;
		}
	}
}

/*
�֐���:getCell
�T�v:�Z�������̂܂܎擾����֐�
����:int row �s��, int col ��
�ԋp�l:CellChain^�@���̈ʒu�̃Z����ԋp����
�쐬��:���c�C�V
�쐬��:9��20��(��)
*/
CellChain ^ CellChain::getCell(int row, int col)
{
	//���̃N���X�ւ̃|�C���^���擾
	CellChain^ current = this;
	//�w��̍s�����J��Ԃ�(-1��1�s�ڂ͈ړ����e�ɒ���)
	for (int i = 0; i < row; i++) {
		//���̃Z���Ɉړ�
		current = current->under;
	}

	//�w��̗񐔕��J��Ԃ�
	for (int j = 0; j < col; j++) {
		//�E�̃Z���Ɉړ�
		current = current->right;
	}
	//���̃Z����ԋp����
	return current;
}

/*
�֐���:
�T�v:
����:int row �s��, int col ��
�ԋp�l:
�쐬��:���c�C�V
�쐬��:9��20��(��)
*/
System::String ^ CellChain::getValue(int row, int col)
{
	//�w��̈ʒu�̃Z�����擾����
	CellChain^ current = getCell(row, col);
	//���̃Z���̒l��ԋp����
	return current->Value;
}

/*
�֐���:getCellKey
�T�v:�w��̃Z���Ɋi�[���ꂽ�L�[�Q��ԋp����
����:int row �s��, int col ��
�ԋp�l:array<String^>^�@�Z���Ɋi�[���ꂽ�L�[�Q
�쐬��:���c�C�V
�쐬��:9��20��(��)
*/
array<System::String^>^ CellChain::getCellKey(int row, int col)
{
	//�w��̈ʒu�̃Z�����擾����
	CellChain^ current = getCell(row, col);
	//���̃Z���̃L�[�Q���擾����
	return current->CellKey;
}

/*
�֐���:setValue
�T�v:�w��̃Z���ɒl���Z�b�g����
����:int row �s��, int col ��
�ԋp�l:����
�쐬��:���c�C�V
�쐬��:9��20��(��)
*/
void CellChain::setValue(int row, int col, String^ value)
{
	//�w��̈ʒu�̃Z�����擾����
	CellChain^ current = getCell(row, col);
	//���̃Z���̒l�Ɉ����̒l���Z�b�g
	current->Value = value;
}

/*
�֐���:setCellKey
�T�v:�w��̃Z���ɃL�[�Q���i�[����
����:int row �s��, int col ��
�ԋp�l:����
�쐬��:���c�C�V
�쐬��:9��20��(��)
*/
void CellChain::setCellKey(int row, int col, array<String^>^ cellKeys)
{
	//�w��̈ʒu�̃Z�����擾����
	CellChain^ current = getCell(row, col);
	//���̃Z���̃L�[�Q�Ɉ����̃L�[�Q���i�[
	current->CellKey = cellKeys;
}

/*
�֐���:next
�T�v:���̃Z���Ɉړ�����
����:����
�ԋp�l:����
�쐬��:���c�C�V
�쐬��:9��20��(��)
*/
void CellChain::next()
{
	//���̃Z���������̃Z���ɂ���
	this->CurrentCell = this->under;
}

/*
�֐���:beforeFirst
�T�v:�ŏ��̃Z���Ɉړ�����
����:�Ȃ�
�ԋp�l:�Ȃ�
�쐬��:���c�C�V
�쐬��:9��20��(��)
*/
void CellChain::beforeFirst()
{
	//��̃Z�����i���ɂȂ�܂ŌJ��Ԃ�
	while (this->CurrentCell->upper != nullptr) {
		//���݂̃Z������̃Z���ɍX�V
		this->CurrentCell = this->CurrentCell->upper;
	}
}

/*
�֐���:addRight
�T�v:�Z���̉E�Ɉ����̃Z�����Z�b�g����
����:CellChain^ temp�@�Z�b�g�������Z��
�ԋp�l:����
�쐬��:���c�C�V
�쐬��:9��20��(��)
*/
void CellChain::addRight(CellChain ^ temp)
{
	//�����̃Z���̍��̃Z���Ƃ��Ă��̃Z�����Z�b�g
	temp->left = this;
	//���̃Z���̉E�̃Z���Ƃ��Ĉ����̃Z�����Z�b�g
	this->right = temp;
}

/*
�֐���:addLegt
�T�v:�Z���̍��Ɉ����̃Z�����Z�b�g����
����:CellChain^ temp�@�Z�b�g�������Z��
�ԋp�l:����
�쐬��:���c�C�V
�쐬��:9��20��(��)
*/
void CellChain::addLeft(CellChain ^ temp)
{
	//�����̃Z���̉E�̃Z���Ƃ��Ă��̃Z�����i�[
	temp->right = this;
	//���̃Z���̍��̃Z���Ƃ��Ĉ����̃Z�����i�[����
	this->left = temp;
}

/*
�֐���:addUpper
�T�v:�Z���̏�Ɉ����̃Z�����Z�b�g����
����:CellChain^ temp�@�Z�b�g�������Z��
�ԋp�l:����
�쐬��:���c�C�V
�쐬��:9��20��(��)
*/
void CellChain::addUpper(CellChain ^ temp)
{
	//�����̃Z���̉��̃Z���Ƃ��Ă��̃Z�����i�[
	temp->under = this;
	//���̃Z���̏�̃Z���Ƃ��Ĉ����̃Z�����i�[����
	this->upper = temp;
}

/*
�֐���:addUnder
�T�v:���ɃZ�����Z�b�g����
����:CellChain�@�Z�b�g�������Z��
�ԋp�l:����
�쐬��:���c�C�V
�쐬��:9��20��(��)
*/
void CellChain::addUnder(CellChain ^ temp)
{
	//�����̏�̃Z���Ƃ��Ă��̃Z�����i�[
	temp->upper = this;
	//���̃Z���̉��̃Z���Ƃ��Ĉ����̃Z�����i�[
	this->under = temp;
}

/*
�֐���:getSelectedeColFromRow
�T�v:��������Ƃ��I������Ă����Z���̗񐔂��擾����
����:int row �s
�ԋp�l:int col�@�I������Ă�����
�쐬��:���c�C�V
�쐬��:9��20��(��)
*/
int CellChain::getSelectedColFromRow(int row)
{
	//�w��̍s�̐擪�̃Z�����擾����
	CellChain^ cell = getCell(row, 0);
	int col = 0;
	//�񐔕��J��Ԃ�
	for (; col <= colCount; col++) {
		//�I�����ꂽ�񂪌���������
		if (cell->isSelectedCol) {
			//���[�v�𔲂���
			break;
		}
	}
	//���[�v�𔲂����Ƃ��̌��������Z���̗�̒l��ԋp����
	return col;
}

/*
�֐���:Clear
�T�v:�\�̒l���i�[����N���X�����ׂď�������N���X
����:����
�ԋp�l:����
�쐬��:���c�C�V
�쐬��:9��20��(��)
*/
void CellChain::Clear()
{
	//
	delete this->under;
	delete this->right;
	//
	this->Value = "";
	this->CellKey = gcnew array<String^>(1);
	CellKey[0] = "";
	//
	this->isBound = false;
	this->isSelectedCol = false;
	this->rowCount = 0;
	this->colCount = 0;
}

/*
�֐���:isCellValid
�T�v:���̃Z�����f�[�^�����o�����̂Ƃ��ēK�؂ł��邩�ǂ����𔻒�
����:�Ȃ�
�ԋp�l:bool�@�K��(�L��)���ǂ����̐^���l
�쐬��:9��22��(��)
�쐬��:���c�C�V
*/
bool CellChain::isCellValid()
{
	int retBool = 0;

	for (int i = 1; i < CellKey->Length; i++) {
		if (CellKey[i] != "") {
			break;
			retBool = 1;
		}
	}
	
	if (Value != "") {
		retBool = 1;
	}

	return retBool == 1;
}

/*
�֐���:������Z�q
�T�v:������Z�q���`
����:CellChain^�@temp
�ԋp�l:CellChain^ �Z����ԋp����
�쐬��:���c�C�V
�쐬��:9��20��(��)
*/
CellChain ^ CellChain::operator=(CellChain ^ temp)
{
	//�e�v�f����
	this->Value = temp->Value;
	this->CellKey = temp->CellKey;
	this->CurrentCell = temp->CurrentCell;
	this->upper = temp->upper;
	this->under = temp->under;
	this->left = temp->left;
	this->right = temp->right;
	this->isBound = temp->isBound;
	this->isSelectedCol = temp->isSelectedCol;

	return this;
}
