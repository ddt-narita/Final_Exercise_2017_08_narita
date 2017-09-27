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
	jsonmanager->grid->Clear();

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
void JsonLoader::job(string jsonnode)
{
	//選択されたノードを取得
	ptree node = jsonmanager->json.get_child(jsonnode);

	//そのノードに対して読み込み処理を行う
	this->loadJson(node);

	//読み込みが終わった後は現在の行数列数をリセット
	this->jsonmanager->setGridRowLen(setGridRowN);
	setGridColN = 0;
	setGridRowN = 0;
}



/*
関数名:loadJson
概要:既存のJSONファイルを読み込んで表にセットする関数
引数:property_tree json　JSONファイル中の選択されたノード
返却値:無し
作成者:成田修之
作成日:9月13日(水)
*/
void JsonLoader::loadJson(boost::property_tree::ptree json)
{
	//第一階層についてループ
	BOOST_FOREACH(const ptree::value_type& child, json) {
		//一列目についてキーとデータ群を取得してセットする
		jsonmanager->grid->setGrid(setGridRowN, setGridColN, child.first);
		jsonmanager->grid->setGridData(setGridRowN, setGridColN, child.second);
		setGridColN++;
		//子がある時
		if (!child.second.empty() && child.second.data().empty()) {
			//子についてループして
			BOOST_FOREACH(const ptree::value_type& chldNodes, child.second) {
				//子が配列を示しているとき
				if ("" == chldNodes.first) {
					//配列内の要素についてループする
					BOOST_FOREACH(const ptree::value_type& arrayNode, chldNodes.second) {
						//配列の要素のキーを取得する(オブジェクトならキーあり、通常要素ならキーなし)
						jsonmanager->setGrid(setGridRowN, setGridColN, arrayNode.first);
						//配列の要素までのキー群を
						jsonmanager->setGridData(setGridRowN, setGridColN, (arrayNode.second));
						setGridColN++;
					}
				}
				else {
					//その子のキー名を表示させるものとして格納する
					jsonmanager->grid->setGrid(setGridRowN, setGridColN, chldNodes.first);
					//その子以下のオブジェクトなどについてはデータとして格納する
					jsonmanager->grid->setGridData(setGridRowN, setGridColN, chldNodes.second);
					//次のセルへ行くためインクリメント
					setGridColN++;
				}
			}
		}
		//改行処理
		returnRow();
	}
}

void JsonLoader::returnRow() {
	//改行するので今の行の値をセットする
	jsonmanager->setGridRowLen(this->setGridRowN);
	//いままでの最大の列数よりも今回の列が多いとき
	if (jsonmanager->getGridColLen() < setGridColN) {
		//最大の列数として列数を保管する
		jsonmanager->setGridColLen(setGridColN);
	}
	//改行するので列はリセット
	setGridColN = 0;
	//次の行へ行くために行の値をプラス一する
	setGridRowN++;

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
