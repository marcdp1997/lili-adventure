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
	Room* lake = new Room("Lake", "Big lake with some fish. A river ends with a strong current in the west part");
	Room* jungle1 = new Room("Jungle", "Trees and two small paths. Behind those trees there is a river going from south to west, but you can't go there");
	Room* middle = new Room("Middle of Nowhere", "You are in a huge field. To the east you can see a big mountain");
	Room* mayan = new Room("Mayan Temple", "There is a deteriorated but beautiful Mayan temple");
	Room* jungle3 = new Room("Jungle", "Trees");
	Room* jungle2 = new Room("Jungle", "Trees and two small paths. There is a river to the south behind those trees, but you can't go there. You can see a mountain from this area");
	Room* peak = new Room("Makalu's Peak", "You arrived at the end of the map, congratulations! A helicopter picked you up to take you home");
	Room* campsite = new Room("Campsite", "Here you can rest and get warmed");
	Room* dunedin = new Room("Dunedin Gates", "This is the path that would guide you to the peak. The river lets you here and you can't go back. The current is strong. A huge gates are in the north");
	Room* lookout = new Room("Lookout", "Such a beautiful views! You can see practically all the island and, in the east, an amazing waterfalls. There is a merch in this area to buy or sell items");
	Room* cave = new Room("Cave", "You are in a cave located behind the waterfall. There are prehistoric paintings in the walls");
	Room* chamber = new Room("Hidden chamber", "Small and cute chamber with nothing important");
	Room* waterfalls = new Room("Waterfalls", "A majestic waterfalls are in the south of this area. They aren't so high to jump from");
	Room* bottom = new Room("Bottom of the waterfalls", "There are lots of corpses floating. The water creates a river to the east part. It could end up in an interesting place");

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
	Item* gps = new Item("gps", "You can see the rooms you have near with this item", jungle1, -1, 0, 12);
	Item* gold = new Item("gold", "Sell it to earn lots of coins", mayan, -1, 0, 100);
	Item* wshield = new Item("wshield", "Wood shield that reduces 1/3 monter's damage", chamber, 0, 0, 15);
	Item* bag = new Item("bag", "Improve your inventory capacity carrying more objects inside the bag", waterfalls, -1, 1, 10);
	Item* amulet = new Item("amulet", "You earn more coins per enemy killed and item sold", jungle3, 2, 0, 50);

	entities.pushback(sword);
	entities.pushback(gps);
	entities.pushback(gold);
	entities.pushback(wshield);
	entities.pushback(bag);
	entities.pushback(amulet);

	// Shop items
	Item* bow = new Item("bow", "Hits two times before being attacked. Damage = 2", nullptr, 1, 0, 35);
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
	Enemy* goblin1 = new Enemy("Goblin 1", "Wild creature that lives in the jungle", bottom);
	Enemy* goblin2 = new Enemy("Goblin 2", "Wild creature that lives in the jungle", jungle1);
	Enemy* goblin3 = new Enemy("Goblin 3", "Wild creature that lives in the jungle", dunedin);
	Enemy* goblin4 = new Enemy("Goblin 4", "Wild creature that lives in the jungle", middle);
	
	entities.pushback(goblin1);
	entities.pushback(goblin2);
	entities.pushback(goblin3);
	entities.pushback(goblin4);

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

	else if (tokens.buffer[0] == "call" && tokens.buffer[1] == "dad") CallDad();

	else if (tokens.buffer[0] == "quit") stop = 1;

	else printf("Command not recogized.\n\n");
}

void World::CallUpdate()
{
	for (int i = 0; i < entities.num_elements; i++)
		entities.buffer[i]->Update(entities, player, i);
}

void World::CallDad()
{
	printf("\n--------------------------------------------------------------------------------------------------------\n");

	// Motivational quotes
	int quote = rand() % 4;

	SlowPrint("*Calling", 100);
	SlowPrint("......*\n", 400);
	switch (quote)
	{
		case 0: SlowPrint("Dad: Breath Lili, you are going to be okey. ", 100); break;
		case 1: SlowPrint("Dad: You can do it honey! ", 100); break;
		case 2: SlowPrint("Dad: Keep going love, you almost have it. ", 100); break;
		case 3: SlowPrint("Dad: I will take you home Lili, I promise. ", 100); break;
	}
	SlowPrint("I'm sending all the commands. Check your phone.\n", 100);
	SlowPrint("*Sending", 100);
	SlowPrint("......*\n", 400);
	SlowPrint("*Received!*\n\n");

	// Commands
	printf("To move: 'move (north, south, east or west)'.\n");
	printf("To look: 'look (north, south, east, west or room)'.\n");
	printf("To pick items: 'pick (name of the item)'.\n");
	printf("To drop items: 'drop (name of the item)'.\n");
	printf("To see the inventory: 'inventory' and 'i', to see only name of the items, or 'look inventory' and 'look i', to see name and description.\n");
	printf("To see the bag: 'bag' and 'b' to see name of the items.\n");
	printf("To equip item: 'equip (name of the item)'.\n");
	printf("To unequip item: 'unequip (name of the item)'.\n");
	printf("To get an item from other: 'get (name of the item) from (name of the item)'.\n");
	printf("To put an item into other: 'put(name of the item) into(name of the item)'.\n");
	printf("To turn on GPS: 'turn on gps'.\n");
	printf("To drink potion: 'drink potion'.\n");
	printf("To close/open gates: 'open' and 'open gates' or 'close' and 'close gates'.\n");
	printf("To buy items: 'buy (name of the item) from merchant'.\n");
	printf("To sell items: 'sell (name of the item) from merchant'.\n");
	printf("To see the items available to buy: 'talk merchant'.\n");
	printf("To see your coins: 'coins' and 'c'.\n");
	printf("To see your hp: 'hp'.\n");
	printf("To see the commands: 'call dad'.\n");
	printf("To end game: 'quit'.\n\n");

	printf("--------------------------------------------------------------------------------------------------------\n\n");
}

void World::Tutorial()
{
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("                                    WELCOME TO LILI'S ADVENTURE                                         \n");
	printf("                 *You can skip every text by pressing any key of your keyboard*                         \n");
	printf("                             Your adventure is about to start, enjoy!                                   \n");
	printf("--------------------------------------------------------------------------------------------------------\n\n");

	clock_t end_time = 3 * 1000 + clock();
	while (clock() < end_time) {}

	SlowPrint("*Ring...* ", 200);
	SlowPrint("*Ring...* ", 200);	
	SlowPrint("*Ring...*\n", 200);

	SlowPrint("- Dad: Lili? Is that you? Thank god you are alive! You have to get out of here RIGHT NOW!\n", 100);
	SlowPrint("- Lili: Wh-why? Whe-where am I?\n", 100);
	SlowPrint("- Dad: You are at Makalu Island, your plane crashed yesterday. Don't you remember? The news are talking about this all the time!\n", 100);
	SlowPrint("*Lili looks at her arm. It is bleeding a lot.*\n", 50);
	SlowPrint("- Dad: Meet me at the peak of the mountain in 20 minutes. Don't ask me why, you have to hurry Lili.\n", 100);
	SlowPrint("- Lili: Dad... I'm scared. I can't do this alone, my arm hurts a-and I don't know what to do.\n", 100);
	SlowPrint("- Dad: Of course you can! You can ask me for help whenever you want Lili. Just call me.\n       I'm here with you honey. Be brave. Now... RUN!\n\n", 100);

	SlowPrint("*Remember to type 'call dad' if you want to talk with Dad*\n\n");

	player->Update(entities);
}

void World::SlowPrint(const char* message, uint milis_per_char)
{
	String str = message;

	for (int i = 0; i < str.Length(); i++)
	{
		if (!_kbhit())
		{
			clock_t end_time = milis_per_char + clock(); // 1st num == seconds of delay
			while (clock() < end_time) {}
		}

		printf("%c", str.string[i]);
	}

	if (_kbhit()) _getch();
}
