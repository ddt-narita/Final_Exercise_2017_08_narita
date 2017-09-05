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
	/// GuiMain �̊T�v
	/// </summary>
	public ref class GuiMain : public System::Windows::Forms::Form
	{
	public:
		GuiMain(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//
		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
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
		/// �K�v�ȃf�U�C�i�[�ϐ��ł��B
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �f�U�C�i�[ �T�|�[�g�ɕK�v�ȃ��\�b�h�ł��B���̃��\�b�h�̓��e��
		/// �R�[�h �G�f�B�^�[�ŕύX���Ȃ��ł��������B
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
			this->buttonJsonCreate->Text = L"�쐬";
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
			this->GridColLabel->Text = L"���R";
			// 
			// GridRowLabel
			// 
			this->GridRowLabel->AutoSize = true;
			this->GridRowLabel->Location = System::Drawing::Point(20, 22);
			this->GridRowLabel->Name = L"GridRowLabel";
			this->GridRowLabel->Size = System::Drawing::Size(22, 12);
			this->GridRowLabel->TabIndex = 0;
			this->GridRowLabel->Text = L"�^�e";
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
			this->buttonEnv->Font = (gcnew System::Drawing::Font(L"�l�r �o�S�V�b�N", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->buttonEnv->Location = System::Drawing::Point(551, 12);
			this->buttonEnv->Name = L"buttonEnv";
			this->buttonEnv->Size = System::Drawing::Size(75, 23);
			this->buttonEnv->TabIndex = 1;
			this->buttonEnv->Text = L"��{";
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

	//OK�{�^���������̃C�x���g
	private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
		
		//���C�A�E�g�̍쐬����߂�i�`�悪���������߁j
		this->SuspendLayout();
		tableLayoutPanel1->SuspendLayout();
		GridtableLayoutPanel->SuspendLayout();
		tableLayoutPanelRowButton->SuspendLayout();
		
		gridJsonCreator = new GridJSONCreator();

		//���͂���Ă���^�e�̒������擾
		int rowN = Convert::ToInt32(textBoxRowN->Text);
		//���͂���Ă��郈�R�̒������擾
		int colN = Convert::ToInt32(textBoxColN->Text);
		
		gridJsonCreator->init(rowN, colN);

		//tablelayoutpanel�̏c���̒������擾�����l�ɐݒ�
		GridtableLayoutPanel->RowCount = rowN;
		GridtableLayoutPanel->ColumnCount = colN;
		tableLayoutPanelRowButton->RowCount = rowN;

		//�\�ɃZ����ǉ����Ă���
		for (int i = 0; i < rowN; i++) {

			Button^ rowButton = gcnew Button();
			rowButton->Size = System::Drawing::Size(70, 25);
			rowButton->Text = (i + 1).ToString() + "�s��";
			tableLayoutPanelRowButton->Controls->Add(rowButton, 0,i);

			for (int j = 0; j < colN; j++) {
				//�p�l���ɃZ�b�g����e�L�X�g�{�b�N�X���쐬
				Button^ temp = gcnew Button();
				temp->Size = System::Drawing::Size(75, 25);
				//temp->Multiline = true;
				temp->Text = "";
				temp->Click += gcnew EventHandler(this, &GuiMain::Cell_Click);
				
				//�O���b�h�̕\�ɒǉ����Ă���
				GridtableLayoutPanel->Controls->Add(temp, j, i);
			}
		}


		//���I�����p�l����GUI��ɕ\��
		tableLayoutPanel1->Controls->Add(tableLayoutPanelRowButton, 0, 0);
		tableLayoutPanel1->Controls->Add(GridtableLayoutPanel,1,0);
		GridtabPage->Controls->Add(tableLayoutPanel1);

		//���C�A�E�g�̕\�����J�n����
		this->ResumeLayout(false);
		this->PerformLayout();
		tableLayoutPanel1->ResumeLayout(false);
		GridtableLayoutPanel->ResumeLayout(false);
		tableLayoutPanelRowButton->ResumeLayout(false);
		tableLayoutPanel1->PerformLayout();
		GridtableLayoutPanel->PerformLayout();
		tableLayoutPanelRowButton->PerformLayout();
 	}
	

	//�e�Z�����_�u���N���b�N�����Ƃ��̃C�x���g
	private: System::Void Cell_Click(System::Object^  sender, System::EventArgs^  e) {
		//�t�H�[����\���������Ƃ��Ƀg�b�v�ɖ߂��Ă��܂��̂ŕ\���O�̈ʒu���擾
		int nowX = this->AutoScrollPosition.X;
		int nowY = this->AutoScrollPosition.Y;

		//�s���񐔎擾
		int rown = GridtableLayoutPanel->GetCellPosition((Button^)sender).Row;
		int coln = GridtableLayoutPanel->GetCellPosition((Button^)sender).Column;

		//�I�����ꂽ�e�L�X�g�̈ʒu��\��
		//MessageBox::Show("�s�F" + (rown + 1).ToString() + "��F" + (coln + 1).ToString(), "�I�����ꂽ�e�L�X�g�I�I");


		//�Z���̏��擾
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
			//������ւ̕ϊ�
			tempt[i] = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(abc[i]).ToPointer();
		}

		//���͂��ꂽ�f�[�^���O���b�h�Ǘ��N���X�ɃZ�b�g
		gridJsonCreator->setGridData(rown, coln, tempt);

		
		//�\���O�̈ʒu�ɖ߂�(�����W�̓}�C�i�X�Ŏ擾���Ă��邽�ߕ����𔽓]������)
		this->AutoScrollPosition = Point(nowX, -nowY);
	}




//�L�����Z���{�^�����N���b�N�����Ƃ��̃C�x���g
//�\�̃R���g���[�������ׂč폜
private: System::Void buttonCancel_Click(System::Object^  sender, System::EventArgs^  e) {
	
	this->SuspendLayout();

	Control^ remv = tableLayoutPanel1->GetControlFromPosition(0, 0);

	tableLayoutPanel1->Controls->Remove(remv);

	//���͂���Ă���^�e�̒������擾
	int rowN = Convert::ToInt32(textBoxRowN->Text);
	//���͂���Ă��郈�R�̒������擾
	int colN = Convert::ToInt32(textBoxColN->Text);

	//�e�L�X�g�{�b�N�X���p�l���ɒǉ�
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
			//�O���b�h�̒l���Z�b�g
			gridJsonCreator->setGrid(i, j, str);
		}
	}

	gridJsonCreator->job();

}
};
}
