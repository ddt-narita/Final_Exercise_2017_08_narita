#pragma once

namespace JSONMaker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// GridRowInfo �̊T�v
	/// </summary>
	public ref class GridRowInfo : public System::Windows::Forms::Form
	{
	public:
		GridRowInfo(void)
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
		~GridRowInfo()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^  labelRowNumber;
	private: System::Windows::Forms::DataGridView^  dataGridViewRowInfo;
	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::Button^  buttonCancel;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;



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
			this->labelRowNumber = (gcnew System::Windows::Forms::Label());
			this->dataGridViewRowInfo = (gcnew System::Windows::Forms::DataGridView());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewRowInfo))->BeginInit();
			this->SuspendLayout();
			// 
			// labelRowNumber
			// 
			this->labelRowNumber->AutoSize = true;
			this->labelRowNumber->Font = (gcnew System::Drawing::Font(L"�l�r �o�S�V�b�N", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelRowNumber->Location = System::Drawing::Point(43, 25);
			this->labelRowNumber->Name = L"labelRowNumber";
			this->labelRowNumber->Size = System::Drawing::Size(0, 15);
			this->labelRowNumber->TabIndex = 1;
			// 
			// dataGridViewRowInfo
			// 
			this->dataGridViewRowInfo->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewRowInfo->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Column1 });
			this->dataGridViewRowInfo->Location = System::Drawing::Point(12, 54);
			this->dataGridViewRowInfo->Name = L"dataGridViewRowInfo";
			this->dataGridViewRowInfo->RowTemplate->Height = 21;
			this->dataGridViewRowInfo->Size = System::Drawing::Size(290, 158);
			this->dataGridViewRowInfo->TabIndex = 2;
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(32, 248);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 23);
			this->buttonOK->TabIndex = 3;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &GridRowInfo::buttonOK_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(191, 248);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 4;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"�s�̐e�L�[";
			this->Column1->Name = L"Column1";
			// 
			// GridRowInfo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(318, 283);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->dataGridViewRowInfo);
			this->Controls->Add(this->labelRowNumber);
			this->Name = L"GridRowInfo";
			this->Text = L"�s�ɂ�������";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &GridRowInfo::GridRowInfo_FormClosing);
			this->Load += gcnew System::EventHandler(this, &GridRowInfo::GridRowInfo_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewRowInfo))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		//�s�̏���ۊǂ��郁���o
		array<String^>^ _gridRowInfo;
		//�s���̃����o
		int _rowN;
	public:
		//�s�̏��v���p�e�B�[
		property array<String^>^ gridRowInfo {
			array<String^>^ get() {
				return _gridRowInfo;
			}

			void set(array<String^>^ temp) {
				int len = temp->Length;
				_gridRowInfo = gcnew array<String^>(len);

				for (int i = 0; i < len; i++) {
					_gridRowInfo[i] = temp[i];
				}

			}
		}
		//�s���̃v���p�e�B�[
		property int rowNumber {
			int get() {
				return _rowN;
			}
			void set(int n) {
				_rowN = n;
			}
		}

	//�t�H�[�����\�������Ƃ��Ɏ��s�����֐�
	private: System::Void GridRowInfo_Load(System::Object^  sender, System::EventArgs^  e) {
		//�����o�ɓn���ꂽ���̔z��̒������擾
		int rowLen = gridRowInfo->Length;

		//���̐������J��Ԃ�
		for (int i = 0; i < rowLen; i++) {
			//�t�H�[���̏��\�����ɏ��ɒǉ����Ă���
			this->dataGridViewRowInfo->Rows->Add(gridRowInfo[i]);
		}
		//���s�ڂ̏�񂩂�\������
		labelRowNumber->Text = rowNumber.ToString() + "�s�ڂ̏��";
	}


	//OK�{�^���������̃C�x���g
	private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
		//���͂��ꂽ���Q�̍s�����擾
		int rowN = dataGridViewRowInfo->Rows->Count - 1;

		//�����o�ɃZ�b�g����p�̍s���̒����̈ꎞ�z����쐬
		array<String^>^ temp = gcnew array<String^>(rowN);
		//�s�̒����������J��Ԃ�
		for (int i = 0; i < rowN; i++) {
			//���͂���Ă�������ꎞ�z��Ɋi�[
			temp[i] = (String^)(dataGridViewRowInfo->Rows[i]->Cells[0]->Value) == nullptr ? "" : (String^)(dataGridViewRowInfo->Rows[i]->Cells[0]->Value);
		}
		//�����o�ɔ��f
		gridRowInfo = temp;
		//�t�H�[�������
		this->Close();

	}
	private: System::Void GridRowInfo_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		//�s�����擾
		int rowN = dataGridViewRowInfo->Rows->Count;
		//�擾�����s���̒����̔z������
		array<String^>^ temp = gcnew array<String^>(rowN);
		//�����������J��Ԃ�
		for (int i = 0; i < rowN; i++) {
			//�z��Ƀt�H�[���ɓ��͂��ꂽ�l���ꎞ�I�u�W�F�N�g�Ɋi�[
			temp[i] = (String^)(dataGridViewRowInfo->Rows[i]->Cells[0]->Value) == nullptr ? "" : (String^)(dataGridViewRowInfo->Rows[i]->Cells[0]->Value);
		}
		//�����o�ɕۑ����ă��C���t�H�[���ɕԂ��B
		gridRowInfo = temp;
	}
};
}
