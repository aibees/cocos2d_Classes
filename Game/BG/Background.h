#pragma once
#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

#include "cocos2d.h"
#include "../Utils/DataList.h"
#include <string>

class Background
{
private:
	std::string List[3];
	cocos2d::Vec2 Position;
	cocos2d::Vec2 BG_Size;
	cocos2d::Sprite* BackgroundImage;
	static Background* Instance;
	DataList* dataList;
	Background(int num);

public:
	static Background* getInstance();

	cocos2d::Sprite* getBG_Sprite();
	void setBG_Sprite();

	cocos2d::Vec2 getPosition();
	void setPosition(cocos2d::Vec2 pos);

	cocos2d::Vec2 getSize();
	void setBG(int num);
};
#endif // !__BACKGROUND_H__
