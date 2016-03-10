#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

void init_room(){

	if (curr_room == dinning_room){
		curr.description = "You are in the dinning room";
		curr.north = 1;
		curr.south = 3;
		curr.east = 2;
		curr.west = 5;
	}

	else if (curr_room == kitchen){
		curr.description = "You are in the kitchen";
		curr.north = 5;
		curr.south = 0;
		curr.east = 4;
		curr.west = 5;
	}

	else if (curr_room == bathroom){
		curr.description = "You are in the bathroom";
		curr.north = 5;
		curr.south = 5;
		curr.east = 5;
		curr.west = 0;
	}

	else if (curr_room == bedroom){
		curr.description = "You are in the bedroom";
		curr.north = 0;
		curr.south = 5;
		curr.east = 5;
		curr.west = 5;
	}

	else if (curr_room == pantry){
		curr.description = "You are in the pantry";
		curr.north = 5;
		curr.south = 5;
		curr.east = 5;
		curr.west = 1;
	}
}

enum rooms which_room(char coord, enum rooms curr_room){

	if (coord == 'n') curr_room = curr.north;
	else if (coord == 's') curr_room = curr.south;
	else if (coord == 'e') curr_room = curr.east;
	else if (coord == 'w') curr_room = curr.west;

	return curr_room;
}

int finish(char coord, int quit){

	if (coord == 'q') quit = 1;
	return quit;
}