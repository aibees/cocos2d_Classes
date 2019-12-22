#include "GameScene.h"

#define TAG_BACKGROUND 0
#define TAG_ENEMY 1
#define TAG_PLAYER 2
#define TAG_ITEM 3
#define TAG_BUTTON 4

USING_NS_CC;

Scene* GameScene::createScene() {
	Scene* gameScene = GameScene::create();
	//Layer Add Position
	//-------- MenuLayer add to StartScene ----------
	Layer* BG_Layer = BackgroundLayer::createLayer();
	Layer* enemyLayer = EnemyLayer::createLayer();
	Layer* playerLayer = PlayerLayer::createLayer();
	Layer* itemLayer = ItemLayer::createLayer();
	Layer* buttonLayer = ButtonLayer::createLayer();
	gameScene->addChild(BG_Layer, 0, TAG_BACKGROUND);
	gameScene->addChild(enemyLayer, 1, TAG_ENEMY);
	gameScene->addChild(playerLayer, 2, TAG_PLAYER);
	gameScene->addChild(itemLayer, 3, TAG_ITEM);
	gameScene->addChild(buttonLayer, 4, TAG_BUTTON);
	return gameScene;
}

bool GameScene::init() {
	if (!Scene::init())
		return false;
	return true;
}

void GameScene::CloseGameScene() {
	// Release memory of Layers
	log("start to erase all layer");
	this->removeAllChildren();
	// Call ExitScene Layer
	Scene* exitScene = ExitLayer::scene();
	//Director::getInstance()->replaceScene(exitScene);
	Director::getInstance()->popScene();
}