#pragma once
#include "DataGridSelfMade.h"

namespace JSONMaker {

	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

	/// <summary>
	/// GridInfo の概要
	/// </summary>
	public ref class GridInfo : public System::Windows::Forms::Form
	{
	public:
		GridInfo(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~GridInfo()
		{
			if (components)
			{
				delete components;
			}
		}




	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::Button^  buttonCancel;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  buttonAdd;
	private: System::Windows::Forms::Button^  buttonPopBack;





	protected:

	protected:




	protected:

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->buttonPopBack = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(80, 20);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(82, 23);
			this->buttonOK->TabIndex = 4;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &GridInfo::buttonOK_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonCancel->Location = System::Drawing::Point(181, 20);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(81, 23);
			this->buttonCancel->TabIndex = 5;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 12);
			this->label1->TabIndex = 7;
			this->label1->Text = L"label1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(14, 82);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(10, 10);
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &GridInfo::Cell_Click);
			// 
			// buttonAdd
			// 
			this->buttonAdd->Location = System::Drawing::Point(80, 49);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(82, 23);
			this->buttonAdd->TabIndex = 9;
			this->buttonAdd->Text = L"追加";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &GridInfo::buttonAdd_Click);
			// 
			// buttonPopBack
			// 
			this->buttonPopBack->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->buttonPopBack->Location = System::Drawing::Point(181, 49);
			this->buttonPopBack->Name = L"buttonPopBack";
			this->buttonPopBack->Size = System::Drawing::Size(81, 23);
			this->buttonPopBack->TabIndex = 10;
			this->buttonPopBack->Text = L"後ろ一つ削除";
			this->buttonPopBack->UseVisualStyleBackColor = true;
			this->buttonPopBack->Click += gcnew System::EventHandler(this, &GridInfo::buttonPopBack_Click);
			// 
			// GridInfo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->CancelButton = this->buttonCancel;
			this->ClientSize = System::Drawing::Size(396, 421);
			this->Controls->Add(this->buttonPopBack);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonOK);
			this->Name = L"GridInfo";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"GridInfo";
			this->Load += gcnew System::EventHandler(this, &GridInfo::GridInfo_Load);
			this->Click += gcnew System::EventHandler(this, &GridInfo::GridInfo_Click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private:
	narita::DataGridSelfMade^ DataGridCellInfo;
	//行の情報を保管するメンバ
	array<String^>^ _gridInfo;
public:
	
	
	public:
		int rowN;
		int colN;
		//行の情報プロパティー
		property array<String^>^ gridInfo {
			array<String^>^ get() {
				return _gridInfo;
			}

			void set(array<String^>^ temp) {
				int len = temp->Length;
				_gridInfo = gcnew array<String^>(len);

				for (int i = 0; i < len; i++) {
					_gridInfo[i] = temp[i];
				}

			}
		}

/*
関数名:buttonOK_Click
概要:OKボタンがクリックされたときのイベント
引数:イベントの引数
返却値:
作成日:9月15日(金)
作成者:成田修之
*/
private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
	//入力された情報群の行数を取得
	int rowN = DataGridCellInfo->rowCount;

	//メンバにセットする用の行数の長さの一時配列を作成
	array<String^>^ temp = gcnew array<String^>(rowN);
	//行の長さ分だけ繰り返す
	for (int i = 0; i < rowN; i++) {
		//入力されている情報を一時配列に格納
		temp[i] = DataGridCellInfo[DataGridCellInfo->CreateGridMapKey(i,1)] == nullptr ? "" : DataGridCellInfo[DataGridCellInfo->CreateGridMapKey(i, 1)];
	}
	//メンバに反映
	gridInfo = temp;
	//フォームを閉じる
	this->Close();
}

		 /*
		 関数名:GridInfo_Load
		 概要:このフォームが立ち上がったときのイベント
		 引数:イベントの引数
		 返却値:無し
		 作成日:9月15日(金)
		 作成者:成田修之
		 */
private: System::Void GridInfo_Load(System::Object^  sender, System::EventArgs^  e) {
	//メンバに渡された情報の配列の長さを取得
	int rowLen = gridInfo->Length;
	//ピクチャボックスを渡してdataGridのインスタンスを生成
	DataGridCellInfo = gcnew narita::DataGridSelfMade(pictureBox1);
	
	//表の行数を取得した情報の数にする
	DataGridCellInfo->rowCount = rowLen;
	//何番目かとキーを表示する列のみなので2列
	DataGridCellInfo->colCount = 2;

	//その数だけ繰り返す
	for (int i = 0; i < rowLen; i++) {
		//何番目のキー表す列
		DataGridCellInfo[DataGridCellInfo->CreateGridMapKey(i, 0)] = "Key[" + i.ToString() + "]";
		//キーを順番に配置
		DataGridCellInfo[DataGridCellInfo->CreateGridMapKey(i, 1)] = gridInfo[i];
	}
	//表を描画
	DataGridCellInfo->Paint();

	//ラベルに何行、何列目のセルの情報なのかを表示
	label1->Text = rowN.ToString() + "行" + colN.ToString() + "列";
}


		 /*
		 関数名:pictureBox_Click	
		 概要:セルがクリックされた時のイベント
		 引数:イベントの引数
		 返却値:無し
		 作成日:9月15日(金)
		 作成者:成田修之
		 */
private: System::Void Cell_Click(System::Object^  sender, System::EventArgs^  e) {
	//クリックされた列を取得
	int col = ((MouseEventArgs^)e)->X / DataGridCellInfo->cellWidth;
	//何番目かを表す編集不可の列でなければ
	if (col != 0) {
		//そのセルがクリックされたとしてメソッド呼び出し
		DataGridCellInfo->cell_click(e);
	}
	//編集不可の列であれば
	else {
		//選択中のセルをもとに戻して
		DataGridCellInfo->drawCell(DataGridCellInfo->currentCell, Brushes::White);
		//カレントのセルを-1,-1に設定
		DataGridCellInfo->currentCell = gcnew narita::Cell(-1, -1);
	}
	//描画を促す
	pictureBox1->Invalidate();
}
		 
		 /*
		 関数名:GridInfo_Click
		 概要:フォームのセル以外の部分がクリックされたときのイベント
		 引数:イベントの引数
		 返却値:なし
		 作成日:9月15日(金)
		 作成者:成田修之
		 */
private: System::Void GridInfo_Click(System::Object^  sender, System::EventArgs^  e) {
	//カレントのセルを-1,-1に設定
	DataGridCellInfo->currentCell = gcnew narita::Cell(-1, -1);
	//そのセルがクリックされたことにしてメソッド呼び出し
	DataGridCellInfo->cell_click(DataGridCellInfo->currentCell);
	//再描画を促す
	pictureBox1->Invalidate();
}

		 /*
		 関数名:buttonAdd_Click
		 概要:追加ボタンがクリックされたときのイベント
		 引数:イベントの引数
		 返却値:無し
		 作成日:9月15日(金)
		 作成者:成田修之
		 */
private: System::Void buttonAdd_Click(System::Object^  sender, System::EventArgs^  e) {
	//表の行数を1追加
	DataGridCellInfo->rowCount += 1;
	//その追加された行の1列目に何個目のキーかを格納
	DataGridCellInfo[DataGridCellInfo->CreateGridMapKey((DataGridCellInfo->rowCount - 1), 0)] = "Key[" + (DataGridCellInfo->rowCount - 1).ToString() + "]";
	//2列目には空文字を
	DataGridCellInfo[DataGridCellInfo->CreateGridMapKey((DataGridCellInfo->rowCount - 1), 1)] = "";
	//メンバの配列の大きさを更新
	Array::Resize(_gridInfo, DataGridCellInfo->rowCount);
	//そのメンバの配列の新しく作成した部分に空文字配置
	gridInfo[DataGridCellInfo->rowCount - 1] = "";
	//表を描画
	DataGridCellInfo->Paint();
}

		 /*
		 関数名:buttonPopBack_Click
		 概要:後ろ一つ削除ボタンがおされたときのイベント
		 引数:イベントの引数
		 返却値:なし
		 作成日:9月15日(金)
		 作成者:成田修之
		 */
private: System::Void buttonPopBack_Click(System::Object^  sender, System::EventArgs^  e) {
	//行数が0なら
	if (DataGridCellInfo->rowCount == 0) {
		//もう減らす行がないことを表示
		MessageBox::Show("これ以上減らせません","警告",MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	//1以上なら
	else {
		//表を1行減らす
		DataGridCellInfo->rowCount -= 1;
		//再描画
		DataGridCellInfo->Paint();
	}
}
};
}
