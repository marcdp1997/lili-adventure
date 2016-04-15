#include "Item.h"

Item::Item(const char* name, const char* description, Room* location) : 
Entity(name, description, ITEM),
location(location)
{
	picked = 0;
}

Item::~Item()
{}