/*
	this class have all infor. of item objects
	if this class get collision event from itemlayer,
	creates related item object then stores this in itemQueue container 
*/

#ifndef __ITEMSET_H__
#define __ITEMSET_H__

#include <vector>
#include "cocos2d.h"
#include "Item.h"
#include "IClear.h"
#include "ICloaking.h"

class ItemSet {
private :
	static ItemSet* Instance;
	std::vector<Item*> itemQueue;
	ItemSet();
public :
	static ItemSet* getInstance();

	int getQueueSize();

};
#endif // !__ITEMSET_H__
