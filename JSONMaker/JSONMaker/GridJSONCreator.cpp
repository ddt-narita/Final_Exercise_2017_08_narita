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
	grid->init(rowN, colN);

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
	for (int i = 0; i < grid->getGridRowLength(); i++) {
		//�s�̏��擾
		vector<string> rowdata (grid->getGridRowData(i));
				
		//���񂪔z��ł͂Ȃ����O�񂪔z��̎�
		if (rowdata[rowdata.size() - 2] != "" && previousIsArray == 1) {
			string s = "json";
			//�e�̃L�[���Q�����񂪋�łȂ���΃s���I�h�ŋ�؂��ĕt������
			s += (parentkeys == "" ? "" : "." + parentkeys);
			//�z��̍Ō�Ƃ��Ăł����z��������o��json�Ɋi�[
			json.add_child(s, arrayptree);
		}
		//���z�񂩂�A�N�Z�X�\�ȕ�����ɕϊ�����
		parentkeys = jsonRowDataStr(rowdata);

		//�z��̎�(�s�̈�ԍŌオ�z�������)
		if (rowdata[rowdata.size() - 2] == "") {
			//�z����̃I�u�W�F�N�g
			ptree child;
			//�񐔕��J��Ԃ�
			for (int j = 0; j < grid->getGridColLength(); j++) {
				//�Z���̒l���擾
				string value = grid->getGrid(i, j);
				
				//�l��������Ɠ��͂���Ă���Ȃ�
				if (value != "") {
					//���̃Z���̏��z����擾����
					vector<string> celldata = grid->getGridData(i, j);

					//�R���e���g�L�[�̃I�u�W�F�N�g���q�̃I�u�W�F�N�g�ɒǉ�
					child.put(celldata[constants.CONTENT_KEY_INDEX], value);
				}
			}
			//�q�I�u�W�F�N�g�ɉ������͂���Ă����
			if (!child.empty() ||!child.data().empty()) {
				//�q�I�u�W�F�N�g����̃L�[�z���Ɋi�[���Ĕz��ɂ���
				arrayptree.push_back(std::make_pair("", child));
			}
			//���񂪔z��ł��������Ƃ�ۑ�
			previousIsArray = 1;
		}
		//���ʂ�JSON�̎�
		else {
			//�s�����J��Ԃ�
			for (int j = 0; j < grid->getGridColLength(); j++) {
				//���̈ʒu�̃Z���̏����擾����
				string value = grid->getGrid(i, j);
				//�������value���Z�b�g����Ă����
				if (value != "") {
					//���̃Z���̏��z����擾����
					vector<string> celldata = grid->getGridData(i, j);
					
					//�O��̏�񂪎c���Ă��܂����߂�����x�擾���ă��Z�b�g
					parentkeys = jsonRowDataStr(rowdata);

					//������ɃL�[�ƃR���e���c�L�[�̏���������
					parentkeys += "." + jsonRowDataStr(celldata);
					//json�ɃA�N�Z�X���ăZ���̒l���i�[
					json.add("json." + parentkeys, value);
				}
			}
			//���񂪔z��ł͂Ȃ����Ƃ�ۑ�
			previousIsArray = 0;
		}
	}

	//�O�񂪔z��̂܂܍Ō�܂ŗ����Ƃ�
	if (previousIsArray == 1) {
		string s  = "json";
		s += (parentkeys == "" ? "" : "." + parentkeys);
		//�z��̍Ō�Ƃ��Ăł����z��������o��json�Ɋi�[
		json.add_child(s, arrayptree);
	}


	//�ł���json���w��̃p�X�ɏ�������
	write_json("data.json", json);
}
