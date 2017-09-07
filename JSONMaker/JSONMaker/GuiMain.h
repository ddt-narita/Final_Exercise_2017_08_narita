#pragma once
#include "GridJSONCreator.h"
#include "GridInfo.h"
#include "GridRowInfo.h"
#include "Constants.h"
#include "EnvForm.h"
#include "JsonLoader.h"
#include <windows.h>

namespace JSONMaker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

	/// <summary>
	/// GuiMain �̊T�v
	/// </summary>
	public ref class GuiMain : public System::Windows::Forms::Form
	{
	public:
		GuiMain(void)
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
		~GuiMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  GridtabPage;
	protected:

	private: System::Windows::Forms::TabPage^  tabPage2;


	private: System::Windows::Forms::Button^  buttonCancel;

	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::TextBox^  textBoxColN;


	private: System::Windows::Forms::TextBox^  textBoxRowN;

	private: System::Windows::Forms::Label^  GridColLabel;
	private: System::Windows::Forms::Label^  GridRowLabel;
	private: System::Windows::Forms::Button^  buttonJsonCreate;
	private: System::Windows::Forms::Button^  buttonEnv;
	private: System::Windows::Forms::DataGridView^  dataGridViewJSON;







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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->GridtabPage = (gcnew System::Windows::Forms::TabPage());
			this->dataGridViewJSON = (gcnew System::Windows::Forms::DataGridView());
			this->buttonJsonCreate = (gcnew System::Windows::Forms::Button());
			this->GridRowLabel = (gcnew System::Windows::Forms::Label());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->textBoxColN = (gcnew System::Windows::Forms::TextBox());
			this->textBoxRowN = (gcnew System::Windows::Forms::TextBox());
			this->GridColLabel = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->buttonEnv = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->GridtabPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewJSON))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->GridtabPage);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(0, 23);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(648, 441);
			this->tabControl1->TabIndex = 0;
			// 
			// GridtabPage
			// 
			this->GridtabPage->Controls->Add(this->dataGridViewJSON);
			this->GridtabPage->Controls->Add(this->buttonJsonCreate);
			this->GridtabPage->Controls->Add(this->GridRowLabel);
			this->GridtabPage->Controls->Add(this->buttonCancel);
			this->GridtabPage->Controls->Add(this->buttonOK);
			this->GridtabPage->Controls->Add(this->textBoxColN);
			this->GridtabPage->Controls->Add(this->textBoxRowN);
			this->GridtabPage->Controls->Add(this->GridColLabel);
			this->GridtabPage->Location = System::Drawing::Point(4, 22);
			this->GridtabPage->Name = L"GridtabPage";
			this->GridtabPage->Padding = System::Windows::Forms::Padding(3);
			this->GridtabPage->Size = System::Drawing::Size(640, 415);
			this->GridtabPage->TabIndex = 0;
			this->GridtabPage->Text = L"Grid";
			this->GridtabPage->UseVisualStyleBackColor = true;
			// 
			// dataGridViewJSON
			// 
			this->dataGridViewJSON->AllowUserToAddRows = false;
			this->dataGridViewJSON->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridViewJSON->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewJSON->Location = System::Drawing::Point(8, 89);
			this->dataGridViewJSON->Name = L"dataGridViewJSON";
			this->dataGridViewJSON->RowTemplate->Height = 21;
			this->dataGridViewJSON->Size = System::Drawing::Size(624, 320);
			this->dataGridViewJSON->TabIndex = 8;
			this->dataGridViewJSON->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &GuiMain::dataGridViewJSON_CellDoubleClick);
			this->dataGridViewJSON->RowHeaderMouseDoubleClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &GuiMain::dataGridViewJSON_RowHeaderMouseDoubleClick);
			// 
			// buttonJsonCreate
			// 
			this->buttonJsonCreate->Location = System::Drawing::Point(335, 38);
			this->buttonJsonCreate->Name = L"buttonJsonCreate";
			this->buttonJsonCreate->Size = System::Drawing::Size(75, 23);
			this->buttonJsonCreate->TabIndex = 7;
			this->buttonJsonCreate->Text = L"�쐬";
			this->buttonJsonCreate->UseVisualStyleBackColor = true;
			this->buttonJsonCreate->Click += gcnew System::EventHandler(this, &GuiMain::buttonJsonCreate_Click);
			// 
			// GridRowLabel
			// 
			this->GridRowLabel->AutoSize = true;
			this->GridRowLabel->Location = System::Drawing::Point(30, 22);
			this->GridRowLabel->Name = L"GridRowLabel";
			this->GridRowLabel->Size = System::Drawing::Size(22, 12);
			this->GridRowLabel->TabIndex = 0;
			this->GridRowLabel->Text = L"�^�e";
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(547, 46);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 5;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &GuiMain::buttonCancel_Click);
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(547, 17);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 23);
			this->buttonOK->TabIndex = 4;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &GuiMain::buttonOK_Click);
			// 
			// textBoxColN
			// 
			this->textBoxColN->Location = System::Drawing::Point(81, 46);
			this->textBoxColN->Name = L"textBoxColN";
			this->textBoxColN->Size = System::Drawing::Size(100, 19);
			this->textBoxColN->TabIndex = 3;
			// 
			// textBoxRowN
			// 
			this->textBoxRowN->Location = System::Drawing::Point(81, 19);
			this->textBoxRowN->Name = L"textBoxRowN";
			this->textBoxRowN->Size = System::Drawing::Size(100, 19);
			this->textBoxRowN->TabIndex = 2;
			// 
			// GridColLabel
			// 
			this->GridColLabel->AutoSize = true;
			this->GridColLabel->Location = System::Drawing::Point(30, 49);
			this->GridColLabel->Name = L"GridColLabel";
			this->GridColLabel->Size = System::Drawing::Size(21, 12);
			this->GridColLabel->TabIndex = 1;
			this->GridColLabel->Text = L"���R";
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(640, 415);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"List";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// buttonEnv
			// 
			this->buttonEnv->Font = (gcnew System::Drawing::Font(L"�l�r �o�S�V�b�N", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->buttonEnv->Location = System::Drawing::Point(551, 12);
			this->buttonEnv->Name = L"buttonEnv";
			this->buttonEnv->Size = System::Drawing::Size(75, 23);
			this->buttonEnv->TabIndex = 1;
			this->buttonEnv->Text = L"��{";
			this->buttonEnv->UseVisualStyleBackColor = true;
			this->buttonEnv->Click += gcnew System::EventHandler(this, &GuiMain::buttonEnv_Click);
			// 
			// GuiMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(648, 464);
			this->Controls->Add(this->buttonEnv);
			this->Controls->Add(this->tabControl1);
			this->Name = L"GuiMain";
			this->Text = L"GuiMain";
			this->Load += gcnew System::EventHandler(this, &GuiMain::GuiMain_Load);
			this->tabControl1->ResumeLayout(false);
			this->GridtabPage->ResumeLayout(false);
			this->GridtabPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewJSON))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		JsonLoader* jsonLoader;
		GridJSONCreator* gridJsonCreator;


std::string UTF8toSjis(std::string srcUTF8) {
	//Unicode�֕ϊ���̕����񒷂𓾂�
	int lenghtUnicode = MultiByteToWideChar(CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, NULL, 0);

	//�K�v�ȕ�����Unicode������̃o�b�t�@���m��
	wchar_t* bufUnicode = new wchar_t[lenghtUnicode];

	//UTF8����Unicode�֕ϊ�
	MultiByteToWideChar(CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, bufUnicode, lenghtUnicode);

	//ShiftJIS�֕ϊ���̕����񒷂𓾂�
	int lengthSJis = WideCharToMultiByte(CP_THREAD_ACP, 0, bufUnicode, -1, NULL, 0, NULL, NULL);
	//�K�v�ȕ�����ShiftJIS������̃o�b�t�@���m��
	char* bufShiftJis = new char[lengthSJis];

	//Unicode����ShiftJIS�֕ϊ�
	WideCharToMultiByte(CP_THREAD_ACP, 0, bufUnicode, lenghtUnicode + 1, bufShiftJis, lengthSJis, NULL, NULL);

	std::string strSJis(bufShiftJis);
	
	delete bufUnicode;
	delete bufShiftJis;

	return strSJis;
}

std::string SjistoUTF8(std::string srcSjis) {
	//Unicode�֕ϊ���̕����񒷂𓾂�
	int lenghtUnicode = MultiByteToWideChar(CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, NULL, 0);

	//�K�v�ȕ�����Unicode������̃o�b�t�@���m��
	wchar_t* bufUnicode = new wchar_t[lenghtUnicode];

	//ShiftJIS����Unicode�֕ϊ�
	MultiByteToWideChar(CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, bufUnicode, lenghtUnicode);


	//UTF8�֕ϊ���̕����񒷂𓾂�
	int lengthUTF8 = WideCharToMultiByte(CP_UTF8, 0, bufUnicode, -1, NULL, 0, NULL, NULL);

	//�K�v�ȕ�����UTF8������̃o�b�t�@���m��
	char* bufUTF8 = new char[lengthUTF8];

	//Unicode����UTF8�֕ϊ�
	WideCharToMultiByte(CP_UTF8, 0, bufUnicode, lenghtUnicode + 1, bufUTF8, lengthUTF8, NULL, NULL);

	std::string strUTF8(bufUTF8);

	delete bufUnicode;
	delete bufUTF8;

	return strUTF8;
}


	//OK�{�^���������̃C�x���g
	private: System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
		//���C�A�E�g�̍쐬����߂�i�`�悪���������߁j
		this->SuspendLayout();
		
		//JSON�ǂݍ��݂̎�
		if (jsonLoader->jsonmanager->isJSONFilePathSet()) {

			jsonLoader->run();

			int rowN = jsonLoader->jsonmanager->getGridRowLength();
			int colN = jsonLoader->jsonmanager->getGridColLength();

			//�܂��\���쐬���Ă��Ȃ������Ȃ�
			if (dataGridViewJSON->RowCount < 1) {
				//�����{�^��
				DataGridViewButtonColumn^ button = gcnew DataGridViewButtonColumn();
				button->Name = "bind";
				button->UseColumnTextForButtonValue = true;
				button->Text = "����";

				//�����{�^�����ǉ�
				dataGridViewJSON->Columns->Add(button);
			}


			dataGridViewJSON->RowCount = rowN;
			dataGridViewJSON->ColumnCount = colN + 1;
			
			for (int i = 0; i < rowN; i++) {
				for (int j = 0; j < colN; j++) {
					(dataGridViewJSON->Rows[i]->Cells[j + 1]->Value) = gcnew String(UTF8toSjis(jsonLoader->jsonmanager->getGrid(i, j)).c_str());
				}
			}

		}
		else {
			//���͂���Ă���^�e�̒������擾
			int rowN = Convert::ToInt32(textBoxRowN->Text);
			//���͂���Ă��郈�R�̒������擾
			int colN = Convert::ToInt32(textBoxColN->Text);
			gridJsonCreator->jsonmanager->setGridRowLen(rowN);
			gridJsonCreator->jsonmanager->setGridMaxColLen(colN);

			gridJsonCreator->init(rowN, colN);


			//�܂��\���쐬���Ă��Ȃ������Ȃ�
			if (dataGridViewJSON->RowCount < 1) {
				//�����{�^��
				DataGridViewButtonColumn^ button = gcnew DataGridViewButtonColumn();
				button->Name = "bind";
				button->UseColumnTextForButtonValue = true;
				button->Text = "����";

				//�����{�^�����ǉ�
				dataGridViewJSON->Columns->Add(button);
			}

			//tablelayoutpanel�̏c���̒������擾�����l�ɐݒ�
			dataGridViewJSON->RowCount = rowN;
			dataGridViewJSON->ColumnCount = colN + 1;
		}

		//���C�A�E�g�̕\�����J�n����
		this->ResumeLayout(false);
		this->PerformLayout();
 	}
	

//�L�����Z���{�^�����N���b�N�����Ƃ��̃C�x���g
//�\�̃R���g���[�������ׂč폜
private: System::Void buttonCancel_Click(System::Object^  sender, System::EventArgs^  e) {
	//�`�揈������U��~
	this->SuspendLayout();
	//�s���擾
	int rowcount = dataGridViewJSON->RowCount;
	//�s�����J��Ԃ��đS�s�폜
	for (int i = 0; i < rowcount; i++) {
		dataGridViewJSON->Rows->RemoveAt(0);
	}
	//�s���񐔂�0�ɂ���
	dataGridViewJSON->ColumnCount = 0;
	dataGridViewJSON->RowCount = 0;

	//�`�揈���������Ȃ�
	this->ResumeLayout(false);
	this->PerformLayout();
}

//�쐬�{�^���������̃C�x���g
private: System::Void buttonJsonCreate_Click(System::Object^  sender, System::EventArgs^  e) {
	//���͂��ꂽ�\�̑傫�����擾����
	int rowN = gridJsonCreator->jsonmanager->getGridRowLength();
	int colN = gridJsonCreator->jsonmanager->getGridColLength();

	//�\�̍s�����J��Ԃ�
	for (int i = 0; i < rowN; i++) {
		//�\�̗񐔕��J��Ԃ�
		for (int j = 0; j < colN; j++) {
			//���̈ʒu�ɓ��͂���Ă���Z���̒l���擾����(cells��+1�͌����{�^���̂���)
			String^ temp = (String^)(dataGridViewJSON->Rows[i]->Cells[j + 1]->Value);
			
			temp = temp == nullptr ? "" : temp;

			//String�^����string�^�֕ϊ�����
			std::string str = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(temp).ToPointer();
			//�ϊ������O���b�h�̒l���Z�b�g
			gridJsonCreator->jsonmanager->setGrid(i, j, str);
		}
	}
	//�Z�b�g���ꂽ�l��JSON���쐬����
	gridJsonCreator->job();

	//�쐬���I�����烁���o��JSON���N���A����
	gridJsonCreator->jsonmanager->jsonClear();

	MessageBox::Show("JSON�쐬�����I�I", "�ʒm");

}

//�Z�����_�u���N���b�N�����ۂ̃C�x���g
private: System::Void dataGridViewJSON_CellDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
{
	//�s���񐔎擾
	int rown = dataGridViewJSON->CurrentCell->RowIndex;
	int coln = dataGridViewJSON->CurrentCell->ColumnIndex - 1;

	//�����{�^���łȂ����
	if (coln >= 0) {
		//�Z���̏��擾
		std::vector<std::string>tempt(gridJsonCreator->jsonmanager->getGridData(rown, coln));
		//�Z���̏��Ƃ���
		array<String^>^ cellinfo_CLI = gcnew array<String^>(constants.CELL_INFO_NUMBER);
		//�Z���̏��̐������J��Ԃ�(2��)
		for (int i = 0; i < constants.CELL_INFO_NUMBER; i++) {
			cellinfo_CLI[i] = gcnew String(tempt[i].c_str());
		}

		//�Z���̏�����͂���t�H�[���̃C���X�^���X�𐶐�
		GridInfo^ gridinfo = gcnew GridInfo();
		//�e����n��
		gridinfo->key = cellinfo_CLI[constants.KEY_INDEX];
		gridinfo->contentKey = cellinfo_CLI[constants.CONTENT_KEY_INDEX];
		gridinfo->rowN = rown + 1;
		gridinfo->colN = coln + 1;

		//�Z���̏������[�_���\��
		gridinfo->ShowDialog();

		//���͂��ꂽ�����擾
		cellinfo_CLI[constants.KEY_INDEX] = gridinfo->key;
		cellinfo_CLI[constants.CONTENT_KEY_INDEX] = gridinfo->contentKey;

		//�R���e���g�L�[�Ɛe�̃L�[�̂ݎ擾
		for (int i = 0; i < constants.CELL_INFO_NUMBER; i++) {
			//������ւ̕ϊ�
			tempt[i] = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(cellinfo_CLI[i]).ToPointer();
		}

		//���͂��ꂽ�f�[�^���O���b�h�Ǘ��N���X�ɃZ�b�g
		gridJsonCreator->jsonmanager->setGridData(rown, coln, tempt);
	}
}


//�s���Ƃ̏�����͂���t�H�[���\��
private: System::Void dataGridViewJSON_RowHeaderMouseDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e) {
	//�I������Ă���s�����s�ڂ��擾
	int rowN = dataGridViewJSON->CurrentRow->Index;
	//���̍s�̏����擾����
	std::vector<std::string> tempvec = gridJsonCreator->jsonmanager->getGridRowData(rowN);

	//�s���Ƃ̏�����͂���t�H�[���̃C���X�^���X�𐶐�
	GridRowInfo^ rowInfo = gcnew GridRowInfo();

	//�s���Ƃ̏��̗v�f�����̔z����m�ہivector��array�ւ̕ϊ��葱���j
	//(size() - constan)�c�͂��ꂪ�Ȃ��ƍs�̏���\�������邽�тɍs�������Ă����Ă��܂�����(DataGridView�̎d�l)
	array<String^>^ temparray = gcnew array<String^>(tempvec.size() - constants.ROW_INFO_ADJUSTER);
	//�擾�������̐������J��Ԃ��ăR�s�[
	for (int i = 0; i < tempvec.size() - 1; i++) {
		String^ tempstr = gcnew String(tempvec[i].c_str());
		temparray[i] = tempstr;
	}

	//�s���Ƃ̏��z����t�H�[���ɓn��
	rowInfo->gridRowInfo = temparray;
	//���s�ڂ��̏����t�H�[���ɓn��
	rowInfo->rowNumber = rowN;

	//�t�H�[�������[�_���\��
	rowInfo->ShowDialog();

	//�z����N���A
	tempvec.clear();
	//�s���Ƃ̏��̐������J��Ԃ�
	for (int i = 0; i < rowInfo->gridRowInfo->Length; i++) {
		//�t�H�[���̏ォ�珇�Ƀf�[�^���i�[
		std::string temp = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(rowInfo->gridRowInfo[i]).ToPointer();
		//�z��Ɋi�[
		tempvec.push_back(temp);
	}
	//�i�[�����f�[�^�����̍s�̃f�[�^�Ƃ��ăZ�b�g
	gridJsonCreator->jsonmanager->setGridRowData(rowN, tempvec);
}


//�����{�^���������ꂽ�Ƃ��̃C�x���g
private: System::Void dataGridViewJSON_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	DataGridView^ dgv = (DataGridView^)sender;
	//"bind"�񂪃N���b�N���ꂽ�Ƃ�(�����{�^���������ꂽ�Ƃ�)
	if (dgv->Columns[e->ColumnIndex]->Name == "bind")
	{
		//
		GuiMain::dataGridViewJSON_CellPainting(sender, (DataGridViewCellPaintingEventArgs^)e);
	}
}

//�Z���̌���
private: System::Void dataGridViewJSON_CellPainting(System::Object^  sender, System::Windows::Forms::DataGridViewCellPaintingEventArgs^  e) {
	
	//if (dataGridViewJSON->CurrentCell->ColumnIndex < 0) {
	//	DataGridView^ dv = (DataGridView^)(sender);
	//	//Rectangle^ rect;
	//	DataGridViewCell^ cell;

	//	rect = e->CellBounds;
	//	cell = dataGridViewJSON[e->ColumnIndex + 1, e->RowIndex];
	//	// ��E�̃Z���̕��𑫂�
	//	rect->Width += cell->Size.Width;
	//	rect->X -= 1;
	//	rect->Y -= 1;
	//	e->Graphics->FillRectangle(gcnew SolidBrush(e->CellStyle->BackColor), *rect);
	//	e->Graphics->DrawRectangle(gcnew Pen(dv->GridColor), *rect);
	//	TextRenderer::DrawText(e->Graphics, e->FormattedValue->ToString(), e->CellStyle->Font, *rect, e->CellStyle->ForeColor, TextFormatFlags::HorizontalCenter | TextFormatFlags::VerticalCenter);
	//	e->Handled = true;
	//}
}


//���{�^���������ꂽ�Ƃ��̃C�x���g
private: System::Void buttonEnv_Click(System::Object^  sender, System::EventArgs^  e) {
	//���ݒ���̓t�H�[���̃C���X�^���X�𐶐�
	EnvForm^ envform = gcnew EnvForm();

	//���݂̏���n��
	envform->JSONFilePath = gcnew String(jsonLoader->jsonmanager->getJsonFilePath().c_str());
	//envform->DBName		  = gcnew String(jsonLoader->getDBName().c_str());
	//envform->Query		  = gcnew String(jsonLoader->getQuery().c_str());
	//���[�_���\������
	envform->ShowDialog();

	std::string filepath = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(envform->JSONFilePath).ToPointer();

	//�p�X���擾���ăZ�b�g����
	jsonLoader->jsonmanager->setJsonFilePath(filepath);

}

//
private: System::Void GuiMain_Load(System::Object^  sender, System::EventArgs^  e) {
	jsonLoader = new JsonLoader();
	gridJsonCreator = new GridJSONCreator;

	jsonLoader->jsonmanager = gridJsonCreator->jsonmanager = new JSONManager();
}
};
}
