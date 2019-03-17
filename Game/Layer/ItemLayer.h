/*
	this class only creates item sprite. no create item objects
	just have sprite's position then, when detected collision event,
	this class just send event data to ItemSet

	but, list of items that can draw in each level exists in ItemSet class
*/

#ifndef __ITEM_LAYER_H__
#define __ITEM_LAYER_H__

#include "cocos2d.h"
#include "../CollisionData.h"
#include "../Item/ItemSet.h"
#include "ButtonLayer.h"
#include "../DataList.h"
#include <ctime>
#include <vector>
#include <string>

class ItemLayer : public cocos2d::Layer {
private :
	cocos2d::Rect playerBox;
		// container for storing item sprite that exist at game scene
	std::vector<cocos2d::CCSprite*> ItemSprite;
	bool ItemCreateFlag;
	DataList* dataList;
public :
	static cocos2d::Layer* createLayer();

	virtual bool init();

	void setItemFrame();
	void updateFrame();
	void itemCallback(cocos2d::EventCustom* event);

	//schedul func
	virtual void update(float delta);
	void createItem(float delta);
	void setSprite(std::string filename, std::string name);
	CREATE_FUNC(ItemLayer);
};

#endif // !__ITEM_LAYER_H__