#ifndef __BUTTON_LAYER_H__
#define __BUTTON_LAYER_H__

#pragma once

#include "cocos2d.h"
#include "cocos-ext.h"

class ButtonLayer : public cocos2d::Layer {
private:
	cocos2d::ui::Button* attackButton;

public:
	static cocos2d::Layer* createLayer();

	virtual bool init();

	void createButton();

	void OnattackTouch(Ref* pSender, cocos2d::ui::Widget::TouchEventType type);

	void attackButtonBegan();

	CREATE_FUNC(ButtonLayer);
};

#endif // !__BUTTON_LAYER_H__

