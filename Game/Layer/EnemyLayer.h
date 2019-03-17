#ifndef __ENEMY_LAYER_H__
#define __ENEMY_LAYER_H__

#include "cocos2d.h"
#include "../Unit/Enemy/Enemy.h"
#include "CollisionData.h"
#include <vector>

class EnemyLayer :cocos2d::Layer {
private :
	std::vector<Enemy*> Enemies;
public :
	static cocos2d::Layer* createLayer();

	virtual bool init();

	//Update
	virtual void update(float delta);

	CREATE_FUNC(EnemyLayer);
};

#endif // !__ENEMY_LAYER_H__
