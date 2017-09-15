#pragma once

namespace JSONMaker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// EnvForm �̊T�v
	/// </summary>
	public ref class EnvForm : public System::Windows::Forms::Form
	{
	public:
		EnvForm(void)
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
		~EnvForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  labelDB;
	private: System::Windows::Forms::Label^  labelJSONName;
	private: System::Windows::Forms::Label^  labelQuery;
	private: System::Windows::Forms::TextBox^  textBoxDBName;

	protected:



	private: System::Windows::Forms::TextBox^  textBoxJSONName;
	private: System::Windows::Forms::TextBox^  textBoxQuery;
	private: System::Windows::Forms::Button^  buttonOK;



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
			this->labelDB = (gcnew System::Windows::Forms::Label());
			this->labelJSONName = (gcnew System::Windows::Forms::Label());
			this->labelQuery = (gcnew System::Windows::Forms::Label());
			this->textBoxDBName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxJSONName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxQuery = (gcnew System::Windows::Forms::TextBox());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// labelDB
			// 
			this->labelDB->AutoSize = true;
			this->labelDB->Font = (gcnew System::Drawing::Font(L"�l�r �o�S�V�b�N", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelDB->Location = System::Drawing::Point(47, 35);
			this->labelDB->Name = L"labelDB";
			this->labelDB->Size = System::Drawing::Size(45, 15);
			this->labelDB->TabIndex = 0;
			this->labelDB->Text = L"DB��";
			// 
			// labelJSONName
			// 
			this->labelJSONName->AutoSize = true;
			this->labelJSONName->Font = (gcnew System::Drawing::Font(L"�l�r �o�S�V�b�N", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelJSONName->Location = System::Drawing::Point(27, 95);
			this->labelJSONName->Name = L"labelJSONName";
			this->labelJSONName->Size = System::Drawing::Size(65, 15);
			this->labelJSONName->TabIndex = 1;
			this->labelJSONName->Text = L"JSON��";
			// 
			// labelQuery
			// 
			this->labelQuery->AutoSize = true;
			this->labelQuery->Font = (gcnew System::Drawing::Font(L"�l�r �o�S�V�b�N", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelQuery->Location = System::Drawing::Point(47, 162);
			this->labelQuery->Name = L"labelQuery";
			this->labelQuery->Size = System::Drawing::Size(46, 15);
			this->labelQuery->TabIndex = 2;
			this->labelQuery->Text = L"�N�G��";
			// 
			// textBoxDBName
			// 
			this->textBoxDBName->Location = System::Drawing::Point(109, 35);
			this->textBoxDBName->Name = L"textBoxDBName";
			this->textBoxDBName->Size = System::Drawing::Size(223, 19);
			this->textBoxDBName->TabIndex = 3;
			// 
			// textBoxJSONName
			// 
			this->textBoxJSONName->Location = System::Drawing::Point(109, 95);
			this->textBoxJSONName->Name = L"textBoxJSONName";
			this->textBoxJSONName->Size = System::Drawing::Size(223, 19);
			this->textBoxJSONName->TabIndex = 4;
			this->textBoxJSONName->DoubleClick += gcnew System::EventHandler(this, &EnvForm::textBoxJSONName_DoubleClick);
			// 
			// textBoxQuery
			// 
			this->textBoxQuery->Location = System::Drawing::Point(109, 162);
			this->textBoxQuery->Name = L"textBoxQuery";
			this->textBoxQuery->Size = System::Drawing::Size(223, 19);
			this->textBoxQuery->TabIndex = 5;
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(358, 154);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 23);
			this->buttonOK->TabIndex = 6;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &EnvForm::buttonOK_Click);
			// 
			// EnvForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(445, 204);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->textBoxQuery);
			this->Controls->Add(this->textBoxJSONName);
			this->Controls->Add(this->textBoxDBName);
			this->Controls->Add(this->labelQuery);
			this->Controls->Add(this->labelJSONName);
			this->Controls->Add(this->labelDB);
			this->Name = L"EnvForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"EnvForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: 
	String^ _JSONFilePath;
	String^ _DBName;
	String^ _Query;

public:
	property String^ JSONFilePath {
		String^ get() {
			return _JSONFilePath;
		}

		void  set(String^ path) {
			_JSONFilePath = path;
		}
	}

	property String^ DBName {
		String^ get() {
			return _DBName;
		}

		void  set(String^ dbName) {
			_DBName = dbName;
		}
	}

	property String^ Query {
		String^ get() {
			return _Query;
		}

		void  set(String^ query) {
			_Query = query;
		}
	}


private: System::Void textBoxJSONName_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
	
	//�G�N�X�v���[���[���J�����߂̃C���X�^���X�𐶐�
	OpenFileDialog^ fileDialog = gcnew OpenFileDialog();

	//�t�B���^�[��ݒ�
	fileDialog->Filter = "JSON�t�@�C��(*.json;*.txt)|*.json;*.txtl|���ׂẴt�@�C��(*.*)|*.*";
	//2�Ԗڂ́u���ׂẴt�@�C���v���I������Ă���悤�ɂ���
	fileDialog->FilterIndex = 2;
	//�^�C�g����ݒ肷��
	fileDialog->Title = "�J���t�@�C����I�����Ă�������";
	//�_�C�A���O�{�b�N�X�����O�Ɍ��݂̃f�B���N�g���𕜌�����悤�ɂ���
	fileDialog->RestoreDirectory = true;

	String^ filepath;
	//�_�C�A���O��\������
	if (fileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		//OK�{�^�����N���b�N���ꂽ�Ƃ��A�t�@�C���p�X���擾
		filepath = (fileDialog->FileName);
	}
	
	//�擾�����t�@�C���p�X���O������A�N�Z�X�ł���悤�Ƀv���p�e�B�ɃZ�b�g
	JSONFilePath = filepath;
	//�e�L�X�g�{�b�N�X�ɕ\��
	textBoxJSONName->Text = filepath;
}
		 
private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
	
	JSONFilePath = textBoxJSONName->Text;
	Query = textBoxQuery->Text;

	this->Close();
}
};
}
