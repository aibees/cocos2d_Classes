#include "Factory.h"

Item* Factory::createItem(std::string name)
{
	return new Item();
}
