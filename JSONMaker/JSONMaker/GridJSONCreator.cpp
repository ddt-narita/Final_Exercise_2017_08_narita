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
	//そのJSONオブジェクトを環境クラスに保存しておいた保存先のパス書き出す
	write_json(jsonmanager->env.jsonSavePath, json);
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
string GridJSONCreator::createAcsessKey(vector<string> keyarray, int level, std::string delimiter) {
	//返却するキー
	string acsesskey;
	//引数の値分繰り返す
	for (int i = 0; i < level; i++) {
		//返却するキーが空でなければ(一番初めではなければ)
		if ("" != acsesskey && "" != keyarray[i]) {
			//アクセス可能なようにカンマで区切る
			acsesskey += delimiter;
		}
		//キーを上から順に継ぎ足していく
		acsesskey += keyarray[i];
	}
	return acsesskey;
}



string GridJSONCreator::createErrorMessage(ChainData* cell, string errorMessage) {
	//返却するエラーメッセージを格納する変数
	string retErrorMsg;
	//引数のセルの親群を取得
	vector<ChainData*> parents = cell->getParents();
	//親群のキーたちを取得する配列
	vector<string> parentkeys(parents.size());
	//親の数だけ繰り返す
	for (int i = 0; i < parents.size(); i++) {
		//キーを格納していく
		parentkeys[i] = parents[i]->key;
	}
	//キーの配列でパスを作成
	string path = createAcsessKey(parentkeys, parentkeys.size(), "-");
	//文字列を格納していく
	retErrorMsg = "\nパス：" + path + "\nキー：" + cell->key +"\n値：" + cell->value + "\n" + errorMessage;
	//エラーメッセージを返却する
	return retErrorMsg;
}

/*
関数名:checkBroKey
概要:引数のセルの兄弟のキーをチェックする
引数:ChainData* cell兄弟について調べたいセル
返却値:無し
作成日:10月4日(水)
作成者:成田修之
*/
void GridJSONCreator::checkBroKey(ChainData * cell)
{
	//引数のセルの長男のセルを取得する
	ChainData* current = cell->getFirstBro();
	//長男のセルが空なら０、空でないなら1を判定用の大元変数に保管
	int judge = "" == current->key ? 0 : 1;
	//カレントがナルになるまで繰り返す
	while (nullptr != current) {
		//カレントのセルが有効ではない
		if (!current->isValid()) {
			//弟へ移動する
			current = current->under;
			//処理を行わず、弟へ
			continue;
		}
		//カレントのキーが空なら0を空でないなら1を比較用変数に格納する。
		int comp = "" == current->key ? 0 : 1;
		//判定用変数と比較用変数が一致しないとき
		if (judge != comp) {
			//例外を送出する
			throw exception(createErrorMessage(current, constants.Message_check_bro_error).c_str());
		}
		//弟へ移動する
		current = current->under;
	}
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
	//引数のセルの兄弟をチェックする
	checkBroKey(cellToArray);
	//配列のJSONを格納するためのJSONオブジェクト
	ptree arrayJson;
	//配列の要素を格納するためのJSONオブジェクト
	ptree objectEle;

	//子の数だけ繰り返す
	for (int i = 0; i < cellToArray->getChildCount(); i++) {
		//配列の要素にキーが入力されているセルがある時
		if ("" != childCurrent->key) {
			//メッセージを添えて例外を送出する
			throw exception(createErrorMessage(childCurrent,constants.MESSAGE_ARRAY_ERROR).c_str());
		}
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
	//子カレントをチェックする
	checkBroKey(childCurrent);
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
			//オブジェクト配列にキーのない要素が入力されたとき
			if ("" == GchildCurrent->key) {
				//メッセージを添えて例外を送出する
				throw exception(createErrorMessage(GchildCurrent, constants.MESSAGE_OBJECT_ARRAY_ERROR).c_str());
			}
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
	//引数のセルの兄弟をチェックする
	checkBroKey(cell);
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
		string acsesskey = createAcsessKey(keyHierarchy, level + 1, ".");
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


