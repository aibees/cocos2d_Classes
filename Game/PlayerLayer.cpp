#include "PlayerLayer.h"
#include <math.h>

#define PLAYER 1
#define PLAYER_MOVE_ACTION 2
#define PLAYER_ROTATE_ACTION 3
#define PIE 3.141592

USING_NS_CC;

Vec2 position;

Layer* PlayerLayer::createLayer() {
	Layer* playerLayer = PlayerLayer::create();
	CCLOG("PlayerLayer Create");
	return playerLayer;
}

bool PlayerLayer::init() {
	if (!Layer::init()) {
		return false;
	}
	auto Visible = Director::getInstance()->getVisibleSize();
	
	//---------------- Player 생성  ------------------------------
	player = new Player(Vec2(Visible.width / 2, Visible.height / 2), 100, 100, 100);
	
	CCSprite* spritePlayer = player->getSprite();
	spritePlayer->setPosition(player->getPosition());
	spritePlayer->setTag(PLAYER);
	this->addChild(spritePlayer, 0);
	
		//Event Dispatcher 생성 -> listener와 Object를 중매해 주는 역할
	EventDispatcher* player_dispatcher = Director::getInstance()->getEventDispatcher();
	auto playerPosition = EventListenerTouchOneByOne::create();
	playerPosition->setSwallowTouches(true);

	playerPosition->onTouchBegan = CC_CALLBACK_2(PlayerLayer::TouchBegan, this);
	player_dispatcher->addEventListenerWithSceneGraphPriority(playerPosition, this);
	//----------------------------------------------------------------------------

	//---------------------
	//button touch dispatch test
	EventListenerCustom* buttonListener = EventListenerCustom::create("ButtonTouchForSpeedUp",CC_CALLBACK_1(PlayerLayer::player_callback, this));
	_eventDispatcher->addEventListenerWithFixedPriority(buttonListener, 1);
	//---------------------

	this->scheduleUpdate();

	return true;
}

 void PlayerLayer::movePlayer(Vec2 Position) {
	//각 class에서 sprite 불러옴
	auto spritePlayer = player->getSprite();
	auto spriteBG = Background::getInstance()->getBG_Sprite();
	
	//새로운 동작 위해 현재 동작 제거
	if (spritePlayer->getActionByTag(PLAYER_MOVE_ACTION)) {
		spritePlayer->stopActionByTag(PLAYER_MOVE_ACTION);
	}

	log("X : %f || Y : %f", Position.x, Position.y); // 이동 위해 새로 찍은 좌표
	CCSize visible = Director::getInstance()->getVisibleSize();
	//Vec2 tmp = Vec2((Position.x - visible.width / 2), (Position.y - visible.height / 2));
	float distance = sqrt((Position.x - visible.width / 2)*(Position.x - visible.width / 2) + (Position.y - visible.height / 2)*(Position.y - visible.height / 2));

	//auto moveAction = MoveBy::create(distance / player->getMoveSpeed(), tmp);
	auto moveAction = MoveTo::create(distance / player->getMoveSpeed(), Position);
	log("%f", distance / player->getMoveSpeed());
	moveAction->setTag(PLAYER_MOVE_ACTION);
	spritePlayer->runAction(moveAction);
	spritePlayer->setRotation(player->calc_rotate(Position));
	log("layer position : %f || %f", this->getPosition().x, this->getPosition().y);
	return;
}

bool PlayerLayer::TouchBegan(Touch* touch, Event* event) {
	movePlayer(touch->getLocation());
	return true;
}

void PlayerLayer::player_callback(EventCustom* event) {
	log("speed up");
	float tmp = player->getMoveSpeed();
	if(tmp > 0.5)
		player->SpeedUp();

}

void PlayerLayer::update(float delta) {

}
