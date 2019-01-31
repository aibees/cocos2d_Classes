#include "IntroScene.h"
#include "Intro/IntroLayer.h"
#include "Intro/LogoLayer.h"
#include "Start/StartScene.h"

//tag define
#define TAG_INTRO 1
#define TAG_LOGO 2

USING_NS_CC;
//world variable

Scene* IntroScene::createScene() {
	Scene* introScene = IntroScene::create();
	//------ IntroLayer add to IntroScene -------
	LayerColor *introLayer = IntroLayer::create();
	introScene->addChild(introLayer, 0, TAG_INTRO);
	//------ LogoLayer add to IntroScene --------
	LayerColor *logoLayer = LogoLayer::create();
	introScene->addChild(logoLayer, -1, TAG_LOGO);

	return introScene;
}

bool IntroScene::init() {
	if (!Scene::init()) {
		return false;
	}
	DelayTime* time = DelayTime::create(6);
	auto replace = CallFuncN::create(CC_CALLBACK_1(IntroScene::GoToStartScene, this));
	Sequence* seq = Sequence::create(time, replace, NULL);
	this->runAction(seq);
	return true;
}

void IntroScene::GoToStartScene(Ref* sender) {
	Scene *Startscene = TransitionFade::create(1.0f, StartScene::createScene());
	Director::getInstance()->replaceScene(Startscene);
	return;
}
