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
関数名:
概要:初期化を行う関数
引数:なし
返却値:なし
作成者:成田修之
作成日:9月5日
*/
void JsonLoader::init()
{
	//セットされたファイルパスを取得
	std::string path = this->jsonmanager->getJsonFilePath();
	//そのパスでjson読み込み
	read_json(path, jsonmanager->json);
}

/*
関数名:job
概要:手続きを行う関数
引数:なし
返却値:なし
作成者:成田修之
作成日:9月5日
*/
void JsonLoader::job(string jsonnode, ChainData* cell)
{
	//選択されたノードを取得
	ptree node = jsonmanager->json.get_child(jsonnode);

	cell->key = jsonnode;
	//そのノードに対して読み込み処理を行う
	this->loadJson(node, cell);
}



/*
関数名:loadJson
概要:既存のJSONファイルを読み込んで表にセットする関数
引数:property_tree json　JSONファイル中の選択されたノード
返却値:無し
作成者:成田修之
作成日:9月13日(水)
*/
void JsonLoader::loadJson(boost::property_tree::ptree json, ChainData* cell)
{
	cell->addRight(new ChainData());
	ChainData * current = cell->right;

	BOOST_FOREACH(const ptree::value_type& child, json) {
		current->key = constants.UTF8toSjis(child.first);
		//配列の時
		if ("" == child.first) {
			//要素がオブジェクトの時
			if (child.second.data().empty()) {
				//子を作成する
				current->addRight(new ChainData());
				//子に移動してカレントとする
				ChainData* arrayCurrent = current->right;

				//オブジェクト内の要素数分繰り返す
				BOOST_FOREACH(const ptree::value_type& arrayElement, child.second) {
					//キーを格納
					arrayCurrent->key = constants.UTF8toSjis(arrayElement.first);
					//値を格納
					arrayCurrent->value = constants.UTF8toSjis(arrayElement.second.data());
					//弟を作成する
					arrayCurrent->addUnder(new ChainData());
					//カレントを作成した弟へ移動
					arrayCurrent = arrayCurrent->under;
				}
				//最後まで来たら余計につけられた弟を指していた兄のポインタをナルを指すように
				arrayCurrent->upper->under = nullptr;
				//最後の弟を削除
				delete arrayCurrent;
			}
			//通常の配列の時
			else {
				//キーを格納(空文字)
				current->key = constants.UTF8toSjis(child.first);
				//値を格納する
				current->value = constants.UTF8toSjis(child.second.data());
			}
		}
		//子がある時
		else if (!child.second.empty() && child.second.data().empty()) {
			//子について再帰処理
			loadJson(child.second, current);
		}
		//最下層の値の時
		else if (child.second.empty() && !child.second.data().empty()) {
			//その右のセルの値をとして格納
			current->value = constants.UTF8toSjis(child.second.data());
		}
		//
		current->addUnder(new ChainData());
		current = current->under;
	}
	//最後まで行ったら余計な最後に追加されたセルを指すポインタがナルを指すようにする
	current->upper->under = nullptr;
	//余計なセルを削除する
	delete current;


}

/*
関数名:getNodes
概要:取得したJSONからどのノードについて表示するかを選択するためにノードの配列を作成する
引数:無し
返却値:vector<string> Nodes　ノード群
作成日:9月25日(月)
作成者:成田修之
*/
std::vector<std::string> JsonLoader::getNodes(ptree json)
{
	//返却するための配列
	vector<string> retVec;
	//取得したJSONの第一階層をループ
	BOOST_FOREACH(const ptree::value_type& child, json) {
		//ノード名をどんどん後ろに追加していく
		retVec.push_back(child.first);
	}
	//出来上がった配列を返却する
	return retVec;
}
