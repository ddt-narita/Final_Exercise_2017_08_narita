#pragma once

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
	private: System::Windows::Forms::DataGridView^  dataGridViewCellInfo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  columnKeys;
	private: System::Windows::Forms::Label^  label1;



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
			this->dataGridViewCellInfo = (gcnew System::Windows::Forms::DataGridView());
			this->columnKeys = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCellInfo))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(80, 20);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 23);
			this->buttonOK->TabIndex = 4;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &GridInfo::buttonOK_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonCancel->Location = System::Drawing::Point(161, 20);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 5;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// dataGridViewCellInfo
			// 
			this->dataGridViewCellInfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridViewCellInfo->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewCellInfo->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->columnKeys });
			this->dataGridViewCellInfo->Location = System::Drawing::Point(27, 49);
			this->dataGridViewCellInfo->Name = L"dataGridViewCellInfo";
			this->dataGridViewCellInfo->RowTemplate->Height = 21;
			this->dataGridViewCellInfo->Size = System::Drawing::Size(187, 226);
			this->dataGridViewCellInfo->TabIndex = 6;
			// 
			// columnKeys
			// 
			this->columnKeys->HeaderText = L"親キー";
			this->columnKeys->Name = L"columnKeys";
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
			// GridInfo
			// 
			this->AcceptButton = this->buttonOK;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->buttonCancel;
			this->ClientSize = System::Drawing::Size(248, 287);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridViewCellInfo);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonOK);
			this->Name = L"GridInfo";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"GridInfo";
			this->Load += gcnew System::EventHandler(this, &GridInfo::GridInfo_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCellInfo))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private:
public:
	//行の情報を保管するメンバ
	array<String^>^ _gridInfo;
	//行数のメンバ
	int _rowN;
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
		//行数のプロパティー
		property int rowNumber {
			int get() {
				return _rowN;
			}
			void set(int n) {
				_rowN = n;
			}
		}

//
private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
	//入力された情報群の行数を取得
	int rowN = dataGridViewCellInfo->Rows->Count - 1;

	//メンバにセットする用の行数の長さの一時配列を作成
	array<String^>^ temp = gcnew array<String^>(rowN);
	//行の長さ分だけ繰り返す
	for (int i = 0; i < rowN; i++) {
		//入力されている情報を一時配列に格納
		temp[i] = (String^)(dataGridViewCellInfo->Rows[i]->Cells[0]->Value) == nullptr ? "" : (String^)(dataGridViewCellInfo->Rows[i]->Cells[0]->Value);
	}
	//メンバに反映
	gridInfo = temp;
	//フォームを閉じる
	this->Close();
}

//
private: System::Void GridInfo_Load(System::Object^  sender, System::EventArgs^  e) {
	//メンバに渡された情報の配列の長さを取得
	int rowLen = gridInfo->Length;

	//その数だけ繰り返す
	for (int i = 0; i < rowLen; i++) {
		//フォームの情報表示部に順に追加していく
		this->dataGridViewCellInfo->Rows->Add(gridInfo[i]);
	}

	label1->Text = rowN.ToString() + "行" + colN.ToString() + "列";
}
};
}
