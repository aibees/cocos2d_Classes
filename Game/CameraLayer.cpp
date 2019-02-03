#include "CameraLayer.h"
#include "ButtonLayer.h"
#include "Camera/playerCamera.h"

#define TAG_BUTTON 0

USING_NS_CC;

Layer* CameraLayer::createLayer() {
	Layer* CameraLayer = CameraLayer::create();

	Layer* buttonLayer = ButtonLayer::create();
	CameraLayer->addChild(buttonLayer, 0, TAG_BUTTON);
	return CameraLayer;
}

bool CameraLayer::init() {
	if (!Layer::init()) {
		return false;
	}
	return true;
}

