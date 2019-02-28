#ifndef __ICLOAKING_H__
#define __ICLOAKING_H__

#include "Item.h"

class ICloaking : public Item {
private:
	cocos2d::CCSprite* itemSprite;
	cocos2d::Vec2 Position;
	cocos2d::String name;
public:
	ICloaking();
	ICloaking(cocos2d::Vec2 position);
	cocos2d::Vec2 getPosition();
	void setPosition(cocos2d::Vec2 position);
	virtual cocos2d::String getItemName();
	cocos2d::Vec2 getDefaultPosition();

	void effect();
};

#endif // !__ICLOAKING_H__
