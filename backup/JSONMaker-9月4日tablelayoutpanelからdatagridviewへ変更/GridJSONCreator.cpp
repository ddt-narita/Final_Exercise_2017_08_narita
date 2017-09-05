#include "GridJSONCreator.h"
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include "Constants.h"

using namespace std;
using namespace boost::property_tree;



GridJSONCreator::GridJSONCreator()
{
}


GridJSONCreator::~GridJSONCreator()
{
}

void GridJSONCreator::init(int rowN, int colN)
{
	grid->init(rowN, colN);

}

string jsonrowdatastr(vector<string> temp) {
	string retStr;
	for (int i = 1; i < temp.size(); i++) {
		if (!retStr.empty()) {
			retStr += ".";
		}
		retStr += temp[i];
	}

	return retStr;
}

//���ۂ�JSON���쐬���郁�\�b�h
void GridJSONCreator::job()
{
	//
	for (int i = 0; i < grid->getGridRowLength(); i++) {
		vector<string> a = getGridRowData(i);
		//�s���Ƃ�JSON
		ptree rowjson;
		for (int j = 0; j < grid->getGridColLength(); j++) {
			vector<string> b;
			string temp = getGrid(i, j);
			b = getGridData(i, j);

			//�擾�����Z���̒l�Ə��ň�ԏ������m�[�h�쐬
			ptree contentjson;
			contentjson.put(b[constants.CONTENT_KEY_INDEX], temp);
			
			//�L�[�����ɔz�u
			ptree keyjson;
			keyjson.add_child(b[constants.KEY_INDEX], contentjson);

			string rowdata = jsonrowdatastr(b);

			rowjson.add_child(rowdata, keyjson);

		}
		string jsonname = getJSONName();

		json.add_child(jsonname, rowjson);
	}

	write_json("", json);
}
