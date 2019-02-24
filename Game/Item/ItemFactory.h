#ifndef __ITEM_FACTORY_H__
#define __ITEM_FACTORY_H__

#include "../Factory.h"
#include "cocos2d.h"
#include "Item.h"

class ItemFactory : public Factory {
private :
	static ItemFactory* Instance;
	ItemFactory();

public :
	static ItemFactory* getInstance();
	virtual Item* createItem(std::string name);
};

#endif // !__ITEM_FACTORY_H__