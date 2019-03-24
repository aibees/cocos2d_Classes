#ifndef __SMALLGUN_H__
#define __SMALLGUM_H__

#include "Enemy.h"
#include <cmath>

class SmallGun : public Enemy {
private :
	cocos2d::Sprite* sp;
	cocos2d::Vec2 Position;
	cocos2d::Rect playerBox;
	long long int HP;
	long long int MP;
public :
	SmallGun();
	SmallGun(std::string spName);
	virtual void setPosition(cocos2d::Vec2 position);
	virtual cocos2d::Vec2 getPosition();
	virtual long long int getHP();
	virtual void setHP(long long int hp);
	virtual long long int getMP();
	virtual void setMP(long long int mp);
	virtual void setPlayerData(cocos2d::Rect player);
	virtual float calcRotation();
};

#endif // !__SMALLGUN_H__