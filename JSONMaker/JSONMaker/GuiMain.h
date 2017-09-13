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
			this->buttonJsonCreate->Text = L"�쐬";
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
			this->GridRowLabel->Text = L"�^�e";
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
			this->GridColLabel->Text = L"���R";
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
			this->buttonEnv->Font = (gcnew System::Drawing::Font(L"�l�r �o�S�V�b�N", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->buttonEnv->Location = System::Drawing::Point(551, 12);
			this->buttonEnv->Name = L"buttonEnv";
			this->buttonEnv->Size = System::Drawing::Size(75, 23);
			this->buttonEnv->TabIndex = 1;
			this->buttonEnv->Text = L"��{";
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

		//utf8��SJIS�ɕϊ�����֐�
		//�t�@�C���̕����R�[�h��utf8�ł���A�t�H�[���Ŏg��������SJIS�̂���
		std::string UTF8toSjis(std::string srcUTF8) {
			//Unicode�֕ϊ���̕����񒷂𓾂�
			int lenghtUnicode = MultiByteToWideChar(CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, NULL, 0);
			//�K�v�ȕ�����Unicode������̃o�b�t�@���m��
			wchar_t* bufUnicode = new wchar_t[lenghtUnicode];
			//UTF8����Unicode�֕ϊ�
			MultiByteToWideChar(CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, bufUnicode, lenghtUnicode);
			//ShiftJIS�֕ϊ���̕����񒷂𓾂�
			int lengthSJis = WideCharToMultiByte(CP_THREAD_ACP, 0, bufUnicode, -1, NULL, 0, NULL, NULL);
			//�K�v�ȕ�����ShiftJIS������̃o�b�t�@���m��
			char* bufShiftJis = new char[lengthSJis];
			//Unicode����ShiftJIS�֕ϊ�
			WideCharToMultiByte(CP_THREAD_ACP, 0, bufUnicode, lenghtUnicode + 1, bufShiftJis, lengthSJis, NULL, NULL);
			std::string strSJis(bufShiftJis);
			delete bufUnicode;
			delete bufShiftJis;
			return strSJis;
		}

		//SJIS����utf8�ɕϊ�����֐�
		//�t�H�[���Ŏg��������SJIS�ł���AJSON�t�@�C���̕����R�[�h��utf8�̂���
		std::string SjistoUTF8(std::string srcSjis) {
			//Unicode�֕ϊ���̕����񒷂𓾂�
			int lenghtUnicode = MultiByteToWideChar(CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, NULL, 0);
			//�K�v�ȕ�����Unicode������̃o�b�t�@���m��
			wchar_t* bufUnicode = new wchar_t[lenghtUnicode];
			//ShiftJIS����Unicode�֕ϊ�
			MultiByteToWideChar(CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, bufUnicode, lenghtUnicode);
			//UTF8�֕ϊ���̕����񒷂𓾂�
			int lengthUTF8 = WideCharToMultiByte(CP_UTF8, 0, bufUnicode, -1, NULL, 0, NULL, NULL);
			//�K�v�ȕ�����UTF8������̃o�b�t�@���m��
			char* bufUTF8 = new char[lengthUTF8];
			//Unicode����UTF8�֕ϊ�
			WideCharToMultiByte(CP_UTF8, 0, bufUnicode, lenghtUnicode + 1, bufUTF8, lengthUTF8, NULL, NULL);
			std::string strUTF8(bufUTF8);
			delete bufUnicode;
			delete bufUTF8;
			return strUTF8;
		}

		//OK�{�^���������̃C�x���g
	private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
		//���C�A�E�g�̍쐬����߂�i�`�悪���������߁j
		this->SuspendLayout();

		//JSON�ǂݍ��݂̎�
		if (jsonLoader->jsonmanager->isJSONFilePathSet()) {
			//�ǂݍ��݊J�n
			jsonLoader->run();
			//�s���擾
			int rowN = jsonLoader->jsonmanager->getGridRowLength() + 1;
			//�ő�̗񐔎擾
			int colN = jsonLoader->jsonmanager->getGridColLength();
			//�\�̑傫�����擾�����񐔍s����
			dataGridJson->rowCount = rowN;
			//�s�̃L�[��
			dataGridJson->colCount = colN;
			//�񐔕��J��Ԃ�
			for (int i = 0; i < rowN; i++) {
				//�s�����J��Ԃ� (�s�̃L�[������
				for (int j = 0; j < colN; j++) {
					//�s�Ɨ񂩂�L�[���쐬
					String^ key = dataGridJson->CreateGridMapKey(i, j);
					//���̈ʒu�ɔz�u
					dataGridJson[key] = gcnew String(UTF8toSjis(jsonLoader->jsonmanager->getGrid(i, j)).c_str());
				}
			}
			//�������ł��Ă��Ȃ������̏��������s��
			gridJsonCreator->jsonmanager->adjustGridDataSize();
		}
		else {
			//���͂���Ă���^�e�̒������擾
			int rowN = Convert::ToInt32(textBoxRowN->Text);
			//���͂���Ă��郈�R�̒������擾
			int colN = Convert::ToInt32(textBoxColN->Text);

			if (gridJsonCreator->jsonmanager->getGridRowLength() == 0) {
				//���������s��
				gridJsonCreator->init(rowN, colN);
			}
			//�ő�̑傫���Ƃ��Ċi�[
			gridJsonCreator->jsonmanager->setGridRowLen(rowN);
			gridJsonCreator->jsonmanager->setGridMaxColLen(colN);
			//���͂���Ă��Ȃ������̏��������s��
			gridJsonCreator->jsonmanager->adjustGridDataSize();

			//tablelayoutpanel�̏c���̒������擾�����l�ɐݒ�
			dataGridJson->rowCount = rowN;
			dataGridJson->colCount = colN;
		}
		//�Z����\��
		dataGridJson->Paint();

		pictureBox1->Visible = true;
		//���C�A�E�g�̕\�����J�n����
		this->ResumeLayout(false);
		this->PerformLayout();
	}


			 //�L�����Z���{�^�����N���b�N�����Ƃ��̃C�x���g
			 //�\�̃R���g���[�������ׂč폜
	private: System::Void buttonCancel_Click(System::Object^  sender, System::EventArgs^  e) {
		//�`�揈������U��~
		this->SuspendLayout();
		//�s���擾
		int rowcount = dataGridJson->rowCount;
		//�s�����J��Ԃ��đS�s�폜
		for (int i = 0; i < rowcount; i++) {
			//dataGridJson[i.ToString()] = "s";
		}
		//�s���񐔂�0�ɂ���
		dataGridJson->colCount = 0;
		dataGridJson->rowCount = 0;

		//�`�揈���������Ȃ�
		this->ResumeLayout(false);
		this->PerformLayout();
	}

			 //�쐬�{�^���������̃C�x���g
	private: System::Void buttonJsonCreate_Click(System::Object^  sender, System::EventArgs^  e) {
		//���͂��ꂽ�\�̑傫�����擾����
		int rowN = gridJsonCreator->jsonmanager->getGridRowLength();
		int colN = gridJsonCreator->jsonmanager->getGridColLength();

		//�\�̍s�����J��Ԃ�
		for (int i = 0; i < rowN; i++) {
			//�\�̗񐔕��J��Ԃ�
			for (int j = 0; j < colN; j++) {
				//���̈ʒu�ɓ��͂���Ă���Z���̒l���擾����(cells��+1�͌����{�^���̂���)
				String^ temp = (dataGridJson[dataGridJson->CreateGridMapKey(i, j)]);
				//�i������΋󕶎��A�����łȂ���΂��̂܂�
				temp = temp == nullptr ? "" : temp;

				//String�^����string�^�֕ϊ�����
				std::string str = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(temp).ToPointer();
				//�ϊ������O���b�h�̒l���Z�b�g
				gridJsonCreator->jsonmanager->setGrid(i, j, str);
			}
		}
		gridJsonCreator->jsonmanager->jsonClear();
		//�Z�b�g���ꂽ�l��JSON���쐬����
		gridJsonCreator->job();
		//�쐬���I�����烁���o��JSON���N���A����
		gridJsonCreator->jsonmanager->jsonClear();
		MessageBox::Show("JSON�쐬�����I�I", "�ʒm");

	}

			 //���{�^���������ꂽ�Ƃ��̃C�x���g
	private: System::Void buttonEnv_Click(System::Object^  sender, System::EventArgs^  e) {
		//���ݒ���̓t�H�[���̃C���X�^���X�𐶐�
		EnvForm^ envform = gcnew EnvForm();

		//���݂̏���n��
		envform->JSONFilePath = gcnew String(jsonLoader->jsonmanager->getJsonFilePath().c_str());
		//envform->DBName		  = gcnew String(jsonLoader->getDBName().c_str());
		//envform->Query		  = gcnew String(jsonLoader->getQuery().c_str());
		//���[�_���\������
		envform->ShowDialog();

		//�t�@�C���p�X����͂��邽�߂̕ϐ�
		std::string filepath;
		//�i���łȂ����
		if (envform->JSONFilePath != nullptr) {
			//�擾
			filepath = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(envform->JSONFilePath).ToPointer();
		}
		//�擾�����p�X���Z�b�g����
		jsonLoader->jsonmanager->setJsonFilePath(filepath);

	}

			 //�����オ�������ɍs���֐�
	private: System::Void GuiMain_Load(System::Object^  sender, System::EventArgs^  e) {
		//�e��N���X�̃C���X�^���X�̍쐬
		jsonLoader = new JsonLoader();
		gridJsonCreator = new GridJSONCreator;
		dataGridJson = gcnew narita::DataGridSelfMade(pictureBox1);

		//JSONManager�̃C���X�^���X�����L����
		jsonLoader->jsonmanager = gridJsonCreator->jsonmanager = new JSONManager();
		//�\�̃e�L�X�g�{�b�N�X�Ƀ_�u���N���b�N�C�x���g��o�^
		dataGridJson->text->DoubleClick += gcnew EventHandler(this, &GuiMain::pictureBox1_DoubleClick);
		pictureBox1->Visible = false;
	}


			 //�t�H�[��������Ƃ��̊֐�
	private: System::Void GuiMain_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {

		delete jsonLoader->jsonmanager;
		delete jsonLoader;
		delete gridJsonCreator;
	}

			 //�s�N�`���[�{�b�N�X���N���b�N���ꂽ�Ƃ��̃C�x���g
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		//�s�Ɨ���擾
		int row = ((MouseEventArgs^)e)->Y / dataGridJson->cellHeight;
		int col = ((MouseEventArgs^)e)->X / dataGridJson->cellWidth;

		//���̈ʒu�ɂ��ăN���b�N����
		dataGridJson->cell_click(row, col);
	}

			 //�_�u���N���b�N���ꂽ�Ƃ��̃C�x���g
			 //�Z���̏���\������
	private: System::Void pictureBox1_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
		int nowX = GridtabPage->AutoScrollPosition.X;
		int nowY = GridtabPage->AutoScrollPosition.Y;

		int row;
		int col;

		//�e�L�X�g�{�b�N�X����Ă΂ꂽ�Ƃ�
		if (sender->GetType() == TextBox::typeid) {
			//�ʒu�擾�̂��߂Ɍ^�ϊ�
			TextBox^ senderBox = (TextBox^)sender;
			//�s�Ɨ���擾
			row = senderBox->Location.Y / dataGridJson->cellHeight;
			col = senderBox->Location.X / dataGridJson->cellWidth;
		}
		//�s�N�`���[�{�b�N�X����Ă΂ꂽ�Ƃ�
		else {
			//��ƍs���擾
			row = ((MouseEventArgs^)e)->Y / dataGridJson->cellHeight;
			col = ((MouseEventArgs^)e)->X / dataGridJson->cellWidth;
		}

		//�Z���̏��擾
		std::vector<std::string>cellData(gridJsonCreator->jsonmanager->getGridData(row, col));
		//�Z���̏��Ƃ���
		array<String^>^ cellinfo_CLI = gcnew array<String^>(cellData.size());
		//�Z���̏��̐������J��Ԃ�(2��)
		for (int i = 0; i < cellData.size(); i++) {
			cellinfo_CLI[i] = gcnew String(cellData[i].c_str());
		}

		//�Z���̏�����͂���t�H�[���̃C���X�^���X�𐶐�
		GridInfo^ gridinfo = gcnew GridInfo();
		//�e����n��
		gridinfo->gridInfo = cellinfo_CLI;
		gridinfo->rowN = row + 1;
		gridinfo->colN = col + 1;
		//�Z���̏������[�_���\��
		gridinfo->ShowDialog();

		cellinfo_CLI = gridinfo->gridInfo;
		cellData = std::vector<std::string>(gridinfo->gridInfo->Length);
		//�R���e���g�L�[�Ɛe�̃L�[�̂ݎ擾
		for (int i = 0; i < gridinfo->gridInfo->Length; i++) {
			//������ւ̕ϊ�
			cellData[i] = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(cellinfo_CLI[i]).ToPointer();
		}

		//���͂��ꂽ�f�[�^���O���b�h�Ǘ��N���X�ɃZ�b�g
		gridJsonCreator->jsonmanager->setGridData(row, col, cellData);

		GridtabPage->AutoScrollPosition = Point(nowX, -nowY);
	}

			 //�Z���ȊO�̕������N���b�N�����ۂ̃C�x���g
	private: System::Void GridtabPage_Click(System::Object^  sender, System::EventArgs^  e) {
		//�J�����g�̃Z����\�����Ȃ������ɂ���
		dataGridJson->drawCell(dataGridJson->currentCell, Brushes::White);
		dataGridJson->currentCell->col = -1;
		dataGridJson->currentCell->row = -1;
		//�\������Ă���Ƃ���ȊO���N���b�N���ꂽ���Ƃɂ���
		dataGridJson->cell_click(dataGridJson->currentCell->row, dataGridJson->currentCell->col);
		pictureBox1->Invalidate();
	}

	};
};