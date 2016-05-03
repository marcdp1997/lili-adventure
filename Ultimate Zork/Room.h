#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"

class Item;

class Room : public Entity
{
public:
	Room(const char* name, const char* description);
	virtual ~Room();
};

#endif