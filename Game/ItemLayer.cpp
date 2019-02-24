#include "ItemLayer.h"

#define ICLEAR "IClear"
#define ICLOAKING "ICloaking"

USING_NS_CC;
using namespace std;

Layer* ItemLayer::createLayer() {
	Layer* itemLayer = ItemLayer::create();
	return itemLayer;
}

bool ItemLayer::init() {
	if (!Layer::init()) { return false; }

	this->scheduleUpdate();
	this->schedule(schedule_selector(ItemLayer::createItem), 10.0f);
	return true;
}

void ItemLayer::update(float delta) {
	// get player Rect data from playerLayer through CollisionData Singleton class
	playerBox = CollisionData::getInstance()->getPlayerBox();
	log("sprite vector size : %d", ItemSprite.size());
}

void ItemLayer::createItem(float delta) {
	srand((unsigned int)time(0));
	int item_num = 0;
	// get filename of item at itemlist db
	string tmp = "", dir = "Item/";
	ifstream item_List("C:/Users/JUIL/project1/Classes/Game/Item/ItemList.txt");
	if (item_List.fail())
		log("itemList file read fail");
	// check the number of item I can use
	while (true) {
		if (item_List.eof()) { break; }
		getline(item_List, tmp);
		item_num++;
	}
	int r_item = rand() % item_num + 1;
	item_List.clear();
	item_List.seekg(0L, ios::beg);
	//read item list randomly in range
	for (int i = 0; i < r_item; i++) { getline(item_List, tmp); }
	setSprite(dir.append(tmp));
}

void ItemLayer::setSprite(string filename) {
	CCSprite* itemSprite = CCSprite::create(filename);
	Vec2 position = Vec2(rand() % 1440, rand() % 720);
	itemSprite->setPosition(position);
	this->addChild(itemSprite);
	ItemSprite.push_back(itemSprite);
}