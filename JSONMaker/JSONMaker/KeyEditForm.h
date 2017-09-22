#pragma once


#ifndef __KEY_EDIT_FORM
#define __KEY_EDIT_FORM

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
	/// KeyEditForm の概要
	/// </summary>
	public ref class KeyEditForm : public System::Windows::Forms::Form
	{
	public:
		KeyEditForm(void)
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
		~KeyEditForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  labelKeyName;
	private: System::Windows::Forms::TextBox^  textBoxKeyName;
	private: System::Windows::Forms::Button^  buttonParent;
	private: System::Windows::Forms::Button^  buttonChild;
	private: System::Windows::Forms::Button^  buttonBigBro;
	private: System::Windows::Forms::Button^  buttonBro;
	private: System::Windows::Forms::RadioButton^  radioButtonYes;
	private: System::Windows::Forms::RadioButton^  radioButtonNo;


	private: System::Windows::Forms::Label^  labelIsArray;
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
			this->labelKeyName = (gcnew System::Windows::Forms::Label());
			this->textBoxKeyName = (gcnew System::Windows::Forms::TextBox());
			this->buttonParent = (gcnew System::Windows::Forms::Button());
			this->buttonChild = (gcnew System::Windows::Forms::Button());
			this->buttonBigBro = (gcnew System::Windows::Forms::Button());
			this->buttonBro = (gcnew System::Windows::Forms::Button());
			this->radioButtonYes = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonNo = (gcnew System::Windows::Forms::RadioButton());
			this->labelIsArray = (gcnew System::Windows::Forms::Label());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// labelKeyName
			// 
			this->labelKeyName->AutoSize = true;
			this->labelKeyName->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelKeyName->Location = System::Drawing::Point(73, 102);
			this->labelKeyName->Name = L"labelKeyName";
			this->labelKeyName->Size = System::Drawing::Size(46, 15);
			this->labelKeyName->TabIndex = 0;
			this->labelKeyName->Text = L"キー名";
			// 
			// textBoxKeyName
			// 
			this->textBoxKeyName->Location = System::Drawing::Point(158, 102);
			this->textBoxKeyName->Name = L"textBoxKeyName";
			this->textBoxKeyName->Size = System::Drawing::Size(100, 19);
			this->textBoxKeyName->TabIndex = 1;
			// 
			// buttonParent
			// 
			this->buttonParent->Location = System::Drawing::Point(60, 181);
			this->buttonParent->Name = L"buttonParent";
			this->buttonParent->Size = System::Drawing::Size(50, 50);
			this->buttonParent->TabIndex = 2;
			this->buttonParent->Text = L"親";
			this->buttonParent->UseVisualStyleBackColor = true;
			this->buttonParent->Click += gcnew System::EventHandler(this, &KeyEditForm::buttonParent_Click);
			// 
			// buttonChild
			// 
			this->buttonChild->Location = System::Drawing::Point(126, 181);
			this->buttonChild->Name = L"buttonChild";
			this->buttonChild->Size = System::Drawing::Size(50, 50);
			this->buttonChild->TabIndex = 3;
			this->buttonChild->Text = L"子";
			this->buttonChild->UseVisualStyleBackColor = true;
			this->buttonChild->Click += gcnew System::EventHandler(this, &KeyEditForm::buttonChild_Click);
			// 
			// buttonBigBro
			// 
			this->buttonBigBro->Location = System::Drawing::Point(196, 181);
			this->buttonBigBro->Name = L"buttonBigBro";
			this->buttonBigBro->Size = System::Drawing::Size(50, 50);
			this->buttonBigBro->TabIndex = 4;
			this->buttonBigBro->Text = L"兄";
			this->buttonBigBro->UseVisualStyleBackColor = true;
			this->buttonBigBro->Click += gcnew System::EventHandler(this, &KeyEditForm::buttonBigBro_Click);
			// 
			// buttonBro
			// 
			this->buttonBro->Location = System::Drawing::Point(266, 181);
			this->buttonBro->Name = L"buttonBro";
			this->buttonBro->Size = System::Drawing::Size(50, 50);
			this->buttonBro->TabIndex = 5;
			this->buttonBro->Text = L"弟";
			this->buttonBro->UseVisualStyleBackColor = true;
			this->buttonBro->Click += gcnew System::EventHandler(this, &KeyEditForm::buttonBigBro_Click);
			// 
			// radioButtonYes
			// 
			this->radioButtonYes->AutoSize = true;
			this->radioButtonYes->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->radioButtonYes->Location = System::Drawing::Point(172, 140);
			this->radioButtonYes->Name = L"radioButtonYes";
			this->radioButtonYes->Size = System::Drawing::Size(49, 19);
			this->radioButtonYes->TabIndex = 6;
			this->radioButtonYes->TabStop = true;
			this->radioButtonYes->Text = L"Yes";
			this->radioButtonYes->UseVisualStyleBackColor = true;
			// 
			// radioButtonNo
			// 
			this->radioButtonNo->AutoSize = true;
			this->radioButtonNo->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->radioButtonNo->Location = System::Drawing::Point(244, 140);
			this->radioButtonNo->Name = L"radioButtonNo";
			this->radioButtonNo->Size = System::Drawing::Size(43, 19);
			this->radioButtonNo->TabIndex = 7;
			this->radioButtonNo->TabStop = true;
			this->radioButtonNo->Text = L"No";
			this->radioButtonNo->UseVisualStyleBackColor = true;
			// 
			// labelIsArray
			// 
			this->labelIsArray->AutoSize = true;
			this->labelIsArray->Location = System::Drawing::Point(90, 145);
			this->labelIsArray->Name = L"labelIsArray";
			this->labelIsArray->Size = System::Drawing::Size(29, 12);
			this->labelIsArray->TabIndex = 8;
			this->labelIsArray->Text = L"配列";
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(172, 265);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 28);
			this->buttonOK->TabIndex = 9;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &KeyEditForm::buttonOK_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(266, 265);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 28);
			this->buttonCancel->TabIndex = 10;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// KeyEditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(385, 325);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->labelIsArray);
			this->Controls->Add(this->radioButtonNo);
			this->Controls->Add(this->radioButtonYes);
			this->Controls->Add(this->buttonBro);
			this->Controls->Add(this->buttonBigBro);
			this->Controls->Add(this->buttonChild);
			this->Controls->Add(this->buttonParent);
			this->Controls->Add(this->textBoxKeyName);
			this->Controls->Add(this->labelKeyName);
			this->Name = L"KeyEditForm";
			this->Text = L"KeyEditForm";
			this->Load += gcnew System::EventHandler(this, &KeyEditForm::KeyEditForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		//ラベルの配列
		array<Label^>^ labels;
		//キーの配列
		array<String^>^ keyArray;
		//すべてのセル
		CellChain^ gridCell;
		//どのキーについての編集かを設定する変数
		int keyLevel;
		//そのセルの行
		int row;
		//そのセルの列
		int col;
		//どのフォームから来たのかを示す
		int FormFrom;

		//
		System::Void CreateKeyLabels(int level) {
			labels = gcnew array<Label^>(keyArray->Length * 2);
			//ラベル作成の配列のカウント行う変数
			int labelCount = 0;
			//メンバのキー配列の長さ分だけ繰り返す
			for (int i = 0; i < level; i++) {
				//キーが空でなければ
				if (i == 0 || keyArray[i] != "") {
					//一番初めでなければ
					if (labelCount != 0) {
						//ラベルを作成
						labels[labelCount] = gcnew Label();
						//キーを分けるハイフンを書き込む
						labels[labelCount]->Text = "-";
						labels[labelCount]->Location = Point(labels[labelCount - 1]->Location.X + 65, 35);
						labels[labelCount]->Size = System::Drawing::Size(10, 35);
						this->Controls->Add(labels[labelCount]);
						labelCount++;
					}

					//ラベルの配列の要素にラベルを作成
					labels[labelCount] = gcnew Label();
					//ラベルにキーを格納
					labels[labelCount]->Text = keyArray[i];
					//ラベルがまだ作られていなければ
					if (labelCount == 0) {
						//初めのラベルの位置に配置
						labels[labelCount]->Location = Point(20, 35);
					}
					//ラベルがすでに作られているとき
					else {
						//位置を前のラベルに合わせる
						labels[labelCount]->Location = Point(labels[labelCount - 1]->Location.X + 15, 35);
					}
					//サイズを決定
					labels[labelCount]->Size = System::Drawing::Size(60, 35);
					//四角で囲む
					labels[labelCount]->BorderStyle = Windows::Forms::BorderStyle::FixedSingle;
					//フォームに追加
					this->Controls->Add(labels[labelCount]);
					//ラベルを次に移動
					labelCount++;
				}
			}
		}

		/*
		関数名:ClearLabels
		概要:ラベルを消去する関数
		引数:int level　キーの数
		返却値:無し
		作成日:9月22日(金)
		作成者:成田修之
		*/
		System::Void ClearLabels(int level) {
			//引数のキーの数だけ繰り返す
			for (int i = 0; i < level; i++) {
				//一番目でなければ
				if (i != 0) {
					//キー間のハイフンのラベルを削除した
					this->Controls->Remove(this->GetChildAtPoint(Point((i * 80)+ 5, 35)));
				}
				//キーのラベルを削除する
				this->Controls->Remove(this->GetChildAtPoint(Point(20 + (i * 80),35)));
			}
		}

		//立ち上げ時のイベント
	private: System::Void KeyEditForm_Load(System::Object^  sender, System::EventArgs^  e) {
		//値へのパスとなるラベル群を作成する
		CreateKeyLabels(keyLevel);
		//一番下の編集対象の値をテキストボックスに表示
		textBoxKeyName->Text = keyArray[keyLevel];
	}

			 //親ボタンが押されたときのイベント
	private: System::Void buttonParent_Click(System::Object^  sender, System::EventArgs^  e) {
		//親のキーについての編集の時
		if (keyLevel == 0) {
			//メッセージボックスでそれ以上上の親を作成することができない
			MessageBox::Show("作成できません", "エラー", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		//キー編集のフォームのインスタンスを作成
		KeyEditForm^ keyEditform = gcnew KeyEditForm();
		//キーの配列を渡す
		keyEditform->keyArray = keyArray;
		//親ボタンからであることを渡す
		keyEditform->FormFrom = constants.FROM_PARENT_BUTTON;
		//フォームをモーダル表示する
		keyEditform->ShowDialog();
		//現在出ているラベルを削除する
		ClearLabels(keyArray->Length);
		//キーの配列を受け取る
		keyArray = keyEditform->keyArray;
		//うけとったキーの配列でラベルを作成する
		CreateKeyLabels(keyArray->Length);
	}

			 //子ボタンが押されたときのイベント
	private: System::Void buttonChild_Click(System::Object^  sender, System::EventArgs^  e) {
		//キー編集のフォームのインスタンスを作成
		KeyEditForm^ keyEditform = gcnew KeyEditForm();
		//キーの配列を渡す
		keyEditform->keyArray = keyArray;
		//どの階層かを示す値を渡す
		keyEditform->keyLevel = keyLevel;
		//子ボタンからであることを渡す
		keyEditform->FormFrom = constants.FROM_CHILD_BUTTON;
		//フォームをモーダル表示する
		keyEditform->ShowDialog();
		//現在出ているラベルを削除する
		ClearLabels(keyArray->Length);
		//キーの配列を受け取る
		keyArray = keyEditform->keyArray;
		//うけとったキーの配列でラベルを作成する
		CreateKeyLabels(keyArray->Length);
	}



			 //兄ボタンが押されたときのイベント
	private: System::Void buttonBigBro_Click(System::Object^  sender, System::EventArgs^  e) {
		//兄からか、弟からかを示す値
		int formFrom = 0;
		//兄ボタンから
		if (sender->Equals(buttonBigBro)) {
			//兄であることを占めす値を取得
			formFrom = constants.FROM_BIGBRO_BUTTON;
		}
		//弟ボタンから
		else {
			//弟であることを示す値を格納
			formFrom = constants.FROM_BRO_BUTTON;
		}
		//キー編集フォームを作製
		KeyEditForm^ keyEdit = gcnew KeyEditForm();
		//どこから来たかを格納
		keyEdit->FormFrom = formFrom;
		//フォームにキーの配列を渡す
		keyEdit->keyArray = keyArray;
		//モーダル表示
		keyEdit->ShowDialog();
	}

	private:

		System::Void insertKeyArray(array<String^>^ arr, String^  value, int index) {
			//配列を要素数の＋1にしたものでとる
			array<String^>^ retArr = gcnew array<String^>(arr->Length + 1);
			//要素を数える変数
			int j = 0;
			//配列の長さ分だけ繰り返す
			for (int i = 0; i < retArr->Length; i++, j++) {
				//引数で指定されたインデックスなら
				if (i = index) {
					//その位置に引数の値を格納して次へ
					retArr[i++] = value;
				}
				//作成した配列に移す
				retArr[i] = arr[j];
			}
			//作成した配列をメンバに保存する
			arr = retArr;
		}


		/*
		関数名:createParent
		概要:親から呼ばれ時の処理
		引数:無し
		返却値:無し
		作成日:9月22日(金)
		作成者:成田修之
		*/
		System::Void createParent() {
			//メンバの配列の階層の位置にテキストボックスに入力されている値を格納する
			insertKeyArray(keyArray, textBoxKeyName->Text, keyLevel);
		}

		/*
		関数名:createChild
		概要:子ボタンから呼ばれた時の処理
		引数:無し
		返却値:無し
		作成日:9月22日(金)
		作成者:成田修之
		*/
		System::Void createChild() {
			//編集中のキーの階層が行をなす親の階層の時
			if (keyLevel == constants.LEVEL_PARENT) {
				//編集中のセルの先頭のセルを取得
				CellChain^ rowCell = this->gridCell->getCell(row, 0);
				//列数分繰り返す
				while (rowCell == nullptr) {
					//そのセルのキーの配列に入力されている値を格納していく
					insertKeyArray(rowCell->CellKey, textBoxKeyName->Text, keyLevel);
					//次のセルへ
					rowCell = rowCell->right;
				}
			}
			//親ではないとき
			else {
				//編集中のセルのキーの親にテキストボックスに入力された値を挿入
				KeyEditForm::insertKeyArray(keyArray, textBoxKeyName->Text, keyLevel);
			}

		}

		/*
		関数名:createBro
		概要:兄弟ボタンから呼ばれていた時の処理
		引数:無し
		返却値:無し
		作成日:9月22日(金)
		作成者:成田修之
		*/
		System::Void createBro() {
			//
			int insertRowNum = 0;
			//階層が親の時
			if (keyLevel == constants.LEVEL_PARENT) {
				//兄ボタンから呼ばれたフォームであるなら
				if (FormFrom == constants.FROM_BIGBRO_BUTTON) {
					//読んだセルの行取得
					insertRowNum = row;

				}
				//弟ボタンからよばれたフォームの時
				else {
					//下のセルを取得
					insertRowNum = row + 1;
				}
				//取得した行に挿入してその時の先頭のセルを取得
				CellChain^ rowCell = gridCell->insertRow(insertRowNum);
				
				//列数分繰り返す
				while (rowCell == nullptr) {
					//そのセルのキーの配列の一番上にテキストボックスに入力された値を格納する
					rowCell->CellKey[keyLevel] = textBoxKeyName->Text;
					//次のセルへ移動
					rowCell = rowCell->right;
				}
			}
			else {
				//兄から呼ばれた場合
				if (FormFrom == constants.FROM_BIGBRO_BUTTON) {
					//呼んだ時のセルを取得する

				}
				//弟からの場合
				else {
					//読んだ時のセルの右のセルを取得する

				}
				//insert();
				//
				array<String^>^ temp = gcnew array<String^>(keyLevel);
				//
				for (int i = 0; i < keyLevel; i++) {
					//
					temp[i] = keyArray[i];
				}

			}
		}

		/*
		関数名:changeKey
		概要:セル編集フォームから呼ばれたときの処理
		引数:無し
		返却値:無し
		作成日:9月22日(金)
		作成者:成田修之
		*/
		System::Void changeKey() {
			//編集中のキーの階層が行をなす親の階層の時
			if (keyLevel == constants.LEVEL_PARENT) {
				//編集中のセルの先頭のセルを取得
				CellChain^ rowCell = this->gridCell->getCell(row -1, 0);
				//列数分繰り返す
				while (rowCell != nullptr) {
					//配列のその位置の値をテキストボックスに入力されている値にする
					rowCell->CellKey[keyLevel] = textBoxKeyName->Text;
					//次のセルへ
					rowCell = rowCell->right;
				}
			}
			//親ではないとき
			else {
				//そのセルだけキーを変更
				keyArray[keyLevel] = textBoxKeyName->Text;
			}
		}


		/*
		関数名:buttonOK_Click
		概要:入力を終え、OKボタンを押したときの処理
		引数:無し
		返却値:無し
		作成日:9月22日(金)
		作成者:成田修之
		*/
	private:
		System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
			//このフォームが親ボタンから呼び出された時
			if (FormFrom == constants.FROM_PARENT_BUTTON) {
				//親からの処理を実行
				createParent();
			}
			//子ボタンから呼び出されたとき
			else if (FormFrom == constants.FROM_CHILD_BUTTON) {
				//子からのときの処理を実行
				createChild();
			}
			//兄弟ボタンから呼び出されたとき
			else if (FormFrom == constants.FROM_BIGBRO_BUTTON || FormFrom == constants.FROM_BIGBRO_BUTTON) {
				//兄弟からの時の処理を実行
				createBro();
			}
			//どのボタンからでもなくセルから呼ばれた最初のフォームの時
			else {
				//同じキー
				changeKey();
			}
			//フォームを閉じる
			this->Close();
		}
	};
}

#endif // !__KEY_EDIT_FORM
