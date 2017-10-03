#pragma once
#include "Constants.h"
#include "ChainData.h"

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
	private: System::Windows::Forms::Button^  buttonCancel;

	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::Button^  buttonParent;
	private: System::Windows::Forms::Button^  buttonChild;
	private: System::Windows::Forms::Button^  buttonBigBro;
	private: System::Windows::Forms::Button^  buttonBro;




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
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonParent = (gcnew System::Windows::Forms::Button());
			this->buttonChild = (gcnew System::Windows::Forms::Button());
			this->buttonBigBro = (gcnew System::Windows::Forms::Button());
			this->buttonBro = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBoxKey
			// 
			this->textBoxKey->Location = System::Drawing::Point(133, 87);
			this->textBoxKey->Name = L"textBoxKey";
			this->textBoxKey->Size = System::Drawing::Size(100, 19);
			this->textBoxKey->TabIndex = 0;
			// 
			// textBoxValue
			// 
			this->textBoxValue->Location = System::Drawing::Point(133, 133);
			this->textBoxValue->Name = L"textBoxValue";
			this->textBoxValue->Size = System::Drawing::Size(100, 19);
			this->textBoxValue->TabIndex = 1;
			// 
			// labelKey
			// 
			this->labelKey->AutoSize = true;
			this->labelKey->Location = System::Drawing::Point(77, 90);
			this->labelKey->Name = L"labelKey";
			this->labelKey->Size = System::Drawing::Size(37, 12);
			this->labelKey->TabIndex = 2;
			this->labelKey->Text = L"�L�[��";
			// 
			// labelValue
			// 
			this->labelValue->AutoSize = true;
			this->labelValue->Location = System::Drawing::Point(97, 136);
			this->labelValue->Name = L"labelValue";
			this->labelValue->Size = System::Drawing::Size(17, 12);
			this->labelValue->TabIndex = 3;
			this->labelValue->Text = L"�l";
			// 
			// buttonCancel
			// 
			this->buttonCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonCancel->Location = System::Drawing::Point(258, 211);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(88, 41);
			this->buttonCancel->TabIndex = 5;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &CellEditForm::buttonCancel_Click);
			// 
			// buttonOK
			// 
			this->buttonOK->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->buttonOK->Location = System::Drawing::Point(258, 163);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(88, 42);
			this->buttonOK->TabIndex = 6;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &CellEditForm::buttonOK_Click);
			// 
			// buttonParent
			// 
			this->buttonParent->Location = System::Drawing::Point(17, 182);
			this->buttonParent->Name = L"buttonParent";
			this->buttonParent->Size = System::Drawing::Size(47, 56);
			this->buttonParent->TabIndex = 7;
			this->buttonParent->Text = L"�e";
			this->buttonParent->UseVisualStyleBackColor = true;
			this->buttonParent->Click += gcnew System::EventHandler(this, &CellEditForm::ButtonFamily_Click);
			// 
			// buttonChild
			// 
			this->buttonChild->Location = System::Drawing::Point(70, 182);
			this->buttonChild->Name = L"buttonChild";
			this->buttonChild->Size = System::Drawing::Size(47, 56);
			this->buttonChild->TabIndex = 8;
			this->buttonChild->Text = L"�q";
			this->buttonChild->UseVisualStyleBackColor = true;
			this->buttonChild->Click += gcnew System::EventHandler(this, &CellEditForm::ButtonFamily_Click);
			// 
			// buttonBigBro
			// 
			this->buttonBigBro->Location = System::Drawing::Point(123, 182);
			this->buttonBigBro->Name = L"buttonBigBro";
			this->buttonBigBro->Size = System::Drawing::Size(47, 56);
			this->buttonBigBro->TabIndex = 9;
			this->buttonBigBro->Text = L"�Z";
			this->buttonBigBro->UseVisualStyleBackColor = true;
			this->buttonBigBro->Click += gcnew System::EventHandler(this, &CellEditForm::ButtonFamily_Click);
			// 
			// buttonBro
			// 
			this->buttonBro->Location = System::Drawing::Point(176, 182);
			this->buttonBro->Name = L"buttonBro";
			this->buttonBro->Size = System::Drawing::Size(48, 56);
			this->buttonBro->TabIndex = 10;
			this->buttonBro->Text = L"��";
			this->buttonBro->UseVisualStyleBackColor = true;
			this->buttonBro->Click += gcnew System::EventHandler(this, &CellEditForm::ButtonFamily_Click);
			// 
			// CellEditForm
			// 
			this->AcceptButton = this->buttonOK;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->buttonCancel;
			this->ClientSize = System::Drawing::Size(358, 264);
			this->Controls->Add(this->buttonBro);
			this->Controls->Add(this->buttonBigBro);
			this->Controls->Add(this->buttonChild);
			this->Controls->Add(this->buttonParent);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->labelValue);
			this->Controls->Add(this->labelKey);
			this->Controls->Add(this->textBoxValue);
			this->Controls->Add(this->textBoxKey);
			this->Name = L"CellEditForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"CellEditForm";
			this->Load += gcnew System::EventHandler(this, &CellEditForm::CellEditForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		ChainData* cell;
		array<Label^>^ labels;
		int FormFrom;

	private:
		System::Void createKeyLabels(array<String^>^ path) {
			//���x���z��̒������n�C�t�������܂߂ăL�[�̐��~�Q�{�P�ɂ���
			labels = gcnew array<Label^>(path->Length * 2);
			//���x���z��̃C���f�b�N�X
			int labelIndex = 0;
			//�����̃L�[�z��̒����������J��Ԃ�
			for (int i = 0; i < path->Length; i++) {
				//��ԏ��߂łȂ��Ȃ�i�n�C�t���̃��x�������j
				if (0 != i) {
					//���x���𐶐�����
					labels[labelIndex] = gcnew Label();
					//�傫�����n�C�t�����ɍ��킹��
					labels[labelIndex]->Size = System::Drawing::Size(10, 35);
					//�ʒu���n�C�t���ɍ��킹��
					labels[labelIndex]->Location = Point((i * 80) + 5, 20);
					//���x���Ƀn�C�t������������
					labels[labelIndex]->Text = "\n-";
					//���x���z��̃C���f�b�N�X������
					labelIndex++;
				}//�n�C�t��������

				//���x�����쐬����
				labels[labelIndex] = gcnew Label();
				//�T�C�Y���L�[�ɍ��킹��
				labels[labelIndex]->Size = System::Drawing::Size(60, 35);
				//�ʒu���L�[�ɍ��킹��
				labels[labelIndex]->Location = Point((i * 80) + 20, 20);
				//���x���ɂ��̎��̃L�[����������
				labels[labelIndex]->Text = path[i];
				//���x�����l�p�ň͂ތ`�ɂ���
				labels[labelIndex]->BorderStyle = BorderStyle::FixedSingle;
				//
				labels[labelIndex]->DoubleClick += gcnew EventHandler(this, &CellEditForm::Labels_DoubleClick);
				//���x���̔z��̃C���f�b�N�X������
				labelIndex++;
			}
			//�ł������x���̔z����t�H�[���ɒǉ�����
			this->Controls->AddRange(labels);
		}

		//���x�����N���A����֐�
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

		/*
		�֐���:CellEditForm_Load
		�T�v:���̃t�H�[���𗧂��グ�鎞�ɍs���֐�
		����:�C�x���g�̈���
		�ԋp�l:����
		�쐬��:9��29��(��)
		�쐬��:���c�C�V
		*/
		System::Void CellEditForm_Load(System::Object^  sender, System::EventArgs^  e) {
			
			//�e�Z���Q���擾
			std::vector<ChainData*> parent = cell->getParents();
			std::vector<std::string>parentKey(parent.size());
			for (int i = 0; i < parent.size(); i++) {
				parentKey[i] = parent[i]->key;
			}

			//�n���ꂽ�Z���̈�ԏォ�炻�̃Z���܂ł̐e�L�[�Q�z����擾����
			array<String^>^ keyPath = constants.vectorToArray(parentKey);
			//�e�̊K�w�̃L�[����L�[�̘A����\��
			createKeyLabels(keyPath);

			//�e�L�X�g�{�b�N�X�ɃL�[�̒l�����
			textBoxKey->Text = gcnew String(cell->key.c_str());
			//�n���ꂽ�Z�����I�u�W�F�N�g
			if (cell->isObject()) {
				//�l�ɂ��Ẵe�L�X�g�{�b�N�X���\��
				textBoxValue->Visible = false;
				//�l�ɂ��Ẵ��x�����\��
				labelValue->Visible = false;
			}
			//�f�[�^�Ȃ�
			else {
				//�l�ɂ��Ẵe�L�X�g�{�b�N�X�ɒl���i�[
				textBoxValue->Text = gcnew String(cell->value.c_str());
			}
			//�e�����Ȃ��Ƃ�
			if (cell->getParents().size() < 1) {
				buttonParent->Visible = false;
			}
		}


		/*
		�֐���:buttonOK_Click
		�T�v:OK�{�^���������ꂽ�Ƃ��̃C�x���g
		����:�C�x���g�̈���
		�ԋp�l:����
		�쐬��:9��29��(��)
		�쐬��:���c�C�V
		*/
		System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
			//�Z���̃L�[�Ƀe�L�X�g�{�b�N�X�œ��͂��ꂽ�l���i�[
			cell->key = constants.StrToc_str(textBoxKey->Text);
			//�Z�����I�u�W�F�N�g�łȂ��Ȃ�
			if (!cell->isObject()) {
				//�Z���̒l�Ƀe�L�X�g�{�b�N�X�ɓ��͂��ꂽ�l���i�[����
				cell->value = constants.StrToc_str(textBoxValue->Text);
			}
			//�Z���ɒl��������Ɠ��͂���Ă�����
			if ("" != cell->key || "" != cell->value) {
				//�L���ɂ���
				cell->valid = true;
			}

			//���̃t�H�[�������
			this->Close();
		}

		/*
		�֐���:ButtonFamily_Click
		�T�v:�e�q�Z��̂����ꂩ�̃{�^���������ꂽ�Ƃ��̃C�x���g
		����:�C�x���g�̈���
		�ԋp�l:����
		�쐬��:9��29��(��)
		�쐬��:���c�C�V
		*/
		System::Void ButtonFamily_Click(System::Object^  sender, System::EventArgs^  e) {
			//�t�H�[���̃C���X�^���X�𐶐�
			CellEditForm^ subForm = gcnew CellEditForm();

			//�����Ă����{�^�����擾
			Button^ send = (Button^)sender;
			//�e�{�^������ł���Ƃ�
			if ("buttonParent" == send->Name) {
				//�e���쐬���ēn��
				subForm->cell = cell->createParent();
				//�e�{�^������ł��邱�Ƃ������l��n��
				subForm->FormFrom = constants.FROM_PARENT_BUTTON;
			}
			//�q�{�^������̎�
			else if ("buttonChild" == send->Name) {
				//�q���쐬���ēn��
				subForm->cell = cell->createChild();
				//�q�{�^������ł��邱�Ƃ������l��n��
				subForm->FormFrom = constants.FROM_CHILD_BUTTON;
			}
			//�Z�{�^������̎�
			else if ("buttonBigBro" == send->Name) {
				//�Z���쐬���ēn��
				subForm->cell = cell->insert(ChainData::FrontBack::Front);
				//�Z�{�^������ł��邱�Ƃ������l��n��
				subForm->FormFrom = constants.FROM_BIGBRO_BUTTON;
			}
			//��{�^������̎�
			else {
				//����쐬���ēn��
				subForm->cell = cell->insert(ChainData::FrontBack::Back);
				//��{�^������ł��邱�Ƃ������l��n��
				subForm->FormFrom = constants.FROM_BRO_BUTTON;
			}
			//�t�H�[����\������
			Windows::Forms::DialogResult rb = subForm->ShowDialog();

			//���ʂ�OK�ł�����Ɛe�q�Z�킪��ꂽ�Ȃ�
			if (Windows::Forms::DialogResult::OK == rb) {
				//���̃Z����L���ɂ���
				cell->valid = true;
			}
		}



		/*
		�֐���:parentCancel
		�T�v:�e���쐬����̂���߂�֐�
		����:�Ȃ�
		�ԋp�l:�Ȃ�
		�쐬��:9��29��(��)
		�쐬��:���c�C�V
		*/
		void parentCancel() {
			//�q���擾����(�e�{�^���Ńt�H�[�����Ăяo���O�ɕҏW���Ă����Z��)
			ChainData* child = cell->right;
			//�쐬���悤�Ƃ��Ă����e�����j�̃Z���̎�
			if (nullptr == cell->upper) {
				//�e���擾
				ChainData* parent = cell->left;
				//�q���e�̎q�ɂȂ�悤�ɂ���
				parent->addRight(child);
			}
			//�쐬���悤�Ƃ��Ă����e�����j�ł͂Ȃ�
			else {
				//�Z���擾
				ChainData* bro = cell->left;
				//�q���Z�̒�ɂȂ�悤�ɂ���
				bro->addUnder(child);
				//�q�̍쐬���悤�Ƃ��Ă����e���w���|�C���^���i���ɂ���
				child->left = nullptr;
			}
			//���̒�̃Z��������
			if (nullptr != cell->under) {
				//���̃Z�����擾����
				ChainData* under = cell->under;
				//�q�̉��ɂ�����i�[����
				child->addUnder(under);
			}
			//�f�X�g���N�^�ō폜����Ă��܂��̂Ŏq�ƒ�ւ̃|�C���^���i�����w���悤�ɂ��Ă���폜
			cell->right = nullptr;
			cell->under = nullptr;

			//���g���폜
			delete cell;
			//�t�H�[�������
			this->Close();
		}

		/*
		�֐���:childCancel
		�T�v:�q���쐬����̂���߂�
		����:�Ȃ�
		�ԋp�l:�Ȃ�
		�쐬��:9��29��(��)
		�쐬��:���c�C�V
		*/
		void childCancel() {
			//�쐬���悤�Ƃ��Ă����q�̐e���擾����
			ChainData* parent = cell->left;
			//�쐬���悤�Ƃ��Ă����q�Ɏq������Ƃ�
			if (nullptr != cell->right) {
				//�q���擾����
				ChainData* child = cell->right;
				//�e�̎q�Ƃ��Ċi�[
				parent->addRight(child);
			}
			//�q���Ȃ��Ƃ�
			else {
				//�e�̎q�ւ̃|�C���^���i����
				parent->right = nullptr;
			}
			//�f�X�g���N�^�ō폜����Ă��܂��̂Ŏq�ւ̃|�C���^���i�����w���悤�ɂ��Ă���폜
			cell->right = nullptr;

			//���g���폜����
			delete cell;
		}


		/*
		�֐���:buttonCancel_Click
		�T�v:�L�����Z���{�^�����N���b�N���ꂽ�Ƃ��̃C�x���g
		����:�C�x���g�̈���
		�ԋp�l:����
		�쐬��:9��29��(��)
		�쐬��:���c�C�V
		*/
		System::Void buttonCancel_Click(System::Object^  sender, System::EventArgs^  e) {
			//�e�{�^������Ă΂ꂽ�t�H�[���Ȃ�
			if (FormFrom == constants.FROM_PARENT_BUTTON) {
				//�e�̍쐬���L�����Z������֐����s��
				parentCancel();
			}
			//�q����Ă΂ꂽ�t�H�[���Ȃ�
			else if (FormFrom == constants.FROM_CHILD_BUTTON) {
				//�q�̍쐬���L�����Z������֐����s��
				childCancel();
			}
			//�Z��ǂ��炩�̂Ƃ�
			else if (FormFrom == constants.FROM_BIGBRO_BUTTON || FormFrom == constants.FROM_BRO_BUTTON) {
				//���̃Z�����폜����
				this->cell->remove();
			}
			//�t�H�[�������
			this->Close();
		}

		/*
		�֐���:Labels_DoubleClick
		�T�v:���x���Q�̂����ꂩ���N���b�N���ꂽ�Ƃ��̃C�x���g
		����:�C�x���g�̈���
		�ԋp�l:����
		�쐬��:10��2��
		�쐬��:���c�C�V
		*/
		System::Void Labels_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			//�N���b�N���ꂽ���x�����擾
			Label^ selectedLabel = (Label^)sender;
			//���̃��x���̍��W����I�����ꂽ�Z�������Ԗڂ����擾
			int select = ((selectedLabel->Location.X - 20) / 80);
			//�e�̃L�[�Q���擾����
			std::vector<ChainData*> parents = cell->getParents();
			//�ڍ׃t�H�[���̃C���X�^���X�𐶐�����
			CellEditForm^ editForm = gcnew CellEditForm();
			//�t�H�[���ɑI�����ꂽ�Z����n��
			editForm->cell = parents[select];
			//�t�H�[����\��
			editForm->ShowDialog();
		}
	};
}

