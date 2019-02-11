#include "playerCamera.h"

USING_NS_CC;

playerCamera::playerCamera() {
	setCamera();
}

Camera* playerCamera::getCamera() {return cam;} 

void playerCamera::setCamera() {
	auto size = Director::getInstance()->getWinSize();
	cam = Camera::createOrthographic(size.width, size.height, 1, getDepth());
}

cocos2d::Vec2 playerCamera::getPosition() { return position; }

void playerCamera::setPosition(cocos2d::Vec2 position) {
	playerCamera::position = position;
}

int playerCamera::getDepth() { return depth; }

void playerCamera::setDepth(int depth) {
	playerCamera::depth = depth;
}