#include "Item.h"

Item::Item(const char* name, const char* description, Room* location, int subtype, bool more_itm) : 
Entity(name, description), location(location), subtype(subtype)
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