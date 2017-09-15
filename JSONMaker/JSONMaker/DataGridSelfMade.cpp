#include "DataGridSelfMade.h"

using namespace narita;

/*
�֐���:�R���X�g���N�^
�T�v:�`���̃s�N�`���[�{�b�N�X���󂯎���Ă��ꂩ��͂����֔z�u����
����:PictureBox^ pictureBox�@�`�悵�����̂̔z�u��
�ԋp�l:����
�쐬��:9��9��
�쐬��:���c�C�V
*/
DataGridSelfMade::DataGridSelfMade(PictureBox^ pictureBox)
{
	//�󂯎�����`�悵�����̂�z�u����I�u�W�F�N�g�������o�ɋ��L
	(this->pictureBox) = pictureBox;
	//�\�̒l
	GridData = gcnew Dictionary<String^, String^>();
	//��������Ă���s�Ƃ��̎��I������Ă�����
	BoundRow = gcnew Dictionary<String^, String^>();
	//������
	colCount = 5;
	//�����s��
	rowCount = 5;
	//�Z���̕�
	cellWidth = 120;
	//�Z���̍���
	cellHeight = 80;
	//�J�����g�Z�����쐬
	currentCell = gcnew narita::Cell();
	
	//�Z���̘g��`���y���I�u�W�F�N�g���쐬
	cellFramePen = gcnew Pen(Color::Black, 3);
	//������������Ƃ��̃t�H���g
	font = gcnew Font("�l�r �S�V�b�N", 9);
	
	//�`��Ώۂ̃C���[�W�I�u�W�F�N�g
	this->canvas = gcnew Bitmap(this->pictureBox->Width - 1, this->pictureBox->Height - 1);
	//�쐬�����C���[�W�I�u�W�F�N�g���s�N�`���{�b�N�X�ɔz�u
	this->pictureBox->Image = this->canvas;
	//�s�N�`���{�b�N�X�`��Ώۂɕ`�����߂̃I�u�W�F�N�g���쐬
	this->graphic = Graphics::FromImage(this->pictureBox->Image);
	//�I�����ꂽ�Z���ɕ\������e�L�X�g�{�b�N�X��\������
	text = gcnew TextBox();
	text->Multiline = true;
	text->AutoSize = false;
	text->ImeMode = ImeMode::Off;
	pictureBox->Controls->Add(text);
	text->KeyDown += gcnew KeyEventHandler(this, &DataGridSelfMade::textboxEnter);
	text->LostFocus += gcnew EventHandler(this, &DataGridSelfMade::textboxLostFocus);
	text->BackColor = Color::Aqua;
	text->Visible = false;
}

/*
�֐���:cell_Click
�T�v:�Z�����N���b�N���ꂽ�Ƃ��̓���
����:����
�ԋp�l:�Ȃ�
�쐬��:9��9��
�쐬��:���c�C�V
*/
Void DataGridSelfMade::cell_click(System::EventArgs^ e)
{
	int row = ((MouseEventArgs^)e)->Y / this->cellHeight;
	int col = ((MouseEventArgs^)e)->X / this->cellWidth;

	this->cell_click(row, col);

}

/*
�֐���:selectedCell_click
�T�v:�I���ς݂̃Z�����N���b�N���ꂽ�Ƃ��̊֐�
����:int row�@�Z���̍s, int col�@�Z���̗�
�ԋp�l:�Ȃ�
�쐬��:9��15��
�쐬��:���c�C�V
*/
Void DataGridSelfMade::SelectedCell_click(int row, int col) {
	//�������ꂽ�s�Ȃ�
	if (checkBound(row)) {
		//�傫���A�ʒu���������ꂽ�Z���̑傫���ɍ��킹��
		text->Size = System::Drawing::Size(cellWidth * colCount - 1, cellHeight - 1);
		text->Location = Point(0, cellHeight * rowCount);
	}
	//�������ꂽ�s�łȂ�
	else {
		//�ʏ�̃Z���̑傫���E�ʒu�ɍ��킹��
		text->Size = System::Drawing::Size(cellWidth - 1, cellHeight - 1);
		text->Location = Point(col * cellWidth, row * cellHeight);
	}

	//���̈ʒu�ɒl�����݂��Ă����
	if (GridData->ContainsKey(CreateGridMapKey(row, col))) {
		//�l���擾����
		text->Text = this->GridData[CreateGridMapKey(row, col)];
	}
	//���݂��Ȃ����
	else {
		//�󕶎���\��������
		text->Text = "";
	}
	//�e�L�X�g�{�b�N�X��\��
	text->Visible = true;
	//�����ɓ��͂ł���悤�Ƀt�H�[�J�X��u��
	text->Focus();
}

/*
�֐���:notSelectedCell_click
�T�v:���߂đI�����ꂽ�Z�����N���b�N���ꂽ�Ƃ��̊֐�
����:int row�@�Z���̍s, int col�@�Z���̗�
�ԋp�l:�Ȃ�
�쐬��:9��15��
�쐬��:���c�C�V
*/
Void DataGridSelfMade::notSelectedCell_click(int row, int col) {
	//���\������Ă���e�L�X�g�{�b�N�X���\���ɂ���
	text->Visible = false;
	//�J�����g�̃Z���ɂ��ĐF�����Ƃɖ߂�
	drawCell(currentCell, Brushes::White);

	//�������ꂽ�s�Ȃ�
	if (checkBound(row)) {
		//�J�����g�̃Z��������̍s�ɂ���
		currentCell->row = row;
		//�������ꂽ�Ƃ��ɑI�����ꂽ��ɂ���
		currentCell->col = Int32::Parse(BoundRow[row.ToString()]);
	}
	//�ʏ�̃Z���Ȃ�
	else {
		//�s�E��Ƃ��Ɏ擾�����l��
		currentCell->row = row;
		currentCell->col = col;
	}
}

/*
�֐���:selectedCell_click
�T�v:�I���ς݂̃Z�����N���b�N���ꂽ�Ƃ��̊֐�
����:int row�@�Z���̍s, int col�@�Z���̗�
�ԋp�l:�Ȃ�
�쐬��:9��10��
�쐬��:���c�C�V
�ύX��:9��15��
�ύX��:���c�C�V
���e:�I���ς݂̎��Ə��߂đI�����ꂽ���̃Z���̓�����T�u�֐���(�X�e�b�v���̊֌W)
*/
Void narita::DataGridSelfMade::cell_click(int row, int col)
{
	//���łɑI���ς݂̃Z�����N���b�N�����Ƃ�
	if (currentCell->col == col && currentCell->row == row && currentCell->row != -1) {
		//�I���ς݂̃Z�����N���b�N���ꂽ�Ƃ��̏����̊֐������s
		this->SelectedCell_click(row, col);
	}
	//���߂đI�������Ȃ�
	else {
		//���߂đI�����ꂽ�Ƃ��̏����̊֐������s
		this->notSelectedCell_click(row, col);
	}
	//�J�����g�̃Z���𐅐F�ŕ\��
	drawCell(currentCell, Brushes::Aqua);
	//�`��𑣂��ĕύX�𔽉f
	pictureBox->Invalidate();
}

/*
�֐���:
�T�v:
����:
�ԋp�l:
�쐬��:���c�C�V
�쐬��:9��15��(��)
*/
Void narita::DataGridSelfMade::cell_click(Cell ^ cell)
{
	//�����̃Z���̍s���񐔂œ����֐����Ăяo���B
	cell_click(cell->row, cell->col);
}

/*
�֐���:CreateGridMapKey
�T�v:�����̍s�Ɨ񂩂�}�b�v�̃L�[���쐬����
����:int row, int col�@�s�Ɨ�
�ԋp�l:String^ �쐬�����L�[
�쐬��:9��9��
�쐬��:���c�C�V
*/
String^ DataGridSelfMade::CreateGridMapKey(int row, int col)
{
	//"�s�F��"�̌`�̃L�[���쐬���ĕԋp����
	return row.ToString() + ":" + col.ToString();
}

/*
�֐���:drawCell
�T�v:�����̍s�Ɨ�̂��̂ɂ��ăZ����`�悷��֐�
����:int row�@�s, int col�@��, Brush^ color�@�Z���̐F
�ԋp�l:����
�쐬��:9��9��
�쐬��:���c�C�V
*/
Void DataGridSelfMade::drawCell(int row, int col, Brush ^ color)
{
	//�Z�����������߂̎l�p�`��p��
	RectangleF^ rect;
	String^ value;
	String^ key = CreateGridMapKey(row, col);
	//�����̈ʒu�̕\�����̏����擾�@�Ȃ���΋󕶎�
	if (GridData->ContainsKey(key)) {
		value = this->GridData[key];
	}
	else {
		value = "";
	}
	//�����̍s���������ꂽ�s�Ȃ̂����擾
	if (checkBound(row)) {
		//�s�S�̂𕢂��`�̎l�p�`���쐬
		rect = gcnew RectangleF(0, row * this->cellHeight, this->colCount * this->cellWidth - 1, cellHeight -1);
	}
	//��������Ă��Ȃ��Ƃ�
	else {
		//���̃Z���𕢂��l�p�`���쐬
		rect = gcnew RectangleF(col * this->cellWidth, row * this->cellHeight, this->cellWidth - 1, this->cellHeight -1);
	}
	//�l�p�`�������̐F�ɂ���
	graphic->FillRectangle(color, *rect);
	//�l�p�`�Ɏ擾�������������������
	graphic->DrawString(value, font, Brushes::Black, *rect);
	
}

/*
�֐���:drawCell
�T�v:�Z����`�悷��֐�
����:
�ԋp�l:
�쐬��:9��9��
�쐬��:���c�C�V
*/
Void DataGridSelfMade::drawCell(Cell ^ cell, Brush ^ color)
{
	//�J�����g�̃Z���̍s�Ɨ�Ŋ֐����Ăяo��
	drawCell(cell->row, cell->col, color);
}

/*
�֐���:checkBound
�T�v:�����̍s����������Ă��邩�𔻒�
����:int row ����ׂ����s
�ԋp�l:boolean ��������Ă��邩�ǂ����𔻒�
�쐬��:9��9��
�쐬��:���c�C�V
*/
Boolean DataGridSelfMade::checkBound(int row)
{
	//�������ꂽ�s���Ǘ����郁���o��������̍s���L�[�Ƃ�����̂����邩�ǂ����Ō������Ă��邩�𔻒�
	return BoundRow->ContainsKey(row.ToString());
}

/*
�֐���:selectedColFromBoundRow
�T�v:�����̌������ꂽ�s�̌������ꂽ�Ƃ��ɑI�����ꂽ���Ԃ��֐�
����:int row �������ꂽ�s
�ԋp�l:int col�@�������ꂽ���I������Ă�����
�쐬��:���c�C�V
�쐬��:9��15��(��)
*/
int narita::DataGridSelfMade::selectedColFromBoundRow(int row)
{
	//�������ꂽ�s���Ǘ����郁���o���炻�̎��I�����ꂽ��𒊏o���ĕԋp����B
	return Int32::Parse(BoundRow[row.ToString()]);
}

/*
�֐���:BindRelease
�T�v:�����^�������郁�\�b�h
����:int row,int col �s�Ɨ�
�ԋp�l:�Ȃ�
�쐬��:9��9��
�쐬��:���c�C�V
*/
Void DataGridSelfMade::BindRelease(int row, int col)
{
	//�������ꂽ�s��
	if (checkBound(row)) {
		//���̍s���L�[�Ƃ�����̂���菜���Č������ꂽ�s�ł͂Ȃ��Ƃ���
		BoundRow->Remove(row.ToString());
		//�񐔕��J��Ԃ�
		for (int i = 0; i < colCount; i++) {
			graphic->DrawLine(cellFramePen, Point(i * cellWidth, row * cellHeight), Point(i * cellWidth, (row + 1) * cellHeight));
			//���̍s�̃Z�������ׂĕ`��
			drawCell(row, i, Brushes::White);
		}
		drawCell(currentCell, Brushes::Aqua);
	}
	//�������ꂽ�s�ł͂Ȃ��Ȃ�
	else {
		//�����Ǘ��̃����o�ɂ��̍s���L�[�A�I�����ꂽ���l�Ƃ��Ď�������
		BoundRow[row.ToString()] = col.ToString();
		//���̍s���������ꂽ�s�Ƃ��ĕ`��
		drawCell(row, col, Brushes::Aqua);
	}
	return Void();
}

/*
�֐���:paint
�T�v:�S�̂�`�悷��֐�
����:����
�ԋp�l:����
�쐬��:9��9��
�쐬��:���c�C�V
*/
Void DataGridSelfMade::Paint()
{
	//�s�N�`���[�{�b�N�X�̑傫����ݒ肳��Ă���s���񐔂ɍ��킹��
	pictureBox->Size = System::Drawing::Size(colCount * cellWidth, rowCount * cellHeight);
	//�s�N�`���[�{�b�N�X�̑傫���ɍ��킹�ĕ`���̃I�u�W�F�N�g�𐶐����Ȃ���
	pictureBox->Image = gcnew Bitmap(pictureBox->Width,pictureBox->Height);
	//���̕`���ɕ`�悷��I�u�W�F�N�g���쐬
	graphic = Graphics::FromImage(pictureBox->Image);

	//�s�����J��Ԃ�
	for (int i = 0; i < rowCount; i++) {
		//�������ꂽ�s�Ȃ�
		if (checkBound(i)) {
			//�������ꂽ�Ƃ��ɑI�����ꂽ����擾
			int selectedColFromBoundRow = Int32::Parse(BoundRow[i.ToString()]);
			//�������ꂽ�s�ɂ��ĕ`��
			drawCell(i, selectedColFromBoundRow + 1, Brushes::White);
		}
		//��������Ă��Ȃ��Ȃ�
		else {
			//�񐔕��J��Ԃ�
			for (int j = 0; j < colCount; j++) {
				//�Z���̋�؂�̐���`��
				graphic->DrawLine(cellFramePen, Point(j * cellWidth, i * cellHeight), Point(j * cellWidth, (i + 1) * cellHeight));
				//���̃Z����`�悷��
				drawCell(i, j, Brushes::White);
			}
		}
		//�s���Ɛ���`��
		graphic->DrawLine(cellFramePen, Point(0, (i+1) * cellHeight), Point(colCount * cellWidth, (i+1) * cellHeight));
	}
	//�J�����g�̃Z���ɂ��ĕ`�悷��
	drawCell(currentCell, Brushes::Aqua);
}

/*
�֐���:textboxEnter
�T�v:�e�L�X�g�{�b�N�X�t�H�[�J�X���ɃC���^�[�L�[�������ꂽ�Ƃ��̃C�x���g
����:����
�ԋp�l:����
�쐬��:9��11��
�쐬��:���c�C�V
*/
Void DataGridSelfMade::textboxEnter(System::Object ^ sender, KeyEventArgs ^ e)
{
	//�������̃e�L�X�g�{�b�N�X���擾
	TextBox^ tempBox = (TextBox^)sender;

	//�e�L�X�g�{�b�N�X�̍��W���擾
	int col = tempBox->Location.X / cellWidth;
	int row = tempBox->Location.Y / cellHeight;

	//�G���^�[�L�[��������Ă�����
	if (e->KeyValue == (int)Keys::Return) {
		//���͂���Ă����l�����̍��W�̒l�Ƃ��ĕۊ�
		GridData[this->CreateGridMapKey(row, col)] = tempBox->Text;
		//�e�L�X�g�{�b�N�X���\���ɂ���
		tempBox->Visible = false;
		//�J�����g�̃Z���𐅐F��
		drawCell(row, col, Brushes::Aqua);
	}
	return Void();
}

/*
�֐���:textboxLostFocus
�T�v:�t�H�[�J�X���������Ƃ��̃C�x���g
����:����
�ԋp�l:����
�쐬��:9��11��
�쐬��:���c�C�V
*/
Void DataGridSelfMade::textboxLostFocus(System::Object ^ sender, EventArgs ^ e)
{
	//�C�x���g���̃e�L�X�g�{�b�N�X���擾
	TextBox^ tempBox = (TextBox^)sender;

	//���W���擾
	int col = tempBox->Location.X / cellWidth;
	int row = tempBox->Location.Y / cellHeight;

	//�e�L�X�g�{�b�N�X�ɓ��͂��ꂽ�l�����̍��W�̒l�Ƃ��ĕۊ�
	GridData[this->CreateGridMapKey(row, col)] = tempBox->Text;
	//��\���ɂ���
	tempBox->Visible = false;
	//�t�H�[�J�X�����ꂽ�̂Ŕ��F��
	drawCell(row, col, Brushes::White);
	
	return Void();
}

/*
�֐���:Clear
�T�v:�ꂩ�����悤�ɃN���X������������֐�
����:�Ȃ�
�ԋp�l:�Ȃ�
�쐬��:9��14��(��)
�쐬��:���c�C�V
*/
Void DataGridSelfMade::Clear() {
	this->BoundRow->Clear();
	this->GridData->Clear();
	this->rowCount = 0;
	this->colCount = 0;
	this->currentCell->col = 0;
	this->currentCell->row = 0;
}