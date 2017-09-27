#pragma once
#ifndef __CellChain
#define __CellChain

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>

ref class CellChain
{
public:
	//‚»‚ÌƒZƒ‹‚ÉŠi”[‚³‚ê‚½ƒL[ŒQ
	boost::property_tree::ptree* CellData;
	int rowCount;	//s”‘SƒZƒ‹‹¤’Ê
	int colCount;	//—ñ”
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
	boost::property_tree::ptree* getCellData(int row, int col);
	void setValue(int row, int col, System::String^ value);
	void setCellData(int row, int col, boost::property_tree::ptree* cellData);
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

#endif // !__CellChain