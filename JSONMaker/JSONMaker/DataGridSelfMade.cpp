#include "DataGridSelfMade.h"
#include "Constants.h"

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
	//�Z�����Ƃ̃N���X������
	//������
	colCount = 1;
	//�����s��
	rowCount = 1;
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
	//text->LostFocus += gcnew EventHandler(this, &DataGridSelfMade::textboxLostFocus);
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
�ύX��:9��20��(��)
�ύX��:���c�C�V
���e:�Z�����Ƃ̃f�[�^��cell�ւ̕ύX
*/
Void DataGridSelfMade::SelectedCell_click(int row, int col) {
	//�������ꂽ�s�Ȃ�
	if (checkBound(row)) {
		//�傫���A�ʒu���������ꂽ�Z���̑傫���ɍ��킹��
		text->Size = System::Drawing::Size(cellWidth * colCount - 1, cellHeight - 1);
		text->Location = Point(0, cellHeight * row);
	}
	//�������ꂽ�s�łȂ�
	else {
		//�ʏ�̃Z���̑傫���E�ʒu�ɍ��킹��
		text->Size = System::Drawing::Size(cellWidth - 1, cellHeight - 1);
		text->Location = Point(col * cellWidth, row * cellHeight);
	}
	//
	text->Text = gcnew String(((cell->getKey(row, col)).c_str()));
	//�i���̎��͋󕶎�����
	text->Text = (text->Text == nullptr ? "" : text->Text);

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
�ύX��:9��20��(��)
�ύX��:���c�C�V
���e:��������Ă���s�ɂ��Ă��̎��I������Ă�����̎擾���Z���N���X����擾��
*/
Void DataGridSelfMade::notSelectedCell_click(int row, int col) {
	//���\������Ă���e�L�X�g�{�b�N�X���\���ɂ���
	text->Visible = false;
	//�����ȃZ�����I������Ă���Ƃ��͉������Ȃ�
	if (!currentCell->isExist()) {
		int i = 0;
	}
	//�Z�����I�u�W�F�N�g�ւ̔z��Ȃ�
	else if (cell->getCell(currentCell->row, currentCell->col)->isObject()) {
		//�I�u�W�F�N�g�p�̐F�ɖ߂�
		drawCell(currentCell, Brushes::LemonChiffon);
	}
	//����ȊO�Ȃ�
	else {
		//�J�����g�̃Z���ɂ��ĐF�����Ƃɖ߂�
		drawCell(currentCell, Brushes::White);
	}
	//�J�����g�̍s�E��Ƃ��Ɏ擾�����l��
	currentCell->row = row;
	currentCell->col = col;

}

/*
�֐���:Cell_click
�T�v:�Z�����N���b�N���ꂽ�Ƃ��̊֐�
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
	//���߂đI�����ꂽ�Ƃ��̏����̊֐������s
	this->notSelectedCell_click(row, col);

	//�J�����g�̃Z���𐅐F�ŕ\��
	drawCell(currentCell, Brushes::Aqua);
	//�`��𑣂��ĕύX�𔽉f
	pictureBox->Invalidate();
}

/*
�֐���:cell_click
�T�v:�Z�����N���b�N���ꂽ�Ƃ��̊֐�(�I�[�o�[���[�h)
����:Cell^ cell �Z��
�ԋp�l:�Ȃ�
�쐬��:���c�C�V
�쐬��:9��15��(��)
*/
Void narita::DataGridSelfMade::cell_click(Cell ^ cell)
{
	//�����̃Z���̍s���񐔂œ����֐����Ăяo���B
	cell_click(cell->row, cell->col);
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
	//�`�����Ƃ��Ă���Z���������Ȏ���
	if (row < 0 || col < 0) {
		//�������I������
		return;
	}
	//�Z�����������߂̎l�p�`��p��
	RectangleF^ rect;
	String^ value;
	//��������I�����ꂽ�Z�����擾����
	ChainData* selectCell = cell->getCell(row, col);
	//�����̈ʒu�̕\�����̏����擾�@�Ȃ���΋󕶎�
	if (selectCell != nullptr && selectCell->isValid()) {
		//�f�[�^���L���Ȓl�Ȃ�
		if (!selectCell->isObject()) {
			//�L�[�Ƃ��̒l��
			value = gcnew String(("key:" + selectCell->key + "\nvalue:" + selectCell->value).c_str());
		}
		//�I�u�W�F�N�g�z��ւ̋�̃I�u�W�F�N�g�ł���Ƃ�
		else if (selectCell->isEmptyCellToObjectArray()) {
			//�I�u�W�F�N�g�z��ł��邱�Ƃ�\������
			value = "arrayObject";
		}
		//�I�u�W�F�N�g�Ȃ�
		else {
			//�L�[�݂̂�\������
			value = gcnew String(selectCell->key.c_str());
		}
	}
	//�i���Ȃ�
	else {
		//�󕶎������Ă���
		value = "";
	}
	//���̃Z���𕢂��l�p�`���쐬
	rect = gcnew RectangleF(col * this->cellWidth, row * this->cellHeight, this->cellWidth - 1, this->cellHeight - 1);

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
	return false;

}

/*
�֐���:selectedColFromBoundRow
�T�v:�����̌������ꂽ�s�̌������ꂽ�Ƃ��ɑI�����ꂽ���Ԃ��֐�
����:int row �������ꂽ�s
�ԋp�l:int col�@�������ꂽ���I������Ă�����
�쐬��:9��15��(��)
�쐬��:���c�C�V
�ύX��:9��20��(��)
�ύX��:���c�C�V
���e:�\���Ǘ�����N���X�̕ύX�ɂ�肷�ׂĕύX
*/
int narita::DataGridSelfMade::selectedColFromBoundRow(int row)
{
	return 0;
}

/*
�֐���:BindRelease
�T�v:�����^�������郁�\�b�h
����:int row,int col �s�Ɨ�
�ԋp�l:�Ȃ�
�쐬��:9��9��
�쐬��:���c�C�V
�쐬��:9��15��(��)
*/
Void DataGridSelfMade::BindRelease(int row, int col)
{
	//CellChain^ cell = this->cell;
	////�������ꂽ�s��
	//if (checkBound(row)) {
	//	//���̍s�̐擪�̃Z���ɂ��̍s����������Ă邩�ǂ����̒l�𖳌���
	//	cell->getCell(row, 0)->isBound = false;
	//	//���̍s�̑I������Ă�����̒l���擾
	//	int selectedCol = cell->getSelectedColFromRow(row);
	//	//���̃Z�����I������Ă������Ƃ𖳌��ɂ���
	//	cell->getCell(row, selectedCol)->isSelectedCol = false;
	//	//�񐔕��J��Ԃ�
	//	for (int i = 0; i < colCount; i++) {
	//		graphic->DrawLine(cellFramePen, Point(i * cellWidth, row * cellHeight), Point(i * cellWidth, (row + 1) * cellHeight));
	//		//���̍s�̃Z�������ׂĕ`��
	//		drawCell(row, i, Brushes::White);
	//	}
	//	drawCell(currentCell, Brushes::Aqua);
	//}
	////�������ꂽ�s�ł͂Ȃ��Ȃ�
	//else {
	//	//���̍s�̐擪�̃Z���Ɍ������ꂽ�s�ł���Ƃ�����
	//	cell->getCell(row, 0)->isBound = true;
	//	//�w��̃Z�����������ꂽ�Ƃ��I�����ꂽ�񂾂Ƃ�����
	//	cell->getCell(row, col)->isSelectedCol = true;
	//	
	//	//���̍s���������ꂽ�s�Ƃ��ĕ`��
	//	drawCell(row, col, Brushes::Aqua);
	//}
	//text->Visible = false;
	//return Void();
}

Void narita::DataGridSelfMade::setRowColFromChain()
{
	//�s�̐擪�ƂȂ�f�[�^���擾(�e�̐擪)
	ChainData* parentCurrent = cell->getCell(0, 0);
	int rowCount = 0;	//�s�������߂�
	int colCount = 0;	//�񐔂����߂�
	int lastValidRow = 0;
	//�e�ɂ��Ă��ׂđ���
	while (nullptr != parentCurrent) {
		//�q�̐��𐔂���
		int childCol = 0;
		int lastValidChild = 0;
		//�q���擾
		ChainData* childCurrent = parentCurrent->right;
		//�q�ɂ��Ă��ׂđ���
		while (nullptr != childCurrent) {
			//�Z��̐��𐔂���
			childCol++;
			//�Z�����L���Ȃ�
			if (childCurrent->isValid()) {
				//���̎��̒l�����Ă���
				lastValidChild = childCol;
			}
			//�Z��Ɉړ�
			childCurrent = childCurrent->under;
		}
		//���܂܂ł̗񐔂��q�̐�����������
		if (colCount < lastValidChild) {
			//���̐���񐔂ɂ���
			colCount = lastValidChild;
		}
		//�s�̐������Z����
		rowCount++;

		//�L���ȃZ���Ȃ�
		if (parentCurrent->isValid()) {
			//���̎��̍s�̒l��ۊǂ���
			lastValidRow = rowCount;
		}
		//�Z��ֈړ�
		parentCurrent = parentCurrent->under;
	}

	//���߂��s���񐔂ɃZ�b�g����
	this->rowCount = lastValidRow;
	this->colCount = colCount;
	//������ƍs�������
	if (this->rowCount > 0) {
		//�擪�̗񕪃v���X����
		this->colCount += 1;
	}
	return Void();
}

Void narita::DataGridSelfMade::adjustCell()
{
	//�s�̐擪�̃Z�����擾
	ChainData* parentCurrent = cell->getCell(0, 0);
	//�s�����J��Ԃ�
	for (int i = 0; i < rowCount; i++) {
		//�q���Ȃ��Ƃ�
		if (nullptr == parentCurrent->right) {
			//�q���쐬
			parentCurrent->addRight(new ChainData());
			//���ߍ��킹�ł��邱�Ƃ������l���i�[
			parentCurrent->right->valid = false;
		}

		//��̐擪�̃Z�����擾
		ChainData* childCurrent = parentCurrent->right;
		//�񐔕��J��Ԃ�(���̎q�̕��ƁA�񐔂͐擪���܂܂�Ă��܂��Ă���̂�-2)
		for (int j = 0; j < colCount - 2; j++) {
			//�J�����g�̃Z���̉��̌Z�킪�i���̎�
			if (nullptr == childCurrent->under) {
				//���ɃZ����ǉ�
				childCurrent->addUnder(new ChainData());
				//���ߍ��킹�ł��邱�Ƃ������l���i�[
				childCurrent->under->valid = false;
			}
			//���̌Z��ֈړ�
			childCurrent = childCurrent->under;
		}
		//�e�����̐e�ֈړ�
		parentCurrent = parentCurrent->under;
	}

	return Void();
}

Void narita::DataGridSelfMade::View()
{
	//�s���Ɨ񐔂��Z���`�F�[���ɍ��킹��
	setRowColFromChain();
	//��ȂǂŖ��܂��Ă��Ȃ������ɂ��Ė��ߍ��킹��
	adjustCell();
	//�`�悷��
	Paint();
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
	//�s����̂ǂ��炩��0�Ȃ�\��������̂͂Ȃ��̂ŉ������Ȃ�
	if (rowCount == 0 || colCount == 0) {
		return;
	}
	//�s�N�`���[�{�b�N�X�̑傫����ݒ肳��Ă���s���񐔂ɍ��킹��
	pictureBox->Size = System::Drawing::Size(colCount * cellWidth, rowCount * cellHeight);
	//�s�N�`���[�{�b�N�X�̑傫���ɍ��킹�ĕ`���̃I�u�W�F�N�g�𐶐����Ȃ���
	pictureBox->Image = gcnew Bitmap(pictureBox->Width, pictureBox->Height);
	//���̕`���ɕ`�悷��I�u�W�F�N�g���쐬
	graphic = Graphics::FromImage(pictureBox->Image);

	//�s�����J��Ԃ�
	for (int i = 0; i < rowCount; i++) {
		//�񐔕��J��Ԃ�
		for (int j = 0; j < colCount; j++) {
			//�Z���̋�؂�̐���`��
			graphic->DrawLine(cellFramePen, Point(j * cellWidth, i * cellHeight), Point(j * cellWidth, (i + 1) * cellHeight));
			//�I�u�W�F�N�g�Ȃ�
			if (cell->getCell(i, j)->isObject()) {
				//�F��ς��ĕ`��
				drawCell(i, j, Brushes::LemonChiffon);
			}
			//����ȊO�Ȃ�
			else {
				//�ʏ�̐F�ŕ`��
				drawCell(i, j, Brushes::White);
			}
		}
		//�s���Ɛ���`��
		graphic->DrawLine(cellFramePen, Point(0, (i + 1) * cellHeight), Point(colCount * cellWidth, (i + 1) * cellHeight));
	}
	//���C���@�J�����g�̃Z���̂���s���Ȃ��Ȃ������Z���̒l���擾�ł�����
	//��O���o��̂ōs���񐔂�葽���Ƃ��̓J�����g�̃Z����`�悵�Ȃ�
	if (currentCell->row < rowCount && currentCell->col < colCount) {
		//�J�����g�̃Z���ɂ��ĕ`�悷��
		drawCell(currentCell, Brushes::Aqua);
	}
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
		//���͂���Ă����l�����̍��W�̒l�Ƃ��ĕۊ� @mod�Z���N���X�̂��̈ʒu�̃Z���Ɋi�[����悤�ɕύX
		cell->getCell(row, col)->key = constants.StrToc_str(tempBox->Text);
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

	//�e�L�X�g�{�b�N�X�ɓ��͂��ꂽ�l�����̍��W�̒l�Ƃ��ĕۊ� @mod�ۊǑΏۂ��Z���N���X�ɕύX
	cell->setKey(row, col, constants.StrToc_str(text->Text));
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

	this->rowCount = 0;
	this->colCount = 0;
	this->currentCell->Reset();
}