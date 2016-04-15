#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"
class Room;

class Item : public Entity
{
public:
	Room* location; // Which room is located the item
	bool picked; // 0 == not picked, 1 == picked
public:
	Item(const char* name, const char* description, Room* location);
	~Item();
};

#endif