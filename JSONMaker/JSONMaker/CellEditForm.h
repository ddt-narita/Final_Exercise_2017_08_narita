#pragma once
#ifndef __CELL_EDIT_FORM
#define __CELL_EDIT_FORM

#include "KeyEditForm.h"
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
	private: System::Windows::Forms::Label^  labelKeyName;
	private: System::Windows::Forms::Label^  labelValue;
	private: System::Windows::Forms::Label^  labelIsArray;
	private: System::Windows::Forms::RadioButton^  radioButtonYes;
	protected:

	protected:



	private: System::Windows::Forms::RadioButton^  radioButtonNo;
	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::Button^  buttonCancel;
	private: System::Windows::Forms::TextBox^  textBoxKeyName;
	private: System::Windows::Forms::TextBox^  textBoxValue;





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
			this->labelValue = (gcnew System::Windows::Forms::Label());
			this->labelIsArray = (gcnew System::Windows::Forms::Label());
			this->radioButtonYes = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonNo = (gcnew System::Windows::Forms::RadioButton());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->textBoxKeyName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxValue = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// labelKeyName
			// 
			this->labelKeyName->AutoSize = true;
			this->labelKeyName->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelKeyName->Location = System::Drawing::Point(55, 104);
			this->labelKeyName->Name = L"labelKeyName";
			this->labelKeyName->Size = System::Drawing::Size(46, 15);
			this->labelKeyName->TabIndex = 0;
			this->labelKeyName->Text = L"�L�[��";
			// 
			// labelValue
			// 
			this->labelValue->AutoSize = true;
			this->labelValue->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelValue->Location = System::Drawing::Point(55, 145);
			this->labelValue->Name = L"labelValue";
			this->labelValue->Size = System::Drawing::Size(22, 15);
			this->labelValue->TabIndex = 1;
			this->labelValue->Text = L"�l";
			// 
			// labelIsArray
			// 
			this->labelIsArray->AutoSize = true;
			this->labelIsArray->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelIsArray->Location = System::Drawing::Point(55, 184);
			this->labelIsArray->Name = L"labelIsArray";
			this->labelIsArray->Size = System::Drawing::Size(37, 15);
			this->labelIsArray->TabIndex = 2;
			this->labelIsArray->Text = L"�z��";
			// 
			// radioButtonYes
			// 
			this->radioButtonYes->AutoSize = true;
			this->radioButtonYes->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->radioButtonYes->Location = System::Drawing::Point(144, 182);
			this->radioButtonYes->Name = L"radioButtonYes";
			this->radioButtonYes->Size = System::Drawing::Size(49, 19);
			this->radioButtonYes->TabIndex = 3;
			this->radioButtonYes->Text = L"Yes";
			this->radioButtonYes->UseVisualStyleBackColor = true;
			// 
			// radioButtonNo
			// 
			this->radioButtonNo->AutoSize = true;
			this->radioButtonNo->Location = System::Drawing::Point(212, 185);
			this->radioButtonNo->Name = L"radioButtonNo";
			this->radioButtonNo->Size = System::Drawing::Size(37, 16);
			this->radioButtonNo->TabIndex = 4;
			this->radioButtonNo->Text = L"No";
			this->radioButtonNo->UseVisualStyleBackColor = true;
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(118, 238);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 23);
			this->buttonOK->TabIndex = 5;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &CellEditForm::buttonOK_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(212, 238);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 6;
			this->buttonCancel->Text = L"�L�����Z��";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// textBoxKeyName
			// 
			this->textBoxKeyName->Location = System::Drawing::Point(149, 104);
			this->textBoxKeyName->Name = L"textBoxKeyName";
			this->textBoxKeyName->Size = System::Drawing::Size(100, 19);
			this->textBoxKeyName->TabIndex = 7;
			// 
			// textBoxValue
			// 
			this->textBoxValue->Location = System::Drawing::Point(149, 145);
			this->textBoxValue->Name = L"textBoxValue";
			this->textBoxValue->Size = System::Drawing::Size(100, 19);
			this->textBoxValue->TabIndex = 8;
			// 
			// CellEditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(338, 302);
			this->Controls->Add(this->textBoxValue);
			this->Controls->Add(this->textBoxKeyName);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->radioButtonNo);
			this->Controls->Add(this->radioButtonYes);
			this->Controls->Add(this->labelIsArray);
			this->Controls->Add(this->labelValue);
			this->Controls->Add(this->labelKeyName);
			this->Name = L"CellEditForm";
			this->Text = L"CellEditForm";
			this->Load += gcnew System::EventHandler(this, &CellEditForm::CellEditForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		//�Z���̃L�[�̔z��
		array<String^>^ keyArray;
		//�Z���̒l
		String^ Value;
		array<Label^>^ labels;

		//�S�̂̃Z��
		CellChain^ cell;

		//���̃Z���̍s
		int row;
		//���̃Z���̗�
		int col;


	private:
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
					labels[labelCount]->DoubleClick += gcnew EventHandler(this, &CellEditForm::LavelKeys_Click);
					//�t�H�[���ɒǉ�����
					this->Controls->Add(labels[labelCount]);
					//���x�������ɍ쐬���邽�߂Ɏ���
					labelCount++;
				}
			}
		}

		/*
		�֐���:ClearLabels
		�T�v:
		����:
		�ԋp�l:
		�쐬��:
		�쐬��:
		*/
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

	private:
		/*
		�֐���:CellEditForm_Load
		�T�v:���̃t�H�[�����\�������O�ɍs���鏈��
		����:�C�x���g�̈���
		�ԋp�l:����
		�쐬��:9��20��(��)
		�쐬��:���c�C�V
		*/
		System::Void CellEditForm_Load(System::Object^  sender, System::EventArgs^  e) {
			
			//�ǂ̈ʒu�̃Z���ɂ��Ă̏�񂩂��^�C�g���ɕ\��
			this->Text = "�s:" + row.ToString() + " ��:" + col.ToString() + " �̏��";
			//�󂯎�����L�[�̔z��Ń��x�����쐬
			createKeyLabels(keyArray->Length - 1);
			//��ԉ��̃L�[��\��
			textBoxKeyName->Text = keyArray[keyArray->Length - 1];
			//�l���e�L�X�g�{�b�N�X�ɒl��\��
			textBoxValue->Text = this->Value;
		}

	private:
		/*
		�֐���:LabelKeys_Click
		�T�v:���x�����N���b�N�����Ƃ��̃C�x���g
		����:�C�x���g�̈���
		�ԋp�l:����
		�쐬��:9��20��(��)
		�쐬��:���c�C�V
		*/
		System::Void LavelKeys_Click(System::Object^ sender, System::EventArgs^ e)
		{
			//�ǂ̃{�^���������ꂽ�����擾
			int level = (((Label^)sender)->Location.X - 20) / 70;
			//�L�[�ҏW�t�H�[�����쐻
			KeyEditForm^ keyEdit = gcnew KeyEditForm();
			keyEdit->row = row-1;
			keyEdit->col = col;
			//�t�H�[���ɔz���n��
			keyEdit->keyArray = keyArray;
			//�ǂ̃L�[�������ꂽ�̂��K�w��n��
			keyEdit->keyLevel = level;
			//�Z���\���ɗp����I�u�W�F�N�g��n��
			keyEdit->gridCell = cell;
			//�t�H�[����\��
			keyEdit->ShowDialog();
			ClearLabels(keyArray->Length);
			//�z����󂯎��
			keyArray = keyEdit->keyArray;
			createKeyLabels(keyArray->Length -1);
			textBoxKeyName->Text = keyArray[keyArray->Length - 1];
		}

		/*
		�֐���:buttonOK_Click
		�T�v:OK�{�^���������ꂽ�Ƃ��̃C�x���g
		����:�C�x���g�̈���
		�ԋp�l:����
		�쐬��:9��20��(��)
		�쐬��:���c�C�V
		*/
	private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
		//�e�L�X�g�{�b�N�X�ɓ��͂��ꂽ�L�[�����L�[�̊Y������ʒu�Ɋi�[
		this->keyArray[keyArray->Length - 1] = textBoxKeyName->Text;
		//�e�L�X�g�{�b�N�X�ɓ��͂��ꂽ�l�������o�Ɋi�[
		Value = textBoxValue->Text;
		//�l�����͂���Ă��Ȃ��Ƃ�
		if ("" == Value) {
			//���͂���Ă��Ȃ����Ƃ��x��
			MessageBox::Show("�l�����͂���Ă��܂���", "�x��", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}

		//�z��Ƀ`�F�b�N�������
		if (radioButtonYes->Checked) {
			//���ɔz��������L�[��ǉ�����
			keyArray[keyArray->Length - 1] = gcnew String(constants.KEY_ISARRAY.c_str());
		}
		this->Close();
	}
	};
}

#endif // !__CELL_EDIT_FORM