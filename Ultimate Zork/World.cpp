#include "World.h"
#include "Item.h"
#include "Path.h"
#include "Room.h"
#include "Player.h"
#include "Enemy.h"
#include "Merchant.h"

World::World()
{
	// Rooms
	Room* crashed_airplane = new Room("Crashed Airplane", "Your plane had landed here. First area of your adventure");
	Room* lake = new Room("Lake", "Big lake with some fish.\nA river ends with a strong current in the west part");
	Room* jungle1 = new Room("Jungle", "Trees and two small paths.\nBehind those trees there is a river going from south to west, but you can't\ngo there");
	Room* middle = new Room("Middle of Nowhere", "You are in a huge field.\nTo the east you can see a big mountain");
	Room* mayan = new Room("Mayan Temple", "There is a deteriorated but beautiful Mayan temple");
	Room* jungle3 = new Room("Jungle", "Trees");
	Room* jungle2 = new Room("Jungle", "Trees and two small paths.\nThere is a river to the south behind those trees, but you can't go there.\nYou can see a mountain from this area");
	Room* peak = new Room("Makalu's Peak", "You arrived at the end of the map, congratulations!\nA helicopter picked you up to take you home");
	Room* campsite = new Room("Campsite", "Here you can rest and get warmed");
	Room* dunedin = new Room("Dunedin Gates", "This is the path that would guide you to the peak.\nThe river lets you here and you can't go back. The current is strong.\nA huge gates are in the north");
	Room* lookout = new Room("Lookout", "Such a beautiful views! You can see practically all the island and, in the east, an amazing waterfalls.\nThere is a merch in this area to buy or sell items");
	Room* cave = new Room("Cave", "You are in a cave located behind the waterfall.\nThere are prehistoric paintings in the walls");
	Room* chamber = new Room("Hidden chamber", "Small and cute chamber with nothing important");
	Room* waterfalls = new Room("Waterfalls", "A majestic waterfalls are in the south of this area. They aren't so high to jump from");
	Room* bottom = new Room("Bottom of the waterfalls", "There are lots of corpses floating.\nThe water creates a river to the east part.\nIt could end up in an interesting place");

	entities.pushback(crashed_airplane);
	entities.pushback(lake);
	entities.pushback(jungle1);
	entities.pushback(middle);
	entities.pushback(mayan);
	entities.pushback(jungle2);
	entities.pushback(jungle3);
	entities.pushback(peak);
	entities.pushback(campsite);
	entities.pushback(dunedin);
	entities.pushback(lookout);
	entities.pushback(cave);
	entities.pushback(chamber);
	entities.pushback(waterfalls);
	entities.pushback(bottom);

	// Paths
	Path* route_1f = new Path("Route 1", "It seems to be water there", crashed_airplane, lake, "south", NO_DOOR);
	Path* route_1b = new Path("Route 1", "Something is burning", lake, crashed_airplane, "north", NO_DOOR);
	Path* route_2f = new Path("Route 2", "There is a long path sorrounded by lots of trees", crashed_airplane, jungle3, "east", NO_DOOR);
	Path* route_2b = new Path("Route 2", "There is a long path sorrounded by lots of trees", jungle3, crashed_airplane, "west", NO_DOOR);
	Path* route_3f = new Path("Route 3", "Trees, trees and more trees", lake, jungle1, "south", NO_DOOR);
	Path* route_3b = new Path("Route 3", "It seems to be water there", jungle1, lake, "north", NO_DOOR);
	Path* route_4f = new Path("Route 4", "Trees, trees and more trees", jungle1, jungle2, "east", NO_DOOR);
	Path* route_4b = new Path("Route 4", "Trees, trees and more trees", jungle2, jungle1, "west", NO_DOOR);
	Path* route_5f = new Path("Route 5", "There are ruins all over the path", jungle2, mayan, "north", NO_DOOR);
	Path* route_5b = new Path("Route 5", "Trees, trees and more trees", mayan, jungle2, "south", NO_DOOR);
	Path* route_6f = new Path("Route 6", "There are ruins all over the path", middle, mayan, "south", NO_DOOR);
	Path* route_6b = new Path("Route 6", "Wow, there is a huge field with nothing important!", mayan, middle, "north", NO_DOOR);
	Path* route_7f = new Path("Route 7", "Wow, there is a huge field with nothing important!", lake, middle, "east", NO_DOOR);
	Path* route_7b = new Path("Route 7", "It seems to be water there", middle, lake, "west", NO_DOOR);
	Path* route_8f = new Path("Route 8", "Makalu Mountain is in front of you. There is a small tunnel where you can go to the next area", middle, lookout, "east", NO_DOOR);
	Path* route_8b = new Path("Route 8", "Makalu Mountain is in front of you. There is a small tunnel where you can go to the next area", lookout, middle, "west", NO_DOOR);
	Path* route_9f = new Path("Route 9", "There's a path that goes to the peak of the Mountain", campsite, peak, "north", NO_DOOR);
	Path* route_10f = new Path("Route 10", "There's a path that goes to the peak of the Mountain", dunedin, campsite, "north", CLOSE);
	Path* route_10b = new Path("Route 10", "Dunedin Gates are in this way", campsite, dunedin, "south", CLOSE);
	Path* route_11f = new Path("Route 11", "Something is burning", campsite, lake, "west", NO_DOOR);
	Path* route_12f = new Path("Route 12", "There is a river", bottom, dunedin, "east", NO_DOOR);
	Path* route_13f = new Path("Route 13", "The waterfalls do not let you see this way", bottom, cave, "west", NO_DOOR);
	Path* route_13b = new Path("Route 13", "The waterfalls do not let you see this way", cave, bottom, "east", NO_DOOR);
	Path* route_14f = new Path("Route 14", "There are stairs that go up somewhere", chamber, cave, "north", NO_DOOR);
	Path* route_14b = new Path("Route 14", "There are stairs that go down somewhere", cave, chamber, "south", NO_DOOR);
	Path* route_15f = new Path("Route 15", "The sound of the water falling is louder", jungle3, waterfalls, "south", NO_DOOR);
	Path* route_15b = new Path("Route 15", "Trees, trees and more trees", waterfalls, jungle3, "north", NO_DOOR);
	Path* route_16f = new Path("Route 16", "There is a rope hanging from the top of the waterfall", bottom, waterfalls, "north", NO_DOOR);
	Path* route_16b = new Path("Route 16", "There is a cliff where starts the waterfall and a rope hanging down", waterfalls, bottom, "south", NO_DOOR);

	entities.pushback(route_1f);
	entities.pushback(route_1b);
	entities.pushback(route_2f);
	entities.pushback(route_2b);
	entities.pushback(route_3f);
	entities.pushback(route_3b);
	entities.pushback(route_4f);
	entities.pushback(route_4b);
	entities.pushback(route_5f);
	entities.pushback(route_5b);
	entities.pushback(route_6f);
	entities.pushback(route_6b);
	entities.pushback(route_7f);
	entities.pushback(route_7b);
	entities.pushback(route_8f);
	entities.pushback(route_8b);
	entities.pushback(route_9f);
	entities.pushback(route_10f);
	entities.pushback(route_10b);
	entities.pushback(route_11f);
	entities.pushback(route_12f);
	entities.pushback(route_13f);
	entities.pushback(route_13b);
	entities.pushback(route_14f);
	entities.pushback(route_14b);
	entities.pushback(route_15f);
	entities.pushback(route_15b);
	entities.pushback(route_16f);
	entities.pushback(route_16b);

	// Map items
	Item* sword = new Item("sword", "Heavy sword with monster's blood. Damage = 3", crashed_airplane, 1, 0, 10);
	Item* gps = new Item("gps", "You can see the rooms you have near with this item", crashed_airplane, -1, 0, 12);
	Item* gold = new Item("gold", "Sell it to earn lots of coins", crashed_airplane, -1, 0, 100);
	Item* wshield = new Item("wshield", "Wood shield that reduces 1/3 monter's damage", crashed_airplane, 0, 0, 15);
	Item* bag = new Item("bag", "Improve your inventory capacity carrying more objects inside the bag", crashed_airplane, -1, 1, 10);
	Item* camo = new Item("camo", "You have more possibilities to evade enemy attacks", crashed_airplane, 2, 1, 20);
	Item* amulet = new Item("amulet", "You earn more coins per enemy killed and item sold", crashed_airplane, 2, 0, 50);

	entities.pushback(sword);
	entities.pushback(gps);
	entities.pushback(gold);
	entities.pushback(wshield);
	entities.pushback(bag);
	entities.pushback(camo);
	entities.pushback(amulet);

	// Shop items
	Item* bow = new Item("bow", "Perfect for long distances. Hits two times before being attacked. Damage = 2", nullptr, 1, 0, 35);
	Item* mshield = new Item("mshield", "Metal shield that reduces 2/3 monter's damage", nullptr, 0, 0, 22);
	Item* hood = new Item("hood", "Invisible hood that makes you inmune to enemy attaks", nullptr, 2, 0, 100);
	Item* potion = new Item("potion", "Your max HP increases  by 5", nullptr, -1, 0, 10);

	entities.pushback(bow);
	entities.pushback(mshield);
	entities.pushback(hood);
	entities.pushback(potion);

	// Player
	player = new Player("Aventurer", "You are brave and strong", crashed_airplane);
	entities.pushback(player);

	// Creatures
	Enemy* goblin1 = new Enemy("Goblin 1", "Wild creature that lives in the jungle", waterfalls);
	entities.pushback(goblin1);
	Enemy* goblin2 = new Enemy("Goblin 2", "Wild creature that lives in the jungle", jungle1);
	entities.pushback(goblin2);

	// Merchant
	merch = new Merchant("Merchant", "A creature with lots of items to buy", lookout);
	entities.pushback(merch);
	merch->inventory->pushback(bow);
	merch->inventory->pushback(mshield);
	merch->inventory->pushback(hood);
	merch->inventory->pushback(potion);
}

World::~World()
{}

void World::Ask()
{
	command.Tokenize(tokens);

	if (tokens.buffer[0] == "move" && (tokens.buffer[1] == "north" || tokens.buffer[1] == "south" || tokens.buffer[1] == "east" || tokens.buffer[1] == "west"))
	{
		if (!player->Move(tokens, entities)) printf("You can't go there.\n\n");
	}

	else if (tokens.buffer[0] == "look" && (tokens.buffer[1] == "north" || tokens.buffer[1] == "south" || tokens.buffer[1] == "east" || tokens.buffer[1] == "west" || tokens.buffer[1] == "room"))
	{
		if (!player->Look(tokens, entities)) printf("There isn't a path to look at.\n\n");
	}

	else if (tokens.buffer[0] == "pick")
	{
		if (!player->Pick(tokens, entities)) printf("Item not found.\n\n");
	}

	else if (tokens.buffer[0] == "drop")
	{
		if (!player->Drop(tokens, entities)) printf("This item is not in your inventory.\n\n");
	}

	else if ((tokens.buffer[0] == "open") || ((tokens.buffer[0] == "open") && (tokens.buffer[1] == "gates")))
	{
		if (player->CheckDoor(entities)) player->Door(OPEN, entities);
		else printf("There isn't a door in this area.\n\n");
	}

	else if ((tokens.buffer[0] == "close") || ((tokens.buffer[0] == "close") && (tokens.buffer[1] == "gates")))
	{
		if (player->CheckDoor(entities)) player->Door(CLOSE, entities);
		else printf("There isn't a door in this area.\n\n");
	}

	else if (tokens.buffer[0] == "equip")
	{
		if (!player->Equip(tokens)) printf("Item not found in the inventory.\n\n");
	}

	else if (tokens.buffer[0] == "unequip")
	{
		if (!player->Unequip(tokens)) printf("You aren't wearing this item so you can't unequip it.\n\n");
	}

	else if (tokens.buffer[0] == "inventory" || tokens.buffer[0] == "i" || (tokens.buffer[0] == "look" && (tokens.buffer[1] == "inventory") || (tokens.buffer[1] == "i")))
	{
		player->Inventory(tokens);
	}

	else if (tokens.buffer[0] == "bag" || tokens.buffer[0] == "b")
	{
		if (!player->Bag()) printf("Bag is not in your inventory.\n\n");
	}

	else if (tokens.buffer[0] == "turn" && tokens.buffer[1] == "on" && tokens.buffer[2] == "gps")
	{
		if (!player->TurnOnGPS(entities)) printf("GPS is not in your inventory.\n\n");
	}

	else if (tokens.buffer[0] == "put" && tokens.buffer[2] == "into")
	{
		if (!player->PutInto(tokens)) printf("To put one item into other, one has to allow to put other items inside itself\nand both have to exist and be in the inventory.\n\n");
	}

	else if (tokens.buffer[0] == "get" && tokens.buffer[2] == "from")
	{
		if (!player->GetFrom(tokens)) printf("To get one item from other, one has to allow to put other items inside itself\n and the other has to be inside. Also, both have to exist and be in the inventory.\n\n");
	}

	else if (tokens.buffer[0] == "get" && tokens.buffer[2] == "from")
	{
		if (!player->GetFrom(tokens)) printf("To get one item from other, one has to allow to put other items inside itself\n and the other has to be inside. Also, both have to exist and be in the inventory.\n\n");
	}

	else if (tokens.buffer[0] == "buy" && tokens.buffer[1] == "merchant")
	{
		if(player->curr_pos == merch->curr_pos) merch->LookItems();
		else printf("There isn't a merchant in this area.\n\n");
	}

	else if ((tokens.buffer[0] == "buy" || tokens.buffer[0] == "sell") && tokens.buffer[3] == "merchant")
	{
		if (player->curr_pos == merch->curr_pos)
		{
			if (!merch->BuySell(tokens, player)) printf("To buy or sell an item it has to be in your inventory or in the shop.\n\n");
		}
		else printf("There isn't a merchant in this area.\n\n");
	}

	else if (tokens.buffer[0] == "coins" || tokens.buffer[0] == "c")
	{
		printf("Coins: %i.\n\n", player->coins);
	}

	else if (tokens.buffer[0] == "hp")
	{
		printf("HP: %i.\n\n", player->hp);
	}

	else if (tokens.buffer[0] == "drink" && tokens.buffer[1] == "potion")
	{
		if (!player->Drink()) printf("Potion is not in your inventory.\n\n");
	}

	else if (tokens.buffer[0] == "help") Help();

	else if (tokens.buffer[0] == "quit") stop = 1;

	else printf("Command not recogized.\n\n");
}

void World::Call_Update()
{
	for (int i = 0; i < entities.num_elements; i++)
		entities.buffer[i]->Update(entities, player, i);
}

void World::Help() const
{
	printf("To move: move (north, south, east, west).\nTo look: look (north, south, east, west, room).\n");
	printf("To pick items: pick (name of the item).\nTo drop items: drop (name of the item).\n");
	printf("To see the inventory: inventory / i (only name of the items) or\nlook inventory / look i (name and description).\n");
	printf("To see the bag: bag / b (to see name of the items).\n");
	printf("To equip item: equip (name of the item).\nTo unequip item: unequip (name of the item).\n");
	printf("To get an item from other: get (name of the item) from (name of the item).\nTo put an item into other: put (name of the item) into (name of the item).\n");
	printf("To turn on GPS: turn on gps.\n");
	printf("To close/open gates: open (or open gates), close (or close gates).\n");
	printf("To buy/sell items: buy / sell (name of the item) from merchant.\n");
	printf("To see the items available to buy: buy (name of the item).\n");
	printf("To see your coins: coins / c.\nTo see your hp: hp.\n");
	printf("To see the commands: help.\nTo end game: quit.\n\n");
}

void World::Tutorial() const
{
	printf("Welcome survivor!\nYour plane had landed here a few days ago.\nYou were unconscious but now you have woken up.\nIt's time to explore this island and arrive to the peak.\n");
	printf("Remember to type 'help' if you want to see the commands during your adventure!\n");
	printf("Good luck!\n\n");

	player->Update(entities);
}
