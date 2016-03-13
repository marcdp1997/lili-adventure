#include <stdio.h>
#include "World.h"

void World::CreateWorld(){

	Rooms = new Room[16];

	for (int n = 0; n < 16; n++){
		Rooms[n].CreateRooms(n);
	}

	Paths = new Path[35];

	for (int n = 0; n < 35; n++){
		Paths[n].CreatePaths(n);
	}
	
}