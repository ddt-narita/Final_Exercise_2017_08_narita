#include "JSONManager.h"
#include "Constants.h"



JSONManager::JSONManager()
{
	
}

JSONManager::~JSONManager() {

}



std::string JSONManager::getQuery()
{
	return env.Query;
}

bool JSONManager::isQuerySet()
{
	return env.Query != "";
}

void JSONManager::setQuery(std::string query)
{
	env.Query = query;
}

std::string JSONManager::getJsonFilePath()
{
	return env.getJSONFilePath();
}

void JSONManager::setJsonFilePath(std::string path)
{
	env.setJSONFilePath(path);
}

bool JSONManager::isJSONFilePathSet()
{
	//���N���X����JSON�̃p�X���擾���āA��łȂ����̐^���l��Ԃ�
	return (env.getJSONFilePath() != "");
}



