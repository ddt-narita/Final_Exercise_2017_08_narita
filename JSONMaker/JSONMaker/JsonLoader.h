#pragma once
#ifndef __JSON_LOADER
#define __JSON_LOADER

#include "JSONManager.h"
#include "GridJSONCreator.h"

class JsonLoader :
	public GridJSONCreator
{
private:
	//�ċA���ɉ��K�w�ڂ���\���ϐ�
	int jsonLevel = 0;
	//�K�w���Ƃ̃L�[����͂��邽�߂̃L�[
	std::vector<std::string> keyHierarchyArray;

	std::vector<std::string> previousRowData;

	//�Z�b�g����ۂ�BOOST_EACH�Ń��[�v���邽�߁A���[�v�ϐ����O�ɒu��
	//�Z�b�g����ۂɂǂ̍s�ɃZ�b�g���邩�w���ϐ�
	int setGridRowN = 0;
	//�Z�b�g����ۂɂǂ̗�ɃZ�b�g���邩���w���ϐ�
	int setGridColN = 0;

public:
	JsonLoader();
	~JsonLoader();

	void run();
	void init();
	void job();

	//
	void loadJson(boost::property_tree::ptree json);
};

#endif // !__JSON_LOADER



