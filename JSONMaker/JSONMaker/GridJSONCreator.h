#pragma once
#ifndef __GRID_JSON_CREATOR
#define __GRID_JSON_CREATOR

#include "JSONManager.h"
#include "ChainData.h"
#include "CLIConstants.h"

class GridJSONCreator
{
private:
	std::vector<std::string> keyHierarchy;
	int level;
public:
	JSONManager* jsonmanager;
	GridJSONCreator();
	~GridJSONCreator();

	//JSON�쐬���s���֐�
	void job(ChainData* cell);
	//�A�N�Z�X���邽�߂̃L�[��������쐬����
	std::string createAcsessKey(std::vector<std::string> keyarray, int level, std::string delimiter);
	std::string createErrorMessage(ChainData* cell, std::string errorMessage);
	//�Z��̃Z�����`�F�b�N����
	void checkBroKey(ChainData* cell);
	//�z���JSON���쐬����
	void createArrayJson(std::string acsessKey, ChainData* cellToArray, boost::property_tree::ptree& json);
	//�I�u�W�F�N�g�z���JSON���쐬����
	void createObjectArrayJson(std::string acsessKey, ChainData* cellToObjectArray, boost::property_tree::ptree& json);
	//���ۂ�JSON���쐬����֐�
	void CreateJSON(ChainData* cell, boost::property_tree::ptree& json);
};

#endif // !__GRID_JSON_CREATOR