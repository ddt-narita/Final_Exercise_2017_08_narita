#include "CellChain.h"

using namespace System;
using namespace System::Collections;

/*
関数名:コンストラクタ
概要:コンストラクタ
引数:無し
返却値:無し
作成者:成田修之
作成日:9月20日(水)
*/
CellChain::CellChain()
{
	//セルのキー群としての配列を格納する
	CellKey = gcnew array<String^>(1);
	//そのセルの一番初めのキーとして空文字格納する
	CellKey[0] = gcnew String("");
	//そのセルの値として空文字を格納する
	Value = gcnew String("");
}

/*
関数名:insert
概要:行と列指定したセルの左に挿入
引数:int row 行数, int col 列数
返却値:CellChain insertCell　挿入したセル
作成者:成田修之
作成日:9月20日(水)
*/
CellChain^ CellChain::insert(int row, int col)
{
	//指定されたセルを取得する
	CellChain^ temp = getCell(row, col);
	//そのセルの左のセルを取得
	CellChain^ left = temp->left;

	//挿入したいセルを作成する
	CellChain^ insertCell = gcnew CellChain();
	//左のセルにそのセルを追加する
	left->addRight(insertCell);
	//そのセルの右に指定のセルを追加する
	insertCell->addRight(temp);
				
	//挿入したセルを返す
	return insertCell;
}

/*
関数名:remove
概要:指定したセルを削除する関数
引数:int row 行数, int col 列数
返却値:無し
作成者:成田修之
作成日:9月20日(水)
*/
void CellChain::remove(int row, int col)
{
	//指定のセルを取得する
	CellChain^ cell = getCell(row, col);
	//そのセルの右のセルを取得する
	CellChain^ cellRight = cell->right;
	//そのセルの左のセルを取得する
	CellChain^ cellLeft = cell->left;

	//指定のセルを削除する
	delete cell;
	//右のセルと左のセルを結びつける
	cellRight->addLeft(cellLeft);
}

/*
関数名:insertRow
概要:行を挿入する関数
引数:int row　行
返却値:rowHead 挿入した行の先頭のセル
作成者:成田修之
作成日:9月20日(水)
*/
CellChain^ CellChain::insertRow(int row)
{
	//指定の行の一列目のセルを取得する
	CellChain^ cell = getCell(row, 0);
	//そのセルの上のセルを取得
	CellChain^ cellupper = cell->upper;
	//挿入するためのセル
	CellChain^ insert = gcnew CellChain();
	//そのセルを上に格納する
	cell->addUpper(insert);
	//セルの下に格納する
	cellupper->addUnder(insert);
	//行の先頭のセルとして保管しておく
	CellChain^ rowHead = insert;
	//列数分繰り返す
	for (int i = 0; i < colCount; i++) {
		//挿入する行のセルを作成
		CellChain^ insertCell = gcnew CellChain();
		//そのセルを行のセルの右に追加
		insert->addRight(insertCell);
		//次のセルへ移動
		insert = insert->right;
	}
	//行を追加したので行数を+1する
	rowCount++;
	//行の先頭のセルを返却する
	return rowHead;
}

/*
関数名:removeRow
概要:行を取り除く
引数:int row　削除する行
返却値:無し
作成者:成田修之
作成日:9月20日(水)
*/
void CellChain::removeRow(int row)
{
	//指定された行の一番先頭のセルを取得する
	CellChain^ rowCell = getCell(row, 0);
	//そのセルの上のセルを取得
	CellChain^ cellupper = rowCell->upper;
	//そのセルの下のセルを取得
	CellChain^ cellunder = rowCell->under;
	//上のセルの下に下のセルを格納
	cellupper->addUnder(cellunder);
	//一行取り除いたので行数を1減らす
	rowCount--;
	//指定のセルを削除
	delete  rowCell;
}

/*
関数名:insertCol
概要:指定の列の左に列を挿入する関数
引数:int col
返却値:無し
作成者:成田修之
作成日:9月20日(水)
*/
void CellChain::insertCol(int col)
{
	//行数分繰り返す
	for (int i = 0; i < rowCount; i++) {
		//各列の引数の列にセルを挿入する
		this->insert(i, col);
	}
}

/*
関数名:removeCol
概要:指定の列を削除する
引数:int col
返却値:無し
作成者:成田修之
作成日:9月20日(水)
*/
void CellChain::removeCol(int col)
{
	//行数分繰り返す
	for (int i = 0; i < rowCount; i++) {
		//各行の引数の列のセルを削除する
		this->remove(i, col);
	}
}

void CellChain::init(int row, int col)
{
	//移動しないように自分のコピーを取る
	CellChain^ cell = this;
	int n = 0;

	//指定の行数分繰り返す
	for (int i = 0; i < row; i++) {
		//行の一番初めのセルを確保
		CellChain^ cellRowHead = cell;
		cellRowHead->Value = (n++).ToString();
		//指定の列数分繰り返す
		for (int j = 0; j < col-1; j++) {
			//追加させるセル
			CellChain^ temp = gcnew CellChain();
			temp->Value = (n++).ToString();
			//コピーを取ったセルの右に作成したセルを追加する
			cell->addRight(temp);
			//右のセルに移動する
			cell = cell->right;
		}
		//行の先頭に戻る
		cell = cellRowHead;
		//最後の行でなければ
		if (i < row - 1) {
			//下の行にくっつけるセルを作成
			CellChain^ rowCell = gcnew CellChain();
			//rowCell->Value = (n++).ToString();
			//セルの下に追加
			cell->addUnder(rowCell);
			//下の行に移動
			cell = cell->under;
		}
	}
}

/*
関数名:getCell
概要:セルをそのまま取得する関数
引数:int row 行数, int col 列数
返却値:CellChain^　その位置のセルを返却する
作成者:成田修之
作成日:9月20日(水)
*/
CellChain ^ CellChain::getCell(int row, int col)
{
	//このクラスへのポインタを取得
	CellChain^ current = this;
	//指定の行数分繰り返す(-1は1行目は移動内容に調整)
	for (int i = 0; i < row; i++) {
		//下のセルに移動
		current = current->under;
	}

	//指定の列数分繰り返す
	for (int j = 0; j < col; j++) {
		//右のセルに移動
		current = current->right;
	}
	//そのセルを返却する
	return current;
}

/*
関数名:
概要:
引数:int row 行数, int col 列数
返却値:
作成者:成田修之
作成日:9月20日(水)
*/
System::String ^ CellChain::getValue(int row, int col)
{
	//指定の位置のセルを取得する
	CellChain^ current = getCell(row, col);
	//そのセルの値を返却する
	return current->Value;
}

/*
関数名:getCellKey
概要:指定のセルに格納されたキー群を返却する
引数:int row 行数, int col 列数
返却値:array<String^>^　セルに格納されたキー群
作成者:成田修之
作成日:9月20日(水)
*/
array<System::String^>^ CellChain::getCellKey(int row, int col)
{
	//指定の位置のセルを取得する
	CellChain^ current = getCell(row, col);
	//そのセルのキー群を取得する
	return current->CellKey;
}

/*
関数名:setValue
概要:指定のセルに値をセットする
引数:int row 行数, int col 列数
返却値:無し
作成者:成田修之
作成日:9月20日(水)
*/
void CellChain::setValue(int row, int col, String^ value)
{
	//指定の位置のセルを取得する
	CellChain^ current = getCell(row, col);
	//そのセルの値に引数の値をセット
	current->Value = value;
}

/*
関数名:setCellKey
概要:指定のセルにキー群を格納する
引数:int row 行数, int col 列数
返却値:無し
作成者:成田修之
作成日:9月20日(水)
*/
void CellChain::setCellKey(int row, int col, array<String^>^ cellKeys)
{
	//指定の位置のセルを取得する
	CellChain^ current = getCell(row, col);
	//そのセルのキー群に引数のキー群を格納
	current->CellKey = cellKeys;
}

/*
関数名:next
概要:下のセルに移動する
引数:無し
返却値:無し
作成者:成田修之
作成日:9月20日(水)
*/
void CellChain::next()
{
	//下のセルを自分のセルにする
	this->CurrentCell = this->under;
}

/*
関数名:beforeFirst
概要:最初のセルに移動する
引数:なし
返却値:なし
作成者:成田修之
作成日:9月20日(水)
*/
void CellChain::beforeFirst()
{
	//上のセルがナルになるまで繰り返す
	while (this->CurrentCell->upper != nullptr) {
		//現在のセルを上のセルに更新
		this->CurrentCell = this->CurrentCell->upper;
	}
}

/*
関数名:addRight
概要:セルの右に引数のセルをセットする
引数:CellChain^ temp　セットしたいセル
返却値:無し
作成者:成田修之
作成日:9月20日(水)
*/
void CellChain::addRight(CellChain ^ temp)
{
	//引数のセルの左のセルとしてこのセルをセット
	temp->left = this;
	//このセルの右のセルとして引数のセルをセット
	this->right = temp;
}

/*
関数名:addLegt
概要:セルの左に引数のセルをセットする
引数:CellChain^ temp　セットしたいセル
返却値:無し
作成者:成田修之
作成日:9月20日(水)
*/
void CellChain::addLeft(CellChain ^ temp)
{
	//引数のセルの右のセルとしてこのセルを格納
	temp->right = this;
	//このセルの左のセルとして引数のセルを格納する
	this->left = temp;
}

/*
関数名:addUpper
概要:セルの上に引数のセルをセットする
引数:CellChain^ temp　セットしたいセル
返却値:無し
作成者:成田修之
作成日:9月20日(水)
*/
void CellChain::addUpper(CellChain ^ temp)
{
	//引数のセルの下のセルとしてこのセルを格納
	temp->under = this;
	//このセルの上のセルとして引数のセルを格納する
	this->upper = temp;
}

/*
関数名:addUnder
概要:下にセルをセットする
引数:CellChain　セットしたいセル
返却値:無し
作成者:成田修之
作成日:9月20日(水)
*/
void CellChain::addUnder(CellChain ^ temp)
{
	//引数の上のセルとしてこのセルを格納
	temp->upper = this;
	//このセルの下のセルとして引数のセルを格納
	this->under = temp;
}

/*
関数名:getSelectedeColFromRow
概要:結合するとき選択されていたセルの列数を取得する
引数:int row 行
返却値:int col　選択されていた列
作成者:成田修之
作成日:9月20日(水)
*/
int CellChain::getSelectedColFromRow(int row)
{
	//指定の行の先頭のセルを取得する
	CellChain^ cell = getCell(row, 0);
	int col = 0;
	//列数分繰り返す
	for (; col <= colCount; col++) {
		//選択された列が見つかったら
		if (cell->isSelectedCol) {
			//ループを抜ける
			break;
		}
	}
	//ループを抜けたときの見つかったセルの列の値を返却する
	return col;
}

/*
関数名:Clear
概要:表の値を格納するクラスをすべて消去するクラス
引数:無し
返却値:無し
作成者:成田修之
作成日:9月20日(水)
*/
void CellChain::Clear()
{
	//
	delete this->under;
	delete this->right;
	//
	this->Value = "";
	this->CellKey = gcnew array<String^>(1);
	CellKey[0] = "";
	//
	this->isBound = false;
	this->isSelectedCol = false;
	this->rowCount = 0;
	this->colCount = 0;
}

/*
関数名:isCellValid
概要:そのセルがデータを取り出すものとして適切であるかどうかを判定
引数:なし
返却値:bool　適切(有効)かどうかの真理値
作成日:9月22日(金)
作成者:成田修之
*/
bool CellChain::isCellValid()
{
	int retBool = 0;

	for (int i = 1; i < CellKey->Length; i++) {
		if (CellKey[i] != "") {
			break;
			retBool = 1;
		}
	}
	
	if (Value != "") {
		retBool = 1;
	}

	return retBool == 1;
}

/*
関数名:代入演算子
概要:代入演算子を定義
引数:CellChain^　temp
返却値:CellChain^ セルを返却する
作成者:成田修之
作成日:9月20日(水)
*/
CellChain ^ CellChain::operator=(CellChain ^ temp)
{
	//各要素を代入
	this->Value = temp->Value;
	this->CellKey = temp->CellKey;
	this->CurrentCell = temp->CurrentCell;
	this->upper = temp->upper;
	this->under = temp->under;
	this->left = temp->left;
	this->right = temp->right;
	this->isBound = temp->isBound;
	this->isSelectedCol = temp->isSelectedCol;

	return this;
}
