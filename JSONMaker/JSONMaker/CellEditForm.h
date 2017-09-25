#pragma once
#ifndef __CELL_EDIT_FORM
#define __CELL_EDIT_FORM

#include "KeyEditForm.h"
#include "Constants.h"
#include "CellChain.h"

namespace JSONMaker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// CellEditForm の概要
	/// </summary>
	public ref class CellEditForm : public System::Windows::Forms::Form
	{
	public:
		CellEditForm(void)
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
		~CellEditForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  labelKeyName;
	private: System::Windows::Forms::Label^  labelValue;
	private: System::Windows::Forms::Label^  labelIsArray;
	private: System::Windows::Forms::RadioButton^  radioButtonYes;
	protected:

	protected:



	private: System::Windows::Forms::RadioButton^  radioButtonNo;
	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::Button^  buttonCancel;
	private: System::Windows::Forms::TextBox^  textBoxKeyName;
	private: System::Windows::Forms::TextBox^  textBoxValue;





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
			this->labelKeyName = (gcnew System::Windows::Forms::Label());
			this->labelValue = (gcnew System::Windows::Forms::Label());
			this->labelIsArray = (gcnew System::Windows::Forms::Label());
			this->radioButtonYes = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonNo = (gcnew System::Windows::Forms::RadioButton());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->textBoxKeyName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxValue = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// labelKeyName
			// 
			this->labelKeyName->AutoSize = true;
			this->labelKeyName->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelKeyName->Location = System::Drawing::Point(55, 104);
			this->labelKeyName->Name = L"labelKeyName";
			this->labelKeyName->Size = System::Drawing::Size(46, 15);
			this->labelKeyName->TabIndex = 0;
			this->labelKeyName->Text = L"キー名";
			// 
			// labelValue
			// 
			this->labelValue->AutoSize = true;
			this->labelValue->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelValue->Location = System::Drawing::Point(55, 145);
			this->labelValue->Name = L"labelValue";
			this->labelValue->Size = System::Drawing::Size(22, 15);
			this->labelValue->TabIndex = 1;
			this->labelValue->Text = L"値";
			// 
			// labelIsArray
			// 
			this->labelIsArray->AutoSize = true;
			this->labelIsArray->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelIsArray->Location = System::Drawing::Point(55, 184);
			this->labelIsArray->Name = L"labelIsArray";
			this->labelIsArray->Size = System::Drawing::Size(37, 15);
			this->labelIsArray->TabIndex = 2;
			this->labelIsArray->Text = L"配列";
			// 
			// radioButtonYes
			// 
			this->radioButtonYes->AutoSize = true;
			this->radioButtonYes->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->radioButtonYes->Location = System::Drawing::Point(144, 182);
			this->radioButtonYes->Name = L"radioButtonYes";
			this->radioButtonYes->Size = System::Drawing::Size(49, 19);
			this->radioButtonYes->TabIndex = 3;
			this->radioButtonYes->Text = L"Yes";
			this->radioButtonYes->UseVisualStyleBackColor = true;
			// 
			// radioButtonNo
			// 
			this->radioButtonNo->AutoSize = true;
			this->radioButtonNo->Location = System::Drawing::Point(212, 185);
			this->radioButtonNo->Name = L"radioButtonNo";
			this->radioButtonNo->Size = System::Drawing::Size(37, 16);
			this->radioButtonNo->TabIndex = 4;
			this->radioButtonNo->Text = L"No";
			this->radioButtonNo->UseVisualStyleBackColor = true;
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(118, 238);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 23);
			this->buttonOK->TabIndex = 5;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &CellEditForm::buttonOK_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(212, 238);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 6;
			this->buttonCancel->Text = L"キャンセル";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// textBoxKeyName
			// 
			this->textBoxKeyName->Location = System::Drawing::Point(149, 104);
			this->textBoxKeyName->Name = L"textBoxKeyName";
			this->textBoxKeyName->Size = System::Drawing::Size(100, 19);
			this->textBoxKeyName->TabIndex = 7;
			// 
			// textBoxValue
			// 
			this->textBoxValue->Location = System::Drawing::Point(149, 145);
			this->textBoxValue->Name = L"textBoxValue";
			this->textBoxValue->Size = System::Drawing::Size(100, 19);
			this->textBoxValue->TabIndex = 8;
			// 
			// CellEditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(338, 302);
			this->Controls->Add(this->textBoxValue);
			this->Controls->Add(this->textBoxKeyName);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->radioButtonNo);
			this->Controls->Add(this->radioButtonYes);
			this->Controls->Add(this->labelIsArray);
			this->Controls->Add(this->labelValue);
			this->Controls->Add(this->labelKeyName);
			this->Name = L"CellEditForm";
			this->Text = L"CellEditForm";
			this->Load += gcnew System::EventHandler(this, &CellEditForm::CellEditForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		//セルのキーの配列
		array<String^>^ keyArray;
		//セルの値
		String^ Value;
		array<Label^>^ labels;

		//全体のセル
		CellChain^ cell;

		//そのセルの行
		int row;
		//そのセルの列
		int col;


	private:
		System::Void createKeyLabels(int level) {
			//ラベルの配列を作成
			labels = gcnew array<Label^>(keyArray->Length * 2);
			//ラベル作成の配列のカウント行う変数
			int labelCount = 0;
			//メンバのキー配列の長さ分だけ繰り返す
			for (int i = 0; i <= level; i++) {
				//キーが空でなければ
				if (i == 0 || keyArray[i] != "") {
					//一番初めでなければ
					if (labelCount != 0) {
						//ラベルを作成
						labels[labelCount] = gcnew Label();
						//キーを分けるハイフンを書き込む
						labels[labelCount]->Text = "-";
						labels[labelCount]->Location = Point((i * 70) + 5, 50);
						labels[labelCount]->Size = System::Drawing::Size(10, 40);
						//フォームにラベルを追加
						this->Controls->Add(labels[labelCount]);
						labelCount++;
					}

					//ラベルの配列の要素にラベルを作成
					labels[labelCount] = gcnew Label();
					//ラベルにキーを格納
					labels[labelCount]->Text = keyArray[i];
					//ラベルをまだ作成していなければ
					if (labelCount == 0) {
						//位置を初期位置に
						labels[labelCount]->Location = Point(20, 35);
					}
					//一個以上作成済み
					else {
						//前のラベルに場所を合わせておく
						labels[labelCount]->Location = Point((i * 70) + 20, 35);
					}
					//ラベルの情報を渡す
					labels[labelCount]->Size = System::Drawing::Size(50, 40);
					labels[labelCount]->BorderStyle = Windows::Forms::BorderStyle::FixedSingle;
					labels[labelCount]->DoubleClick += gcnew EventHandler(this, &CellEditForm::LavelKeys_Click);
					//フォームに追加する
					this->Controls->Add(labels[labelCount]);
					//ラベルを次に作成するために次へ
					labelCount++;
				}
			}
		}

		/*
		関数名:ClearLabels
		概要:
		引数:
		返却値:
		作成日:
		作成者:
		*/
		System::Void ClearLabels(int level) {
			//表示させるラベルの数だけ繰り返す
			for (int i = 0; i < level; i++) {
				//一番目だけでなければ
				if (i != 0) {
					//キー間のハイフンのラベルを削除
					this->Controls->Remove(this->GetChildAtPoint(Point((i * 80) + 5, 35)));
				}
				//キーのラベルを削除する
				this->Controls->Remove(this->GetChildAtPoint(Point((i * 80) + 20, 35)));
			}
		}

	private:
		/*
		関数名:CellEditForm_Load
		概要:このフォームが表示される前に行われる処理
		引数:イベントの引数
		返却値:無し
		作成日:9月20日(水)
		作成者:成田修之
		*/
		System::Void CellEditForm_Load(System::Object^  sender, System::EventArgs^  e) {
			
			//どの位置のセルについての情報かをタイトルに表示
			this->Text = "行:" + row.ToString() + " 列:" + col.ToString() + " の情報";
			//受け取ったキーの配列でラベルを作成
			createKeyLabels(keyArray->Length - 1);
			//一番下のキーを表示
			textBoxKeyName->Text = keyArray[keyArray->Length - 1];
			//値をテキストボックスに値を表示
			textBoxValue->Text = this->Value;
		}

	private:
		/*
		関数名:LabelKeys_Click
		概要:ラベルをクリックしたときのイベント
		引数:イベントの引数
		返却値:無し
		作成日:9月20日(水)
		作成者:成田修之
		*/
		System::Void LavelKeys_Click(System::Object^ sender, System::EventArgs^ e)
		{
			//どのボタンが押されたかを取得
			int level = (((Label^)sender)->Location.X - 20) / 70;
			//キー編集フォームを作製
			KeyEditForm^ keyEdit = gcnew KeyEditForm();
			keyEdit->row = row-1;
			keyEdit->col = col;
			//フォームに配列を渡す
			keyEdit->keyArray = keyArray;
			//どのキーが押されたのか階層を渡す
			keyEdit->keyLevel = level;
			//セル表示に用いるオブジェクトを渡す
			keyEdit->gridCell = cell;
			//フォームを表示
			keyEdit->ShowDialog();
			ClearLabels(keyArray->Length);
			//配列を受け取る
			keyArray = keyEdit->keyArray;
			createKeyLabels(keyArray->Length -1);
			textBoxKeyName->Text = keyArray[keyArray->Length - 1];
		}

		/*
		関数名:buttonOK_Click
		概要:OKボタンが押されたときのイベント
		引数:イベントの引数
		返却値:無し
		作成日:9月20日(水)
		作成者:成田修之
		*/
	private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
		//テキストボックスに入力されたキー名をキーの該当する位置に格納
		this->keyArray[keyArray->Length - 1] = textBoxKeyName->Text;
		//テキストボックスに入力された値をメンバに格納
		Value = textBoxValue->Text;
		//値が入力されていないとき
		if ("" == Value) {
			//入力されていないことを警告
			MessageBox::Show("値が入力されていません", "警告", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}

		//配列にチェックがあれば
		if (radioButtonYes->Checked) {
			//後ろに配列を示すキーを追加する
			keyArray[keyArray->Length - 1] = gcnew String(constants.KEY_ISARRAY.c_str());
		}
		this->Close();
	}
	};
}

#endif // !__CELL_EDIT_FORM