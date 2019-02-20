#ifndef __ITEM_H__
#define __ITEM_H__

#include "cocos2d.h"

class Item : cocos2d::Node {
protected :
	cocos2d::CCSprite* itemSprite;
	cocos2d::Vec2 Position;
public :
	Item();
	Item(cocos2d::Vec2 Position);
	virtual cocos2d::Vec2 getPosition();
	virtual void setPosition(cocos2d::Vec2 position);
	virtual void effect();
};
#endif // !__ITEM_H__
