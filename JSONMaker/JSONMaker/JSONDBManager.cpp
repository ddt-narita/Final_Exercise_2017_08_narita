#pragma
//#include "JSONDBManager.h"
//#include <vector>
//
//using namespace std;
//
//JSONDBManager::JSONDBManager()
//{
//}
//
//
//JSONDBManager::~JSONDBManager()
//{
//}
//
//void JSONDBManager::run(ChainData* cell)
//{
//	//���������s��
//	this->init();
//	//�ǂݍ��ݏ������s��
//	this->job(cell);
//}
//
//void JSONDBManager::init()
//{
//	//DB�ɐڑ�����
//	this->Connect(env.DBname);	
//}
//
//void JSONDBManager::job(ChainData* cell)
//{
//	//���͂��ꂽ�N�G����DB�ɓ��������ʂœǂݍ���
//	loadDBResult(getQuery(), cell);
//	//DB�Ƃ̐ڑ���؂�
//	disConnect();
//}
//
//std::string JSONDBManager::getQuery()
//{
//	//���N���X������͂��ꂽ�N�G�����擾���ĕԂ�
//	return jsonmanager->env.getQuery();
//}
//
//bool JSONDBManager::isQuerySet()
//{
//	//�N�G�������͂���Ă��邩�ǂ�����ԋp����
//	return jsonmanager->isQuerySet();
//}
//
//void JSONDBManager::loadDBResult(std::string query, ChainData* cell)
//{
//	//�X�e�[�g�����g���쐬
//	sql::Statement *stmt = con->createStatement();
//	//���ʂ��i�[����ϐ���p��
//	sql::ResultSet *result = nullptr;
//	//�����̃N�G���Ō��ʂ��擾
//	result = stmt->executeQuery(query);
//	//���ʂ��烁�^�f�[�^���擾
//	sql::ResultSetMetaData *metaData = result->getMetaData();
//	
//	//�񐔂��擾
//	int colN = metaData->getColumnCount();
//	//�q���쐬����
//	cell->addRight(new ChainData());
//	//�q�J�����g�Ƃ���
//	ChainData* childCurrent = cell->right;
//
//	//���ʂ̑S�s���J��Ԃ�
//	while (result->next()) {
//		//�q�J�����g�ɑ����쐬����
//		childCurrent->addRight(new ChainData());
//		//���J�����g�Ƃ���
//		ChainData* GchildCurrent = childCurrent->right;
//		//�񐔕��J��Ԃ�
//		for (int i = 0; i < colN; i++) {
//			//���̃L�[�ɂ͗�̖��O
//			GchildCurrent->key = constants.UTF8toSjis(metaData->getColumnName(i + 1));
//			//���̒l�ɂ͂��̃Z���̒l���i�[����
//			GchildCurrent->value = constants.UTF8toSjis(result->getString(i + 1));
//			//�Ō�̗�ł͂Ȃ����
//			if (i != colN - 1) {
//				//���J�����g�ɒ���쐬
//				GchildCurrent->addUnder(new ChainData());
//				//���J�����g�����̒�ɂ���
//				GchildCurrent = GchildCurrent->under;
//			}
//		}
//		//�q�J�����g�ɒ���쐬
//		childCurrent->addUnder(new ChainData());
//		//�q�J�����g�����̒�ɂ���
//		childCurrent = childCurrent->under;
//	}
//	//�Ō�ɗ]���Ă��܂����q�J�����g�̌Z����̎q�J�����g���w���|�C���^���i�����w���悤�ɂ���
//	childCurrent->upper->under = nullptr;
//	//�q�J�����g���폜����
//	delete childCurrent;
//}
