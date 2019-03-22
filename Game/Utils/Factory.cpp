#include "Factory.h"

cocos2d::Node* Factory::createItem(std::string name)
{
	return new Item();
}