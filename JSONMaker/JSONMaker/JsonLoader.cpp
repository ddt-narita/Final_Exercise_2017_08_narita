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
	hierarchyKeys = vector<string>(15);

	//�Z�b�g���ꂽ�t�@�C���p�X���擾
	std::string path = this->jsonmanager->getJsonFilePath();
	//���̃p�X��json�ǂݍ���
	read_json(path, jsonmanager->json);
	//���K�w�ڂ��̐��l��0�Ń��Z�b�g
	jsonLevel = 0;
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
	this->hierarchyKeys.clear();
	this->cellKeys.clear();
	this->preCellKeys.clear();
}

/*
�K�w�̃L�[�Q����K�v�ȕ������������o���֐�
9��12��(��)
���c�C�V
*/
vector<string> keyRemvFromHierarchy(const vector<string>& hierarchy, int jsonlevel) {
	return vector<string>(hierarchy.begin(), hierarchy.begin() + jsonlevel + 1);
}

void JsonLoader::returnRow() {
	//���̍s�ɍs�����߂ɃC���N�������g
	setGridRowN++;
	//
	this->jsonmanager->setGridRowLen(setGridRowN);
	//
	if (jsonmanager->getGridColLength() < setGridColN) {
		//
		this->jsonmanager->setGridColLen(setGridColN);

	}
	//���s����̂ŗ�̒l��0��
	setGridColN = 0;
}


/*
�֐���
�T�v
*/
std::vector<std::string> JsonLoader::getNodes()
{
	//
	vector<string> retVec;
	//
	BOOST_FOREACH(const ptree::value_type& child, jsonmanager->json) {
		//
		retVec.push_back(child.first);
	}
	//
	return retVec;
}



string preKey;
/*
�֐���:loadJson
�T�v:������JSON�t�@�C����ǂݍ���ŕ\�ɃZ�b�g����֐�
����:property_tree json�@JSON�t�@�C�����̑I�����ꂽ�m�[�h
�ԋp�l:����
�쐬��:���c�C�V
�쐬��:9��13��(��)
*/
void JsonLoader::loadJson(boost::property_tree::ptree json) {
	//�󂯎����Json�ɂ��đ��K�w���[�v
	BOOST_FOREACH(const ptree::value_type& child, json) {
		//�L�[���K�w�̃L�[�Ɋi�[
		hierarchyKeys[jsonLevel] = child.first;
		//�z��̎�
		if (child.first == "") {
			//�v�f���I�u�W�F�N�g�̎�
			if (child.second.data().empty()) {
				BOOST_FOREACH(const ptree::value_type& arrayObject, child.second) {
					//�L�[���K�w�̃L�[�Q�Ɋi�[
					hierarchyKeys[jsonLevel + 1] = arrayObject.first;
					//�l��\�o�͕��Ƃ��Ċi�[
					jsonmanager->setGrid(setGridRowN, setGridColN, arrayObject.second.data());
					//�L�[�Q���Z���̏��Ƃ��Ċi�[
					jsonmanager->setGridData(setGridRowN, setGridColN, keyRemvFromHierarchy(hierarchyKeys, jsonLevel + 1));
					//���̗�Ɉړ�
					setGridColN++;
				}

				returnRow();
			}
			//�v�f���I�u�W�F�N�g�ł͂Ȃ��ʏ�̗v�f
			else {
				//���̊K�w�܂ł̃L�[�Q������̃L�[�Ƃ��ĕۊ�
				cellKeys = vector<string>(hierarchyKeys.begin(), hierarchyKeys.begin() + jsonLevel + 1);

				//�z��������L�[�����Ɋi�[
				hierarchyKeys[jsonLevel + 1] = constants.KEY_ISARRAY;
				//�O�̃Z���Ɣ�ׂē����s���ǂ������肷��
				if (!isSameRow(cellKeys, preCellKeys) || jsonLevel == 1) {
					returnRow();
					preKey == "";
				}
				//�l��\�o�͕��Ƃ��Ċi�[
				jsonmanager->setGrid(setGridRowN, setGridColN, child.second.data());
				//�L�[�Q���Z���̏��Ƃ��Ċi�[
				jsonmanager->setGridData(setGridRowN, setGridColN, keyRemvFromHierarchy(hierarchyKeys, jsonLevel + 1));
				//���̗��
				setGridColN++;
				preKey = "disp";
			} //�z����v�f�I��
		}
		//�q�����鎞
		else if (!child.second.empty() && child.second.data().empty()) {
			//����ɐ��邽�߂ɊK�w�̒l���C���N�������g
			jsonLevel++;
			//�q�ɑ΂��čċA����
			loadJson(child.second);
			//�����o������K�w�̒l�����Ƃɖ߂�
			jsonLevel--;
		}
		//�z��ł��q�ł��Ȃ��Ƃ�(�ŉ��w�̒l)
		else {
			//���̊K�w�܂ł̃L�[�Q������̃L�[�Ƃ��ĕۊ�
			cellKeys = vector<string>(hierarchyKeys.begin(), hierarchyKeys.begin() + jsonLevel + 1);
			//�O�̃Z���Ɣ�ׂē����s���ǂ������肷��
			if (!isSameRow(cellKeys, preCellKeys)) {
				returnRow();
				preKey == "";
			}
			//�\�̒l�Ƃ��ăZ�b�g
			jsonmanager->setGrid(setGridRowN, setGridColN, child.second.data());
			//�K�w�̃L�[����f�[�^���Z�b�g
			jsonmanager->setGridData(setGridRowN, setGridColN, keyRemvFromHierarchy(hierarchyKeys, jsonLevel));
			//�\�ɕ\����������̂Ƃ��ăZ�b�g���邽�߂̕ϐ������̗��
			setGridColN++;

		}
		//���ɍs���O�ɍ���̃L�[�Q��O��̃L�[�Ƃ��ĕۊ�
		preCellKeys = cellKeys;
	} //�󂯎����JSON�̑��K�w����
}


bool JsonLoader::isSameRow(const vector<string> &thistime, const vector<string> &pre) {
	int thisSize = thistime.size();
	int preSize = pre.size();
	//��ԏ��߂ł܂��O�̃L�[���Ȃ��Ƃ�
	if (preSize < 1) {
		//�����s�Ōp��
		return true;
	}

	//��r����L�[�̃C���f�b�N�X���擾�i�T�C�Y�̑傫���ق��̔z��̌�납��3�Ԗڂ̃L�[�ɂ��Ĕ�r�j
	int compNum = (thisSize > preSize ? thisSize : preSize) - 3;

	//��ԏ�̃L�[���Ⴆ�Ή��s
	if (thistime[0] != pre[0]) {
		//���s�ł�
		return false;
	}
	if (compNum < 0) {
		return true;
	}
	//�O�񂩁A����̔z�񂪃C���f�b�N�X��菬�����Ƃ������s��
	if (preSize < compNum || thisSize < compNum) {
		return true;
	}
	//��ׂ�ׂ��L�[�̂Ƃ��낪����Ă���Ή��s
	else if (thistime[compNum] != pre[compNum]) {
		return false;
	}
	return true;
}