# define BOOST_ENABLE_ASSERT_HANDLER
#include <boost/assert.hpp>

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

namespace boost {

	/*
	ブースとのアサートを定義
	主に配列以外で空のキーに子を格納しようとしたときに起こる
	*/
	void assertion_failed(const char* expr, const char* function, const char* file, long line)
	{
		//例外を送出する
		throw std::exception();
	}
}



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
	//階層のキー群を格納する配列
	keyHierarchy = vector<string>(15);
	//階層の値
	level = 0;
	//書き込む対象
	ptree json;
	//引数のセルから書き込み対象にJSONを書きこむ
	CreateJSON(cell, json);

	//階層のキー群配列をクリア
	keyHierarchy.clear();
	//階層の値を元に戻す
	level = 0;
	//そのJSONオブジェクトを書き出す
	write_json("data.json", json);
	//書き込んだオブジェクトをクリア
	json.clear();
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
			if ("" != acsesskey && "" != keyarray[i]) {
				//アクセス可能なようにカンマで区切る
				acsesskey += ".";
			}
			//キーを上から順に継ぎ足していく
			acsesskey += keyarray[i];
		}
	}
	//例外が発生したとき
	catch (exception& e) {
		int i = 0;
	}
	return acsesskey;
}


/*
関数名: createArrayJson
概要:配列のJSONを作成する
引数:string acsesskey 作成したJSONを格納するパス
ChainData* cell　配列への先頭のセル
ptree& json	JSONを書き込む対象
返却値:なし
作成日:10月2日(月)
作成者:成田修之
*/
void GridJSONCreator::createArrayJson(std::string acsessKey, ChainData * cellToArray, ptree & json)
{
	//子を取得して子カレントとする
	ChainData* childCurrent = cellToArray->right;
	//配列のJSONを格納するためのJSONオブジェクト
	ptree arrayJson;
	//配列の要素を格納するためのJSONオブジェクト
	ptree objectEle;
	//子の数だけ繰り返す
	for (int i = 0; i < cellToArray->getChildCount(); i++) {
		//要素としてキーと値を格納する
		objectEle.put(constants.SjistoUTF8(childCurrent->key), constants.SjistoUTF8(childCurrent->value));
		//配列を示すため空のキーと作ったオブジェクトのペアを格納
		arrayJson.push_back(make_pair("", objectEle));
		//兄弟に移動
		childCurrent = childCurrent->under;
	}
	//子でできた空の配列へのキーをそれまでのキーはいかに格納する
	json.put_child(acsessKey, arrayJson);
}

/*
関数名:createObjectJson
概要:オブジェクト配列のJSONを作成する
引数:string acsesskey　作成したJSONを格納するパス
	ChainData* cell　オブジェクト配列への先頭のセル
	ptree& json	JSONを書き込む対象
返却値:なし
作成日:10月2日(月)
作成者:成田修之
*/
void GridJSONCreator::createObjectArrayJson(std::string acsessKey, ChainData* cellToObjectArray, ptree& json) {
	//子を取得して子カレントに
	ChainData* childCurrent = cellToObjectArray->right;
	//オブジェクト配列を格納するJSONオブジェクト
	ptree objectArray;
	//子の数だけ繰り返す
	for (int i = 0; i < cellToObjectArray->getChildCount(); i++) {
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
	json.put_child(acsessKey, objectArray);
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
		while (nullptr != cell) {
			//階層のキーに値があり、階層が最初の時(2個目のトップノード)
			if (keyHierarchy[0] != "" && level == 0) {
				//処理をやめる
				return;
			}
			//セルが有効でないなら
			if (!cell->isValid()) {
				//次の兄弟へ移動する
				cell = cell->under;
				//この回を飛ばして次へ
				continue;
			}
			//値を階層のキーとして保管する
			keyHierarchy[level] = constants.SjistoUTF8(cell->key);
			//その階層までのキーからアクセスするためのキー文字列を作成する
			string acsesskey = createAcsessKey(keyHierarchy, level + 1);
			//オブジェクト配列への先頭のセルの時
			if (cell->isCellToObjectArray()) {
				//オブジェクト配列のJSONを作成する
				createObjectArrayJson(acsesskey, cell, json);
			}
			//通常配列へのセルの時
			else if (cell->isCellToArray()) {
				//配列のJSONを作成する
				createArrayJson(acsesskey, cell, json);
			}
			//配列やオブジェクト配列でない子がある時
			else if (cell->isObject()) //子が通常通りある時
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
	//例外が発生したとき
	catch (std::exception& e) {
		//その階層とそのセルの値を格納したメッセージを用意
		string Message = "階層：" + to_string(level) + "　値：" + cell->key;
		//メッセージで初期化した例外を送出する
		throw exception(Message.c_str());
	}
}


