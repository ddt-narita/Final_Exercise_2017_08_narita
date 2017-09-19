#pragma once
#include "DataGridSelfMade.h"

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




	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::Button^  buttonCancel;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  buttonAdd;
	private: System::Windows::Forms::Button^  buttonPopBack;





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
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->buttonPopBack = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(80, 20);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(82, 23);
			this->buttonOK->TabIndex = 4;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &GridInfo::buttonOK_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonCancel->Location = System::Drawing::Point(181, 20);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(81, 23);
			this->buttonCancel->TabIndex = 5;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 12);
			this->label1->TabIndex = 7;
			this->label1->Text = L"label1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(14, 82);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(10, 10);
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &GridInfo::Cell_Click);
			// 
			// buttonAdd
			// 
			this->buttonAdd->Location = System::Drawing::Point(80, 49);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(82, 23);
			this->buttonAdd->TabIndex = 9;
			this->buttonAdd->Text = L"�ǉ�";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &GridInfo::buttonAdd_Click);
			// 
			// buttonPopBack
			// 
			this->buttonPopBack->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->buttonPopBack->Location = System::Drawing::Point(181, 49);
			this->buttonPopBack->Name = L"buttonPopBack";
			this->buttonPopBack->Size = System::Drawing::Size(81, 23);
			this->buttonPopBack->TabIndex = 10;
			this->buttonPopBack->Text = L"����폜";
			this->buttonPopBack->UseVisualStyleBackColor = true;
			this->buttonPopBack->Click += gcnew System::EventHandler(this, &GridInfo::buttonPopBack_Click);
			// 
			// GridInfo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->CancelButton = this->buttonCancel;
			this->ClientSize = System::Drawing::Size(396, 421);
			this->Controls->Add(this->buttonPopBack);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonOK);
			this->Name = L"GridInfo";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"GridInfo";
			this->Load += gcnew System::EventHandler(this, &GridInfo::GridInfo_Load);
			this->Click += gcnew System::EventHandler(this, &GridInfo::GridInfo_Click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private:
	narita::DataGridSelfMade^ DataGridCellInfo;
	//�s�̏���ۊǂ��郁���o
	array<String^>^ _gridInfo;
public:
	
	
	public:
		int rowN;
		int colN;
		//�s�̏��v���p�e�B�[
		property array<String^>^ gridInfo {
			array<String^>^ get() {
				return _gridInfo;
			}

			void set(array<String^>^ temp) {
				int len = temp->Length;
				_gridInfo = gcnew array<String^>(len);

				for (int i = 0; i < len; i++) {
					_gridInfo[i] = temp[i];
				}

			}
		}

/*
�֐���:buttonOK_Click
�T�v:OK�{�^�����N���b�N���ꂽ�Ƃ��̃C�x���g
����:�C�x���g�̈���
�ԋp�l:
�쐬��:9��15��(��)
�쐬��:���c�C�V
*/
private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
	//���͂��ꂽ���Q�̍s�����擾
	int rowN = DataGridCellInfo->rowCount;

	//�����o�ɃZ�b�g����p�̍s���̒����̈ꎞ�z����쐬
	array<String^>^ temp = gcnew array<String^>(rowN);
	//�s�̒����������J��Ԃ�
	for (int i = 0; i < rowN; i++) {
		//���͂���Ă�������ꎞ�z��Ɋi�[
		temp[i] = DataGridCellInfo[DataGridCellInfo->CreateGridMapKey(i,1)] == nullptr ? "" : DataGridCellInfo[DataGridCellInfo->CreateGridMapKey(i, 1)];
	}
	//�����o�ɔ��f
	gridInfo = temp;
	//�t�H�[�������
	this->Close();
}

		 /*
		 �֐���:GridInfo_Load
		 �T�v:���̃t�H�[���������オ�����Ƃ��̃C�x���g
		 ����:�C�x���g�̈���
		 �ԋp�l:����
		 �쐬��:9��15��(��)
		 �쐬��:���c�C�V
		 */
private: System::Void GridInfo_Load(System::Object^  sender, System::EventArgs^  e) {
	//�����o�ɓn���ꂽ���̔z��̒������擾
	int rowLen = gridInfo->Length;
	//�s�N�`���{�b�N�X��n����dataGrid�̃C���X�^���X�𐶐�
	DataGridCellInfo = gcnew narita::DataGridSelfMade(pictureBox1);
	
	//�\�̍s�����擾�������̐��ɂ���
	DataGridCellInfo->rowCount = rowLen;
	//���Ԗڂ��ƃL�[��\�������݂̂Ȃ̂�2��
	DataGridCellInfo->colCount = 2;

	//���̐������J��Ԃ�
	for (int i = 0; i < rowLen; i++) {
		//���Ԗڂ̃L�[�\����
		DataGridCellInfo[DataGridCellInfo->CreateGridMapKey(i, 0)] = "Key[" + i.ToString() + "]";
		//�L�[�����Ԃɔz�u
		DataGridCellInfo[DataGridCellInfo->CreateGridMapKey(i, 1)] = gridInfo[i];
	}
	//�\��`��
	DataGridCellInfo->Paint();

	//���x���ɉ��s�A����ڂ̃Z���̏��Ȃ̂���\��
	label1->Text = rowN.ToString() + "�s" + colN.ToString() + "��";
}


		 /*
		 �֐���:pictureBox_Click	
		 �T�v:�Z�����N���b�N���ꂽ���̃C�x���g
		 ����:�C�x���g�̈���
		 �ԋp�l:����
		 �쐬��:9��15��(��)
		 �쐬��:���c�C�V
		 */
private: System::Void Cell_Click(System::Object^  sender, System::EventArgs^  e) {
	//�N���b�N���ꂽ����擾
	int col = ((MouseEventArgs^)e)->X / DataGridCellInfo->cellWidth;
	//���Ԗڂ���\���ҏW�s�̗�łȂ����
	if (col != 0) {
		//���̃Z�����N���b�N���ꂽ�Ƃ��ă��\�b�h�Ăяo��
		DataGridCellInfo->cell_click(e);
	}
	//�ҏW�s�̗�ł����
	else {
		//�I�𒆂̃Z�������Ƃɖ߂���
		DataGridCellInfo->drawCell(DataGridCellInfo->currentCell, Brushes::White);
		//�J�����g�̃Z����-1,-1�ɐݒ�
		DataGridCellInfo->currentCell = gcnew narita::Cell(-1, -1);
	}
	//�`��𑣂�
	pictureBox1->Invalidate();
}
		 
		 /*
		 �֐���:GridInfo_Click
		 �T�v:�t�H�[���̃Z���ȊO�̕������N���b�N���ꂽ�Ƃ��̃C�x���g
		 ����:�C�x���g�̈���
		 �ԋp�l:�Ȃ�
		 �쐬��:9��15��(��)
		 �쐬��:���c�C�V
		 */
private: System::Void GridInfo_Click(System::Object^  sender, System::EventArgs^  e) {
	//�J�����g�̃Z����-1,-1�ɐݒ�
	DataGridCellInfo->currentCell = gcnew narita::Cell(-1, -1);
	//���̃Z�����N���b�N���ꂽ���Ƃɂ��ă��\�b�h�Ăяo��
	DataGridCellInfo->cell_click(DataGridCellInfo->currentCell);
	//�ĕ`��𑣂�
	pictureBox1->Invalidate();
}

		 /*
		 �֐���:buttonAdd_Click
		 �T�v:�ǉ��{�^�����N���b�N���ꂽ�Ƃ��̃C�x���g
		 ����:�C�x���g�̈���
		 �ԋp�l:����
		 �쐬��:9��15��(��)
		 �쐬��:���c�C�V
		 */
private: System::Void buttonAdd_Click(System::Object^  sender, System::EventArgs^  e) {
	//�\�̍s����1�ǉ�
	DataGridCellInfo->rowCount += 1;
	//���̒ǉ����ꂽ�s��1��ڂɉ��ڂ̃L�[�����i�[
	DataGridCellInfo[DataGridCellInfo->CreateGridMapKey((DataGridCellInfo->rowCount - 1), 0)] = "Key[" + (DataGridCellInfo->rowCount - 1).ToString() + "]";
	//2��ڂɂ͋󕶎���
	DataGridCellInfo[DataGridCellInfo->CreateGridMapKey((DataGridCellInfo->rowCount - 1), 1)] = "";
	//�����o�̔z��̑傫�����X�V
	Array::Resize(_gridInfo, DataGridCellInfo->rowCount);
	//���̃����o�̔z��̐V�����쐬���������ɋ󕶎��z�u
	gridInfo[DataGridCellInfo->rowCount - 1] = "";
	//�\��`��
	DataGridCellInfo->Paint();
}

		 /*
		 �֐���:buttonPopBack_Click
		 �T�v:����폜�{�^���������ꂽ�Ƃ��̃C�x���g
		 ����:�C�x���g�̈���
		 �ԋp�l:�Ȃ�
		 �쐬��:9��15��(��)
		 �쐬��:���c�C�V
		 */
private: System::Void buttonPopBack_Click(System::Object^  sender, System::EventArgs^  e) {
	//�s����0�Ȃ�
	if (DataGridCellInfo->rowCount == 0) {
		//�������炷�s���Ȃ����Ƃ�\��
		MessageBox::Show("����ȏ㌸�点�܂���","�x��",MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	//1�ȏ�Ȃ�
	else {
		//�\��1�s���炷
		DataGridCellInfo->rowCount -= 1;
		//�ĕ`��
		DataGridCellInfo->Paint();
	}
}
};
}
