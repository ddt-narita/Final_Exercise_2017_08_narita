#include "JsonLoader.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <iostream>
#include "Constants.h"

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
	this->JsonLoader::init();
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
	string path = this->getJsonFilePath();
	read_json(path, json);

	jsonLevel = 0;

	if (json.empty()) {
		cout << "json couldn't read";
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
	this->loadJson(json);
}

/*
関数名:getJsonFilePath
概要:指定されたjsonファイルのパスをメンバのEnvから取得する関数
引数:なし
返却値:string path　パス
作成者:成田修之
作成日:9月5日
*/
std::string JsonLoader::getJsonFilePath()
{
	return std::string();
}


/*
関数名:isSameParentNumber
概要:親のキー群同士を比べて同じ要素である個数を返す関数
引数:vector<string>previous:比較対象の前回のキー群　 vector<string> previous:今回のキー群
返却値:int retSameCount 同じ値の要素の数
作成者:成田修之
作成日:9月5日
*/
int isSameParentNumber(const vector<string> &previous, const vector<string>& thistime) {

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
		hierarchy.push_back(child.first);

		//valueがオブジェクト
		if (!child.second.empty() && child.second.data().empty()) {

			//階層を表す変数を+1
			this->jsonLevel += 1;
			//このオブジェクトについて再帰処理
			loadJson(child.second);
			//抜け出したら変数を-1して
			this->jsonLevel -= 1;
			//一番後ろの階層のキーを取り除く
			hierarchy.pop_back();
		}
		//配列の時
		else if (child.first == "") {
			//配列を取得
			ptree arraytree = child.second;
			//配列の要素オブジェクトを全走査
			BOOST_FOREACH(const ptree::value_type& arrayNode, arraytree) {
				//要素がオブジェクトの時
				if (!arrayNode.second.empty() && arrayNode.second.data().empty()) {
					//オブジェクト内をすべて走査
					BOOST_FOREACH(const ptree::value_type& arrayObject, arrayNode.second) {
						//セルのデータとしてセットするための配列
						vector<string> gridDataForSet(2);
						//コンテンツキーに現在のキー名をセット
						gridDataForSet[constants.CONTENT_KEY_INDEX] = arrayObject.first;
						//要素のvalueを取得
						boost::optional<std::string> value = arrayObject.second.get_optional<std::string>(arrayObject.first);
						//取得した値をセットする
						setGrid(setGridRowN,setGridColN, value.get());

						//次、となりの列に行くために列の値をインクリメント
						setGridColN++;

					}	//オブジェクト内終了
//行の情報を格納する(引数要修正)
					this->setGridRowData(setGridRowN,hierarchy);
					//次の行に行くためにインクリメント
					setGridRowN++;
					//改行するので列の値は0に
					setGridColN = 0;
					
				}
				//要素がオブジェクトではなく、通常の要素
				else {
					//valueを取得する
					boost::optional<std::string> value = arrayNode.second.get_optional<std::string>(arrayNode.first);
					//取得した値を表にセット
					setGrid(setGridRowN, setGridColN, value.get());
					//行の情報を格納する
					setGridRowData(setGridRowN, hierarchy);
					//改行処理
					setGridRowN++;
					setGridColN = 0;

				}
			}	//配列の要素終了
		}//子でも配列でもないとき(最下層でvalueが取り出せるとき)
		else {
			//valueを取得
			boost::optional<std::string> value = child.second.get_optional<std::string>(child.first);

			//今回の階層のキーと前回のキー情報で同じものが階層の数-1より大きい(違う部分が一つのみ)
			if (isSameParentNumber(previousRowData, hierarchy) > jsonLevel - 1) {
				setGridRowData(setGridRowN, hierarchy);
				//改行して次の行へ格納するように
				setGridRowN++;
				//改行なので列の値は0に
				setGridColN = 0;
			}
			//取得したvalueをセット
			setGrid(setGridRowN,setGridColN, value.get());
			setGridData(setGridRowN,setGridColN, hierarchy);
			//次の列へ
			setGridColN++;
			//今回の情報を保存して次のノードへ
			previousRowData = hierarchy;
		}
	}
}

vector<string> hierarToRowData(const vector<string>& hier) {
	vector<string> rowdata(hier.size() - 2);
	for (int i = 0; i < rowdata.size(); i++) {

	}
}

vector<string> hierarToGridData(const vector<string>& hier) {
	vector<string> gridData(2);
	for (int i = 0; i < 2; i++) {

	}
}