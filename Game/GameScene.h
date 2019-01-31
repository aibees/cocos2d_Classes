#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#pragma once

#include "cocos2d.h"

class GameScene : public cocos2d::Scene {
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(GameScene);
};

#endif // !__GAME_SCENE_H__

