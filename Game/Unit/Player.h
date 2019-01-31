#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Entity.h"
#include <string>

class Player : public Entity {
private:
	cocos2d::CCSprite* spritePlayer;
	cocos2d::Vec2 Position;
	long long int HP;
	long long int MP;
	float moveSpeed;

public:
	Player();
	Player(cocos2d::Vec2 position, long long int hp, long long int mp, float moveSpeed);
	
	void setSprite();
	cocos2d::CCSprite* getSprite();
	
	void setPosition(cocos2d::Vec2);
	cocos2d::Vec2 getPosition();

	void setHP(long long int hp);
	long long int getHP();

	void setMP(long long int mp);
	long long int getMP();

	void setMoveSpeed(float Speed);
	float getMoveSpeed();

	void SpeedUp();

	float calc_rotate(cocos2d::Vec2 newPosition);
};
#endif // !__PLAYER_H__
