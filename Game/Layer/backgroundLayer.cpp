#include "backgroundLayer.h"

#define BACKGROUND 1

USING_NS_CC;

Layer* BackgroundLayer::createLayer() {
	Layer* BackgroundLayer = BackgroundLayer::create();
	log("bg create");
	return BackgroundLayer;
}

bool BackgroundLayer::init() {
	if (!Layer::init()) {
		return false;
	}
	log("init background Layer");
	BG_Setting();
	
	return true;
}

void BackgroundLayer::BG_Setting() {
	auto visible = Director::getInstance()->getVisibleSize();
	
	CCSprite* BGsprite = Background::getInstance()->getBG_Sprite();
	BGsprite->setPosition(Vec2(visible.width / 2, visible.height / 2));
	BGsprite->setTag(BACKGROUND);
	this->addChild(BGsprite, 0);
}