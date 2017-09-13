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
�֐���:jsonRowDataStr
�T�v:�s���Ƃ̃f�[�^���A�N�Z�X�\�ȕ�����ɕϊ�����
����:vector<string> rowData �s���Ƃ̏��z��
�ԋp�l:int len
�쐬��:���c�C�V
�쐬��:9��4��(��)
*/
string jsonRowDataStr(vector<string> rowData) {
	string retStr;
	//�s���Ƃ̃f�[�^�̑傫�����J��Ԃ�
	for (int i = 0; i < rowData.size(); i++) {
		//�ԋp���镶���񂪋�łȂ��A�Ō������؂蕶���łȂ��A��ŉ�����f�[�^���󔒂ł��Ȃ��Ƃ�
		if (!retStr.empty() && retStr.back() != '.' && rowData[i] != "") {
			//.�ŋ�؂�
			retStr += ".";
		}
		//�s���Ƃ̃f�[�^��ǉ����Ă���
		retStr += rowData[i];
	}

	//�쐬�����������ԋp����
	return retStr;
}

bool GridJSONCreator::isRowArray(int row) {
	vector<string> temp =  this->jsonmanager->getGridData(row, 0);
	int len = temp.size();
	for (int i = 0; i < len; i++) {
		if (temp[i] == "" && i != len) {
			return true;
		}
	}
	return false;
}

vector<string> GridJSONCreator::getRowDataVer(int row)
{
	//
	vector<string> row1 = jsonmanager->getGridData(row, 0);
	vector<string> row2 = jsonmanager->getGridData(row, 1);
	int n = row1.size() < row2.size() ? row1.size() : row2.size();

	//2��ڂ����͂���Ă��Ȃ��Ƃ�
	if (row2[0] == "") {
		return vector<string>(row1.begin(), row1.end() - 1);
	}
	else {
		for (int i = 0; i < n; i++) {
			if (row1[i] != row2[i]) {
				return vector<string>(row1.begin(), row1.begin() + i - 1);
			}
		}
	}
}

//���ۂ�JSON���쐬���郁�\�b�h
/*
�֐���:job
�T�v:GridManager�Ɋi�[���ꂽ��񂩂���ۂ�JSON���쐬����
����:�Ȃ�
�ԋp�l:�Ȃ�
�쐬��:���c�C�V
�쐬��:9��4��(��)
*/
void GridJSONCreator::job()
{
	//�z��̃I�u�W�F�N�g���i�[����ϐ�
	ptree arrayptree;

	//�O�񂪔z��ł��������������ϐ�
	int previousIsArray = 0;
	//�e�̃L�[���A�N�Z�X�\�ȕ�����ɕϊ����Ċi�[����ϐ�
	string parentkeys;

	//�s�����J��Ԃ�
	for (int i = 0; i < jsonmanager->grid->getGridRowLength(); i++) {
				
		//���񂪔z��ł͂Ȃ����O�񂪔z��̎�
		if (previousIsArray == 1 && !isRowArray(i)) {
			string s = "";
			//�e�̃L�[���Q�����񂪋�łȂ���΃s���I�h�ŋ�؂��ĕt������
			s += (parentkeys == "" ? "" : "" + parentkeys);
			//�z��̍Ō�Ƃ��Ăł����z��������o��json�Ɋi�[
			jsonmanager->json.add_child(s, arrayptree);
			arrayptree.clear();
		}
		//���z�񂩂�A�N�Z�X�\�ȕ�����ɕϊ�����
		parentkeys = jsonRowDataStr(getRowDataVer(i));

		//�z��̎�(�s�̈�ԍŌオ�z�������)
		if (isRowArray(i)) {
			//�z����̃I�u�W�F�N�g
			ptree child;
			//�񐔕��J��Ԃ�
			for (int j = 0; j < jsonmanager->grid->getGridColLength(); j++) {
				//�Z���̒l���擾
				string value = jsonmanager->grid->getGrid(i, j);
				
				//�l��������Ɠ��͂���Ă���Ȃ�
				if (value != "") {
					//���̃Z���̏��z����擾����
					vector<string> celldata = jsonmanager->grid->getGridData(i, j);

					//�R���e���g�L�[�̃I�u�W�F�N�g���q�̃I�u�W�F�N�g�ɒǉ�
					child.put(celldata[celldata.size() - 1], value);
				}
			}
			//�q�I�u�W�F�N�g�ɉ������͂���Ă����
			if (!child.empty() || !child.data().empty()) {
				//�q�I�u�W�F�N�g����̃L�[�z���Ɋi�[���Ĕz��ɂ���
				arrayptree.push_back(std::make_pair("", child));
			}
			//���񂪔z��ł��������Ƃ�ۑ�
			previousIsArray = 1;
		}
		//���ʂ�JSON�̎�
		else {
			//�s�����J��Ԃ�
			for (int j = 0; j < jsonmanager->grid->getGridColLength(); j++) {
				//���̈ʒu�̃Z���̏����擾����
				string value = jsonmanager->grid->getGrid(i, j);
				//�������value���Z�b�g����Ă����
				if (value != "") {
					//���̃Z���̏��z����擾����
					vector<string> celldata = jsonmanager->grid->getGridData(i, j);
					//������ɃL�[�ƃR���e���c�L�[�̏���������
					parentkeys = jsonRowDataStr(celldata);
					//json�ɃA�N�Z�X���ăZ���̒l���i�[
					jsonmanager->json.add("" + parentkeys, value);
				}
			}
			//���񂪔z��ł͂Ȃ����Ƃ�ۑ�
			previousIsArray = 0;
		}
	}

	//�O�񂪔z��̂܂܍Ō�܂ŗ����Ƃ�
	if (previousIsArray == 1) {
		string s  = "";
		s += (parentkeys == "" ? "" : "" + parentkeys);
		//�z��̍Ō�Ƃ��Ăł����z��������o��json�Ɋi�[
		jsonmanager->json.add_child(s, arrayptree);
		arrayptree.clear();
	}


	//�ł���json���w��̃p�X�ɏ�������
	write_json("data.json", jsonmanager->json);
}
