#pragma once
#ifndef __BACKGROUND_LAYER_H__
#define __BACKGROUND_LAYER_H__

#include "cocos2d.h"
#include "BG/Background.h"

class BackgroundLayer : public cocos2d::Layer {
private:

public:
	static cocos2d::Layer* createLayer();

	virtual bool init();

	CREATE_FUNC(BackgroundLayer);

	void BG_Setting();
};

#endif // !__BACKGROUND_H__
