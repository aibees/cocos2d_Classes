#pragma once
#ifndef __CAMERA_LAYER_H__
#define __CAMERA_LAYER_H__

#include "cocos2d.h"

class CameraLayer : cocos2d::Layer {
private :
	cocos2d::Camera* cam;
	cocos2d::Vec3 camPosition;
public :
	static cocos2d::Layer* createLayer();

	virtual bool init();

	void Right(cocos2d::EventCustom* event);

	void Left(cocos2d::EventCustom* event);

	CREATE_FUNC(CameraLayer);

};
#endif // !__CAMERA_LAYER_H__
