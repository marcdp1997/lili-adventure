#include "World.h"
#include "Item.h"
#include "Path.h"
#include "Room.h"
#include "Player.h"

World::World()
{
	// Rooms
	Room* crashed_airplane = new Room("Crashed Airplane", "Your plane had landed here. First area of your adventure");
	Room* lake = new Room("Lake", "Big lake with some fish.\nA river ends with a strong current in the west part");

	Entities.pushback(crashed_airplane);
	Entities.pushback(lake);

	// Paths
	Path* route_1f = new Path("Route 1", "It seems to be water there", crashed_airplane, lake, "South", NO_DOOR);
	Path* route_1b = new Path("Route 1", "Something is burning", lake, crashed_airplane, "North", NO_DOOR);

	Entities.pushback(route_1f);
	Entities.pushback(route_1b);

	// Items
	Item* item_1 = new Item("Item 1", "Random item 1", crashed_airplane);
	Item* item_2 = new Item("Item 2", "Random item 2", crashed_airplane);

	Entities.pushback(item_1);
	Entities.pushback(item_2);

	// Player
	player = new Player("Marc", "The character is brave and strong", crashed_airplane);
	Entities.pushback(player);
}

World::~World()
{}

void World::Ask()
{
	command.GetString();

	if ((command == "move north\n") || (command == "move south\n") || (command == "move east\n") || (command == "move west\n"))
	{
		command.GetWord(5);
		player->Move(command, Entities);
	}
}