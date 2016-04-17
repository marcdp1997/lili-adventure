#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"
class Room;

class Item : public Entity
{
public:
	Room* location; // Which room is located the item
	bool pick = 0; // 0 == not picked, 1 == picked
	int equip; // -1 == can't be equipped, 0 == not equiped, 1 == equiped
public:
	Item(const char* name, const char* description, Room* location, int num);
	~Item();
};

#endif