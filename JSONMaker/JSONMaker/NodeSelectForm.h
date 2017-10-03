#pragma once

namespace JSONMaker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// NodeSelectForm の概要
	/// </summary>
	public ref class NodeSelectForm : public System::Windows::Forms::Form
	{
	public:
		NodeSelectForm(void)
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
		~NodeSelectForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::Button^  buttonCancel;
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
			this->SuspendLayout();
			// 
			// buttonOK
			// 
			this->buttonOK->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->buttonOK->Location = System::Drawing::Point(12, 16);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 23);
			this->buttonOK->TabIndex = 1;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &NodeSelectForm::buttonOK_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonCancel->Location = System::Drawing::Point(114, 16);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 2;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// NodeSelectForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(288, 271);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonOK);
			this->Name = L"NodeSelectForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"NodeSelectForm";
			this->Load += gcnew System::EventHandler(this, &NodeSelectForm::NodeSelectForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	public:array<String^>^ Nodes;
	public:String^ selectedNode;
	public: array<RadioButton^>^ buttonNodes;

			/*
			関数名:NodeSelectForm_Load
			概要:このフォームが立ち上がる時に行う処理
			引数:イベントの引数
			返却値:無し
			作成日:9月15日(金)
			作成者:成田修之
			*/
	private: System::Void NodeSelectForm_Load(System::Object^  sender, System::EventArgs^  e) {
		//フォームに渡されたノード群の数を取得
		int len = Nodes->Length;
		//ラジオボタンの配列を生成
		buttonNodes = gcnew array<RadioButton^>(len);

		//ノードの数だけ繰り返す
		for (int i = 0; i < len; i++) {
			//ラジオボタンを生成して各種情報追加
			buttonNodes[i] = gcnew RadioButton();
			buttonNodes[i]->Text = Nodes[i];
			buttonNodes[i]->Location = Point(25, buttonOK->Bottom + 10 + (i * 25));
			buttonNodes[i]->BackColor = Color::White;
			//フォームに加える
			this->Controls->Add(buttonNodes[i]);

		}
	}
			 /*
			 関数名:buttonOK_Click
			 概要:OKボタンがクリックされたときのイベント
			 引数:イベントの引数
			 返却値:無し
			 作成日:9月15日(金)
			 作成者:成田修之
			 */
	private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
		//選択されていないラジオボタンの数を取得するための変数
		int i;
		//ラジオボタンの数だけ繰り返す
		for (i = 0; i < buttonNodes->Length; i++) {
			//チェックされていたら
			if (buttonNodes[i]->Checked) {
				//選択されたノードをメンバに格納して
				selectedNode = buttonNodes[i]->Text;
				//ループを抜ける
				break;
			}
		}
		//変数がラジオボタンの数と同じとき
		if (i == buttonNodes->Length) {
			//選択されていなかったことを警告
			MessageBox::Show("ノードが選択されていません", "警告", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		//ラジオボタンの数より小さければ
		else {
			//選択されたものとしてフォームを閉じる
			this->Close();
		}
	}
};
}
