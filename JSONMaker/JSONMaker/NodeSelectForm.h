#pragma once

namespace JSONMaker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// NodeSelectForm �̊T�v
	/// </summary>
	public ref class NodeSelectForm : public System::Windows::Forms::Form
	{
	public:
		NodeSelectForm(void)
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
		~NodeSelectForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckedListBox^  checkedListBox1;
	private: System::Windows::Forms::Button^  buttonOK;
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
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->Font = (gcnew System::Drawing::Font(L"�l�r �o�S�V�b�N", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Location = System::Drawing::Point(12, 45);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(264, 214);
			this->checkedListBox1->TabIndex = 0;
			this->checkedListBox1->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &NodeSelectForm::checkedListBox1_ItemCheck);
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(12, 16);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 23);
			this->buttonOK->TabIndex = 1;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &NodeSelectForm::buttonOK_Click);
			// 
			// NodeSelectForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(288, 271);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->checkedListBox1);
			this->Name = L"NodeSelectForm";
			this->Text = L"NodeSelectForm";
			this->Load += gcnew System::EventHandler(this, &NodeSelectForm::NodeSelectForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	public:array<String^>^ Items;
	public:String^ Node;

	private: System::Void NodeSelectForm_Load(System::Object^  sender, System::EventArgs^  e) {
		checkedListBox1->Items->AddRange(Items);
	}


	private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
		Node = checkedListBox1->CheckedItems[0]->ToString();
		this->Close();
	}
	private: System::Void checkedListBox1_ItemCheck(System::Object^  sender, System::Windows::Forms::ItemCheckEventArgs^  e) {
		for (int i = 0; i < checkedListBox1->CheckedItems->Count; i++) {
			if (i != e->Index) {
				checkedListBox1->SetItemChecked(i, false);
			}
		}

	}
	};
}
