#include "IClear.h"

USING_NS_CC;

IClear::IClear() {
	IClear(Vec2(IClear::getDefaultPosition()));
	name = "IClear";
}

IClear::IClear(Vec2 position) {
	IClear::Position = position;
	
}

Vec2 IClear::getDefaultPosition() {
	Size visible = Director::getInstance()->getVisibleSize();
	return Vec2(visible.width / 2, visible.height / 2);
}

Vec2 IClear::getPosition() {
	return Position;
}

void IClear::setPosition(Vec2 position) {
	Position = position;
}

std::string IClear::getItemName() {
	return name;
}

void IClear::effect() {
	EventCustom clear("setClear");
	_eventDispatcher->dispatchEvent(&clear);
}