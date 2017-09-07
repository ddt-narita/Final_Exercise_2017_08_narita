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




/*
関数名:isSameParentNumber
概要:親のキー群同士を比べて同じ要素である個数を返す関数
引数:vector<string>previous:比較対象の前回のキー群　 vector<string> previous:今回のキー群
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


/*
関数名:loadJson
概要:指定のJSONファイルを読み込んで各情報を配置していく関数
引数:boost::property_tree::ptree ptree :jsonオブジェクト
返却値:なし
作成者:成田修之
作成日:9月5日
*/
void JsonLoader::loadJson(ptree json)
{
	//受け取ったjsonについて第一階層全走査
	BOOST_FOREACH(const ptree::value_type& child, json) {
		//キー名をその階層のキーとして格納
		keyHierarchyArray[jsonLevel] = child.first;

		//配列の時
		if (child.first == "") {
			//配列を取得
			ptree arraytree = child.second;
			//配列の要素オブジェクトを全走査
			BOOST_FOREACH(const ptree::value_type& arrayNode, arraytree) {
				//要素がオブジェクトの時
				if (arrayNode.first != "") {
					//オブジェクト内をすべて走査
					BOOST_FOREACH(const ptree::value_type& arrayObject, arrayNode.second) {
						//セルのデータとしてセットするための配列
						vector<std::string> gridDataForSet(2);
						//コンテンツキーに現在のキー名をセット
						gridDataForSet[constants.CONTENT_KEY_INDEX] = arrayObject.first;
						//要素のvalueを取得
						boost::optional<std::string> value = arrayObject.second.get_optional<std::string>(arrayObject.first);
						//取得した値をセットする
						jsonmanager->setGrid(setGridRowN, setGridColN, value.get());
						//次、となりの列に行くために列の値をインクリメント
						setGridColN++;

					}	//オブジェクト内終了
						//配列であることを示すキーを階層のキー配列に追加
					keyHierarchyArray.push_back(constants.KEY_IS_ARRAY);
					//行の情報を格納する(配列なのでこのまま)
					jsonmanager->setGridRowData(setGridRowN, vector<string>(keyHierarchyArray.begin(),keyHierarchyArray.begin() + jsonLevel + 1));
					//配列であることを示すキーを取り除く(階層のキーとは関係がないため)
					keyHierarchyArray.pop_back();
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
					//valueを取得する
					//boost::optional<std::string> value = arrayNode.second.get_optional<std::string>(arrayNode.first);
					std::string value = arrayNode.second.data();
					
					//取得した値を表にセット
					jsonmanager->setGrid(setGridRowN, setGridColN, value);
					//配列であることを示すキーを追加
					keyHierarchyArray.push_back(constants.KEY_IS_ARRAY);
					//行の情報を格納する
					jsonmanager->setGridRowData(setGridRowN, keyHierarchyArray);
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
			}	//配列の要素終了
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

			//今回の階層のキーと前回のキー情報で同じものが階層の数-1より大きい(違う部分が一つのみ)
			int sameParentNumber = isSameParentNumber(previousRowData, keyHierarchyArray);
			//前回と今回で同じキーの数が階層の数との差が1(前回と今回で異なるキーが1つのみ)
			if (sameParentNumber != 0 && sameParentNumber >= jsonLevel - 1) {
				//階層のキーから最新2つを除いた配列を行のデータとしてセット
				jsonmanager->setGridRowData(setGridRowN, vector<std::string>(keyHierarchyArray.begin(), keyHierarchyArray.end() - 2));
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
			jsonmanager->setGridData(setGridRowN, setGridColN, vector<std::string>(keyHierarchyArray.end() - 2, keyHierarchyArray.end()));

			//次の列へ
			setGridColN++;
			//今回の情報を保存して次のノードへ
			previousRowData = keyHierarchyArray;
		}
		
	}
}