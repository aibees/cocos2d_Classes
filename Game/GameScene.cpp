#include "GameScene.h"

#define TAG_BACKGROUND 0
#define TAG_PLAYER 1
#define TAG_ITEM 2
#define TAG_BUTTON 3

USING_NS_CC;

Scene* GameScene::createScene() {
	Scene* gameScene = GameScene::create();
	//Layer Add Position
	//-------- MenuLayer add to StartScene ----------
	Layer* BG_Layer = BackgroundLayer::createLayer();
	Layer* itemLayer = ItemLayer::createLayer();
	Layer* playerLayer = PlayerLayer::createLayer();
	Layer* buttonLayer = ButtonLayer::createLayer();
	gameScene->addChild(BG_Layer, 0, TAG_BACKGROUND);
	gameScene->addChild(playerLayer, 1, TAG_PLAYER);
	gameScene->addChild(itemLayer, 2, TAG_ITEM);
	gameScene->addChild(buttonLayer, 3, TAG_BUTTON);
	return gameScene;
}

bool GameScene::init() {
	if (!Scene::init())
		return false;
	return true;
}