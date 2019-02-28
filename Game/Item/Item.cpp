#include "Item.h"

USING_NS_CC;

Item::Item() {
	name = "Item";
}

Item::Item(Vec2 position) {
	Position = position;
}

Vec2 Item::getPosition() {
	return Position;
}

void Item::setPosition(Vec2 position) {
	Position = position;
	return;
}

void Item::effect() {
	log("effect");
}

std::string Item::getItemName() {
	return name;
}