#include "Item.h"

Item::Item(const char* name, const char* description, Room* location, int equip, int more_itm) : 
Entity(name, description), equip(equip), location(location), more_itm(more_itm)
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