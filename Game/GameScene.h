#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#pragma once

#include "cocos2d.h"
#include "Layer/PlayerLayer.h"
#include "Layer/ButtonLayer.h"
#include "Layer/backgroundLayer.h"
#include "Layer/ItemLayer.h"
#include "Layer/EnemyLayer.h"
#include "Layer/ExitLayer.h"

class GameScene : public cocos2d::Scene {
private:
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void CloseGameScene();

	CREATE_FUNC(GameScene);
};

#endif // !__GAME_SCENE_H__

