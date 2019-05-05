#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "../Entity.h"

class Enemy : public Entity {
private :
	cocos2d::Vec2 Position;
public :
	Enemy();
	Enemy(cocos2d::Vec2 position);
	virtual cocos2d::Vec2 getPosition() = 0;
	virtual void setPosition(cocos2d::Vec2 position) = 0;
	virtual long long int getHP() = 0;
	virtual void setHP(long long int hp) = 0;
	virtual long long int getMP() = 0;
	virtual void setMP(long long int mp) = 0;
	virtual std::string getName() = 0;
	virtual float getSpeed() = 0;
	virtual void setPlayerData(cocos2d::Rect player) = 0;
	virtual float calcRotation() = 0;
	virtual cocos2d::Vec2 calcPosition() = 0;
	virtual bool isCollision(cocos2d::Rect bound) = 0;
};
#endif // !__ENEMY_H__