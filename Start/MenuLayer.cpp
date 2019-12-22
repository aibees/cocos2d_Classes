#include "MenuLayer.h"
#include "SimpleAudioEngine.h"

#define MENU_START 1
#define MENU_SETTING 2

USING_NS_CC;

Layer* MenuLayer::createLayer(){
	return MenuLayer::create();
}

bool MenuLayer::init() {
	if (!Layer::create()) {
		return false;
	}
	//sound
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic("sound/Intro.mp3", true);

	//Listener
	auto MouseListener = EventListenerMouse::create();
	MouseListener->onMouseDown = CC_CALLBACK_1(MenuLayer::onMouseDown, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(MouseListener, this);

	//Labeling
	Label* label_Start = Label::createWithTTF("PLAY", "fonts/Marker Felt.ttf", 60);
	Label* label_Setting = Label::createWithTTF("SETTING", "fonts/Marker Felt.ttf", 60);
	
	//start menu make and add
	auto Item_Start = MenuItemLabel::create(label_Start, CC_CALLBACK_1(MenuLayer::MenuCallBack, this));
	Item_Start->setColor(ccc3(255, 255, 255));
	Item_Start->setTag(MENU_START);
	
	//setting menu make and add
	auto Item_Setting = MenuItemLabel::create(label_Setting, CC_CALLBACK_1(MenuLayer::MenuCallBack, this));
	Item_Setting->setColor(ccc3(127, 127, 127));
	Item_Setting->setTag(MENU_SETTING);
	
	//Make menu items setting
	auto menu = Menu::create(Item_Start, Item_Setting, NULL);
	menu->alignItemsVertically();
	this->addChild(menu, 1);
	return true;
}

void MenuLayer::MenuCallBack(Ref *sender) {
	CCMenuItem* Item = (CCMenuItem*)sender;
	int menu_Tag = Item->getTag();
	auto replace = CallFuncN::create(CC_CALLBACK_1(MenuLayer::ReplaceToStart, this));
	switch (menu_Tag) {
	case MENU_START:
		this->runAction(replace);
		break;
	case MENU_SETTING:
		break;
	}
	return;
}

void MenuLayer::onMouseDown(Event* event) {
	auto mouseEvent = static_cast<EventMouse*>(event);
	Vec2 ClickPoint = Vec2(mouseEvent->getCursorX(), mouseEvent->getCursorY());
	return;
}

void MenuLayer::ReplaceToStart(Ref* sender) {
	Scene *GameScene = GameScene::createScene();
	//Director::getInstance()->replaceScene(GameScene);
	Director::getInstance()->pushScene(GameScene);
	return;
}