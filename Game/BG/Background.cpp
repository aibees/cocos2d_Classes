#include "Background.h"

USING_NS_CC;
using namespace std;

Background* Background::Instance = NULL;

Background* Background::getInstance() {
	if (!Instance) {
		Instance = new Background(1);
	}
	return Instance;
}

Background::Background(int num) {
	dataList = new DataList();
	setBG(num);
}

CCSprite* Background::getBG_Sprite() { return BackgroundImage; }

void Background::setBG_Sprite() { 
	string tmp = "BG/";
	tmp.append(dataList->getBackground(0));
	BackgroundImage = CCSprite::create(tmp);
	return;
}

Vec2 Background::getSize() { return BG_Size; }

Vec2 Background::getPosition() { return Position; }

void Background::setPosition(Vec2 pos) {
	Position = pos;
}

void Background::setBG(int num) {
	log("setBG");
	setBG_Sprite();
	setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2));
	return;
}
