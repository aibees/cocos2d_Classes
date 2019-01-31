#ifndef __INTRO_SCENE_H__
#define __INTRO_SCENE_H__

#include "cocos2d.h"
#include "Start/StartScene.h"

class IntroScene : public cocos2d::Scene{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void GoToStartScene(Ref* sender);

	CREATE_FUNC(IntroScene);
};
#endif // !__INTRO_SCENE_H__

