#pragma once
#include "InputForm.h"
#include <map>

namespace ControlTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm �̊T�v
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button2;








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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(12, 46);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(473, 351);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			this->pictureBox1->DoubleClick += gcnew System::EventHandler(this, &MyForm::pictureBox1_DoubleClick);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 17);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"BitMap";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::BitMapButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(629, 440);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
		int rowN = 80;		//�s��
		int colN = 20;		//��
		int rectHigh = 20;	//�Z���̍���
		int rectWidth = 60;	//�Z���̕�
		
		ref class selectedCell {

		};

		//�e�Z���̏����i�[����}�b�v
		std::map<std::string, std::string> *valueMap;

		//�s�Ɨ�̉�����}�b�v�ɔz�u����L�[���쐬
		String^ coordinateString(int rowN, int colN) {
			String^ ret = rowN.ToString() + ":" + colN.ToString();
			return ret;
		}

private: System::Void BitMapButton_Click(System::Object^  sender, System::EventArgs^  e) {	

	this->SuspendLayout();

	this->pictureBox1->Size = System::Drawing::Size(colN * rectWidth, rowN * rectHigh);

	//�`���Ƃ���Image�I�u�W�F�N�g���쐬����
	Bitmap^ canvas = gcnew Bitmap(pictureBox1->Width - 1, pictureBox1->Height - 1);
	//Image�I�u�W�F�N�g��Graphics�I�u�W�F�N�g���쐬����
	Graphics^ g = Graphics::FromImage(canvas);

	//Pen�I�u�W�F�N�g�̍쐬(��3���F)
	Pen^ p = gcnew Pen(System::Drawing::Color::Black, 3);

	for (int i = 0; i < rowN; i++) {
		for (int j = 0; j < colN; j++) {
			//���͂��鐔�l
			String^ drawString = (j + (colN * i)).ToString();
			//�s�Ɨ񂩂�L�[�쐬
			std::string key = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(coordinateString(i, j)).ToPointer();
			//�l��std::string�ɒ���
			std::string value = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(drawString).ToPointer();
			//�����o�ɕێ�����
			(*valueMap)[key] = value;

			//Font���쐬
			System::Drawing::Font^ fnt = gcnew System::Drawing::Font("�l�r �S�V�b�N", 12);
			//�������\������͈͂��w�肷��
			RectangleF^ rect = gcnew RectangleF(j * rectWidth, i * rectHigh, rectWidth, rectHigh);
			//�Z�����ƂɃ^�e�̐����쐬����
			g->DrawLine(p, Point(j *rectWidth, i * rectHigh), Point(j * rectWidth, (i + 1) * rectHigh));

			//rect�̎l�p��`��
			g->FillRectangle(Brushes::White, *rect);
			//����������
			g->DrawString(drawString, fnt, Brushes::Black, *rect);
		}
		
		//�s���Ƃɍs�̐���`��
		g->DrawLine(p, Point(0,(i + 1) * rectHigh), Point(colN * rectWidth, (i + 1) * rectHigh));
	}

	//PictureBox1�ɕ\������
	pictureBox1->Image = canvas;
	pictureBox1->Visible = true;

	this->ResumeLayout(false);
	this->PerformLayout();
}


private: System::Void ButtonBindRelease_Click(System::Object^  sender, System::EventArgs^  e) {
	
	int nowX = this->AutoScrollPosition.X;
	int nowY = this->AutoScrollPosition.Y;

	//�}�E�X�N���b�N���ꂽ���W���擾
	int x = ((MouseEventArgs^)e)->X;
	int y = ((MouseEventArgs^)e)->Y;

	//�擾�������W����ǂ̍s�ǂ̗񂩂��擾
	int selectedColN = x / rectWidth;
	int selectedRowN = y / rectHigh;

	//���͂��邽�߂̃t�H�[���쐬
	InputForm^ iForm = gcnew InputForm();

	//�L�[���쐬
	String^ temp = coordinateString(selectedRowN, selectedColN);

	//�L�[�̕������std::string�ɕϊ�
	std::string key = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(temp).ToPointer();
	
	//�L�[�̈ʒu�̏����t�H�[���ɓn��
	iForm->value = gcnew String((*valueMap)[key].c_str());

	iForm->ShowDialog();
	

	//�t�H�[���ɓ��͂��ꂽ�l���擾
	String^ drawString = iForm->value;

	//�擾�����l��std::string�ɒ���
	std::string value = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(drawString).ToPointer();
	//�������l��ۊ�
	(*valueMap)[key] = value;


	//�`��I�u�W�F�N�g��\������pictureBox����쐬
	Graphics^ g = Graphics::FromImage(pictureBox1->Image);
	//�ォ�珑�����߂̎l�p�`���쐬
	RectangleF^ rect = gcnew RectangleF(selectedColN * rectWidth, selectedRowN * rectHigh, rectWidth - 1, rectHigh-1);
	//�t�H���g���쐬
	System::Drawing::Font^ fnt = gcnew System::Drawing::Font("�l�r �S�V�b�N", 12);
	//rect�̎l�p��`��
	g->FillRectangle(Brushes::White, *rect);
	//�擾�����l�̕�������l�p�`�ɏ���
	g->DrawString(drawString, fnt, Brushes::Black, *rect);
	
	//�t�H�[����\���������߃g�b�v�ɖ߂��Ă��܂��̂ŃC�x���g��������̈ʒu�ɖ߂�
	this->AutoScrollPosition = Point(nowX, -nowY);
	//�ĕ`��𖾎�����
	pictureBox1->Invalidate();

	
}

private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	//�l��ۊǂ���}�b�v�̃C���X�^���X����
	valueMap = new std::map<std::string, std::string>();
}

private: System::Void MyForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	delete valueMap;
}

private: System::Void pictureBox1_DoubleClick(System::Object^  sender, System::EventArgs^  e) {

}
};
}
