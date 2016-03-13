#ifndef PLAYER_H
#define PLAYER_H

#include "World.h"

class Player{

public:
	char command[20];
	int curr_position;
	int stopgame;

public:
	void AskPlayer(World Makalu);
	void MovePlayer(World Makalu);
	void LookPlayer(World Makalu);
};

#endif