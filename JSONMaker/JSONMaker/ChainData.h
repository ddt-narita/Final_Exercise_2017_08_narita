#pragma once
#include <string>
#include "boost\property_tree\ptree.hpp"
#include "Constants.h"

class ChainData
{
public:
	//コンストラクタ
	ChainData();
	//デストラクタ
	~ChainData();

	//キー
	std::string key;
	//値
	std::string value;
	//有効なセルかどうかを示す
	bool valid;
	//前に挿入するか後ろに挿入するか
	enum FrontBack {
		Front,
		Back
	};

	//上へのポインタ(兄)
	ChainData* upper;
	//下へのポインタ(弟)
	ChainData* under;
	//右へのポインタ(子)
	ChainData* right;
	//左へのポインタ(親)
	ChainData* left;

	//前に挿入する関数
	ChainData* insertFront();
	//後ろに挿入する関数
	ChainData* insertBack();
	//挿入をする(引数で前後ろ決定)
	ChainData* insert(FrontBack);
	//削除する
	void remove();
	//行を挿入する
	ChainData* insertRow(int row, FrontBack);
	//列を挿入する
	void insertCol(int col, FrontBack);
	//行を削除する
	void removeRow(int row);
	//列を削除する
	void removeCol(int col);
	//親を作成する
	ChainData* createParent();
	//子を作成する
	ChainData* createChild();
	//親を取り除いて兄弟を親の兄弟へ繰り上げ
	void removeParent();

	//行列指定してその位置のセルを取得する
	ChainData* getCell(int row, int col);
	//長男のセルを取得する関数
	ChainData* getFirstBro();
	//末の弟を取得する関数
	ChainData* getLastBro();
	//行と列指定したセルのキーを取得
	std::string getKey(int row, int col);
	//
	void setKey(int row, int col, std::string value);
	//
	std::string getValue(int row, int col);
	//
	void setValue(int row, int col, std::string value);
	
	//セルの右に追加する
	void addRight(ChainData* temp);
	//セルの左に追加する
	void addLeft(ChainData* temp);
	//セルの上に追加する
	void addUpper(ChainData* temp);
	//セルの下に追加する
	void addUnder(ChainData* temp);
	//子の数を取得する
	int getChildCount();
	//親の数を取得する
	std::vector<ChainData*> getParents();

	//オブジェクトかどうかを判定する
	bool isObject();
	//有効なセルかどうか判定する
	bool isValid();
	//セルが配列へのものかどうか判定する
	bool isCellToArray();
	//セルがオブジェクト配列へのものかどうか判定
	bool isCellToObjectArray();
	//
	bool isEmptyCellToObjectArray();
};

