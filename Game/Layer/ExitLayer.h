#ifndef __EXIT_LAYER__
#define __EXIT_LAYER__

#include "cocos2d.h"
#include "../../Start/StartScene.h"

class ExitLayer : public cocos2d::Layer {
private :
	cocos2d::Size winSize;
public :
	static cocos2d::Scene* scene();

	virtual bool init();

	void doClose(cocos2d::Object* pSender);

	CREATE_FUNC(ExitLayer);
};
#endif // !__EXIT_LAYER__
