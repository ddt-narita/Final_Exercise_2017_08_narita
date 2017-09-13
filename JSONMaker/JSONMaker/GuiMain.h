#pragma once
#include "GridJSONCreator.h"
#include "GridInfo.h"
#include "GridRowInfo.h"
#include "Constants.h"
#include "EnvForm.h"
#include "JsonLoader.h"
#include "DataGridSelfMade.h"
#include <windows.h>

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
	private: System::Windows::Forms::TableLayoutPanel^  PanelRowButton;










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
			this->PanelRowButton = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->buttonJsonCreate = (gcnew System::Windows::Forms::Button());
			this->GridRowLabel = (gcnew System::Windows::Forms::Label());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->textBoxColN = (gcnew System::Windows::Forms::TextBox());
			this->textBoxRowN = (gcnew System::Windows::Forms::TextBox());
			this->GridColLabel = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->buttonEnv = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->GridtabPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->GridtabPage);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(0, 23);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(648, 441);
			this->tabControl1->TabIndex = 0;
			// 
			// GridtabPage
			// 
			this->GridtabPage->AutoScroll = true;
			this->GridtabPage->Controls->Add(this->PanelRowButton);
			this->GridtabPage->Controls->Add(this->pictureBox1);
			this->GridtabPage->Controls->Add(this->buttonJsonCreate);
			this->GridtabPage->Controls->Add(this->GridRowLabel);
			this->GridtabPage->Controls->Add(this->buttonCancel);
			this->GridtabPage->Controls->Add(this->buttonOK);
			this->GridtabPage->Controls->Add(this->textBoxColN);
			this->GridtabPage->Controls->Add(this->textBoxRowN);
			this->GridtabPage->Controls->Add(this->GridColLabel);
			this->GridtabPage->Location = System::Drawing::Point(4, 22);
			this->GridtabPage->Name = L"GridtabPage";
			this->GridtabPage->Padding = System::Windows::Forms::Padding(3);
			this->GridtabPage->Size = System::Drawing::Size(640, 415);
			this->GridtabPage->TabIndex = 0;
			this->GridtabPage->Text = L"Grid";
			this->GridtabPage->UseVisualStyleBackColor = true;
			this->GridtabPage->Click += gcnew System::EventHandler(this, &GuiMain::GridtabPage_Click);
			// 
			// PanelRowButton
			// 
			this->PanelRowButton->AutoSize = true;
			this->PanelRowButton->ColumnCount = 1;
			this->PanelRowButton->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->PanelRowButton->Location = System::Drawing::Point(15, 102);
			this->PanelRowButton->Name = L"PanelRowButton";
			this->PanelRowButton->RowCount = 2;
			this->PanelRowButton->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->PanelRowButton->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->PanelRowButton->Size = System::Drawing::Size(10, 10);
			this->PanelRowButton->TabIndex = 9;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(52, 102);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(10, 10);
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &GuiMain::pictureBox1_Click);
			this->pictureBox1->DoubleClick += gcnew System::EventHandler(this, &GuiMain::pictureBox1_DoubleClick);
			// 
			// buttonJsonCreate
			// 
			this->buttonJsonCreate->Location = System::Drawing::Point(335, 38);
			this->buttonJsonCreate->Name = L"buttonJsonCreate";
			this->buttonJsonCreate->Size = System::Drawing::Size(75, 23);
			this->buttonJsonCreate->TabIndex = 7;
			this->buttonJsonCreate->Text = L"作成";
			this->buttonJsonCreate->UseVisualStyleBackColor = true;
			this->buttonJsonCreate->Click += gcnew System::EventHandler(this, &GuiMain::buttonJsonCreate_Click);
			// 
			// GridRowLabel
			// 
			this->GridRowLabel->AutoSize = true;
			this->GridRowLabel->Location = System::Drawing::Point(30, 22);
			this->GridRowLabel->Name = L"GridRowLabel";
			this->GridRowLabel->Size = System::Drawing::Size(22, 12);
			this->GridRowLabel->TabIndex = 0;
			this->GridRowLabel->Text = L"タテ";
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(547, 46);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 5;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &GuiMain::buttonCancel_Click);
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(547, 22);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 23);
			this->buttonOK->TabIndex = 4;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &GuiMain::buttonOK_Click);
			// 
			// textBoxColN
			// 
			this->textBoxColN->Location = System::Drawing::Point(81, 46);
			this->textBoxColN->Name = L"textBoxColN";
			this->textBoxColN->Size = System::Drawing::Size(100, 19);
			this->textBoxColN->TabIndex = 3;
			// 
			// textBoxRowN
			// 
			this->textBoxRowN->Location = System::Drawing::Point(81, 19);
			this->textBoxRowN->Name = L"textBoxRowN";
			this->textBoxRowN->Size = System::Drawing::Size(100, 19);
			this->textBoxRowN->TabIndex = 2;
			// 
			// GridColLabel
			// 
			this->GridColLabel->AutoSize = true;
			this->GridColLabel->Location = System::Drawing::Point(30, 49);
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
			this->tabPage2->Size = System::Drawing::Size(640, 415);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"List";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// buttonEnv
			// 
			this->buttonEnv->Font = (gcnew System::Drawing::Font(L"ＭＳ Ｐゴシック", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->buttonEnv->Location = System::Drawing::Point(551, 12);
			this->buttonEnv->Name = L"buttonEnv";
			this->buttonEnv->Size = System::Drawing::Size(75, 23);
			this->buttonEnv->TabIndex = 1;
			this->buttonEnv->Text = L"基本";
			this->buttonEnv->UseVisualStyleBackColor = true;
			this->buttonEnv->Click += gcnew System::EventHandler(this, &GuiMain::buttonEnv_Click);
			// 
			// GuiMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(648, 464);
			this->Controls->Add(this->buttonEnv);
			this->Controls->Add(this->tabControl1);
			this->Name = L"GuiMain";
			this->Text = L"GuiMain";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &GuiMain::GuiMain_FormClosed);
			this->Load += gcnew System::EventHandler(this, &GuiMain::GuiMain_Load);
			this->tabControl1->ResumeLayout(false);
			this->GridtabPage->ResumeLayout(false);
			this->GridtabPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		JsonLoader* jsonLoader;
		GridJSONCreator* gridJsonCreator;
		narita::DataGridSelfMade^ dataGridJson;

		//utf8をSJISに変換する関数
		//ファイルの文字コードがutf8であり、フォームで使う文字列がSJISのため
		std::string UTF8toSjis(std::string srcUTF8) {
			//Unicodeへ変換後の文字列長を得る
			int lenghtUnicode = MultiByteToWideChar(CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, NULL, 0);
			//必要な分だけUnicode文字列のバッファを確保
			wchar_t* bufUnicode = new wchar_t[lenghtUnicode];
			//UTF8からUnicodeへ変換
			MultiByteToWideChar(CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, bufUnicode, lenghtUnicode);
			//ShiftJISへ変換後の文字列長を得る
			int lengthSJis = WideCharToMultiByte(CP_THREAD_ACP, 0, bufUnicode, -1, NULL, 0, NULL, NULL);
			//必要な分だけShiftJIS文字列のバッファを確保
			char* bufShiftJis = new char[lengthSJis];
			//UnicodeからShiftJISへ変換
			WideCharToMultiByte(CP_THREAD_ACP, 0, bufUnicode, lenghtUnicode + 1, bufShiftJis, lengthSJis, NULL, NULL);
			std::string strSJis(bufShiftJis);
			delete bufUnicode;
			delete bufShiftJis;
			return strSJis;
		}

		//SJISからutf8に変換する関数
		//フォームで使う文字列がSJISであり、JSONファイルの文字コードがutf8のため
		std::string SjistoUTF8(std::string srcSjis) {
			//Unicodeへ変換後の文字列長を得る
			int lenghtUnicode = MultiByteToWideChar(CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, NULL, 0);
			//必要な分だけUnicode文字列のバッファを確保
			wchar_t* bufUnicode = new wchar_t[lenghtUnicode];
			//ShiftJISからUnicodeへ変換
			MultiByteToWideChar(CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, bufUnicode, lenghtUnicode);
			//UTF8へ変換後の文字列長を得る
			int lengthUTF8 = WideCharToMultiByte(CP_UTF8, 0, bufUnicode, -1, NULL, 0, NULL, NULL);
			//必要な分だけUTF8文字列のバッファを確保
			char* bufUTF8 = new char[lengthUTF8];
			//UnicodeからUTF8へ変換
			WideCharToMultiByte(CP_UTF8, 0, bufUnicode, lenghtUnicode + 1, bufUTF8, lengthUTF8, NULL, NULL);
			std::string strUTF8(bufUTF8);
			delete bufUnicode;
			delete bufUTF8;
			return strUTF8;
		}

		//OKボタン押下時のイベント
	private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
		//レイアウトの作成をやめる（描画がおもいため）
		this->SuspendLayout();

		//JSON読み込みの時
		if (jsonLoader->jsonmanager->isJSONFilePathSet()) {
			//読み込み開始
			jsonLoader->run();
			//行数取得
			int rowN = jsonLoader->jsonmanager->getGridRowLength() + 1;
			//最大の列数取得
			int colN = jsonLoader->jsonmanager->getGridColLength();
			//表の大きさを取得した列数行数に
			dataGridJson->rowCount = rowN;
			//行のキー列分
			dataGridJson->colCount = colN;
			//列数分繰り返す
			for (int i = 0; i < rowN; i++) {
				//行数分繰り返す (行のキーを除く
				for (int j = 0; j < colN; j++) {
					//行と列からキーを作成
					String^ key = dataGridJson->CreateGridMapKey(i, j);
					//その位置に配置
					dataGridJson[key] = gcnew String(UTF8toSjis(jsonLoader->jsonmanager->getGrid(i, j)).c_str());
				}
			}
			//初期化できていない部分の初期化を行う
			gridJsonCreator->jsonmanager->adjustGridDataSize();
		}
		else {
			//入力されているタテの長さを取得
			int rowN = Convert::ToInt32(textBoxRowN->Text);
			//入力されているヨコの長さを取得
			int colN = Convert::ToInt32(textBoxColN->Text);

			if (gridJsonCreator->jsonmanager->getGridRowLength() == 0) {
				//初期化を行う
				gridJsonCreator->init(rowN, colN);
			}
			//最大の大きさとして格納
			gridJsonCreator->jsonmanager->setGridRowLen(rowN);
			gridJsonCreator->jsonmanager->setGridMaxColLen(colN);
			//入力されていない部分の初期化を行う
			gridJsonCreator->jsonmanager->adjustGridDataSize();

			//tablelayoutpanelの縦横の長さを取得した値に設定
			dataGridJson->rowCount = rowN;
			dataGridJson->colCount = colN;
		}
		//セルを表示
		dataGridJson->Paint();

		pictureBox1->Visible = true;
		//レイアウトの表示を開始する
		this->ResumeLayout(false);
		this->PerformLayout();
	}


			 //キャンセルボタンをクリックしたときのイベント
			 //表のコントロールをすべて削除
	private: System::Void buttonCancel_Click(System::Object^  sender, System::EventArgs^  e) {
		//描画処理を一旦停止
		this->SuspendLayout();
		//行数取得
		int rowcount = dataGridJson->rowCount;
		//行数分繰り返して全行削除
		for (int i = 0; i < rowcount; i++) {
			//dataGridJson[i.ToString()] = "s";
		}
		//行数列数を0にする
		dataGridJson->colCount = 0;
		dataGridJson->rowCount = 0;

		//描画処理をおこなう
		this->ResumeLayout(false);
		this->PerformLayout();
	}

			 //作成ボタン押下時のイベント
	private: System::Void buttonJsonCreate_Click(System::Object^  sender, System::EventArgs^  e) {
		//入力された表の大きさを取得する
		int rowN = gridJsonCreator->jsonmanager->getGridRowLength();
		int colN = gridJsonCreator->jsonmanager->getGridColLength();

		//表の行数分繰り返す
		for (int i = 0; i < rowN; i++) {
			//表の列数分繰り返す
			for (int j = 0; j < colN; j++) {
				//その位置に入力されているセルの値を取得する(cellsが+1は結合ボタンのため)
				String^ temp = (dataGridJson[dataGridJson->CreateGridMapKey(i, j)]);
				//ナルあれば空文字、そうでなければそのまま
				temp = temp == nullptr ? "" : temp;

				//String型からstring型へ変換する
				std::string str = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(temp).ToPointer();
				//変換したグリッドの値をセット
				gridJsonCreator->jsonmanager->setGrid(i, j, str);
			}
		}
		gridJsonCreator->jsonmanager->jsonClear();
		//セットされた値でJSONを作成する
		gridJsonCreator->job();
		//作成し終えたらメンバのJSONをクリアする
		gridJsonCreator->jsonmanager->jsonClear();
		MessageBox::Show("JSON作成完了！！", "通知");

	}

			 //環境ボタンが押されたときのイベント
	private: System::Void buttonEnv_Click(System::Object^  sender, System::EventArgs^  e) {
		//環境設定入力フォームのインスタンスを生成
		EnvForm^ envform = gcnew EnvForm();

		//現在の情報を渡す
		envform->JSONFilePath = gcnew String(jsonLoader->jsonmanager->getJsonFilePath().c_str());
		//envform->DBName		  = gcnew String(jsonLoader->getDBName().c_str());
		//envform->Query		  = gcnew String(jsonLoader->getQuery().c_str());
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
		jsonLoader->jsonmanager->setJsonFilePath(filepath);

	}

			 //立ち上がった時に行う関数
	private: System::Void GuiMain_Load(System::Object^  sender, System::EventArgs^  e) {
		//各種クラスのインスタンスの作成
		jsonLoader = new JsonLoader();
		gridJsonCreator = new GridJSONCreator;
		dataGridJson = gcnew narita::DataGridSelfMade(pictureBox1);

		//JSONManagerのインスタンスを共有する
		jsonLoader->jsonmanager = gridJsonCreator->jsonmanager = new JSONManager();
		//表のテキストボックスにダブルクリックイベントを登録
		dataGridJson->text->DoubleClick += gcnew EventHandler(this, &GuiMain::pictureBox1_DoubleClick);
		pictureBox1->Visible = false;
	}


			 //フォームが閉じるときの関数
	private: System::Void GuiMain_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {

		delete jsonLoader->jsonmanager;
		delete jsonLoader;
		delete gridJsonCreator;
	}

			 //ピクチャーボックスがクリックされたときのイベント
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		//行と列を取得
		int row = ((MouseEventArgs^)e)->Y / dataGridJson->cellHeight;
		int col = ((MouseEventArgs^)e)->X / dataGridJson->cellWidth;

		//その位置についてクリック処理
		dataGridJson->cell_click(row, col);
	}

			 //ダブルクリックされたときのイベント
			 //セルの情報を表示する
	private: System::Void pictureBox1_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
		int nowX = GridtabPage->AutoScrollPosition.X;
		int nowY = GridtabPage->AutoScrollPosition.Y;

		int row;
		int col;

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

		//セルの情報取得
		std::vector<std::string>cellData(gridJsonCreator->jsonmanager->getGridData(row, col));
		//セルの情報として
		array<String^>^ cellinfo_CLI = gcnew array<String^>(cellData.size());
		//セルの情報の数だけ繰り返す(2回)
		for (int i = 0; i < cellData.size(); i++) {
			cellinfo_CLI[i] = gcnew String(cellData[i].c_str());
		}

		//セルの情報を入力するフォームのインスタンスを生成
		GridInfo^ gridinfo = gcnew GridInfo();
		//各情報を渡す
		gridinfo->gridInfo = cellinfo_CLI;
		gridinfo->rowN = row + 1;
		gridinfo->colN = col + 1;
		//セルの情報をモーダル表示
		gridinfo->ShowDialog();

		cellinfo_CLI = gridinfo->gridInfo;
		cellData = std::vector<std::string>(gridinfo->gridInfo->Length);
		//コンテントキーと親のキーのみ取得
		for (int i = 0; i < gridinfo->gridInfo->Length; i++) {
			//文字列への変換
			cellData[i] = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(cellinfo_CLI[i]).ToPointer();
		}

		//入力されたデータをグリッド管理クラスにセット
		gridJsonCreator->jsonmanager->setGridData(row, col, cellData);

		GridtabPage->AutoScrollPosition = Point(nowX, -nowY);
	}

			 //セル以外の部分をクリックした際のイベント
	private: System::Void GridtabPage_Click(System::Object^  sender, System::EventArgs^  e) {
		//カレントのセルを表示しない部分にする
		dataGridJson->drawCell(dataGridJson->currentCell, Brushes::White);
		dataGridJson->currentCell->col = -1;
		dataGridJson->currentCell->row = -1;
		//表示されているところ以外がクリックされたことにして
		dataGridJson->cell_click(dataGridJson->currentCell->row, dataGridJson->currentCell->col);
		pictureBox1->Invalidate();
	}

	};
};