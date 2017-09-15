#pragma once

namespace JSONMaker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// EnvForm の概要
	/// </summary>
	public ref class EnvForm : public System::Windows::Forms::Form
	{
	public:
		EnvForm(void)
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
		~EnvForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  labelDB;
	private: System::Windows::Forms::Label^  labelJSONName;
	private: System::Windows::Forms::Label^  labelQuery;
	private: System::Windows::Forms::TextBox^  textBoxDBName;

	protected:



	private: System::Windows::Forms::TextBox^  textBoxJSONName;
	private: System::Windows::Forms::TextBox^  textBoxQuery;
	private: System::Windows::Forms::Button^  buttonOK;



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
			this->labelDB = (gcnew System::Windows::Forms::Label());
			this->labelJSONName = (gcnew System::Windows::Forms::Label());
			this->labelQuery = (gcnew System::Windows::Forms::Label());
			this->textBoxDBName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxJSONName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxQuery = (gcnew System::Windows::Forms::TextBox());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// labelDB
			// 
			this->labelDB->AutoSize = true;
			this->labelDB->Font = (gcnew System::Drawing::Font(L"ＭＳ Ｐゴシック", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelDB->Location = System::Drawing::Point(47, 35);
			this->labelDB->Name = L"labelDB";
			this->labelDB->Size = System::Drawing::Size(45, 15);
			this->labelDB->TabIndex = 0;
			this->labelDB->Text = L"DB名";
			// 
			// labelJSONName
			// 
			this->labelJSONName->AutoSize = true;
			this->labelJSONName->Font = (gcnew System::Drawing::Font(L"ＭＳ Ｐゴシック", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelJSONName->Location = System::Drawing::Point(27, 95);
			this->labelJSONName->Name = L"labelJSONName";
			this->labelJSONName->Size = System::Drawing::Size(65, 15);
			this->labelJSONName->TabIndex = 1;
			this->labelJSONName->Text = L"JSON名";
			// 
			// labelQuery
			// 
			this->labelQuery->AutoSize = true;
			this->labelQuery->Font = (gcnew System::Drawing::Font(L"ＭＳ Ｐゴシック", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelQuery->Location = System::Drawing::Point(47, 162);
			this->labelQuery->Name = L"labelQuery";
			this->labelQuery->Size = System::Drawing::Size(46, 15);
			this->labelQuery->TabIndex = 2;
			this->labelQuery->Text = L"クエリ";
			// 
			// textBoxDBName
			// 
			this->textBoxDBName->Location = System::Drawing::Point(109, 35);
			this->textBoxDBName->Name = L"textBoxDBName";
			this->textBoxDBName->Size = System::Drawing::Size(223, 19);
			this->textBoxDBName->TabIndex = 3;
			// 
			// textBoxJSONName
			// 
			this->textBoxJSONName->Location = System::Drawing::Point(109, 95);
			this->textBoxJSONName->Name = L"textBoxJSONName";
			this->textBoxJSONName->Size = System::Drawing::Size(223, 19);
			this->textBoxJSONName->TabIndex = 4;
			this->textBoxJSONName->DoubleClick += gcnew System::EventHandler(this, &EnvForm::textBoxJSONName_DoubleClick);
			// 
			// textBoxQuery
			// 
			this->textBoxQuery->Location = System::Drawing::Point(109, 162);
			this->textBoxQuery->Name = L"textBoxQuery";
			this->textBoxQuery->Size = System::Drawing::Size(223, 19);
			this->textBoxQuery->TabIndex = 5;
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(358, 154);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 23);
			this->buttonOK->TabIndex = 6;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &EnvForm::buttonOK_Click);
			// 
			// EnvForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(445, 204);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->textBoxQuery);
			this->Controls->Add(this->textBoxJSONName);
			this->Controls->Add(this->textBoxDBName);
			this->Controls->Add(this->labelQuery);
			this->Controls->Add(this->labelJSONName);
			this->Controls->Add(this->labelDB);
			this->Name = L"EnvForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"EnvForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: 
	String^ _JSONFilePath;
	String^ _DBName;
	String^ _Query;

public:
	property String^ JSONFilePath {
		String^ get() {
			return _JSONFilePath;
		}

		void  set(String^ path) {
			_JSONFilePath = path;
		}
	}

	property String^ DBName {
		String^ get() {
			return _DBName;
		}

		void  set(String^ dbName) {
			_DBName = dbName;
		}
	}

	property String^ Query {
		String^ get() {
			return _Query;
		}

		void  set(String^ query) {
			_Query = query;
		}
	}


private: System::Void textBoxJSONName_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
	
	//エクスプローラーを開くためのインスタンスを生成
	OpenFileDialog^ fileDialog = gcnew OpenFileDialog();

	//フィルターを設定
	fileDialog->Filter = "JSONファイル(*.json;*.txt)|*.json;*.txtl|すべてのファイル(*.*)|*.*";
	//2番目の「すべてのファイル」が選択されているようにする
	fileDialog->FilterIndex = 2;
	//タイトルを設定する
	fileDialog->Title = "開くファイルを選択してください";
	//ダイアログボックスを閉じる前に現在のディレクトリを復元するようにする
	fileDialog->RestoreDirectory = true;

	String^ filepath;
	//ダイアログを表示する
	if (fileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		//OKボタンがクリックされたとき、ファイルパスを取得
		filepath = (fileDialog->FileName);
	}
	
	//取得したファイルパスを外部からアクセスできるようにプロパティにセット
	JSONFilePath = filepath;
	//テキストボックスに表示
	textBoxJSONName->Text = filepath;
}
		 
private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
	
	JSONFilePath = textBoxJSONName->Text;
	Query = textBoxQuery->Text;

	this->Close();
}
};
}
