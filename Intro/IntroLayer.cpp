#include "IntroLayer.h"

USING_NS_CC;

LayerColor* IntroLayer::createLayer() {
	return IntroLayer::create();
}

bool IntroLayer::init() {
	//super init first
	if (!LayerColor::initWithColor(ccc4(0,0,0,0))) {
		return false;
	}

	auto Visible = Director::getInstance()->getVisibleSize();

	auto Cocos_sprite = Sprite::create("HelloWorld.png");
	float Cocos_w = 195, Cocos_h = 270;
	Cocos_sprite->setPosition(Vec2(Visible.width / 2, Visible.height / 2));
	this->addChild(Cocos_sprite, 0);

	auto FadeOutAction_Intro = FadeOut::create(1.0f);
	auto DelayTime = DelayTime::create(2.0f);
	Sequence *cocos_action = Sequence::create(DelayTime, FadeOutAction_Intro, NULL);

	Cocos_sprite->runAction(cocos_action);

	return true;
}

