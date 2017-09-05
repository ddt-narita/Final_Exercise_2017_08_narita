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
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
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
			// Column1
			// 
			this->Column1->HeaderText = L"Column1";
			this->Column1->Name = L"Column1";
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
			this->Load += gcnew System::EventHandler(this, &GridRowInfo::GridRowInfo_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewRowInfo))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		array<String^>^ _gridRowInfo;
		int _rowN;
	public:
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
		property int rowNumber {
			int get() {
				return _rowN;
			}

			void set(int n) {
				_rowN = n;
			}
		}

	private: System::Void GridRowInfo_Load(System::Object^  sender, System::EventArgs^  e) {
		int rowLen = gridRowInfo->Length;

		for (int i = 0; i < rowLen; i++) {
			this->dataGridViewRowInfo->Rows->Add(gridRowInfo[i]);
		}

		labelRowNumber->Text = rowNumber.ToString() + "�s�ڂ̏��";
	}

//OK�{�^���������̃C�x���g
private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
	int rowN = dataGridViewRowInfo->Rows->Count;

	array<String^>^ temp = gcnew array<String^>(rowN);
	for (int i = 0; i < rowN; i++) {
		temp[i] =  (String^)(dataGridViewRowInfo->Rows[i]->Cells[0]->Value) == nullptr ? "" : (String^)(dataGridViewRowInfo->Rows[i]->Cells[0]->Value);
	}

	gridRowInfo = temp;

	this->Close();

}
};
}
