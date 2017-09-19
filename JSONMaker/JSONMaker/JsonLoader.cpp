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
	hierarchyKeys = vector<string>(15);

	//セットされたファイルパスを取得
	std::string path = this->jsonmanager->getJsonFilePath();
	//そのパスでjson読み込み
	read_json(path, jsonmanager->json);
	//何階層目かの数値を0でリセット
	jsonLevel = 0;
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
	this->hierarchyKeys.clear();
	this->cellKeys.clear();
	this->preCellKeys.clear();
}

/*
階層のキー群から必要な部分だけを取り出す関数
9月12日(火)
成田修之
*/
vector<string> keyRemvFromHierarchy(const vector<string>& hierarchy, int jsonlevel) {
	return vector<string>(hierarchy.begin(), hierarchy.begin() + jsonlevel + 1);
}

void JsonLoader::returnRow() {
	//次の行に行くためにインクリメント
	setGridRowN++;
	//
	this->jsonmanager->setGridRowLen(setGridRowN);
	//
	if (jsonmanager->getGridColLength() < setGridColN) {
		//
		this->jsonmanager->setGridColLen(setGridColN);

	}
	//改行するので列の値は0に
	setGridColN = 0;
}


/*
関数名
概要
*/
std::vector<std::string> JsonLoader::getNodes()
{
	//
	vector<string> retVec;
	//
	BOOST_FOREACH(const ptree::value_type& child, jsonmanager->json) {
		//
		retVec.push_back(child.first);
	}
	//
	return retVec;
}



string preKey;
/*
関数名:loadJson
概要:既存のJSONファイルを読み込んで表にセットする関数
引数:property_tree json　JSONファイル中の選択されたノード
返却値:無し
作成者:成田修之
作成日:9月13日(水)
*/
void JsonLoader::loadJson(boost::property_tree::ptree json) {
	//受け取ったJsonについて第一階層ループ
	BOOST_FOREACH(const ptree::value_type& child, json) {
		//キーを階層のキーに格納
		hierarchyKeys[jsonLevel] = child.first;
		//配列の時
		if (child.first == "") {
			//要素がオブジェクトの時
			if (child.second.data().empty()) {
				BOOST_FOREACH(const ptree::value_type& arrayObject, child.second) {
					//キーを階層のキー群に格納
					hierarchyKeys[jsonLevel + 1] = arrayObject.first;
					//値を表出力部として格納
					jsonmanager->setGrid(setGridRowN, setGridColN, arrayObject.second.data());
					//キー群をセルの情報として格納
					jsonmanager->setGridData(setGridRowN, setGridColN, keyRemvFromHierarchy(hierarchyKeys, jsonLevel + 1));
					//次の列に移動
					setGridColN++;
				}

				returnRow();
			}
			//要素がオブジェクトではなく通常の要素
			else {
				//その階層までのキー群を今回のキーとして保管
				cellKeys = vector<string>(hierarchyKeys.begin(), hierarchyKeys.begin() + jsonLevel + 1);

				//配列を示すキーを後ろに格納
				hierarchyKeys[jsonLevel + 1] = constants.KEY_ISARRAY;
				//前のセルと比べて同じ行かどうか判定する
				if (!isSameRow(cellKeys, preCellKeys) || jsonLevel == 1) {
					returnRow();
					preKey == "";
				}
				//値を表出力部として格納
				jsonmanager->setGrid(setGridRowN, setGridColN, child.second.data());
				//キー群をセルの情報として格納
				jsonmanager->setGridData(setGridRowN, setGridColN, keyRemvFromHierarchy(hierarchyKeys, jsonLevel + 1));
				//次の列へ
				setGridColN++;
				preKey = "disp";
			} //配列内要素終了
		}
		//子がある時
		else if (!child.second.empty() && child.second.data().empty()) {
			//さらに潜るために階層の値をインクリメント
			jsonLevel++;
			//子に対して再帰処理
			loadJson(child.second);
			//抜け出したら階層の値をもとに戻す
			jsonLevel--;
		}
		//配列でも子でもないとき(最下層の値)
		else {
			//その階層までのキー群を今回のキーとして保管
			cellKeys = vector<string>(hierarchyKeys.begin(), hierarchyKeys.begin() + jsonLevel + 1);
			//前のセルと比べて同じ行かどうか判定する
			if (!isSameRow(cellKeys, preCellKeys)) {
				returnRow();
				preKey == "";
			}
			//表の値としてセット
			jsonmanager->setGrid(setGridRowN, setGridColN, child.second.data());
			//階層のキーからデータをセット
			jsonmanager->setGridData(setGridRowN, setGridColN, keyRemvFromHierarchy(hierarchyKeys, jsonLevel));
			//表に表示させるものとしてセットするための変数を次の列へ
			setGridColN++;

		}
		//次に行く前に今回のキー群を前回のキーとして保管
		preCellKeys = cellKeys;
	} //受け取ったJSONの第一階層完了
}


bool JsonLoader::isSameRow(const vector<string> &thistime, const vector<string> &pre) {
	int thisSize = thistime.size();
	int preSize = pre.size();
	//一番初めでまだ前のキーがないとき
	if (preSize < 1) {
		//同じ行で継続
		return true;
	}

	//比較するキーのインデックスを取得（サイズの大きいほうの配列の後ろから3番目のキーについて比較）
	int compNum = (thisSize > preSize ? thisSize : preSize) - 3;

	//一番上のキーが違えば改行
	if (thistime[0] != pre[0]) {
		//改行です
		return false;
	}
	if (compNum < 0) {
		return true;
	}
	//前回か、今回の配列がインデックスより小さいとき同じ行で
	if (preSize < compNum || thisSize < compNum) {
		return true;
	}
	//比べるべきキーのところが違っていれば改行
	else if (thistime[compNum] != pre[compNum]) {
		return false;
	}
	return true;
}