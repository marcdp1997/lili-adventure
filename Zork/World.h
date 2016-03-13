#ifndef WORLD_H
#define WORLD_H

#include "Room.h"
#include "Path.h"

class World{

public:
	Room* Rooms;
	Path* Paths;
	int num_rooms;
	int num_paths;

public:
	void CreateWorld();

};

#endif