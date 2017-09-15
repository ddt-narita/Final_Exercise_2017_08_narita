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
	//表の値
	GridData = gcnew Dictionary<String^, String^>();
	//結合されている行とその時選択されていた列
	BoundRow = gcnew Dictionary<String^, String^>();
	//初期列数
	colCount = 5;
	//初期行数
	rowCount = 5;
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
	text->LostFocus += gcnew EventHandler(this, &DataGridSelfMade::textboxLostFocus);
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
*/
Void DataGridSelfMade::SelectedCell_click(int row, int col) {
	//結合された行なら
	if (checkBound(row)) {
		//大きさ、位置を結合されたセルの大きさに合わせる
		text->Size = System::Drawing::Size(cellWidth * colCount - 1, cellHeight - 1);
		text->Location = Point(0, cellHeight * rowCount);
	}
	//結合された行でない
	else {
		//通常のセルの大きさ・位置に合わせる
		text->Size = System::Drawing::Size(cellWidth - 1, cellHeight - 1);
		text->Location = Point(col * cellWidth, row * cellHeight);
	}

	//その位置に値が存在していれば
	if (GridData->ContainsKey(CreateGridMapKey(row, col))) {
		//値を取得する
		text->Text = this->GridData[CreateGridMapKey(row, col)];
	}
	//存在しなければ
	else {
		//空文字を表示させる
		text->Text = "";
	}
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
		//結合されたときに選択された列にする
		currentCell->col = Int32::Parse(BoundRow[row.ToString()]);
	}
	//通常のセルなら
	else {
		//行・列ともに取得した値に
		currentCell->row = row;
		currentCell->col = col;
	}
}

/*
関数名:selectedCell_click
概要:選択済みのセルがクリックされたときの関数
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
関数名:
概要:
引数:
返却値:
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
	if (GridData->ContainsKey(key)) {
		value = this->GridData[key];
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
	//結合された行を管理するメンバから引数の行をキーとするものがあるかどうかで結合しているかを判定
	return BoundRow->ContainsKey(row.ToString());
}

/*
関数名:selectedColFromBoundRow
概要:引数の結合された行の結合されたときに選択された列を返す関数
引数:int row 結合された行
返却値:int col　結合された時選択されていた列
作成者:成田修之
作成日:9月15日(金)
*/
int narita::DataGridSelfMade::selectedColFromBoundRow(int row)
{
	//結合された行を管理するメンバからその時選択された列を抽出して返却する。
	return Int32::Parse(BoundRow[row.ToString()]);
}

/*
関数名:BindRelease
概要:結合／解除するメソッド
引数:int row,int col 行と列
返却値:なし
作成日:9月9日
作成者:成田修之
*/
Void DataGridSelfMade::BindRelease(int row, int col)
{
	//結合された行か
	if (checkBound(row)) {
		//その行をキーとするものを取り除いて結合された行ではないとする
		BoundRow->Remove(row.ToString());
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
		//結合管理のメンバにその行をキー、選択された列を値として持たせる
		BoundRow[row.ToString()] = col.ToString();
		//その行を結合された行として描画
		drawCell(row, col, Brushes::Aqua);
	}
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
			//結合されたときに選択された列を取得
			int selectedColFromBoundRow = Int32::Parse(BoundRow[i.ToString()]);
			//結合された行について描画
			drawCell(i, selectedColFromBoundRow + 1, Brushes::White);
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
		//入力されていた値をその座標の値として保管
		GridData[this->CreateGridMapKey(row, col)] = tempBox->Text;
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

	//テキストボックスに入力された値をその座標の値として保管
	GridData[this->CreateGridMapKey(row, col)] = tempBox->Text;
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
	this->BoundRow->Clear();
	this->GridData->Clear();
	this->rowCount = 0;
	this->colCount = 0;
	this->currentCell->col = 0;
	this->currentCell->row = 0;
}