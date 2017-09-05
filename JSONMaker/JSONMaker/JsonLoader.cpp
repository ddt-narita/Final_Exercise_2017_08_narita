#include "JsonLoader.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <iostream>
#include "Constants.h"

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
	this->JsonLoader::init();
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
	string path = this->getJsonFilePath();
	read_json(path, json);

	jsonLevel = 0;

	if (json.empty()) {
		cout << "json couldn't read";
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
	this->loadJson(json);
}

/*
�֐���:getJsonFilePath
�T�v:�w�肳�ꂽjson�t�@�C���̃p�X�������o��Env����擾����֐�
����:�Ȃ�
�ԋp�l:string path�@�p�X
�쐬��:���c�C�V
�쐬��:9��5��
*/
std::string JsonLoader::getJsonFilePath()
{
	return std::string();
}


/*
�֐���:isSameParentNumber
�T�v:�e�̃L�[�Q���m���ׂē����v�f�ł������Ԃ��֐�
����:vector<string>previous:��r�Ώۂ̑O��̃L�[�Q�@ vector<string> previous:����̃L�[�Q
�ԋp�l:int retSameCount �����l�̗v�f�̐�
�쐬��:���c�C�V
�쐬��:9��5��
*/
int isSameParentNumber(const vector<string> &previous, const vector<string>& thistime) {

	//�ԋp���鉽���������i�[����ϐ�
	int retSameCount;

	//�����̂ǂ��炩�̔z���
	for (retSameCount = 0; retSameCount < previous.size(); retSameCount++) {
		//�z��̗v�f���ׂĈقȂ�l�̎�
		if (previous[retSameCount] != thistime[retSameCount]) {
			//���[�v�𔲂��A���̎��̒l��ԋp����
			break;
		}
	}

	return retSameCount;
}


/*
�֐���:loadJson
�T�v:�w���JSON�t�@�C����ǂݍ���Ŋe����z�u���Ă����֐�
����:boost::property_tree::ptree ptree :json�I�u�W�F�N�g
�ԋp�l:�Ȃ�
�쐬��:���c�C�V
�쐬��:9��5��
*/
void JsonLoader::loadJson(ptree json)
{
	//�󂯎����json�ɂ��đ��K�w�S����
	BOOST_FOREACH(const ptree::value_type& child, json) {
		//�L�[�������̊K�w�̃L�[�Ƃ��Ċi�[
		hierarchy.push_back(child.first);

		//value���I�u�W�F�N�g
		if (!child.second.empty() && child.second.data().empty()) {

			//�K�w��\���ϐ���+1
			this->jsonLevel += 1;
			//���̃I�u�W�F�N�g�ɂ��čċA����
			loadJson(child.second);
			//�����o������ϐ���-1����
			this->jsonLevel -= 1;
			//��Ԍ��̊K�w�̃L�[����菜��
			hierarchy.pop_back();
		}
		//�z��̎�
		else if (child.first == "") {
			//�z����擾
			ptree arraytree = child.second;
			//�z��̗v�f�I�u�W�F�N�g��S����
			BOOST_FOREACH(const ptree::value_type& arrayNode, arraytree) {
				//�v�f���I�u�W�F�N�g�̎�
				if (!arrayNode.second.empty() && arrayNode.second.data().empty()) {
					//�I�u�W�F�N�g�������ׂđ���
					BOOST_FOREACH(const ptree::value_type& arrayObject, arrayNode.second) {
						//�Z���̃f�[�^�Ƃ��ăZ�b�g���邽�߂̔z��
						vector<string> gridDataForSet(2);
						//�R���e���c�L�[�Ɍ��݂̃L�[�����Z�b�g
						gridDataForSet[constants.CONTENT_KEY_INDEX] = arrayObject.first;
						//�v�f��value���擾
						boost::optional<std::string> value = arrayObject.second.get_optional<std::string>(arrayObject.first);
						//�擾�����l���Z�b�g����
						setGrid(setGridRowN,setGridColN, value.get());

						//���A�ƂȂ�̗�ɍs�����߂ɗ�̒l���C���N�������g
						setGridColN++;

					}	//�I�u�W�F�N�g���I��
//�s�̏����i�[����(�����v�C��)
					this->setGridRowData(setGridRowN,hierarchy);
					//���̍s�ɍs�����߂ɃC���N�������g
					setGridRowN++;
					//���s����̂ŗ�̒l��0��
					setGridColN = 0;
					
				}
				//�v�f���I�u�W�F�N�g�ł͂Ȃ��A�ʏ�̗v�f
				else {
					//value���擾����
					boost::optional<std::string> value = arrayNode.second.get_optional<std::string>(arrayNode.first);
					//�擾�����l��\�ɃZ�b�g
					setGrid(setGridRowN, setGridColN, value.get());
					//�s�̏����i�[����
					setGridRowData(setGridRowN, hierarchy);
					//���s����
					setGridRowN++;
					setGridColN = 0;

				}
			}	//�z��̗v�f�I��
		}//�q�ł��z��ł��Ȃ��Ƃ�(�ŉ��w��value�����o����Ƃ�)
		else {
			//value���擾
			boost::optional<std::string> value = child.second.get_optional<std::string>(child.first);

			//����̊K�w�̃L�[�ƑO��̃L�[���œ������̂��K�w�̐�-1���傫��(�Ⴄ��������̂�)
			if (isSameParentNumber(previousRowData, hierarchy) > jsonLevel - 1) {
				setGridRowData(setGridRowN, hierarchy);
				//���s���Ď��̍s�֊i�[����悤��
				setGridRowN++;
				//���s�Ȃ̂ŗ�̒l��0��
				setGridColN = 0;
			}
			//�擾����value���Z�b�g
			setGrid(setGridRowN,setGridColN, value.get());
			setGridData(setGridRowN,setGridColN, hierarchy);
			//���̗��
			setGridColN++;
			//����̏���ۑ����Ď��̃m�[�h��
			previousRowData = hierarchy;
		}
	}
}

vector<string> hierarToRowData(const vector<string>& hier) {
	vector<string> rowdata(hier.size() - 2);
	for (int i = 0; i < rowdata.size(); i++) {

	}
}

vector<string> hierarToGridData(const vector<string>& hier) {
	vector<string> gridData(2);
	for (int i = 0; i < 2; i++) {

	}
}