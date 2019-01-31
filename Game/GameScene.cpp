#include "GameScene.h"
#include "PlayerLayer.h"
#include "ButtonLayer.h"
#include "backgroundLayer.h"

#define TAG_BACKGROUND 0
#define TAG_PLAYER 1
#define TAG_BUTTON 2

USING_NS_CC;

Scene* GameScene::createScene() {
	Scene* gameScene = GameScene::create();
	//Layer Add Position
	//-------- MenuLayer add to StartScene ----------
	Layer *BG_Layer = BackgroundLayer::createLayer();
	Layer *playerLayer = PlayerLayer::createLayer();
	Layer *buttonLayer = ButtonLayer::createLayer();
	gameScene->addChild(BG_Layer, 0, TAG_BACKGROUND);
	gameScene->addChild(playerLayer, 1, TAG_PLAYER);
	gameScene->addChild(buttonLayer, 2, TAG_BUTTON);
	log("button layer create");
	return gameScene;
}

bool GameScene::init() {
	if (!Scene::init())
		return false;
	return true;
}