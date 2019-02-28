#ifndef __ICLEAR_H__
#define __ICLEAR_H__

#include "Item.h"

class IClear : public Item {
private :
	cocos2d::CCSprite* itemSprite;
	cocos2d::Vec2 Position;
	cocos2d::String name;
public :
	IClear();
	IClear(cocos2d::Vec2 position);
	cocos2d::Vec2 getPosition();
	void setPosition(cocos2d::Vec2 position);

	cocos2d::String getItemName();

	cocos2d::Vec2 getDefaultPosition();

	void effect();
};

#endif // !__ICLEAR_H__
