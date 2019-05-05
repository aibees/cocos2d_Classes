#include "ExitLayer.h"

USING_NS_CC;

Scene* ExitLayer::scene() {
	Scene* scene = Scene::create();
	ExitLayer* exitLayer = ExitLayer::create();
	scene->addChild(exitLayer);
	return scene;
}

bool ExitLayer::init() {
	if (!Layer::init())
		return false;
	this->setOpacity(50);
	auto item1 = MenuItemFont::create("Close Scene 2", CC_CALLBACK_1(ExitLayer::doClose, this));

	item1->setColor(Color3B(255, 0, 255));
	auto pMenu = Menu::create(item1, NULL);
	pMenu->setPosition(Vec2(240, 50));
	this->addChild(pMenu);
	return true;
}

void ExitLayer::doClose(Object* pSender) {
	Director::getInstance()->replaceScene(StartScene::createScene());
}