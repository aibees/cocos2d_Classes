#ifndef __LOGO_LAYER_H__
#define __LOGO_LAYER_H__

#include "cocos2d.h"

class LogoLayer : public cocos2d::LayerColor {
private:

public:
	static cocos2d::LayerColor* createLayer();

	virtual bool init();

	CREATE_FUNC(LogoLayer);
};

#endif // !__LOGO_LAYER_H__
