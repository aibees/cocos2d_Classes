#include "LogoLayer.h"

USING_NS_CC;

LayerColor* LogoLayer::createLayer() {
	return LogoLayer::create();
}

bool LogoLayer::init() {
	if (!LayerColor::initWithColor(ccc4(0, 0, 0, 0))) {
		return false;
	}

	auto Visible = Director::getInstance()->getVisibleSize();

	auto Logo_sprite = Sprite::create("Logo.png");
	float Logo_w = 400, Logo_h = 400;
	Logo_sprite->setPosition(Vec2(Visible.width / 2, Visible.height / 2));
	Logo_sprite->setOpacity(0);
	this->addChild(Logo_sprite, 0);

	auto FadeInAction_Logo = FadeIn::create(1.4f);
	auto DelayTime = DelayTime::create(3.5f);
	Sequence *logo_action = Sequence::create(DelayTime, FadeInAction_Logo, NULL);

	Logo_sprite->runAction(logo_action);
	return true;
}
