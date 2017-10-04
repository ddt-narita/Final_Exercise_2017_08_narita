#include "ChainData.h"

using namespace std;

ChainData::ChainData()
{
	this->key = "";
	this->value = "";
	this->valid = true;
	this->right = nullptr;
	this->left = nullptr;
	this->upper = nullptr;
	this->under = nullptr;
}


ChainData::~ChainData()
{
	if (nullptr != this->right) {
		delete this->right;
	}
	if (nullptr != this->under) {
		delete this->under;
	}
}



//�O�ɑ}������
ChainData * ChainData::insertFront()
{
	//�w�肳�ꂽ�Z�����擾����
	ChainData* selectedCell = this;
	//�}������Z��
	ChainData* insertCell = new ChainData();

	//�Z���Ȃ��Ƃ��i���j�̃Z���̎��j
	if (nullptr == selectedCell->upper) {
		//�e�̃Z�����擾
		ChainData* parent = selectedCell->left;
		//�e�̎q�Ƃ��đ}�����邽�߂̃Z����ǉ�����
		parent->addRight(insertCell);
		//�}�������Z���̉��ɑI�����ꂽ�Z����ǉ�
		insertCell->addUnder(selectedCell);
	}
	//���j�̃Z���ł͂Ȃ�
	else {
		//��i�Z�j�̃Z�����擾����
		ChainData* upper = selectedCell->upper;
		//��̃Z���̉��ɑ}������Z����ǉ�����
		upper->addUnder(insertCell);
		//�}�������Z���̉��ɑI�����ꂽ�Z����ǉ�����
		insertCell->addUnder(selectedCell);
		//�Z�̃Z���������Ȃ�}�������Z����������
		if (!upper->valid) {
			insertCell->valid = false;
		}
	}
	//�}�������Z����Ԃ�
	return insertCell;
}

//��ɑ}������
ChainData * ChainData::insertBack()
{
	//�I�����ꂽ�Z�����擾����
	ChainData* selectedCell = this;
	//�}�����邽�߂̃Z��
	ChainData* insertCell = new ChainData();

	//�I�����ꂽ�Z���̉��ɃZ�������݂���
	if (nullptr != selectedCell->under) {
		//���̃Z�����擾����
		ChainData* under = selectedCell->under;
		//�I�����ꂽ�Z���̉��ɑ}�����邽�߂̃Z����ǉ����đ}��
		selectedCell->addUnder(insertCell);
		//�}�������Z���̉��ɉ��̃Z����ǉ�
		insertCell->addUnder(under);
	}
	//���̃Z�������݂��Ȃ�
	else {
		//�I�����ꂽ�Z���̉��ɑ}�����邽�߂̃Z����ǉ�����
		selectedCell->addUnder(insertCell);
	}
	//�Z�̃Z���������Ȃ�}�������Z����������
	if (!selectedCell->valid) {
		insertCell->valid = false;
	}

	//�}�������Z����ԋp����
	return insertCell;
}

/*
�֐���:insert
�T�v:�O����ɑ}������֐�
����:ChainData::FrontBacm fb�@�O���ォ
�ԋp�l:ChainData* insertCell�@�}�������Z��
�쐬��:10��2��(��)
�쐬��:���c�C�V
*/
ChainData * ChainData::insert(FrontBack fb)
{
	//�}�������Z�����擾���ĕԂ����߂̕ϐ�
	ChainData* insertCell;
	//�����̒l���O�������Ă�����
	if (FrontBack::Front == fb) {
		//�O�ւ̒ǉ��֐������s
		insertCell = insertFront();
	}
	//���������Ă���Ƃ�
	else {
		//���ւ̒ǉ��֐������s
		insertCell = insertBack();
	}
	//�}�������Z����ԋp����
	return insertCell;
}


//�I�����ꂽ�Z�����폜����
void ChainData::remove()
{
	//�w��̃Z�����擾����
	ChainData* selectedCell = this;
	
	//�Z�̂��Ȃ��Z���Ȃ�
	if (nullptr == selectedCell->upper) {
		//�e�̃Z�����擾����
		ChainData* parent = selectedCell->left;
		//���̃Z��������Ȃ�
		if (nullptr != selectedCell->under) {
			//�e�̃Z���̎q�Ƃ��ĉ��̃Z����ǉ�
			parent->addRight(selectedCell->under);
			//���Ԃ���ɂȂ��Ă��܂����̃Z���̏�ւ̃|�C���^��null�ɂ���
			selectedCell->under->upper = nullptr;
			//����w�����܂܂��Ə����Ă��܂��̂Ńi�����
			selectedCell->under = nullptr;
		}
		else {
			//�e���w���Ă������g�ւ̃|�C���^���i���ɂ���
			parent->right = nullptr;
		}

	}
	//�Z�̂���Z���Ȃ�
	else {
		//�Z�̃Z�����擾����
		ChainData* bro = selectedCell->upper;
		//���̃Z��������Ȃ�
		if (nullptr != selectedCell->under) {
			//�Z�̃Z���̒�Ƃ��ĉ��̃Z�����i�[
			bro->addUnder(selectedCell->under);
			//����w�����܂܂��Ə����Ă��܂��̂Ńi�����
			selectedCell->under = nullptr;
		}
		else {
			//�Z���w���Ă��������ւ̃|�C���^���i���ɂ���
			bro->under = nullptr;
		}
	}
	//�I�����ꂽ�Z����j������
	delete selectedCell;
}

ChainData * ChainData::insertRow(int row, FrontBack fb)
{
	ChainData* rowHead = this->getCell(row, 0);
	//���̍s�̐擪�̃Z���ɑ΂��Ĉ����̑O����n���đ}������
	ChainData* insertRowHead = rowHead->insert(fb);
	
	//�s��ǉ������̂ōs����+1����
	//�s�̐擪�̃Z����ԋp����
	return insertRowHead;
}

void ChainData::removeRow(int row)
{
	ChainData* rowHead = this->getCell(row, 0);
	//���̍s�̐擪�̃Z���ɑ΂��č폜���s��
	rowHead->remove();

}

void ChainData::insertCol(int col, FrontBack fb)
{
	//��s�ڂɂ��Ă͎d�l������ɒǉ��i2�s�ڂɂ��đ}���̂��߂��̏����Ɂj
	if (0 == col) {
		col = 1;
		fb = ChainData::FrontBack::Front;
	}
	int row = getChildCount();
	//�s�����J��Ԃ�
	for (int i = 0; i < row; i++) {
		ChainData* colCell = this->getCell(i, col);
		//���̃Z���ɑ΂��Ĉ����̑O����n���đ}������
		colCell->insert(fb);
	}
}

void ChainData::removeCol(int col)
{
	//���ڂɂ��Ă͎d�l��������폜�i2��ڂɂ��č폜�̂��߂��̏����Ɂj
	if (0 == col) {
		col = 1;
	}
	int row = getChildCount();
	//�s�����J��Ԃ�
	for (int i = 0; i < row; i++) {
		ChainData* colCell = this->getCell(i, col);
		//���̃Z���ɑ΂��č폜����
		colCell->remove();
	}
}

ChainData * ChainData::createParent()
{
	ChainData* insertCell = new ChainData();
	//���j�̃Z���̎�
	if (nullptr == this->upper) {
		//�e�̃Z�����擾
		ChainData* parent = this->left;
		//�e�̎q�Ƃ��đ}������Z����ǉ�
		parent->addRight(insertCell);

		//���ɃZ���������
		if (nullptr != this->under) {
			//���̃Z�����擾
			ChainData* under = this->under;
			//�ǉ������Z���̉��ɂ��̃Z����ǉ�
			insertCell->addUnder(under);
		}
	}
	//���j�ł͂Ȃ��Ƃ�
	else {
		//��̌Z�̃Z�����擾
		ChainData* bro = this->upper;
		//�Z�̉��ɐV�����Z����ǉ�
		bro->addUnder(insertCell);
		//���ɃZ�������鎞
		if (nullptr != this->under) {
			//���̃Z�����擾
			ChainData* under = this->under;
			//�V�����Z���̉��ɂ����ǉ�
			insertCell->addUnder(under);
		}
	}
	//�I�����ꂽ�Z���̉���null��
	this->under = nullptr;
	//�}�������Z���̎q�Ƃ��Ď��M���i�[����
	insertCell->addRight(this);
	//�}�������Z����Ԃ�
	return insertCell;
}

/*
*/
ChainData * ChainData::createChild()
{
	//�}������V�����Z��
	ChainData* insertCell = new ChainData();
	//�q���擾
	ChainData* child = this->right;

	this->addRight(insertCell);

	//�q��������Ǝ擾�ł��Ă�����
	if (nullptr != child) {
		//�}�������Z���̎q�Ƃ��Ċi�[����
		insertCell->addRight(child);
	}
	//�}�������Z����ԋp����
	return insertCell;
}


ChainData * ChainData::getCell(int row, int col)
{
	//���̃N���X�ւ̃|�C���^���擾
	ChainData* current = this->right;
	//�w��̍s�����J��Ԃ�(-1��1�s�ڂ͈ړ����e�ɒ���)
	for (int i = 0; i < row; i++) {
		//���̃Z���Ɉړ�
		current = current->under;
	}

	//�񐔂��q���擾����ق��܂ōs���Ă���(2��ڈȍ~���擾���悤�Ƃ��Ă���Ȃ�)
	if (col > 0) {
		//�q�ɍ~���
		current = current->right;
		//�w��̗񐔕��J��Ԃ�
		for (int j = 1; j < col; j++) {
			//�Z����ړ�
			current = current->under;
		}
	}
	//���̃Z����ԋp����
	return current;
}

std::string ChainData::getKey(int row, int col)
{
	//
	ChainData* current = getCell(row, col);
	// 
	return current->key;
}

void ChainData::setKey(int row, int col, std::string value)
{
	//
	ChainData* current = getCell(row, col);
	// 
	current->key = value;
}

std::string ChainData::getValue(int row, int col)
{
	return getCell(row,col)->value;
}

void ChainData::setValue(int row, int col, std::string value)
{
	getCell(row, col)->value = value;
}

void ChainData::addRight(ChainData * temp)
{
	temp->left = this;
	this->right = temp;
}

void ChainData::addLeft(ChainData * temp)
{
	temp->right = this;
	this->left = temp;
}

void ChainData::addUpper(ChainData * temp)
{
	//�����̃Z���̉��̃Z���Ƃ��Ă��̃Z�����i�[
	temp->under = this;
	//���̃Z���̏�̃Z���Ƃ��Ĉ����̃Z�����i�[����
	this->upper = temp;
}

void ChainData::addUnder(ChainData * temp)
{
	//�����̏�̃Z���Ƃ��Ă��̃Z�����i�[
	temp->upper = this;
	//���̃Z���̉��̃Z���Ƃ��Ĉ����̃Z�����i�[
	this->under = temp;
}

/*
�֐���:getChildCount
�T�v:�q�̐��𐔂��ĕԂ�
����:����
�ԋp�l:int childCount �q�̐�
�쐬��:9��26��(��)
�쐬��:���c�C�V
*/
int ChainData::getChildCount()
{
	//�J�����g�̃Z���Ƃ��ĕۊ�
	ChainData* current = this;
	//�q�̃Z�����擾
	ChainData* child = current->right;

	//�J�E���g����ϐ�
	int childCount = 0;
	//�q�����ׂđ���
	while(child != nullptr && child->isValid()) {
		//���̎q��
		child = child->under;
		//�J�E���g����
		childCount++;
	}
	//�J�E���g�����l��ԋp����
	return childCount;

}


/*
�֐���:getParentPath
�T�v:��ԏォ�炻�̃Z���܂ł̃p�X���擾����
����:�Ȃ�
�ԋp�l:vector<string> retPath ��ԏ�̐e����̃p�X
�쐬��:9��30��(�y)
�쐬��:���c�C�V
*/
std::vector<ChainData*> ChainData::getParents()
{
	//�ԋp����p�X���ォ��������z��
	vector<ChainData*> retPath;
	//���g��e�̃J�����g�Ƃ��Ď擾
	ChainData* parentCurrent = this;
	//�e���i�����w���܂ŌJ��Ԃ�
	while (nullptr != parentCurrent) {
		//�e�Ɉڂ�����q�̃J�����g��p�ӂ��Ă�����q�̃J�����g��
		ChainData* childCurrent = parentCurrent;
		//�q�ɂ��ČZ���i�����w���܂ŌJ��Ԃ�
		while (nullptr != childCurrent->upper) {
			//�Z�Ɉړ�����
			childCurrent = childCurrent->upper;
		}
		//�e�̃J�����g�����܂̎q�̃J�����g�̐e�ɐݒ�
		parentCurrent = childCurrent->left;
		//�e��������Ƃ���Ȃ�
		if (nullptr != parentCurrent) {
			//�p�ӂ����z��̐擪���擾����
			auto ite = retPath.begin();
			//�擪�ɃL�[���i�[����
			retPath.insert(ite, parentCurrent);
		}
	}
	//�쐬�����z���ԋp����
	return retPath;
}

/*
�֐���:isObject
�T�v:���̃Z�����I�u�W�F�N�g���ǂ����𔻒�
����:����
�ԋp�l:bool �I�u�W�F�N�g�̏����ɓ��Ă͂܂邩�ǂ���
�쐬��:9��28��(��)
�쐬��:���c�C�V
*/
bool ChainData::isObject()
{
	//�q������A�q���L�����ǂ����Ŕ���
	return this->right != nullptr && this->right->isValid();
}

/*
�֐���:isValid
�T�v:�L���ȃZ�����ǂ������肷��֐�
����:����
�ԋp�l:bool �L�����ǂ�������
�쐬��:9��28��(��)
�쐬��:���c�C�V
*/
//�L���ł��邩�ǂ����𔻒肷��
bool ChainData::isValid()
{
	//�L�[�ƒl�ɖ����ȃZ���ł��邱�Ƃ������l�����͂���Ă��Ȃ����ǂ�����ԋp����
	return valid;
}


/*
�֐���:isArray
�T�v:�z��ւ̃Z���ł��邱�Ƃ𔻒肷��
����:bool �z��ւ̃Z�����ǂ���
�ԋp�l:����
�쐬��:9��29��(��)
�쐬��:���c�C�V
*/
bool ChainData::isCellToArray()
{
	//�q���Ȃ��Ƃ�
	if (nullptr == this->right) {
		//�z��ւ̃Z���ł͂Ȃ�
		return false;
	}
	//�z��̗v�f�ł���q���擾
	ChainData* child = this->right;
	//�v�f�̃Z�����L�[����Œl�͂���A���̂���Ɏq�͑��݂��Ȃ�,�܂������Ă��L���łȂ��Ƃ�
	if ("" == child->key && "" != child->value && (nullptr == child->right || !child->right->isValid())) {
		//�ʏ�̔z��ւ̃Z���ł��邱�Ƃ�Ԃ�
		return true;
	}
	//����ȊO�͈Ⴄ���Ƃ�Ԃ�
	return false;
}

/*
�֐���:isArray
�T�v:�I�u�W�F�N�g�z��ւ̃Z���ł��邱�Ƃ𔻒肷��
����:bool �I�u�W�F�N�g�z��ւ̃Z�����ǂ���
�ԋp�l:����
�쐬��:9��29��(��)
�쐬��:���c�C�V
*/
bool ChainData::isCellToObjectArray()
{
	//�q���Ȃ��Ƃ�
	if (nullptr == this->right) {
		//�m���ɈႤ�̂�false��Ԃ�
		return false;
	}
	//�ԋp����^���l��Ԃ����߂̕ϐ�
	int retVal = 0;
	//�q���擾����
	ChainData* child = this->right;
	//�q�̃L�[����łȂ�
	if ("" != child->key) {
		//�I�u�W�F�N�g�z��̏����ɂ͍���Ȃ�
		retVal = 0;
	}
	//�������Ȃ��Ƃ�
	else if(nullptr == child->right || !child->right->isValid()) {
		//�����ɍ���Ȃ�
		retVal = 0;
	}
	//�������鎞
	else {
		//�����擾����
		ChainData* Gchild = child->right;
		//���̃L�[�ƒl�����͂���Ă��āA���̂���Ɏq�͑��݂��Ȃ��������̎�
		if ((nullptr == Gchild->right || !Gchild->right->isValid())) {
			//�I�u�W�F�N�g�z��ւ̃Z���ł��邱�Ƃ�Ԃ�
			retVal = 1;
		}
	}
	//���ׂĂɓ��Ă͂܂�Ȃ����false��Ԃ�
	return retVal == 1;
}

bool ChainData::isEmptyCellToObjectArray()
{
	//�ԋp����^���l�ɗp����l
	int retVal = 1;
	//�L�[����łȂ��Ƃ�
	if ("" != this->value) {
		//�m���ɈႤ�̂ł��̂��Ƃ�Ԃ�
		return false;
	}

	//���g���擾���ăJ�����g�Ƃ���
	ChainData* current = this;
	//�Z�����Ȃ��Ȃ�܂ł����̂ڂ��Ē��j���擾
	while (nullptr != current->upper)
	{
		//�Z�ֈړ�
		current = current->upper;
	}

	//�J�����g���i���ɂȂ�܂ŌJ��Ԃ�
	while (nullptr != current) {
		//�J�����g�̃Z���̃L�[�ɋ�łȂ����̂�����Ȃ�
		if ("" != current->key) {
			//�ԋp�ɗp����l��false��\���l���i�[
			retVal = 0;
			//���[�v�𔲂���
			break;
		}
		//��Ɉړ�����
		current = current->under;
	}

	//true�������l�Ɠ��������ǂ����Ŕ����Ԃ�
	return retVal == 1;
}


