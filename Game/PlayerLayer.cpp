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
		// flag init
	isMoving = directionFlag = false;
	
		//Event Dispatcher 생성 -> listener와 Object를 중매해 주는 역할
	EventDispatcher* player_dispatcher = Director::getInstance()->getEventDispatcher();
	auto playerPosition = EventListenerTouchOneByOne::create();
	playerPosition->setSwallowTouches(true);

	playerPosition->onTouchBegan = CC_CALLBACK_2(PlayerLayer::TouchBegan, this);
	playerPosition->onTouchMoved = CC_CALLBACK_2(PlayerLayer::TouchMoved, this);
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

bool PlayerLayer::TouchBegan(Touch* touch, Event* event) {
	newPosition = touch->getLocation();
	//방향벡터를 touch하는 순간에 값 계산하고 normalize
	normalVector = Vec2(newPosition.x - player->getPosition().x, newPosition.y - player->getPosition().y);
	normalVector.normalize();
	if (newPosition != player->getPosition())
		isMoving = directionFlag = true;
	return true;
}

bool PlayerLayer::TouchMoved(Touch* touch, Event* event) {
	newPosition = touch->getLocation();
	normalVector = Vec2(newPosition.x - player->getPosition().x, newPosition.y - player->getPosition().y);
	normalVector.normalize();
	if (newPosition != player->getPosition())
		isMoving = directionFlag = true;
	return true;
}

void PlayerLayer::player_callback(EventCustom* event) {
	log("speed up");
	float tmp = player->getMoveSpeed();
	if(tmp > 0.5)
		player->SpeedUp();

}

void PlayerLayer::update(float delta) {
	// tag로 playerSprite load
	auto playerSprite = static_cast<CCSprite*>(getChildByTag(PLAYER));
	Vec2 move, d;
	if (isMoving) {
		// rotation set : flag 하나를 사용하여 새로운 이동이 감지될 때마다 flag를 세워 rotation 갱신
		// 그 후에 다시 false로 바꾸어 새로운 direction 갱신이 있을 때까지 rotation 값을 유지
		if(directionFlag) {
			playerSprite->setRotation(player->calc_rotate(newPosition));
			directionFlag = false;
		}
		d = Vec2(normalVector.x * delta * player->getMoveSpeed(), normalVector.y * delta * player->getMoveSpeed());
		// move : 매 frame마다 sprite가 이동할 거리 vector
		move = Vec2(player->getPosition().x + (d.x), player->getPosition().y + (d.y));

		// player 객체에 position 갱신 후 sprite 위치도 갱신
		player->setPosition(move);
		playerSprite->setPosition(player->getPosition());
		
		log("sprite position : %f || %f", player->getPosition().x, player->getPosition().y);
		log("newposition : %f || %f", newPosition.x, newPosition.y);

		if (abs(newPosition.x - player->getPosition().x) < abs(d.x) && abs(newPosition.y - player->getPosition().y) < abs(d.y)) {
			isMoving = false;
		}
	}
	// check moving
	
}
