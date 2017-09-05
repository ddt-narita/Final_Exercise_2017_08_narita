#pragma once
#include "GridJSONCreator.h"
#include "GridInfo.h"
#include "GridRowInfo.h"


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
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  GridtableLayoutPanel;
	private: System::Windows::Forms::Button^  buttonCancel;

	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::TextBox^  textBoxColN;


	private: System::Windows::Forms::TextBox^  textBoxRowN;

	private: System::Windows::Forms::Label^  GridColLabel;
	private: System::Windows::Forms::Label^  GridRowLabel;
	private: System::Windows::Forms::Button^  buttonJsonCreate;
	private: System::Windows::Forms::Button^  buttonEnv;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanelRowButton;




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
			this->buttonJsonCreate = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->textBoxColN = (gcnew System::Windows::Forms::TextBox());
			this->textBoxRowN = (gcnew System::Windows::Forms::TextBox());
			this->GridColLabel = (gcnew System::Windows::Forms::Label());
			this->GridRowLabel = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->GridtableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->buttonEnv = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanelRowButton = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tabControl1->SuspendLayout();
			this->GridtabPage->SuspendLayout();
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
			this->GridtabPage->Controls->Add(this->buttonJsonCreate);
			this->GridtabPage->Controls->Add(this->tableLayoutPanel1);
			this->GridtabPage->Controls->Add(this->buttonCancel);
			this->GridtabPage->Controls->Add(this->buttonOK);
			this->GridtabPage->Controls->Add(this->textBoxColN);
			this->GridtabPage->Controls->Add(this->textBoxRowN);
			this->GridtabPage->Controls->Add(this->GridColLabel);
			this->GridtabPage->Controls->Add(this->GridRowLabel);
			this->GridtabPage->Location = System::Drawing::Point(4, 22);
			this->GridtabPage->Name = L"GridtabPage";
			this->GridtabPage->Padding = System::Windows::Forms::Padding(3);
			this->GridtabPage->Size = System::Drawing::Size(640, 415);
			this->GridtabPage->TabIndex = 0;
			this->GridtabPage->Text = L"Grid";
			this->GridtabPage->UseVisualStyleBackColor = true;
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
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->AutoScroll = true;
			this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 75);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->Size = System::Drawing::Size(637, 322);
			this->tableLayoutPanel1->TabIndex = 6;
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
			this->GridColLabel->Location = System::Drawing::Point(20, 49);
			this->GridColLabel->Name = L"GridColLabel";
			this->GridColLabel->Size = System::Drawing::Size(21, 12);
			this->GridColLabel->TabIndex = 1;
			this->GridColLabel->Text = L"ヨコ";
			// 
			// GridRowLabel
			// 
			this->GridRowLabel->AutoSize = true;
			this->GridRowLabel->Location = System::Drawing::Point(20, 22);
			this->GridRowLabel->Name = L"GridRowLabel";
			this->GridRowLabel->Size = System::Drawing::Size(22, 12);
			this->GridRowLabel->TabIndex = 0;
			this->GridRowLabel->Text = L"タテ";
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
			// GridtableLayoutPanel
			// 
			this->GridtableLayoutPanel->AutoSize = true;
			this->GridtableLayoutPanel->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->GridtableLayoutPanel->ColumnCount = 3;
			this->GridtableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->GridtableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->GridtableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->GridtableLayoutPanel->Location = System::Drawing::Point(4, 4);
			this->GridtableLayoutPanel->Name = L"GridtableLayoutPanel";
			this->GridtableLayoutPanel->RowCount = 3;
			this->GridtableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->GridtableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->GridtableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->GridtableLayoutPanel->Size = System::Drawing::Size(4, 4);
			this->GridtableLayoutPanel->TabIndex = 0;
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
			// 
			// tableLayoutPanelRowButton
			// 
			this->tableLayoutPanelRowButton->AutoSize = true;
			this->tableLayoutPanelRowButton->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanelRowButton->ColumnCount = 1;
			this->tableLayoutPanelRowButton->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanelRowButton->Location = System::Drawing::Point(5, 4);
			this->tableLayoutPanelRowButton->Name = L"tableLayoutPanelRowButton";
			this->tableLayoutPanelRowButton->RowCount = 1;
			this->tableLayoutPanelRowButton->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanelRowButton->Size = System::Drawing::Size(200, 100);
			this->tableLayoutPanelRowButton->TabIndex = 0;
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
			this->tabControl1->ResumeLayout(false);
			this->GridtabPage->ResumeLayout(false);
			this->GridtabPage->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		GridJSONCreator* gridJsonCreator;

	//OKボタン押下時のイベント
	private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
		
		//レイアウトの作成をやめる（描画がおもいため）
		this->SuspendLayout();
		tableLayoutPanel1->SuspendLayout();
		GridtableLayoutPanel->SuspendLayout();
		tableLayoutPanelRowButton->SuspendLayout();
		
		gridJsonCreator = new GridJSONCreator();

		//入力されているタテの長さを取得
		int rowN = Convert::ToInt32(textBoxRowN->Text);
		//入力されているヨコの長さを取得
		int colN = Convert::ToInt32(textBoxColN->Text);
		
		gridJsonCreator->init(rowN, colN);

		//tablelayoutpanelの縦横の長さを取得した値に設定
		GridtableLayoutPanel->RowCount = rowN;
		GridtableLayoutPanel->ColumnCount = colN;
		tableLayoutPanelRowButton->RowCount = rowN;

		//表にセルを追加していく
		for (int i = 0; i < rowN; i++) {

			Button^ rowButton = gcnew Button();
			rowButton->Size = System::Drawing::Size(70, 25);
			rowButton->Text = (i + 1).ToString() + "行目";
			tableLayoutPanelRowButton->Controls->Add(rowButton, 0,i);

			for (int j = 0; j < colN; j++) {
				//パネルにセットするテキストボックスを作成
				Button^ temp = gcnew Button();
				temp->Size = System::Drawing::Size(75, 25);
				//temp->Multiline = true;
				temp->Text = "";
				temp->Click += gcnew EventHandler(this, &GuiMain::Cell_Click);
				
				//グリッドの表に追加していく
				GridtableLayoutPanel->Controls->Add(temp, j, i);
			}
		}


		//作り終えたパネルをGUI上に表示
		tableLayoutPanel1->Controls->Add(tableLayoutPanelRowButton, 0, 0);
		tableLayoutPanel1->Controls->Add(GridtableLayoutPanel,1,0);
		GridtabPage->Controls->Add(tableLayoutPanel1);

		//レイアウトの表示を開始する
		this->ResumeLayout(false);
		this->PerformLayout();
		tableLayoutPanel1->ResumeLayout(false);
		GridtableLayoutPanel->ResumeLayout(false);
		tableLayoutPanelRowButton->ResumeLayout(false);
		tableLayoutPanel1->PerformLayout();
		GridtableLayoutPanel->PerformLayout();
		tableLayoutPanelRowButton->PerformLayout();
 	}
	

	//各セルをダブルクリックしたときのイベント
	private: System::Void Cell_Click(System::Object^  sender, System::EventArgs^  e) {
		//フォームを表示させたときにトップに戻ってしまうので表示前の位置を取得
		int nowX = this->AutoScrollPosition.X;
		int nowY = this->AutoScrollPosition.Y;

		//行数列数取得
		int rown = GridtableLayoutPanel->GetCellPosition((Button^)sender).Row;
		int coln = GridtableLayoutPanel->GetCellPosition((Button^)sender).Column;

		//選択されたテキストの位置を表示
		//MessageBox::Show("行：" + (rown + 1).ToString() + "列：" + (coln + 1).ToString(), "選択されたテキスト！！");


		//セルの情報取得
		std::vector<std::string>tempt(gridJsonCreator->getGridData(rown, coln));
		array<String^>^ abc = gcnew array<String^>(4);
		for (int i = 0; i < 4; i++) {
			abc[i] = gcnew String(tempt[i].c_str());
		}

		GridInfo^ gridinfo = gcnew GridInfo();
		gridinfo->contentKey = abc[0];
		gridinfo->key = abc[1];
		gridinfo->rowN = rown + 1;
		gridinfo->colN = coln + 1;

		gridinfo->ShowDialog();

		abc[0] = gridinfo->contentKey;
		abc[1] = gridinfo->key;
		abc[2] = gridinfo->rowspan.ToString();
		abc[3] = gridinfo->colspan.ToString();

		for (int i = 0; i < 4; i++) {
			//文字列への変換
			tempt[i] = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(abc[i]).ToPointer();
		}

		//入力されたデータをグリッド管理クラスにセット
		gridJsonCreator->setGridData(rown, coln, tempt);

		
		//表示前の位置に戻す(ｙ座標はマイナスで取得しているため符号を反転させる)
		this->AutoScrollPosition = Point(nowX, -nowY);
	}




//キャンセルボタンをクリックしたときのイベント
//表のコントロールをすべて削除
private: System::Void buttonCancel_Click(System::Object^  sender, System::EventArgs^  e) {
	
	this->SuspendLayout();

	Control^ remv = tableLayoutPanel1->GetControlFromPosition(0, 0);

	tableLayoutPanel1->Controls->Remove(remv);

	//入力されているタテの長さを取得
	int rowN = Convert::ToInt32(textBoxRowN->Text);
	//入力されているヨコの長さを取得
	int colN = Convert::ToInt32(textBoxColN->Text);

	//テキストボックスをパネルに追加
	for (int i = 0; i < rowN; i++) {
		for (int j = 0; j < colN; j++) {
			Control^ remv = GridtableLayoutPanel->GetControlFromPosition(j, i);

			GridtableLayoutPanel->Controls->Remove(remv);
		}
	}
	this->ResumeLayout(false);
	this->PerformLayout();
}

//
private: System::Void buttonJsonCreate_Click(System::Object^  sender, System::EventArgs^  e) {
	int rowN = gridJsonCreator->getGridRowLength();
	int colN = gridJsonCreator->getGridColLength();

	for (int i = 0; i < rowN; i++) {
		for (int j = 0; j < colN; j++) {
			Button^ temp = (Button^)(GridtableLayoutPanel->GetControlFromPosition(j, i));
			std::string str = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(temp->Text).ToPointer();
			//グリッドの値をセット
			gridJsonCreator->setGrid(i, j, str);
		}
	}

	gridJsonCreator->job();

}
};
}
