#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"
class Room;

#define MAX_ITEMS 2

class Item : public Entity
{
public:
	Room* location;
	bool more_itm;
	bool pick = 0;    // To know if it's inside the inventory of the player
	bool pick2 = 0;   // To know if it's inside the "inventory" of an item
	int equip;        // -1 == can't be equipped, 0 == not equiped, 1 == equiped

public:
	Item::Item(const char* name, const char* description, Room* location, int equip, int more_itm);
	virtual ~Item();
};

#endif