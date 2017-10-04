#include "DataGridSelfMade.h"
#include "Constants.h"

using namespace narita;

/*
関数名:コンストラクタ
概要:描画先のピクチャーボックスを受け取ってこれからはそこへ配置する
引数:PictureBox^ pictureBox　描画したものの配置先
返却値:無し
作成日:9月9日
作成者:成田修之
*/
DataGridSelfMade::DataGridSelfMade(PictureBox^ pictureBox)
{
	//受け取った描画したものを配置するオブジェクトをメンバに共有
	(this->pictureBox) = pictureBox;
	//セルごとのクラス初期化
	//初期列数
	colCount = 1;
	//初期行数
	rowCount = 1;
	//セルの幅
	cellWidth = 120;
	//セルの高さ
	cellHeight = 80;
	//カレントセルを作成
	currentCell = gcnew narita::Cell();

	//セルの枠を描くペンオブジェクトを作成
	cellFramePen = gcnew Pen(Color::Black, 3);
	//文字列を書くときのフォント
	font = gcnew Font("ＭＳ ゴシック", 9);

	//描画対象のイメージオブジェクト
	this->canvas = gcnew Bitmap(this->pictureBox->Width - 1, this->pictureBox->Height - 1);
	//作成したイメージオブジェクトをピクチャボックスに配置
	this->pictureBox->Image = this->canvas;
	//ピクチャボックス描画対象に描くためのオブジェクトを作成
	this->graphic = Graphics::FromImage(this->pictureBox->Image);
	//選択されたセルに表示するテキストボックスを表示する
	text = gcnew TextBox();
	text->Multiline = true;
	text->AutoSize = false;
	text->ImeMode = ImeMode::Off;
	pictureBox->Controls->Add(text);
	text->KeyDown += gcnew KeyEventHandler(this, &DataGridSelfMade::textboxEnter);
	//text->LostFocus += gcnew EventHandler(this, &DataGridSelfMade::textboxLostFocus);
	text->BackColor = Color::Aqua;
	text->Visible = false;
}

/*
関数名:cell_Click
概要:セルがクリックされたときの動作
引数:無し
返却値:なし
作成日:9月9日
作成者:成田修之
*/
Void DataGridSelfMade::cell_click(System::EventArgs^ e)
{
	int row = ((MouseEventArgs^)e)->Y / this->cellHeight;
	int col = ((MouseEventArgs^)e)->X / this->cellWidth;

	this->cell_click(row, col);

}

/*
関数名:selectedCell_click
概要:選択済みのセルがクリックされたときの関数
引数:int row　セルの行, int col　セルの列
返却値:なし
作成日:9月15日
作成者:成田修之
変更日:9月20日(水)
変更者:成田修之
内容:セルごとのデータのcellへの変更
*/
Void DataGridSelfMade::SelectedCell_click(int row, int col) {
	//結合された行なら
	if (checkBound(row)) {
		//大きさ、位置を結合されたセルの大きさに合わせる
		text->Size = System::Drawing::Size(cellWidth * colCount - 1, cellHeight - 1);
		text->Location = Point(0, cellHeight * row);
	}
	//結合された行でない
	else {
		//通常のセルの大きさ・位置に合わせる
		text->Size = System::Drawing::Size(cellWidth - 1, cellHeight - 1);
		text->Location = Point(col * cellWidth, row * cellHeight);
	}
	//
	text->Text = gcnew String(((cell->getKey(row, col)).c_str()));
	//ナルの時は空文字を代入
	text->Text = (text->Text == nullptr ? "" : text->Text);

	//テキストボックスを表示
	text->Visible = true;
	//すぐに入力できるようにフォーカスを置く
	text->Focus();
}

/*
関数名:notSelectedCell_click
概要:初めて選択されたセルがクリックされたときの関数
引数:int row　セルの行, int col　セルの列
返却値:なし
作成日:9月15日
作成者:成田修之
変更日:9月20日(水)
変更者:成田修之
内容:結合されている行についてその時選択されていた列の取得をセルクラスから取得に
*/
Void DataGridSelfMade::notSelectedCell_click(int row, int col) {
	//今表示されているテキストボックスを非表示にする
	text->Visible = false;
	//無効なセルが選択されているときは何もしない
	if (!currentCell->isExist()) {
		int i = 0;
	}
	//セルがオブジェクトへの配列なら
	else if (cell->getCell(currentCell->row, currentCell->col)->isObject()) {
		//オブジェクト用の色に戻す
		drawCell(currentCell, Brushes::LemonChiffon);
	}
	//それ以外なら
	else {
		//カレントのセルについて色をもとに戻す
		drawCell(currentCell, Brushes::White);
	}
	//カレントの行・列ともに取得した値に
	currentCell->row = row;
	currentCell->col = col;

}

/*
関数名:Cell_click
概要:セルがクリックされたときの関数
引数:int row　セルの行, int col　セルの列
返却値:なし
作成日:9月10日
作成者:成田修之
変更日:9月15日
変更者:成田修之
内容:選択済みの時と初めて選択された時のセルの動作をサブ関数化(ステップ数の関係)
*/
Void narita::DataGridSelfMade::cell_click(int row, int col)
{
	//初めて選択されたときの処理の関数を実行
	this->notSelectedCell_click(row, col);

	//カレントのセルを水色で表示
	drawCell(currentCell, Brushes::Aqua);
	//描画を促して変更を反映
	pictureBox->Invalidate();
}

/*
関数名:cell_click
概要:セルがクリックされたときの関数(オーバーロード)
引数:Cell^ cell セル
返却値:なし
作成者:成田修之
作成日:9月15日(金)
*/
Void narita::DataGridSelfMade::cell_click(Cell ^ cell)
{
	//引数のセルの行数列数で同じ関数を呼び出す。
	cell_click(cell->row, cell->col);
}


/*
関数名:drawCell
概要:引数の行と列のものについてセルを描画する関数
引数:int row　行, int col　列, Brush^ color　セルの色
返却値:無し
作成日:9月9日
作成者:成田修之
*/
Void DataGridSelfMade::drawCell(int row, int col, Brush ^ color)
{
	//描こうとしているセルが無効な時は
	if (row < 0 || col < 0) {
		//処理を終了する
		return;
	}
	//セルを書くための四角形を用意
	RectangleF^ rect;
	String^ value;
	//引数から選択されたセルを取得する
	ChainData* selectCell = cell->getCell(row, col);
	//引数の位置の表示部の情報を取得　なければ空文字
	if (selectCell != nullptr && selectCell->isValid()) {
		//データ且つ有効な値なら
		if (!selectCell->isObject()) {
			//キーとその値を
			value = gcnew String(("key:" + selectCell->key + "\nvalue:" + selectCell->value).c_str());
		}
		//オブジェクト配列への空のオブジェクトであるとき
		else if (selectCell->isEmptyCellToObjectArray()) {
			//オブジェクト配列であることを表示する
			value = "arrayObject";
		}
		//オブジェクトなら
		else {
			//キーのみを表示する
			value = gcnew String(selectCell->key.c_str());
		}
	}
	//ナルなら
	else {
		//空文字を入れておく
		value = "";
	}
	//そのセルを覆う四角形を作成
	rect = gcnew RectangleF(col * this->cellWidth, row * this->cellHeight, this->cellWidth - 1, this->cellHeight - 1);

	//四角形を引数の色にする
	graphic->FillRectangle(color, *rect);
	//四角形に取得した文字列を書き込む
	graphic->DrawString(value, font, Brushes::Black, *rect);

}

/*
関数名:drawCell
概要:セルを描画する関数
引数:
返却値:
作成日:9月9日
作成者:成田修之
*/
Void DataGridSelfMade::drawCell(Cell ^ cell, Brush ^ color)
{
	//カレントのセルの行と列で関数を呼び出す
	drawCell(cell->row, cell->col, color);
}

/*
関数名:checkBound
概要:引数の行が結合されているかを判定
引数:int row しらべたい行
返却値:boolean 結合されているかどうかを判定
作成日:9月9日
作成者:成田修之
*/
Boolean DataGridSelfMade::checkBound(int row)
{
	return false;

}

/*
関数名:selectedColFromBoundRow
概要:引数の結合された行の結合されたときに選択された列を返す関数
引数:int row 結合された行
返却値:int col　結合された時選択されていた列
作成日:9月15日(金)
作成者:成田修之
変更日:9月20日(水)
変更者:成田修之
内容:表を管理するクラスの変更によりすべて変更
*/
int narita::DataGridSelfMade::selectedColFromBoundRow(int row)
{
	return 0;
}

/*
関数名:BindRelease
概要:結合／解除するメソッド
引数:int row,int col 行と列
返却値:なし
作成日:9月9日
作成者:成田修之
作成日:9月15日(金)
*/
Void DataGridSelfMade::BindRelease(int row, int col)
{
	//CellChain^ cell = this->cell;
	////結合された行か
	//if (checkBound(row)) {
	//	//その行の先頭のセルにその行が結合されてるかどうかの値を無効に
	//	cell->getCell(row, 0)->isBound = false;
	//	//その行の選択されていた列の値を取得
	//	int selectedCol = cell->getSelectedColFromRow(row);
	//	//そのセルが選択されていたことを無効にする
	//	cell->getCell(row, selectedCol)->isSelectedCol = false;
	//	//列数分繰り返す
	//	for (int i = 0; i < colCount; i++) {
	//		graphic->DrawLine(cellFramePen, Point(i * cellWidth, row * cellHeight), Point(i * cellWidth, (row + 1) * cellHeight));
	//		//その行のセルをすべて描画
	//		drawCell(row, i, Brushes::White);
	//	}
	//	drawCell(currentCell, Brushes::Aqua);
	//}
	////結合された行ではないなら
	//else {
	//	//その行の先頭のセルに結合された行であるとさせる
	//	cell->getCell(row, 0)->isBound = true;
	//	//指定のセルを結合されたとき選択された列だとさせる
	//	cell->getCell(row, col)->isSelectedCol = true;
	//	
	//	//その行を結合された行として描画
	//	drawCell(row, col, Brushes::Aqua);
	//}
	//text->Visible = false;
	//return Void();
}

Void narita::DataGridSelfMade::setRowColFromChain()
{
	//行の先頭となるデータを取得(親の先頭)
	ChainData* parentCurrent = cell->getCell(0, 0);
	int rowCount = 0;	//行数を求める
	int colCount = 0;	//列数を求める
	int lastValidRow = 0;
	//親についてすべて走査
	while (nullptr != parentCurrent) {
		//子の数を数える
		int childCol = 0;
		int lastValidChild = 0;
		//子を取得
		ChainData* childCurrent = parentCurrent->right;
		//子についてすべて走査
		while (nullptr != childCurrent) {
			//兄弟の数を数える
			childCol++;
			//セルが有効なら
			if (childCurrent->isValid()) {
				//その時の値を入れておく
				lastValidChild = childCol;
			}
			//兄弟に移動
			childCurrent = childCurrent->under;
		}
		//いままでの列数を子の数が超えたら
		if (colCount < lastValidChild) {
			//その数を列数にする
			colCount = lastValidChild;
		}
		//行の数を加算する
		rowCount++;

		//有効なセルなら
		if (parentCurrent->isValid()) {
			//その時の行の値を保管する
			lastValidRow = rowCount;
		}
		//兄弟へ移動
		parentCurrent = parentCurrent->under;
	}

	//求めた行数列数にセットする
	this->rowCount = lastValidRow;
	this->colCount = colCount;
	//きちんと行があれば
	if (this->rowCount > 0) {
		//先頭の列分プラスする
		this->colCount += 1;
	}
	return Void();
}

Void narita::DataGridSelfMade::adjustCell()
{
	//行の先頭のセルを取得
	ChainData* parentCurrent = cell->getCell(0, 0);
	//行数分繰り返す
	for (int i = 0; i < rowCount; i++) {
		//子がないとき
		if (nullptr == parentCurrent->right) {
			//子を作成
			parentCurrent->addRight(new ChainData());
			//埋め合わせであることを示す値を格納
			parentCurrent->right->valid = false;
		}

		//列の先頭のセルを取得
		ChainData* childCurrent = parentCurrent->right;
		//列数分繰り返す(今の子の分と、列数は先頭も含まれてしまっているので-2)
		for (int j = 0; j < colCount - 2; j++) {
			//カレントのセルの下の兄弟がナルの時
			if (nullptr == childCurrent->under) {
				//下にセルを追加
				childCurrent->addUnder(new ChainData());
				//埋め合わせであることを示す値を格納
				childCurrent->under->valid = false;
			}
			//次の兄弟へ移動
			childCurrent = childCurrent->under;
		}
		//親も次の親へ移動
		parentCurrent = parentCurrent->under;
	}

	return Void();
}

Void narita::DataGridSelfMade::View()
{
	//行数と列数をセルチェーンに合わせる
	setRowColFromChain();
	//列などで埋まっていない部分について埋め合わせる
	adjustCell();
	//描画する
	Paint();
}

/*
関数名:paint
概要:全体を描画する関数
引数:無し
返却値:無し
作成日:9月9日
作成者:成田修之
*/
Void DataGridSelfMade::Paint()
{
	//行か列のどちらかが0なら表示するものはないので何もしない
	if (rowCount == 0 || colCount == 0) {
		return;
	}
	//ピクチャーボックスの大きさを設定されている行数列数に合わせる
	pictureBox->Size = System::Drawing::Size(colCount * cellWidth, rowCount * cellHeight);
	//ピクチャーボックスの大きさに合わせて描画先のオブジェクトを生成しなおす
	pictureBox->Image = gcnew Bitmap(pictureBox->Width, pictureBox->Height);
	//その描画先に描画するオブジェクトを作成
	graphic = Graphics::FromImage(pictureBox->Image);

	//行数分繰り返す
	for (int i = 0; i < rowCount; i++) {
		//列数分繰り返す
		for (int j = 0; j < colCount; j++) {
			//セルの区切りの線を描画
			graphic->DrawLine(cellFramePen, Point(j * cellWidth, i * cellHeight), Point(j * cellWidth, (i + 1) * cellHeight));
			//オブジェクトなら
			if (cell->getCell(i, j)->isObject()) {
				//色を変えて描画
				drawCell(i, j, Brushes::LemonChiffon);
			}
			//それ以外なら
			else {
				//通常の色で描画
				drawCell(i, j, Brushes::White);
			}
		}
		//行ごと線を描画
		graphic->DrawLine(cellFramePen, Point(0, (i + 1) * cellHeight), Point(colCount * cellWidth, (i + 1) * cellHeight));
	}
	//＠修正　カレントのセルのある行がなくなった時セルの値を取得できずに
	//例外が出るので行数列数より多いときはカレントのセルを描画しない
	if (currentCell->row < rowCount && currentCell->col < colCount) {
		//カレントのセルについて描画する
		drawCell(currentCell, Brushes::Aqua);
	}
}

/*
関数名:textboxEnter
概要:テキストボックスフォーカス中にインターキーが押されたときのイベント
引数:無し
返却値:無し
作成日:9月11日
作成者:成田修之
*/
Void DataGridSelfMade::textboxEnter(System::Object ^ sender, KeyEventArgs ^ e)
{
	//発生元のテキストボックスを取得
	TextBox^ tempBox = (TextBox^)sender;

	//テキストボックスの座標を取得
	int col = tempBox->Location.X / cellWidth;
	int row = tempBox->Location.Y / cellHeight;

	//エンターキーが押されていたら
	if (e->KeyValue == (int)Keys::Return) {
		//入力されていた値をその座標の値として保管 @modセルクラスのその位置のセルに格納するように変更
		cell->getCell(row, col)->key = constants.StrToc_str(tempBox->Text);
		//テキストボックスを非表示にする
		tempBox->Visible = false;
		//カレントのセルを水色に
		drawCell(row, col, Brushes::Aqua);
	}
	return Void();
}

/*
関数名:textboxLostFocus
概要:フォーカスを失ったときのイベント
引数:無し
返却値:無し
作成日:9月11日
作成者:成田修之
*/
Void DataGridSelfMade::textboxLostFocus(System::Object ^ sender, EventArgs ^ e)
{
	//イベント元のテキストボックスを取得
	TextBox^ tempBox = (TextBox^)sender;

	//座標を取得
	int col = tempBox->Location.X / cellWidth;
	int row = tempBox->Location.Y / cellHeight;

	//テキストボックスに入力された値をその座標の値として保管 @mod保管対象をセルクラスに変更
	cell->setKey(row, col, constants.StrToc_str(text->Text));
	//非表示にする
	tempBox->Visible = false;
	//フォーカスが離れたので白色に
	drawCell(row, col, Brushes::White);

	return Void();
}

/*
関数名:Clear
概要:一から作れるようにクラスを初期化する関数
引数:なし
返却値:なし
作成日:9月14日(木)
作成者:成田修之
*/
Void DataGridSelfMade::Clear() {

	this->rowCount = 0;
	this->colCount = 0;
	this->currentCell->Reset();
}