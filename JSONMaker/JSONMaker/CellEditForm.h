#pragma once
#include "Constants.h"

namespace JSONMaker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// CellEditForm �̊T�v
	/// </summary>
	public ref class CellEditForm : public System::Windows::Forms::Form
	{
	public:
		CellEditForm(void)
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
		~CellEditForm()
		{
			if (components)
			{
				delete components;
			}
		}
	protected: System::Windows::Forms::TextBox^  textBoxKey;
	private: System::Windows::Forms::TextBox^  textBoxValue;
	protected:

	protected:

	protected:

	private: System::Windows::Forms::Label^  labelKey;
	private: System::Windows::Forms::Label^  labelValue;
	private: System::Windows::Forms::Button^  buttonCandel;
	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::Button^  buttonParent;
	private: System::Windows::Forms::Button^  buttonChild;




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
			this->textBoxKey = (gcnew System::Windows::Forms::TextBox());
			this->textBoxValue = (gcnew System::Windows::Forms::TextBox());
			this->labelKey = (gcnew System::Windows::Forms::Label());
			this->labelValue = (gcnew System::Windows::Forms::Label());
			this->buttonCandel = (gcnew System::Windows::Forms::Button());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonParent = (gcnew System::Windows::Forms::Button());
			this->buttonChild = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBoxKey
			// 
			this->textBoxKey->Location = System::Drawing::Point(125, 66);
			this->textBoxKey->Name = L"textBoxKey";
			this->textBoxKey->Size = System::Drawing::Size(100, 19);
			this->textBoxKey->TabIndex = 0;
			// 
			// textBoxValue
			// 
			this->textBoxValue->Location = System::Drawing::Point(125, 104);
			this->textBoxValue->Name = L"textBoxValue";
			this->textBoxValue->Size = System::Drawing::Size(100, 19);
			this->textBoxValue->TabIndex = 1;
			// 
			// labelKey
			// 
			this->labelKey->AutoSize = true;
			this->labelKey->Location = System::Drawing::Point(49, 69);
			this->labelKey->Name = L"labelKey";
			this->labelKey->Size = System::Drawing::Size(37, 12);
			this->labelKey->TabIndex = 2;
			this->labelKey->Text = L"�L�[��";
			// 
			// labelValue
			// 
			this->labelValue->AutoSize = true;
			this->labelValue->Location = System::Drawing::Point(49, 107);
			this->labelValue->Name = L"labelValue";
			this->labelValue->Size = System::Drawing::Size(17, 12);
			this->labelValue->TabIndex = 3;
			this->labelValue->Text = L"�l";
			// 
			// buttonCandel
			// 
			this->buttonCandel->Location = System::Drawing::Point(187, 185);
			this->buttonCandel->Name = L"buttonCandel";
			this->buttonCandel->Size = System::Drawing::Size(75, 23);
			this->buttonCandel->TabIndex = 5;
			this->buttonCandel->Text = L"Cancel";
			this->buttonCandel->UseVisualStyleBackColor = true;
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(187, 156);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 23);
			this->buttonOK->TabIndex = 6;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &CellEditForm::buttonOK_Click);
			// 
			// buttonParent
			// 
			this->buttonParent->Location = System::Drawing::Point(39, 156);
			this->buttonParent->Name = L"buttonParent";
			this->buttonParent->Size = System::Drawing::Size(47, 52);
			this->buttonParent->TabIndex = 7;
			this->buttonParent->Text = L"�e";
			this->buttonParent->UseVisualStyleBackColor = true;
			this->buttonParent->Click += gcnew System::EventHandler(this, &CellEditForm::buttonParent_Click);
			// 
			// buttonChild
			// 
			this->buttonChild->Location = System::Drawing::Point(101, 156);
			this->buttonChild->Name = L"buttonChild";
			this->buttonChild->Size = System::Drawing::Size(47, 52);
			this->buttonChild->TabIndex = 8;
			this->buttonChild->Text = L"�q";
			this->buttonChild->UseVisualStyleBackColor = true;
			this->buttonChild->Click += gcnew System::EventHandler(this, &CellEditForm::buttonChild_Click);
			// 
			// CellEditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(296, 237);
			this->Controls->Add(this->buttonChild);
			this->Controls->Add(this->buttonParent);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->buttonCandel);
			this->Controls->Add(this->labelValue);
			this->Controls->Add(this->labelKey);
			this->Controls->Add(this->textBoxValue);
			this->Controls->Add(this->textBoxKey);
			this->Name = L"CellEditForm";
			this->Text = L"CellEditForm";
			this->Load += gcnew System::EventHandler(this, &CellEditForm::CellEditForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:

		String^ key;
		String^ value;
		array<String^>^ keyArray;
		array<Label^>^ labels;
		int level;
		int FormFrom;


		System::Void createKeyLabels(int level) {
			//���x���̔z����쐬
			labels = gcnew array<Label^>(keyArray->Length * 2);
			//���x���쐬�̔z��̃J�E���g�s���ϐ�
			int labelCount = 0;
			//�����o�̃L�[�z��̒����������J��Ԃ�
			for (int i = 0; i <= level; i++) {
				//�L�[����łȂ����
				if (i == 0 || keyArray[i] != "") {
					//��ԏ��߂łȂ����
					if (labelCount != 0) {
						//���x�����쐬
						labels[labelCount] = gcnew Label();
						//�L�[�𕪂���n�C�t������������
						labels[labelCount]->Text = "-";
						labels[labelCount]->Location = Point((i * 70) + 5, 50);
						labels[labelCount]->Size = System::Drawing::Size(10, 40);
						//�t�H�[���Ƀ��x����ǉ�
						this->Controls->Add(labels[labelCount]);
						labelCount++;
					}

					//���x���̔z��̗v�f�Ƀ��x�����쐬
					labels[labelCount] = gcnew Label();
					//���x���ɃL�[���i�[
					labels[labelCount]->Text = keyArray[i];
					//���x�����܂��쐬���Ă��Ȃ����
					if (labelCount == 0) {
						//�ʒu�������ʒu��
						labels[labelCount]->Location = Point(20, 35);
					}
					//��ȏ�쐬�ς�
					else {
						//�O�̃��x���ɏꏊ�����킹�Ă���

						labels[labelCount]->Location = Point((i * 70) + 20, 35);
					}
					//���x���̏���n��

					labels[labelCount]->Size = System::Drawing::Size(50, 40);
					labels[labelCount]->BorderStyle = Windows::Forms::BorderStyle::FixedSingle;
					//Slabels[labelCount]->DoubleClick += gcnew EventHandler(this, &CellEditForm::LavelKeys_Click);
					//�t�H�[���ɒǉ�����
					this->Controls->Add(labels[labelCount]);
					//���x�������ɍ쐬���邽�߂Ɏ���
					labelCount++;
				}
			}
		}

		System::Void ClearLabels(int level) {
			//�\�������郉�x���̐������J��Ԃ�
			for (int i = 0; i < level; i++) {
				//��Ԗڂ����łȂ����
				if (i != 0) {
					//�L�[�Ԃ̃n�C�t���̃��x�����폜
					this->Controls->Remove(this->GetChildAtPoint(Point((i * 80) + 5, 35)));
				}
				//�L�[�̃��x�����폜����
				this->Controls->Remove(this->GetChildAtPoint(Point((i * 80) + 20, 35)));
			}
		}

		System::Void LavelKeys_Click(System::Object^ sender, System::EventArgs^ e)
		{
			//�ǂ̃{�^���������ꂽ�����擾
			int level = (((Label^)sender)->Location.X - 20) / 70;
			//�L�[�ҏW�t�H�[�����쐻
			CellEditForm^ keyEdit = gcnew CellEditForm();
			//�t�H�[���ɔz���n��
			keyEdit->keyArray = keyArray;
			//�ǂ̃L�[�������ꂽ�̂��K�w��n��
			keyEdit->level = level;
			//�t�H�[����\��
			keyEdit->ShowDialog();
			ClearLabels(keyArray->Length);
			//�z����󂯎��
			keyArray = keyEdit->keyArray;
			createKeyLabels(keyArray->Length - 1);
			textBoxKey->Text = keyArray[keyArray->Length - 1];
		}

	private:
		System::Void CellEditForm_Load(System::Object^  sender, System::EventArgs^  e) {
			//�t�H�[���ɓn���ꂽ�L�[�ƒl���e�L�X�g�{�b�N�X�ɓ���
			textBoxKey->Text = key;
			textBoxValue->Text = value;
			//�l���n����Ă��Ȃ����
			if ("" == value || nullptr == value) {
				//�l�̃e�L�X�g�{�b�N�X���\���ɂ���
				textBoxValue->Visible = false;
			}
		}

	private:
		System::Void buttonParent_Click(System::Object^  sender, System::EventArgs^  e) {
			//�e�̃L�[�ɂ��Ă̕ҏW�̎�
			if (level == 0) {
				//���b�Z�[�W�{�b�N�X�ł���ȏ��̐e���쐬���邱�Ƃ��ł��Ȃ�
				MessageBox::Show("�쐬�ł��܂���", "�G���[", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			//�L�[�ҏW�̃t�H�[���̃C���X�^���X���쐬
			CellEditForm^ keyEditform = gcnew CellEditForm();
			//�L�[�̔z���n��
			keyEditform->keyArray = keyArray;
			//�e�{�^������ł��邱�Ƃ�n��
			keyEditform->FormFrom = constants.FROM_PARENT_BUTTON;
			keyEditform->level = level;
			//keyEditform->gridCell = gridCell;
			//�t�H�[�������[�_���\������
			keyEditform->ShowDialog();
			//���ݏo�Ă��郉�x�����폜����
			ClearLabels(keyArray->Length);
			//�L�[�̔z����󂯎��
			keyArray = keyEditform->keyArray;
			level += 1;
			//�����Ƃ����L�[�̔z��Ń��x�����쐬����
			createKeyLabels(keyArray->Length);
		}

		//�q�{�^���������ꂽ�Ƃ��̃C�x���g
	private:
		System::Void buttonChild_Click(System::Object^  sender, System::EventArgs^  e) {
			//�L�[�ҏW�̃t�H�[���̃C���X�^���X���쐬
			CellEditForm^ keyEditform = gcnew CellEditForm();
			//�L�[�̔z���n��
			keyEditform->keyArray = keyArray;
			//�ǂ̊K�w���������l��n��
			keyEditform->level = level;
			//�q�{�^������ł��邱�Ƃ�n��
			keyEditform->FormFrom = constants.FROM_CHILD_BUTTON;
			//�t�H�[�������[�_���\������
			keyEditform->ShowDialog();
			//���ݏo�Ă��郉�x�����폜����
			ClearLabels(keyArray->Length);
			//�L�[�̔z����󂯎��
			keyArray = keyEditform->keyArray;
			//�����Ƃ����L�[�̔z��Ń��x�����쐬����
			createKeyLabels(keyArray->Length - 1);
		}

		//�z���v�f���́{1�ɂ������̂łƂ�
		array<String^>^ insertKeyArray(array<String^>^ arr, String^  value, int index) {
			//�z���v�f���̑}������v�f���́{1�ɂ������̂łƂ�
			array<String^>^ retArr = gcnew array<String^>(arr->Length + 1);
			//�v�f�𐔂���ϐ�
			int j = 0;
			int i = 0;
			//�z��̒����������J��Ԃ�
			for (; i < retArr->Length; ) {
				//�����Ŏw�肳�ꂽ�C���f�b�N�X
				if (index == i) {
					//���̈ʒu�Ɉ����̒l���i�[���Ď���
					retArr[i++] = value;
				}
				//�쐬�����z��Ɉڂ�
				retArr[i++] = arr[j++];
			}
			//�쐬�����z��������o�ɕۑ�����
			return retArr;
		}

		//�e�����
		System::Void createParent() {
			//�����o�̔z��̊K�w�̈ʒu�Ƀe�L�X�g�{�b�N�X�ɓ��͂���Ă���l���i�[����
			keyArray = insertKeyArray(keyArray, textBoxKey->Text, level);
		}

		//�q�����
		System::Void createChild() {
			//�e�L�X�g�{�b�N�X�ɓ��͂���Ă���l��
			keyArray = insertKeyArray(keyArray, textBoxKey->Text, level + 1);
		}

		System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
			//���͂��ꂽ�L�[�������o�ɃZ�b�g
			key = textBoxKey->Text;
			//�l�������o�ɃZ�b�g
			value = textBoxValue->Text;

			//���̃t�H�[�����e�{�^������Ăяo���ꂽ��
			if (FormFrom == constants.FROM_PARENT_BUTTON) {
				//�e����̏��������s
				createParent();
			}
			//�q�{�^������Ăяo���ꂽ�Ƃ�
			else if (FormFrom == constants.FROM_CHILD_BUTTON) {
				//�q����̂Ƃ��̏��������s
				createChild();
			}

			this->Close();
		}

};
}

