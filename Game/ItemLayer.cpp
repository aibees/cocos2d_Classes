#include "ItemLayer.h"

USING_NS_CC;

Layer* ItemLayer::createLayer() {
	Layer* itemLayer = ItemLayer::create();
	return itemLayer;
}

bool ItemLayer::init() {
	if (!Layer::init()) { return false; }

	return true;
}