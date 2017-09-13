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
�֐���:run
�T�v:�������Ǝ葱�����ꊇ�ōs���֐�
����:�Ȃ�
�ԋp�l:�Ȃ�
�쐬��:���c�C�V
�쐬��:9��5��
*/
void JsonLoader::run()
{
	//�������֐������s
	this->JsonLoader::init();
	//�ǂݍ��݂��s���֐������s
	this->JsonLoader::job();
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
	vector<string> temp(15);

	keyHierarchyArray = temp;
	//previousRowData = temp;

	//�Z�b�g���ꂽ�t�@�C���p�X���擾
	std::string path = this->jsonmanager->getJsonFilePath();
	//���̃p�X��json�ǂݍ���
	read_json(path, jsonmanager->json);
	//���K�w�ڂ��̐��l��0�Ń��Z�b�g
	jsonLevel = 0;
	//�ǂ݂��߂Ă��Ȃ�������
	if (jsonmanager->json.empty()) {
		//�ǂ݂��߂Ă��Ȃ��������Ƃ�\��
		cout << "json couldn't read";
	}
	else {
		stringstream ss;
		write_json(ss, jsonmanager->json);
		cout << ss.str();
	}
}

/*
�֐���:job
�T�v:�葱�����s���֐�
����:�Ȃ�
�ԋp�l:�Ȃ�
�쐬��:���c�C�V
�쐬��:9��5��
*/
void JsonLoader::job()
{
	//���ۂ�json��ǂݍ���
	this->loadJson(jsonmanager->json);
}

/*
�K�w�̃L�[�Q����K�v�ȕ������������o���֐�
9��12��(��)
���c�C�V
*/
vector<string> keyRemvFromHierarchy(const vector<string>& hierarchy, int jsonlevel) {
	return vector<string>(hierarchy.begin(), hierarchy.begin() + jsonlevel + 1);
}

/*
�K�w�̃L�[������͂���Ďg���镔�������o���֐�
*/
int keySize(const vector<string>& temp) {
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] == "") {
			return i;
		}
	}
}

/*
�֐���:isSameRow
�T�v:�O�̗v�f�Ɣ�ׂē����s�̂��̂��ǂ������肷��֐�
����:vector<string> previous, vector<string> thistime�@�O��ƍ���̃L�[�Q
�ԋp�l:bool�@�����s���ǂ����̐^���l
�쐬��:9��12��(��)
�쐬��:���c�C�V
*/
bool JsonLoader::isSameRow(const vector<string> & previous, const vector<string>& thistime) {
	//���߂ĂȂ�
	if (previous.size() == 0) {
		//���s���s��Ȃ��Ă����悤��true��Ԃ�
		return true;
	}
	else {
		//�O��ƍ���̃L�[�̐����擾
		int preSize = keySize(previous);
		int thisSize = keySize(thistime);

		//�傫���ق��̒l�擾
		int maxComp = preSize > thisSize ? preSize : thisSize;
		//�����l�̐����擾���邽�߂̕ϐ�
		int sameNumber = 0;
		//�傫���ق��̗v�f�����J��Ԃ�
		for (int i = 0; i < maxComp; i++) {
			//�O��ƍ���ňႤ�l�Ȃ�
			if (previous[i] != thistime[i]) {
				//���܂œ������������擾
				sameNumber = i;
				//�l��������̂Ń��[�v�𔲂���
				break;
			}
		}
		//���������ő傩��2�������l���傫�����
		if (sameNumber >= maxComp - 2) {
			//�����s�Ȃ̂�true��Ԃ�
			return true;
		}
		//�����łȂ����
		else {
			//false��Ԃ�
			return false;
		}
	}
}

int previousType = 2;
const int typeArray = 1;
const int typeNormal = 2;

/*
�֐���:loadJson
�T�v:�w���JSON�t�@�C����ǂݍ���Ŋe����z�u���Ă����֐�
����:boost::property_tree::ptree json :json�I�u�W�F�N�g
�ԋp�l:�Ȃ�
�쐬��:���c�C�V
�쐬��:9��5��
*/
void JsonLoader::loadJson(boost::property_tree::ptree json)
{
	//�󂯎����json�ɂ��đ��K�w�S����
	BOOST_FOREACH(const ptree::value_type& child, json) {
		//�L�[�������̊K�w�̃L�[�Ƃ��Ċi�[
		keyHierarchyArray[jsonLevel] = child.first;
		for (int i = jsonLevel + 1; i < 15; i++) {
			keyHierarchyArray[i] = "";
		}

		//�z��̎�
		if (child.first == "") {
			if (previousType != typeArray) {
				//���̍s�ɍs�����߂ɃC���N�������g
				setGridRowN++;
				jsonmanager->setGridRowLen(setGridRowN);
				if (jsonmanager->getGridColLength() < setGridColN) {
					jsonmanager->setGridMaxColLen(setGridColN);
				}
				//���s����̂ŗ�̒l��0��
				setGridColN = 0;
			}
			
			//�v�f���I�u�W�F�N�g�̎�
			if (child.second.data().empty()) {
				//�I�u�W�F�N�g�������ׂđ���
				BOOST_FOREACH(const ptree::value_type& arrayObject, child.second) {
					//�l���擾
					string value = arrayObject.second.data();
					//�擾�����l���Z�b�g����
					jsonmanager->setGrid(setGridRowN, setGridColN, value);
					//�Z���̏����Z�b�g����
					jsonmanager->setGridData(setGridRowN, setGridColN, keyRemvFromHierarchy(keyHierarchyArray, jsonLevel));
					//���A�ƂȂ�̗�ɍs�����߂ɗ�̒l���C���N�������g
					setGridColN++;

				}	//�I�u�W�F�N�g���I��
				//���̍s�ɍs�����߂ɃC���N�������g
				setGridRowN++;
				jsonmanager->setGridRowLen(setGridRowN);
				if (jsonmanager->getGridColLength() < setGridColN) {
					jsonmanager->setGridMaxColLen(setGridColN);
				}
				//���s����̂ŗ�̒l��0��
				setGridColN = 0;
				previousRowData = keyHierarchyArray;
			}
			//�z��̗v�f���I�u�W�F�N�g�ł͂Ȃ��A�ʏ�̗v�f
			else {
				std::string value = child.second.data();
				//�擾�����l��\�ɃZ�b�g
				jsonmanager->setGrid(setGridRowN, setGridColN, value);
				//�Z���̏����Z�b�g
				jsonmanager->setGridData(setGridRowN, setGridColN, keyRemvFromHierarchy(keyHierarchyArray, jsonLevel));
				//���s����
				setGridRowN++;
				if (jsonmanager->getGridColLength() < setGridColN) {
					jsonmanager->setGridMaxColLen(setGridColN);
				}
				setGridColN = 0;
				jsonmanager->setGridRowLen(setGridRowN);
				previousRowData = keyHierarchyArray;
			}//�z��̒ʏ�v�f�I��

			previousType = typeArray;
		}
		//value���I�u�W�F�N�g
		else if (!child.second.empty() && child.second.data().empty()) {
			//�K�w��\���ϐ���+1
			this->jsonLevel += 1;
			//���̃I�u�W�F�N�g�ɂ��čċA����
			loadJson(child.second);
			//�����o������ϐ���-1����
			this->jsonLevel -= 1;			
		}
		//�q�ł��z��ł��Ȃ��Ƃ�(�ŉ��w��value�����o����Ƃ�)
		else {
			//value���擾
			std::string gridvalue = child.second.data();
			//�O��ƍ�����ׂē����s�łȂ��Ɣ��肳�ꂽ��
			if (previousType != typeArray && !isSameRow(previousRowData, keyHierarchyArray)) {
				//���s���Ď��̍s�֊i�[����悤��
				setGridRowN++;
				jsonmanager->setGridRowLen(setGridRowN);
				if (jsonmanager->getGridColLength() < setGridColN) {
					jsonmanager->setGridMaxColLen(setGridColN);
				}
				//���s�Ȃ̂ŗ�̒l��0��
				setGridColN = 0;
			}
			//�擾����value���Z�b�g
			jsonmanager->setGrid(setGridRowN, setGridColN, gridvalue);
			//�K�w�̃L�[�̌�납��2�Ԗڂ���Ō�܂Łi�ŐV�̃L�[2�j�̃L�[�Q������value�̏��Ƃ��Ċi�[
			jsonmanager->setGridData(setGridRowN, setGridColN, keyRemvFromHierarchy(keyHierarchyArray, jsonLevel));

			//���̗��
			setGridColN++;
			//����̏���ۑ����Ď��̃m�[�h��
			previousRowData = keyHierarchyArray;

			previousType = typeNormal;
		}
	}

	if (jsonLevel == 0) {
		//jsonmanager->setGridRowLen(setGridRowN);
		setGridColN = 0;
		setGridRowN = 0;
	}
}
