#pragma once
#include "Cell.h"

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

		//表示する値を格納する行：列と値の連想配列
		Dictionary<String^, String^>^ GridData;
		//結合されている行とその時選択されていた列のペアの連想配列
		Dictionary<String^, String^>^ BoundRow;

	public:
		int cellWidth;	//セルの幅
		int cellHeight;	//セルの高さ
		TextBox^ text;	//テキストボックス
		//列数のプロパティー
		property int colCount {
			int get() {
				return _colCount;
			}
			void set(int col) {
				for (int i = 0; i < rowCount; i++) {
					for (int j = _colCount; j < col; j++) {
						GridData[CreateGridMapKey(i,j)] = "";
					}
				}
				_colCount = col;
			}
		}
		//行数のプロパティー
		property int rowCount {
			int get() {
				return _rowCount;
			}
			void set(int row) {
				
				for (int i = _rowCount; i < row; i++) {
					for (int j = 0; j < colCount; j++) {
						GridData[CreateGridMapKey(i,j)] = "";
					}
				}
				_rowCount = row;
			}
		}
		//現在選択中のセル
		narita::Cell^ currentCell;

		//コンストラクタ
		DataGridSelfMade(PictureBox^ pictureBox);

		//クリックされたときの動作
		Void cell_click(int row, int col);
		//表示部の値を取得するためのキーを作成する関数
		String^ CreateGridMapKey(int row, int col);
		//指定の行、列に引数の色のセルを描画する関数
		Void drawCell(int row, int col, Brush^ color);
		//引数がセルの時
		Void drawCell(Cell^ cell, Brush ^ color);
		//引数の行が結合された行なのかを判定する関数
		Boolean checkBound(int row);
		//引数の位置のセルを結合／解除する関数
		Void BindRelease(int row, int col);
		//全体を一から描画するメソッド
		Void Paint();
		Void Clear();

		//このクラスに対する添字演算子の定義
		property System::String^ default[System::String^]{
			System::String^ get(System::String^ index) {
				return this->GridData[index];
			}
			void set(System::String^ index, System::String^ value) {
				this->GridData[index] = value;
			}
		}

	private:Void textboxEnter(System::Object^  sender, Windows::Forms::KeyEventArgs^  e);
	Void textboxLostFocus(System::Object ^ sender, EventArgs ^ e);
	};

}