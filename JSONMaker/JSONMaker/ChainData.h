#pragma once
#include <string>
#include "boost\property_tree\ptree.hpp"
#include "Constants.h"

class ChainData
{
public:
	ChainData();
	~ChainData();

	std::string key;
	std::string value;
	bool valid;
	enum FrontBack {
		Front,
		Back
	};

	ChainData* upper;
	ChainData* under;
	ChainData* right;
	ChainData* left;

	ChainData* insertFront();
	ChainData* insertBack();
	ChainData* insert(FrontBack);
	void remove();
	ChainData* insertRow(int row, FrontBack);
	void insertCol(int col, FrontBack);
	void removeRow(int row);
	void removeCol(int col);
	ChainData* createParent();
	ChainData* createChild();

	ChainData* getCell(int row, int col);
	std::string getKey(int row, int col);
	void setKey(int row, int col, std::string value);
	std::string getValue(int row, int col);
	void setValue(int row, int col, std::string value);
	void addRight(ChainData* temp);
	void addLeft(ChainData* temp);
	void addUpper(ChainData* temp);
	void addUnder(ChainData* temp);
	int getChildCount();
	std::vector<ChainData*> getParents();

	bool isObject();
	void Clear();
	bool isValid();
	bool isCellToArray();
	bool isCellToObjectArray();

};

