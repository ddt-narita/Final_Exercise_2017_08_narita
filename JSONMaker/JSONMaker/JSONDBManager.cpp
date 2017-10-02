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
//	//初期化を行う
//	this->init();
//	//読み込み処理を行う
//	this->job(cell);
//}
//
//void JSONDBManager::init()
//{
//	//DBに接続する
//	this->Connect(env.DBname);	
//}
//
//void JSONDBManager::job(ChainData* cell)
//{
//	//入力されたクエリをDBに投げた結果で読み込み
//	loadDBResult(getQuery(), cell);
//	//DBとの接続を切る
//	disConnect();
//}
//
//std::string JSONDBManager::getQuery()
//{
//	//環境クラスから入力されたクエリを取得して返す
//	return jsonmanager->env.getQuery();
//}
//
//bool JSONDBManager::isQuerySet()
//{
//	//クエリが入力されているかどうかを返却する
//	return jsonmanager->isQuerySet();
//}
//
//void JSONDBManager::loadDBResult(std::string query, ChainData* cell)
//{
//	//ステートメントを作成
//	sql::Statement *stmt = con->createStatement();
//	//結果を格納する変数を用意
//	sql::ResultSet *result = nullptr;
//	//引数のクエリで結果を取得
//	result = stmt->executeQuery(query);
//	//結果からメタデータを取得
//	sql::ResultSetMetaData *metaData = result->getMetaData();
//	
//	//列数を取得
//	int colN = metaData->getColumnCount();
//	//子を作成して
//	cell->addRight(new ChainData());
//	//子カレントとする
//	ChainData* childCurrent = cell->right;
//
//	//結果の全行分繰り返す
//	while (result->next()) {
//		//子カレントに孫を作成する
//		childCurrent->addRight(new ChainData());
//		//孫カレントとする
//		ChainData* GchildCurrent = childCurrent->right;
//		//列数分繰り返す
//		for (int i = 0; i < colN; i++) {
//			//孫のキーには列の名前
//			GchildCurrent->key = constants.UTF8toSjis(metaData->getColumnName(i + 1));
//			//孫の値にはそのセルの値を格納する
//			GchildCurrent->value = constants.UTF8toSjis(result->getString(i + 1));
//			//最後の列ではなければ
//			if (i != colN - 1) {
//				//孫カレントに弟を作成
//				GchildCurrent->addUnder(new ChainData());
//				//孫カレントをその弟にする
//				GchildCurrent = GchildCurrent->under;
//			}
//		}
//		//子カレントに弟を作成
//		childCurrent->addUnder(new ChainData());
//		//子カレントをその弟にする
//		childCurrent = childCurrent->under;
//	}
//	//最後に余ってしまった子カレントの兄からの子カレントを指すポインタをナルを指すようにする
//	childCurrent->upper->under = nullptr;
//	//子カレントを削除する
//	delete childCurrent;
//}
