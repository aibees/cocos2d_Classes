#include "ICloaking.h"

USING_NS_CC;

ICloaking::ICloaking() {
	ICloaking(Vec2(ICloaking::getDefaultPosition()));
	name = "ICloaking";
}

ICloaking::ICloaking(Vec2 position) {
	ICloaking::Position = position;
	
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

std::string ICloaking::getItemName() {
	return name;
}

void ICloaking::effect() {
	EventCustom opacity("setOpacity");
	_eventDispatcher->dispatchEvent(&opacity);
}