# define BOOST_ENABLE_ASSERT_HANDLER
#include <boost/assert.hpp>

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

namespace boost {

	/*
	�u�[�X�Ƃ̃A�T�[�g���`
	��ɔz��ȊO�ŋ�̃L�[�Ɏq���i�[���悤�Ƃ����Ƃ��ɋN����
	*/
	void assertion_failed(const char* expr, const char* function, const char* file, long line)
	{
		//��O�𑗏o����
		throw std::exception();
	}
}



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
	//�K�w�̃L�[�Q���i�[����z��
	keyHierarchy = vector<string>(15);
	//�K�w�̒l
	level = 0;
	//�������ޑΏ�
	ptree json;
	//�����̃Z�����珑�����ݑΏۂ�JSON����������
	CreateJSON(cell, json);

	//�K�w�̃L�[�Q�z����N���A
	keyHierarchy.clear();
	//�K�w�̒l�����ɖ߂�
	level = 0;
	//����JSON�I�u�W�F�N�g�������o��
	write_json("data.json", json);
	//�������񂾃I�u�W�F�N�g���N���A
	json.clear();
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
			if ("" != acsesskey && "" != keyarray[i]) {
				//�A�N�Z�X�\�Ȃ悤�ɃJ���}�ŋ�؂�
				acsesskey += ".";
			}
			//�L�[���ォ�珇�Ɍp�������Ă���
			acsesskey += keyarray[i];
		}
	}
	//��O�����������Ƃ�
	catch (exception& e) {
		int i = 0;
	}
	return acsesskey;
}


/*
�֐���: createArrayJson
�T�v:�z���JSON���쐬����
����:string acsesskey �쐬����JSON���i�[����p�X
ChainData* cell�@�z��ւ̐擪�̃Z��
ptree& json	JSON���������ޑΏ�
�ԋp�l:�Ȃ�
�쐬��:10��2��(��)
�쐬��:���c�C�V
*/
void GridJSONCreator::createArrayJson(std::string acsessKey, ChainData * cellToArray, ptree & json)
{
	//�q���擾���Ďq�J�����g�Ƃ���
	ChainData* childCurrent = cellToArray->right;
	//�z���JSON���i�[���邽�߂�JSON�I�u�W�F�N�g
	ptree arrayJson;
	//�z��̗v�f���i�[���邽�߂�JSON�I�u�W�F�N�g
	ptree objectEle;
	//�q�̐������J��Ԃ�
	for (int i = 0; i < cellToArray->getChildCount(); i++) {
		//�v�f�Ƃ��ăL�[�ƒl���i�[����
		objectEle.put(constants.SjistoUTF8(childCurrent->key), constants.SjistoUTF8(childCurrent->value));
		//�z����������ߋ�̃L�[�ƍ�����I�u�W�F�N�g�̃y�A���i�[
		arrayJson.push_back(make_pair("", objectEle));
		//�Z��Ɉړ�
		childCurrent = childCurrent->under;
	}
	//�q�łł�����̔z��ւ̃L�[������܂ł̃L�[�͂����Ɋi�[����
	json.put_child(acsessKey, arrayJson);
}

/*
�֐���:createObjectJson
�T�v:�I�u�W�F�N�g�z���JSON���쐬����
����:string acsesskey�@�쐬����JSON���i�[����p�X
	ChainData* cell�@�I�u�W�F�N�g�z��ւ̐擪�̃Z��
	ptree& json	JSON���������ޑΏ�
�ԋp�l:�Ȃ�
�쐬��:10��2��(��)
�쐬��:���c�C�V
*/
void GridJSONCreator::createObjectArrayJson(std::string acsessKey, ChainData* cellToObjectArray, ptree& json) {
	//�q���擾���Ďq�J�����g��
	ChainData* childCurrent = cellToObjectArray->right;
	//�I�u�W�F�N�g�z����i�[����JSON�I�u�W�F�N�g
	ptree objectArray;
	//�q�̐������J��Ԃ�
	for (int i = 0; i < cellToObjectArray->getChildCount(); i++) {
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
	json.put_child(acsessKey, objectArray);
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
		while (nullptr != cell) {
			//�K�w�̃L�[�ɒl������A�K�w���ŏ��̎�(2�ڂ̃g�b�v�m�[�h)
			if (keyHierarchy[0] != "" && level == 0) {
				//��������߂�
				return;
			}
			//�Z�����L���łȂ��Ȃ�
			if (!cell->isValid()) {
				//���̌Z��ֈړ�����
				cell = cell->under;
				//���̉���΂��Ď���
				continue;
			}
			//�l���K�w�̃L�[�Ƃ��ĕۊǂ���
			keyHierarchy[level] = constants.SjistoUTF8(cell->key);
			//���̊K�w�܂ł̃L�[����A�N�Z�X���邽�߂̃L�[��������쐬����
			string acsesskey = createAcsessKey(keyHierarchy, level + 1);
			//�I�u�W�F�N�g�z��ւ̐擪�̃Z���̎�
			if (cell->isCellToObjectArray()) {
				//�I�u�W�F�N�g�z���JSON���쐬����
				createObjectArrayJson(acsesskey, cell, json);
			}
			//�ʏ�z��ւ̃Z���̎�
			else if (cell->isCellToArray()) {
				//�z���JSON���쐬����
				createArrayJson(acsesskey, cell, json);
			}
			//�z���I�u�W�F�N�g�z��łȂ��q�����鎞
			else if (cell->isObject()) //�q���ʏ�ʂ肠�鎞
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
	//��O�����������Ƃ�
	catch (std::exception& e) {
		//���̊K�w�Ƃ��̃Z���̒l���i�[�������b�Z�[�W��p��
		string Message = "�K�w�F" + to_string(level) + "�@�l�F" + cell->key;
		//���b�Z�[�W�ŏ�����������O�𑗏o����
		throw exception(Message.c_str());
	}
}


