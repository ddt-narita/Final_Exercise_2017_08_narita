#include "GridJSONCreator.h"
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include "Constants.h"
#include <iostream>

using namespace std;
using namespace boost::property_tree;

GridJSONCreator::GridJSONCreator()
{
}

GridJSONCreator::~GridJSONCreator()
{
}

/*
�֐���:init
�T�v:�������֐�
����:int rowN int colN�@
�ԋp�l:�Ȃ�
�쐬��:���c�C�V
�쐬��:9��4��(��)
*/
void GridJSONCreator::init(int rowN, int colN)
{
	//�������֐�
	jsonmanager->grid->init(rowN, colN);

}

/*
�֐���:createAcsessKey
�T�v:�L�[�Q����JSON�ɃA�N�Z�X�\�ȕ�����ɕϊ����ĕԋp����֐�
����:vector<string>eachCellKeys �L�[�Q int isArray�@�z��̃L�[�Q�Ȃ̂��ǂ���
�ԋp�l:string acsessKey�@�A�N�Z�X�\�ȕ�����
�쐬��:9��14��(��)
�쐬��:���c�C�V
*/
std::string GridJSONCreator::createAcsessKey(std::vector<std::string> eachCellKeys, int isArray) {
	//�z��Ȃ�z��̃L�[���g��Ȃ����߂�2�������łȂ��Ȃ炷�ׂĎg���̂�0��
	int adjuster = isArray == 1 ? 2 : 0;

	//�I�����ꂽ�EDB�̂��́E���͂��ꂽ�m�[�h�̖��O(���܂͉��Ƀm�[�h)
	string acsessKey = this->jsonmanager->env.getNodeName();
	//
	if (eachCellKeys.size() >= adjuster) {
		//�����̔z��̃T�C�Y����z�񂩂ǂ����ɍ��킹���l���J��Ԃ�
		for (int i = 0; i < eachCellKeys.size() - adjuster; i++) {
			//�L�[����ł͂Ȃ��A�z����ɂ�������ƒl�������
			if (acsessKey != "" && eachCellKeys[i] != "") {
				//��؂�Ƃ��̎��̒l��������
				acsessKey += "." + eachCellKeys[i];
			}
		}
	}
	//�A�N�Z�X�\�ȕ������ԋp����
	return acsessKey;
}

/*
�֐���:isArray
�T�v:���̃Z�����z��̗v�f�Ȃ̂��ǂ������肷��֐�
����:vector<string>�@�Z�����Ƃ̃L�[
�ԋp�l:bool �z�񂩂ǂ�������
�쐬��:9��14��(��)
�쐬��:���c�C�V
*/
bool isArray(vector<string> eachCellKey) {
	//����Ɏg���ϐ��z��ł͂Ȃ����Ƃ������l�ŏ�����
	int retJudge = 0;
	//�����̔z��̗e���������J��Ԃ�
	for (int i = 0; i < eachCellKey.size(); i++) {
		//�v�f�̒��ɔz��ł��邱�Ƃ������L�[���܂܂�Ă���Ƃ�
		if (eachCellKey[i] == constants.KEY_ISARRAY) {
			//�z��ł��邱�Ƃ������l���i�[
			retJudge = 1;
			//���[�v�𔲂���
			break;
		}
	}
	//�l���z��������Ă��邩�ǂ����Ŕ��肵�ĕԋp����B
	return retJudge == 1;
}


bool emptyData(vector<string> data) {
	int i = 0;
	for (i = 1; i < data.size(); i++) {
		if (data[i] != "") {
			break;
		}
	}
	return i == data.size();
}


/*
�֐���:CreateJSON
�T�v:GridManager�Ɋi�[���ꂽ��񂩂���ۂ�JSON���쐬����
����:�Ȃ�
�ԋp�l:�Ȃ�
�쐬��:���c�C�V
�쐬��:9��4��(��)
*/
void GridJSONCreator::CreateJSON()
{
	//�s���Ɨ񐔂��擾
	int row = this->jsonmanager->getGridRowLength() + 1;
	int col = this->jsonmanager->getGridColLength();
	ptree arrayObject;
	ptree arraytree;
	int rowContainsArray = 0;
	int arrayType = 0;
	vector<string>preArrayData;
	int i = 0;
	int j = 0;
	
	try {
		//�s�����J��Ԃ�
		for ( i = 0; i < row; i++) {
			//�񐔕��J��Ԃ�
			for (j = 0; j < col; j++) {

				//�Z���̏����擾
				vector<string> cellData = this->jsonmanager->getGridData(i, j);
				//�l���擾
				string value = this->jsonmanager->getGrid(i, j);
				if (value != "" || !emptyData(cellData)) {

					//���̃Z�����z��������Ă���Ƃ�
					if (isArray(cellData)) {
						arrayType = 0;
						//
						arrayObject.put(*(cellData.end() - 1), value);
						//�v�f���I�u�W�F�N�g�ł͂Ȃ��Ȃ�
						if (*(cellData.end() - 1) == "") {
							//
							arraytree.push_back(make_pair("", arrayObject));
							arrayType = 1;
						}
						preArrayData = cellData;
						//
						rowContainsArray = 1;
					}
					//�z��ł͂Ȃ��A�ʏ�̗v�f�̎�
					else {
						//
						jsonmanager->json.put(createAcsessKey(cellData, 0), value);
					}
				}

			}
			//���̍s���Ɉ�ł��z��̗v�f�������
			if (rowContainsArray == 1) {
				//�I�u�W�F�N�g�̎�
				if (arrayType == 0) {
					//����Ƃ̏o���オ�����z��̃I�u�W�F�N�g�v�f��ǉ�����
					arraytree.push_back(make_pair("", arrayObject));
				}
				//�ʏ�v�f�̎�
				else {
					//�ł����z��̗v�f���Ƃ̃I�u�W�F�N�g�����܂܂ł̃L�[�z���Ɋi�[
					jsonmanager->json.add_child(createAcsessKey(preArrayData, 1), arraytree);
					//���Ɏg�����߂ɃN���A
					arraytree.clear();
				}
				//�s�ɔz�񂪂��������Ƃ������l���N���A
				rowContainsArray = 0;
			}
			//��s���Ƃɔz��̃I�u�W�F�N�g�v�f���N���A����
			arrayObject.clear();
		}
		//�Ō�ɔz��ł�����̂��c���Ă���Ȃ�(0)
		if (!arraytree.empty() && arrayType == 0) {
			//���̔z����i�[����
			jsonmanager->json.add_child(createAcsessKey(preArrayData, 1), arraytree);
		}
	}
	catch (...) {
		throw exception(("��: " + to_string(i) + " �s:" + to_string(j)).c_str());
	}
	write_json("data.json", jsonmanager->json);
}