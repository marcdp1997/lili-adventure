#ifndef WORLD_H
#define WORLD_H

#include "Room.h"
#include "Path.h"
#include "Player.h"

#define NUM_ROOMS 16
#define NUM_PATHS 34

class World
{
public:
	Room* Rooms;
	Path* Paths;
	Player* player; 

public:
	World();
	~World();
};

#endif