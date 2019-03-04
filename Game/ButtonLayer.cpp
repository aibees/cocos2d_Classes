#include "ButtonLayer.h"

#define ATTACK_BUTTON 1
#define LEFT_BUTTON 2
#define RIGHT_BUTTON 3

USING_NS_CC;

Layer* ButtonLayer::createLayer() {
	Layer* buttonLayer = ButtonLayer::create();
	log("create button layer in buttonlayer class");
	return buttonLayer;
}

void ButtonLayer::createButton() {
	auto Visible = Director::getInstance()->getVisibleSize();

	//------attack button------
	attackButton = ui::Button::create();
	//attackButton->setTouchEnabled(true);
	attackButton->loadTextures("button/button_attack.png", "button/button_attack_pressed.png", "");
	attackButton->setPosition(Vec2(Visible.width - 80, 160));
	this->addChild(attackButton, 1, ATTACK_BUTTON);

	log("add button");
	return;
}

void ButtonLayer::attackButtonBegan() {
	EventCustom clickEvent("ButtonTouchForSpeedUp");
	_eventDispatcher->dispatchEvent(&clickEvent);
}

void ButtonLayer::OnattackTouch(Ref* pSender, ui::Widget::TouchEventType type) {
	switch (type)
	{
	case cocos2d::ui::Widget::TouchEventType::BEGAN:
		attackButtonBegan();
		break;
	case cocos2d::ui::Widget::TouchEventType::MOVED:
		break;
	case cocos2d::ui::Widget::TouchEventType::ENDED:
		break;
	default:
		break;
	}
}

void ButtonLayer::LeftTouchBegan() {
	EventCustom clickEvent("LeftToCamera");
	_eventDispatcher->dispatchEvent(&clickEvent);
}

void ButtonLayer::LeftTouch(Ref* pSender, ui::Widget::TouchEventType type) {
	switch (type)
	{
	case cocos2d::ui::Widget::TouchEventType::BEGAN:
		LeftTouchBegan();
		break;
	case cocos2d::ui::Widget::TouchEventType::MOVED:
		break;
	case cocos2d::ui::Widget::TouchEventType::ENDED:
		break;
	default:
		break;
	}
}

void ButtonLayer::RightTouchBegan() {
	EventCustom clickEvent("RightToCamera");
	_eventDispatcher->dispatchEvent(&clickEvent);
}

void ButtonLayer::RightTouch(Ref* pSender, ui::Widget::TouchEventType type) {
	switch (type)
	{
	case cocos2d::ui::Widget::TouchEventType::BEGAN:
		RightTouchBegan();
		break;
	case cocos2d::ui::Widget::TouchEventType::MOVED:
		break;
	case cocos2d::ui::Widget::TouchEventType::ENDED:
		break;
	default:
		break;
	}
}

bool ButtonLayer::init() {
	if (!Layer::init()) {
		return false;
	}
	log("buttonlayer init");
	EventDispatcher* button_dispatcher = Director::getInstance()->getEventDispatcher();
	auto buttonListener = EventListenerTouchOneByOne::create();
	buttonListener->setSwallowTouches(true);
	createButton();
	attackButton->addTouchEventListener(CC_CALLBACK_2(ButtonLayer::OnattackTouch, this));
	cameraLeftButton->addTouchEventListener(CC_CALLBACK_2(ButtonLayer::LeftTouch, this));
	cameraRightButton->addTouchEventListener(CC_CALLBACK_2(ButtonLayer::RightTouch, this));

	return true;
}