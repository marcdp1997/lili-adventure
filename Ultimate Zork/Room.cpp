#include "Room.h"
#include "Item.h"

Room::Room(const char* name, const char* description) : Entity(name, description)
{
	type = ROOM;
	inventory = NULL;
}

Room::~Room()
{}