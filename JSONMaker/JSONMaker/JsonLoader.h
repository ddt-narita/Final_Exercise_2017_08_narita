#pragma once
#ifndef __JSON_LOADER
#define __JSON_LOADER

#include "JSONManager.h"
#include <vector>

class JsonLoader
{
private:
	//�Z�b�g����ۂ�BOOST_EACH�Ń��[�v���邽�߁A���[�v�ϐ����O�ɒu��
	//�Z�b�g����ۂɂǂ̍s�ɃZ�b�g���邩�w���ϐ�
	int setGridRowN = 0;
	//�Z�b�g����ۂɂǂ̗�ɃZ�b�g���邩���w���ϐ�
	int setGridColN = 0;


public:
	JSONManager* jsonmanager;

	JsonLoader();
	~JsonLoader();

	void init();
	void job(std::string jsonnode);

	//
	void loadJson(boost::property_tree::ptree json);
	void returnRow();
	std::vector<std::string> getNodes(boost::property_tree::ptree json);
};

#endif // !__JSON_LOADER



