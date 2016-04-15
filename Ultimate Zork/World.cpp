#include "World.h"

World::World()
{
	Rooms = new Room[NUM_ROOMS];
	for (int i = 0; i < NUM_ROOMS; i++)
	{
		Rooms[i].CreateRooms(i);
	}

	Paths = new Path[NUM_PATHS];
	for (int i = 0; i < NUM_PATHS; i++)
	{
		Paths[i].CreatePaths(i);
	}

	Items = new Item[NUM_ITEMS];
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		Items[i].CreateItems(i);
	}

	player = new Player; // Right now there is only 1 player
}

World::~World()
{
	delete[] Rooms;
	delete[] Paths;
	delete[] Items;
	delete player;
}