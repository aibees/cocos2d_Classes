#ifndef __ENEMY_LAYER_H__
#define __ENEMY_LAYER_H__

#include "cocos2d.h"
#include "Game/GameScene.h"
#include "../Unit/Enemy/Enemy.h"
#include "../Unit/Enemy/EnemyFactory.h"
#include "../Utils/CollisionData.h"
#include "../Utils/DataList.h"
#include "ExitLayer.h"
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>

class EnemyLayer :cocos2d::Layer {
private :
	std::vector<Enemy*> Enemies;
	std::map<std::string, cocos2d::Sprite*> spriteMapping;
	cocos2d::EventListenerCustom* clearSkillButtonListener;
	DataList* dataList;
public :
	static cocos2d::Layer* createLayer();
	~EnemyLayer();

	virtual bool init();

	void popExitScene();
	
	//Update
	virtual void update(float delta);
	void createEnemy(float delta);

	void clearSkill_callback(cocos2d::EventCustom *event);

	CREATE_FUNC(EnemyLayer);
};

#endif // !__ENEMY_LAYER_H__
