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
	//�s���擾
	int rowN = getListLength();
	//�z��̃I�u�W�F�N�g���i�[����ϐ�
	ptree arraytree;

	//�s�����J��Ԃ�
	for (int i = 0; i < rowN; i++) {
		//���̍s�̒l���擾����
		string rowvalue = getList(i);
		//�ꎞ�I�Ȏq�I�u�W�F�N�g��p��
		ptree child;
		//�擾�����l����łȂ��Ƃ�
		if (rowvalue != "") {
			//�L�[����̂Ƃ���ɒǉ�
			child.put("", rowvalue);
			//�z��Ƃ��Ēǉ�
			arraytree.push_back(std::make_pair("", child));
		}
	}

	json.add_child("json", arraytree);

	write_json("datalist.json", json);
}
