#ifndef __PLAYERCAMERA_H__
#define __PLAYERCAMERA_H__

#include "cocos2d.h"

class playerCamera : public cocos2d::Camera{
private:
	cocos2d::Camera* cam;
	cocos2d::Vec2 position;
	int depth;
public:
	playerCamera();

	cocos2d::Camera* getCamera();
	void setCamera();

	cocos2d::Vec2 getPosition();
	void setPosition(cocos2d::Vec2 position);

	int getDepth();
	void setDepth(int depth);
};


#endif // !__PLAYERCAMERA_H__
