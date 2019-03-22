#ifndef __START_MENU_H__
#define __START_MENU_H__

#include "cocos2d.h"
#include "../Game/GameScene.h"

class MenuLayer : public cocos2d::Layer {
public:
	static cocos2d::Layer* createLayer();

	virtual bool init();

	void MenuCallBack(Ref *sender);

	void onMouseDown(cocos2d::Event* event);

	void ReplaceToStart(Ref* sender);

	CREATE_FUNC(MenuLayer);
};
#endif // !__START_MENU_H__
