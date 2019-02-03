#pragma once
#ifndef __CAMERA_LAYER_H__
#define __CAMERA_LAYER_H__

#include "cocos2d.h"

class CameraLayer : cocos2d::Layer {
private :

public :
	static cocos2d::Layer* createLayer();

	virtual bool init();

	CREATE_FUNC(PlayerLayer);

};
#endif // !__CAMERA_LAYER_H__
