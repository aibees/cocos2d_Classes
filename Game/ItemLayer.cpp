#include "ItemLayer.h"
#include "Item/ItemSet.h"

USING_NS_CC;
using namespace std;

Layer* ItemLayer::createLayer() {
	Layer* itemLayer = ItemLayer::create();
	return itemLayer;
}

bool ItemLayer::init() {
	if (!Layer::init()) { return false; }
	setItemFrame();
	this->scheduleUpdate();
	this->schedule(schedule_selector(ItemLayer::createItem), 4.0f);
	ItemCreateFlag = false;
	return true;
}

void ItemLayer::setItemFrame() { //Frame sprite is tagged in 100's numbering
	int num = ItemSet::getInstance()->getQueueCapacity();
	auto visible = Director::getInstance()->getVisibleSize();
	Sprite* ItemFrame[5] = {nullptr, };
	for (int i = 0; i < num; i++) {
		ItemFrame[i] = Sprite::create("Item/ItemFrame.png");
		ItemFrame[i]->setAnchorPoint(Vec2(0, 1));
		ItemFrame[i]->setScale(1.7f);
		Rect box = ItemFrame[i]->getBoundingBox();
		ItemFrame[i]->setPosition(Vec2(visible.width - (box.getMaxX() - box.getMinX()), visible.height - i*(box.getMaxY() - box.getMinY())));
		ItemFrame[i]->setTag(100 + i);
		this->addChild(ItemFrame[i], 1);
	}
	return;
}

void ItemLayer::update(float delta) {
	// get player Rect data from playerLayer through CollisionData Singleton class
	playerBox = CollisionData::getInstance()->getPlayerBox();
	// loop for detecting collision
	for (auto it = ItemSprite.begin(); it != ItemSprite.end(); it++) {
		if (((*it)->getBoundingBox()).intersectsCircle(Vec2(playerBox.getMidX(), playerBox.getMidY()), (playerBox.getMidX() - playerBox.getMinX()))) {
			// if collision detected between player and any item, remove that itemSprite
				// log("collision detected : %f || %f", (*it)->getPosition().x, (*it)->getPosition().y);
			if (!ItemSet::getInstance()->isQueueFull()) {
				ItemSet::getInstance()->insertItem((*it)->getName());
				log("itemQueueSize : %d", ItemSet::getInstance()->getQueueSize());
			}
			auto sp = (*it);
			ItemSprite.erase(it);
			sp->removeFromParent();
			break;
		}
	}
	// Item Frame update
	int num = ItemSet::getInstance()->getQueueSize();
	for(int i = 0; i < num; i++) {
		if (ItemSet::getInstance()->getItem(i) == nullptr)
			break;
		CCSprite* frame = static_cast<CCSprite*>(getChildByTag(100 + i));
		string SpriteName = "Item/";
		SpriteName.append(ItemSet::getInstance()->getItem(i)->getItemName());
		SpriteName.append(".png");
		CCSprite* item = CCSprite::create(SpriteName);
		item->setAnchorPoint(Vec2(1, 1));
		item->setPosition(Vec2((frame->getBoundingBox().getMaxX() - frame->getBoundingBox().getMinX()) / 2, (frame->getBoundingBox().getMaxY() - frame->getBoundingBox().getMinY()) / 2));
		frame->addChild(item);
		/*
			TODO1 : Alignment between item & frame
			TODO2 : sprite remove process when player use item
		*/
	}
	
		
	// schedule control
	if(ItemSet::getInstance()->isQueueFull()) {
		this->unschedule(schedule_selector(ItemLayer::createItem));
		ItemCreateFlag = true;
	}
	if (!ItemSet::getInstance()->isQueueFull() && ItemCreateFlag) {
		this->schedule(schedule_selector(ItemLayer::createItem), 4.0f);
		ItemCreateFlag = false;
	}
}

void ItemLayer::createItem(float delta) {
	srand((unsigned int)time(0));
	int item_num = 0;
	// get filename of item at itemlist db
	string tmp = "", dir = "Item/";
	ifstream item_List("D:/workspace/mygame/Classes/Game/Item/ItemList.txt");
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
	setSprite(dir.append(tmp), tmp);
}

void ItemLayer::setSprite(string filename, string name) {
	srand(time(NULL));
	CCSprite* itemSprite = CCSprite::create(filename);
	Vec2 position = Vec2(rand()*rand() % 1480, rand()*rand() % 720);
	itemSprite->setPosition(position);
	itemSprite->setName(name);
	this->addChild(itemSprite);
	ItemSprite.push_back(itemSprite);
}