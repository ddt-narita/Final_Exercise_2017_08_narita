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
	jsonmanager->grid->Clear();

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
void JsonLoader::job(string jsonnode)
{
	//�I�����ꂽ�m�[�h���擾
	ptree node = jsonmanager->json.get_child(jsonnode);

	//���̃m�[�h�ɑ΂��ēǂݍ��ݏ������s��
	this->loadJson(node);

	//�ǂݍ��݂��I�������͌��݂̍s���񐔂����Z�b�g
	this->jsonmanager->setGridRowLen(setGridRowN);
	setGridColN = 0;
	setGridRowN = 0;
}



/*
�֐���:loadJson
�T�v:������JSON�t�@�C����ǂݍ���ŕ\�ɃZ�b�g����֐�
����:property_tree json�@JSON�t�@�C�����̑I�����ꂽ�m�[�h
�ԋp�l:����
�쐬��:���c�C�V
�쐬��:9��13��(��)
*/
void JsonLoader::loadJson(boost::property_tree::ptree json)
{
	//���K�w�ɂ��ă��[�v
	BOOST_FOREACH(const ptree::value_type& child, json) {
		//���ڂɂ��ăL�[�ƃf�[�^�Q���擾���ăZ�b�g����
		jsonmanager->grid->setGrid(setGridRowN, setGridColN, child.first);
		jsonmanager->grid->setGridData(setGridRowN, setGridColN, child.second);
		setGridColN++;
		//�q�����鎞
		if (!child.second.empty() && child.second.data().empty()) {
			//�q�ɂ��ă��[�v����
			BOOST_FOREACH(const ptree::value_type& chldNodes, child.second) {
				//�q���z��������Ă���Ƃ�
				if ("" == chldNodes.first) {
					//�z����̗v�f�ɂ��ă��[�v����
					BOOST_FOREACH(const ptree::value_type& arrayNode, chldNodes.second) {
						//�z��̗v�f�̃L�[���擾����(�I�u�W�F�N�g�Ȃ�L�[����A�ʏ�v�f�Ȃ�L�[�Ȃ�)
						jsonmanager->setGrid(setGridRowN, setGridColN, arrayNode.first);
						//�z��̗v�f�܂ł̃L�[�Q��
						jsonmanager->setGridData(setGridRowN, setGridColN, (arrayNode.second));
						setGridColN++;
					}
				}
				else {
					//���̎q�̃L�[����\����������̂Ƃ��Ċi�[����
					jsonmanager->grid->setGrid(setGridRowN, setGridColN, chldNodes.first);
					//���̎q�ȉ��̃I�u�W�F�N�g�Ȃǂɂ��Ă̓f�[�^�Ƃ��Ċi�[����
					jsonmanager->grid->setGridData(setGridRowN, setGridColN, chldNodes.second);
					//���̃Z���֍s�����߃C���N�������g
					setGridColN++;
				}
			}
		}
		//���s����
		returnRow();
	}
}

void JsonLoader::returnRow() {
	//���s����̂ō��̍s�̒l���Z�b�g����
	jsonmanager->setGridRowLen(this->setGridRowN);
	//���܂܂ł̍ő�̗񐔂�������̗񂪑����Ƃ�
	if (jsonmanager->getGridColLen() < setGridColN) {
		//�ő�̗񐔂Ƃ��ė񐔂�ۊǂ���
		jsonmanager->setGridColLen(setGridColN);
	}
	//���s����̂ŗ�̓��Z�b�g
	setGridColN = 0;
	//���̍s�֍s�����߂ɍs�̒l���v���X�ꂷ��
	setGridRowN++;

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
