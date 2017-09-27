#include "GridJSONCreator.h"
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include "Constants.h"
#include <iostream>

using namespace std;
using namespace boost::property_tree;

GridJSONCreator::GridJSONCreator()
{
}

GridJSONCreator::~GridJSONCreator()
{
}

/*
関数名:init
概要:初期化関数
引数:int rowN int colN　
返却値:なし
作成者:成田修之
作成日:9月4日(月)
*/
void GridJSONCreator::init(int rowN, int colN)
{
	//初期化関数
	jsonmanager->grid->init(rowN, colN);

}


/*
関数名:job
概要:JSON作成の一連の処理を行う関数
引数:無し
返却値:無し
作成日:9月27日(水)
作成者:成田修之
*/
void GridJSONCreator::job() {
	//JSON作成処理
	jsonmanager->json = CreateJSON();
constants.jsonfileout(jsonmanager->json);
	//作ったJSONオブジェクトを避難
	boost::property_tree::ptree p =jsonmanager->json;
	//ノード名配下に格納
	jsonmanager->json.put_child(jsonmanager->env.getNodeName(), p);
	//そのJSONオブジェクトを書き出す
	write_json("data.json", jsonmanager->json);
}

bool isJsonEmpty(ptree json) {
	int i = 0;
	if ("" != json.data()) {
		return false;
	}

	BOOST_FOREACH(const ptree::value_type& child, json) {
		i = 1;
	}

	if (i != 0) {
		return false;
	}
	else {
		return true;
	}
}

/*
関数名:CreateJSON
概要:GridManagerに格納された情報から実際にJSONを作成する
引数:なし
返却値:なし
作成者:成田修之
作成日:9月4日(月)
*/
ptree GridJSONCreator::CreateJSON()
{
	ptree json;

	//行数と列数を取得
	int row = this->jsonmanager->getGridRowLength();
	int col = this->jsonmanager->getGridColLen();

	//ノード名を取得する
	string nodeName = jsonmanager->env.getNodeName();

	//行数分繰り返す
	for (int i = 0; i < row; i++) {
		//行の一番左のその行について表すキーを取得する
		string rowStr = jsonmanager->getGrid(i, 0);
		ptree data = jsonmanager->getGridData(i, 0);
		//一列目のセルがデータなら
		if ("" != data.data()/* || data.empty()*/) {
			json.add(rowStr, data.data());
		}

		//
		ptree rowJson;
		//列数分繰り返す
		for (int j = 1; j < col; j++) {
			string key = jsonmanager->getGrid(i, j);
			if ("" != key) {
				//そのセルのデータを取得する
				ptree cellData = jsonmanager->getGridData(i, j);
				
				if (isJsonEmpty(cellData)) {
					json.add(rowStr + "." + key, "");
				}
				else {
					//行ごとのJSONにその行のキー配下に取得したセルのデータをセットする
					json.add_child(rowStr + "." + key, cellData);
				}
			}
		}
	}
constants.jsonfileout(json);
	return json;
}


