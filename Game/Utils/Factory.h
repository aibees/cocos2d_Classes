#ifndef __FACTORY_H__
#define __FACTORY_H__

#include "cocos2d.h"
#include "Game/Item/Item.h"
#include <string>

class Factory {
private :

public :
	virtual Item* createItem(std::string name);
};

#endif // __FACTORY_H__
