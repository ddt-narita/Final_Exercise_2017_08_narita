#include "ListJSONCreator.h"

using namespace std;
using namespace boost::property_tree;

ListJSONCreator::ListJSONCreator()
{
}


ListJSONCreator::~ListJSONCreator()
{
}

void ListJSONCreator::init(int rowN)
{
	list->init(rowN);
}

std::string ListJSONCreator::getList(int rowN)
{
	return list->getList(rowN);
}

void ListJSONCreator::setList(int rowN, std::string value)
{
	list->setList(rowN, value);
}

int ListJSONCreator::getListLength()
{
	return list->getRowLength();
}

void ListJSONCreator::job()
{
	//行数取得
	int rowN = getListLength();
	//配列のオブジェクトを格納する変数
	ptree arraytree;

	//行数分繰り返す
	for (int i = 0; i < rowN; i++) {
		//その行の値を取得する
		string rowvalue = getList(i);
		//一時的な子オブジェクトを用意
		ptree child;
		//取得した値が空でないとき
		if (rowvalue != "") {
			//キーが空のところに追加
			child.put("", rowvalue);
			//配列として追加
			arraytree.push_back(std::make_pair("", child));
		}
	}

	json.add_child("json", arraytree);

	write_json("datalist.json", json);
}
