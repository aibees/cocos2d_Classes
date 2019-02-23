/*
	collision data class
	What this class does in game is collect 'Rect' data for calculate coliision
	player(dynamic) <-> items(static) // Because item position is static, this class don't have to get items position
	player(dynamic) <-> enemy(dynamic)
	player(dynamic) <-> enemy's bullet(dynamic)
	player's attack(dynamic) <-> enemy(dynamic)
*/

#ifndef __COLLISION_DATA_H__
#define __COLLISION_DATA_H__

#include "cocos2d.h"

class CollisionData {
private :
	cocos2d::Rect playerBox;
	static CollisionData* Instance;
	CollisionData();
public :
	static CollisionData* getInstance();

	cocos2d::Rect getPlayerBox();
	void setPlayerBox(cocos2d::Rect player);
};

#endif // !__COLLISION_DATA_H__
