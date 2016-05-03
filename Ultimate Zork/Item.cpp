#include "Item.h"

Item::Item(const char* name, const char* description, Room* location, int equip, bool more_itm) : 
Entity(name, description), equip(equip), location(location)
{
	type = ITEM;

	if (more_itm)
	{
		inventory = new Vector<Item*>(MAX_ITEMS);
	}
	else inventory = NULL;
}

Item::~Item()
{}