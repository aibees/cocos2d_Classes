#include "ItemSet.h"

USING_NS_CC;
using namespace std;

ItemSet* ItemSet::Instance = NULL;

ItemSet* ItemSet::getInstance() {
	if (!Instance) {
		Instance = new ItemSet();
	}
	return Instance;
}

ItemSet::ItemSet() {
	ItemQueue.reserve(5);
}

int ItemSet::getQueueSize() {
	return ItemQueue.size();
}

int ItemSet::getQueueCapacity() {
	return ItemQueue.capacity();
}

bool ItemSet::isQueueFull() {
	if (ItemQueue.size() == ItemQueue.capacity())
		return true;
	else
		return false;
}

void ItemSet::insertItem(string itemName) {
	// how change string to item object...?
	
	ItemQueue.push_back(ItemFactory::getInstance()->createItem(itemName));
}

Item* ItemSet::popItem() {
	if (ItemQueue.size() < 1)
		return nullptr;
	Item* item = ItemQueue.front();
	ItemQueue.erase(ItemQueue.begin(), ItemQueue.begin() + 1);
	return item;
}

Item* ItemSet::getItem(int index) {
	return ItemQueue[index];
}