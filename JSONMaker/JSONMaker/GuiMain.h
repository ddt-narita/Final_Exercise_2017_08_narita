#pragma once
#include "GridJSONCreator.h"
//#include "JSONDBManager.h"
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
			this->panel1->SuspendLayout();
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
			this->tabControl1->Size = System::Drawing::Size(685, 538);
			this->tabControl1->TabIndex = 0;
			// 
			// GridtabPage
			// 
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
			this->GridtabPage->Size = System::Drawing::Size(677, 512);
			this->GridtabPage->TabIndex = 0;
			this->GridtabPage->Text = L"Grid";
			this->GridtabPage->UseVisualStyleBackColor = true;
			this->GridtabPage->Click += gcnew System::EventHandler(this, &GuiMain::LostFocusFromGrid);
			// 
			// buttonOpen
			// 
			this->buttonOpen->Location = System::Drawing::Point(378, 48);
			this->buttonOpen->Name = L"buttonOpen";
			this->buttonOpen->Size = System::Drawing::Size(52, 33);
			this->buttonOpen->TabIndex = 21;
			this->buttonOpen->Text = L"�W�J";
			this->buttonOpen->UseVisualStyleBackColor = true;
			this->buttonOpen->Click += gcnew System::EventHandler(this, &GuiMain::OpenDialogButtons_Click);
			// 
			// buttonDetail
			// 
			this->buttonDetail->Location = System::Drawing::Point(378, 9);
			this->buttonDetail->Name = L"buttonDetail";
			this->buttonDetail->Size = System::Drawing::Size(52, 33);
			this->buttonDetail->TabIndex = 20;
			this->buttonDetail->Text = L"�ڍ�";
			this->buttonDetail->UseVisualStyleBackColor = true;
			this->buttonDetail->Click += gcnew System::EventHandler(this, &GuiMain::OpenDialogButtons_Click);
			// 
			// buttonColRemove
			// 
			this->buttonColRemove->Location = System::Drawing::Point(318, 48);
			this->buttonColRemove->Name = L"buttonColRemove";
			this->buttonColRemove->Size = System::Drawing::Size(54, 33);
			this->buttonColRemove->TabIndex = 19;
			this->buttonColRemove->Text = L"��폜";
			this->buttonColRemove->UseVisualStyleBackColor = true;
			this->buttonColRemove->Click += gcnew System::EventHandler(this, &GuiMain::RemoveButtons_Click);
			// 
			// buttonColInsert
			// 
			this->buttonColInsert->Location = System::Drawing::Point(318, 9);
			this->buttonColInsert->Name = L"buttonColInsert";
			this->buttonColInsert->Size = System::Drawing::Size(54, 33);
			this->buttonColInsert->TabIndex = 18;
			this->buttonColInsert->Text = L"��}��";
			this->buttonColInsert->UseVisualStyleBackColor = true;
			this->buttonColInsert->Click += gcnew System::EventHandler(this, &GuiMain::InsertButtons_Click);
			// 
			// buttonRowRemove
			// 
			this->buttonRowRemove->Location = System::Drawing::Point(258, 48);
			this->buttonRowRemove->Name = L"buttonRowRemove";
			this->buttonRowRemove->Size = System::Drawing::Size(54, 33);
			this->buttonRowRemove->TabIndex = 17;
			this->buttonRowRemove->Text = L"�s�폜";
			this->buttonRowRemove->UseVisualStyleBackColor = true;
			this->buttonRowRemove->Click += gcnew System::EventHandler(this, &GuiMain::RemoveButtons_Click);
			// 
			// buttonRowInsert
			// 
			this->buttonRowInsert->Location = System::Drawing::Point(258, 9);
			this->buttonRowInsert->Name = L"buttonRowInsert";
			this->buttonRowInsert->Size = System::Drawing::Size(54, 33);
			this->buttonRowInsert->TabIndex = 16;
			this->buttonRowInsert->Text = L"�s�}��";
			this->buttonRowInsert->UseVisualStyleBackColor = true;
			this->buttonRowInsert->Click += gcnew System::EventHandler(this, &GuiMain::InsertButtons_Click);
			// 
			// buttonRemove
			// 
			this->buttonRemove->Location = System::Drawing::Point(198, 48);
			this->buttonRemove->Name = L"buttonRemove";
			this->buttonRemove->Size = System::Drawing::Size(54, 33);
			this->buttonRemove->TabIndex = 15;
			this->buttonRemove->Text = L"�폜";
			this->buttonRemove->UseVisualStyleBackColor = true;
			this->buttonRemove->Click += gcnew System::EventHandler(this, &GuiMain::RemoveButtons_Click);
			// 
			// buttonInsert
			// 
			this->buttonInsert->Location = System::Drawing::Point(198, 9);
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
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(8, 87);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(661, 417);
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
			// buttonJsonCreate
			// 
			this->buttonJsonCreate->Location = System::Drawing::Point(476, 9);
			this->buttonJsonCreate->Name = L"buttonJsonCreate";
			this->buttonJsonCreate->Size = System::Drawing::Size(54, 33);
			this->buttonJsonCreate->TabIndex = 7;
			this->buttonJsonCreate->Text = L"�쐬";
			this->buttonJsonCreate->UseVisualStyleBackColor = true;
			this->buttonJsonCreate->Click += gcnew System::EventHandler(this, &GuiMain::buttonJsonCreate_Click);
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
			this->buttonCancel->Location = System::Drawing::Point(571, 53);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 5;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &GuiMain::buttonCancel_Click);
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(571, 19);
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
			this->tabPage2->Size = System::Drawing::Size(677, 512);
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
			this->ClientSize = System::Drawing::Size(685, 561);
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
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		JsonLoader* jsonLoader;
		GridJSONCreator* gridJsonCreator;
		//JSONDBManager* jsonDbLoader;
		narita::DataGridSelfMade^ dataGridJson;
		JSONManager* jsonmanager;

		String^ keyStr;
		boost::property_tree::ptree* json;
		int FormType = 0;

		ChainData* cellChain;

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

		/*
		�֐���:
		�T�v:
		����:
		�ԋp�l:
		�쐬��:9��15��(��)
		�쐬��:���c�C�V
		*/
		array<String^>^ getNodes(std::vector<std::string> node) {
			array<String^>^ retArray = gcnew array<String^>(node.size());
			for (int i = 0; i < node.size(); i++) {
				retArray[i] = gcnew String(node[i].c_str());
			}
			return retArray;
		}

		/*
		�֐���:StrToC_str
		�T�v:System::String^����std::string�ɕϊ����ĕԂ��֐�
		����:String^ �ϊ���
		�ԋp�l:string �ϊ���̕�����
		�쐬��:9��15��(��)
		�쐬��:���c�C�V
		*/
		std::string StrToc_str(String^ temp) {
			return (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(temp).ToPointer();
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
				array<String^>^ Nodes = getNodes(jsonLoader->getNodes(jsonmanager->json));
				//�m�[�h��I������t�H�[���̃C���X�^���X���쐬����
				NodeSelectForm^ nodeForm = gcnew NodeSelectForm();

				//�m�[�h�Q���t�H�[���ɓn��
				nodeForm->Nodes = Nodes;
				//�t�H�[�������[�_���\������
				nodeForm->ShowDialog();

				//�ǂݍ��݂��J�n����
				jsonLoader->job(StrToc_str(nodeForm->selectedNode), cellChain);
				//�t�H�[���̃m�[�h���ɑI�����ꂽ�m�[�h��\��
				textBoxNodeName->Text = nodeForm->selectedNode;
				//�ǂ݂��񂾃`�F�[���f�[�^��\�����ɓn��
				dataGridJson->cell = cellChain;
				//�`�揈�����s��
				ViewTable();
				//�`��𔽉f������
				pictureBox1->Invalidate();
			}
			catch (std::exception& e) {
				MessageBox::Show("�t�@�C����ǂ߂��߂܂���ł����B\n�w�肳�ꂽ�t�@�C���ɂ��Č������Ă��������B", "�G���[", MessageBoxButtons::OK, MessageBoxIcon::Hand);
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
			}
			catch (Exception^) {
				MessageBox::Show("���͂���Ă���l�������ł�", "�x��", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				throw gcnew Exception("�^�e���R�ɖ����Ȓl�����͂���Ă��܂��B");
			}
			//���͂���Ă��Ȃ������̏��������s��

			//�\�̏c���̒������擾�����l�ɐݒ�
			dataGridJson->rowCount = rowN;
			dataGridJson->colCount = colN;
			dataGridJson->adjustCell();
			dataGridJson->Paint();
		}

		/*
		�֐���:getJSONFromQuery
		�T�v:�N�G���̌��ʂ���JSON���쐬���鏈�����s���֐�
		����:����
		�ԋp�l:����
		�쐬��:9��15��(��)
		�쐬��:���c�C�V
		*/
		//private:Void getJsonFromQuery(ChainData* cell) {
		//	jsonDbLoader->run(cell);
		//	//�ǂ݂��񂾃`�F�[���f�[�^��\�����ɓn��
		//	dataGridJson->cell = cellChain;
		//	ViewTable();
		//}

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
			if (FormType == constants.IS_SUB_FORM) {
				
				//�t�H�[�������
				this->Close();
				return;
			}
			else {
				try {
					//JSON�ǂݍ��݂̎�
					if (jsonmanager->isJSONFilePathSet()) {
						//JSON�ǂݍ��ݏ��������s����
						LoadJson();
					}
					//else if (jsonDbLoader->isQuerySet()) {
					//	//
					//	getJsonFromQuery(cellChain);
					//}
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

			pictureBox1->Visible = true;
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
				MessageBox::Show("���JSON��ǂݍ��ނ��A\n�s��w�肵�ĕ\���쐬���Ă�������", "�G���[", MessageBoxButtons::OK, MessageBoxIcon::Hand);
				return;
			}
			System::Windows::Forms::DialogResult result = MessageBox::Show("���ׂč폜���܂�\n��낵���ł����H", "�x��", MessageBoxButtons::OKCancel, MessageBoxIcon::Exclamation);
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

			if (nullptr == cellChain->left) {
				delete cellChain;
				cellChain = new ChainData();
			}
			else {
				cellChain->remove();
			}

			pictureBox1->Visible = false;
			//�`�揈���������Ȃ�
			this->ResumeLayout(false);
			this->PerformLayout();
		}


		//�쐬�{�^���������̃C�x���g
	private:
		System::Void buttonJsonCreate_Click(System::Object^  sender, System::EventArgs^  e) {

			//�q�����݂��Ȃ��Ƃ�(�q�����݂��Ȃ��Ƃ������Ƃ͂܂��ǂ݂��݂��V�K�̍s��w������Ă��Ȃ�)
			if (nullptr == cellChain->right) {
				//�G���[���b�Z�[�W������
				MessageBox::Show("���JSON��ǂݍ��ނ��A\n�s��w�肵�ĕ\���쐬���Ă�������", "�G���[", MessageBoxButtons::OK, MessageBoxIcon::Hand);
				//��������߂�
				return;
			}
			//�m�[�h�������͂���Ă��Ȃ�
			if ("" == textBoxNodeName->Text) {
				//�m�[�h������ł��邱�ƂƂ��̂܂ܑ����邩�𕷂�
				System::Windows::Forms::DialogResult result = MessageBox::Show("�m�[�h������ł��B\n���̂܂܍쐬���܂���", "�x��", MessageBoxButtons::OKCancel, MessageBoxIcon::Error);
				//OK�{�^����������Ă��Ȃ����
				if (result != System::Windows::Forms::DialogResult::OK) {
					//��������߂�
					return;
				}
			}

			try {
				//�m�[�h���̃e�L�X�g�{�b�N�X�ɓ��͂��ꂽ�l���L�[����
				cellChain->key = constants.StrToc_str(textBoxNodeName->Text);
				//�Z�b�g���ꂽ�l��JSON���쐬����
				gridJsonCreator->job(cellChain);

			}
			catch (std::exception& e) {
				String^ errorMessage = gcnew String(e.what());
				System::Diagnostics::Debug::WriteLine(errorMessage);
			}
			//�쐬���I�����烁���o��JSON���N���A����
			jsonmanager->json.clear();
			//�쐬�������������Ƃ�ʒm
			MessageBox::Show("JSON�쐬�����I�I", "�ʒm");
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
			std::string query = envform->Query == nullptr ? "" : StrToc_str(envform->Query);
			//�Z�b�g
			jsonmanager->setQuery(query);
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
			//jsonDbLoader = new JSONDBManager();
			//���L�I�u�W�F�N�g�𐶐�
			jsonmanager = new JSONManager();
			dataGridJson = gcnew narita::DataGridSelfMade(pictureBox1);

			//���L�I�u�W�F�N�g�����L������
			jsonLoader->jsonmanager = gridJsonCreator->jsonmanager = /*jsonDbLoader->jsonmanager =*/ jsonmanager;
			//�\�̃e�L�X�g�{�b�N�X�Ƀ_�u���N���b�N�C�x���g��o�^
			dataGridJson->text->DoubleClick += gcnew EventHandler(this, &GuiMain::pictureBox1_DoubleClick);
			//�Z����\������`��Ώۂ������Ȃ�����
			pictureBox1->Visible = false;
			//�f�o�b�O���p�̃p�X
			std::string filePathFlower = "C:\\Users\\lenovo\\Documents\\flower\\flower\\WebContent\\source\\bridal.json";
			std::string filePathObjectArray = "C:\\Users\\lenovo\\Documents\\final_exercise_2017_08_narita\\JSONMaker\\JSONMaker\\objectArray.json";
			std::string filePathArray = "C:\\Users\\lenovo\\Documents\\final_exercise_2017_08_narita\\JSONMaker\\JSONMaker\\array.json";
			//�p�X��ݒ�
			//jsonmanager->setJsonFilePath(filePathFlower);
			jsonmanager->env.Query = "SELECT id, school_key, send_datetime, magazine_type, magazine_title, magazine_content FROM mail_magazine ORDER BY send_datetime DESC";

			//JSON���Z�b�g�����null�ł͂Ȃ��Ƃ�(�T�u�t�H�[���̎�)
			if (nullptr != cellChain && cellChain->isValid()) {
				dataGridJson->cell = cellChain;
				//�ǂ݂��񂾃f�[�^�ŕ\��\������
				ViewTable();
				//�s�N�`���[�{�b�N�X��������悤�ɂ���
				pictureBox1->Visible = true;
				//�m�[�h�����e�L�X�g�{�b�N�X��
				textBoxNodeName->Text = gcnew String(cellChain->key.c_str());
			}
			else {
				cellChain = new ChainData();
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
			if (dataGridJson->checkBound(row)) {
				col = dataGridJson->selectedColFromBoundRow(row);
			}

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
			if (col == constants.COLUMN_ONE && cellChain->getCell(row, col)->isObject()) {
				//���ڂ̃Z�����擾
				selected = cellChain->getCell(row, 0);
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
			dataGridJson->Paint();
			//�\�̕\���𑣂�
			pictureBox1->Invalidate();
			//�X�N���[���̃|�W�V�������t�H�[���\���O�Ɠ����ɂ���
			GridtabPage->AutoScrollPosition = Point(-nowX, -nowY);
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
			if (dataGridJson->currentCell->isValid()) {
				//�I������Ă���Z���̍s���擾����
				int row = dataGridJson->currentCell->row;
				//�I������Ă���Z���̗���擾����
				int col = dataGridJson->currentCell->col;
				//�}���{�^������̎�
				if ("buttonInsert" == InsertButton->Name) {
					//�I������Ă���Z�����擾����
					ChainData* selected = cellChain->getCell(row, col);
					//�I������Ă���Z���ɂ��đ}���������s��
					selected->insertFront();
				}
				//�s�폜�{�^������̎�
				else if ("buttonRowInsert" == InsertButton->Name) {
					//�s�}���������s��
					cellChain->insertRow(row);
				}
				//��폜�{�^������̎�
				else if ("buttonColInsert" == InsertButton->Name) {
					//��}���������s��
					cellChain->insertCol(col);
				}
				//�S�̂��ĕ`�悷��
				ViewTable();
			}
			//�Z�����I������Ă��Ȃ��Ƃ�
			else {
				//���b�Z�[�W�ł��̂��Ƃ��x��
				MessageBox::Show("�Z����I�����Ă�������", "�G���[", MessageBoxButtons::OK, MessageBoxIcon::Hand);
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
			if (dataGridJson->currentCell->isValid()) {
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
				//�폜�����̂őI�𒆂̃Z���ɂ��ă��Z�b�g
				dataGridJson->currentCell->Reset();
				//�S�̂��ĕ`�悷��
				ViewTable();
			}
			//�Z�����I������Ă��Ȃ��Ƃ�
			else {
				//���b�Z�[�W�ł��̂��Ƃ��x��
				MessageBox::Show("�Z����I�����Ă�������", "�G���[", MessageBoxButtons::OK, MessageBoxIcon::Hand);
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
			if (dataGridJson->currentCell->isValid()) {
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
				MessageBox::Show("�Z����I�����Ă�������", "�G���[", MessageBoxButtons::OK, MessageBoxIcon::Hand);
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
	};
};