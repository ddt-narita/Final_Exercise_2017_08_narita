#pragma once

namespace JSONMaker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// GridRowInfo の概要
	/// </summary>
	public ref class GridRowInfo : public System::Windows::Forms::Form
	{
	public:
		GridRowInfo(void)
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
		~GridRowInfo()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^  labelRowNumber;
	private: System::Windows::Forms::DataGridView^  dataGridViewRowInfo;
	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::Button^  buttonCancel;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;



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
			this->labelRowNumber = (gcnew System::Windows::Forms::Label());
			this->dataGridViewRowInfo = (gcnew System::Windows::Forms::DataGridView());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewRowInfo))->BeginInit();
			this->SuspendLayout();
			// 
			// labelRowNumber
			// 
			this->labelRowNumber->AutoSize = true;
			this->labelRowNumber->Font = (gcnew System::Drawing::Font(L"ＭＳ Ｐゴシック", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelRowNumber->Location = System::Drawing::Point(43, 25);
			this->labelRowNumber->Name = L"labelRowNumber";
			this->labelRowNumber->Size = System::Drawing::Size(0, 15);
			this->labelRowNumber->TabIndex = 1;
			// 
			// dataGridViewRowInfo
			// 
			this->dataGridViewRowInfo->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewRowInfo->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Column1 });
			this->dataGridViewRowInfo->Location = System::Drawing::Point(12, 54);
			this->dataGridViewRowInfo->Name = L"dataGridViewRowInfo";
			this->dataGridViewRowInfo->RowTemplate->Height = 21;
			this->dataGridViewRowInfo->Size = System::Drawing::Size(290, 158);
			this->dataGridViewRowInfo->TabIndex = 2;
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(32, 248);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 23);
			this->buttonOK->TabIndex = 3;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &GridRowInfo::buttonOK_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(191, 248);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 4;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"行の親キー";
			this->Column1->Name = L"Column1";
			// 
			// GridRowInfo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(318, 283);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->dataGridViewRowInfo);
			this->Controls->Add(this->labelRowNumber);
			this->Name = L"GridRowInfo";
			this->Text = L"行にかかる情報";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &GridRowInfo::GridRowInfo_FormClosing);
			this->Load += gcnew System::EventHandler(this, &GridRowInfo::GridRowInfo_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewRowInfo))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		//行の情報を保管するメンバ
		array<String^>^ _gridRowInfo;
		//行数のメンバ
		int _rowN;
	public:
		//行の情報プロパティー
		property array<String^>^ gridRowInfo {
			array<String^>^ get() {
				return _gridRowInfo;
			}

			void set(array<String^>^ temp) {
				int len = temp->Length;
				_gridRowInfo = gcnew array<String^>(len);

				for (int i = 0; i < len; i++) {
					_gridRowInfo[i] = temp[i];
				}

			}
		}
		//行数のプロパティー
		property int rowNumber {
			int get() {
				return _rowN;
			}
			void set(int n) {
				_rowN = n;
			}
		}

	//フォームが表示されるときに実行される関数
	private: System::Void GridRowInfo_Load(System::Object^  sender, System::EventArgs^  e) {
		//メンバに渡された情報の配列の長さを取得
		int rowLen = gridRowInfo->Length;

		//その数だけ繰り返す
		for (int i = 0; i < rowLen; i++) {
			//フォームの情報表示部に順に追加していく
			this->dataGridViewRowInfo->Rows->Add(gridRowInfo[i]);
		}
		//何行目の情報かを表示する
		labelRowNumber->Text = rowNumber.ToString() + "行目の情報";
	}


	//OKボタン押下時のイベント
	private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
		//入力された情報群の行数を取得
		int rowN = dataGridViewRowInfo->Rows->Count - 1;

		//メンバにセットする用の行数の長さの一時配列を作成
		array<String^>^ temp = gcnew array<String^>(rowN);
		//行の長さ分だけ繰り返す
		for (int i = 0; i < rowN; i++) {
			//入力されている情報を一時配列に格納
			temp[i] = (String^)(dataGridViewRowInfo->Rows[i]->Cells[0]->Value) == nullptr ? "" : (String^)(dataGridViewRowInfo->Rows[i]->Cells[0]->Value);
		}
		//メンバに反映
		gridRowInfo = temp;
		//フォームを閉じる
		this->Close();

	}
	private: System::Void GridRowInfo_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		//行数を取得
		int rowN = dataGridViewRowInfo->Rows->Count;
		//取得した行数の長さの配列を取る
		array<String^>^ temp = gcnew array<String^>(rowN);
		//長さ分だけ繰り返す
		for (int i = 0; i < rowN; i++) {
			//配列にフォームに入力された値を一時オブジェクトに格納
			temp[i] = (String^)(dataGridViewRowInfo->Rows[i]->Cells[0]->Value) == nullptr ? "" : (String^)(dataGridViewRowInfo->Rows[i]->Cells[0]->Value);
		}
		//メンバに保存してメインフォームに返す。
		gridRowInfo = temp;
	}
};
}
