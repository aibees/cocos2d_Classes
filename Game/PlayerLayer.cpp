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
	
	//---------------- Player create ------------------------------
	player = new Player(Vec2(Visible.width / 2, Visible.height / 2), 100, 100, 100);
	
	CCSprite* spritePlayer = player->getSprite();
	spritePlayer->setPosition(player->getPosition());
	spritePlayer->setTag(PLAYER);
	this->addChild(spritePlayer, 0);
		// flag init
	isMoving = directionFlag = false;
	
		//Event Dispatcher create -> Have role for connection between listener and Object.
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
	//At the moment of caculating direct vector, will normalize this.
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
	// playerSprite load with tag value
	auto playerSprite = static_cast<CCSprite*>(getChildByTag(PLAYER));
	Vec2 move, d;
	if (isMoving) {

		//rotation set : update rotation whenever detected new move of sprite by flag
		//after, keep the rotation variable until detecting renewed direction
		if(directionFlag) {
			playerSprite->setRotation(player->calc_rotate(newPosition));
			directionFlag = false;
		}
		// delta vector
		d = Vec2(normalVector.x * delta * player->getMoveSpeed(), normalVector.y * delta * player->getMoveSpeed());
		
		// move : player sprite will move by distance vector at a frame
		move = Vec2(player->getPosition().x + (d.x), player->getPosition().y + (d.y));

		// after updates player object's position, will updates sprite position
		player->setPosition(move);
		playerSprite->setPosition(player->getPosition());

		// check moving
		if (abs(newPosition.x - player->getPosition().x) < abs(d.x) && abs(newPosition.y - player->getPosition().y) < abs(d.y)) {
			isMoving = false;
		}
	}
}
