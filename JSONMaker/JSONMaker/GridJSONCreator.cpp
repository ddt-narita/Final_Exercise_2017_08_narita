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
関数名:createAcsessKey
概要:キー群からJSONにアクセス可能な文字列に変換して返却する関数
引数:vector<string>eachCellKeys キー群 int isArray　配列のキー群なのかどうか
返却値:string acsessKey　アクセス可能な文字列
作成日:9月14日(木)
作成者:成田修之
*/
std::string GridJSONCreator::createAcsessKey(std::vector<std::string> eachCellKeys, int isArray) {
	//配列なら配列のキー分使わないために2をそうでないならすべて使うので0を
	int adjuster = isArray == 1 ? 2 : 0;

	//選択された・DBのもの・入力されたノードの名前(いまは仮にノード)
	string acsessKey = this->jsonmanager->env.getNodeName();
	//引数の配列のサイズから配列かどうかに合わせた値分繰り返す
	for (int i = 0; i < eachCellKeys.size() - adjuster; i++) {
		//キーが空ではなく、配列内にもきちんと値があれば
		if (acsessKey != "" && eachCellKeys[i] != "") {
			//区切りとその時の値を加える
			acsessKey += "." + eachCellKeys[i];
		}
	}
	//アクセス可能な文字列を返却する
	return acsessKey;
}

/*
関数名:isArray
概要:そのセルが配列の要素なのかどうか判定する関数
引数:vector<string>　セルごとのキー
返却値:bool 配列かどうか判定
作成日:9月14日(木)
作成者:成田修之
*/
bool isArray(vector<string> eachCellKey) {
	//判定に使う変数配列ではないことを示す値で初期化
	int retJudge = 0;
	//引数の配列の容数分だけ繰り返す
	for (int i = 0; i < eachCellKey.size(); i++) {
		//要素の中に配列であることを示すキーが含まれているとき
		if (eachCellKey[i] == constants.KEY_ISARRAY) {
			//配列であることを示す値を格納
			retJudge = 1;
			//ループを抜ける
			break;
		}
	}
	//値が配列を示しているかどうかで判定して返却する。
	return retJudge == 1;
}


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
	//行数と列数を取得
	int row = this->jsonmanager->getGridRowLength() + 1;
	int col = this->jsonmanager->getGridColLength();
	ptree arrayObject;
	ptree arraytree;
	int rowContainsArray = 0;
	int arrayType = 0;
	vector<string>preArrayData;

	//行数分繰り返す
	for (int i = 0; i < row; i++) {
		//列数分繰り返す
		for (int j = 0; j < col; j++) {
			//セルの情報を取得
			vector<string> cellData = this->jsonmanager->getGridData(i, j);
			//値を取得
			string value = this->jsonmanager->getGrid(i, j);
			
			if (value != "") {
				//そのセルが配列を示しているとき
				if (isArray(cellData)) {
					arrayType = 0;
					//
					arrayObject.put(*(cellData.end() - 1), value);
					//要素がオブジェクトではないなら
					if (*(cellData.end() - 1) == "") {
						//
						arraytree.push_back(make_pair("", arrayObject));
						arrayType = 1;
					}
					preArrayData = cellData;
					//
					rowContainsArray = 1;
				}
				//配列ではなく、通常の要素の時
				else {
					//
					jsonmanager->json.add(createAcsessKey(cellData, 0), value);
				}
			}
		}
		//その行内に一つでも配列の要素があれば
		if (rowContainsArray == 1) {
			//オブジェクトの時
			if (arrayType == 0) {
				arraytree.push_back(make_pair("", arrayObject));
			}
			else {
				jsonmanager->json.add_child(createAcsessKey(preArrayData, 1), arraytree);
				arraytree.clear();
			}
			rowContainsArray = 0;
		}
		arrayObject.clear();
	}
	if (!arraytree.empty() && arrayType == 0) {
		jsonmanager->json.add_child(createAcsessKey(preArrayData, 1), arraytree);
	}
	write_json("data.json", jsonmanager->json);
}

void GridJSONCreator::GridClear(int rowN, int colN)
{
	this->jsonmanager->grid->GridClear(rowN, colN);
}
