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
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
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
			this->Name = L"NodeSelectForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"NodeSelectForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &NodeSelectForm::NodeSelectForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &NodeSelectForm::NodeSelectForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	public:array<String^>^ Items;
	public:String^ Node;
	public: array<RadioButton^>^ radiobuttons;

			/*
			�֐���:NodeSelectForm_Load
			�T�v:���̃t�H�[���������オ�鎞�ɍs������
			����:�C�x���g�̈���
			�ԋp�l:����
			�쐬��:9��15��(��)
			�쐬��:���c�C�V
			*/
	private: System::Void NodeSelectForm_Load(System::Object^  sender, System::EventArgs^  e) {
		//�t�H�[���ɓn���ꂽ�m�[�h�Q�̐����擾
		int len = Items->Length;
		//���W�I�{�^���̔z��𐶐�
		radiobuttons = gcnew array<RadioButton^>(len);

		//�m�[�h�̐������J��Ԃ�
		for (int i = 0; i < len; i++) {
			//���W�I�{�^���𐶐����Ċe����ǉ�
			radiobuttons[i] = gcnew RadioButton();
			radiobuttons[i]->Text = Items[i];
			radiobuttons[i]->Location = Point(25, buttonOK->Bottom + 10 + (i * 25));
			radiobuttons[i]->BackColor = Color::White;
			//�t�H�[���ɉ�����
			this->Controls->Add(radiobuttons[i]);

		}
	}

			 /*
			 �֐���:buttonOK_Click
			 �T�v:OK�{�^�����N���b�N���ꂽ�Ƃ��̃C�x���g
			 ����:�C�x���g�̈���
			 �ԋp�l:����
			 �쐬��:9��15��(��)
			 �쐬��:���c�C�V
			 */
	private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
		//�I������Ă��Ȃ����W�I�{�^���̐����擾���邽�߂̕ϐ�
		int i;
		//���W�I�{�^���̐������J��Ԃ�
		for (i = 0; i < radiobuttons->Length; i++) {
			//�`�F�b�N����Ă�����
			if (radiobuttons[i]->Checked) {
				//�I�����ꂽ�m�[�h�������o�Ɋi�[����
				Node = radiobuttons[i]->Text;
				//���[�v�𔲂���
				break;
			}
		}
		//�ϐ������W�I�{�^���̐��Ɠ����Ƃ�
		if (i == radiobuttons->Length) {
			//�I������Ă��Ȃ��������Ƃ��x��
			MessageBox::Show("�m�[�h���I������Ă��܂���", "�x��", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		//���W�I�{�^���̐���菬�������
		else {
			//�I�����ꂽ���̂Ƃ��ăt�H�[�������
			this->Close();
		}
	}


			 /*
			 �֐���:NodeSelectForm_FormClosing
			 �T�v:�t�H�[��������Ƃ��ɍs���鏈��
			 ����:�C�x���g�̈���
			 �ԋp�l:����
			 �쐬��:9��15��(��)
			 �쐬��:���c�C�V
			 */
	private: System::Void NodeSelectForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		//�I������Ă��Ȃ����W�I�{�^���̐����擾����ϐ�
		int i;
		//���W�I�{�^���̐������J��Ԃ�
		for (i = 0; i < radiobuttons->Length; i++) {
			//�`�F�b�N����Ă�����
			if (radiobuttons[i]->Checked) {
				//���̃m�[�h�����擾
				Node = radiobuttons[i]->Text;
				//���󂩂����̂Ń��[�v�𔲂���
				break;
			}
		}
		//������ƑI�����ꂽ�m�[�h���݂����Ă��Ȃ����
		if (i == radiobuttons->Length) {
			//�I������Ă��Ȃ����Ƃ��x��
			MessageBox::Show("�m�[�h���I������Ă��܂���", "�x��", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			//�t�H�[�������̂���߂�
			e->Cancel = true;
		}
		
	}
};
}
