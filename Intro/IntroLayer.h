#ifndef __INTRO_LAYER_H__
#define __INTRO_LAYER_H__

#include "cocos2d.h"

class IntroLayer : public cocos2d::LayerColor {
private:

public:
	static cocos2d::LayerColor* createLayer();

	virtual bool init();

	CREATE_FUNC(IntroLayer);
};

#endif // !__INTRO_LAYER_H__
