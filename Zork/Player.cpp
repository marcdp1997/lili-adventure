#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Player.h"

// Checking which command typed the player
void Player::AskPlayer(World Makalu){
	stopgame = 0;
	printf("> ");
	fgets(command, sizeof(command), stdin);

	if (((strcmp(command, "go north\n") == 0) || (strcmp(command, "go south\n") == 0) || (strcmp(command, "go east\n") == 0) || (strcmp(command, "go west\n") == 0)))
		MovePlayer(Makalu);

	else if (((strcmp(command, "look north\n") == 0) || (strcmp(command, "look south\n") == 0) || (strcmp(command, "look east\n") == 0) || (strcmp(command, "look west\n") == 0)))
		LookPlayer(Makalu);

	else if (strcmp(command, "help\n") == 0)
		printf("Commands:\n Move: go north, go south, go east, go west.\n Look: look north, look south, look east, look west.\n Gates: open (or open gates), close (or close gates).\n Quit.\n\n");

	else if (strcmp(command, "quit\n") == 0)
		stopgame = 1;
}

// Showing path's description
void Player::LookPlayer(World Makalu){
	
	if (strcmp(command, "look north\n") == 0){
		if (Makalu.Rooms[curr_position].north == -1)
			printf("There isn't a path to look at.\n\n");
		else
			for (int i = 0; i < Makalu.num_paths; i++)
				if (Makalu.Paths[i].id == Makalu.Rooms[curr_position].north)
					printf("%s\n\n", Makalu.Paths[i].description);
	}

	else if (strcmp(command, "look south\n") == 0){
		if (Makalu.Rooms[curr_position].south == -1)
			printf("There isn't a path to look at.\n\n");
		else
			for (int i = 0; i < Makalu.num_paths; i++)
				if (Makalu.Paths[i].id == Makalu.Rooms[curr_position].south)
					printf("%s\n\n", Makalu.Paths[i].description);
	}

	else if (strcmp(command, "look east\n") == 0){
		if (Makalu.Rooms[curr_position].east == -1)
			printf("There isn't a path to look at.\n\n");
		else
			for (int i = 0; i < Makalu.num_paths; i++)
				if (Makalu.Paths[i].id == Makalu.Rooms[curr_position].east)
					printf("%s\n\n", Makalu.Paths[i].description);
	}

	else if (strcmp(command, "look west\n") == 0){
		if (Makalu.Rooms[curr_position].west == -1)
			printf("There isn't a path to look at.\n\n");
		else
			for (int i = 0; i < Makalu.num_paths; i++)
				if (Makalu.Paths[i].id == Makalu.Rooms[curr_position].west)
					printf("%s\n\n", Makalu.Paths[i].description);
	}
}

// Calling CheckDoor and establishing the path.
void Player::MovePlayer(World Makalu){

	if (strcmp(command, "go north\n") == 0){
		if (Makalu.Rooms[curr_position].north == -1)
			printf("You can't go there\n\n");
		else
			// Travelling to check if there is a door in the path that has Makalu.Rooms[curr_position].north.
			for (int i = 0; i < Makalu.num_paths; i++)
				if (Makalu.Paths[i].id == Makalu.Rooms[curr_position].north){
					CheckDoor(Makalu, i);
					break;
				}
	}

	if (strcmp(command, "go south\n") == 0){
		if (Makalu.Rooms[curr_position].south == -1)
			printf("You can't go there\n\n");
		else
			for (int i = 0; i < Makalu.num_paths; i++)
				if (Makalu.Paths[i].id == Makalu.Rooms[curr_position].south){
					CheckDoor(Makalu, i);
					break;
				}
	}

	if (strcmp(command, "go east\n") == 0){
		if (Makalu.Rooms[curr_position].east == -1)
			printf("You can't go there\n\n");
		else
			for (int i = 0; i < Makalu.num_paths; i++)
				if (Makalu.Paths[i].id == Makalu.Rooms[curr_position].east){
					CheckDoor(Makalu, i);
					break;
				}
	}

	if (strcmp(command, "go west\n") == 0){
		if (Makalu.Rooms[curr_position].west == -1)
			printf("You can't go there\n\n");
		else
			for (int i = 0; i < Makalu.num_paths; i++)
				if (Makalu.Paths[i].id == Makalu.Rooms[curr_position].west){
					CheckDoor(Makalu, i);
					break;
				}

	}
}

// Checking if there is a door in the path. If so, check if it is open or not. Changing curr_position and showing name and desc.
void Player::CheckDoor(World Makalu, int i){

	if ((strcmp(Makalu.Paths[i].door, "closed") == 0)){
		printf("The gates are closed!\n");
		printf("> ");
		fgets(command, sizeof(command), stdin);
		// If you want to open
		if ((strcmp(command, "open\n") == 0) || (strcmp(command, "open gates\n") == 0)){
			strcpy_s(Makalu.Paths[i].door, 10, "opened");
			// Opening both paths.
			for (int x = 0; x < Makalu.num_paths; x++){
				if ((Makalu.Paths[i].destination == Makalu.Paths[x].source) && (Makalu.Paths[x].destination == Makalu.Paths[i].source))
					strcpy_s(Makalu.Paths[x].door, 10, "opened");
			}
			printf("You have opened the gates.\n\n");
		}
	}

	if ((strcmp(Makalu.Paths[i].door, "opened") == 0)){
		printf("Remember: you left the gates opened; you can ignore it or close them.\n\n");
		printf("> ");
		fgets(command, sizeof(command), stdin);
		// If you want to close:
		if ((strcmp(command, "close\n") == 0) || (strcmp(command, "close gates\n") == 0)){
			strcpy_s(Makalu.Paths[i].door, 10, "closed");
			// Closing both paths (Path from A to B and from B to A). That's because there is only one door but two ways of passing it (front and back).
			for (int x = 0; x < Makalu.num_paths; x++){
				if ((Makalu.Paths[i].destination == Makalu.Paths[x].source) && (Makalu.Paths[x].destination == Makalu.Paths[i].source))
					strcpy_s(Makalu.Paths[x].door, 10, "closed");
			}
			printf("You have closed the gates.\n\n");
		}
		//Changing curr_position
		curr_position = Makalu.Paths[i].destination;
		printf("%s %s\n\n", Makalu.Rooms[curr_position].name, Makalu.Rooms[curr_position].description);
	}

	// If there is no_door, then we only change position
	if ((strcmp(Makalu.Paths[i].door, "no_door") == 0)){
		curr_position = Makalu.Paths[i].destination;
		printf("%s %s\n\n", Makalu.Rooms[curr_position].name, Makalu.Rooms[curr_position].description);
	}

	// When the program asks for close / open you can type whatever you want to ignore it.
}