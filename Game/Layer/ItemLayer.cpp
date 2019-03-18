#include "ItemLayer.h"

USING_NS_CC;
using namespace std;

Layer* ItemLayer::createLayer() {
	Layer* itemLayer = ItemLayer::create();
	return itemLayer;
}

bool ItemLayer::init() {
	if (!Layer::init()) { return false; }
	setItemFrame();
	dataList = new DataList();
	this->scheduleUpdate();
	this->schedule(schedule_selector(ItemLayer::createItem), 4.0f);
	ItemCreateFlag = false;

	// button event listener
	EventListenerCustom* buttonListener = EventListenerCustom::create("ItemEffect", CC_CALLBACK_1(ItemLayer::itemCallback, this));
	_eventDispatcher->addEventListenerWithFixedPriority(buttonListener, 1);
	return true;
}

void ItemLayer::itemCallback(EventCustom* event) {
	auto item = ItemSet::getInstance()->popItem();
	updateFrame();
	if (item == nullptr) {
		log("queue is empty");
		return;
	}
	item->effect();
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

void ItemLayer::updateFrame() {
	int num = ItemSet::getInstance()->getQueueSize();
	for (int i = 0; i < num + 1; i++) {
		this->removeChildByTag(200 + i);
	}
	for (int i = 0; i < num; i++) {
		if (ItemSet::getInstance()->getItem(i) == nullptr)
			break;
		CCSprite* frame = static_cast<CCSprite*>(getChildByTag(100 + i));
		string SpriteName = "Item/" + ItemSet::getInstance()->getItem(i)->getItemName() + ".png";
		CCSprite* item = CCSprite::create(SpriteName);
		item->setAnchorPoint(Vec2(0.5, 0.5));
		item->setTag(200 + i);
		item->setPosition(Vec2(frame->getBoundingBox().getMidX(), frame->getBoundingBox().getMidY()));
		this->addChild(item, 2);
	}
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
			updateFrame();
			break;
		}
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
	// get filename of item at itemlist db
	int r_item = rand() % (dataList->getItemListSize());
	string dir = "Item/", tmp = "";
	tmp = dataList->getItemList(r_item);
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