#include "ButtonLayer.h"
#include "cocos-ext.h"

#define ATTACK_BUTTON 1

USING_NS_CC;

Layer* ButtonLayer::createLayer() {
	Layer* buttonLayer = ButtonLayer::create();
	log("create button layer in buttonlayer class");
	return buttonLayer;
}

void ButtonLayer::createButton() {
	auto Visible = Director::getInstance()->getVisibleSize();

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
		log("attack button touched!");
		break;
	case cocos2d::ui::Widget::TouchEventType::MOVED:
		log("attack button moved");
		break;
	case cocos2d::ui::Widget::TouchEventType::ENDED:
		log("attack button released");
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
	
	return true;
}