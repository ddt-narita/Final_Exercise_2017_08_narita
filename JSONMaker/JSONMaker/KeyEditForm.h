#pragma once


#ifndef __KEY_EDIT_FORM
#define __KEY_EDIT_FORM

#include "Constants.h"
#include "CellChain.h"

namespace JSONMaker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// KeyEditForm �̊T�v
	/// </summary>
	public ref class KeyEditForm : public System::Windows::Forms::Form
	{
	public:
		KeyEditForm(void)
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
		~KeyEditForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  labelKeyName;
	private: System::Windows::Forms::TextBox^  textBoxKeyName;
	private: System::Windows::Forms::Button^  buttonParent;
	private: System::Windows::Forms::Button^  buttonChild;
	private: System::Windows::Forms::Button^  buttonBigBro;
	private: System::Windows::Forms::Button^  buttonBro;
	private: System::Windows::Forms::RadioButton^  radioButtonYes;
	private: System::Windows::Forms::RadioButton^  radioButtonNo;


	private: System::Windows::Forms::Label^  labelIsArray;
	private: System::Windows::Forms::Button^  buttonOK;

	private: System::Windows::Forms::Button^  buttonCancel;






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
			this->labelKeyName = (gcnew System::Windows::Forms::Label());
			this->textBoxKeyName = (gcnew System::Windows::Forms::TextBox());
			this->buttonParent = (gcnew System::Windows::Forms::Button());
			this->buttonChild = (gcnew System::Windows::Forms::Button());
			this->buttonBigBro = (gcnew System::Windows::Forms::Button());
			this->buttonBro = (gcnew System::Windows::Forms::Button());
			this->radioButtonYes = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonNo = (gcnew System::Windows::Forms::RadioButton());
			this->labelIsArray = (gcnew System::Windows::Forms::Label());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// labelKeyName
			// 
			this->labelKeyName->AutoSize = true;
			this->labelKeyName->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelKeyName->Location = System::Drawing::Point(73, 102);
			this->labelKeyName->Name = L"labelKeyName";
			this->labelKeyName->Size = System::Drawing::Size(46, 15);
			this->labelKeyName->TabIndex = 0;
			this->labelKeyName->Text = L"�L�[��";
			// 
			// textBoxKeyName
			// 
			this->textBoxKeyName->Location = System::Drawing::Point(158, 102);
			this->textBoxKeyName->Name = L"textBoxKeyName";
			this->textBoxKeyName->Size = System::Drawing::Size(100, 19);
			this->textBoxKeyName->TabIndex = 1;
			// 
			// buttonParent
			// 
			this->buttonParent->Location = System::Drawing::Point(60, 181);
			this->buttonParent->Name = L"buttonParent";
			this->buttonParent->Size = System::Drawing::Size(50, 50);
			this->buttonParent->TabIndex = 2;
			this->buttonParent->Text = L"�e";
			this->buttonParent->UseVisualStyleBackColor = true;
			this->buttonParent->Click += gcnew System::EventHandler(this, &KeyEditForm::buttonParent_Click);
			// 
			// buttonChild
			// 
			this->buttonChild->Location = System::Drawing::Point(126, 181);
			this->buttonChild->Name = L"buttonChild";
			this->buttonChild->Size = System::Drawing::Size(50, 50);
			this->buttonChild->TabIndex = 3;
			this->buttonChild->Text = L"�q";
			this->buttonChild->UseVisualStyleBackColor = true;
			this->buttonChild->Click += gcnew System::EventHandler(this, &KeyEditForm::buttonChild_Click);
			// 
			// buttonBigBro
			// 
			this->buttonBigBro->Location = System::Drawing::Point(196, 181);
			this->buttonBigBro->Name = L"buttonBigBro";
			this->buttonBigBro->Size = System::Drawing::Size(50, 50);
			this->buttonBigBro->TabIndex = 4;
			this->buttonBigBro->Text = L"�Z";
			this->buttonBigBro->UseVisualStyleBackColor = true;
			this->buttonBigBro->Click += gcnew System::EventHandler(this, &KeyEditForm::buttonBigBro_Click);
			// 
			// buttonBro
			// 
			this->buttonBro->Location = System::Drawing::Point(266, 181);
			this->buttonBro->Name = L"buttonBro";
			this->buttonBro->Size = System::Drawing::Size(50, 50);
			this->buttonBro->TabIndex = 5;
			this->buttonBro->Text = L"��";
			this->buttonBro->UseVisualStyleBackColor = true;
			this->buttonBro->Click += gcnew System::EventHandler(this, &KeyEditForm::buttonBigBro_Click);
			// 
			// radioButtonYes
			// 
			this->radioButtonYes->AutoSize = true;
			this->radioButtonYes->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->radioButtonYes->Location = System::Drawing::Point(172, 140);
			this->radioButtonYes->Name = L"radioButtonYes";
			this->radioButtonYes->Size = System::Drawing::Size(49, 19);
			this->radioButtonYes->TabIndex = 6;
			this->radioButtonYes->TabStop = true;
			this->radioButtonYes->Text = L"Yes";
			this->radioButtonYes->UseVisualStyleBackColor = true;
			// 
			// radioButtonNo
			// 
			this->radioButtonNo->AutoSize = true;
			this->radioButtonNo->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->radioButtonNo->Location = System::Drawing::Point(244, 140);
			this->radioButtonNo->Name = L"radioButtonNo";
			this->radioButtonNo->Size = System::Drawing::Size(43, 19);
			this->radioButtonNo->TabIndex = 7;
			this->radioButtonNo->TabStop = true;
			this->radioButtonNo->Text = L"No";
			this->radioButtonNo->UseVisualStyleBackColor = true;
			// 
			// labelIsArray
			// 
			this->labelIsArray->AutoSize = true;
			this->labelIsArray->Location = System::Drawing::Point(90, 145);
			this->labelIsArray->Name = L"labelIsArray";
			this->labelIsArray->Size = System::Drawing::Size(29, 12);
			this->labelIsArray->TabIndex = 8;
			this->labelIsArray->Text = L"�z��";
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(172, 265);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 28);
			this->buttonOK->TabIndex = 9;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &KeyEditForm::buttonOK_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(266, 265);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 28);
			this->buttonCancel->TabIndex = 10;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// KeyEditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(385, 325);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->labelIsArray);
			this->Controls->Add(this->radioButtonNo);
			this->Controls->Add(this->radioButtonYes);
			this->Controls->Add(this->buttonBro);
			this->Controls->Add(this->buttonBigBro);
			this->Controls->Add(this->buttonChild);
			this->Controls->Add(this->buttonParent);
			this->Controls->Add(this->textBoxKeyName);
			this->Controls->Add(this->labelKeyName);
			this->Name = L"KeyEditForm";
			this->Text = L"KeyEditForm";
			this->Load += gcnew System::EventHandler(this, &KeyEditForm::KeyEditForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		//���x���̔z��
		array<Label^>^ labels;
		//�L�[�̔z��
		array<String^>^ keyArray;
		//���ׂẴZ��
		CellChain^ gridCell;
		//�ǂ̃L�[�ɂ��Ă̕ҏW����ݒ肷��ϐ�
		int keyLevel;
		//���̃Z���̍s
		int row;
		//���̃Z���̗�
		int col;
		//�ǂ̃t�H�[�����痈���̂�������
		int FormFrom;

		//
		System::Void CreateKeyLabels(int level) {
			labels = gcnew array<Label^>(keyArray->Length * 2);
			//���x���쐬�̔z��̃J�E���g�s���ϐ�
			int labelCount = 0;
			//�����o�̃L�[�z��̒����������J��Ԃ�
			for (int i = 0; i < level; i++) {
				//�L�[����łȂ����
				if (i == 0 || keyArray[i] != "") {
					//��ԏ��߂łȂ����
					if (labelCount != 0) {
						//���x�����쐬
						labels[labelCount] = gcnew Label();
						//�L�[�𕪂���n�C�t������������
						labels[labelCount]->Text = "-";
						labels[labelCount]->Location = Point(labels[labelCount - 1]->Location.X + 65, 35);
						labels[labelCount]->Size = System::Drawing::Size(10, 35);
						this->Controls->Add(labels[labelCount]);
						labelCount++;
					}

					//���x���̔z��̗v�f�Ƀ��x�����쐬
					labels[labelCount] = gcnew Label();
					//���x���ɃL�[���i�[
					labels[labelCount]->Text = keyArray[i];
					//���x�����܂�����Ă��Ȃ����
					if (labelCount == 0) {
						//���߂̃��x���̈ʒu�ɔz�u
						labels[labelCount]->Location = Point(20, 35);
					}
					//���x�������łɍ���Ă���Ƃ�
					else {
						//�ʒu��O�̃��x���ɍ��킹��
						labels[labelCount]->Location = Point(labels[labelCount - 1]->Location.X + 15, 35);
					}
					//�T�C�Y������
					labels[labelCount]->Size = System::Drawing::Size(60, 35);
					//�l�p�ň͂�
					labels[labelCount]->BorderStyle = Windows::Forms::BorderStyle::FixedSingle;
					//�t�H�[���ɒǉ�
					this->Controls->Add(labels[labelCount]);
					//���x�������Ɉړ�
					labelCount++;
				}
			}
		}

		/*
		�֐���:ClearLabels
		�T�v:���x������������֐�
		����:int level�@�L�[�̐�
		�ԋp�l:����
		�쐬��:9��22��(��)
		�쐬��:���c�C�V
		*/
		System::Void ClearLabels(int level) {
			//�����̃L�[�̐������J��Ԃ�
			for (int i = 0; i < level; i++) {
				//��ԖڂłȂ����
				if (i != 0) {
					//�L�[�Ԃ̃n�C�t���̃��x�����폜����
					this->Controls->Remove(this->GetChildAtPoint(Point((i * 80)+ 5, 35)));
				}
				//�L�[�̃��x�����폜����
				this->Controls->Remove(this->GetChildAtPoint(Point(20 + (i * 80),35)));
			}
		}

		//�����グ���̃C�x���g
	private: System::Void KeyEditForm_Load(System::Object^  sender, System::EventArgs^  e) {
		//�l�ւ̃p�X�ƂȂ郉�x���Q���쐬����
		CreateKeyLabels(keyLevel);
		//��ԉ��̕ҏW�Ώۂ̒l���e�L�X�g�{�b�N�X�ɕ\��
		textBoxKeyName->Text = keyArray[keyLevel];
	}

			 //�e�{�^���������ꂽ�Ƃ��̃C�x���g
	private: System::Void buttonParent_Click(System::Object^  sender, System::EventArgs^  e) {
		//�e�̃L�[�ɂ��Ă̕ҏW�̎�
		if (keyLevel == 0) {
			//���b�Z�[�W�{�b�N�X�ł���ȏ��̐e���쐬���邱�Ƃ��ł��Ȃ�
			MessageBox::Show("�쐬�ł��܂���", "�G���[", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		//�L�[�ҏW�̃t�H�[���̃C���X�^���X���쐬
		KeyEditForm^ keyEditform = gcnew KeyEditForm();
		//�L�[�̔z���n��
		keyEditform->keyArray = keyArray;
		//�e�{�^������ł��邱�Ƃ�n��
		keyEditform->FormFrom = constants.FROM_PARENT_BUTTON;
		//�t�H�[�������[�_���\������
		keyEditform->ShowDialog();
		//���ݏo�Ă��郉�x�����폜����
		ClearLabels(keyArray->Length);
		//�L�[�̔z����󂯎��
		keyArray = keyEditform->keyArray;
		//�����Ƃ����L�[�̔z��Ń��x�����쐬����
		CreateKeyLabels(keyArray->Length);
	}

			 //�q�{�^���������ꂽ�Ƃ��̃C�x���g
	private: System::Void buttonChild_Click(System::Object^  sender, System::EventArgs^  e) {
		//�L�[�ҏW�̃t�H�[���̃C���X�^���X���쐬
		KeyEditForm^ keyEditform = gcnew KeyEditForm();
		//�L�[�̔z���n��
		keyEditform->keyArray = keyArray;
		//�ǂ̊K�w���������l��n��
		keyEditform->keyLevel = keyLevel;
		//�q�{�^������ł��邱�Ƃ�n��
		keyEditform->FormFrom = constants.FROM_CHILD_BUTTON;
		//�t�H�[�������[�_���\������
		keyEditform->ShowDialog();
		//���ݏo�Ă��郉�x�����폜����
		ClearLabels(keyArray->Length);
		//�L�[�̔z����󂯎��
		keyArray = keyEditform->keyArray;
		//�����Ƃ����L�[�̔z��Ń��x�����쐬����
		CreateKeyLabels(keyArray->Length);
	}



			 //�Z�{�^���������ꂽ�Ƃ��̃C�x���g
	private: System::Void buttonBigBro_Click(System::Object^  sender, System::EventArgs^  e) {
		//�Z���炩�A�킩�炩�������l
		int formFrom = 0;
		//�Z�{�^������
		if (sender->Equals(buttonBigBro)) {
			//�Z�ł��邱�Ƃ��߂��l���擾
			formFrom = constants.FROM_BIGBRO_BUTTON;
		}
		//��{�^������
		else {
			//��ł��邱�Ƃ������l���i�[
			formFrom = constants.FROM_BRO_BUTTON;
		}
		//�L�[�ҏW�t�H�[�����쐻
		KeyEditForm^ keyEdit = gcnew KeyEditForm();
		//�ǂ����痈�������i�[
		keyEdit->FormFrom = formFrom;
		//�t�H�[���ɃL�[�̔z���n��
		keyEdit->keyArray = keyArray;
		//���[�_���\��
		keyEdit->ShowDialog();
	}

	private:

		System::Void insertKeyArray(array<String^>^ arr, String^  value, int index) {
			//�z���v�f���́{1�ɂ������̂łƂ�
			array<String^>^ retArr = gcnew array<String^>(arr->Length + 1);
			//�v�f�𐔂���ϐ�
			int j = 0;
			//�z��̒����������J��Ԃ�
			for (int i = 0; i < retArr->Length; i++, j++) {
				//�����Ŏw�肳�ꂽ�C���f�b�N�X�Ȃ�
				if (i = index) {
					//���̈ʒu�Ɉ����̒l���i�[���Ď���
					retArr[i++] = value;
				}
				//�쐬�����z��Ɉڂ�
				retArr[i] = arr[j];
			}
			//�쐬�����z��������o�ɕۑ�����
			arr = retArr;
		}


		/*
		�֐���:createParent
		�T�v:�e����Ă΂ꎞ�̏���
		����:����
		�ԋp�l:����
		�쐬��:9��22��(��)
		�쐬��:���c�C�V
		*/
		System::Void createParent() {
			//�����o�̔z��̊K�w�̈ʒu�Ƀe�L�X�g�{�b�N�X�ɓ��͂���Ă���l���i�[����
			insertKeyArray(keyArray, textBoxKeyName->Text, keyLevel);
		}

		/*
		�֐���:createChild
		�T�v:�q�{�^������Ă΂ꂽ���̏���
		����:����
		�ԋp�l:����
		�쐬��:9��22��(��)
		�쐬��:���c�C�V
		*/
		System::Void createChild() {
			//�ҏW���̃L�[�̊K�w���s���Ȃ��e�̊K�w�̎�
			if (keyLevel == constants.LEVEL_PARENT) {
				//�ҏW���̃Z���̐擪�̃Z�����擾
				CellChain^ rowCell = this->gridCell->getCell(row, 0);
				//�񐔕��J��Ԃ�
				while (rowCell == nullptr) {
					//���̃Z���̃L�[�̔z��ɓ��͂���Ă���l���i�[���Ă���
					insertKeyArray(rowCell->CellKey, textBoxKeyName->Text, keyLevel);
					//���̃Z����
					rowCell = rowCell->right;
				}
			}
			//�e�ł͂Ȃ��Ƃ�
			else {
				//�ҏW���̃Z���̃L�[�̐e�Ƀe�L�X�g�{�b�N�X�ɓ��͂��ꂽ�l��}��
				KeyEditForm::insertKeyArray(keyArray, textBoxKeyName->Text, keyLevel);
			}

		}

		/*
		�֐���:createBro
		�T�v:�Z��{�^������Ă΂�Ă������̏���
		����:����
		�ԋp�l:����
		�쐬��:9��22��(��)
		�쐬��:���c�C�V
		*/
		System::Void createBro() {
			//
			int insertRowNum = 0;
			//�K�w���e�̎�
			if (keyLevel == constants.LEVEL_PARENT) {
				//�Z�{�^������Ă΂ꂽ�t�H�[���ł���Ȃ�
				if (FormFrom == constants.FROM_BIGBRO_BUTTON) {
					//�ǂ񂾃Z���̍s�擾
					insertRowNum = row;

				}
				//��{�^�������΂ꂽ�t�H�[���̎�
				else {
					//���̃Z�����擾
					insertRowNum = row + 1;
				}
				//�擾�����s�ɑ}�����Ă��̎��̐擪�̃Z�����擾
				CellChain^ rowCell = gridCell->insertRow(insertRowNum);
				
				//�񐔕��J��Ԃ�
				while (rowCell == nullptr) {
					//���̃Z���̃L�[�̔z��̈�ԏ�Ƀe�L�X�g�{�b�N�X�ɓ��͂��ꂽ�l���i�[����
					rowCell->CellKey[keyLevel] = textBoxKeyName->Text;
					//���̃Z���ֈړ�
					rowCell = rowCell->right;
				}
			}
			else {
				//�Z����Ă΂ꂽ�ꍇ
				if (FormFrom == constants.FROM_BIGBRO_BUTTON) {
					//�Ă񂾎��̃Z�����擾����

				}
				//�킩��̏ꍇ
				else {
					//�ǂ񂾎��̃Z���̉E�̃Z�����擾����

				}
				//insert();
				//
				array<String^>^ temp = gcnew array<String^>(keyLevel);
				//
				for (int i = 0; i < keyLevel; i++) {
					//
					temp[i] = keyArray[i];
				}

			}
		}

		/*
		�֐���:changeKey
		�T�v:�Z���ҏW�t�H�[������Ă΂ꂽ�Ƃ��̏���
		����:����
		�ԋp�l:����
		�쐬��:9��22��(��)
		�쐬��:���c�C�V
		*/
		System::Void changeKey() {
			//�ҏW���̃L�[�̊K�w���s���Ȃ��e�̊K�w�̎�
			if (keyLevel == constants.LEVEL_PARENT) {
				//�ҏW���̃Z���̐擪�̃Z�����擾
				CellChain^ rowCell = this->gridCell->getCell(row -1, 0);
				//�񐔕��J��Ԃ�
				while (rowCell != nullptr) {
					//�z��̂��̈ʒu�̒l���e�L�X�g�{�b�N�X�ɓ��͂���Ă���l�ɂ���
					rowCell->CellKey[keyLevel] = textBoxKeyName->Text;
					//���̃Z����
					rowCell = rowCell->right;
				}
			}
			//�e�ł͂Ȃ��Ƃ�
			else {
				//���̃Z�������L�[��ύX
				keyArray[keyLevel] = textBoxKeyName->Text;
			}
		}


		/*
		�֐���:buttonOK_Click
		�T�v:���͂��I���AOK�{�^�����������Ƃ��̏���
		����:����
		�ԋp�l:����
		�쐬��:9��22��(��)
		�쐬��:���c�C�V
		*/
	private:
		System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
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
			//�Z��{�^������Ăяo���ꂽ�Ƃ�
			else if (FormFrom == constants.FROM_BIGBRO_BUTTON || FormFrom == constants.FROM_BIGBRO_BUTTON) {
				//�Z�킩��̎��̏��������s
				createBro();
			}
			//�ǂ̃{�^������ł��Ȃ��Z������Ă΂ꂽ�ŏ��̃t�H�[���̎�
			else {
				//�����L�[
				changeKey();
			}
			//�t�H�[�������
			this->Close();
		}
	};
}

#endif // !__KEY_EDIT_FORM
