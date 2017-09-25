#include "DataGridSelfMade.h"

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
	cell = gcnew CellChain();
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

	//値を取得する @mod 値の取得をセルクラスのメソッドから取得する
	text->Text = cell->getValue(row, col);
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
	//カレントのセルについて色をもとに戻す
	drawCell(currentCell, Brushes::White);

	//結合された行なら
	if (checkBound(row)) {
		//カレントのセルを今回の行にする
		currentCell->row = row;
		//結合されたときに選択された列にする @mod9月20日(水)　列の取得をセルクラスからに
		currentCell->col = cell->getSelectedColFromRow(row);
	}
	//通常のセルなら
	else {
		//行・列ともに取得した値に
		currentCell->row = row;
		currentCell->col = col;
	}
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
	//すでに選択済みのセルをクリックしたとき
	if (currentCell->col == col && currentCell->row == row && currentCell->row != -1) {
		//選択済みのセルをクリックされたときの処理の関数を実行
		this->SelectedCell_click(row, col);
	}
	//初めて選択されるなら
	else {
		//初めて選択されたときの処理の関数を実行
		this->notSelectedCell_click(row, col);
	}
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
関数名:CreateGridMapKey
概要:引数の行と列からマップのキーを作成する
引数:int row, int col　行と列
返却値:String^ 作成したキー
作成日:9月9日
作成者:成田修之
*/
String^ DataGridSelfMade::CreateGridMapKey(int row, int col)
{
	//"行：列"の形のキーを作成して返却する
	return row.ToString() + ":" + col.ToString();
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
	//セルを書くための四角形を用意
	RectangleF^ rect;
	String^ value;
	String^ key = CreateGridMapKey(row, col);
	//引数の位置の表示部の情報を取得　なければ空文字
	if (cell->getCell(row, col) != nullptr) {
		value = cell->getValue(row, col);
	}
	else {
		value = "";
	}
	//引数の行が結合された行なのかを取得
	if (checkBound(row)) {
		//行全体を覆う形の四角形を作成
		rect = gcnew RectangleF(0, row * this->cellHeight, this->colCount * this->cellWidth - 1, cellHeight -1);
	}
	//結合されていないとき
	else {
		//そのセルを覆う四角形を作成
		rect = gcnew RectangleF(col * this->cellWidth, row * this->cellHeight, this->cellWidth - 1, this->cellHeight -1);
	}
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
	CellChain^ temp = cell;
	//結合された行を管理するメンバから引数の行をキーとするものがあるかどうかで結合しているかを判定
	for (int i = 0; i < row; i++) {
		temp = temp->under;
	}
	return temp->isBound;
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
	//セルを取得
	CellChain^ temp = cell;
	//引数の行数分繰り返す
	for (int i = 0; i < row; i++) {
		//下のセルに更新
		temp = temp->under;
	}
	//返却する選択されたセルの列数
	int col = 0;

	//列数分繰り返す
	for (; col < this->colCount; col++) {
		//選択されたセルが見つかったら
		if (temp->isSelectedCol) {
			//ループを抜ける
			break;
		}
		//右のセルに移動
		temp = temp->right;
	}

	//結合された行を管理するメンバからその時選択された列を抽出して返却する。
	return col;
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
	CellChain^ cell = this->cell;
	//結合された行か
	if (checkBound(row)) {
		//その行の先頭のセルにその行が結合されてるかどうかの値を無効に
		cell->getCell(row, 0)->isBound = false;
		//その行の選択されていた列の値を取得
		int selectedCol = cell->getSelectedColFromRow(row);
		//そのセルが選択されていたことを無効にする
		cell->getCell(row, selectedCol)->isSelectedCol = false;
		//列数分繰り返す
		for (int i = 0; i < colCount; i++) {
			graphic->DrawLine(cellFramePen, Point(i * cellWidth, row * cellHeight), Point(i * cellWidth, (row + 1) * cellHeight));
			//その行のセルをすべて描画
			drawCell(row, i, Brushes::White);
		}
		drawCell(currentCell, Brushes::Aqua);
	}
	//結合された行ではないなら
	else {
		//その行の先頭のセルに結合された行であるとさせる
		cell->getCell(row, 0)->isBound = true;
		//指定のセルを結合されたとき選択された列だとさせる
		cell->getCell(row, col)->isSelectedCol = true;
		
		//その行を結合された行として描画
		drawCell(row, col, Brushes::Aqua);
	}
	text->Visible = false;
	return Void();
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
	//ピクチャーボックスの大きさを設定されている行数列数に合わせる
	pictureBox->Size = System::Drawing::Size(colCount * cellWidth, rowCount * cellHeight);
	//ピクチャーボックスの大きさに合わせて描画先のオブジェクトを生成しなおす
	pictureBox->Image = gcnew Bitmap(pictureBox->Width,pictureBox->Height);
	//その描画先に描画するオブジェクトを作成
	graphic = Graphics::FromImage(pictureBox->Image);

	//行数分繰り返す
	for (int i = 0; i < rowCount; i++) {
		//結合された行なら
		if (checkBound(i)) {
			//結合されたときに選択された列を取得 @mod セルクラスから取得するように変更
			int selectedColFromBoundRow = cell->getSelectedColFromRow(i);
			//結合された行について描画
			drawCell(i, selectedColFromBoundRow, Brushes::White);
		}
		//結合されていないなら
		else {
			//列数分繰り返す
			for (int j = 0; j < colCount; j++) {
				//セルの区切りの線を描画
				graphic->DrawLine(cellFramePen, Point(j * cellWidth, i * cellHeight), Point(j * cellWidth, (i + 1) * cellHeight));
				//そのセルを描画する
				drawCell(i, j, Brushes::White);
			}
		}
		//行ごと線を描画
		graphic->DrawLine(cellFramePen, Point(0, (i+1) * cellHeight), Point(colCount * cellWidth, (i+1) * cellHeight));
	}
	//カレントのセルについて描画する
	drawCell(currentCell, Brushes::Aqua);
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
		cell->getCell(row, col)->Value = tempBox->Text;
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
	cell->setValue(row, col, text->Text);
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
	this->currentCell->col = -1;
	this->currentCell->row = -1;
	//セルクラスでもクリア処理
	cell->Clear();
}