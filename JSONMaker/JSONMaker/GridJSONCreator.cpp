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
	grid->init(rowN, colN);

}

/*
関数名:jsonRowDataStr
概要:行ごとのデータをアクセス可能な文字列に変換する
引数:vector<string> rowData 行ごとの情報配列
返却値:int len
作成者:成田修之
作成日:9月4日(月)
*/
string jsonRowDataStr(vector<string> rowData) {
	string retStr;
	//行ごとのデータの大きさ分繰り返す
	for (int i = 0; i < rowData.size(); i++) {
		//返却する文字列が空でなく、最後尾が区切り文字でなく、後で加えるデータが空白でもないとき
		if (!retStr.empty() && retStr.back() != '.' && rowData[i] != "") {
			//.で区切る
			retStr += ".";
		}
		//行ごとのデータを追加していく
		retStr += rowData[i];
	}

	//作成した文字列を返却する
	return retStr;
}

//実際にJSONを作成するメソッド
/*
関数名:job
概要:GridManagerに格納された情報から実際にJSONを作成する
引数:なし
返却値:なし
作成者:成田修之
作成日:9月4日(月)
*/
void GridJSONCreator::job()
{
	//配列のオブジェクトを格納する変数
	ptree arrayptree;

	//前回が配列であったかを示す変数
	int previousIsArray = 0;
	//親のキーをアクセス可能な文字列に変換して格納する変数
	string parentkeys;

	//行数分繰り返す
	for (int i = 0; i < grid->getGridRowLength(); i++) {
		//行の情報取得
		vector<string> rowdata (grid->getGridRowData(i));
				
		//今回が配列ではない且つ前回が配列の時
		if (rowdata[rowdata.size() - 2] != "" && previousIsArray == 1) {
			string s = "json";
			//親のキー情報群文字列が空でなければピリオドで区切って付け足す
			s += (parentkeys == "" ? "" : "." + parentkeys);
			//配列の最後としてできた配列をメンバのjsonに格納
			json.add_child(s, arrayptree);
		}
		//情報配列からアクセス可能な文字列に変換する
		parentkeys = jsonRowDataStr(rowdata);

		//配列の時(行の一番最後が配列を示す)
		if (rowdata[rowdata.size() - 2] == "") {
			//配列内のオブジェクト
			ptree child;
			//列数分繰り返す
			for (int j = 0; j < grid->getGridColLength(); j++) {
				//セルの値を取得
				string value = grid->getGrid(i, j);
				
				//値がきちんと入力されているなら
				if (value != "") {
					//そのセルの情報配列を取得する
					vector<string> celldata = grid->getGridData(i, j);

					//コンテントキーのオブジェクトを子のオブジェクトに追加
					child.put(celldata[constants.CONTENT_KEY_INDEX], value);
				}
			}
			//子オブジェクトに何か入力されていれば
			if (!child.empty() ||!child.data().empty()) {
				//子オブジェクトを空のキー配下に格納して配列にする
				arrayptree.push_back(std::make_pair("", child));
			}
			//今回が配列であったことを保存
			previousIsArray = 1;
		}
		//普通のJSONの時
		else {
			//行数分繰り返す
			for (int j = 0; j < grid->getGridColLength(); j++) {
				//その位置のセルの情報を取得する
				string value = grid->getGrid(i, j);
				//きちんとvalueがセットされていれば
				if (value != "") {
					//そのセルの情報配列を取得する
					vector<string> celldata = grid->getGridData(i, j);
					
					//前回の情報が残ってしまうためもう一度取得してリセット
					parentkeys = jsonRowDataStr(rowdata);

					//文字列にキーとコンテンツキーの情報を加える
					parentkeys += "." + jsonRowDataStr(celldata);
					//jsonにアクセスしてセルの値を格納
					json.add("json." + parentkeys, value);
				}
			}
			//今回が配列ではないことを保存
			previousIsArray = 0;
		}
	}

	//前回が配列のまま最後まで来たとき
	if (previousIsArray == 1) {
		string s  = "json";
		s += (parentkeys == "" ? "" : "." + parentkeys);
		//配列の最後としてできた配列をメンバのjsonに格納
		json.add_child(s, arrayptree);
	}


	//できたjsonを指定のパスに書き込む
	write_json("data.json", json);
}
