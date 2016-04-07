#include <stdio.h>
#include "Action.h"

void Action::Tutorial(World &Island)
{
	printf("Welcome survivor!\nYour plane had landed here a few days ago.\nYou were unconscious but now you have woken up.\nIt's time to explore this island and arrive to the peak.\n");
	printf("But first of all, type 'help' to see the commands.\n\n");

	int a = 0;
	while (command != "help\n")
	{
		if (a > 0) printf("Command not recognized.\n");
		command.GetString();
		a++;
	}

	Help();

	printf("Press enter...\n");
	getchar();

	printf("So now we can continue. Remember to use 'help' if you're stuck.\n");
	printf("Good luck!\n");

	printf("%s %s\n\n", Island.Rooms[Island.player->curr_pos].name.string, Island.Rooms[Island.player->curr_pos].description.string);
}

void Action::Ask(World &Island)
{
	stop = 0;
	command.GetString();

	if ((command == "move north\n") || (command == "move south\n") || (command == "move east\n") || (command == "move west\n"))
		Move(Island);

	else if ((command == "look north\n") || (command == "look south\n") || (command == "look east\n") || (command == "look west\n") || (command == "look room\n"))
		Look(Island);

	else if (command == "help\n")
		Help();

	else if (command == "quit\n")
		stop = 1;

	else
		printf("Command not recognized.\n");
}

void Action::Help()
{
	printf("To move: move (north, south, east, west).\nTo look: look (north, south, east, west or room).\n\n");
	printf("For close/open gates: open (or open gates), close (or close gates).\nAlso allowed 'yes' and 'no'.\n\n");
	printf("To see the commands: help.\nTo end game: quit.\n\n");
}

void Action::Move(World &Island)
{
	if (command == "move north\n")
	{
		if (Island.Rooms[Island.player->curr_pos].north == -1)
		{
			printf("You can't go there\n\n");
		}
		else
		{
			for (int i = 0; i < NUM_PATHS; i++)
			{
				if (Island.Paths[i].id == Island.Rooms[Island.player->curr_pos].north)
				{
					CheckDoor(Island, i);
					break;
				}
			}
		}
	}

	else if (command == "move south\n")
	{
		if (Island.Rooms[Island.player->curr_pos].south == -1)
		{
			printf("You can't go there\n\n");
		}
		else
		{
			for (int i = 0; i < NUM_PATHS; i++)
			{
				if (Island.Paths[i].id == Island.Rooms[Island.player->curr_pos].south)
				{
					CheckDoor(Island, i);
					break;
				}
			}
		}
	}

	else if (command == "move east\n")
	{
		if (Island.Rooms[Island.player->curr_pos].east == -1)
		{
			printf("You can't go there\n\n");
		}
		else
		{
			for (int i = 0; i < NUM_PATHS; i++)
			{
				if (Island.Paths[i].id == Island.Rooms[Island.player->curr_pos].east)
				{
					CheckDoor(Island, i);
					break;
				}
			}
		}
	}

	else if (command == "move west\n")
	{
		if (Island.Rooms[Island.player->curr_pos].west == -1)
		{
			printf("You can't go there\n\n");
		}
		else
		{
			for (int i = 0; i < NUM_PATHS; i++)
			{
				if (Island.Paths[i].id == Island.Rooms[Island.player->curr_pos].west)
				{
					CheckDoor(Island, i);
					break;
				}
			}
		}
	}
}

void Action::Look(World &Island)
{
	if (command == "look north\n")
	{
		if (Island.Rooms[Island.player->curr_pos].north == -1)
		{
			printf("There isn't a path to look at.\n\n");
		}
		else
		{
			for (int i = 0; i < NUM_PATHS; i++)
			{
				if (Island.Paths[i].id == Island.Rooms[Island.player->curr_pos].north)
					printf("%s\n\n", Island.Paths[i].description.string);
			}
		}
	}

	if (command == "look south\n")
	{
		if (Island.Rooms[Island.player->curr_pos].south == -1)
		{
			printf("There isn't a path to look at.\n\n");
		}
		else
		{
			for (int i = 0; i < NUM_PATHS; i++)
			{
				if (Island.Paths[i].id == Island.Rooms[Island.player->curr_pos].south)
					printf("%s\n\n", Island.Paths[i].description.string);
			}
		}
	}

	if (command == "look east\n")
	{
		if (Island.Rooms[Island.player->curr_pos].east == -1)
		{
			printf("There isn't a path to look at.\n\n");
		}
		else
		{
			for (int i = 0; i < NUM_PATHS; i++)
			{
				if (Island.Paths[i].id == Island.Rooms[Island.player->curr_pos].east)
					printf("%s\n\n", Island.Paths[i].description.string);
			}
		}
	}

	if (command == "look west\n")
	{
		if (Island.Rooms[Island.player->curr_pos].west == -1)
		{
			printf("There isn't a path to look at.\n\n");
		}
		else
		{
			for (int i = 0; i < NUM_PATHS; i++)
			{
				if (Island.Paths[i].id == Island.Rooms[Island.player->curr_pos].west)
					printf("%s\n\n", Island.Paths[i].description.string);
			}
		}
	}

	if (command == "look room\n")
	{
		printf("%s\n\n", Island.Rooms[Island.player->curr_pos].description.string);
	}
}

void Action::CheckDoor(World &Island, const int i)
{
	if (Island.Paths[i].door == 0) 
		Update(Island, i);

	else if (Island.Paths[i].door == 1)
	{
		int a = 0;
		while ((command != "close\n") && (command != "close gates\n") && (command != "yes\n") && (command != "no\n"))
		{
			if (command == "help\n")
				Help();
			else if (a > 0) 
				printf("Command not recognized.\n");

			printf("Wait! You left the gates opened, do you want to close them?\n");
			command.GetString();
			a++;
		}

		if ((command == "close\n") || (command == "close gates\n") || (command == "yes\n"))
		{
			Island.Paths[i].door = 2;
			// Closing both paths (Path from A to B and from B to A). That's because there is only one door but two ways of passing it (front and back).
			for (int x = 0; x < NUM_PATHS; x++)
			{
				if ((Island.Paths[i].destination == Island.Paths[x].source) && (Island.Paths[x].destination == Island.Paths[i].source))
					Island.Paths[x].door = 2;
			}
			printf("You have closed the gates.\n");
		}
		if (command == "no\n") printf("The gates remain opened.\n");
		Update(Island, i);
	}

	else if (Island.Paths[i].door == 2)
	{
		int a = 0;
		while ((command != "open\n") && (command != "open gates\n") && (command != "yes\n") && (command != "no\n"))
		{
			if (command == "help\n") 
				Help();
			else if (a > 0) 
				printf("Command not recognized.\n");

			printf("The gates are closed! Do you want to open them?\n");
			command.GetString();
			a++;
		}

		if ((command == "open\n") || (command == "open gates\n") || (command == "yes\n"))
		{
			Island.Paths[i].door = 1;

			for (int x = 0; x < NUM_PATHS; x++)
			{
				if ((Island.Paths[i].destination == Island.Paths[x].source) && (Island.Paths[x].destination == Island.Paths[i].source))
					Island.Paths[x].door = 1;
			}
			printf("You have opened the gates.\n");
			Update(Island, i);
		}
		if (command == "no\n") printf("The gates remain closed.\n");
	}
}

void Action::Update(World &Island, const int i)
{
	Island.player->curr_pos = Island.Paths[i].destination;
	printf("%s %s\n\n", Island.Rooms[Island.player->curr_pos].name.string, Island.Rooms[Island.player->curr_pos].description.string);
}

