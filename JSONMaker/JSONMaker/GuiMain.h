#pragma once
#include "GridJSONCreator.h"
#include "JSONDBManager.h"
#include "Constants.h"
#include "EnvForm.h"
#include "JsonLoader.h"
#include "DataGridSelfMade.h"
#include "NodeSelectForm.h"
#include "JSONManager.h"
#include "CellEditForm.h"
#include "ChainData.h"
#include <windows.h>
#include <boost/foreach.hpp>
#include "CLIConstants.h"

namespace JSONMaker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// GuiMain の概要
	/// </summary>
	public ref class GuiMain : public System::Windows::Forms::Form
	{
	public:
		GuiMain(void)
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
		~GuiMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  GridtabPage;
	protected:

	private: System::Windows::Forms::TabPage^  tabPage2;


	private: System::Windows::Forms::Button^  buttonCancel;

	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::TextBox^  textBoxColN;


	private: System::Windows::Forms::TextBox^  textBoxRowN;

	private: System::Windows::Forms::Label^  GridColLabel;
	private: System::Windows::Forms::Label^  GridRowLabel;
	private: System::Windows::Forms::Button^  buttonJsonCreate;
	private: System::Windows::Forms::Button^  buttonEnv;
	private: System::Windows::Forms::PictureBox^  pictureBox1;


	private: System::Windows::Forms::TextBox^  textBoxNodeName;
	private: System::Windows::Forms::Label^  labelNodeName;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  buttonColRemove;

	private: System::Windows::Forms::Button^  buttonColInsert;

	private: System::Windows::Forms::Button^  buttonRowRemove;

	private: System::Windows::Forms::Button^  buttonRowInsert;

	private: System::Windows::Forms::Button^  buttonRemove;
	private: System::Windows::Forms::Button^  buttonInsert;

	private: System::Windows::Forms::Button^  buttonOpen;

	private: System::Windows::Forms::Button^  buttonDetail;
	private: System::Windows::Forms::Label^  labelInsertFrontBack;
	private: System::Windows::Forms::Button^  buttonChangeFrontBack;
	private: System::Windows::Forms::Panel^  panel2;




















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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->GridtabPage = (gcnew System::Windows::Forms::TabPage());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->buttonEnv = (gcnew System::Windows::Forms::Button());
			this->labelInsertFrontBack = (gcnew System::Windows::Forms::Label());
			this->buttonJsonCreate = (gcnew System::Windows::Forms::Button());
			this->buttonChangeFrontBack = (gcnew System::Windows::Forms::Button());
			this->buttonOpen = (gcnew System::Windows::Forms::Button());
			this->buttonDetail = (gcnew System::Windows::Forms::Button());
			this->buttonColRemove = (gcnew System::Windows::Forms::Button());
			this->buttonColInsert = (gcnew System::Windows::Forms::Button());
			this->buttonRowRemove = (gcnew System::Windows::Forms::Button());
			this->buttonRowInsert = (gcnew System::Windows::Forms::Button());
			this->buttonRemove = (gcnew System::Windows::Forms::Button());
			this->buttonInsert = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBoxNodeName = (gcnew System::Windows::Forms::TextBox());
			this->labelNodeName = (gcnew System::Windows::Forms::Label());
			this->GridRowLabel = (gcnew System::Windows::Forms::Label());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->textBoxColN = (gcnew System::Windows::Forms::TextBox());
			this->textBoxRowN = (gcnew System::Windows::Forms::TextBox());
			this->GridColLabel = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabControl1->SuspendLayout();
			this->GridtabPage->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->GridtabPage);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(685, 561);
			this->tabControl1->TabIndex = 0;
			// 
			// GridtabPage
			// 
			this->GridtabPage->Controls->Add(this->panel2);
			this->GridtabPage->Controls->Add(this->buttonEnv);
			this->GridtabPage->Controls->Add(this->labelInsertFrontBack);
			this->GridtabPage->Controls->Add(this->buttonJsonCreate);
			this->GridtabPage->Controls->Add(this->buttonChangeFrontBack);
			this->GridtabPage->Controls->Add(this->buttonOpen);
			this->GridtabPage->Controls->Add(this->buttonDetail);
			this->GridtabPage->Controls->Add(this->buttonColRemove);
			this->GridtabPage->Controls->Add(this->buttonColInsert);
			this->GridtabPage->Controls->Add(this->buttonRowRemove);
			this->GridtabPage->Controls->Add(this->buttonRowInsert);
			this->GridtabPage->Controls->Add(this->buttonRemove);
			this->GridtabPage->Controls->Add(this->buttonInsert);
			this->GridtabPage->Controls->Add(this->panel1);
			this->GridtabPage->Controls->Add(this->textBoxNodeName);
			this->GridtabPage->Controls->Add(this->labelNodeName);
			this->GridtabPage->Controls->Add(this->GridRowLabel);
			this->GridtabPage->Controls->Add(this->buttonCancel);
			this->GridtabPage->Controls->Add(this->buttonOK);
			this->GridtabPage->Controls->Add(this->textBoxColN);
			this->GridtabPage->Controls->Add(this->textBoxRowN);
			this->GridtabPage->Controls->Add(this->GridColLabel);
			this->GridtabPage->Location = System::Drawing::Point(4, 22);
			this->GridtabPage->Name = L"GridtabPage";
			this->GridtabPage->Padding = System::Windows::Forms::Padding(3);
			this->GridtabPage->Size = System::Drawing::Size(677, 535);
			this->GridtabPage->TabIndex = 0;
			this->GridtabPage->Text = L"Grid";
			this->GridtabPage->UseVisualStyleBackColor = true;
			this->GridtabPage->Click += gcnew System::EventHandler(this, &GuiMain::LostFocusFromGrid);
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Location = System::Drawing::Point(8, 87);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(661, 48);
			this->panel2->TabIndex = 24;
			// 
			// buttonEnv
			// 
			this->buttonEnv->Font = (gcnew System::Drawing::Font(L"ＭＳ Ｐゴシック", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->buttonEnv->Location = System::Drawing::Point(578, 6);
			this->buttonEnv->Name = L"buttonEnv";
			this->buttonEnv->Size = System::Drawing::Size(75, 23);
			this->buttonEnv->TabIndex = 1;
			this->buttonEnv->Text = L"基本";
			this->buttonEnv->UseVisualStyleBackColor = true;
			this->buttonEnv->Click += gcnew System::EventHandler(this, &GuiMain::buttonEnv_Click);
			// 
			// labelInsertFrontBack
			// 
			this->labelInsertFrontBack->AutoSize = true;
			this->labelInsertFrontBack->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->labelInsertFrontBack->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelInsertFrontBack->Location = System::Drawing::Point(470, 9);
			this->labelInsertFrontBack->Name = L"labelInsertFrontBack";
			this->labelInsertFrontBack->Size = System::Drawing::Size(36, 26);
			this->labelInsertFrontBack->TabIndex = 23;
			this->labelInsertFrontBack->Text = L"前";
			// 
			// buttonJsonCreate
			// 
			this->buttonJsonCreate->Location = System::Drawing::Point(410, 48);
			this->buttonJsonCreate->Name = L"buttonJsonCreate";
			this->buttonJsonCreate->Size = System::Drawing::Size(54, 33);
			this->buttonJsonCreate->TabIndex = 7;
			this->buttonJsonCreate->Text = L"作成";
			this->buttonJsonCreate->UseVisualStyleBackColor = true;
			this->buttonJsonCreate->Click += gcnew System::EventHandler(this, &GuiMain::buttonJsonCreate_Click);
			// 
			// buttonChangeFrontBack
			// 
			this->buttonChangeFrontBack->Location = System::Drawing::Point(411, 9);
			this->buttonChangeFrontBack->Name = L"buttonChangeFrontBack";
			this->buttonChangeFrontBack->Size = System::Drawing::Size(53, 33);
			this->buttonChangeFrontBack->TabIndex = 22;
			this->buttonChangeFrontBack->Text = L"挿入　前/後ろ";
			this->buttonChangeFrontBack->UseVisualStyleBackColor = true;
			this->buttonChangeFrontBack->Click += gcnew System::EventHandler(this, &GuiMain::buttonFrontBack_Click);
			// 
			// buttonOpen
			// 
			this->buttonOpen->Location = System::Drawing::Point(353, 48);
			this->buttonOpen->Name = L"buttonOpen";
			this->buttonOpen->Size = System::Drawing::Size(52, 33);
			this->buttonOpen->TabIndex = 21;
			this->buttonOpen->Text = L"展開";
			this->buttonOpen->UseVisualStyleBackColor = true;
			this->buttonOpen->Click += gcnew System::EventHandler(this, &GuiMain::OpenDialogButtons_Click);
			// 
			// buttonDetail
			// 
			this->buttonDetail->Location = System::Drawing::Point(353, 9);
			this->buttonDetail->Name = L"buttonDetail";
			this->buttonDetail->Size = System::Drawing::Size(52, 33);
			this->buttonDetail->TabIndex = 20;
			this->buttonDetail->Text = L"詳細";
			this->buttonDetail->UseVisualStyleBackColor = true;
			this->buttonDetail->Click += gcnew System::EventHandler(this, &GuiMain::OpenDialogButtons_Click);
			// 
			// buttonColRemove
			// 
			this->buttonColRemove->Location = System::Drawing::Point(293, 48);
			this->buttonColRemove->Name = L"buttonColRemove";
			this->buttonColRemove->Size = System::Drawing::Size(54, 33);
			this->buttonColRemove->TabIndex = 19;
			this->buttonColRemove->Text = L"列削除";
			this->buttonColRemove->UseVisualStyleBackColor = true;
			this->buttonColRemove->Click += gcnew System::EventHandler(this, &GuiMain::RemoveButtons_Click);
			// 
			// buttonColInsert
			// 
			this->buttonColInsert->Location = System::Drawing::Point(293, 9);
			this->buttonColInsert->Name = L"buttonColInsert";
			this->buttonColInsert->Size = System::Drawing::Size(54, 33);
			this->buttonColInsert->TabIndex = 18;
			this->buttonColInsert->Text = L"列挿入";
			this->buttonColInsert->UseVisualStyleBackColor = true;
			this->buttonColInsert->Click += gcnew System::EventHandler(this, &GuiMain::InsertButtons_Click);
			// 
			// buttonRowRemove
			// 
			this->buttonRowRemove->Location = System::Drawing::Point(233, 48);
			this->buttonRowRemove->Name = L"buttonRowRemove";
			this->buttonRowRemove->Size = System::Drawing::Size(54, 33);
			this->buttonRowRemove->TabIndex = 17;
			this->buttonRowRemove->Text = L"行削除";
			this->buttonRowRemove->UseVisualStyleBackColor = true;
			this->buttonRowRemove->Click += gcnew System::EventHandler(this, &GuiMain::RemoveButtons_Click);
			// 
			// buttonRowInsert
			// 
			this->buttonRowInsert->Location = System::Drawing::Point(233, 9);
			this->buttonRowInsert->Name = L"buttonRowInsert";
			this->buttonRowInsert->Size = System::Drawing::Size(54, 33);
			this->buttonRowInsert->TabIndex = 16;
			this->buttonRowInsert->Text = L"行挿入";
			this->buttonRowInsert->UseVisualStyleBackColor = true;
			this->buttonRowInsert->Click += gcnew System::EventHandler(this, &GuiMain::InsertButtons_Click);
			// 
			// buttonRemove
			// 
			this->buttonRemove->Location = System::Drawing::Point(173, 48);
			this->buttonRemove->Name = L"buttonRemove";
			this->buttonRemove->Size = System::Drawing::Size(54, 33);
			this->buttonRemove->TabIndex = 15;
			this->buttonRemove->Text = L"削除";
			this->buttonRemove->UseVisualStyleBackColor = true;
			this->buttonRemove->Click += gcnew System::EventHandler(this, &GuiMain::RemoveButtons_Click);
			// 
			// buttonInsert
			// 
			this->buttonInsert->Location = System::Drawing::Point(173, 9);
			this->buttonInsert->Name = L"buttonInsert";
			this->buttonInsert->Size = System::Drawing::Size(54, 33);
			this->buttonInsert->TabIndex = 14;
			this->buttonInsert->Text = L"挿入";
			this->buttonInsert->UseVisualStyleBackColor = true;
			this->buttonInsert->Click += gcnew System::EventHandler(this, &GuiMain::InsertButtons_Click);
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->AutoScroll = true;
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(8, 141);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(661, 388);
			this->panel1->TabIndex = 13;
			this->panel1->Click += gcnew System::EventHandler(this, &GuiMain::LostFocusFromGrid);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(15, 3, 3, 15);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(10, 10);
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &GuiMain::pictureBox1_Click);
			this->pictureBox1->DoubleClick += gcnew System::EventHandler(this, &GuiMain::pictureBox1_DoubleClick);
			// 
			// textBoxNodeName
			// 
			this->textBoxNodeName->Location = System::Drawing::Point(56, 62);
			this->textBoxNodeName->Name = L"textBoxNodeName";
			this->textBoxNodeName->Size = System::Drawing::Size(100, 19);
			this->textBoxNodeName->TabIndex = 12;
			this->textBoxNodeName->TextChanged += gcnew System::EventHandler(this, &GuiMain::textBoxNodeName_TextChanged);
			// 
			// labelNodeName
			// 
			this->labelNodeName->AutoSize = true;
			this->labelNodeName->Location = System::Drawing::Point(6, 65);
			this->labelNodeName->Name = L"labelNodeName";
			this->labelNodeName->Size = System::Drawing::Size(44, 12);
			this->labelNodeName->TabIndex = 11;
			this->labelNodeName->Text = L"ノード名";
			// 
			// GridRowLabel
			// 
			this->GridRowLabel->AutoSize = true;
			this->GridRowLabel->Location = System::Drawing::Point(28, 16);
			this->GridRowLabel->Name = L"GridRowLabel";
			this->GridRowLabel->Size = System::Drawing::Size(22, 12);
			this->GridRowLabel->TabIndex = 0;
			this->GridRowLabel->Text = L"タテ";
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(578, 59);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 5;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &GuiMain::buttonCancel_Click);
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(578, 36);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 23);
			this->buttonOK->TabIndex = 4;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &GuiMain::buttonOK_Click);
			// 
			// textBoxColN
			// 
			this->textBoxColN->Location = System::Drawing::Point(56, 38);
			this->textBoxColN->Name = L"textBoxColN";
			this->textBoxColN->Size = System::Drawing::Size(100, 19);
			this->textBoxColN->TabIndex = 3;
			// 
			// textBoxRowN
			// 
			this->textBoxRowN->Location = System::Drawing::Point(56, 13);
			this->textBoxRowN->Name = L"textBoxRowN";
			this->textBoxRowN->Size = System::Drawing::Size(100, 19);
			this->textBoxRowN->TabIndex = 2;
			// 
			// GridColLabel
			// 
			this->GridColLabel->AutoSize = true;
			this->GridColLabel->Location = System::Drawing::Point(29, 41);
			this->GridColLabel->Name = L"GridColLabel";
			this->GridColLabel->Size = System::Drawing::Size(21, 12);
			this->GridColLabel->TabIndex = 1;
			this->GridColLabel->Text = L"ヨコ";
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(677, 535);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"List";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// GuiMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(685, 561);
			this->Controls->Add(this->tabControl1);
			this->Name = L"GuiMain";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"GuiMain";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &GuiMain::GuiMain_FormClosed);
			this->Load += gcnew System::EventHandler(this, &GuiMain::GuiMain_Load);
			this->tabControl1->ResumeLayout(false);
			this->GridtabPage->ResumeLayout(false);
			this->GridtabPage->PerformLayout();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		JsonLoader* jsonLoader;						//JSON読み込みに関するクラス
		GridJSONCreator* gridJsonCreator;			//読みこんだり作成したセルからJSONを作成するクラス
		JSONDBManager* jsonDbLoader;				//DBの結果からセルに落とすクラス
		narita::DataGridSelfMade^ dataGridJson;		//表クラス
		JSONManager* jsonmanager;					//各クラスの共有オブジェクト
		int FormType = 0;							//サブフォームかどうかを表す値
		ChainData* cellChain;						//トップノードのセル
		ChainData::FrontBack _fb;					//挿入の方向を表す
		CLIConstants^ cliconstants;					//CLIでの定数クラス


		//前に挿入するか後ろに挿入するかを選択するメンバのプロパティー
		property ChainData::FrontBack frontBack {
			//ゲッター
			ChainData::FrontBack get() {
				//そのまま返す
				return _fb;
			}
			//セッター
			System::Void set(ChainData::FrontBack fb) {
				//引数の値をセットして
				_fb = fb;
				//それに該当する文字をラベルに表示する
				labelInsertFrontBack->Text = fb == ChainData::Front ? "前" : "後ろ";
			}
		}

		/*
		*/
		void cellReset() {
			delete cellChain;
			dataGridJson->cell = cellChain = new ChainData();
		}


		/*
		関数名:LoadJson
		概要:JSONを読み込む処理を行う関数
		引数:無し
		返却値:無し
		作成日:9月15日(金)
		作成者:成田修之
		*/
	private:
		Void LoadJson() {
			try {
				//読み込み開始
				jsonLoader->init();
				//読みこんだJSONから兄弟群を抜き出す
				array<String^>^ Nodes = constants.vectorToArray(jsonLoader->getNodes(jsonmanager->json));
				//ノードを選択するフォームのインスタンスを作成する
				NodeSelectForm^ nodeForm = gcnew NodeSelectForm();
				//ノード群をフォームに渡す
				nodeForm->Nodes = Nodes;
				//フォームをモーダル表示する
				Windows::Forms::DialogResult dr = nodeForm->ShowDialog();

				//フォームの結果がキャンセルをクリックされたなら
				if (Windows::Forms::DialogResult::Cancel == dr) {
					//処理をやめる
					return;
				}
				cellReset();
				//読み込みを開始する
				jsonLoader->job(constants.StrToc_str(nodeForm->selectedNode), cellChain);
				//フォームのノード名に選択されたノードを表示
				textBoxNodeName->Text = nodeForm->selectedNode;
				//描画処理を行う
				ViewTable();
				//描画を反映させる
				pictureBox1->Invalidate();
			}
			catch (std::exception& e) {
				MessageBox::Show(cliconstants->MESSAGE_FAILD_TO_READ_JSON, "エラー", MessageBoxButtons::OK, MessageBoxIcon::Hand);
			}
		}

		/*
		関数名:createGrid
		概要:テキストボックスに入力された値から表を作成
		引数:int rowN, int colN
		返却値:無し
		作成日:10月3日(火)
		作成者:成田修之
		*/
		System::Void createGrid(int rowN, int colN) {
			//現在のトップのセルに子を作成
			cellChain->addRight(new ChainData());
			//トップのセルの子を子カレントとする
			ChainData* childCurrent = cellChain->right;
			//タテ数分繰り返す
			for (int i = 0; i < rowN; i++) {
				//子カレントに子を作成
				childCurrent->addRight(new ChainData());
				//それを孫カレントとする
				ChainData* GchildCurrent = childCurrent->right;

				//ヨコ分繰り返す
				for (int j = 0; j < colN; j++) {
					//最後の列でなければ
					if (j < colN - 2) {
						//孫カレントに弟を作成
						GchildCurrent->addUnder(new ChainData());
						//孫カレントを弟に移動
						GchildCurrent = GchildCurrent->under;
					}
				}
				//最後の行でなければ
				if (i < rowN - 1) {
					//子カレントに弟を作成して
					childCurrent->addUnder(new ChainData());
					//子カレントをその弟に移動
					childCurrent = childCurrent->under;
				}
			}
		}


		/*
		関数名:printGrid
		概要:新規にJSONを作成するための処理を行う関数
		引数:無し
		返却値:無し
		作成日:9月15日(金)
		作成者:成田修之
		*/
	private:
		Void printGrid() {
			int rowN;
			int colN;
			try {
				//入力されているタテの長さを取得
				rowN = Convert::ToInt32(textBoxRowN->Text);
				//入力されているヨコの長さを取得
				colN = Convert::ToInt32(textBoxColN->Text);

				//入力されている値のどちらかが0なら
				if (rowN == 0 || colN == 0) {
					//例外を送出
					throw gcnew Exception();
				}
			}
			catch (Exception^) {
				MessageBox::Show(cliconstants->MESSAGE_INVALID_VALUE, "警告", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				throw gcnew Exception("タテヨコに無効な値が入力されています。");
			}
			//作成をすることをOKキャンセルで確認を取る
			Windows::Forms::DialogResult dr = MessageBox::Show(rowN.ToString() + "行" + colN.ToString() + "列で表を作成します\nよろしいですか", "", MessageBoxButtons::OKCancel, MessageBoxIcon::Question);
			//キャンセルが押されたら
			if (Windows::Forms::DialogResult::Cancel == dr) {
				//処理をやめる
				return;
			}
			cellReset();
			//取得した行と列で表を作成する
			createGrid(rowN, colN);
			//表を表示する
			ViewTable();
		}

		/*
		関数名:getJSONFromQuery
		概要:クエリの結果からJSONを作成する処理を行う関数
		引数:無し
		返却値:無し
		作成日:9月15日(金)
		作成者:成田修之
		*/

		   private:Void getJsonFromQuery(ChainData* cell) {
		   	//メッセージを作成
		   	String^ message = gcnew String(jsonmanager->env.DBname.c_str()) + cliconstants->MESSAGE_EXECUTE_QUERY_BEFORE + gcnew String(jsonmanager->env.Query.c_str()) + cliconstants->MESSAGE_EXECUTE_QUERY_BACK;
		   	//メッセージボックスで表示
		   	Windows::Forms::DialogResult dr = MessageBox::Show(message, "確認", MessageBoxButtons::OKCancel, MessageBoxIcon::Question);
		   	//キャンセルが選択されたら
		   	if(Windows::Forms::DialogResult::Cancel == dr) {
		   		//関数の実行をやめる
		   		return;
		   	}
		   	try {
				cellReset();
		   		//DBの結果読み込みを開始する
		   		jsonDbLoader->run(cell);
		   		//読みこんだセルで表を作成する
		   		ViewTable();
		   	}
		   	//例外が発生したとき
		   	catch (sql::SQLException& e) {
		   		//エラーがDB接続に関するものだった時
		   		if (e.getErrorCode() == constants.CODE_DB_ERROR) {
		   			//メッセージボックスで表示
		   			MessageBox::Show(cliconstants->MESSAGE_FAILED_TO_CONNECT_DB, "エラー", MessageBoxButtons::OK, MessageBoxIcon::Hand);
		   		
		   		}//MySQLへの接続に関するエラー
		   		else if(e.getErrorCode() == constants.CODE_MYSQL_ERROR) {
		   			//メッセージボックスで表示
		   			MessageBox::Show(cliconstants->MESSAGE_FAILED_TO_CONNECT_MySQL, "エラー", MessageBoxButtons::OK, MessageBoxIcon::Hand);					
		   		
		   		}//ログインに関するエラーの時
		   		else if(e.getErrorCode() == constants.CODE_ROGIN_ERROR) {
		   			//メッセージボックスで表示
		   			MessageBox::Show(cliconstants->MESSAGE_FAILED_TO_ROGIN, "エラー", MessageBoxButtons::OK, MessageBoxIcon::Hand);
		   		
		   		} //無効なクエリに関するエラー
		   		else if(e.getErrorCode() == constants.CODE_INVALID_QUERY_ERROR){
		   			//メッセージボックスで表示
		   			MessageBox::Show(cliconstants->MESSAGE_INVALID_QUERY, "エラー", MessageBoxButtons::OK, MessageBoxIcon::Hand);
		   		}
		   		//文法的に間違ったSQLのエラー
		   		else if (e.getErrorCode() == constants.CODE_QUERY_SYNTAX_ERROR) {
		   			//メッセージボックスで表示
		   			MessageBox::Show(cliconstants->MESSAGE_QUERY_SYNTAX_ERROR, "エラー", MessageBoxButtons::OK, MessageBoxIcon::Hand);
		   		}
		   	}
		   }


		   /*
		   関数名:buttonOK_Click
		   概要:OKボタンが押されたときのイベント
		   引数:イベントの引数
		   返却値:無し
		   作成日:9月15日(金)
		   作成者:成田修之
		   */
	private:
		System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
			//レイアウトの作成をやめる（描画がおもいため）
			this->SuspendLayout();
			//サブフォームなら
			if (FormType == constants.IS_SUB_FORM) {
				//フォームを閉じる
				this->Close();
				//処理をやめる
				return;
			}
			else {
				try {
					//JSON読み込みの時
					if (jsonmanager->isJSONFilePathSet()) {
						//JSON読み込み処理を実行する
						LoadJson();
					}
					else if (jsonDbLoader->isQuerySet()) {
						//
						getJsonFromQuery(cellChain);
					}
					else {
						//新規にJSONを作成するための表を表示する処理を実行
						printGrid();
					}
				}
				catch (Exception^ e) {
					System::Diagnostics::Debug::WriteLine("----Debug---");
					System::Diagnostics::Debug::WriteLine(e->Message);
					System::Diagnostics::Debug::WriteLine("------------");
					return;
				}
			}
			//レイアウトの表示を開始する
			this->ResumeLayout(false);
			this->PerformLayout();
		}


		/*
		関数名:buttonCancel_Click
		概要:キャンセルボタンがクリックされたときのイベント
		引数:イベントの引数
		返却値:無し
		作成日:9月15日(金)
		作成者:成田修之
		*/
	private:
		System::Void buttonCancel_Click(System::Object^  sender, System::EventArgs^  e) {
			//描画処理を一旦停止
			this->SuspendLayout();
			if (nullptr == cellChain->right) {
				MessageBox::Show(cliconstants->MESSAGE_HAVE_NOT_VIEW_TABLE_YET, "エラー", MessageBoxButtons::OK, MessageBoxIcon::Hand);
				return;
			}
			System::Windows::Forms::DialogResult result = MessageBox::Show(cliconstants->MESSAGE_ALL_CLEAR, "警告", MessageBoxButtons::OKCancel, MessageBoxIcon::Exclamation);
			if (result != System::Windows::Forms::DialogResult::OK) {
				return;
			}
			//ファイルパスをクリア
			jsonmanager->env.JSONFilePath = "";
			//クエリをクリア
			jsonmanager->env.Query = "";
			//テキストボックスをクリア
			textBoxNodeName->Text = "";
			textBoxColN->Text = "";
			textBoxRowN->Text = "";

			//表の値をクリア
			dataGridJson->Clear();

			//セルに親が存在しないときは
			if (cellChain->getParents().size() == 0) {
				//そのセルを削除して
				delete cellChain;
				//新たに作り直して表クラスにも渡す
				dataGridJson->cell = cellChain = new ChainData();
			}
			//セルに親がいるなら(サブフォームなら)
			else {
				//そのセルの削除関数を実行
				cellChain->remove();
			}
			//ピクチャーボックスを非表示にする
			pictureBox1->Visible = false;
			//描画処理をおこなう
			this->ResumeLayout(false);
			this->PerformLayout();
		}


		/*
		関数名:buttonJsonCreate_Click
		概要:作成ボタン押下時のイベント
		引数:イベントの引数
		返却値:なし
		作成日:10月3日(火)
		作成者:成田修之
		*/
	private:
		System::Void buttonJsonCreate_Click(System::Object^  sender, System::EventArgs^  e) {
			//子が存在しないとき(子が存在しないということはまだ読みこみも新規の行列指定もしていない)
			if (nullptr == cellChain->right) {
				//エラーメッセージをだす
				MessageBox::Show(cliconstants->MESSAGE_HAVE_NOT_VIEW_TABLE_YET, "エラー", MessageBoxButtons::OK, MessageBoxIcon::Hand);
				//処理をやめる
				return;
			}
			//ノード名が入力されていない
			if ("" == textBoxNodeName->Text) {
				//ノード名が空であることとこのまま続けるかを聞く
				MessageBox::Show(cliconstants->MESSAGE_EMPTY_NODE_NAME, "警告", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			try {
				//ノード名のテキストボックスに入力された値をキー名に
				cellChain->key = constants.StrToc_str(textBoxNodeName->Text);
				//セットされた値でJSONを作成する
				gridJsonCreator->job(cellChain);
			}
			//JSON作成で例外が発生したとき
			catch (std::exception& e) {
				//エラーメッセージを取得
				String^ errorMessage = gcnew String(e.what());
				//デバッグ出力する
				System::Diagnostics::Debug::WriteLine(errorMessage);
				//メッセージボックスでエラー内容を表示
				MessageBox::Show(cliconstants->MESSAGE_CREATE_JSON_ERROR + "\n" + gcnew String(e.what()), "エラー", MessageBoxButtons::OK, MessageBoxIcon::Hand);
				return;
			}
			//作成が完了したことを通知
			MessageBox::Show(cliconstants->MESSAGE_CREATED, "通知");
		}

		/*
		関数名:buttonEnv_Click
		概要:環境(基本)ボタンがクリックされたときのイベント
		引数:イベントの引数
		返却値:なし
		作成日:9月15日(金)
		作成者:成田修之
		*/
	private:
		System::Void buttonEnv_Click(System::Object^  sender, System::EventArgs^  e) {
			//環境設定入力フォームのインスタンスを生成
			EnvForm^ envform = gcnew EnvForm();
			//現在の情報を渡す
			envform->DBName = gcnew String(jsonmanager->env.DBname.c_str());
			envform->JSONFilePath = gcnew String(jsonmanager->getJsonFilePath().c_str());
			envform->Query = gcnew String(jsonmanager->getQuery().c_str());
			//モーダル表示する
			envform->ShowDialog();

			//ファイルパスを入力するための変数
			std::string filepath;
			//ナルでなければ
			if (envform->JSONFilePath != nullptr) {
				//取得
				filepath = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(envform->JSONFilePath).ToPointer();
			}
			//取得したパスをセットする
			jsonmanager->setJsonFilePath(filepath);
			//入力されたクエリを取得して
			std::string query = envform->Query == nullptr ? "" : constants.StrToc_str(envform->Query);
			//セット
			jsonmanager->setQuery(query);
			jsonmanager->env.DBname = constants.StrToc_str(envform->DBName == nullptr ? "" : envform->DBName);
		}
		/*
		関数名:createKeyLabels
		概要:キー配列からラベル群を作成する
		引数:array<String^>^ path　キー群
		返却値:無し
		作成日:10月2日(月)
		作成者:成田修之
		*/
		System::Void createKeyLabels(array<String^>^ path) {
			//ラベル配列の長さをハイフン分を含めてキーの数×２＋１にする
			array<Label^>^ labels = gcnew array<Label^>(path->Length * 2);
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
					labels[labelIndex]->Location = Point((i * 80) + 5, 5);
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
				labels[labelIndex]->Location = Point((i * 80) + 20, 5);
				//ラベルにその時のキーを書き込む
				labels[labelIndex]->Text = path[i];
				//ラベルを四角で囲む形にする
				labels[labelIndex]->BorderStyle = BorderStyle::FixedSingle;
				//
				labels[labelIndex]->DoubleClick += gcnew EventHandler(this, &GuiMain::Labels_DoubleClick);
				//ラベルの配列のインデックスを次へ
				labelIndex++;
			}
			//できたラベルの配列をフォームに追加する
			this->panel2->Controls->AddRange(labels);
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
			std::vector<ChainData*> parents = cellChain->getParents();
			//詳細フォームのインスタンスを生成する
			GuiMain^ editForm = gcnew GuiMain();
			//フォームに選択されたセルを渡す
			editForm->cellChain = parents[select];
			editForm->FormType = constants.IS_SUB_FORM;
			//環境ボタンをいじれないようにする
			editForm->buttonEnv->Visible = false;
			//フォームを表示
			editForm->ShowDialog();
			ClearLabels();
			createlabels();

		}
		//ラベルをクリアする関数
		System::Void ClearLabels() {
			int level = cellChain->getParents().size();
			//表示させるラベルの数だけ繰り返す
			for (int i = 0; i < level; i++) {
				//一番目だけでなければ
				if (i != 0) {
					//キー間のハイフンのラベルを削除
					this->panel2->Controls->Remove(this->GetChildAtPoint(Point((i * 80) + 5, 5)));
				}
				//キーのラベルを削除する
				this->panel2->Controls->Remove(this->GetChildAtPoint(Point((i * 80) + 20, 5)));
			}
		}

		void createlabels() {
			//親セル群を取得
			std::vector<ChainData*> parent = cellChain->getParents();
			std::vector<std::string>parentKey(parent.size());
			for (int i = 0; i < parent.size(); i++) {
				parentKey[i] = parent[i]->key;
			}

			//渡されたセルの一番上からそのセルまでの親キー群配列を取得する
			array<String^>^ keyPath = constants.vectorToArray(parentKey);
			//親の階層のキーからキーの連鎖を表示
			createKeyLabels(keyPath);
		}

		/*
		関数名:GuiMain_Load
		概要:このフォームが立ち上がった時に行うイベント
		引数:イベントの引数
		返却値:無し
		作成日:9月15日(金)
		作成者:成田修之
		*/
	private:
		System::Void GuiMain_Load(System::Object^  sender, System::EventArgs^  e) {
			//各種クラスのインスタンスの作成
			jsonLoader = new JsonLoader();
			gridJsonCreator = new GridJSONCreator();
			jsonDbLoader = new JSONDBManager();
			//共有オブジェクトを生成
			jsonmanager = new JSONManager();
			dataGridJson = gcnew narita::DataGridSelfMade(pictureBox1);
			cliconstants = gcnew CLIConstants();

			//共有オブジェクトを共有させる
			jsonLoader->jsonmanager = gridJsonCreator->jsonmanager = jsonDbLoader->jsonmanager =  jsonmanager;
			//表のテキストボックスにダブルクリックイベントを登録
			dataGridJson->text->DoubleClick += gcnew EventHandler(this, &GuiMain::pictureBox1_DoubleClick);
			//セルを表示する描画対象を見えなくする
			pictureBox1->Visible = false;
			//JSONがセットされてnullではないとき(サブフォームの時)
			if (nullptr != cellChain && cellChain->isValid()) {
				dataGridJson->cell = cellChain;
				//読みこんだデータで表を表示する
				ViewTable();
				//ピクチャーボックスが見えるようにする
				pictureBox1->Visible = true;
				//ノード名をテキストボックスに
				textBoxNodeName->Text = gcnew String(cellChain->key.c_str());
				createlabels();
			}
			//最初のフォーム立ち上げなら
			else {
				//メンバのセルを生成する
				cellChain = new ChainData();
				//そのセルを表クラスに渡す
				dataGridJson->cell = cellChain;
			}
		}

		/*
		関数名:GuiMain_FormClosed
		概要:フォームが閉じるときのイベント
		引数:イベントの引数
		返却値:無し
		作成日:9月15日(金)
		作成者:成田修之
		*/
	private:
		System::Void GuiMain_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			//共通オブジェクトを削除
			delete jsonmanager;
			//JSON読み込み処理クラスを削除する
			delete jsonLoader;
			//表からJSONを作成するクラスを削除
			delete gridJsonCreator;
			//delete jsonDBLoader;
		}

		//ピクチャーボックスがクリックされたときのイベント
		System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
			int row = ((MouseEventArgs^)e)->Y / dataGridJson->cellHeight;
			int col = ((MouseEventArgs^)e)->X / dataGridJson->cellWidth;
			//その位置についてクリック処理
			dataGridJson->cell_click(row, col);
		}

		/*
		関数名:picture_Box1_DoubleClick
		概要:セルがダブルクリックされたときのイベント
		　　 セルの情報を表示する
		引数:イベントの引数
		返却値:無し
		作成日:9月15日(金)
		作成者:成田修之
		*/
		System::Void pictureBox1_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			int nowX = panel1->AutoScrollPosition.X;
			int nowY = panel1->AutoScrollPosition.Y;

			int row;
			int col;
			//選択されたセルを格納する
			ChainData* selected;

			//テキストボックスから呼ばれたとき
			if (sender->GetType() == TextBox::typeid) {
				//位置取得のために型変換
				TextBox^ senderBox = (TextBox^)sender;
				//行と列を取得
				row = senderBox->Location.Y / dataGridJson->cellHeight;
				col = senderBox->Location.X / dataGridJson->cellWidth;
			}
			//ピクチャーボックスから呼ばれたとき
			else {
				//列と行を取得
				row = ((MouseEventArgs^)e)->Y / dataGridJson->cellHeight;
				col = ((MouseEventArgs^)e)->X / dataGridJson->cellWidth;
			}

			//一列目のセルがクリックされたときのイベント
			if (cellChain->getCell(row, col)->isObject()) {
				//一列目のセルを取得
				selected = cellChain->getCell(row, col);
				//そのセルについて展開する
				OpenCell(selected);
			}
			//1行目以外のセルがクリックされたときのイベント
			else {
				//選択されたセルを取得
				selected = cellChain->getCell(row, col);
				//詳細を開く
				OpenDetail(selected);
			}
			//全体を描画する
			ViewTable();
			//表の表示を促す
			pictureBox1->Invalidate();
			//スクロールのポジションをフォーム表示前と同じにする
			panel1->AutoScrollPosition = Point(-nowX, -nowY);
		}

		/*
		関数名:GridTabPage_Click
		概要:セル以外の部分をクリックしたときの動作
		引数:イベントの引数
		返却値:無し
		作成日:9月28日(木)
		作成者:成田修之
		*/
		System::Void LostFocusFromGrid(System::Object^  sender, System::EventArgs^  e) {
			//カレントのセルを表示しない部分にする
			dataGridJson->cell_click(-1, -1);
			pictureBox1->Invalidate();
		}

		/*
		関数名:OpenCell
		概要:選択されたセルについて展開する関数
		引数:ChainData* cell 選択されたセル
		返却値:無し
		作成日:9月29日(金)
		作成者:成田修之
		*/
		System::Void OpenCell(ChainData* cell) {
			//サブ画面のインスタンスを生成
			GuiMain^ sub = gcnew GuiMain();
			//引数のセルを渡す
			sub->cellChain = cell;
			//環境ボタンをいじれないようにする
			sub->buttonEnv->Visible = false;
			//サブフォームであることを格納
			sub->FormType = constants.IS_SUB_FORM;
			//サブフォームを表示する
			sub->ShowDialog();
			//全体を描画する
			ViewTable();
		}

		/*
		関数名:OpenDetail
		概要:引数のセルについて詳細ダイアログを表示する関数
		引数:ChainData* selectedCell　選択されたセル
		返却値:無し
		作成日:9月29日(金)
		作成者:成田修之
		*/
		System::Void OpenDetail(ChainData* selectedCell) {
			//セル編集フォームのインスタンスを生成
			CellEditForm^ editForm = gcnew CellEditForm();
			//フォームに選択されたセルを渡す
			editForm->cell = selectedCell;
			//フォームを表示する
			editForm->ShowDialog();
			//全体を再描画
			ViewTable();
		}

		/*
		関数名:InsertButtons_Click
		概要:挿入に関するボタンが押下されたときのイベント
		引数:イベントの引数
		返却値:無し
		作成日:9月29日(金)
		作成者:成田修之
		*/
		System::Void InsertButtons_Click(System::Object^  sender, System::EventArgs^  e) {
			//挿入に関係したボタンを取得
			Button^ InsertButton = (Button^)sender;
			//選択中のセルが有効な値の時
			if (dataGridJson->currentCell->isExist()) {
				//選択されているセルの行を取得する
				int row = dataGridJson->currentCell->row;
				//選択されているセルの列を取得する
				int col = dataGridJson->currentCell->col;
				//挿入ボタンからの時
				if ("buttonInsert" == InsertButton->Name) {
					//選択されているセルを取得する
					ChainData* selected = cellChain->getCell(row, col);
					//選択されているセルについて前か後かの値を渡して挿入処理を行う
					selected->insert(frontBack);
				}
				//行削除ボタンからの時
				else if ("buttonRowInsert" == InsertButton->Name) {
					//行挿入処理を行う
					cellChain->insertRow(row, frontBack);
				}
				//列削除ボタンからの時
				else if ("buttonColInsert" == InsertButton->Name) {
					//列挿入処理を行う
					cellChain->insertCol(col, frontBack);
				}
				//全体を再描画する
				ViewTable();
			}
			//セルが選択されていないとき
			else {
				//メッセージでそのことを警告
				MessageBox::Show(cliconstants->MESSAGE_NOT_SELECTED_CELL, "エラー", MessageBoxButtons::OK, MessageBoxIcon::Hand);
			}
		}

		/*
		関数名:RemoveButtons_Click
		概要:削除にかかわるボタンがクリックされたとき
		引数:イベントの引数
		返却値:無し
		作成日:9月29日(金)
		作成者:成田修之
		*/
		System::Void RemoveButtons_Click(System::Object^  sender, System::EventArgs^  e) {
			//削除に関係したボタンを取得
			Button^ RemoveButton = (Button^)sender;

			//選択中のセルが有効な値の時
			if (dataGridJson->currentCell->isExist()) {
				//選択されているセルの行を取得する
				int row = dataGridJson->currentCell->row;
				//選択されているセルの列を取得する
				int col = dataGridJson->currentCell->col;

				//削除ボタンからの時
				if ("buttonRemove" == RemoveButton->Name) {
					//選択されているセルを取得する
					ChainData* selectedCell = cellChain->getCell(row, col);
					//削除処理を行う
					selectedCell->remove();
				}
				//行削除ボタンからの時
				else if ("buttonRowRemove" == RemoveButton->Name) {
					//行削除処理を行う
					cellChain->removeRow(row);
				}
				//列削除ボタンからの時
				else if ("buttonColRemove" == RemoveButton->Name) {
					//列削除処理を行う
					cellChain->removeCol(col);
				}
				else if ("buttonParentRemove" == RemoveButton->Name) {
					ChainData* select = cellChain->getCell(row, col);
					select->removeParent();
				}

				//削除したので選択中のセルについてリセット
				dataGridJson->currentCell->Reset();
				//全体を再描画する
				ViewTable();
			}
			//セルが選択されていないとき
			else {
				//メッセージでそのことを警告
				MessageBox::Show(cliconstants->MESSAGE_NOT_SELECTED_CELL, "エラー", MessageBoxButtons::OK, MessageBoxIcon::Hand);
			}
		}

		/*
		関数名:OpenDialogButtons_Click
		概要:ダイアログ表示に関わるボタンが押下されたときのイベント
		引数:イベントの引数
		返却値:無し
		作成日:9月29日(金)
		作成者:成田修之
		*/
		System::Void OpenDialogButtons_Click(System::Object^  sender, System::EventArgs^  e) {
			//削除に関係したボタンを取得
			Button^ OpenDialogButtons = (Button^)sender;
			//選択中のセルが有効な値の時
			if (dataGridJson->currentCell->isExist()) {
				//選択されているセルの行を取得する
				int row = dataGridJson->currentCell->row;
				//選択されているセルの列を取得する
				int col = dataGridJson->currentCell->col;

				ChainData* selectedCell = cellChain->getCell(row, col);
				//展開ボタンからの時
				if ("buttonOpen" == OpenDialogButtons->Name) {
					//選択されたセルがオブジェクトなら
					if (selectedCell->isObject()) {
						//展開処理を行う
						OpenCell(selectedCell);
					}
				}
				//詳細ボタンからの時
				else if ("buttonDetail" == OpenDialogButtons->Name) {
					//詳細フォーム表示処理を行う
					OpenDetail(selectedCell);
				}
				//全体を再描画する
				ViewTable();
			}
			//セルが選択されていないとき
			else {
				//メッセージでそのことを警告
				MessageBox::Show(cliconstants->MESSAGE_NOT_SELECTED_CELL, "エラー", MessageBoxButtons::OK, MessageBoxIcon::Hand);
			}
		}

		/*
		関数名:ViewTable
		概要:表を表示する関数
		引数:無し
		返却値:無し
		作成日:9月29日(金)
		作成者:成田修之
		*/
		System::Void ViewTable() {
			//表クラスの表示関数を実行
			dataGridJson->View();
			//その表に合わせた行数をテキストボックスに表示
			textBoxRowN->Text = dataGridJson->rowCount.ToString();
			//列数をテキストボックスに表示
			textBoxColN->Text = dataGridJson->colCount.ToString();
			//一番トップのノードのキーをテキストボックスに入力する
			textBoxNodeName->Text = gcnew String(cellChain->key.c_str());
			//行か列のどちらかが0の時
			if (dataGridJson->rowCount == 0 || dataGridJson->colCount == 0) {
				//表示するピクチャーボックスを非表示に
				pictureBox1->Visible = false;
			}
			//行と列があるなら
			else {
				//ピクチャーボックスを表示する
				pictureBox1->Visible = true;
			}
		}

		/*
		関数名:buttonFrontBack_Click
		概要:前後ろボタンがクリックされたとき、挿入の前後ろを変更する
		引数:イベントの引数
		返却値:無し
		作成日:10月2日(月)
		作成者:成田修之
		*/
		System::Void buttonFrontBack_Click(System::Object^  sender, System::EventArgs^  e) {
			//いままでが前なら後ろに、後ろだったなら前に変える
			frontBack = (ChainData::Front == frontBack ? ChainData::Back : ChainData::Front);
		}

		/*
		関数名:textBoxNodename_TextChanged
		概要:ノード名を入力するテキストボックスの値が変化したときトップのセルのキーにその値を入力する
		引数:イベントの引数
		返却値:無し
		作成日:10月3日(火)
		作成者:成田修之
		*/
		System::Void textBoxNodeName_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			//トップのセルのキーに代入する
			cellChain->key = constants.StrToc_str(textBoxNodeName->Text);
		}
};
};