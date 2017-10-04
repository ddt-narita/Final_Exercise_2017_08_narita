#include "JsonLoader.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <iostream>
#include "Constants.h"
#include <sstream>
#include <codecvt>
#include <locale>



using namespace std;
using namespace boost::property_tree;

JsonLoader::JsonLoader()
{
}


JsonLoader::~JsonLoader()
{
}


/*
�֐���:
�T�v:���������s���֐�
����:�Ȃ�
�ԋp�l:�Ȃ�
�쐬��:���c�C�V
�쐬��:9��5��
*/
void JsonLoader::init()
{
	//�Z�b�g���ꂽ�t�@�C���p�X���擾
	std::string path = this->jsonmanager->getJsonFilePath();
	//���̃p�X��json�ǂݍ���
	read_json(path, jsonmanager->json);
}

/*
�֐���:job
�T�v:�葱�����s���֐�
����:�Ȃ�
�ԋp�l:�Ȃ�
�쐬��:���c�C�V
�쐬��:9��5��
*/
void JsonLoader::job(string jsonnode, ChainData* cell)
{
	//�I�����ꂽ�m�[�h���擾
	ptree node = jsonmanager->json.get_child(jsonnode);

	cell->key = jsonnode;
	//���̃m�[�h�ɑ΂��ēǂݍ��ݏ������s��
	this->loadJson(node, cell);
}



/*
�֐���:loadJson
�T�v:������JSON�t�@�C����ǂݍ���ŕ\�ɃZ�b�g����֐�
����:property_tree json�@JSON�t�@�C�����̑I�����ꂽ�m�[�h
�ԋp�l:����
�쐬��:���c�C�V
�쐬��:9��13��(��)
*/
void JsonLoader::loadJson(boost::property_tree::ptree json, ChainData* cell)
{
	cell->addRight(new ChainData());
	ChainData * current = cell->right;

	BOOST_FOREACH(const ptree::value_type& child, json) {
		current->key = constants.UTF8toSjis(child.first);
		//�z��̎�
		if ("" == child.first) {
			//�v�f���I�u�W�F�N�g�̎�
			if (child.second.data().empty()) {
				//�q���쐬����
				current->addRight(new ChainData());
				//�q�Ɉړ����ăJ�����g�Ƃ���
				ChainData* arrayCurrent = current->right;

				//�I�u�W�F�N�g���̗v�f�����J��Ԃ�
				BOOST_FOREACH(const ptree::value_type& arrayElement, child.second) {
					//�L�[���i�[
					arrayCurrent->key = constants.UTF8toSjis(arrayElement.first);
					//�l���i�[
					arrayCurrent->value = constants.UTF8toSjis(arrayElement.second.data());
					//����쐬����
					arrayCurrent->addUnder(new ChainData());
					//�J�����g���쐬������ֈړ�
					arrayCurrent = arrayCurrent->under;
				}
				//�Ō�܂ŗ�����]�v�ɂ���ꂽ����w���Ă����Z�̃|�C���^���i�����w���悤��
				arrayCurrent->upper->under = nullptr;
				//�Ō�̒���폜
				delete arrayCurrent;
			}
			//�ʏ�̔z��̎�
			else {
				//�L�[���i�[(�󕶎�)
				current->key = constants.UTF8toSjis(child.first);
				//�l���i�[����
				current->value = constants.UTF8toSjis(child.second.data());
			}
		}
		//�q�����鎞
		else if (!child.second.empty() && child.second.data().empty()) {
			//�q�ɂ��čċA����
			loadJson(child.second, current);
		}
		//�ŉ��w�̒l�̎�
		else if (child.second.empty() && !child.second.data().empty()) {
			//���̉E�̃Z���̒l���Ƃ��Ċi�[
			current->value = constants.UTF8toSjis(child.second.data());
		}
		//
		current->addUnder(new ChainData());
		current = current->under;
	}
	//�Ō�܂ōs������]�v�ȍŌ�ɒǉ����ꂽ�Z�����w���|�C���^���i�����w���悤�ɂ���
	current->upper->under = nullptr;
	//�]�v�ȃZ�����폜����
	delete current;


}

/*
�֐���:getNodes
�T�v:�擾����JSON����ǂ̃m�[�h�ɂ��ĕ\�����邩��I�����邽�߂Ƀm�[�h�̔z����쐬����
����:����
�ԋp�l:vector<string> Nodes�@�m�[�h�Q
�쐬��:9��25��(��)
�쐬��:���c�C�V
*/
std::vector<std::string> JsonLoader::getNodes(ptree json)
{
	//�ԋp���邽�߂̔z��
	vector<string> retVec;
	//�擾����JSON�̑��K�w�����[�v
	BOOST_FOREACH(const ptree::value_type& child, json) {
		//�m�[�h�����ǂ�ǂ���ɒǉ����Ă���
		retVec.push_back(child.first);
	}
	//�o���オ�����z���ԋp����
	return retVec;
}
