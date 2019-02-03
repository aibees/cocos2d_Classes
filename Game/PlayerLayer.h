#ifndef __PLAYER_LAYER_H__
#define __PLAYER_LAYER_H__

#pragma once

#include "cocos2d.h"
#include "Game/Unit/Player.h"
#include "Game/backgroundLayer.h"
#include "Game/BG/Background.h"
#include "Game/playerCamera.h"

class PlayerLayer : public cocos2d::Layer {
private:
	Player* player;
public:
	static cocos2d::Layer* createLayer();

	virtual bool init();

	virtual bool TouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	//Player method
	void movePlayer(cocos2d::Vec2 Position);

	void player_callback(cocos2d::EventCustom* event);

	//Update
	virtual void update(float delta);
	CREATE_FUNC(PlayerLayer);
};

#endif // !__PLAYER_LAYER_H__