#pragma once
#include <vector>
#include <string>

class DataList {
private :
	std::vector<std::string> backgroundList;
	std::vector<std::string> itemList;
	std::vector<std::string> enemyList;
public :
	DataList();
	void dataInput();
	std::string getBackground(int idx);

	std::string getItemList(int idx);
	int getItemListSize();

	std::string getEnemyList(int idx);
	int getEnemyListSize();
};