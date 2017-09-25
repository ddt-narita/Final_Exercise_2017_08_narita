#pragma once
#include "Cell.h"
#include "CellChain.h"

namespace narita {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	ref class DataGridSelfMade
	{
	private:
		PictureBox^ pictureBox;	//�`�悵�����̂�z�u����s�N�`���[�{�b�N�X
		Bitmap^ canvas;			//�`���̃I�u�W�F�N�g
		Graphics^ graphic;		//�`�悷�邽�߂̃I�u�W�F�N�g
		Pen^ cellFramePen;		//�Z���̘g���������߂̃y���I�u�W�F�N�g
		Font^ font;				//�t�H���g
		

		int _colCount;	//��
		int _rowCount;	//�s��

		

	public:
		int cellWidth;	//�Z���̕�
		int cellHeight;	//�Z���̍���
		//�\��\������̂Ɏg���Z�����Ƃ̃N���X
		CellChain^ cell;
		TextBox^ text;	//�e�L�X�g�{�b�N�X
		//�񐔂̃v���p�e�B�[
		property int colCount {
			int get() {
				return _colCount;
			}
			void set(int col) {
				_colCount = col;
				cell->colCount = col;
			}
		}
		//�s���̃v���p�e�B�[
		property int rowCount {
			int get() {
				return _rowCount;
			}
			void set(int row) {
				_rowCount = row;
				cell->rowCount = row;
			}
		}
		//���ݑI�𒆂̃Z��
		Cell^ currentCell;

		//�R���X�g���N�^
		DataGridSelfMade(PictureBox^ pictureBox);

		//�N���b�N���ꂽ�Ƃ��̓���
		Void cell_click(EventArgs^ e);
		Void cell_click(int row, int col);
		Void cell_click(Cell^ cell);
		Void SelectedCell_click(int row, int col);
		Void notSelectedCell_click(int row, int col);
		//�\�����̒l���擾���邽�߂̃L�[���쐬����֐�
		String^ CreateGridMapKey(int row, int col);
		//�w��̍s�A��Ɉ����̐F�̃Z����`�悷��֐�
		Void drawCell(int row, int col, Brush^ color);
		//�������Z���̎�
		Void drawCell(Cell^ cell, Brush ^ color);
		//�����̍s���������ꂽ�s�Ȃ̂��𔻒肷��֐�
		Boolean checkBound(int row);
		int selectedColFromBoundRow(int row);
		//�����̈ʒu�̃Z���������^��������֐�
		Void BindRelease(int row, int col);
		//�S�̂��ꂩ��`�悷�郁�\�b�h
		Void Paint();
		//�\�����̃f�[�^���N���A����֐�
		Void Clear();

	private:Void textboxEnter(System::Object^  sender, Windows::Forms::KeyEventArgs^  e);
	Void textboxLostFocus(System::Object ^ sender, EventArgs ^ e);
	};

}