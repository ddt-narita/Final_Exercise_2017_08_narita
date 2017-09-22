#pragma once
ref class CellChain
{
public:
	//���̃Z���Ɋi�[���ꂽ�L�[�Q
	array < System::String^ >^ CellKey;
	static int rowCount;	//�s���S�Z������
	static int colCount;	//��
	CellChain^ CurrentCell;
	System::String^ Value;
	bool isBound;
	bool isSelectedCol;

	CellChain^ upper;
	CellChain^ under;
	CellChain^ left;
	CellChain^ right;

	CellChain();
	~CellChain() { this->!CellChain(); };
	!CellChain() {};

	CellChain^ insert(int row, int col);
	void remove(int row, int col);
	CellChain^ insertRow(int row);
	void removeRow(int row);
	void insertCol(int col);
	void removeCol(int col);

	void init(int row, int col);
	CellChain^ getCell(int row, int col);
	System::String^ getValue(int row, int col);
	array<System::String^>^ getCellKey(int row, int col);
	void setValue(int row, int col, System::String^ value);
	void setCellKey(int row, int col, array<System::String^>^ cellKeys);
	void next();
	void beforeFirst();
	void addRight(CellChain^ temp);
	void addLeft(CellChain^ temp);
	void addUpper(CellChain^ temp);
	void addUnder(CellChain^ temp);
	int getSelectedColFromRow(int row);
	void Clear();
	bool isCellValid();

	CellChain^ operator=(CellChain^ temp);
};

