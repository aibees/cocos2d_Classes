#include "Player.h"
#include <math.h>

USING_NS_CC;
#define PIE 3.141592

Player::Player(Vec2 position, long long int hp, long long int mp, float moveSpeed) {
	Player::setPosition(position);
	Player::setHP(hp);
	Player::setMP(mp);
	Player::setMoveSpeed(moveSpeed);
	setSprite();
}

void Player::setSprite() {
	log("create player sprite");
	std::string tmp = "unit/Player/Basic.png";
	spritePlayer = CCSprite::create(tmp);
}

CCSprite* Player::getSprite() {return spritePlayer;}

void Player::setPosition(Vec2 position) {Player::Position = position;}
cocos2d::Vec2 Player::getPosition() {return Player::Position;}

void Player::setHP(long long int hp) {Player::HP = hp;}
long long int Player::getHP() {return Player::HP;}

void Player::setMP(long long int mp) {Player::MP = mp;}
long long int Player::getMP() {return Player::MP;}

void Player::setMoveSpeed(float Speed) {moveSpeed = Speed;}
float Player::getMoveSpeed() {return moveSpeed;}

void Player::SpeedUp() {
	moveSpeed += 50.0;
}

float Player::calc_rotate(Vec2 newPosition) {
	float rotate = 0;
	float tmp = atan2((Position.y - newPosition.y), (Position.x - newPosition.x));
	rotate = tmp * (-180/PIE) -90;
	return rotate;
}