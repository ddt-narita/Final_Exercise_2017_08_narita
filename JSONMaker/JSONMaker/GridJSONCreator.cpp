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
関数名:job
概要:JSON作成の一連の処理を行う関数
引数:無し
返却値:無し
作成日:9月27日(水)
作成者:成田修之
*/
void GridJSONCreator::job(ChainData* cell) {

	keyHierarchy = vector<string>(15);
	level = 0;
	ptree json;
	CreateJSON(cell, json);

	keyHierarchy.clear();
	level = 0;
	//そのJSONオブジェクトを書き出す
	write_json("data.json", json);
	json.clear();
	jsonmanager->json.clear();
}

/*
関数名:createAcsessKey
概要:
引数:vector<string> keyarray　階層ごとのキー配列
	 int level　階層の値
返却値:string 返却するアクセスするためのキー
作成日:9月28日(木)
作成者:成田修之
*/
string GridJSONCreator::createAcsessKey(vector<string> keyarray, int level) {
	//返却するキー
	string acsesskey;
	try {//引数の階層の値分繰り返す
		for (int i = 0; i < level; i++) {
			//返却するキーが空でなければ(一番初めではなければ)
			if ("" != acsesskey) {
				//アクセス可能なようにカンマで区切る
				acsesskey += ".";
			}
			//キーを上から順に継ぎ足していく
			acsesskey += keyarray[i];
		}
	}
	catch (exception& e) {
		int i = 0;
	}
	return acsesskey;
}

/*
*/
void createObjectArrayJson(ChainData* cellToObjectArray, ptree json) {

}

/*
関数名:CreateJSON
概要:GridManagerに格納された情報から実際にJSONを作成する
引数:なし
返却値:なし
作成者:成田修之
作成日:9月28日(木)
*/
void GridJSONCreator::CreateJSON(ChainData* cell, ptree& json)
{
	try {
		//兄弟すべて走査
		while (nullptr != cell && cell->isValid()) {
			if (keyHierarchy[0] != "" && level == 0) {
				return;
			}
			
			//値を階層のキーとして保管する
			keyHierarchy[level] = constants.SjistoUTF8(cell->key);
			//その階層までのキーからアクセスするためのキー文字列を作成する
			string acsesskey = createAcsessKey(keyHierarchy, level + 1);
			


			//オブジェクト配列へのセル先頭のセルの時
			if (cell->isCellToObjectArray()) {
				//子を取得して子カレントに
				ChainData* childCurrent = cell->right;
				//オブジェクト配列を格納するJSONオブジェクト
				ptree objectArray;
				//子の数だけ繰り返す
				for (int i = 0; i < cell->getChildCount(); i++) {
					//孫を取得して孫カレントにする
					ChainData* GchildCurrent = childCurrent->right;
					//オブジェクト配列の要素を格納するためのJSONオブジェクト
					ptree ObjectArrayEle;
					//孫の数だけ繰り返す
					for (int j = 0; j < childCurrent->getChildCount(); j++) {
						//オブジェクト配列の要素として孫のキーと値を格納する
						ObjectArrayEle.put(constants.SjistoUTF8(GchildCurrent->key), constants.SjistoUTF8(GchildCurrent->value));
						//孫をその兄弟に移動
						GchildCurrent = GchildCurrent->under;
					}
					//孫でできた要素を空のキーのオブジェクトに格納する
					objectArray.push_back(make_pair("", ObjectArrayEle));
					//
					ObjectArrayEle.clear();
					//子をその兄弟に移動する
					childCurrent = childCurrent->under;
				}
				//子と孫でできたオブジェクト配列をそれまでのキー配下に格納する
				json.put_child(acsesskey, objectArray);
			}
			//通常配列へのセルの時
			else if (cell->isCellToArray()) {
				//子を取得して子カレントとする
				ChainData* childCurrent = cell->right;
				//配列のJSONを格納するためのJSONオブジェクト
				ptree arrayJson;
				//配列の要素を格納するためのJSONオブジェクト
				ptree objectEle;
				//子の数だけ繰り返す
				for (int i = 0; i < cell->getChildCount(); i++) {
					//要素としてキーと値を格納する
					objectEle.put(constants.SjistoUTF8(childCurrent->key), constants.SjistoUTF8(childCurrent->value));
					//配列を示すため空のキーと作ったオブジェクトのペアを格納
					arrayJson.push_back(make_pair("", objectEle));
					//兄弟に移動
					childCurrent = childCurrent->under;
				}
				//子でできた空の配列へのキーをそれまでのキーはいかに格納する
				json.put_child(acsesskey, arrayJson);
			}
			//子がある時
			else if (nullptr != cell->right && cell->right->isValid()) //子が通常通りある時
			{
				//子について行うので階層の値を+1
				level++;
				//子について再帰処理を行う
				CreateJSON(cell->right, json);
				//子について抜け出したので階層の値を元に戻す
				level--;
			}
			//最下層の値の時
			else {
				//それまでのキー配下に格納する
				json.put(acsesskey, constants.SjistoUTF8(cell->value));
			}
			//次の兄弟へ移動する
			cell = cell->under;
		}
	}
	catch (std::exception& e) {
		//
		string Message = "階層：" + to_string(level) + "　値：" + cell->key;
		//
		throw exception(Message.c_str());
	}
}


