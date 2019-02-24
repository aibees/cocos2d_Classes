/*
	this class only creates item sprite. no create item objects
	just have sprite's position then, when detected collision event,
	this class just send event data to ItemSet

	but, list of items that can draw in each level exists in ItemSet class
*/

#ifndef __ITEM_LAYER_H__
#define __ITEM_LAYER_H__

#include "cocos2d.h"
#include "Game/CollisionData.h"
#include <ctime>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class ItemLayer : public cocos2d::Layer {
private :
	cocos2d::Rect playerBox;
		// container for storing item sprite that exist at game scene
	std::vector<cocos2d::CCSprite*> ItemSprite;
public :
	static cocos2d::Layer* createLayer();

	virtual bool init();

	void setSprite(std::string filename);

	//schedul func
	virtual void update(float delta);
	void createItem(float delta);

	CREATE_FUNC(ItemLayer);
};

#endif // !__ITEM_LAYER_H__