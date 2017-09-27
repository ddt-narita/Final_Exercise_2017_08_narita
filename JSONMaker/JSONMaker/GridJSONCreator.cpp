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
�֐���:job
�T�v:JSON�쐬�̈�A�̏������s���֐�
����:����
�ԋp�l:����
�쐬��:9��27��(��)
�쐬��:���c�C�V
*/
void GridJSONCreator::job() {
	//JSON�쐬����
	jsonmanager->json = CreateJSON();
constants.jsonfileout(jsonmanager->json);
	//�����JSON�I�u�W�F�N�g����
	boost::property_tree::ptree p =jsonmanager->json;
	//�m�[�h���z���Ɋi�[
	jsonmanager->json.put_child(jsonmanager->env.getNodeName(), p);
	//����JSON�I�u�W�F�N�g�������o��
	write_json("data.json", jsonmanager->json);
}

bool isJsonEmpty(ptree json) {
	int i = 0;
	if ("" != json.data()) {
		return false;
	}

	BOOST_FOREACH(const ptree::value_type& child, json) {
		i = 1;
	}

	if (i != 0) {
		return false;
	}
	else {
		return true;
	}
}

/*
�֐���:CreateJSON
�T�v:GridManager�Ɋi�[���ꂽ��񂩂���ۂ�JSON���쐬����
����:�Ȃ�
�ԋp�l:�Ȃ�
�쐬��:���c�C�V
�쐬��:9��4��(��)
*/
ptree GridJSONCreator::CreateJSON()
{
	ptree json;

	//�s���Ɨ񐔂��擾
	int row = this->jsonmanager->getGridRowLength();
	int col = this->jsonmanager->getGridColLen();

	//�m�[�h�����擾����
	string nodeName = jsonmanager->env.getNodeName();

	//�s�����J��Ԃ�
	for (int i = 0; i < row; i++) {
		//�s�̈�ԍ��̂��̍s�ɂ��ĕ\���L�[���擾����
		string rowStr = jsonmanager->getGrid(i, 0);
		ptree data = jsonmanager->getGridData(i, 0);
		//���ڂ̃Z�����f�[�^�Ȃ�
		if ("" != data.data()/* || data.empty()*/) {
			json.add(rowStr, data.data());
		}

		//
		ptree rowJson;
		//�񐔕��J��Ԃ�
		for (int j = 1; j < col; j++) {
			string key = jsonmanager->getGrid(i, j);
			if ("" != key) {
				//���̃Z���̃f�[�^���擾����
				ptree cellData = jsonmanager->getGridData(i, j);
				
				if (isJsonEmpty(cellData)) {
					json.add(rowStr + "." + key, "");
				}
				else {
					//�s���Ƃ�JSON�ɂ��̍s�̃L�[�z���Ɏ擾�����Z���̃f�[�^���Z�b�g����
					json.add_child(rowStr + "." + key, cellData);
				}
			}
		}
	}
constants.jsonfileout(json);
	return json;
}


