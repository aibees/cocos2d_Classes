/*
	this class have all infor. of item objects
	if this class get collision event from itemlayer,
	creates related item object then stores this in itemQueue container 
*/

#ifndef __ITEMSET_H__
#define __ITEMSET_H__

#include "cocos2d.h"
#include "Item.h"
#include "ItemFactory.h"
#include <vector>
#include <string>

class ItemSet {
private :
	static ItemSet* Instance;
	std::vector<Item*> ItemQueue;
	ItemSet();
public :
	static ItemSet* getInstance();

	// ItemQueue function
	int getQueueSize();
	bool isQueueFull();
	void insertItem(std::string itemName);
};
#endif // !__ITEMSET_H__
