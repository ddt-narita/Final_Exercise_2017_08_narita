#pragma once
#include "GridJSONCreator.h"
#include "JSONDBManager.h"
#include "Constants.h"
#include "EnvForm.h"
#include "CellEditForm.h"
#include "JsonLoader.h"
#include "DataGridSelfMade.h"
#include "NodeSelectForm.h"
#include <windows.h>
#include "JSONManager.h"

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

	private: System::Windows::Forms::Button^  buttonBindRelease;
	private: System::Windows::Forms::TextBox^  textBoxNodeName;
	private: System::Windows::Forms::Label^  labelNodeName;
	private: System::Windows::Forms::Panel^  panel1;










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
			this->textBoxNodeName = (gcnew System::Windows::Forms::TextBox());
			this->labelNodeName = (gcnew System::Windows::Forms::Label());
			this->buttonBindRelease = (gcnew System::Windows::Forms::Button());
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tabControl1->SuspendLayout();
			this->GridtabPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
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
			this->GridtabPage->Controls->Add(this->panel1);
			this->GridtabPage->Controls->Add(this->textBoxNodeName);
			this->GridtabPage->Controls->Add(this->labelNodeName);
			this->GridtabPage->Controls->Add(this->buttonBindRelease);
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
			// textBoxNodeName
			// 
			this->textBoxNodeName->Location = System::Drawing::Point(81, 62);
			this->textBoxNodeName->Name = L"textBoxNodeName";
			this->textBoxNodeName->Size = System::Drawing::Size(100, 19);
			this->textBoxNodeName->TabIndex = 12;
			// 
			// labelNodeName
			// 
			this->labelNodeName->AutoSize = true;
			this->labelNodeName->Location = System::Drawing::Point(18, 65);
			this->labelNodeName->Name = L"labelNodeName";
			this->labelNodeName->Size = System::Drawing::Size(44, 12);
			this->labelNodeName->TabIndex = 11;
			this->labelNodeName->Text = L"ノード名";
			// 
			// buttonBindRelease
			// 
			this->buttonBindRelease->Location = System::Drawing::Point(375, 44);
			this->buttonBindRelease->Name = L"buttonBindRelease";
			this->buttonBindRelease->Size = System::Drawing::Size(75, 23);
			this->buttonBindRelease->TabIndex = 10;
			this->buttonBindRelease->Text = L"結合／解除";
			this->buttonBindRelease->UseVisualStyleBackColor = true;
			this->buttonBindRelease->Click += gcnew System::EventHandler(this, &GuiMain::buttonBindRelease_Click);
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
			// buttonJsonCreate
			// 
			this->buttonJsonCreate->Location = System::Drawing::Point(272, 44);
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
			this->GridRowLabel->Location = System::Drawing::Point(41, 16);
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
			this->textBoxColN->Location = System::Drawing::Point(81, 38);
			this->textBoxColN->Name = L"textBoxColN";
			this->textBoxColN->Size = System::Drawing::Size(100, 19);
			this->textBoxColN->TabIndex = 3;
			// 
			// textBoxRowN
			// 
			this->textBoxRowN->Location = System::Drawing::Point(81, 13);
			this->textBoxRowN->Name = L"textBoxRowN";
			this->textBoxRowN->Size = System::Drawing::Size(100, 19);
			this->textBoxRowN->TabIndex = 2;
			// 
			// GridColLabel
			// 
			this->GridColLabel->AutoSize = true;
			this->GridColLabel->Location = System::Drawing::Point(41, 41);
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
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->AutoScroll = true;
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(8, 87);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(614, 320);
			this->panel1->TabIndex = 13;
			// 
			// GuiMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(648, 464);
			this->Controls->Add(this->buttonEnv);
			this->Controls->Add(this->tabControl1);
			this->Name = L"GuiMain";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"GuiMain";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &GuiMain::GuiMain_FormClosed);
			this->Load += gcnew System::EventHandler(this, &GuiMain::GuiMain_Load);
			this->tabControl1->ResumeLayout(false);
			this->GridtabPage->ResumeLayout(false);
			this->GridtabPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		JsonLoader* jsonLoader;
		GridJSONCreator* gridJsonCreator;
		//JSONDBManager* jsonDbLoader;
		narita::DataGridSelfMade^ dataGridJson;
		JSONManager* jsonmanager;

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

		/*
		関数名:
		概要:
		引数:
		返却値:
		作成日:9月15日(金)
		作成者:成田修之
		*/
		array<String^>^ getNodes(std::vector<std::string> node) {
			array<String^>^ retArray = gcnew array<String^>(node.size());
			for (int i = 0; i < node.size(); i++) {
				retArray[i] = gcnew String(node[i].c_str());
			}
			return retArray;
		}

		/*
		関数名:
		概要:
		引数:
		返却値:
		作成日:9月15日(金)
		作成者:成田修之
		*/
		std::string StrToc_str(String^ temp) {
			return (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(temp).ToPointer();
		}

		/*
		関数名:LoadJson
		概要:JSONを読み込む処理を行う関数
		引数:無し
		返却値:無し
		作成日:9月15日(金)
		作成者:成田修之
		*/
	private:Void LoadJson() {
		//読み込み開始
		jsonLoader->init();

		//読みこんだJSONから兄弟群を抜き出す
		array<String^>^ Nodes = getNodes(jsonLoader->getNodes());
		//ノードを選択するフォームのインスタンスを作成する
		NodeSelectForm^ nodeForm = gcnew NodeSelectForm();

		//
		nodeForm->Nodes = Nodes;
		//
		nodeForm->ShowDialog();

		//
		jsonLoader->job(StrToc_str(nodeForm->selectedNode));
		//フォームのノード名に選択されたノードを表示
		textBoxNodeName->Text = nodeForm->selectedNode;

		passDataToGrid();
	}
			/*
			関数名:vectorToArray
			概要:vectorからArrayに変換して返却する関数
			引数:vector<string> vec　変換したい配列
			返却値:array<String^>^　変換後の配列
			作成日:9月20日(水)
			作成者:成田修之
			*/
			array<String^>^ vectorToArray(const std::vector<std::string>& vec) {
				//返却する配列を確保
				array<String^>^ retArray = gcnew array<String^>(vec.size());
				//長さ分繰り返す
				for (int i = 0; i < vec.size(); i++) {
					//引数の配列の各値をマネージに変換して作成した返却する配列に格納
					retArray[i] = gcnew String(UTF8toSjis(vec[i]).c_str());
				}
				//作成した配列を返却する
				return retArray;
			}

			/*
			関数名:arrayToVector
			概要:CLI配列からC++配列に変換
			　　 その際Jフォームの文字列がSJISなのでSON用にUTF8に変換する
			引数:array<String^>^ arr CLI配列
			返却値:vector<string> C++配列
			作成日:9月21日(木)
			作成者:成田修之
			*/
			std::vector<std::string> ArrayToVector(array<String^>^ temp) {
				//返却に使う配列　長さは引数の配列の長さ分
				std::vector<std::string> retVec(temp->Length);
				//配列の長さ分だけ繰り返す
				for (int i = 0; i < temp->Length; i++) {
					//CLI文字列からC++文字列に変換し、UTF8に変換して格納
					retVec[i] = SjistoUTF8(StrToc_str(temp[i]));
				}
				//配列を返す
				return retVec;
			}

			/*
			関数名:printGrid
			概要:新規にJSONを作成するための処理を行う関数
			引数:無し
			返却値:無し
			作成日:9月15日(金)
			作成者:成田修之
			*/
	private: Void printGrid() {
		int rowN;
		int colN;
		try {
			//入力されているタテの長さを取得
			rowN = Convert::ToInt32(textBoxRowN->Text);
			//入力されているヨコの長さを取得
			colN = Convert::ToInt32(textBoxColN->Text);
		}
		catch (Exception^) {
			MessageBox::Show("入力されている値が無効です", "警告", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			throw gcnew Exception("タテヨコに無効な値が入力されています。");
		}
		jsonmanager->grid->init(rowN, colN);
		//入力されていない部分の初期化を行う
		jsonmanager->adjustGridDataSize();
		dataGridJson->cell->init(rowN, colN);
		//表の縦横の長さを取得した値に設定
		dataGridJson->rowCount = rowN;
		dataGridJson->colCount = colN;
	}

			 /*
			 関数名:getJSONFromQuery
			 概要:クエリの結果からJSONを作成する処理を行う関数
			 引数:無し
			 返却値:無し
			 作成日:9月15日(金)
			 作成者:成田修之
			 */
			 //private:Void getJSONFromQuery() {
			 //	jsonDbLoader->run();
			 //	passDataToGrid();
			 //}


			 /*
			 関数名:passDataToGrid
			 概要:処理部で読みこんだ情報を表に渡す関数
			 引数:無し
			 返却値:無し
			 作成日:9月15日(金)
			 作成者:成田修之
			 変更日:9月20日(水)
			 変更者:成田修之
			 内容:値だけでなくキー群も格納する
			 */
	private:void passDataToGrid() {

		int row = jsonmanager->getGridRowLength() + 1;
		int col = jsonmanager->getGridColLength();

		dataGridJson->rowCount = row;
		dataGridJson->colCount = col;
		dataGridJson->cell->init(row, col);
		textBoxRowN->Text = row.ToString();
		textBoxColN->Text = col.ToString();
		jsonmanager->adjustGridDataSize();
		
		//行数分繰り返す
		for (int i = 0; i < row; i++) {
			//列数分繰り返す
			for (int j = 0; j < col; j++) {
				//その位置に値を保管する
				dataGridJson->cell->setValue(i, j, gcnew String(UTF8toSjis(jsonmanager->getGrid(i, j)).c_str()));
				//キー群も取得して格納する
				dataGridJson->cell->setCellKey(i, j, vectorToArray(jsonmanager->getGridData(i, j)));
			}
		}
		//セットした値を表に表示する
		dataGridJson->Paint();
		//初期化できていない部分の初期化を行う
		
	}

			/*
			関数名:buttonOK_Click
			概要:OKボタンが押されたときのイベント
			引数:イベントの引数
			返却値:無し
			作成日:9月15日(金)
			作成者:成田修之
			*/
	private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
		//レイアウトの作成をやめる（描画がおもいため）
		this->SuspendLayout();
		try {
			//JSON読み込みの時
			if (jsonmanager->isJSONFilePathSet()) {
				//JSON読み込み処理を実行する
				LoadJson();
			}
			//else if (jsonDbLoader->isQuerySet()) {
			//	getJsonFromQuery();
			//}
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
		//セルを表示
		dataGridJson->Paint();

		pictureBox1->Visible = true;
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
	private: System::Void buttonCancel_Click(System::Object^  sender, System::EventArgs^  e) {
		//描画処理を一旦停止
		this->SuspendLayout();

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
		//処理部のデータをクリア
		jsonmanager->jsonClear();
		pictureBox1->Visible = false;
		//描画処理をおこなう
		this->ResumeLayout(false);
		this->PerformLayout();
	}

			 //作成ボタン押下時のイベント
	private: System::Void buttonJsonCreate_Click(System::Object^  sender, System::EventArgs^  e) {
		//表の大きさを取得する
		int rowN = dataGridJson->rowCount;
		int colN = dataGridJson->colCount;
		if (textBoxNodeName->Text == "") {
			MessageBox::Show("ノード名が入力されていません", "警告", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		jsonmanager->grid->Clear();
		jsonmanager->env.setNodeName(StrToc_str(textBoxNodeName->Text));
		//表の行数分繰り返す
		for (int i = 0; i < rowN; i++) {
			//結合された行なら
			if (dataGridJson->checkBound(i)) {
				//その時選択されていた列取得
				int selectedColFromRow = dataGridJson->cell->getSelectedColFromRow(i);
				//その位置のデータを取得してUTF8に変換して格納
				jsonmanager->setGrid(i, selectedColFromRow, SjistoUTF8(StrToc_str(dataGridJson->cell->getValue(i, selectedColFromRow))));
				//キーも取得して配置
				jsonmanager->setGridData(i, selectedColFromRow, ArrayToVector(dataGridJson->cell->getCellData(i, selectedColFromRow)));
			}
			//通常の行
			else {
				//表の列数分繰り返す
				for (int j = 0; j < colN; j++) {
					//その位置の値取得してセット
					jsonmanager->setGrid(i, j, SjistoUTF8(StrToc_str(dataGridJson->cell->getValue(i, j))));
					//その位置のキー群を取得してセットする
					jsonmanager->setGridData(i, j, ArrayToVector(dataGridJson->cell->getCellData(i, j)));
					//変換したグリッドの値をセット
				}
			}
		}
		//JSONをクリアする
		jsonmanager->json.clear();
		try {
			//セットされた値でJSONを作成する
			gridJsonCreator->CreateJSON();
		}
		catch (std::exception& e) {
			String^ errorMessage = gcnew String(e.what());
			System::Diagnostics::Debug::WriteLine(errorMessage);
		}
		//作成し終えたらメンバのJSONをクリアする
		jsonmanager->json.clear();
		//作成が完了したことを通知
		MessageBox::Show("JSON作成完了！！", "通知");

	}

			 /*
			 関数名:buttonEnv_Click
			 概要:環境(基本)ボタンがクリックされたときのイベント
			 引数:イベントの引数
			 返却値:なし
			 作成日:9月15日(金)
			 作成者:成田修之
			 */
	private: System::Void buttonEnv_Click(System::Object^  sender, System::EventArgs^  e) {
		//環境設定入力フォームのインスタンスを生成
		EnvForm^ envform = gcnew EnvForm();
		//現在の情報を渡す
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
		std::string query = envform->Query == nullptr ? "" : StrToc_str(envform->Query);
		//セット
		jsonmanager->setQuery(query);
	}

			 /*
			 関数名:GuiMain_Load
			 概要:このフォームが立ち上がった時に行うイベント
			 引数:イベントの引数
			 返却値:無し
			 作成日:9月15日(金)
			 作成者:成田修之
			 */
	private: System::Void GuiMain_Load(System::Object^  sender, System::EventArgs^  e) {
		//各種クラスのインスタンスの作成
		jsonLoader = new JsonLoader();
		gridJsonCreator = new GridJSONCreator();
		//jsonDbLoader = new JSONDBManager();
		//共有オブジェクトを生成
		jsonmanager = new JSONManager();
		dataGridJson = gcnew narita::DataGridSelfMade(pictureBox1);
		
		//共有オブジェクトを共有させる
		jsonLoader->jsonmanager = gridJsonCreator->jsonmanager/* = jsonDbLoader->jsonmanager*/ = jsonmanager;
		//表のテキストボックスにダブルクリックイベントを登録
		dataGridJson->text->DoubleClick += gcnew EventHandler(this, &GuiMain::pictureBox1_DoubleClick);
		//セルを表示する描画対象を見えなくする
		pictureBox1->Visible = false;
//デバッグ時用のパス
std::string filePath = "C:\\Users\\lenovo\\Documents\\flower\\flower\\WebContent\\source\\nfd.json";
		//パスを設定
		jsonmanager->setJsonFilePath(filePath);
	}

			 /*
			 関数名:GuiMain_FormClosed
			 概要:フォームが閉じるときのイベント
			 引数:イベントの引数
			 返却値:無し
			 作成日:9月15日(金)
			 作成者:成田修之
			 */
	private: System::Void GuiMain_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		//共通オブジェクトを削除
		delete jsonmanager;
		//JSON読み込み処理クラスを削除する
		delete jsonLoader;
		//表からJSONを作成するクラスを削除
		delete gridJsonCreator;
		//delete jsonDBLoader;
	}

			 //ピクチャーボックスがクリックされたときのイベント
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		int row = ((MouseEventArgs^)e)->Y / dataGridJson->cellHeight;
		int col = ((MouseEventArgs^)e)->X / dataGridJson->cellWidth;
		if (dataGridJson->checkBound(row)) {
			col = dataGridJson->selectedColFromBoundRow(row);
		}

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
	private: System::Void pictureBox1_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
		int nowX = panel1->AutoScrollPosition.X;
		int nowY = panel1->AutoScrollPosition.Y;

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
		std::vector<std::string>cellData;
		if (dataGridJson->checkBound(row)) {
			col = dataGridJson->selectedColFromBoundRow(row);
		}
		//セルの情報を入力するフォームのインスタンスを生成
		CellEditForm^ cellEdit = gcnew CellEditForm();
		//各情報を渡す
		cellEdit->keyArray = dataGridJson->cell->getCellData(row, col);;
		cellEdit->Value = dataGridJson->cell->getValue(row, col);
		//+1は
		cellEdit->row = row + 1;
		cellEdit->col = col + 1;
		cellEdit->cell = dataGridJson->cell;
		//セルの情報をモーダル表示
		cellEdit->ShowDialog();
		//
		dataGridJson->cell->setCellKey(row, col, cellEdit->keyArray);
		dataGridJson->cell->setValue(row, col, cellEdit->Value);
		dataGridJson->rowCount = dataGridJson->cell->rowCount;
		dataGridJson->colCount = dataGridJson->cell->colCount;
		//
		dataGridJson->drawCell(row, col, Brushes::White);
		dataGridJson->Paint();
		//入力されたデータをグリッド管理クラスにセット
		pictureBox1->Invalidate();
		//スクロールのポジションをフォーム表示前と同じにする
		GridtabPage->AutoScrollPosition = Point(-nowX, -nowY);
	}

			 //セル以外の部分をクリックした際のイベント
	private: System::Void GridtabPage_Click(System::Object^  sender, System::EventArgs^  e) {
		//カレントのセルを表示しない部分にする
		dataGridJson->drawCell(dataGridJson->currentCell, Brushes::White);
		dataGridJson->currentCell->col = -1;
		dataGridJson->currentCell->row = -1;
		pictureBox1->Invalidate();
	}

	private: System::Void buttonBindRelease_Click(System::Object^  sender, System::EventArgs^  e) {
		//選択されている行、列について結合処理を行う
		dataGridJson->BindRelease(dataGridJson->currentCell->row, dataGridJson->currentCell->col);
		pictureBox1->Invalidate();
	}
	};
};