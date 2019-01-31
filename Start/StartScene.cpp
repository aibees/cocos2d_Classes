#include "StartScene.h"
#include "MenuLayer.h"
#include "SimpleAudioEngine.h"

#define TAG_MENU 1

USING_NS_CC;

using namespace CocosDenshion;

Scene* StartScene::createScene() {
	CCLOG("create startScene");
	Scene* startScene = StartScene::create();
	//Layer Add Position
	//-------- MenuLayer add to StartScene ----------
	Layer *menuLayer = MenuLayer::create();
	startScene->addChild(menuLayer, 1, TAG_MENU);
	return startScene;
}

bool StartScene::init() {
	if (!Scene::init()) {
		return false;
	}
	CCLOG("StartScene init");
	return true;
}
