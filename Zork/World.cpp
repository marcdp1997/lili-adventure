#include <stdio.h>
#include "World.h"

void World::CreateWorld(){

	num_rooms = 16;
	Rooms = new Room[num_rooms];

	for (int n = 0; n < 16; n++){
		Rooms[n].CreateRooms(n);
	}

	num_paths = 35;
	Paths = new Path[num_paths];

	for (int n = 0; n < 35; n++){
		Paths[n].CreatePaths(n);
	}
}