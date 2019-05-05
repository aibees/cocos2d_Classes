#ifndef __PLAYER_LAYER_H__
#define __PLAYER_LAYER_H__

#pragma once

#include "cocos2d.h"
#include "../Unit/Player.h"
#include "backgroundLayer.h"
#include "../BG/Background.h"
#include "ButtonLayer.h"
#include "../Utils/CollisionData.h"

class PlayerLayer : public cocos2d::Layer {
private:
	Player* player;
	cocos2d::Vec2 newPosition;
	cocos2d::Vec2 normalVector;
	bool isMoving;
	bool directionFlag;
	int opacityTimer;
	cocos2d::EventListenerCustom* skillButtonListener;
public:
	~PlayerLayer();

	static cocos2d::Layer* createLayer();

	virtual bool init();

	virtual bool TouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	virtual bool TouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);

	//Player method

	void player_callback(cocos2d::EventCustom* event);

	//Update
	virtual void update(float delta);

	CREATE_FUNC(PlayerLayer);
};

#endif // !__PLAYER_LAYER_H__