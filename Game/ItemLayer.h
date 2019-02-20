#ifndef __ITEM_LAYER_H__
#define __ITEM_LAYER_H__

#include "cocos2d.h"

class ItemLayer : public cocos2d::Layer {
private :

public :
	static cocos2d::Layer* createLayer();

	virtual bool init();

	CREATE_FUNC(ItemLayer);
};

#endif // !__ITEM_LAYER_H__
