#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#pragma once

#include "cocos2d.h"
#include "PlayerLayer.h"
#include "ButtonLayer.h"
#include "backgroundLayer.h"
#include "ItemLayer.h"

class GameScene : public cocos2d::Scene {
private:
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(GameScene);
};

#endif // !__GAME_SCENE_H__

