#pragma once
#include "Constants.h"

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
	protected: System::Windows::Forms::TextBox^  textBoxKey;
	private: System::Windows::Forms::TextBox^  textBoxValue;
	protected:

	protected:

	protected:

	private: System::Windows::Forms::Label^  labelKey;
	private: System::Windows::Forms::Label^  labelValue;
	private: System::Windows::Forms::Button^  buttonCandel;
	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::Button^  buttonParent;
	private: System::Windows::Forms::Button^  buttonChild;




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
			this->textBoxKey = (gcnew System::Windows::Forms::TextBox());
			this->textBoxValue = (gcnew System::Windows::Forms::TextBox());
			this->labelKey = (gcnew System::Windows::Forms::Label());
			this->labelValue = (gcnew System::Windows::Forms::Label());
			this->buttonCandel = (gcnew System::Windows::Forms::Button());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonParent = (gcnew System::Windows::Forms::Button());
			this->buttonChild = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBoxKey
			// 
			this->textBoxKey->Location = System::Drawing::Point(125, 66);
			this->textBoxKey->Name = L"textBoxKey";
			this->textBoxKey->Size = System::Drawing::Size(100, 19);
			this->textBoxKey->TabIndex = 0;
			// 
			// textBoxValue
			// 
			this->textBoxValue->Location = System::Drawing::Point(125, 104);
			this->textBoxValue->Name = L"textBoxValue";
			this->textBoxValue->Size = System::Drawing::Size(100, 19);
			this->textBoxValue->TabIndex = 1;
			// 
			// labelKey
			// 
			this->labelKey->AutoSize = true;
			this->labelKey->Location = System::Drawing::Point(49, 69);
			this->labelKey->Name = L"labelKey";
			this->labelKey->Size = System::Drawing::Size(37, 12);
			this->labelKey->TabIndex = 2;
			this->labelKey->Text = L"キー名";
			// 
			// labelValue
			// 
			this->labelValue->AutoSize = true;
			this->labelValue->Location = System::Drawing::Point(49, 107);
			this->labelValue->Name = L"labelValue";
			this->labelValue->Size = System::Drawing::Size(17, 12);
			this->labelValue->TabIndex = 3;
			this->labelValue->Text = L"値";
			// 
			// buttonCandel
			// 
			this->buttonCandel->Location = System::Drawing::Point(187, 185);
			this->buttonCandel->Name = L"buttonCandel";
			this->buttonCandel->Size = System::Drawing::Size(75, 23);
			this->buttonCandel->TabIndex = 5;
			this->buttonCandel->Text = L"Cancel";
			this->buttonCandel->UseVisualStyleBackColor = true;
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(187, 156);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 23);
			this->buttonOK->TabIndex = 6;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &CellEditForm::buttonOK_Click);
			// 
			// buttonParent
			// 
			this->buttonParent->Location = System::Drawing::Point(39, 156);
			this->buttonParent->Name = L"buttonParent";
			this->buttonParent->Size = System::Drawing::Size(47, 52);
			this->buttonParent->TabIndex = 7;
			this->buttonParent->Text = L"親";
			this->buttonParent->UseVisualStyleBackColor = true;
			this->buttonParent->Click += gcnew System::EventHandler(this, &CellEditForm::buttonParent_Click);
			// 
			// buttonChild
			// 
			this->buttonChild->Location = System::Drawing::Point(101, 156);
			this->buttonChild->Name = L"buttonChild";
			this->buttonChild->Size = System::Drawing::Size(47, 52);
			this->buttonChild->TabIndex = 8;
			this->buttonChild->Text = L"子";
			this->buttonChild->UseVisualStyleBackColor = true;
			this->buttonChild->Click += gcnew System::EventHandler(this, &CellEditForm::buttonChild_Click);
			// 
			// CellEditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(296, 237);
			this->Controls->Add(this->buttonChild);
			this->Controls->Add(this->buttonParent);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->buttonCandel);
			this->Controls->Add(this->labelValue);
			this->Controls->Add(this->labelKey);
			this->Controls->Add(this->textBoxValue);
			this->Controls->Add(this->textBoxKey);
			this->Name = L"CellEditForm";
			this->Text = L"CellEditForm";
			this->Load += gcnew System::EventHandler(this, &CellEditForm::CellEditForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:

		String^ key;
		String^ value;
		array<String^>^ keyArray;
		array<Label^>^ labels;
		int level;
		int FormFrom;


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
					//Slabels[labelCount]->DoubleClick += gcnew EventHandler(this, &CellEditForm::LavelKeys_Click);
					//フォームに追加する
					this->Controls->Add(labels[labelCount]);
					//ラベルを次に作成するために次へ
					labelCount++;
				}
			}
		}

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

		System::Void LavelKeys_Click(System::Object^ sender, System::EventArgs^ e)
		{
			//どのボタンが押されたかを取得
			int level = (((Label^)sender)->Location.X - 20) / 70;
			//キー編集フォームを作製
			CellEditForm^ keyEdit = gcnew CellEditForm();
			//フォームに配列を渡す
			keyEdit->keyArray = keyArray;
			//どのキーが押されたのか階層を渡す
			keyEdit->level = level;
			//フォームを表示
			keyEdit->ShowDialog();
			ClearLabels(keyArray->Length);
			//配列を受け取る
			keyArray = keyEdit->keyArray;
			createKeyLabels(keyArray->Length - 1);
			textBoxKey->Text = keyArray[keyArray->Length - 1];
		}

	private:
		System::Void CellEditForm_Load(System::Object^  sender, System::EventArgs^  e) {
			//フォームに渡されたキーと値をテキストボックスに入力
			textBoxKey->Text = key;
			textBoxValue->Text = value;
			//値が渡されていなければ
			if ("" == value || nullptr == value) {
				//値のテキストボックスを非表示にする
				textBoxValue->Visible = false;
			}
		}

	private:
		System::Void buttonParent_Click(System::Object^  sender, System::EventArgs^  e) {
			//親のキーについての編集の時
			if (level == 0) {
				//メッセージボックスでそれ以上上の親を作成することができない
				MessageBox::Show("作成できません", "エラー", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			//キー編集のフォームのインスタンスを作成
			CellEditForm^ keyEditform = gcnew CellEditForm();
			//キーの配列を渡す
			keyEditform->keyArray = keyArray;
			//親ボタンからであることを渡す
			keyEditform->FormFrom = constants.FROM_PARENT_BUTTON;
			keyEditform->level = level;
			//keyEditform->gridCell = gridCell;
			//フォームをモーダル表示する
			keyEditform->ShowDialog();
			//現在出ているラベルを削除する
			ClearLabels(keyArray->Length);
			//キーの配列を受け取る
			keyArray = keyEditform->keyArray;
			level += 1;
			//うけとったキーの配列でラベルを作成する
			createKeyLabels(keyArray->Length);
		}

		//子ボタンが押されたときのイベント
	private:
		System::Void buttonChild_Click(System::Object^  sender, System::EventArgs^  e) {
			//キー編集のフォームのインスタンスを作成
			CellEditForm^ keyEditform = gcnew CellEditForm();
			//キーの配列を渡す
			keyEditform->keyArray = keyArray;
			//どの階層かを示す値を渡す
			keyEditform->level = level;
			//子ボタンからであることを渡す
			keyEditform->FormFrom = constants.FROM_CHILD_BUTTON;
			//フォームをモーダル表示する
			keyEditform->ShowDialog();
			//現在出ているラベルを削除する
			ClearLabels(keyArray->Length);
			//キーの配列を受け取る
			keyArray = keyEditform->keyArray;
			//うけとったキーの配列でラベルを作成する
			createKeyLabels(keyArray->Length - 1);
		}

		//配列を要素数の＋1にしたものでとる
		array<String^>^ insertKeyArray(array<String^>^ arr, String^  value, int index) {
			//配列を要素数の挿入する要素分の＋1にしたものでとる
			array<String^>^ retArr = gcnew array<String^>(arr->Length + 1);
			//要素を数える変数
			int j = 0;
			int i = 0;
			//配列の長さ分だけ繰り返す
			for (; i < retArr->Length; ) {
				//引数で指定されたインデックス
				if (index == i) {
					//その位置に引数の値を格納して次へ
					retArr[i++] = value;
				}
				//作成した配列に移す
				retArr[i++] = arr[j++];
			}
			//作成した配列をメンバに保存する
			return retArr;
		}

		//親を作る
		System::Void createParent() {
			//メンバの配列の階層の位置にテキストボックスに入力されている値を格納する
			keyArray = insertKeyArray(keyArray, textBoxKey->Text, level);
		}

		//子を作る
		System::Void createChild() {
			//テキストボックスに入力されている値を
			keyArray = insertKeyArray(keyArray, textBoxKey->Text, level + 1);
		}

		System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
			//入力されたキーをメンバにセット
			key = textBoxKey->Text;
			//値をメンバにセット
			value = textBoxValue->Text;

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

			this->Close();
		}

};
}

