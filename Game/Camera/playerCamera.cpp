#include "playerCamera.h"

USING_NS_CC;

playerCamera* playerCamera::Instance = NULL;

playerCamera* playerCamera::getInstance() {
	if (!Instance) {
		Instance = new playerCamera();
	}
	return Instance;
}

playerCamera::playerCamera() {
	setCamera();
}

Camera* playerCamera::getCamera() {return cam;}

void playerCamera::setCamera() {
	cam = Camera::getDefaultCamera();
}

cocos2d::Vec2 playerCamera::getPosition() { return position; }

void playerCamera::setPosition(cocos2d::Vec2 position) {
	playerCamera::position = position;
}

int playerCamera::getDepth() { return depth; }

void playerCamera::setDepth(int depth) {
	playerCamera::depth = depth;
}