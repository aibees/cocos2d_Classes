#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "cocos2d.h"

class Entity
{
public:
	Entity();
	Entity(cocos2d::Vec2 position, long long int hp, long long int mp);
	cocos2d::Vec2 getDefaultPosition();
	virtual cocos2d::Vec2 getPosition();
	virtual void setPosition(cocos2d::Vec2 position);
	virtual long long int getHP();
	virtual void setHP(long long int hp);
	virtual long long int getMP();
	virtual void setMP(long long int mp);

private:
	//coordinate of entity
	cocos2d::Vec2 Position;
	//Health and Magic point of entity
	long long int HP;
	long long int MP;
};

#endif // !__ENTITY_H__
