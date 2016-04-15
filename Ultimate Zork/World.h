#ifndef WORLD_H
#define WORLD_H

#include "Room.h"
#include "Path.h"
#include "Player.h"
#include "Item.h"

#define NUM_ROOMS 16
#define NUM_PATHS 35
#define NUM_ITEMS 5

class World
{
public:
	Room* Rooms;
	Path* Paths;
	Player* player; 
	Item* Items;

public:
	World();
	virtual ~World();
};

#endif