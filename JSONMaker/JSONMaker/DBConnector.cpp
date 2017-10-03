#pragma
#include "DBConnector.h"
#include  <iostream>
#include  <sstream>


using namespace std;

DBConnector::DBConnector()
{
}


DBConnector::~DBConnector()
{
	delete con;
}

void DBConnector::Connect(string DBName)
{
	//�h���C�o�[��ǂ݂���
	sql::mysql::MySQL_Driver *driver;
	//�h���C�o�[�̃C���X�^���X���쐬
	driver = sql::mysql::get_mysql_driver_instance();
	//DB�̖��O��ݒ�
	string dbname = "ddthink-com00006";

	//DB�ɐڑ�
	con = driver->connect("", "root", "");
	//DB���w��
	con->setSchema(DBName);

}

void DBConnector::disConnect()
{
	try {
		//�R�l�N�V���������
		this->con->close();
	}
	//SQL��O����
	catch (sql::SQLException &e) {
		//���������ُ���R���\�[���ɕ\��
		cout << e.what();
	}
}
