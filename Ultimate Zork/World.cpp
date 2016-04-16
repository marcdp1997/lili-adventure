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
	Path* route_1f = new Path("Route 1", "It seems to be water there", crashed_airplane, lake, "south", CLOSE);
	Path* route_1b = new Path("Route 1", "Something is burning", lake, crashed_airplane, "north", CLOSE);

	Entities.pushback(route_1f);
	Entities.pushback(route_1b);

	// Items
	Item* item_1 = new Item("sword", "Random item 1", crashed_airplane);
	Item* item_2 = new Item("shield", "Random item 2", crashed_airplane);
	Item* item_3 = new Item("horse", "Random item 3", crashed_airplane);

	Entities.pushback(item_1);
	Entities.pushback(item_2);
	Entities.pushback(item_3);

	// Player
	player = new Player("Marc", "The character is brave and strong", crashed_airplane);
	Entities.pushback(player);
}

World::~World()
{
	//Entities.clear();
}

void World::Ask()
{
	command.Tokenize(tokens);

	if (tokens.buffer[0] == "move" && (tokens.buffer[1] == "north" || tokens.buffer[1] == "south" || tokens.buffer[1] == "east" || tokens.buffer[1] == "west"))
	{
		player->Move(tokens, Entities);
	}

	else if (tokens.buffer[0] == "look" && (tokens.buffer[1] == "north" || tokens.buffer[1] == "south" || tokens.buffer[1] == "east" || tokens.buffer[1] == "west"))
	{
		player->LookPath(tokens, Entities);
	}

	else if (tokens.buffer[0] == "look" && tokens.buffer[1] == "room")
	{
		printf("%s. %s.\n\n", player->curr_pos->name.string, player->curr_pos->description.string);
	}

	else if ((tokens.buffer[0] == "open") || ((tokens.buffer[0] == "open") && (tokens.buffer[1] == "gates")))
	{
		printf("You have opened the gates.\n\n");
		player->Door(OPEN, Entities);
	}

	else if ((tokens.buffer[0] == "close") || ((tokens.buffer[0] == "close") && (tokens.buffer[1] == "gates")))
	{
		printf("You have closed the gates.\n\n");
		player->Door(CLOSE, Entities);
	}

	else if (tokens.buffer[0] == "pick")
	{
		player->Pick(tokens, Entities);
	}

	else if (tokens.buffer[0] == "drop")
	{
		player->Drop(tokens, Entities);
	}

	else if (tokens.buffer[0] == "look" && tokens.buffer[1] == "bag")
	{
		player->LookBag();
	}

	else if (tokens.buffer[0] == "help")
	{
		Help();
	}

	else if (tokens.buffer[0] == "quit") stop = 1;

	else printf("Command not recogized.\n\n");

}

void World::Help() const
{
	printf("To move: move (north, south, east, west).\nTo look: look (north, south, east, west, room or bag).\n\n");
	printf("To pick items: pick (name of the item).\n");
	printf("To drop items: drop (name of the item).\n\n");
	printf("For close/open gates: open (or open gates), close (or close gates).\n\n");
	printf("To see the commands: help.\nTo end game: quit.\n\n");
}
