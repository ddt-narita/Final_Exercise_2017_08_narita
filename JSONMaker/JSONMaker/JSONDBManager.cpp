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
//	//初期化を行う
//	this->init();
//	//読み込み処理を行う
//	this->job();
//}
//
//void JSONDBManager::init()
//{
//	//DBに接続する
//	this->Connect();
//	constants.fileout("初期化完了");
//}
//
//void JSONDBManager::job()
//{
//	//入力されたクエリをDBに投げた結果で読み込み
//	loadDBResult(getQuery());
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
//void JSONDBManager::loadDBResult(std::string query)
//{
//	//ステートメントを作成
//	sql::Statement *stmt = con->createStatement();
//	//結果を格納する変数を用意
//	sql::ResultSet *result = nullptr;
//	constants.fileout("クエリ投げる前");
//	//引数のクエリで結果を取得
//	result = stmt->executeQuery(query);
//	constants.fileout("クエリ投げられた");
//
//	//結果からメタデータを取得
//	sql::ResultSetMetaData *metaData = result->getMetaData();
//	
//	//列数を取得
//	int colN = metaData->getColumnCount();
//
//	//セットするためのベクトルデータを用意
//	vector<string> setData(2);
//	//格納する際に使う何行目かを示す値
//	int i = 0;
//	//結果をすべて走査
//	while(result->next()) {
//		//列すべて走査
//		for (int j = 0; j < colN; j++) {
//			//列名取得してキー名として保存
//			setData[1] = metaData->getColumnLabel(j + 1);
//			//キー群を格納
//			this->jsonmanager->setGridData(i, j, setData);
//			//その列の値を取得する
//			string value = result->getString(j + 1);
//			//値がナルなら空文字に置き換える
//			//value = &value == nullptr ? "" : value;
//			//取得した値をセットする
//			jsonmanager->setGrid(i, j, value);
//		}
//		constants.fileout(to_string(i));
//		//何行目かを表す値を増加
//		i++;
//	}
//	constants.fileout("セット完了");
//
//	//行数列数を格納する
//	jsonmanager->setGridMaxColLen(colN);
//	jsonmanager->setGridRowLen(i);
//}
