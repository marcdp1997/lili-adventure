#include <stdio.h>
#include "Action.h"

void Action::Tutorial(const World &Island)
{
	printf("Welcome survivor!\nYour plane had landed here a few days ago.\nYou were unconscious but now you have woken up.\nIt's time to explore this island and arrive to the peak.\n");
	printf("But first of all, type 'help' to see the commands.\n\n");

	command.GetString();

	while (command != "help\n")
	{
		printf("Command not recognized.\n");
		command.GetString();
	}

	Help();

	printf("Press enter...\n");
	getchar();

	printf("So now we can continue. Remember to use 'help' if you're stuck.\n");
	printf("Good luck!\n\n");

	printf("%s. %s.\n\n", Island.Rooms[POS_PLAYER].name.string, Island.Rooms[POS_PLAYER].description.string);
}

void Action::Ask(World &Island)
{
	stop = 0;
	command.GetString();

	if (command == "move north\n")
		Move(Island, north);
	else if (command == "move south\n") 
		Move(Island, south);
	else if (command == "move east\n") 
		Move(Island, east);
	else if (command == "move west\n") 
		Move(Island, west);

	else if (command == "look north\n") 
		Look(Island, north);
	else if (command == "look south\n") 
		Look(Island, south);
	else if (command == "look east\n") 
		Look(Island, east);
	else if (command == "look west\n") 
		Look(Island, west);
	else if (command == "look room\n")
		printf("%s. %s.\n\n", Island.Rooms[POS_PLAYER].name.string, Island.Rooms[POS_PLAYER].description.string);

	else if ((command == "pick item 1\n") || (command == "pick item 2\n") || (command == "pick item 3\n") || (command == "pick item 4\n") || (command == "pick item 5\n")) 
		Pick(Island);
	else if ((command == "drop item 1\n") || (command == "drop item 2\n") || (command == "drop item 3\n") || (command == "drop item 4\n") || (command == "drop item 5\n"))
		Drop(Island);

	else if (command == "help\n")
		Help();

	else if (command == "quit\n")
		stop = 1;

	else
		printf("Command not recognized.\n");
}

void Action::Help() const
{
	printf("To move: move (north, south, east, west).\nTo look: look (north, south, east, west or room).\n\n");
	printf("For close/open gates: open (or open gates), close (or close gates).\nAlso allowed 'yes' and 'no'.\n\n");
	printf("To see the commands: help.\nTo end game: quit.\n\n");
}

void Action::Move(World &Island, const enum coords &coord)
{
	for (int i = 0; i < NUM_PATHS; i++) 
	{
		if ((POS_PLAYER == Island.Paths[i].source) && (Island.Paths[i].direction == coord)) 
		{
			if (Island.Paths[i].door == 0)
			{
				POS_PLAYER = Island.Paths[i].destination;
				printf("%s. %s.\n\n", Island.Rooms[POS_PLAYER].name.string, Island.Rooms[POS_PLAYER].description.string);
			}
			else CheckDoor(Island, i);
			break;
		}
		else if (i == NUM_PATHS - 1) printf("You can't go there.\n\n");
	}
}

void Action::Look(World &Island, const enum coords &coord)
{
	for (int i = 0; i < NUM_PATHS; i++)
	{
		if ((POS_PLAYER == Island.Paths[i].source) && (Island.Paths[i].direction == coord))
		{
			printf("%s.\n\n", Island.Paths[i].description.string);
			break;
		}
		else if (i == NUM_PATHS - 1) printf("There isn't a path to look at.\n\n");
	}
}

void Action::Pick(World &Island)
{
	command.GetWord(5);

	for (int i = 0; i < NUM_ITEMS; i++)
	{
		if ((Island.Rooms[POS_PLAYER].id == Island.Items[i].room) && (command == Island.Items[i].name) && (Island.Items[i].picked == 0))
		{
			if (LAST_ITEM < INV_CAPACITY)
			{
				Island.player->inventory[LAST_ITEM] = Island.Items[i];
				LAST_ITEM++;
				printf("%s is added to your inventory.\n\n", Island.Items[i].name.string);
				Island.Items[i].picked = 1;
			}
			else printf("Your inventory is full.\n\n");
			break;
		}
		if (i == NUM_ITEMS - 1) printf("No item found.\n\n");
	}
}

void Action::Drop(World &Island)
{
	command.GetWord(5);

	for (int i = 0; i < INV_CAPACITY; i++)
	{
		if (command == Island.player->inventory[i].name)
		{
			printf("You dropped %s.\n\n", Island.player->inventory[i].name.string);
			for (int u = i; u < INV_CAPACITY - 1; u++) Island.player->inventory[i] = Island.player->inventory[i + 1];
			LAST_ITEM--;
			Island.Items[i].picked = 0;
			break;
		}
		else if (i == INV_CAPACITY - 1) printf("Can't find this item in your inventory.\n\n");
	}
}

void Action::CheckDoor(World &Island, const int i)
{
	if (Island.Paths[i].door == 1)
	{
		printf("Wait! You left the gates opened, do you want to close them?\n");
		command.GetString();

		while ((command != "close\n") && (command != "close gates\n") && (command != "yes\n") && (command != "no\n") && (command != "help\n"))
		{
			printf("Command not recognized.\n");
			command.GetString();
		}

		if (command == "help\n") Help();

		else if ((command == "close\n") || (command == "close gates\n") || (command == "yes\n"))
		{
			Island.Paths[i].door = 2; // Closing one way
			
			for (int x = 0; x < NUM_PATHS; x++)
				if ((Island.Paths[i].destination == Island.Paths[x].source) && (Island.Paths[x].destination == Island.Paths[i].source))
					Island.Paths[x].door = 2; // Closing the other way

			printf("You have closed the gates.\n");
		}

		else  // Command == "no\n"
			printf("The gates remain opened.\n");

		POS_PLAYER = Island.Paths[i].destination;
		printf("%s. %s.\n\n", Island.Rooms[POS_PLAYER].name.string, Island.Rooms[POS_PLAYER].description.string);
	}

	if (Island.Paths[i].door == 2)
	{
		printf("The gates are closed. Do you want to open them?\n");
		command.GetString();

		while ((command != "open\n") && (command != "open gates\n") && (command != "yes\n") && (command != "no\n"))
		{
			printf("Command not recognized.\n");
			command.GetString();
		}

		if (command == "help\n") Help();

		else if ((command == "open\n") || (command == "open gates\n") || (command == "yes\n"))
		{
			Island.Paths[i].door = 1; // Opening one way

			for (int x = 0; x < NUM_PATHS; x++)
				if ((Island.Paths[i].destination == Island.Paths[x].source) && (Island.Paths[x].destination == Island.Paths[i].source))
					Island.Paths[x].door = 1; // Opening the other way

			printf("You have opened the gates.\n");
			POS_PLAYER = Island.Paths[i].destination;
			printf("%s. %s.\n\n", Island.Rooms[POS_PLAYER].name.string, Island.Rooms[POS_PLAYER].description.string);
		}
		else // Command == "no\n"
			printf("The gates remain closed. You can't go to the next room.\n");
	}
}



