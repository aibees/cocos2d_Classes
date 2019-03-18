#ifndef __ENEMY_LAYER_H__
#define __ENEMY_LAYER_H__

#include "cocos2d.h"
#include "../Unit/Enemy/Enemy.h"
#include "../Utils/CollisionData.h"
#include "../Utils/DataList.h"
#include <vector>
#include <cstdlib>
#include <ctime>

class EnemyLayer :cocos2d::Layer {
private :
	std::vector<Enemy*> Enemies;
	DataList* dataList;
public :
	static cocos2d::Layer* createLayer();

	virtual bool init();
	
	//Update
	virtual void update(float delta);
	void createEnemy(float delta);

	CREATE_FUNC(EnemyLayer);
};

#endif // !__ENEMY_LAYER_H__
