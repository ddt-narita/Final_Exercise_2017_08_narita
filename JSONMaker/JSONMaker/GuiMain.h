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
			this->buttonEnv->Font = (gcnew System::Drawing::Font(L"�l�r �o�S�V�b�N", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->buttonEnv->Location = System::Drawing::Point(578, 6);
			this->buttonEnv->Name = L"buttonEnv";
			this->buttonEnv->Size = System::Drawing::Size(75, 23);
			this->buttonEnv->TabIndex = 1;
			this->buttonEnv->Text = L"��{";
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
			this->labelInsertFrontBack->Text = L"�O";
			// 
			// buttonJsonCreate
			// 
			this->buttonJsonCreate->Location = System::Drawing::Point(410, 48);
			this->buttonJsonCreate->Name = L"buttonJsonCreate";
			this->buttonJsonCreate->Size = System::Drawing::Size(54, 33);
			this->buttonJsonCreate->TabIndex = 7;
			this->buttonJsonCreate->Text = L"�쐬";
			this->buttonJsonCreate->UseVisualStyleBackColor = true;
			this->buttonJsonCreate->Click += gcnew System::EventHandler(this, &GuiMain::buttonJsonCreate_Click);
			// 
			// buttonChangeFrontBack
			// 
			this->buttonChangeFrontBack->Location = System::Drawing::Point(411, 9);
			this->buttonChangeFrontBack->Name = L"buttonChangeFrontBack";
			this->buttonChangeFrontBack->Size = System::Drawing::Size(53, 33);
			this->buttonChangeFrontBack->TabIndex = 22;
			this->buttonChangeFrontBack->Text = L"�}���@�O/���";
			this->buttonChangeFrontBack->UseVisualStyleBackColor = true;
			this->buttonChangeFrontBack->Click += gcnew System::EventHandler(this, &GuiMain::buttonFrontBack_Click);
			// 
			// buttonOpen
			// 
			this->buttonOpen->Location = System::Drawing::Point(353, 48);
			this->buttonOpen->Name = L"buttonOpen";
			this->buttonOpen->Size = System::Drawing::Size(52, 33);
			this->buttonOpen->TabIndex = 21;
			this->buttonOpen->Text = L"�W�J";
			this->buttonOpen->UseVisualStyleBackColor = true;
			this->buttonOpen->Click += gcnew System::EventHandler(this, &GuiMain::OpenDialogButtons_Click);
			// 
			// buttonDetail
			// 
			this->buttonDetail->Location = System::Drawing::Point(353, 9);
			this->buttonDetail->Name = L"buttonDetail";
			this->buttonDetail->Size = System::Drawing::Size(52, 33);
			this->buttonDetail->TabIndex = 20;
			this->buttonDetail->Text = L"�ڍ�";
			this->buttonDetail->UseVisualStyleBackColor = true;
			this->buttonDetail->Click += gcnew System::EventHandler(this, &GuiMain::OpenDialogButtons_Click);
			// 
			// buttonColRemove
			// 
			this->buttonColRemove->Location = System::Drawing::Point(293, 48);
			this->buttonColRemove->Name = L"buttonColRemove";
			this->buttonColRemove->Size = System::Drawing::Size(54, 33);
			this->buttonColRemove->TabIndex = 19;
			this->buttonColRemove->Text = L"��폜";
			this->buttonColRemove->UseVisualStyleBackColor = true;
			this->buttonColRemove->Click += gcnew System::EventHandler(this, &GuiMain::RemoveButtons_Click);
			// 
			// buttonColInsert
			// 
			this->buttonColInsert->Location = System::Drawing::Point(293, 9);
			this->buttonColInsert->Name = L"buttonColInsert";
			this->buttonColInsert->Size = System::Drawing::Size(54, 33);
			this->buttonColInsert->TabIndex = 18;
			this->buttonColInsert->Text = L"��}��";
			this->buttonColInsert->UseVisualStyleBackColor = true;
			this->buttonColInsert->Click += gcnew System::EventHandler(this, &GuiMain::InsertButtons_Click);
			// 
			// buttonRowRemove
			// 
			this->buttonRowRemove->Location = System::Drawing::Point(233, 48);
			this->buttonRowRemove->Name = L"buttonRowRemove";
			this->buttonRowRemove->Size = System::Drawing::Size(54, 33);
			this->buttonRowRemove->TabIndex = 17;
			this->buttonRowRemove->Text = L"�s�폜";
			this->buttonRowRemove->UseVisualStyleBackColor = true;
			this->buttonRowRemove->Click += gcnew System::EventHandler(this, &GuiMain::RemoveButtons_Click);
			// 
			// buttonRowInsert
			// 
			this->buttonRowInsert->Location = System::Drawing::Point(233, 9);
			this->buttonRowInsert->Name = L"buttonRowInsert";
			this->buttonRowInsert->Size = System::Drawing::Size(54, 33);
			this->buttonRowInsert->TabIndex = 16;
			this->buttonRowInsert->Text = L"�s�}��";
			this->buttonRowInsert->UseVisualStyleBackColor = true;
			this->buttonRowInsert->Click += gcnew System::EventHandler(this, &GuiMain::InsertButtons_Click);
			// 
			// buttonRemove
			// 
			this->buttonRemove->Location = System::Drawing::Point(173, 48);
			this->buttonRemove->Name = L"buttonRemove";
			this->buttonRemove->Size = System::Drawing::Size(54, 33);
			this->buttonRemove->TabIndex = 15;
			this->buttonRemove->Text = L"�폜";
			this->buttonRemove->UseVisualStyleBackColor = true;
			this->buttonRemove->Click += gcnew System::EventHandler(this, &GuiMain::RemoveButtons_Click);
			// 
			// buttonInsert
			// 
			this->buttonInsert->Location = System::Drawing::Point(173, 9);
			this->buttonInsert->Name = L"buttonInsert";
			this->buttonInsert->Size = System::Drawing::Size(54, 33);
			this->buttonInsert->TabIndex = 14;
			this->buttonInsert->Text = L"�}��";
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
			this->labelNodeName->Text = L"�m�[�h��";
			// 
			// GridRowLabel
			// 
			this->GridRowLabel->AutoSize = true;
			this->GridRowLabel->Location = System::Drawing::Point(28, 16);
			this->GridRowLabel->Name = L"GridRowLabel";
			this->GridRowLabel->Size = System::Drawing::Size(22, 12);
			this->GridRowLabel->TabIndex = 0;
			this->GridRowLabel->Text = L"�^�e";
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
			this->GridColLabel->Text = L"���R";
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
		JsonLoader* jsonLoader;						//JSON�ǂݍ��݂Ɋւ���N���X
		GridJSONCreator* gridJsonCreator;			//�ǂ݂��񂾂�쐬�����Z������JSON���쐬����N���X
		JSONDBManager* jsonDbLoader;				//DB�̌��ʂ���Z���ɗ��Ƃ��N���X
		narita::DataGridSelfMade^ dataGridJson;		//�\�N���X
		JSONManager* jsonmanager;					//�e�N���X�̋��L�I�u�W�F�N�g
		int FormType = 0;							//�T�u�t�H�[�����ǂ�����\���l
		ChainData* cellChain;						//�g�b�v�m�[�h�̃Z��
		ChainData::FrontBack _fb;					//�}���̕�����\��
		CLIConstants^ cliconstants;					//CLI�ł̒萔�N���X


		//�O�ɑ}�����邩���ɑ}�����邩��I�����郁���o�̃v���p�e�B�[
		property ChainData::FrontBack frontBack {
			//�Q�b�^�[
			ChainData::FrontBack get() {
				//���̂܂ܕԂ�
				return _fb;
			}
			//�Z�b�^�[
			System::Void set(ChainData::FrontBack fb) {
				//�����̒l���Z�b�g����
				_fb = fb;
				//����ɊY�����镶�������x���ɕ\������
				labelInsertFrontBack->Text = fb == ChainData::Front ? "�O" : "���";
			}
		}

		/*
		*/
		void cellReset() {
			delete cellChain;
			dataGridJson->cell = cellChain = new ChainData();
		}


		/*
		�֐���:LoadJson
		�T�v:JSON��ǂݍ��ޏ������s���֐�
		����:����
		�ԋp�l:����
		�쐬��:9��15��(��)
		�쐬��:���c�C�V
		*/
	private:
		Void LoadJson() {
			try {
				//�ǂݍ��݊J�n
				jsonLoader->init();
				//�ǂ݂���JSON����Z��Q�𔲂��o��
				array<String^>^ Nodes = constants.vectorToArray(jsonLoader->getNodes(jsonmanager->json));
				//�m�[�h��I������t�H�[���̃C���X�^���X���쐬����
				NodeSelectForm^ nodeForm = gcnew NodeSelectForm();
				//�m�[�h�Q���t�H�[���ɓn��
				nodeForm->Nodes = Nodes;
				//�t�H�[�������[�_���\������
				Windows::Forms::DialogResult dr = nodeForm->ShowDialog();

				//�t�H�[���̌��ʂ��L�����Z�����N���b�N���ꂽ�Ȃ�
				if (Windows::Forms::DialogResult::Cancel == dr) {
					//��������߂�
					return;
				}
				cellReset();
				//�ǂݍ��݂��J�n����
				jsonLoader->job(constants.StrToc_str(nodeForm->selectedNode), cellChain);
				//�t�H�[���̃m�[�h���ɑI�����ꂽ�m�[�h��\��
				textBoxNodeName->Text = nodeForm->selectedNode;
				//�`�揈�����s��
				ViewTable();
				//�`��𔽉f������
				pictureBox1->Invalidate();
			}
			catch (std::exception& e) {
				MessageBox::Show(cliconstants->MESSAGE_FAILD_TO_READ_JSON, "�G���[", MessageBoxButtons::OK, MessageBoxIcon::Hand);
			}
		}

		/*
		�֐���:createGrid
		�T�v:�e�L�X�g�{�b�N�X�ɓ��͂��ꂽ�l����\���쐬
		����:int rowN, int colN
		�ԋp�l:����
		�쐬��:10��3��(��)
		�쐬��:���c�C�V
		*/
		System::Void createGrid(int rowN, int colN) {
			//���݂̃g�b�v�̃Z���Ɏq���쐬
			cellChain->addRight(new ChainData());
			//�g�b�v�̃Z���̎q���q�J�����g�Ƃ���
			ChainData* childCurrent = cellChain->right;
			//�^�e�����J��Ԃ�
			for (int i = 0; i < rowN; i++) {
				//�q�J�����g�Ɏq���쐬
				childCurrent->addRight(new ChainData());
				//����𑷃J�����g�Ƃ���
				ChainData* GchildCurrent = childCurrent->right;

				//���R���J��Ԃ�
				for (int j = 0; j < colN; j++) {
					//�Ō�̗�łȂ����
					if (j < colN - 2) {
						//���J�����g�ɒ���쐬
						GchildCurrent->addUnder(new ChainData());
						//���J�����g���Ɉړ�
						GchildCurrent = GchildCurrent->under;
					}
				}
				//�Ō�̍s�łȂ����
				if (i < rowN - 1) {
					//�q�J�����g�ɒ���쐬����
					childCurrent->addUnder(new ChainData());
					//�q�J�����g�����̒�Ɉړ�
					childCurrent = childCurrent->under;
				}
			}
		}


		/*
		�֐���:printGrid
		�T�v:�V�K��JSON���쐬���邽�߂̏������s���֐�
		����:����
		�ԋp�l:����
		�쐬��:9��15��(��)
		�쐬��:���c�C�V
		*/
	private:
		Void printGrid() {
			int rowN;
			int colN;
			try {
				//���͂���Ă���^�e�̒������擾
				rowN = Convert::ToInt32(textBoxRowN->Text);
				//���͂���Ă��郈�R�̒������擾
				colN = Convert::ToInt32(textBoxColN->Text);

				//���͂���Ă���l�̂ǂ��炩��0�Ȃ�
				if (rowN == 0 || colN == 0) {
					//��O�𑗏o
					throw gcnew Exception();
				}
			}
			catch (Exception^) {
				MessageBox::Show(cliconstants->MESSAGE_INVALID_VALUE, "�x��", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				throw gcnew Exception("�^�e���R�ɖ����Ȓl�����͂���Ă��܂��B");
			}
			//�쐬�����邱�Ƃ�OK�L�����Z���Ŋm�F�����
			Windows::Forms::DialogResult dr = MessageBox::Show(rowN.ToString() + "�s" + colN.ToString() + "��ŕ\���쐬���܂�\n��낵���ł���", "", MessageBoxButtons::OKCancel, MessageBoxIcon::Question);
			//�L�����Z���������ꂽ��
			if (Windows::Forms::DialogResult::Cancel == dr) {
				//��������߂�
				return;
			}
			cellReset();
			//�擾�����s�Ɨ�ŕ\���쐬����
			createGrid(rowN, colN);
			//�\��\������
			ViewTable();
		}

		/*
		�֐���:getJSONFromQuery
		�T�v:�N�G���̌��ʂ���JSON���쐬���鏈�����s���֐�
		����:����
		�ԋp�l:����
		�쐬��:9��15��(��)
		�쐬��:���c�C�V
		*/

		   private:Void getJsonFromQuery(ChainData* cell) {
		   	//���b�Z�[�W���쐬
		   	String^ message = gcnew String(jsonmanager->env.DBname.c_str()) + cliconstants->MESSAGE_EXECUTE_QUERY_BEFORE + gcnew String(jsonmanager->env.Query.c_str()) + cliconstants->MESSAGE_EXECUTE_QUERY_BACK;
		   	//���b�Z�[�W�{�b�N�X�ŕ\��
		   	Windows::Forms::DialogResult dr = MessageBox::Show(message, "�m�F", MessageBoxButtons::OKCancel, MessageBoxIcon::Question);
		   	//�L�����Z�����I�����ꂽ��
		   	if(Windows::Forms::DialogResult::Cancel == dr) {
		   		//�֐��̎��s����߂�
		   		return;
		   	}
		   	try {
				cellReset();
		   		//DB�̌��ʓǂݍ��݂��J�n����
		   		jsonDbLoader->run(cell);
		   		//�ǂ݂��񂾃Z���ŕ\���쐬����
		   		ViewTable();
		   	}
		   	//��O�����������Ƃ�
		   	catch (sql::SQLException& e) {
		   		//�G���[��DB�ڑ��Ɋւ�����̂�������
		   		if (e.getErrorCode() == constants.CODE_DB_ERROR) {
		   			//���b�Z�[�W�{�b�N�X�ŕ\��
		   			MessageBox::Show(cliconstants->MESSAGE_FAILED_TO_CONNECT_DB, "�G���[", MessageBoxButtons::OK, MessageBoxIcon::Hand);
		   		
		   		}//MySQL�ւ̐ڑ��Ɋւ���G���[
		   		else if(e.getErrorCode() == constants.CODE_MYSQL_ERROR) {
		   			//���b�Z�[�W�{�b�N�X�ŕ\��
		   			MessageBox::Show(cliconstants->MESSAGE_FAILED_TO_CONNECT_MySQL, "�G���[", MessageBoxButtons::OK, MessageBoxIcon::Hand);					
		   		
		   		}//���O�C���Ɋւ���G���[�̎�
		   		else if(e.getErrorCode() == constants.CODE_ROGIN_ERROR) {
		   			//���b�Z�[�W�{�b�N�X�ŕ\��
		   			MessageBox::Show(cliconstants->MESSAGE_FAILED_TO_ROGIN, "�G���[", MessageBoxButtons::OK, MessageBoxIcon::Hand);
		   		
		   		} //�����ȃN�G���Ɋւ���G���[
		   		else if(e.getErrorCode() == constants.CODE_INVALID_QUERY_ERROR){
		   			//���b�Z�[�W�{�b�N�X�ŕ\��
		   			MessageBox::Show(cliconstants->MESSAGE_INVALID_QUERY, "�G���[", MessageBoxButtons::OK, MessageBoxIcon::Hand);
		   		}
		   		//���@�I�ɊԈ����SQL�̃G���[
		   		else if (e.getErrorCode() == constants.CODE_QUERY_SYNTAX_ERROR) {
		   			//���b�Z�[�W�{�b�N�X�ŕ\��
		   			MessageBox::Show(cliconstants->MESSAGE_QUERY_SYNTAX_ERROR, "�G���[", MessageBoxButtons::OK, MessageBoxIcon::Hand);
		   		}
		   	}
		   }


		   /*
		   �֐���:buttonOK_Click
		   �T�v:OK�{�^���������ꂽ�Ƃ��̃C�x���g
		   ����:�C�x���g�̈���
		   �ԋp�l:����
		   �쐬��:9��15��(��)
		   �쐬��:���c�C�V
		   */
	private:
		System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
			//���C�A�E�g�̍쐬����߂�i�`�悪���������߁j
			this->SuspendLayout();
			//�T�u�t�H�[���Ȃ�
			if (FormType == constants.IS_SUB_FORM) {
				//�t�H�[�������
				this->Close();
				//��������߂�
				return;
			}
			else {
				try {
					//JSON�ǂݍ��݂̎�
					if (jsonmanager->isJSONFilePathSet()) {
						//JSON�ǂݍ��ݏ��������s����
						LoadJson();
					}
					else if (jsonDbLoader->isQuerySet()) {
						//
						getJsonFromQuery(cellChain);
					}
					else {
						//�V�K��JSON���쐬���邽�߂̕\��\�����鏈�������s
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
			//���C�A�E�g�̕\�����J�n����
			this->ResumeLayout(false);
			this->PerformLayout();
		}


		/*
		�֐���:buttonCancel_Click
		�T�v:�L�����Z���{�^�����N���b�N���ꂽ�Ƃ��̃C�x���g
		����:�C�x���g�̈���
		�ԋp�l:����
		�쐬��:9��15��(��)
		�쐬��:���c�C�V
		*/
	private:
		System::Void buttonCancel_Click(System::Object^  sender, System::EventArgs^  e) {
			//�`�揈������U��~
			this->SuspendLayout();
			if (nullptr == cellChain->right) {
				MessageBox::Show(cliconstants->MESSAGE_HAVE_NOT_VIEW_TABLE_YET, "�G���[", MessageBoxButtons::OK, MessageBoxIcon::Hand);
				return;
			}
			System::Windows::Forms::DialogResult result = MessageBox::Show(cliconstants->MESSAGE_ALL_CLEAR, "�x��", MessageBoxButtons::OKCancel, MessageBoxIcon::Exclamation);
			if (result != System::Windows::Forms::DialogResult::OK) {
				return;
			}
			//�t�@�C���p�X���N���A
			jsonmanager->env.JSONFilePath = "";
			//�N�G�����N���A
			jsonmanager->env.Query = "";
			//�e�L�X�g�{�b�N�X���N���A
			textBoxNodeName->Text = "";
			textBoxColN->Text = "";
			textBoxRowN->Text = "";

			//�\�̒l���N���A
			dataGridJson->Clear();

			//�Z���ɐe�����݂��Ȃ��Ƃ���
			if (cellChain->getParents().size() == 0) {
				//���̃Z�����폜����
				delete cellChain;
				//�V���ɍ�蒼���ĕ\�N���X�ɂ��n��
				dataGridJson->cell = cellChain = new ChainData();
			}
			//�Z���ɐe������Ȃ�(�T�u�t�H�[���Ȃ�)
			else {
				//���̃Z���̍폜�֐������s
				cellChain->remove();
			}
			//�s�N�`���[�{�b�N�X���\���ɂ���
			pictureBox1->Visible = false;
			//�`�揈���������Ȃ�
			this->ResumeLayout(false);
			this->PerformLayout();
		}


		/*
		�֐���:buttonJsonCreate_Click
		�T�v:�쐬�{�^���������̃C�x���g
		����:�C�x���g�̈���
		�ԋp�l:�Ȃ�
		�쐬��:10��3��(��)
		�쐬��:���c�C�V
		*/
	private:
		System::Void buttonJsonCreate_Click(System::Object^  sender, System::EventArgs^  e) {
			//�q�����݂��Ȃ��Ƃ�(�q�����݂��Ȃ��Ƃ������Ƃ͂܂��ǂ݂��݂��V�K�̍s��w������Ă��Ȃ�)
			if (nullptr == cellChain->right) {
				//�G���[���b�Z�[�W������
				MessageBox::Show(cliconstants->MESSAGE_HAVE_NOT_VIEW_TABLE_YET, "�G���[", MessageBoxButtons::OK, MessageBoxIcon::Hand);
				//��������߂�
				return;
			}
			//�m�[�h�������͂���Ă��Ȃ�
			if ("" == textBoxNodeName->Text) {
				//�m�[�h������ł��邱�ƂƂ��̂܂ܑ����邩�𕷂�
				MessageBox::Show(cliconstants->MESSAGE_EMPTY_NODE_NAME, "�x��", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			try {
				//�m�[�h���̃e�L�X�g�{�b�N�X�ɓ��͂��ꂽ�l���L�[����
				cellChain->key = constants.StrToc_str(textBoxNodeName->Text);
				//�Z�b�g���ꂽ�l��JSON���쐬����
				gridJsonCreator->job(cellChain);
			}
			//JSON�쐬�ŗ�O�����������Ƃ�
			catch (std::exception& e) {
				//�G���[���b�Z�[�W���擾
				String^ errorMessage = gcnew String(e.what());
				//�f�o�b�O�o�͂���
				System::Diagnostics::Debug::WriteLine(errorMessage);
				//���b�Z�[�W�{�b�N�X�ŃG���[���e��\��
				MessageBox::Show(cliconstants->MESSAGE_CREATE_JSON_ERROR + "\n" + gcnew String(e.what()), "�G���[", MessageBoxButtons::OK, MessageBoxIcon::Hand);
				return;
			}
			//�쐬�������������Ƃ�ʒm
			MessageBox::Show(cliconstants->MESSAGE_CREATED, "�ʒm");
		}

		/*
		�֐���:buttonEnv_Click
		�T�v:��(��{)�{�^�����N���b�N���ꂽ�Ƃ��̃C�x���g
		����:�C�x���g�̈���
		�ԋp�l:�Ȃ�
		�쐬��:9��15��(��)
		�쐬��:���c�C�V
		*/
	private:
		System::Void buttonEnv_Click(System::Object^  sender, System::EventArgs^  e) {
			//���ݒ���̓t�H�[���̃C���X�^���X�𐶐�
			EnvForm^ envform = gcnew EnvForm();
			//���݂̏���n��
			envform->DBName = gcnew String(jsonmanager->env.DBname.c_str());
			envform->JSONFilePath = gcnew String(jsonmanager->getJsonFilePath().c_str());
			envform->Query = gcnew String(jsonmanager->getQuery().c_str());
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
			jsonmanager->setJsonFilePath(filepath);
			//���͂��ꂽ�N�G�����擾����
			std::string query = envform->Query == nullptr ? "" : constants.StrToc_str(envform->Query);
			//�Z�b�g
			jsonmanager->setQuery(query);
			jsonmanager->env.DBname = constants.StrToc_str(envform->DBName == nullptr ? "" : envform->DBName);
		}
		/*
		�֐���:createKeyLabels
		�T�v:�L�[�z�񂩂烉�x���Q���쐬����
		����:array<String^>^ path�@�L�[�Q
		�ԋp�l:����
		�쐬��:10��2��(��)
		�쐬��:���c�C�V
		*/
		System::Void createKeyLabels(array<String^>^ path) {
			//���x���z��̒������n�C�t�������܂߂ăL�[�̐��~�Q�{�P�ɂ���
			array<Label^>^ labels = gcnew array<Label^>(path->Length * 2);
			//���x���z��̃C���f�b�N�X
			int labelIndex = 0;
			//�����̃L�[�z��̒����������J��Ԃ�
			for (int i = 0; i < path->Length; i++) {
				//��ԏ��߂łȂ��Ȃ�i�n�C�t���̃��x�������j
				if (0 != i) {
					//���x���𐶐�����
					labels[labelIndex] = gcnew Label();
					//�傫�����n�C�t�����ɍ��킹��
					labels[labelIndex]->Size = System::Drawing::Size(10, 35);
					//�ʒu���n�C�t���ɍ��킹��
					labels[labelIndex]->Location = Point((i * 80) + 5, 5);
					//���x���Ƀn�C�t������������
					labels[labelIndex]->Text = "\n-";
					//���x���z��̃C���f�b�N�X������
					labelIndex++;
				}//�n�C�t��������

				 //���x�����쐬����
				labels[labelIndex] = gcnew Label();
				//�T�C�Y���L�[�ɍ��킹��
				labels[labelIndex]->Size = System::Drawing::Size(60, 35);
				//�ʒu���L�[�ɍ��킹��
				labels[labelIndex]->Location = Point((i * 80) + 20, 5);
				//���x���ɂ��̎��̃L�[����������
				labels[labelIndex]->Text = path[i];
				//���x�����l�p�ň͂ތ`�ɂ���
				labels[labelIndex]->BorderStyle = BorderStyle::FixedSingle;
				//
				labels[labelIndex]->DoubleClick += gcnew EventHandler(this, &GuiMain::Labels_DoubleClick);
				//���x���̔z��̃C���f�b�N�X������
				labelIndex++;
			}
			//�ł������x���̔z����t�H�[���ɒǉ�����
			this->panel2->Controls->AddRange(labels);
		}
		/*
		�֐���:Labels_DoubleClick
		�T�v:���x���Q�̂����ꂩ���N���b�N���ꂽ�Ƃ��̃C�x���g
		����:�C�x���g�̈���
		�ԋp�l:����
		�쐬��:10��2��
		�쐬��:���c�C�V
		*/
		System::Void Labels_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			//�N���b�N���ꂽ���x�����擾
			Label^ selectedLabel = (Label^)sender;
			//���̃��x���̍��W����I�����ꂽ�Z�������Ԗڂ����擾
			int select = ((selectedLabel->Location.X - 20) / 80);
			//�e�̃L�[�Q���擾����
			std::vector<ChainData*> parents = cellChain->getParents();
			//�ڍ׃t�H�[���̃C���X�^���X�𐶐�����
			GuiMain^ editForm = gcnew GuiMain();
			//�t�H�[���ɑI�����ꂽ�Z����n��
			editForm->cellChain = parents[select];
			editForm->FormType = constants.IS_SUB_FORM;
			//���{�^����������Ȃ��悤�ɂ���
			editForm->buttonEnv->Visible = false;
			//�t�H�[����\��
			editForm->ShowDialog();
			ClearLabels();
			createlabels();

		}
		//���x�����N���A����֐�
		System::Void ClearLabels() {
			int level = cellChain->getParents().size();
			//�\�������郉�x���̐������J��Ԃ�
			for (int i = 0; i < level; i++) {
				//��Ԗڂ����łȂ����
				if (i != 0) {
					//�L�[�Ԃ̃n�C�t���̃��x�����폜
					this->panel2->Controls->Remove(this->GetChildAtPoint(Point((i * 80) + 5, 5)));
				}
				//�L�[�̃��x�����폜����
				this->panel2->Controls->Remove(this->GetChildAtPoint(Point((i * 80) + 20, 5)));
			}
		}

		void createlabels() {
			//�e�Z���Q���擾
			std::vector<ChainData*> parent = cellChain->getParents();
			std::vector<std::string>parentKey(parent.size());
			for (int i = 0; i < parent.size(); i++) {
				parentKey[i] = parent[i]->key;
			}

			//�n���ꂽ�Z���̈�ԏォ�炻�̃Z���܂ł̐e�L�[�Q�z����擾����
			array<String^>^ keyPath = constants.vectorToArray(parentKey);
			//�e�̊K�w�̃L�[����L�[�̘A����\��
			createKeyLabels(keyPath);
		}

		/*
		�֐���:GuiMain_Load
		�T�v:���̃t�H�[���������オ�������ɍs���C�x���g
		����:�C�x���g�̈���
		�ԋp�l:����
		�쐬��:9��15��(��)
		�쐬��:���c�C�V
		*/
	private:
		System::Void GuiMain_Load(System::Object^  sender, System::EventArgs^  e) {
			//�e��N���X�̃C���X�^���X�̍쐬
			jsonLoader = new JsonLoader();
			gridJsonCreator = new GridJSONCreator();
			jsonDbLoader = new JSONDBManager();
			//���L�I�u�W�F�N�g�𐶐�
			jsonmanager = new JSONManager();
			dataGridJson = gcnew narita::DataGridSelfMade(pictureBox1);
			cliconstants = gcnew CLIConstants();

			//���L�I�u�W�F�N�g�����L������
			jsonLoader->jsonmanager = gridJsonCreator->jsonmanager = jsonDbLoader->jsonmanager =  jsonmanager;
			//�\�̃e�L�X�g�{�b�N�X�Ƀ_�u���N���b�N�C�x���g��o�^
			dataGridJson->text->DoubleClick += gcnew EventHandler(this, &GuiMain::pictureBox1_DoubleClick);
			//�Z����\������`��Ώۂ������Ȃ�����
			pictureBox1->Visible = false;
			//JSON���Z�b�g�����null�ł͂Ȃ��Ƃ�(�T�u�t�H�[���̎�)
			if (nullptr != cellChain && cellChain->isValid()) {
				dataGridJson->cell = cellChain;
				//�ǂ݂��񂾃f�[�^�ŕ\��\������
				ViewTable();
				//�s�N�`���[�{�b�N�X��������悤�ɂ���
				pictureBox1->Visible = true;
				//�m�[�h�����e�L�X�g�{�b�N�X��
				textBoxNodeName->Text = gcnew String(cellChain->key.c_str());
				createlabels();
			}
			//�ŏ��̃t�H�[�������グ�Ȃ�
			else {
				//�����o�̃Z���𐶐�����
				cellChain = new ChainData();
				//���̃Z����\�N���X�ɓn��
				dataGridJson->cell = cellChain;
			}
		}

		/*
		�֐���:GuiMain_FormClosed
		�T�v:�t�H�[��������Ƃ��̃C�x���g
		����:�C�x���g�̈���
		�ԋp�l:����
		�쐬��:9��15��(��)
		�쐬��:���c�C�V
		*/
	private:
		System::Void GuiMain_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			//���ʃI�u�W�F�N�g���폜
			delete jsonmanager;
			//JSON�ǂݍ��ݏ����N���X���폜����
			delete jsonLoader;
			//�\����JSON���쐬����N���X���폜
			delete gridJsonCreator;
			//delete jsonDBLoader;
		}

		//�s�N�`���[�{�b�N�X���N���b�N���ꂽ�Ƃ��̃C�x���g
		System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
			int row = ((MouseEventArgs^)e)->Y / dataGridJson->cellHeight;
			int col = ((MouseEventArgs^)e)->X / dataGridJson->cellWidth;
			//���̈ʒu�ɂ��ăN���b�N����
			dataGridJson->cell_click(row, col);
		}

		/*
		�֐���:picture_Box1_DoubleClick
		�T�v:�Z�����_�u���N���b�N���ꂽ�Ƃ��̃C�x���g
		�@�@ �Z���̏���\������
		����:�C�x���g�̈���
		�ԋp�l:����
		�쐬��:9��15��(��)
		�쐬��:���c�C�V
		*/
		System::Void pictureBox1_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			int nowX = panel1->AutoScrollPosition.X;
			int nowY = panel1->AutoScrollPosition.Y;

			int row;
			int col;
			//�I�����ꂽ�Z�����i�[����
			ChainData* selected;

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

			//���ڂ̃Z�����N���b�N���ꂽ�Ƃ��̃C�x���g
			if (cellChain->getCell(row, col)->isObject()) {
				//���ڂ̃Z�����擾
				selected = cellChain->getCell(row, col);
				//���̃Z���ɂ��ēW�J����
				OpenCell(selected);
			}
			//1�s�ڈȊO�̃Z�����N���b�N���ꂽ�Ƃ��̃C�x���g
			else {
				//�I�����ꂽ�Z�����擾
				selected = cellChain->getCell(row, col);
				//�ڍׂ��J��
				OpenDetail(selected);
			}
			//�S�̂�`�悷��
			ViewTable();
			//�\�̕\���𑣂�
			pictureBox1->Invalidate();
			//�X�N���[���̃|�W�V�������t�H�[���\���O�Ɠ����ɂ���
			panel1->AutoScrollPosition = Point(-nowX, -nowY);
		}

		/*
		�֐���:GridTabPage_Click
		�T�v:�Z���ȊO�̕������N���b�N�����Ƃ��̓���
		����:�C�x���g�̈���
		�ԋp�l:����
		�쐬��:9��28��(��)
		�쐬��:���c�C�V
		*/
		System::Void LostFocusFromGrid(System::Object^  sender, System::EventArgs^  e) {
			//�J�����g�̃Z����\�����Ȃ������ɂ���
			dataGridJson->cell_click(-1, -1);
			pictureBox1->Invalidate();
		}

		/*
		�֐���:OpenCell
		�T�v:�I�����ꂽ�Z���ɂ��ēW�J����֐�
		����:ChainData* cell �I�����ꂽ�Z��
		�ԋp�l:����
		�쐬��:9��29��(��)
		�쐬��:���c�C�V
		*/
		System::Void OpenCell(ChainData* cell) {
			//�T�u��ʂ̃C���X�^���X�𐶐�
			GuiMain^ sub = gcnew GuiMain();
			//�����̃Z����n��
			sub->cellChain = cell;
			//���{�^����������Ȃ��悤�ɂ���
			sub->buttonEnv->Visible = false;
			//�T�u�t�H�[���ł��邱�Ƃ��i�[
			sub->FormType = constants.IS_SUB_FORM;
			//�T�u�t�H�[����\������
			sub->ShowDialog();
			//�S�̂�`�悷��
			ViewTable();
		}

		/*
		�֐���:OpenDetail
		�T�v:�����̃Z���ɂ��ďڍ׃_�C�A���O��\������֐�
		����:ChainData* selectedCell�@�I�����ꂽ�Z��
		�ԋp�l:����
		�쐬��:9��29��(��)
		�쐬��:���c�C�V
		*/
		System::Void OpenDetail(ChainData* selectedCell) {
			//�Z���ҏW�t�H�[���̃C���X�^���X�𐶐�
			CellEditForm^ editForm = gcnew CellEditForm();
			//�t�H�[���ɑI�����ꂽ�Z����n��
			editForm->cell = selectedCell;
			//�t�H�[����\������
			editForm->ShowDialog();
			//�S�̂��ĕ`��
			ViewTable();
		}

		/*
		�֐���:InsertButtons_Click
		�T�v:�}���Ɋւ���{�^�����������ꂽ�Ƃ��̃C�x���g
		����:�C�x���g�̈���
		�ԋp�l:����
		�쐬��:9��29��(��)
		�쐬��:���c�C�V
		*/
		System::Void InsertButtons_Click(System::Object^  sender, System::EventArgs^  e) {
			//�}���Ɋ֌W�����{�^�����擾
			Button^ InsertButton = (Button^)sender;
			//�I�𒆂̃Z�����L���Ȓl�̎�
			if (dataGridJson->currentCell->isExist()) {
				//�I������Ă���Z���̍s���擾����
				int row = dataGridJson->currentCell->row;
				//�I������Ă���Z���̗���擾����
				int col = dataGridJson->currentCell->col;
				//�}���{�^������̎�
				if ("buttonInsert" == InsertButton->Name) {
					//�I������Ă���Z�����擾����
					ChainData* selected = cellChain->getCell(row, col);
					//�I������Ă���Z���ɂ��đO���ォ�̒l��n���đ}���������s��
					selected->insert(frontBack);
				}
				//�s�폜�{�^������̎�
				else if ("buttonRowInsert" == InsertButton->Name) {
					//�s�}���������s��
					cellChain->insertRow(row, frontBack);
				}
				//��폜�{�^������̎�
				else if ("buttonColInsert" == InsertButton->Name) {
					//��}���������s��
					cellChain->insertCol(col, frontBack);
				}
				//�S�̂��ĕ`�悷��
				ViewTable();
			}
			//�Z�����I������Ă��Ȃ��Ƃ�
			else {
				//���b�Z�[�W�ł��̂��Ƃ��x��
				MessageBox::Show(cliconstants->MESSAGE_NOT_SELECTED_CELL, "�G���[", MessageBoxButtons::OK, MessageBoxIcon::Hand);
			}
		}

		/*
		�֐���:RemoveButtons_Click
		�T�v:�폜�ɂ������{�^�����N���b�N���ꂽ�Ƃ�
		����:�C�x���g�̈���
		�ԋp�l:����
		�쐬��:9��29��(��)
		�쐬��:���c�C�V
		*/
		System::Void RemoveButtons_Click(System::Object^  sender, System::EventArgs^  e) {
			//�폜�Ɋ֌W�����{�^�����擾
			Button^ RemoveButton = (Button^)sender;

			//�I�𒆂̃Z�����L���Ȓl�̎�
			if (dataGridJson->currentCell->isExist()) {
				//�I������Ă���Z���̍s���擾����
				int row = dataGridJson->currentCell->row;
				//�I������Ă���Z���̗���擾����
				int col = dataGridJson->currentCell->col;

				//�폜�{�^������̎�
				if ("buttonRemove" == RemoveButton->Name) {
					//�I������Ă���Z�����擾����
					ChainData* selectedCell = cellChain->getCell(row, col);
					//�폜�������s��
					selectedCell->remove();
				}
				//�s�폜�{�^������̎�
				else if ("buttonRowRemove" == RemoveButton->Name) {
					//�s�폜�������s��
					cellChain->removeRow(row);
				}
				//��폜�{�^������̎�
				else if ("buttonColRemove" == RemoveButton->Name) {
					//��폜�������s��
					cellChain->removeCol(col);
				}
				else if ("buttonParentRemove" == RemoveButton->Name) {
					ChainData* select = cellChain->getCell(row, col);
					select->removeParent();
				}

				//�폜�����̂őI�𒆂̃Z���ɂ��ă��Z�b�g
				dataGridJson->currentCell->Reset();
				//�S�̂��ĕ`�悷��
				ViewTable();
			}
			//�Z�����I������Ă��Ȃ��Ƃ�
			else {
				//���b�Z�[�W�ł��̂��Ƃ��x��
				MessageBox::Show(cliconstants->MESSAGE_NOT_SELECTED_CELL, "�G���[", MessageBoxButtons::OK, MessageBoxIcon::Hand);
			}
		}

		/*
		�֐���:OpenDialogButtons_Click
		�T�v:�_�C�A���O�\���Ɋւ��{�^�����������ꂽ�Ƃ��̃C�x���g
		����:�C�x���g�̈���
		�ԋp�l:����
		�쐬��:9��29��(��)
		�쐬��:���c�C�V
		*/
		System::Void OpenDialogButtons_Click(System::Object^  sender, System::EventArgs^  e) {
			//�폜�Ɋ֌W�����{�^�����擾
			Button^ OpenDialogButtons = (Button^)sender;
			//�I�𒆂̃Z�����L���Ȓl�̎�
			if (dataGridJson->currentCell->isExist()) {
				//�I������Ă���Z���̍s���擾����
				int row = dataGridJson->currentCell->row;
				//�I������Ă���Z���̗���擾����
				int col = dataGridJson->currentCell->col;

				ChainData* selectedCell = cellChain->getCell(row, col);
				//�W�J�{�^������̎�
				if ("buttonOpen" == OpenDialogButtons->Name) {
					//�I�����ꂽ�Z�����I�u�W�F�N�g�Ȃ�
					if (selectedCell->isObject()) {
						//�W�J�������s��
						OpenCell(selectedCell);
					}
				}
				//�ڍ׃{�^������̎�
				else if ("buttonDetail" == OpenDialogButtons->Name) {
					//�ڍ׃t�H�[���\���������s��
					OpenDetail(selectedCell);
				}
				//�S�̂��ĕ`�悷��
				ViewTable();
			}
			//�Z�����I������Ă��Ȃ��Ƃ�
			else {
				//���b�Z�[�W�ł��̂��Ƃ��x��
				MessageBox::Show(cliconstants->MESSAGE_NOT_SELECTED_CELL, "�G���[", MessageBoxButtons::OK, MessageBoxIcon::Hand);
			}
		}

		/*
		�֐���:ViewTable
		�T�v:�\��\������֐�
		����:����
		�ԋp�l:����
		�쐬��:9��29��(��)
		�쐬��:���c�C�V
		*/
		System::Void ViewTable() {
			//�\�N���X�̕\���֐������s
			dataGridJson->View();
			//���̕\�ɍ��킹���s�����e�L�X�g�{�b�N�X�ɕ\��
			textBoxRowN->Text = dataGridJson->rowCount.ToString();
			//�񐔂��e�L�X�g�{�b�N�X�ɕ\��
			textBoxColN->Text = dataGridJson->colCount.ToString();
			//��ԃg�b�v�̃m�[�h�̃L�[���e�L�X�g�{�b�N�X�ɓ��͂���
			textBoxNodeName->Text = gcnew String(cellChain->key.c_str());
			//�s����̂ǂ��炩��0�̎�
			if (dataGridJson->rowCount == 0 || dataGridJson->colCount == 0) {
				//�\������s�N�`���[�{�b�N�X���\����
				pictureBox1->Visible = false;
			}
			//�s�Ɨ񂪂���Ȃ�
			else {
				//�s�N�`���[�{�b�N�X��\������
				pictureBox1->Visible = true;
			}
		}

		/*
		�֐���:buttonFrontBack_Click
		�T�v:�O���{�^�����N���b�N���ꂽ�Ƃ��A�}���̑O����ύX����
		����:�C�x���g�̈���
		�ԋp�l:����
		�쐬��:10��2��(��)
		�쐬��:���c�C�V
		*/
		System::Void buttonFrontBack_Click(System::Object^  sender, System::EventArgs^  e) {
			//���܂܂ł��O�Ȃ���ɁA��낾�����Ȃ�O�ɕς���
			frontBack = (ChainData::Front == frontBack ? ChainData::Back : ChainData::Front);
		}

		/*
		�֐���:textBoxNodename_TextChanged
		�T�v:�m�[�h������͂���e�L�X�g�{�b�N�X�̒l���ω������Ƃ��g�b�v�̃Z���̃L�[�ɂ��̒l����͂���
		����:�C�x���g�̈���
		�ԋp�l:����
		�쐬��:10��3��(��)
		�쐬��:���c�C�V
		*/
		System::Void textBoxNodeName_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			//�g�b�v�̃Z���̃L�[�ɑ������
			cellChain->key = constants.StrToc_str(textBoxNodeName->Text);
		}
};
};