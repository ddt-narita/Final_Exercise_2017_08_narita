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
�֐���:job
�T�v:JSON�쐬�̈�A�̏������s���֐�
����:����
�ԋp�l:����
�쐬��:9��27��(��)
�쐬��:���c�C�V
*/
void GridJSONCreator::job(ChainData* cell) {

	keyHierarchy = vector<string>(15);
	level = 0;
	ptree json;
	CreateJSON(cell, json);

	keyHierarchy.clear();
	level = 0;
	//����JSON�I�u�W�F�N�g�������o��
	write_json("data.json", json);
	json.clear();
	jsonmanager->json.clear();
}

/*
�֐���:createAcsessKey
�T�v:
����:vector<string> keyarray�@�K�w���Ƃ̃L�[�z��
	 int level�@�K�w�̒l
�ԋp�l:string �ԋp����A�N�Z�X���邽�߂̃L�[
�쐬��:9��28��(��)
�쐬��:���c�C�V
*/
string GridJSONCreator::createAcsessKey(vector<string> keyarray, int level) {
	//�ԋp����L�[
	string acsesskey;
	try {//�����̊K�w�̒l���J��Ԃ�
		for (int i = 0; i < level; i++) {
			//�ԋp����L�[����łȂ����(��ԏ��߂ł͂Ȃ����)
			if ("" != acsesskey) {
				//�A�N�Z�X�\�Ȃ悤�ɃJ���}�ŋ�؂�
				acsesskey += ".";
			}
			//�L�[���ォ�珇�Ɍp�������Ă���
			acsesskey += keyarray[i];
		}
	}
	catch (exception& e) {
		int i = 0;
	}
	return acsesskey;
}

/*
*/
void createObjectArrayJson(ChainData* cellToObjectArray, ptree json) {

}

/*
�֐���:CreateJSON
�T�v:GridManager�Ɋi�[���ꂽ��񂩂���ۂ�JSON���쐬����
����:�Ȃ�
�ԋp�l:�Ȃ�
�쐬��:���c�C�V
�쐬��:9��28��(��)
*/
void GridJSONCreator::CreateJSON(ChainData* cell, ptree& json)
{
	try {
		//�Z�킷�ׂđ���
		while (nullptr != cell && cell->isValid()) {
			if (keyHierarchy[0] != "" && level == 0) {
				return;
			}
			
			//�l���K�w�̃L�[�Ƃ��ĕۊǂ���
			keyHierarchy[level] = constants.SjistoUTF8(cell->key);
			//���̊K�w�܂ł̃L�[����A�N�Z�X���邽�߂̃L�[��������쐬����
			string acsesskey = createAcsessKey(keyHierarchy, level + 1);
			


			//�I�u�W�F�N�g�z��ւ̃Z���擪�̃Z���̎�
			if (cell->isCellToObjectArray()) {
				//�q���擾���Ďq�J�����g��
				ChainData* childCurrent = cell->right;
				//�I�u�W�F�N�g�z����i�[����JSON�I�u�W�F�N�g
				ptree objectArray;
				//�q�̐������J��Ԃ�
				for (int i = 0; i < cell->getChildCount(); i++) {
					//�����擾���đ��J�����g�ɂ���
					ChainData* GchildCurrent = childCurrent->right;
					//�I�u�W�F�N�g�z��̗v�f���i�[���邽�߂�JSON�I�u�W�F�N�g
					ptree ObjectArrayEle;
					//���̐������J��Ԃ�
					for (int j = 0; j < childCurrent->getChildCount(); j++) {
						//�I�u�W�F�N�g�z��̗v�f�Ƃ��đ��̃L�[�ƒl���i�[����
						ObjectArrayEle.put(constants.SjistoUTF8(GchildCurrent->key), constants.SjistoUTF8(GchildCurrent->value));
						//�������̌Z��Ɉړ�
						GchildCurrent = GchildCurrent->under;
					}
					//���łł����v�f����̃L�[�̃I�u�W�F�N�g�Ɋi�[����
					objectArray.push_back(make_pair("", ObjectArrayEle));
					//
					ObjectArrayEle.clear();
					//�q�����̌Z��Ɉړ�����
					childCurrent = childCurrent->under;
				}
				//�q�Ƒ��łł����I�u�W�F�N�g�z�������܂ł̃L�[�z���Ɋi�[����
				json.put_child(acsesskey, objectArray);
			}
			//�ʏ�z��ւ̃Z���̎�
			else if (cell->isCellToArray()) {
				//�q���擾���Ďq�J�����g�Ƃ���
				ChainData* childCurrent = cell->right;
				//�z���JSON���i�[���邽�߂�JSON�I�u�W�F�N�g
				ptree arrayJson;
				//�z��̗v�f���i�[���邽�߂�JSON�I�u�W�F�N�g
				ptree objectEle;
				//�q�̐������J��Ԃ�
				for (int i = 0; i < cell->getChildCount(); i++) {
					//�v�f�Ƃ��ăL�[�ƒl���i�[����
					objectEle.put(constants.SjistoUTF8(childCurrent->key), constants.SjistoUTF8(childCurrent->value));
					//�z����������ߋ�̃L�[�ƍ�����I�u�W�F�N�g�̃y�A���i�[
					arrayJson.push_back(make_pair("", objectEle));
					//�Z��Ɉړ�
					childCurrent = childCurrent->under;
				}
				//�q�łł�����̔z��ւ̃L�[������܂ł̃L�[�͂����Ɋi�[����
				json.put_child(acsesskey, arrayJson);
			}
			//�q�����鎞
			else if (nullptr != cell->right && cell->right->isValid()) //�q���ʏ�ʂ肠�鎞
			{
				//�q�ɂ��čs���̂ŊK�w�̒l��+1
				level++;
				//�q�ɂ��čċA�������s��
				CreateJSON(cell->right, json);
				//�q�ɂ��Ĕ����o�����̂ŊK�w�̒l�����ɖ߂�
				level--;
			}
			//�ŉ��w�̒l�̎�
			else {
				//����܂ł̃L�[�z���Ɋi�[����
				json.put(acsesskey, constants.SjistoUTF8(cell->value));
			}
			//���̌Z��ֈړ�����
			cell = cell->under;
		}
	}
	catch (std::exception& e) {
		//
		string Message = "�K�w�F" + to_string(level) + "�@�l�F" + cell->key;
		//
		throw exception(Message.c_str());
	}
}


