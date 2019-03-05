#ifndef __ENEMY_LAYER_H__
#define __ENEMY_LAYER_H__

#include "cocos2d.h"

class EnemyLayer :cocos2d::Layer {
private :

public :
	static cocos2d::Layer* createLayer();

	virtual bool init();

	//Update
	virtual void update(float delta);

	CREATE_FUNC(PlayerLayer);
};

#endif // !__ENEMY_LAYER_H__
