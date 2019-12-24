#include "LandMine.h"

USING_NS_CC;
using namespace std;

LandMine::LandMine(string spName) {
	srand((unsigned int)time(0));
	speed = 0;
	objName = "LandMine";
	objName.append(to_string(time(0)));
	setHP(1);
	setMP(1);
	Size ws = Director::getInstance()->getVisibleSize();
	float spSizeX = 50;
	float spSizeY = 50;
	float x = rand() % ((int)ws.width);
	float y = rand() % ((int)ws.height);
	setPosition(Vec2(x, y));
}

bool LandMine::isCollision(Rect spBound) {
	if (spBound.intersectsCircle(Vec2(playerBox.getMidX(), playerBox.getMidY()), (playerBox.getMidY() - playerBox.getMinY()))) {
		//collision detected
		return true;
	}
	return false;
}