#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Player.h"

void Player::AskPlayer(World Makalu)
{
	stopgame = 0;
	curr_position = 0;
	printf(">");
	fgets(command, sizeof(command), stdin);

	if (strcmp(command, "move\n") == 0){
		printf("Where do you want to move?\n");
		fgets(command, sizeof(command), stdin);
		MovePlayer(Makalu);
	}
	else if (strcmp(command, "look\n") == 0){
		printf("Where do you want to look?\n");
		fgets(command, sizeof(command), stdin);
		LookPlayer(Makalu);
	}
	else if (strcmp(command, "help\n") == 0){
		printf("Commands: move, look, quit, help, open // open door, close // close door.\n");
		printf("Directions: north, south, east, west.\n");
	}
	else if (strcmp(command, "quit\n") == 0)
		stopgame = 1;
}

void Player::MovePlayer(World Makalu)
{
	//Source to destination
	if (strcmp(command, "north\n") == 0)
	{
		if (Makalu.Rooms[curr_position].north == -1)
			printf("You can't go there");
		else
			for (int i = 0; i < Makalu.num_paths; i++)
				if (Makalu.Paths[i].id == Makalu.Rooms[curr_position].north)
				{
					curr_position = Makalu.Paths[i].destination;
					break;
				}			
	}

	if (strcmp(command, "south\n") == 0)
	{
		if (Makalu.Rooms[curr_position].south == -1)
			printf("You can't go there");
		else
			for (int i = 0; i < Makalu.num_paths; i++)
				if (Makalu.Paths[i].id == Makalu.Rooms[curr_position].south)
				{
					curr_position = Makalu.Paths[i].destination;
					break;
				}
	}

	if (strcmp(command, "east\n") == 0)
	{
		if (Makalu.Rooms[curr_position].east == -1)
			printf("You can't go there");
		else
			for (int i = 0; i < Makalu.num_paths; i++)
				if (Makalu.Paths[i].id == Makalu.Rooms[curr_position].east)
				{
					curr_position = Makalu.Paths[i].destination;
					break;
				}
	}

	if (strcmp(command, "west\n") == 0)
	{
		if (Makalu.Rooms[curr_position].west == -1)
			printf("You can't go there");
		else
			for (int i = 0; i < Makalu.num_paths; i++)
				if (Makalu.Paths[i].id == Makalu.Rooms[curr_position].west)
				{
					curr_position = Makalu.Paths[i].destination;
					break;
				}
	}

	//Showing room description
	for (int i = 0; i < Makalu.num_rooms; i++)
		if (Makalu.Rooms[i].id == curr_position)
		{
			printf("You are in %s%s", Makalu.Rooms[i].name, Makalu.Rooms[i].description);
			break;
		}
}

void Player::LookPlayer(World Makalu)
{
	//Source to destination
	if (strcmp(command, "north\n") == 0)
	{
		if (Makalu.Rooms[curr_position].north == -1)
			printf("There is no path to look at.\n");
		else
			for (int i = 0; i < Makalu.num_paths; i++)
				if (Makalu.Paths[i].id == Makalu.Rooms[curr_position].north)
					printf("%s", Makalu.Paths[i].description);
	}

	else if (strcmp(command, "south\n") == 0)
	{
		if (Makalu.Rooms[curr_position].south == -1)
			printf("There is no path to look at.\n");
		else
			for (int i = 0; i < Makalu.num_paths; i++)
				if (Makalu.Paths[i].id == Makalu.Rooms[curr_position].south)
					printf("%s", Makalu.Paths[i].description);
	}

	else if (strcmp(command, "east\n") == 0)
	{
		if (Makalu.Rooms[curr_position].east == -1)
			printf("There is no path to look at.\n");
		else
			for (int i = 0; i < Makalu.num_paths; i++)
				if (Makalu.Paths[i].id == Makalu.Rooms[curr_position].east)
					printf("%s", Makalu.Paths[i].description);
	}

	else if (strcmp(command, "west\n") == 0)
	{
		if (Makalu.Rooms[curr_position].west == -1)
			printf("There is no path to look at.\n");
		else
			for (int i = 0; i < Makalu.num_paths; i++)
				if (Makalu.Paths[i].id == Makalu.Rooms[curr_position].west)
					printf("%s", Makalu.Paths[i].description);
	}
}