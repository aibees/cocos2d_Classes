#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "../Entity.h"

class Enemy : public Entity {
private :
	cocos2d::Vec2 Position;
	long long int HP;
	long long int MP;
	cocos2d::Rect playerBox;
public :
	Enemy();
	Enemy(cocos2d::Vec2 position, long long int hp, long long int mp);
	virtual cocos2d::Vec2 getPosition();
	virtual void setPosition(cocos2d::Vec2 position);
	virtual long long int getHP();
	virtual void setHP(long long int hp);
	virtual long long int getMP();
	virtual void setMP(long long int mp);
	virtual void setPlayerData(cocos2d::Rect player);
};

#endif // !__ENEMY_H__