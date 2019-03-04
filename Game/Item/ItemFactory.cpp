#include "ItemFactory.h"
#include "Effect/ICloaking.h"
#include "Effect/IClear.h"

USING_NS_CC;
using namespace std;

ItemFactory* ItemFactory::Instance = NULL;

ItemFactory* ItemFactory::getInstance() {
	if (!Instance)
		Instance = new ItemFactory();
	return Instance;
}

ItemFactory::ItemFactory() {

}

Item* ItemFactory::createItem(string name) {
	if (name == "IClear.png")
		return new IClear();
	else if (name == "ICloaking.png")
		return new ICloaking();
	else
		return nullptr;
}