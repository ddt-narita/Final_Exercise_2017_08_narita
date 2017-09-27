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

	private: System::Windows::Forms::Button^  buttonBindRelease;
	private: System::Windows::Forms::TextBox^  textBoxNodeName;
	private: System::Windows::Forms::Label^  labelNodeName;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  buttonColRemove;

	private: System::Windows::Forms::Button^  buttonColInsert;

	private: System::Windows::Forms::Button^  buttonRowRemove;

	private: System::Windows::Forms::Button^  buttonRowInsert;

	private: System::Windows::Forms::Button^  buttonRemove;
	private: System::Windows::Forms::Button^  butonInsert;










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
			this->buttonColRemove = (gcnew System::Windows::Forms::Button());
			this->buttonColInsert = (gcnew System::Windows::Forms::Button());
			this->buttonRowRemove = (gcnew System::Windows::Forms::Button());
			this->buttonRowInsert = (gcnew System::Windows::Forms::Button());
			this->buttonRemove = (gcnew System::Windows::Forms::Button());
			this->butonInsert = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBoxNodeName = (gcnew System::Windows::Forms::TextBox());
			this->labelNodeName = (gcnew System::Windows::Forms::Label());
			this->buttonBindRelease = (gcnew System::Windows::Forms::Button());
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
			this->tabControl1->Size = System::Drawing::Size(648, 441);
			this->tabControl1->TabIndex = 0;
			// 
			// GridtabPage
			// 
			this->GridtabPage->Controls->Add(this->buttonColRemove);
			this->GridtabPage->Controls->Add(this->buttonColInsert);
			this->GridtabPage->Controls->Add(this->buttonRowRemove);
			this->GridtabPage->Controls->Add(this->buttonRowInsert);
			this->GridtabPage->Controls->Add(this->buttonRemove);
			this->GridtabPage->Controls->Add(this->butonInsert);
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
			// buttonColRemove
			// 
			this->buttonColRemove->Location = System::Drawing::Point(420, 36);
			this->buttonColRemove->Name = L"buttonColRemove";
			this->buttonColRemove->Size = System::Drawing::Size(75, 23);
			this->buttonColRemove->TabIndex = 19;
			this->buttonColRemove->Text = L"��폜";
			this->buttonColRemove->UseVisualStyleBackColor = true;
			// 
			// buttonColInsert
			// 
			this->buttonColInsert->Location = System::Drawing::Point(420, 11);
			this->buttonColInsert->Name = L"buttonColInsert";
			this->buttonColInsert->Size = System::Drawing::Size(75, 23);
			this->buttonColInsert->TabIndex = 18;
			this->buttonColInsert->Text = L"��}��";
			this->buttonColInsert->UseVisualStyleBackColor = true;
			// 
			// buttonRowRemove
			// 
			this->buttonRowRemove->Location = System::Drawing::Point(339, 36);
			this->buttonRowRemove->Name = L"buttonRowRemove";
			this->buttonRowRemove->Size = System::Drawing::Size(75, 23);
			this->buttonRowRemove->TabIndex = 17;
			this->buttonRowRemove->Text = L"�s�폜";
			this->buttonRowRemove->UseVisualStyleBackColor = true;
			// 
			// buttonRowInsert
			// 
			this->buttonRowInsert->Location = System::Drawing::Point(339, 11);
			this->buttonRowInsert->Name = L"buttonRowInsert";
			this->buttonRowInsert->Size = System::Drawing::Size(75, 23);
			this->buttonRowInsert->TabIndex = 16;
			this->buttonRowInsert->Text = L"�s�}��";
			this->buttonRowInsert->UseVisualStyleBackColor = true;
			// 
			// buttonRemove
			// 
			this->buttonRemove->Location = System::Drawing::Point(258, 36);
			this->buttonRemove->Name = L"buttonRemove";
			this->buttonRemove->Size = System::Drawing::Size(75, 23);
			this->buttonRemove->TabIndex = 15;
			this->buttonRemove->Text = L"�폜";
			this->buttonRemove->UseVisualStyleBackColor = true;
			// 
			// butonInsert
			// 
			this->butonInsert->Location = System::Drawing::Point(258, 11);
			this->butonInsert->Name = L"butonInsert";
			this->butonInsert->Size = System::Drawing::Size(75, 23);
			this->butonInsert->TabIndex = 14;
			this->butonInsert->Text = L"�}��";
			this->butonInsert->UseVisualStyleBackColor = true;
			this->butonInsert->Click += gcnew System::EventHandler(this, &GuiMain::butonInsert_Click);
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
			this->panel1->Click += gcnew System::EventHandler(this, &GuiMain::GridtabPage_Click);
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
			// buttonBindRelease
			// 
			this->buttonBindRelease->Location = System::Drawing::Point(177, 36);
			this->buttonBindRelease->Name = L"buttonBindRelease";
			this->buttonBindRelease->Size = System::Drawing::Size(75, 23);
			this->buttonBindRelease->TabIndex = 10;
			this->buttonBindRelease->Text = L"�����^����";
			this->buttonBindRelease->UseVisualStyleBackColor = true;
			this->buttonBindRelease->Click += gcnew System::EventHandler(this, &GuiMain::buttonBindRelease_Click);
			// 
			// buttonJsonCreate
			// 
			this->buttonJsonCreate->Location = System::Drawing::Point(177, 11);
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
			this->GridRowLabel->Location = System::Drawing::Point(28, 16);
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
			jsonLoader->job(StrToc_str(nodeForm->selectedNode));
			//�t�H�[���̃m�[�h���ɑI�����ꂽ�m�[�h��\��
			textBoxNodeName->Text = nodeForm->selectedNode;
			//�ǂ݂��񂾃f�[�^��\�ɓn��
			passDataToGrid();
		}
		/*
		�֐���:vectorToArray
		�T�v:vector����Array�ɕϊ����ĕԋp����֐�
		����:vector<string> vec�@�ϊ��������z��
		�ԋp�l:array<String^>^�@�ϊ���̔z��
		�쐬��:9��20��(��)
		�쐬��:���c�C�V
		*/
		array<String^>^ vectorToArray(const std::vector<std::string>& vec) {
			//�ԋp����z����m��
			array<String^>^ retArray = gcnew array<String^>(vec.size());
			//�������J��Ԃ�
			for (int i = 0; i < vec.size(); i++) {
				//�����̔z��̊e�l���}�l�[�W�ɕϊ����č쐬�����ԋp����z��Ɋi�[
				retArray[i] = gcnew String(UTF8toSjis(vec[i]).c_str());
			}
			//�쐬�����z���ԋp����
			return retArray;
		}

		/*
		�֐���:arrayToVector
		�T�v:CLI�z�񂩂�C++�z��ɕϊ�
		�@�@ ���̍�J�t�H�[���̕�����SJIS�Ȃ̂�SON�p��UTF8�ɕϊ�����
		����:array<String^>^ arr CLI�z��
		�ԋp�l:vector<string> C++�z��
		�쐬��:9��21��(��)
		�쐬��:���c�C�V
		*/
		std::vector<std::string> ArrayToVector(array<String^>^ temp) {
			//�ԋp�Ɏg���z��@�����͈����̔z��̒�����
			std::vector<std::string> retVec(temp->Length);
			//�z��̒����������J��Ԃ�
			for (int i = 0; i < temp->Length; i++) {
				//CLI�����񂩂�C++������ɕϊ����AUTF8�ɕϊ����Ċi�[
				retVec[i] = SjistoUTF8(StrToc_str(temp[i]));
			}
			//�z���Ԃ�
			return retVec;
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
			jsonmanager->grid->init(rowN, colN);
			//���͂���Ă��Ȃ������̏��������s��

			dataGridJson->cell->init(rowN, colN);
			//�\�̏c���̒������擾�����l�ɐݒ�
			dataGridJson->rowCount = rowN;
			dataGridJson->colCount = colN;
		}

		/*
		�֐���:getJSONFromQuery
		�T�v:�N�G���̌��ʂ���JSON���쐬���鏈�����s���֐�
		����:����
		�ԋp�l:����
		�쐬��:9��15��(��)
		�쐬��:���c�C�V
		*/
		//private:Void getJSONFromQuery() {
		//	jsonDbLoader->run();
		//	passDataToGrid();
		//}


		/*
		�֐���:passDataToGrid
		�T�v:�������œǂ݂��񂾏���\�ɓn���֐�
		����:����
		�ԋp�l:����
		�쐬��:9��15��(��)
		�쐬��:���c�C�V
		�ύX��:9��20��(��)
		�ύX��:���c�C�V
		���e:�l�����łȂ��L�[�Q���i�[����
		*/
	private:
		void passDataToGrid() {

			int row = jsonmanager->getGridRowLength();
			int col = jsonmanager->getGridColLen();

			dataGridJson->rowCount = row;
			dataGridJson->colCount = col;
			//�Z���N���X������������
			dataGridJson->cell->init(row, col);
			//���C���t�H�[���̍s���񐔂��擾�����ő�̍s���񐔂ɂ���
			textBoxRowN->Text = row.ToString();
			textBoxColN->Text = col.ToString();

			//�s�����J��Ԃ�
			for (int i = 0; i < row; i++) {
				//�񐔕��J��Ԃ�
				for (int j = 0; j < col; j++) {
					//���̈ʒu�ɒl��ۊǂ���
					dataGridJson->cell->setValue(i, j, gcnew String(UTF8toSjis(jsonmanager->getGrid(i, j)).c_str()));
					//�L�[�Q���擾���Ċi�[����
					boost::property_tree::ptree* point = new boost::property_tree::ptree();
					*point = jsonmanager->getGridData(i, j);
					dataGridJson->cell->setCellData(i, j, point);
				}
			}
			//�Z�b�g�����l��\�ɕ\������
			dataGridJson->Paint();
			//�������ł��Ă��Ȃ������̏��������s��

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

			if (FormType == constants.IS_SUB_FORM) {
				PassDataToProcedure();
				jsonmanager->json.clear();
				constants.fileout("subForm OK clicked!\n");
				jsonmanager->json = gridJsonCreator->CreateJSON();
				boost::property_tree::write_json("debug.json", jsonmanager->json);
				*json = jsonmanager->json;
				this->Close();
				return;
			}else{
			try {
				//JSON�ǂݍ��݂̎�
				if (jsonmanager->isJSONFilePathSet()) {
					//JSON�ǂݍ��ݏ��������s����
					LoadJson();
				}
				//else if (jsonDbLoader->isQuerySet()) {
				//	getJsonFromQuery();
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
			//�Z����\��
			dataGridJson->Paint();

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
			//�������̃f�[�^���N���A
			jsonmanager->jsonClear();
			pictureBox1->Visible = false;
			//�`�揈���������Ȃ�
			this->ResumeLayout(false);
			this->PerformLayout();
		}


		void PassDataToProcedure() {
			//�\�̑傫�����擾����
			int rowN = dataGridJson->rowCount;
			int colN = dataGridJson->colCount;
			if (textBoxNodeName->Text == "") {
				MessageBox::Show("�m�[�h�������͂���Ă��܂���", "�x��", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			jsonmanager->grid->Clear();
			jsonmanager->env.setNodeName(StrToc_str(textBoxNodeName->Text));
			//�\�̍s�����J��Ԃ�
			for (int i = 0; i < rowN; i++) {
				//�������ꂽ�s�Ȃ�
				if (dataGridJson->checkBound(i)) {
					//���̎��I������Ă�����擾
					int selectedColFromRow = dataGridJson->cell->getSelectedColFromRow(i);
					//���̈ʒu�̃f�[�^���擾����UTF8�ɕϊ����Ċi�[
					jsonmanager->setGrid(i, selectedColFromRow, SjistoUTF8(StrToc_str(dataGridJson->cell->getValue(i, selectedColFromRow))));
					//�L�[���擾���Ĕz�u
					jsonmanager->setGridData(i, selectedColFromRow, *dataGridJson->cell->getCellData(i, selectedColFromRow));
				}
				//�ʏ�̍s
				else {
					//�\�̗񐔕��J��Ԃ�
					for (int j = 0; j < colN; j++) {
						//���̈ʒu�̒l�擾���ăZ�b�g
						jsonmanager->setGrid(i, j, SjistoUTF8(StrToc_str(dataGridJson->cell->getValue(i, j))));
						boost::property_tree::ptree* p = new boost::property_tree::ptree();
						p = dataGridJson->cell->getCellData(i, j);
						//���̈ʒu�̂���܂ł̃L�[���擾���ăZ�b�g����
						jsonmanager->setGridData(i, j, *(p));

					}
				}
			}
		}


		//�쐬�{�^���������̃C�x���g
	private:
		System::Void buttonJsonCreate_Click(System::Object^  sender, System::EventArgs^  e) {
			//
			jsonmanager->grid->Clear();
			//�\�̃f�[�^���������ɓn��
			PassDataToProcedure();
			//JSON���N���A����
			jsonmanager->json.clear();
			try {
				//�Z�b�g���ꂽ�l��JSON���쐬����
				gridJsonCreator->job();

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
			jsonLoader->jsonmanager = gridJsonCreator->jsonmanager/* = jsonDbLoader->jsonmanager*/ = jsonmanager;
			//�\�̃e�L�X�g�{�b�N�X�Ƀ_�u���N���b�N�C�x���g��o�^
			dataGridJson->text->DoubleClick += gcnew EventHandler(this, &GuiMain::pictureBox1_DoubleClick);
			//�Z����\������`��Ώۂ������Ȃ�����
			pictureBox1->Visible = false;
			//�f�o�b�O���p�̃p�X
			std::string filePath = "C:\\Users\\lenovo\\Documents\\flower\\flower\\WebContent\\source\\national.json";
			//�p�X��ݒ�
			jsonmanager->setJsonFilePath(filePath);

			//JSON���Z�b�g�����null�ł͂Ȃ��Ƃ�(�T�u�t�H�[���̎�)
			if (nullptr != json) {
				//����JSON����������JOSN�ɓn��
				jsonmanager->json = *json;
				//�ǂݍ��݂��J�n����
				jsonLoader->loadJson(jsonmanager->json);
				//�s�̒�����ǂݍ��ݏ�����̒����ɂ���
				jsonmanager->setGridRowLen(jsonmanager->getGridRowLength() + 1);
				//�t�H�[���̃m�[�h���ɑI�����ꂽ�m�[�h��\��
				textBoxNodeName->Text = keyStr;
				//�ǂ݂��񂾃f�[�^��\�ɓn��
				passDataToGrid();
				//�ǂ݂��񂾃f�[�^�ŕ\��\������
				dataGridJson->Paint();
				//�s�N�`���[�{�b�N�X��������悤�ɂ���
				pictureBox1->Visible = true;
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
	private:
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
	private:
		System::Void pictureBox1_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			int nowX = panel1->AutoScrollPosition.X;
			int nowY = panel1->AutoScrollPosition.Y;

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

			//���ڂ̃Z�����N���b�N���ꂽ�Ƃ��̃C�x���g
			if (col == constants.COLUMN_ONE) {
				//���ڂ��N���b�N���ꂽ�Ƃ��̏��������s
				RowHead_DoubleClick(row);
			}
			//1�s�ڈȊO�̃Z�����N���b�N���ꂽ�Ƃ��̃C�x���g
			else {
				//�擾�����s�A��̃Z�����N���b�N���ꂽ�Ƃ��̏��������s����
				Cell_DoubleClick(row, col);
			}
			//�s�����Z�b�g����
			dataGridJson->rowCount = dataGridJson->cell->rowCount;
			//�񐔂��Z�b�g����
			dataGridJson->colCount = dataGridJson->cell->colCount;
			//���̃Z���ɂ��Č��̐F�ŕ`��
			dataGridJson->drawCell(row, col, Brushes::White);
			dataGridJson->Paint();
			//�\�̕\���𑣂�
			pictureBox1->Invalidate();
			//�X�N���[���̃|�W�V�������t�H�[���\���O�Ɠ����ɂ���
			GridtabPage->AutoScrollPosition = Point(-nowX, -nowY);
		}



	private:
		System::Void RowHead_DoubleClick(int row) {
			//�W�J��̃T�u�t�H�[�����쐻����
			GuiMain^ sub = gcnew  GuiMain();
			boost::property_tree::ptree* pt = new boost::property_tree::ptree();
			PassDataToProcedure();
			jsonmanager->json.clear();
			//�S�̂�JSON���쐬����
			*pt = gridJsonCreator->CreateJSON();
			std::string cellName = StrToc_str(dataGridJson->cell->getValue(row, 0));
constants.jsonfileout(*pt);
			*pt = pt->get_child(cellName);
			//JSON��n��
			sub->json = pt;
			//�L�[�ƂȂ�l��n��
			sub->keyStr = this->dataGridJson->cell->getValue(row, 0);
			//�T�u�t�H�[���ł͊��{�^���͎g���Ȃ��悤�ɂ���
			sub->buttonEnv->Visible = false;
			//���̃t�H�[�����T�u�t�H�[���ł��邱�Ƃ������l��n��
			sub->FormType = constants.IS_SUB_FORM;
			//�t�H�[����\������
			sub->ShowDialog();
constants.fileout("\nsubJSON\n");
constants.jsonfileout(*sub->json);
			//�t�H�[����������ۂɍ��ꂽJSON���擾
			boost::property_tree::ptree* subJson = sub->json;
			
			//�󂯎����JSON�̈�ԏ�̃m�[�h�Q���擾����
			int colN = jsonLoader->getNodes(*subJson).size();
			//�t�H�[���\���O��񐔂������Ȃ��Ă�����
			if (colN > jsonmanager->getGridColLen()) {
				//�񐔂����̐��ɃZ�b�g����
				dataGridJson->colCount = colN;
			}
			//foreach���̓��������̂��߂̃��[�v�ϐ�
			int i = 1;
			//�󂯎����JSON�ɂ��Ĕ��f�����邽�ߑ��K�w���[�v
			BOOST_FOREACH(const boost::property_tree::ptree::value_type& child, *subJson) {
				//�L�[��\�����̒l�Ƃ��Ċi�[����
				dataGridJson->cell->setValue(row, i, gcnew String(UTF8toSjis(child.first).c_str()));
				//�v���p�e�B�c���[�̃|�C���^���쐬����
				boost::property_tree::ptree* point = new boost::property_tree::ptree();
				//���̃|�C���^�ɃL�[�ȉ��̃I�u�W�F�N�g���i�[����
				*point = child.second;
constants.jsonfileout(*point);
				//����JSON�I�u�W�F�N�g�ւ̃|�C���^���i�[����
				dataGridJson->cell->setCellData(row, i, point);
				//���̗�ֈړ�����
				i++;
			}
			//�S�̂�`�悷��
			dataGridJson->Paint();
		}

	private:
		System::Void Cell_DoubleClick(int row, int col) {
			//
			boost::property_tree::ptree* jsonObject = dataGridJson->cell->getCellData(row, col);
			//�Z���ҏW�t�H�[���𐶐�����
			CellEditForm^ editForm = gcnew CellEditForm();

			//�ŉ��w�܂Œ��n�̎q�����Ȃ��ꍇ
			if (isStraightJSON(*jsonObject)) {
				//�t�H�[���ɓn���z��
				std::vector<std::string> stdPassData;
				//�擾�����Z����JSON�I�u�W�F�N�g��z��ɒ���
				LoadStraightJSON(*jsonObject, stdPassData);
				//
				editForm->keyArray = vectorToArray(stdPassData);

			}
			//
			else {
				//

			}

		}

	private:
		bool isStraightJSON(boost::property_tree::ptree straightJson) {
			try {
				//�����Ŏ󂯎����JSON���q����2�l�ȏア�Ȃ����̂Ƃ��ēǂ݂���
				LoadStraightJSON(straightJson, std::vector<std::string>());
			}
			//�ǂݍ��ޒ���2�l�ȏア��Ȃǂ̗�O�����������Ƃ�
			catch (std::exception& e) {
				//���n�̎q�������Ȃ�JSON�ł͂Ȃ����Ƃ�ԋp����
				return false;

			}
			//�������Ȃ���Β��n�݂̂�JSON�ł���Ƃ��ĕԋp����
			return true;
		}

		System::Void LoadStraightJSON(boost::property_tree::ptree straightJson, std::vector<std::string> &arr) {
			int i = 0;
			//���K�w�����[�v����
			BOOST_FOREACH(const boost::property_tree::ptree::value_type& child, straightJson) {
				arr.push_back(child.first);
				//
				if (child.second.data() == "") {
					LoadStraightJSON(child.second, arr);
				}
				//���[�v�ϐ����v���X���Ă��̊K�w�̎q�̐��𐔂���
				i++;
				//�ϐ���i�ȏ�̒l�ɂȂ�����
				if (i > 1) {
					throw std::exception("isNotStraight");
				}
			}
		}

		//�Z���ȊO�̕������N���b�N�����ۂ̃C�x���g
	private:
		System::Void GridtabPage_Click(System::Object^  sender, System::EventArgs^  e) {
			//�J�����g�̃Z����\�����Ȃ������ɂ���
			dataGridJson->drawCell(dataGridJson->currentCell, Brushes::White);
			dataGridJson->currentCell->col = -1;
			dataGridJson->currentCell->row = -1;
			pictureBox1->Invalidate();
		}

	private:
		System::Void buttonBindRelease_Click(System::Object^  sender, System::EventArgs^  e) {
			//�I������Ă���s�A��ɂ��Č����������s��
			dataGridJson->BindRelease(dataGridJson->currentCell->row, dataGridJson->currentCell->col);
			pictureBox1->Invalidate();
		}

	private:
		System::Void Column_Head_Click(int row) {



		}



	private: System::Void butonInsert_Click(System::Object^  sender, System::EventArgs^  e) {
		int row = dataGridJson->currentCell->row;
		int col = dataGridJson->currentCell->col;

		dataGridJson->cell->insert(row, col);

		int rowCount = dataGridJson->rowCount;
		int colCount = dataGridJson->colCount;

		for (int i = 0; i < rowCount; i++) {
			if (i != row) {
				CellChain^ endOfLine = dataGridJson->cell->getCell(i, colCount - 1);
				//
				endOfLine->addRight(gcnew CellChain());
			}
		}
		dataGridJson->colCount = colCount + 1;
		jsonmanager->setGridColLen(colCount + 1);

		dataGridJson->Paint();
	}
	};
};