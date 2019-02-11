#include "CameraLayer.h"
#include "ButtonLayer.h"
#include "Game/PlayerLayer.h"

USING_NS_CC;

Layer* CameraLayer::createLayer() {
	Layer* CameraLayer = CameraLayer::create();
	return CameraLayer;
}

bool CameraLayer::init() {
	if (!Layer::init()) {
		return false;
	}
	// ------camera »ý¼º ------
	auto visible = Director::getInstance()->getWinSize();
	camPosition = Vec3(visible.width / 2, visible.height / 2, 10);
	cam = Camera::createOrthographic(visible.width, visible.height, -2, 13);
	cam->setPosition3D(camPosition);
	this->addChild(cam, 3);

	//button touch dispatch test
	EventListenerCustom* Right = EventListenerCustom::create("RightToCamera", CC_CALLBACK_1(CameraLayer::Right, this));
	_eventDispatcher->addEventListenerWithFixedPriority(Right, 1);
	EventListenerCustom* Left = EventListenerCustom::create("LeftToCamera", CC_CALLBACK_1(CameraLayer::Left, this));
	_eventDispatcher->addEventListenerWithFixedPriority(Left, 1);
	//---------------------

	return true;
}

void CameraLayer::Right(EventCustom* event) {
	log("camera right %f, %f, %f", camPosition.x, camPosition.y, camPosition.z);
	camPosition.y -= 20;
	log("after -20 %f, %f, %f", camPosition.x, camPosition.y, camPosition.z);
	this->setColor(Color3B(255,0,0));
	log("getColor %d || %d", this->getColor().r, this->getColor().g);
}

void CameraLayer::Left(EventCustom* event) {
	auto isc = cam->isRunning();
	log("cam is running ? : %d", isc);
	log("camera right %f, %f, %f", camPosition.x, camPosition.y, camPosition.z);
	camPosition.y += 20;
	log("after +20 %f, %f, %f", camPosition.x, camPosition.y, camPosition.z);
	this->setColor(Color3B(255, 128, 0));
	log("getColor %d || %d", this->getColor().r, this->getColor().g);
}