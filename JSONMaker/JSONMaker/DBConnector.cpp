//#include "DBConnector.h"
//#include  <iostream>
//#include  <sstream>
//
//
//using namespace std;
//
//DBConnector::DBConnector()
//{
//}
//
//
//DBConnector::~DBConnector()
//{
//	delete con;
//}
//
//void DBConnector::Connect()
//{
//	//ドライバーを読みこむ
//	sql::mysql::MySQL_Driver *driver;
//	//ドライバーのインスタンスを作成
//	driver = sql::mysql::get_mysql_driver_instance();
//	//DBの名前を設定
//	string dbname = "ddthink-com00006";
//
//	//DBに接続
//	con = driver->connect("tcp://127.0.0.1:3306", "root", "");
//	//DBを指定
//	con->setSchema(dbname);
//
//}
//
//void DBConnector::disConnect()
//{
//	try {
//		//コネクションを閉じる
//		this->con->close();
//	}
//	//SQL例外発生
//	catch (sql::SQLException &e) {
//		//発生した異常をコンソールに表示（必要ない？）
//		cout << e.what();
//	}
//}
