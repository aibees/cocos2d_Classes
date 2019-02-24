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
	itemQueue.reserve(5);
}

int ItemSet::getQueueSize() {
	return itemQueue.size();
}