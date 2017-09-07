#pragma once
#include "GridJSONCreator.h"
#include "GridInfo.h"
#include "GridRowInfo.h"
#include "Constants.h"
#include "EnvForm.h"
#include "JsonLoader.h"
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
	private: System::Windows::Forms::DataGridView^  dataGridViewJSON;







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
			this->dataGridViewJSON = (gcnew System::Windows::Forms::DataGridView());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewJSON))->BeginInit();
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
			this->GridtabPage->Controls->Add(this->dataGridViewJSON);
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
			// 
			// dataGridViewJSON
			// 
			this->dataGridViewJSON->AllowUserToAddRows = false;
			this->dataGridViewJSON->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridViewJSON->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewJSON->Location = System::Drawing::Point(8, 89);
			this->dataGridViewJSON->Name = L"dataGridViewJSON";
			this->dataGridViewJSON->RowTemplate->Height = 21;
			this->dataGridViewJSON->Size = System::Drawing::Size(624, 320);
			this->dataGridViewJSON->TabIndex = 8;
			this->dataGridViewJSON->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &GuiMain::dataGridViewJSON_CellDoubleClick);
			this->dataGridViewJSON->RowHeaderMouseDoubleClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &GuiMain::dataGridViewJSON_RowHeaderMouseDoubleClick);
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
			this->buttonOK->Location = System::Drawing::Point(547, 17);
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
			this->Load += gcnew System::EventHandler(this, &GuiMain::GuiMain_Load);
			this->tabControl1->ResumeLayout(false);
			this->GridtabPage->ResumeLayout(false);
			this->GridtabPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewJSON))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		JsonLoader* jsonLoader;
		GridJSONCreator* gridJsonCreator;


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

			jsonLoader->run();

			int rowN = jsonLoader->jsonmanager->getGridRowLength();
			int colN = jsonLoader->jsonmanager->getGridColLength();

			//まだ表を作成していなかったなら
			if (dataGridViewJSON->RowCount < 1) {
				//結合ボタン
				DataGridViewButtonColumn^ button = gcnew DataGridViewButtonColumn();
				button->Name = "bind";
				button->UseColumnTextForButtonValue = true;
				button->Text = "結合";

				//結合ボタン列を追加
				dataGridViewJSON->Columns->Add(button);
			}


			dataGridViewJSON->RowCount = rowN;
			dataGridViewJSON->ColumnCount = colN + 1;
			
			for (int i = 0; i < rowN; i++) {
				for (int j = 0; j < colN; j++) {
					(dataGridViewJSON->Rows[i]->Cells[j + 1]->Value) = gcnew String(UTF8toSjis(jsonLoader->jsonmanager->getGrid(i, j)).c_str());
				}
			}

		}
		else {
			//入力されているタテの長さを取得
			int rowN = Convert::ToInt32(textBoxRowN->Text);
			//入力されているヨコの長さを取得
			int colN = Convert::ToInt32(textBoxColN->Text);
			gridJsonCreator->jsonmanager->setGridRowLen(rowN);
			gridJsonCreator->jsonmanager->setGridMaxColLen(colN);

			gridJsonCreator->init(rowN, colN);


			//まだ表を作成していなかったなら
			if (dataGridViewJSON->RowCount < 1) {
				//結合ボタン
				DataGridViewButtonColumn^ button = gcnew DataGridViewButtonColumn();
				button->Name = "bind";
				button->UseColumnTextForButtonValue = true;
				button->Text = "結合";

				//結合ボタン列を追加
				dataGridViewJSON->Columns->Add(button);
			}

			//tablelayoutpanelの縦横の長さを取得した値に設定
			dataGridViewJSON->RowCount = rowN;
			dataGridViewJSON->ColumnCount = colN + 1;
		}

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
	int rowcount = dataGridViewJSON->RowCount;
	//行数分繰り返して全行削除
	for (int i = 0; i < rowcount; i++) {
		dataGridViewJSON->Rows->RemoveAt(0);
	}
	//行数列数を0にする
	dataGridViewJSON->ColumnCount = 0;
	dataGridViewJSON->RowCount = 0;

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
			String^ temp = (String^)(dataGridViewJSON->Rows[i]->Cells[j + 1]->Value);
			
			temp = temp == nullptr ? "" : temp;

			//String型からstring型へ変換する
			std::string str = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(temp).ToPointer();
			//変換したグリッドの値をセット
			gridJsonCreator->jsonmanager->setGrid(i, j, str);
		}
	}
	//セットされた値でJSONを作成する
	gridJsonCreator->job();

	//作成し終えたらメンバのJSONをクリアする
	gridJsonCreator->jsonmanager->jsonClear();

	MessageBox::Show("JSON作成完了！！", "通知");

}

//セルをダブルクリックした際のイベント
private: System::Void dataGridViewJSON_CellDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
{
	//行数列数取得
	int rown = dataGridViewJSON->CurrentCell->RowIndex;
	int coln = dataGridViewJSON->CurrentCell->ColumnIndex - 1;

	//結合ボタンでなければ
	if (coln >= 0) {
		//セルの情報取得
		std::vector<std::string>tempt(gridJsonCreator->jsonmanager->getGridData(rown, coln));
		//セルの情報として
		array<String^>^ cellinfo_CLI = gcnew array<String^>(constants.CELL_INFO_NUMBER);
		//セルの情報の数だけ繰り返す(2回)
		for (int i = 0; i < constants.CELL_INFO_NUMBER; i++) {
			cellinfo_CLI[i] = gcnew String(tempt[i].c_str());
		}

		//セルの情報を入力するフォームのインスタンスを生成
		GridInfo^ gridinfo = gcnew GridInfo();
		//各情報を渡す
		gridinfo->key = cellinfo_CLI[constants.KEY_INDEX];
		gridinfo->contentKey = cellinfo_CLI[constants.CONTENT_KEY_INDEX];
		gridinfo->rowN = rown + 1;
		gridinfo->colN = coln + 1;

		//セルの情報をモーダル表示
		gridinfo->ShowDialog();

		//入力された情報を取得
		cellinfo_CLI[constants.KEY_INDEX] = gridinfo->key;
		cellinfo_CLI[constants.CONTENT_KEY_INDEX] = gridinfo->contentKey;

		//コンテントキーと親のキーのみ取得
		for (int i = 0; i < constants.CELL_INFO_NUMBER; i++) {
			//文字列への変換
			tempt[i] = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(cellinfo_CLI[i]).ToPointer();
		}

		//入力されたデータをグリッド管理クラスにセット
		gridJsonCreator->jsonmanager->setGridData(rown, coln, tempt);
	}
}


//行ごとの情報を入力するフォーム表示
private: System::Void dataGridViewJSON_RowHeaderMouseDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e) {
	//選択されている行が何行目か取得
	int rowN = dataGridViewJSON->CurrentRow->Index;
	//その行の情報を取得する
	std::vector<std::string> tempvec = gridJsonCreator->jsonmanager->getGridRowData(rowN);

	//行ごとの情報を入力するフォームのインスタンスを生成
	GridRowInfo^ rowInfo = gcnew GridRowInfo();

	//行ごとの情報の要素数分の配列を確保（vector→arrayへの変換手続き）
	//(size() - constan)…はこれがないと行の情報を表示させるたびに行が増えていってしまうため(DataGridViewの仕様)
	array<String^>^ temparray = gcnew array<String^>(tempvec.size() - constants.ROW_INFO_ADJUSTER);
	//取得した情報の数だけ繰り返してコピー
	for (int i = 0; i < tempvec.size() - 1; i++) {
		String^ tempstr = gcnew String(tempvec[i].c_str());
		temparray[i] = tempstr;
	}

	//行ごとの情報配列をフォームに渡す
	rowInfo->gridRowInfo = temparray;
	//何行目かの情報をフォームに渡す
	rowInfo->rowNumber = rowN;

	//フォームをモーダル表示
	rowInfo->ShowDialog();

	//配列をクリア
	tempvec.clear();
	//行ごとの情報の数だけ繰り返す
	for (int i = 0; i < rowInfo->gridRowInfo->Length; i++) {
		//フォームの上から順にデータを格納
		std::string temp = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(rowInfo->gridRowInfo[i]).ToPointer();
		//配列に格納
		tempvec.push_back(temp);
	}
	//格納したデータをその行のデータとしてセット
	gridJsonCreator->jsonmanager->setGridRowData(rowN, tempvec);
}


//結合ボタンが押されたときのイベント
private: System::Void dataGridViewJSON_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	DataGridView^ dgv = (DataGridView^)sender;
	//"bind"列がクリックされたとき(結合ボタンが押されたとき)
	if (dgv->Columns[e->ColumnIndex]->Name == "bind")
	{
		//
		GuiMain::dataGridViewJSON_CellPainting(sender, (DataGridViewCellPaintingEventArgs^)e);
	}
}

//セルの結合
private: System::Void dataGridViewJSON_CellPainting(System::Object^  sender, System::Windows::Forms::DataGridViewCellPaintingEventArgs^  e) {
	
	//if (dataGridViewJSON->CurrentCell->ColumnIndex < 0) {
	//	DataGridView^ dv = (DataGridView^)(sender);
	//	//Rectangle^ rect;
	//	DataGridViewCell^ cell;

	//	rect = e->CellBounds;
	//	cell = dataGridViewJSON[e->ColumnIndex + 1, e->RowIndex];
	//	// 一つ右のセルの幅を足す
	//	rect->Width += cell->Size.Width;
	//	rect->X -= 1;
	//	rect->Y -= 1;
	//	e->Graphics->FillRectangle(gcnew SolidBrush(e->CellStyle->BackColor), *rect);
	//	e->Graphics->DrawRectangle(gcnew Pen(dv->GridColor), *rect);
	//	TextRenderer::DrawText(e->Graphics, e->FormattedValue->ToString(), e->CellStyle->Font, *rect, e->CellStyle->ForeColor, TextFormatFlags::HorizontalCenter | TextFormatFlags::VerticalCenter);
	//	e->Handled = true;
	//}
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

	std::string filepath = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(envform->JSONFilePath).ToPointer();

	//パスを取得してセットする
	jsonLoader->jsonmanager->setJsonFilePath(filepath);

}

//
private: System::Void GuiMain_Load(System::Object^  sender, System::EventArgs^  e) {
	jsonLoader = new JsonLoader();
	gridJsonCreator = new GridJSONCreator;

	jsonLoader->jsonmanager = gridJsonCreator->jsonmanager = new JSONManager();
}
};
}
