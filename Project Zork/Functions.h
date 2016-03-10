#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct {
	char *description;
	int north;
	int south;
	int east;
	int west;
	//char item;
	//int points;
} room_data;

room_data curr;

enum rooms{ dinning_room, kitchen, bathroom, bedroom, pantry, wall };

enum rooms curr_room;

void init_room();
enum rooms which_room(char coord, enum rooms curr_room);
int finish(char coord, int quit);

#endif