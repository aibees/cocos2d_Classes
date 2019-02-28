#include "ICloaking.h"

USING_NS_CC;

ICloaking::ICloaking() {
	ICloaking(Vec2(ICloaking::getDefaultPosition()));
}

ICloaking::ICloaking(Vec2 position) {
	ICloaking::Position = position;
	name = "ICloaking";
}

Vec2 ICloaking::getDefaultPosition() {
	Size visible = Director::getInstance()->getVisibleSize();
	return Vec2(visible.width / 2, visible.height / 2);
}

Vec2 ICloaking::getPosition() {
	return Position;
}

void ICloaking::setPosition(Vec2 position) {
	Position = position;
}

String ICloaking::getItemName() {
	return name;
}

void ICloaking::effect() {
	log("ICloaking");
}