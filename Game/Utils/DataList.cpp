#include "DataList.h"

using namespace std;

DataList::DataList() {
	dataInput();
}

void DataList::dataInput() {
	backgroundList = {
		"Level_1.png",
		"Level_2.png"
	};
	itemList = {
		"IClear.png",
		"ICloaking.png"
	};
}

string DataList::getBackground(int idx) {
	return backgroundList[idx];
}

string DataList::getItemList(int idx) {
	return itemList[idx];
}

int DataList::getItemListSize() { return itemList.size(); }

std::string DataList::getEnemyList(int idx)
{
	return enemyList[idx];
}

int DataList::getEnemyListSize()
{
	return enemyList.size();
}
