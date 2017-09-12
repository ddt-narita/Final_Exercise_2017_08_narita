#include "JsonLoader.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <iostream>
#include "Constants.h"
#include <sstream>
#include <codecvt>
#include <locale>



using namespace std;
using namespace boost::property_tree;

JsonLoader::JsonLoader()
{
}


JsonLoader::~JsonLoader()
{
}

/*
関数名:run
概要:初期化と手続きを一括で行う関数
引数:なし
返却値:なし
作成者:成田修之
作成日:9月5日
*/
void JsonLoader::run()
{
	//初期化関数を実行
	this->JsonLoader::init();
	//読み込みを行う関数を実行
	this->JsonLoader::job();
}

/*
関数名:
概要:初期化を行う関数
引数:なし
返却値:なし
作成者:成田修之
作成日:9月5日
*/
void JsonLoader::init()
{
	vector<string> temp(15);

	keyHierarchyArray = temp;
	previousRowData = temp;

	//セットされたファイルパスを取得
	std::string path = this->jsonmanager->getJsonFilePath();
	//そのパスでjson読み込み
	read_json(path, jsonmanager->json);
	//何階層目かの数値を0でリセット
	jsonLevel = 0;
	//読みこめていなかったら
	if (jsonmanager->json.empty()) {
		//読みこめていなかったことを表示
		cout << "json couldn't read";
	}
	else {
		stringstream ss;
		write_json(ss, jsonmanager->json);
		cout << ss.str();
	}
}

/*
関数名:job
概要:手続きを行う関数
引数:なし
返却値:なし
作成者:成田修之
作成日:9月5日
*/
void JsonLoader::job()
{
	//実際にjsonを読み込む
	this->loadJson(jsonmanager->json);
}


/*
関数名:getJsonFilePath
概要:指定されたjsonファイルのパスをメンバのEnvから取得する関数
引数:なし
返却値:string path　パス
作成者:成田修之
作成日:9月5日
*/


vector<string> keyRemvFromHierarchy(const vector<string>& hierarchy, int jsonlevel) {
	if (hierarchy.size() > 2 + jsonlevel) {
		return vector<string>(hierarchy.begin(), hierarchy.begin() + jsonlevel);
	}
	else {
		return vector<string>(hierarchy.begin(), hierarchy.begin() + jsonlevel);
	}
}


/*
関数名:isSameParentNumber
概要:親のキー群同士を比べて同じ要素である個数を返す関数
引数:vector<string>previous:比較対象の前回のキー群　 vector<string> thistime:今回のキー群
返却値:int retSameCount 同じ値の要素の数
作成者:成田修之
作成日:9月5日
*/
int isSameParentNumber(const vector<string> &previous, const vector<string>& thistime) 
{
	//返却する何個同じかを格納する変数
	int retSameCount;

	//引数のどちらかの配列の
	for (retSameCount = 0; retSameCount < previous.size(); retSameCount++) {
		//配列の要素を比べて異なる値の時
		if (previous[retSameCount] != thistime[retSameCount]) {
			//ループを抜け、その時の値を返却する
			break;
		}
	}
	//何個同じだったかを返却する
	return retSameCount;
}

int keySize(const vector<string>& temp) {
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] == "") {
			return i;
		}
	}
}


/*
関数名:isSameRow
概要:前の要素と比べて同じ行のものかどうか判定する関数
引数:vector<string> previous, vector<string> thistime　前回と今回のキー群
返却値:bool　同じ行かどうかの真理値
作成日:9月12日(火)
作成者:成田修之
*/
bool JsonLoader::isSameRow(const vector<string> & previous, const vector<string>& thistime) {
	//初めてなら
	if (previous.size() == 0) {
		//改行を行わなくていいようにtrueを返す
		return true;
	}
	else {

		int preSize = keySize(previous);
		int thisSize = keySize(thistime);

		//大きいほうの値取得
		int maxComp = preSize > thisSize ? preSize : thisSize;
		//同じ値の数を取得するための変数
		int sameNumber = 0;
		//大きいほうの要素数分繰り返す
		for (int i = 0; i < maxComp; i++) {
			//前回と今回で違う値なら
			if (previous[i] != thistime[i]) {
				//何個まで同じだったか取得
				sameNumber = i;
				//値が違ったのでループを抜ける
				break;
			}
		}
		//同じ数が最大から2引いた値より大きければ
		if (sameNumber >= maxComp - 2) {
			//同じ行なのでtrueを返す
			return true;
		}
		//そうでなければ
		else {
			//falseを返す
			return false;
		}
	}
}

/*
関数名:loadJson
概要:指定のJSONファイルを読み込んで各情報を配置していく関数
引数:boost::property_tree::ptree json :jsonオブジェクト
返却値:なし
作成者:成田修之
作成日:9月5日
*/
void JsonLoader::loadJson(boost::property_tree::ptree json)
{
	//受け取ったjsonについて第一階層全走査
	BOOST_FOREACH(const ptree::value_type& child, json) {
		//キー名をその階層のキーとして格納
		keyHierarchyArray[jsonLevel] = child.first;
		for (int i = jsonLevel + 1; i < 15; i++) {
			keyHierarchyArray[i] = "";
		}

		//配列の時
		if (child.first == "") {
			//要素がオブジェクトの時
			if (child.second.data().empty()) {
				//オブジェクト内をすべて走査
				BOOST_FOREACH(const ptree::value_type& arrayObject, child.second) {
					//セルのデータとしてセットするための配列
					vector<std::string> gridDataForSet(2);
					//コンテンツキーに現在のキー名をセット
					gridDataForSet[constants.CONTENT_KEY_INDEX] = arrayObject.first;
					//値を取得
					string value = arrayObject.second.data();
					//取得した値をセットする
					jsonmanager->setGrid(setGridRowN, setGridColN, value);
					//次、となりの列に行くために列の値をインクリメント
					setGridColN++;

				}	//オブジェクト内終了
					//配列であることを示すキーを階層のキー配列に追加
				keyHierarchyArray[jsonLevel + 1] = (constants.KEY_IS_ARRAY);
				//この階層までのキーを行の情報として格納する(+1は配列であることを示すキー分)
				jsonmanager->setGridRowData(setGridRowN, std::vector<std::string>(keyHierarchyArray.begin(), keyHierarchyArray.begin() + jsonLevel + 1));
				//配列であることを示すキーを取り除く(階層のキーとは関係がないため)
				keyHierarchyArray[jsonLevel + 1] = "";
				//次の行に行くためにインクリメント
				setGridRowN++;
				jsonmanager->setGridRowLen(setGridRowN);
				if (jsonmanager->getGridColLength() < setGridColN) {
					jsonmanager->setGridMaxColLen(setGridColN);
				}
				//改行するので列の値は0に
				setGridColN = 0;
				previousRowData = keyHierarchyArray;
			}
			//配列の要素がオブジェクトではなく、通常の要素
			else {
				std::string value = child.second.data();

				//取得した値を表にセット
				jsonmanager->setGrid(setGridRowN, setGridColN, value);
				//配列であることを示すキーを追加
				keyHierarchyArray.push_back(constants.KEY_IS_ARRAY);
				//この階層までのキーを行の情報として格納する(+1は配列であることを示すキー分)
				jsonmanager->setGridRowData(setGridRowN, vector<string>(keyHierarchyArray.begin(), keyHierarchyArray.begin() + jsonLevel + 1));
				//配列であることを示すキーを取り除く(階層のキーとは無関係なため)
				keyHierarchyArray.pop_back();
				//改行処理
				setGridRowN++;
				if (jsonmanager->getGridColLength() < setGridColN) {
					jsonmanager->setGridMaxColLen(setGridColN);
				}
				setGridColN = 0;
				jsonmanager->setGridRowLen(setGridRowN);
				previousRowData = keyHierarchyArray;
			}
				//配列の要素終了
		}
		//valueがオブジェクト
		else if (!child.second.empty() && child.second.data().empty()) {
			//階層を表す変数を+1
			this->jsonLevel += 1;
			//このオブジェクトについて再帰処理
			loadJson(child.second);
			//抜け出したら変数を-1して
			this->jsonLevel -= 1;			
		}
		//子でも配列でもないとき(最下層でvalueが取り出せるとき)
		else {
			//valueを取得
			std::string gridvalue = child.second.data();

			//前回と今回を比べて同じ行でないと判定されたら
			if (!isSameRow(previousRowData, keyHierarchyArray)) {
				//階層のキーから最新2つを除いた配列を行のデータとしてセット
				jsonmanager->setGridRowData(setGridRowN, keyRemvFromHierarchy(previousRowData, jsonLevel));
				//改行して次の行へ格納するように
				setGridRowN++;
				jsonmanager->setGridRowLen(setGridRowN);
				if (jsonmanager->getGridColLength() < setGridColN) {
					jsonmanager->setGridMaxColLen(setGridColN);
				}
				//改行なので列の値は0に
				setGridColN = 0;
			}
			
			//取得したvalueをセット
			jsonmanager->setGrid(setGridRowN, setGridColN, gridvalue);
			//階層のキーの後ろから2番目から最後まで（最新のキー2つ）のキー群をそのvalueの情報として格納
			jsonmanager->setGridData(setGridRowN, setGridColN, vector<std::string>(keyHierarchyArray.begin() + jsonLevel - 1, keyHierarchyArray.begin()+ jsonLevel + 1));

			//次の列へ
			setGridColN++;
			//今回の情報を保存して次のノードへ
			previousRowData = keyHierarchyArray;
		}
		
	}
}
