#include "Item.h"

Item::Item(const char* name, const char* description, Room* location, int subtype, bool more_itm, uint coins) : 
Entity(name, description), location(location), subtype(subtype), coins(coins)
{
	type = ITEM;

	if (more_itm)
	{
		inventory = new Vector<Item*>(MAX_ITEMS);
	}
	else inventory = nullptr;
}

Item::~Item()
{}