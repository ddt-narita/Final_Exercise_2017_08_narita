#pragma once
#include "Constants.h"
#include "ChainData.h"

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
	private: System::Windows::Forms::Button^  buttonCancel;

	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::Button^  buttonParent;
	private: System::Windows::Forms::Button^  buttonChild;
	private: System::Windows::Forms::Button^  buttonBigBro;
	private: System::Windows::Forms::Button^  buttonBro;




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
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonParent = (gcnew System::Windows::Forms::Button());
			this->buttonChild = (gcnew System::Windows::Forms::Button());
			this->buttonBigBro = (gcnew System::Windows::Forms::Button());
			this->buttonBro = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBoxKey
			// 
			this->textBoxKey->Location = System::Drawing::Point(133, 87);
			this->textBoxKey->Name = L"textBoxKey";
			this->textBoxKey->Size = System::Drawing::Size(100, 19);
			this->textBoxKey->TabIndex = 0;
			// 
			// textBoxValue
			// 
			this->textBoxValue->Location = System::Drawing::Point(133, 133);
			this->textBoxValue->Name = L"textBoxValue";
			this->textBoxValue->Size = System::Drawing::Size(100, 19);
			this->textBoxValue->TabIndex = 1;
			// 
			// labelKey
			// 
			this->labelKey->AutoSize = true;
			this->labelKey->Location = System::Drawing::Point(77, 90);
			this->labelKey->Name = L"labelKey";
			this->labelKey->Size = System::Drawing::Size(37, 12);
			this->labelKey->TabIndex = 2;
			this->labelKey->Text = L"キー名";
			// 
			// labelValue
			// 
			this->labelValue->AutoSize = true;
			this->labelValue->Location = System::Drawing::Point(97, 136);
			this->labelValue->Name = L"labelValue";
			this->labelValue->Size = System::Drawing::Size(17, 12);
			this->labelValue->TabIndex = 3;
			this->labelValue->Text = L"値";
			// 
			// buttonCancel
			// 
			this->buttonCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonCancel->Location = System::Drawing::Point(258, 211);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(88, 41);
			this->buttonCancel->TabIndex = 5;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &CellEditForm::buttonCancel_Click);
			// 
			// buttonOK
			// 
			this->buttonOK->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->buttonOK->Location = System::Drawing::Point(258, 163);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(88, 42);
			this->buttonOK->TabIndex = 6;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &CellEditForm::buttonOK_Click);
			// 
			// buttonParent
			// 
			this->buttonParent->Location = System::Drawing::Point(17, 182);
			this->buttonParent->Name = L"buttonParent";
			this->buttonParent->Size = System::Drawing::Size(47, 56);
			this->buttonParent->TabIndex = 7;
			this->buttonParent->Text = L"親";
			this->buttonParent->UseVisualStyleBackColor = true;
			this->buttonParent->Click += gcnew System::EventHandler(this, &CellEditForm::ButtonFamily_Click);
			// 
			// buttonChild
			// 
			this->buttonChild->Location = System::Drawing::Point(70, 182);
			this->buttonChild->Name = L"buttonChild";
			this->buttonChild->Size = System::Drawing::Size(47, 56);
			this->buttonChild->TabIndex = 8;
			this->buttonChild->Text = L"子";
			this->buttonChild->UseVisualStyleBackColor = true;
			this->buttonChild->Click += gcnew System::EventHandler(this, &CellEditForm::ButtonFamily_Click);
			// 
			// buttonBigBro
			// 
			this->buttonBigBro->Location = System::Drawing::Point(123, 182);
			this->buttonBigBro->Name = L"buttonBigBro";
			this->buttonBigBro->Size = System::Drawing::Size(47, 56);
			this->buttonBigBro->TabIndex = 9;
			this->buttonBigBro->Text = L"兄";
			this->buttonBigBro->UseVisualStyleBackColor = true;
			this->buttonBigBro->Click += gcnew System::EventHandler(this, &CellEditForm::ButtonFamily_Click);
			// 
			// buttonBro
			// 
			this->buttonBro->Location = System::Drawing::Point(176, 182);
			this->buttonBro->Name = L"buttonBro";
			this->buttonBro->Size = System::Drawing::Size(48, 56);
			this->buttonBro->TabIndex = 10;
			this->buttonBro->Text = L"弟";
			this->buttonBro->UseVisualStyleBackColor = true;
			this->buttonBro->Click += gcnew System::EventHandler(this, &CellEditForm::ButtonFamily_Click);
			// 
			// CellEditForm
			// 
			this->AcceptButton = this->buttonOK;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->buttonCancel;
			this->ClientSize = System::Drawing::Size(358, 264);
			this->Controls->Add(this->buttonBro);
			this->Controls->Add(this->buttonBigBro);
			this->Controls->Add(this->buttonChild);
			this->Controls->Add(this->buttonParent);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->labelValue);
			this->Controls->Add(this->labelKey);
			this->Controls->Add(this->textBoxValue);
			this->Controls->Add(this->textBoxKey);
			this->Name = L"CellEditForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"CellEditForm";
			this->Load += gcnew System::EventHandler(this, &CellEditForm::CellEditForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		ChainData* cell;
		array<Label^>^ labels;
		int FormFrom;

	private:
		System::Void createKeyLabels(array<String^>^ path) {
			//ラベル配列の長さをハイフン分を含めてキーの数×２＋１にする
			labels = gcnew array<Label^>(path->Length * 2);
			//ラベル配列のインデックス
			int labelIndex = 0;
			//引数のキー配列の長さ分だけ繰り返す
			for (int i = 0; i < path->Length; i++) {
				//一番初めでないなら（ハイフンのラベルを作る）
				if (0 != i) {
					//ラベルを生成する
					labels[labelIndex] = gcnew Label();
					//大きさをハイフン分に合わせる
					labels[labelIndex]->Size = System::Drawing::Size(10, 35);
					//位置をハイフンに合わせる
					labels[labelIndex]->Location = Point((i * 80) + 5, 20);
					//ラベルにハイフンを書き込む
					labels[labelIndex]->Text = "\n-";
					//ラベル配列のインデックスを次へ
					labelIndex++;
				}//ハイフン分完了

				//ラベルを作成する
				labels[labelIndex] = gcnew Label();
				//サイズをキーに合わせる
				labels[labelIndex]->Size = System::Drawing::Size(60, 35);
				//位置をキーに合わせる
				labels[labelIndex]->Location = Point((i * 80) + 20, 20);
				//ラベルにその時のキーを書き込む
				labels[labelIndex]->Text = path[i];
				//ラベルを四角で囲む形にする
				labels[labelIndex]->BorderStyle = BorderStyle::FixedSingle;
				//
				labels[labelIndex]->DoubleClick += gcnew EventHandler(this, &CellEditForm::Labels_DoubleClick);
				//ラベルの配列のインデックスを次へ
				labelIndex++;
			}
			//できたラベルの配列をフォームに追加する
			this->Controls->AddRange(labels);
		}

		//ラベルをクリアする関数
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

		/*
		関数名:CellEditForm_Load
		概要:このフォームを立ち上げる時に行う関数
		引数:イベントの引数
		返却値:無し
		作成日:9月29日(金)
		作成者:成田修之
		*/
		System::Void CellEditForm_Load(System::Object^  sender, System::EventArgs^  e) {
			
			//親セル群を取得
			std::vector<ChainData*> parent = cell->getParents();
			std::vector<std::string>parentKey(parent.size());
			for (int i = 0; i < parent.size(); i++) {
				parentKey[i] = parent[i]->key;
			}

			//渡されたセルの一番上からそのセルまでの親キー群配列を取得する
			array<String^>^ keyPath = constants.vectorToArray(parentKey);
			//親の階層のキーからキーの連鎖を表示
			createKeyLabels(keyPath);

			//テキストボックスにキーの値を入力
			textBoxKey->Text = gcnew String(cell->key.c_str());
			//渡されたセルがオブジェクト
			if (cell->isObject()) {
				//値についてのテキストボックスを非表示
				textBoxValue->Visible = false;
				//値についてのラベルを非表示
				labelValue->Visible = false;
			}
			//データなら
			else {
				//値についてのテキストボックスに値を格納
				textBoxValue->Text = gcnew String(cell->value.c_str());
			}
			//親がいないとき
			if (cell->getParents().size() < 1) {
				buttonParent->Visible = false;
			}
		}


		/*
		関数名:buttonOK_Click
		概要:OKボタンが押されたときのイベント
		引数:イベントの引数
		返却値:無し
		作成日:9月29日(金)
		作成者:成田修之
		*/
		System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
			//セルのキーにテキストボックスで入力された値を格納
			cell->key = constants.StrToc_str(textBoxKey->Text);
			//セルがオブジェクトでないなら
			if (!cell->isObject()) {
				//セルの値にテキストボックスに入力された値を格納する
				cell->value = constants.StrToc_str(textBoxValue->Text);
			}
			//セルに値がきちんと入力されていたら
			if ("" != cell->key || "" != cell->value) {
				//有効にする
				cell->valid = true;
			}

			//このフォームを閉じる
			this->Close();
		}

		/*
		関数名:ButtonFamily_Click
		概要:親子兄弟のいずれかのボタンが押されたときのイベント
		引数:イベントの引数
		返却値:無し
		作成日:9月29日(金)
		作成者:成田修之
		*/
		System::Void ButtonFamily_Click(System::Object^  sender, System::EventArgs^  e) {
			//フォームのインスタンスを生成
			CellEditForm^ subForm = gcnew CellEditForm();

			//送られてきたボタンを取得
			Button^ send = (Button^)sender;
			//親ボタンからであるとき
			if ("buttonParent" == send->Name) {
				//親を作成して渡す
				subForm->cell = cell->createParent();
				//親ボタンからであることを示す値を渡す
				subForm->FormFrom = constants.FROM_PARENT_BUTTON;
			}
			//子ボタンからの時
			else if ("buttonChild" == send->Name) {
				//子を作成して渡す
				subForm->cell = cell->createChild();
				//子ボタンからであることを示す値を渡す
				subForm->FormFrom = constants.FROM_CHILD_BUTTON;
			}
			//兄ボタンからの時
			else if ("buttonBigBro" == send->Name) {
				//兄を作成して渡す
				subForm->cell = cell->insert(ChainData::FrontBack::Front);
				//兄ボタンからであることを示す値を渡す
				subForm->FormFrom = constants.FROM_BIGBRO_BUTTON;
			}
			//弟ボタンからの時
			else {
				//弟を作成して渡す
				subForm->cell = cell->insert(ChainData::FrontBack::Back);
				//弟ボタンからであることを示す値を渡す
				subForm->FormFrom = constants.FROM_BRO_BUTTON;
			}
			//フォームを表示する
			Windows::Forms::DialogResult rb = subForm->ShowDialog();

			//結果がOKできちんと親子兄弟が作れたなら
			if (Windows::Forms::DialogResult::OK == rb) {
				//そのセルを有効にする
				cell->valid = true;
			}
		}



		/*
		関数名:parentCancel
		概要:親を作成するのをやめる関数
		引数:なし
		返却値:なし
		作成日:9月29日(金)
		作成者:成田修之
		*/
		void parentCancel() {
			//子を取得する(親ボタンでフォームを呼び出す前に編集していたセル)
			ChainData* child = cell->right;
			//作成しようとしていた親が長男のセルの時
			if (nullptr == cell->upper) {
				//親を取得
				ChainData* parent = cell->left;
				//子が親の子になるようにする
				parent->addRight(child);
			}
			//作成しようとしていた親が長男ではない
			else {
				//兄を取得
				ChainData* bro = cell->left;
				//子が兄の弟になるようにする
				bro->addUnder(child);
				//子の作成しようとしていた親を指すポインタをナルにする
				child->left = nullptr;
			}
			//下の弟のセルがある
			if (nullptr != cell->under) {
				//下のセルを取得する
				ChainData* under = cell->under;
				//子の下にそれを格納する
				child->addUnder(under);
			}
			//デストラクタで削除されてしまうので子と弟へのポインタをナルを指すようにしてから削除
			cell->right = nullptr;
			cell->under = nullptr;

			//自身を削除
			delete cell;
			//フォームを閉じる
			this->Close();
		}

		/*
		関数名:childCancel
		概要:子を作成するのをやめる
		引数:なし
		返却値:なし
		作成日:9月29日(金)
		作成者:成田修之
		*/
		void childCancel() {
			//作成しようとしていた子の親を取得する
			ChainData* parent = cell->left;
			//作成しようとしていた子に子があるとき
			if (nullptr != cell->right) {
				//子を取得して
				ChainData* child = cell->right;
				//親の子として格納
				parent->addRight(child);
			}
			//子がないとき
			else {
				//親の子へのポインタをナルに
				parent->right = nullptr;
			}
			//デストラクタで削除されてしまうので子へのポインタをナルを指すようにしてから削除
			cell->right = nullptr;

			//自身を削除する
			delete cell;
		}


		/*
		関数名:buttonCancel_Click
		概要:キャンセルボタンがクリックされたときのイベント
		引数:イベントの引数
		返却値:無し
		作成日:9月29日(金)
		作成者:成田修之
		*/
		System::Void buttonCancel_Click(System::Object^  sender, System::EventArgs^  e) {
			//親ボタンから呼ばれたフォームなら
			if (FormFrom == constants.FROM_PARENT_BUTTON) {
				//親の作成をキャンセルする関数を行う
				parentCancel();
			}
			//子から呼ばれたフォームなら
			else if (FormFrom == constants.FROM_CHILD_BUTTON) {
				//子の作成をキャンセルする関数を行う
				childCancel();
			}
			//兄弟どちらかのとき
			else if (FormFrom == constants.FROM_BIGBRO_BUTTON || FormFrom == constants.FROM_BRO_BUTTON) {
				//そのセルを削除する
				this->cell->remove();
			}
			//フォームを閉じる
			this->Close();
		}

		/*
		関数名:Labels_DoubleClick
		概要:ラベル群のいずれかがクリックされたときのイベント
		引数:イベントの引数
		返却値:無し
		作成日:10月2日
		作成者:成田修之
		*/
		System::Void Labels_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			//クリックされたラベルを取得
			Label^ selectedLabel = (Label^)sender;
			//そのラベルの座標から選択されたセルが何番目かを取得
			int select = ((selectedLabel->Location.X - 20) / 80);
			//親のキー群を取得する
			std::vector<ChainData*> parents = cell->getParents();
			//詳細フォームのインスタンスを生成する
			CellEditForm^ editForm = gcnew CellEditForm();
			//フォームに選択されたセルを渡す
			editForm->cell = parents[select];
			//フォームを表示
			editForm->ShowDialog();
		}
	};
}

