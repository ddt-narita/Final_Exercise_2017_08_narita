#include "ChainData.h"

using namespace std;

ChainData::ChainData()
{
	this->key = "";
	this->value = "";
	this->valid = true;
	this->right = nullptr;
	this->left = nullptr;
	this->upper = nullptr;
	this->under = nullptr;
}


ChainData::~ChainData()
{
	if (nullptr != this->right) {
		delete this->right;
	}
	if (nullptr != this->under) {
		delete this->under;
	}
}



//前に挿入する
ChainData * ChainData::insertFront()
{
	//指定されたセルを取得する
	ChainData* selectedCell = this;
	//挿入するセル
	ChainData* insertCell = new ChainData();

	//兄がないとき（長男のセルの時）
	if (nullptr == selectedCell->upper) {
		//親のセルを取得
		ChainData* parent = selectedCell->left;
		//親の子として挿入するためのセルを追加する
		parent->addRight(insertCell);
		//挿入したセルの下に選択されたセルを追加
		insertCell->addUnder(selectedCell);
	}
	//長男のセルではない
	else {
		//上（兄）のセルを取得する
		ChainData* upper = selectedCell->upper;
		//上のセルの下に挿入するセルを追加する
		upper->addUnder(insertCell);
		//挿入したセルの下に選択されたセルを追加する
		insertCell->addUnder(selectedCell);
		//兄のセルが無効なら挿入したセルも無効に
		if (!upper->valid) {
			insertCell->valid = false;
		}
	}
	//挿入したセルを返す
	return insertCell;
}

//後に挿入する
ChainData * ChainData::insertBack()
{
	//選択されたセルを取得する
	ChainData* selectedCell = this;
	//挿入するためのセル
	ChainData* insertCell = new ChainData();

	//選択されたセルの下にセルが存在する
	if (nullptr != selectedCell->under) {
		//下のセルを取得する
		ChainData* under = selectedCell->under;
		//選択されたセルの下に挿入するためのセルを追加して挿入
		selectedCell->addUnder(insertCell);
		//挿入したセルの下に下のセルを追加
		insertCell->addUnder(under);
	}
	//下のセルが存在しない
	else {
		//選択されたセルの下に挿入するためのセルを追加する
		selectedCell->addUnder(insertCell);
	}
	//兄のセルが無効なら挿入したセルも無効に
	if (!selectedCell->valid) {
		insertCell->valid = false;
	}

	//挿入したセルを返却する
	return insertCell;
}

/*
関数名:insert
概要:前か後に挿入する関数
引数:ChainData::FrontBacm fb　前か後か
返却値:ChainData* insertCell　挿入したセル
作成日:10月2日(月)
作成者:成田修之
*/
ChainData * ChainData::insert(FrontBack fb)
{
	//挿入したセルを取得して返すための変数
	ChainData* insertCell;
	//引数の値が前を示していたら
	if (FrontBack::Front == fb) {
		//前への追加関数を実行
		insertCell = insertFront();
	}
	//後ろを示しているとき
	else {
		//後ろへの追加関数を実行
		insertCell = insertBack();
	}
	//挿入したセルを返却する
	return insertCell;
}


//選択されたセルを削除する
void ChainData::remove()
{
	//指定のセルを取得する
	ChainData* selectedCell = this;
	
	//兄のいないセルなら
	if (nullptr == selectedCell->upper) {
		//親のセルを取得する
		ChainData* parent = selectedCell->left;
		//下のセルがあるなら
		if (nullptr != selectedCell->under) {
			//親のセルの子として下のセルを追加
			parent->addRight(selectedCell->under);
			//宙ぶらりんになってしまう下のセルの上へのポインタをnullにする
			selectedCell->under->upper = nullptr;
			//弟を指したままだと消してしまうのでナル代入
			selectedCell->under = nullptr;
		}
		else {
			//親が指していた自身へのポインタをナルにする
			parent->right = nullptr;
		}

	}
	//兄のいるセルなら
	else {
		//兄のセルを取得して
		ChainData* bro = selectedCell->upper;
		//下のセルがあるなら
		if (nullptr != selectedCell->under) {
			//兄のセルの弟として下のセルを格納
			bro->addUnder(selectedCell->under);
			//弟を指したままだと消してしまうのでナル代入
			selectedCell->under = nullptr;
		}
		else {
			//兄が指していた自分へのポインタをナルにする
			bro->under = nullptr;
		}
	}
	//選択されたセルを破棄する
	delete selectedCell;
}

ChainData * ChainData::insertRow(int row, FrontBack fb)
{
	ChainData* rowHead = this->getCell(row, 0);
	//その行の先頭のセルに対して引数の前後ろを渡して挿入する
	ChainData* insertRowHead = rowHead->insert(fb);
	
	//行を追加したので行数を+1する
	//行の先頭のセルを返却する
	return insertRowHead;
}

void ChainData::removeRow(int row)
{
	ChainData* rowHead = this->getCell(row, 0);
	//その行の先頭のセルに対して削除を行う
	rowHead->remove();

}

void ChainData::insertCol(int col, FrontBack fb)
{
	//一行目については仕様から後ろに追加（2行目について挿入のためこの処理に）
	if (0 == col) {
		col = 1;
		fb = ChainData::FrontBack::Front;
	}
	int row = getChildCount();
	//行数分繰り返す
	for (int i = 0; i < row; i++) {
		ChainData* colCell = this->getCell(i, col);
		//そのセルに対して引数の前後ろを渡して挿入する
		colCell->insert(fb);
	}
}

void ChainData::removeCol(int col)
{
	//一列目については仕様から後ろを削除（2列目について削除のためこの処理に）
	if (0 == col) {
		col = 1;
	}
	int row = getChildCount();
	//行数分繰り返す
	for (int i = 0; i < row; i++) {
		ChainData* colCell = this->getCell(i, col);
		//そのセルに対して削除する
		colCell->remove();
	}
}

ChainData * ChainData::createParent()
{
	ChainData* insertCell = new ChainData();
	//長男のセルの時
	if (nullptr == this->upper) {
		//親のセルを取得
		ChainData* parent = this->left;
		//親の子として挿入するセルを追加
		parent->addRight(insertCell);

		//下にセルがあれば
		if (nullptr != this->under) {
			//下のセルを取得
			ChainData* under = this->under;
			//追加したセルの下にそのセルを追加
			insertCell->addUnder(under);
		}
	}
	//長男ではないとき
	else {
		//上の兄のセルを取得
		ChainData* bro = this->upper;
		//兄の下に新しいセルを追加
		bro->addUnder(insertCell);
		//下にセルがある時
		if (nullptr != this->under) {
			//下のセルを取得
			ChainData* under = this->under;
			//新しいセルの下にそれを追加
			insertCell->addUnder(under);
		}
	}
	//選択されたセルの下をnullに
	this->under = nullptr;
	//挿入したセルの子として自信を格納する
	insertCell->addRight(this);
	//挿入したセルを返す
	return insertCell;
}

/*
*/
ChainData * ChainData::createChild()
{
	//挿入する新しいセル
	ChainData* insertCell = new ChainData();
	//子を取得
	ChainData* child = this->right;

	this->addRight(insertCell);

	//子がきちんと取得できていたら
	if (nullptr != child) {
		//挿入したセルの子として格納する
		insertCell->addRight(child);
	}
	//挿入したセルを返却する
	return insertCell;
}


ChainData * ChainData::getCell(int row, int col)
{
	//このクラスへのポインタを取得
	ChainData* current = this->right;
	//指定の行数分繰り返す(-1は1行目は移動内容に調整)
	for (int i = 0; i < row; i++) {
		//下のセルに移動
		current = current->under;
	}

	//列数が子を取得するほうまで行ってたら(2列目以降を取得しようとしているなら)
	if (col > 0) {
		//子に降りて
		current = current->right;
		//指定の列数分繰り返す
		for (int j = 1; j < col; j++) {
			//兄弟を移動
			current = current->under;
		}
	}
	//そのセルを返却する
	return current;
}

std::string ChainData::getKey(int row, int col)
{
	//
	ChainData* current = getCell(row, col);
	// 
	return current->key;
}

void ChainData::setKey(int row, int col, std::string value)
{
	//
	ChainData* current = getCell(row, col);
	// 
	current->key = value;
}

std::string ChainData::getValue(int row, int col)
{
	return getCell(row,col)->value;
}

void ChainData::setValue(int row, int col, std::string value)
{
	getCell(row, col)->value = value;
}

void ChainData::addRight(ChainData * temp)
{
	temp->left = this;
	this->right = temp;
}

void ChainData::addLeft(ChainData * temp)
{
	temp->right = this;
	this->left = temp;
}

void ChainData::addUpper(ChainData * temp)
{
	//引数のセルの下のセルとしてこのセルを格納
	temp->under = this;
	//このセルの上のセルとして引数のセルを格納する
	this->upper = temp;
}

void ChainData::addUnder(ChainData * temp)
{
	//引数の上のセルとしてこのセルを格納
	temp->upper = this;
	//このセルの下のセルとして引数のセルを格納
	this->under = temp;
}

/*
関数名:getChildCount
概要:子の数を数えて返す
引数:無し
返却値:int childCount 子の数
作成日:9月26日(火)
作成者:成田修之
*/
int ChainData::getChildCount()
{
	//カレントのセルとして保管
	ChainData* current = this;
	//子のセルを取得
	ChainData* child = current->right;

	//カウントする変数
	int childCount = 0;
	//子をすべて走査
	while(child != nullptr && child->isValid()) {
		//次の子へ
		child = child->under;
		//カウントする
		childCount++;
	}
	//カウントした値を返却する
	return childCount;

}


/*
関数名:getParentPath
概要:一番上からそのセルまでのパスを取得する
引数:なし
返却値:vector<string> retPath 一番上の親からのパス
作成日:9月30日(土)
作成者:成田修之
*/
std::vector<ChainData*> ChainData::getParents()
{
	//返却するパスが上から入った配列
	vector<ChainData*> retPath;
	//自身を親のカレントとして取得
	ChainData* parentCurrent = this;
	//親がナルを指すまで繰り返す
	while (nullptr != parentCurrent) {
		//親に移った後子のカレントを用意してそれを子のカレントに
		ChainData* childCurrent = parentCurrent;
		//子について兄がナルを指すまで繰り返す
		while (nullptr != childCurrent->upper) {
			//兄に移動する
			childCurrent = childCurrent->upper;
		}
		//親のカレントをいまの子のカレントの親に設定
		parentCurrent = childCurrent->left;
		//親がきちんとあるなら
		if (nullptr != parentCurrent) {
			//用意した配列の先頭を取得して
			auto ite = retPath.begin();
			//先頭にキーを格納する
			retPath.insert(ite, parentCurrent);
		}
	}
	//作成した配列を返却する
	return retPath;
}

/*
関数名:isObject
概要:そのセルがオブジェクトかどうかを判定
引数:無し
返却値:bool オブジェクトの条件に当てはまるかどうか
作成日:9月28日(木)
作成者:成田修之
*/
bool ChainData::isObject()
{
	//子があり、子が有効かどうかで判定
	return this->right != nullptr && this->right->isValid();
}

/*
関数名:isValid
概要:有効なセルかどうか判定する関数
引数:無し
返却値:bool 有効かどうか判定
作成日:9月28日(木)
作成者:成田修之
*/
//有効であるかどうかを判定する
bool ChainData::isValid()
{
	//キーと値に無効なセルであることを示す値が入力されていないかどうかを返却する
	return valid;
}


/*
関数名:isArray
概要:配列へのセルであることを判定する
引数:bool 配列へのセルかどうか
返却値:無し
作成日:9月29日(金)
作成者:成田修之
*/
bool ChainData::isCellToArray()
{
	//子がないとき
	if (nullptr == this->right) {
		//配列へのセルではない
		return false;
	}
	//配列の要素である子を取得
	ChainData* child = this->right;
	//要素のセルがキーが空で値はあり、そのさらに子は存在しない,またあっても有効でないとき
	if ("" == child->key && "" != child->value && (nullptr == child->right || !child->right->isValid())) {
		//通常の配列へのセルであることを返す
		return true;
	}
	//それ以外は違うことを返す
	return false;
}

/*
関数名:isArray
概要:オブジェクト配列へのセルであることを判定する
引数:bool オブジェクト配列へのセルかどうか
返却値:無し
作成日:9月29日(金)
作成者:成田修之
*/
bool ChainData::isCellToObjectArray()
{
	//子がないとき
	if (nullptr == this->right) {
		//確実に違うのでfalseを返す
		return false;
	}
	//返却する真理値を返すための変数
	int retVal = 0;
	//子を取得する
	ChainData* child = this->right;
	//子のキーが空でない
	if ("" != child->key) {
		//オブジェクト配列の条件には合わない
		retVal = 0;
	}
	//孫がいないとき
	else if(nullptr == child->right || !child->right->isValid()) {
		//条件に合わない
		retVal = 0;
	}
	//孫がいる時
	else {
		//孫を取得して
		ChainData* Gchild = child->right;
		//孫のキーと値が入力されていて、そのさらに子は存在しないか無効の時
		if ((nullptr == Gchild->right || !Gchild->right->isValid())) {
			//オブジェクト配列へのセルであることを返す
			retVal = 1;
		}
	}
	//すべてに当てはまらなければfalseを返す
	return retVal == 1;
}

bool ChainData::isEmptyCellToObjectArray()
{
	//返却する真理値に用いる値
	int retVal = 1;
	//キーが空でないとき
	if ("" != this->value) {
		//確実に違うのでそのことを返す
		return false;
	}

	//自身を取得してカレントとする
	ChainData* current = this;
	//兄がいなくなるまでさかのぼって長男を取得
	while (nullptr != current->upper)
	{
		//兄へ移動
		current = current->upper;
	}

	//カレントがナルになるまで繰り返す
	while (nullptr != current) {
		//カレントのセルのキーに空でないものがあるなら
		if ("" != current->key) {
			//返却に用いる値にfalseを表す値を格納
			retVal = 0;
			//ループを抜ける
			break;
		}
		//弟に移動する
		current = current->under;
	}

	//trueを示す値と等しいかどうかで判定を返す
	return retVal == 1;
}


