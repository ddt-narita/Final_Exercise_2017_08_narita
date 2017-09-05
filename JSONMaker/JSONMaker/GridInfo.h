#pragma once

namespace JSONMaker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// GridInfo �̊T�v
	/// </summary>
	public ref class GridInfo : public System::Windows::Forms::Form
	{
	public:
		GridInfo(void)
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
		~GridInfo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  labelParentKey;
	private: System::Windows::Forms::Label^  labelContentKey;
	private: System::Windows::Forms::TextBox^  textBoxParentKey;
	private: System::Windows::Forms::TextBox^  textBoxContentKey;
	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::Button^  buttonCancel;
	private: System::Windows::Forms::Label^  labelMatrix;

	protected:

	protected:




	protected:

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
			this->labelParentKey = (gcnew System::Windows::Forms::Label());
			this->labelContentKey = (gcnew System::Windows::Forms::Label());
			this->textBoxParentKey = (gcnew System::Windows::Forms::TextBox());
			this->textBoxContentKey = (gcnew System::Windows::Forms::TextBox());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->labelMatrix = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labelParentKey
			// 
			this->labelParentKey->AutoSize = true;
			this->labelParentKey->Location = System::Drawing::Point(55, 50);
			this->labelParentKey->Name = L"labelParentKey";
			this->labelParentKey->Size = System::Drawing::Size(47, 12);
			this->labelParentKey->TabIndex = 0;
			this->labelParentKey->Text = L"�e�̃L�[";
			// 
			// labelContentKey
			// 
			this->labelContentKey->AutoSize = true;
			this->labelContentKey->Location = System::Drawing::Point(41, 99);
			this->labelContentKey->Name = L"labelContentKey";
			this->labelContentKey->Size = System::Drawing::Size(69, 12);
			this->labelContentKey->TabIndex = 1;
			this->labelContentKey->Text = L"�R���e���c�L�[";
			// 
			// textBoxParentKey
			// 
			this->textBoxParentKey->Location = System::Drawing::Point(116, 47);
			this->textBoxParentKey->Name = L"textBoxParentKey";
			this->textBoxParentKey->Size = System::Drawing::Size(122, 19);
			this->textBoxParentKey->TabIndex = 2;
			// 
			// textBoxContentKey
			// 
			this->textBoxContentKey->Location = System::Drawing::Point(116, 96);
			this->textBoxContentKey->Name = L"textBoxContentKey";
			this->textBoxContentKey->Size = System::Drawing::Size(122, 19);
			this->textBoxContentKey->TabIndex = 3;
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(35, 150);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 23);
			this->buttonOK->TabIndex = 4;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &GridInfo::buttonOK_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonCancel->Location = System::Drawing::Point(198, 150);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 5;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// labelMatrix
			// 
			this->labelMatrix->AutoSize = true;
			this->labelMatrix->Location = System::Drawing::Point(33, 19);
			this->labelMatrix->Name = L"labelMatrix";
			this->labelMatrix->Size = System::Drawing::Size(0, 12);
			this->labelMatrix->TabIndex = 6;
			// 
			// GridInfo
			// 
			this->AcceptButton = this->buttonOK;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->buttonCancel;
			this->ClientSize = System::Drawing::Size(323, 198);
			this->Controls->Add(this->labelMatrix);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->textBoxContentKey);
			this->Controls->Add(this->textBoxParentKey);
			this->Controls->Add(this->labelContentKey);
			this->Controls->Add(this->labelParentKey);
			this->Name = L"GridInfo";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"GridInfo";
			this->Load += gcnew System::EventHandler(this, &GridInfo::GridInfo_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private:
		String^ _key;
		String^ _contentKey;
		int _rowN;
		int _colN;

public:
		property String^ key
		{
			String^ get()
			{
				return _key;
			}

			void set(String^ temp)
			{
				_key = temp;
			}
		}

		property String^ contentKey
		{
			String^ get()
			{
				return _contentKey;
			}

			void set(String^ temp)
			{
				_contentKey = temp;
			}
		}

		property int rowN {
			int get() {
				return _rowN;
			}

			void set(int rown) {
				_rowN = rown;
			}
		}

		property int colN {
			int get() {
				return _colN;
			}

			void set(int coln) {
				_colN = coln;
			}
		}

	private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
		this->contentKey = textBoxContentKey->Text;
		this->key = textBoxParentKey->Text;
		this->Close();
	}

//
private: System::Void GridInfo_Load(System::Object^  sender, System::EventArgs^  e) {
	this->textBoxContentKey->Text = this->contentKey;
	this->textBoxParentKey->Text = this->key;
	this->labelMatrix->Text = this->rowN.ToString() + "�s�A" + this->colN.ToString() + "��̏��";
}
};
}
