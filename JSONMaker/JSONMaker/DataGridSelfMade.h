#pragma once
#include "Cell.h"
#include "ChainData.h"


namespace narita {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	ref class DataGridSelfMade
	{
	private:
		PictureBox^ pictureBox;	//描画したものを配置するピクチャーボックス
		Bitmap^ canvas;			//描画先のオブジェクト
		Graphics^ graphic;		//描画するためのオブジェクト
		Pen^ cellFramePen;		//セルの枠を書くためのペンオブジェクト
		Font^ font;				//フォント


		int _colCount;	//列数
		int _rowCount;	//行数



	public:
		int cellWidth;	//セルの幅
		int cellHeight;	//セルの高さ

		ChainData* cell;

		TextBox^ text;	//テキストボックス
		//列数のプロパティー
		property int colCount {
			int get() {
				return _colCount;
			}
			void set(int col) {
				_colCount = col;
			}
		}
		//行数のプロパティー
		property int rowCount {
			int get() {
				return _rowCount;
			}
			void set(int row) {
				_rowCount = row;
			}
		}
		//現在選択中のセル
		Cell^ currentCell;

		//コンストラクタ
		DataGridSelfMade(PictureBox^ pictureBox);

		//クリックされたときの動作
		Void cell_click(EventArgs^ e);
		Void cell_click(int row, int col);
		Void cell_click(Cell^ cell);
		Void SelectedCell_click(int row, int col);
		Void notSelectedCell_click(int row, int col);
		//表示部の値を取得するためのキーを作成する関数
		
		//指定の行、列に引数の色のセルを描画する関数
		Void drawCell(int row, int col, Brush^ color);
		//引数がセルの時
		Void drawCell(Cell^ cell, Brush ^ color);
		//引数の行が結合された行なのかを判定する関数
		Boolean checkBound(int row);
		int selectedColFromBoundRow(int row);
		//引数の位置のセルを結合／解除する関数
		Void BindRelease(int row, int col);

		Void setRowColFromChain();
		Void adjustCell();

		//セットされたセルのチェーンデータから表示を行う処理
		Void View();
		//全体を一から描画するメソッド
		Void Paint();
		//表部分のデータをクリアする関数
		Void Clear();

	private:Void textboxEnter(System::Object^  sender, Windows::Forms::KeyEventArgs^  e);
			Void textboxLostFocus(System::Object ^ sender, EventArgs ^ e);
	};

}