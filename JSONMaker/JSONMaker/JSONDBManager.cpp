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
//void JSONDBManager::run()
//{
//	//���������s��
//	this->init();
//	//�ǂݍ��ݏ������s��
//	this->job();
//}
//
//void JSONDBManager::init()
//{
//	//DB�ɐڑ�����
//	this->Connect();
//	constants.fileout("����������");
//}
//
//void JSONDBManager::job()
//{
//	//���͂��ꂽ�N�G����DB�ɓ��������ʂœǂݍ���
//	loadDBResult(getQuery());
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
//void JSONDBManager::loadDBResult(std::string query)
//{
//	//�X�e�[�g�����g���쐬
//	sql::Statement *stmt = con->createStatement();
//	//���ʂ��i�[����ϐ���p��
//	sql::ResultSet *result = nullptr;
//	constants.fileout("�N�G��������O");
//	//�����̃N�G���Ō��ʂ��擾
//	result = stmt->executeQuery(query);
//	constants.fileout("�N�G��������ꂽ");
//
//	//���ʂ��烁�^�f�[�^���擾
//	sql::ResultSetMetaData *metaData = result->getMetaData();
//	
//	//�񐔂��擾
//	int colN = metaData->getColumnCount();
//
//	//�Z�b�g���邽�߂̃x�N�g���f�[�^��p��
//	vector<string> setData(2);
//	//�i�[����ۂɎg�����s�ڂ��������l
//	int i = 0;
//	//���ʂ����ׂđ���
//	while(result->next()) {
//		//�񂷂ׂđ���
//		for (int j = 0; j < colN; j++) {
//			//�񖼎擾���ăL�[���Ƃ��ĕۑ�
//			setData[1] = metaData->getColumnLabel(j + 1);
//			//�L�[�Q���i�[
//			this->jsonmanager->setGridData(i, j, setData);
//			//���̗�̒l���擾����
//			string value = result->getString(j + 1);
//			//�l���i���Ȃ�󕶎��ɒu��������
//			//value = &value == nullptr ? "" : value;
//			//�擾�����l���Z�b�g����
//			jsonmanager->setGrid(i, j, value);
//		}
//		constants.fileout(to_string(i));
//		//���s�ڂ���\���l�𑝉�
//		i++;
//	}
//	constants.fileout("�Z�b�g����");
//
//	//�s���񐔂��i�[����
//	jsonmanager->setGridMaxColLen(colN);
//	jsonmanager->setGridRowLen(i);
//}
