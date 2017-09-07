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
	previousRowData = temp;

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
�֐���:getJsonFilePath
�T�v:�w�肳�ꂽjson�t�@�C���̃p�X�������o��Env����擾����֐�
����:�Ȃ�
�ԋp�l:string path�@�p�X
�쐬��:���c�C�V
�쐬��:9��5��
*/




/*
�֐���:isSameParentNumber
�T�v:�e�̃L�[�Q���m���ׂē����v�f�ł������Ԃ��֐�
����:vector<string>previous:��r�Ώۂ̑O��̃L�[�Q�@ vector<string> previous:����̃L�[�Q
�ԋp�l:int retSameCount �����l�̗v�f�̐�
�쐬��:���c�C�V
�쐬��:9��5��
*/
int isSameParentNumber(const vector<string> &previous, const vector<string>& thistime) 
{
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
	//����������������ԋp����
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
		keyHierarchyArray[jsonLevel] = child.first;

		//�z��̎�
		if (child.first == "") {
			//�z����擾
			ptree arraytree = child.second;
			//�z��̗v�f�I�u�W�F�N�g��S����
			BOOST_FOREACH(const ptree::value_type& arrayNode, arraytree) {
				//�v�f���I�u�W�F�N�g�̎�
				if (arrayNode.first != "") {
					//�I�u�W�F�N�g�������ׂđ���
					BOOST_FOREACH(const ptree::value_type& arrayObject, arrayNode.second) {
						//�Z���̃f�[�^�Ƃ��ăZ�b�g���邽�߂̔z��
						vector<std::string> gridDataForSet(2);
						//�R���e���c�L�[�Ɍ��݂̃L�[�����Z�b�g
						gridDataForSet[constants.CONTENT_KEY_INDEX] = arrayObject.first;
						//�v�f��value���擾
						boost::optional<std::string> value = arrayObject.second.get_optional<std::string>(arrayObject.first);
						//�擾�����l���Z�b�g����
						jsonmanager->setGrid(setGridRowN, setGridColN, value.get());
						//���A�ƂȂ�̗�ɍs�����߂ɗ�̒l���C���N�������g
						setGridColN++;

					}	//�I�u�W�F�N�g���I��
						//�z��ł��邱�Ƃ������L�[���K�w�̃L�[�z��ɒǉ�
					keyHierarchyArray.push_back(constants.KEY_IS_ARRAY);
					//�s�̏����i�[����(�z��Ȃ̂ł��̂܂�)
					jsonmanager->setGridRowData(setGridRowN, vector<string>(keyHierarchyArray.begin(),keyHierarchyArray.begin() + jsonLevel + 1));
					//�z��ł��邱�Ƃ������L�[����菜��(�K�w�̃L�[�Ƃ͊֌W���Ȃ�����)
					keyHierarchyArray.pop_back();
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
					//value���擾����
					//boost::optional<std::string> value = arrayNode.second.get_optional<std::string>(arrayNode.first);
					std::string value = arrayNode.second.data();
					
					//�擾�����l��\�ɃZ�b�g
					jsonmanager->setGrid(setGridRowN, setGridColN, value);
					//�z��ł��邱�Ƃ������L�[��ǉ�
					keyHierarchyArray.push_back(constants.KEY_IS_ARRAY);
					//�s�̏����i�[����
					jsonmanager->setGridRowData(setGridRowN, keyHierarchyArray);
					//�z��ł��邱�Ƃ������L�[����菜��(�K�w�̃L�[�Ƃ͖��֌W�Ȃ���)
					keyHierarchyArray.pop_back();
					//���s����
					setGridRowN++;
					if (jsonmanager->getGridColLength() < setGridColN) {
						jsonmanager->setGridMaxColLen(setGridColN);
					}
					setGridColN = 0;
					jsonmanager->setGridRowLen(setGridRowN);
					previousRowData = keyHierarchyArray;
				}
			}	//�z��̗v�f�I��
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

			//����̊K�w�̃L�[�ƑO��̃L�[���œ������̂��K�w�̐�-1���傫��(�Ⴄ��������̂�)
			int sameParentNumber = isSameParentNumber(previousRowData, keyHierarchyArray);
			//�O��ƍ���œ����L�[�̐����K�w�̐��Ƃ̍���1(�O��ƍ���ňقȂ�L�[��1�̂�)
			if (sameParentNumber != 0 && sameParentNumber >= jsonLevel - 1) {
				//�K�w�̃L�[����ŐV2���������z����s�̃f�[�^�Ƃ��ăZ�b�g
				jsonmanager->setGridRowData(setGridRowN, vector<std::string>(keyHierarchyArray.begin(), keyHierarchyArray.end() - 2));
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
			jsonmanager->setGridData(setGridRowN, setGridColN, vector<std::string>(keyHierarchyArray.end() - 2, keyHierarchyArray.end()));

			//���̗��
			setGridColN++;
			//����̏���ۑ����Ď��̃m�[�h��
			previousRowData = keyHierarchyArray;
		}
		
	}
}