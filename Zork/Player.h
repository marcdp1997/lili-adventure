#include "World.h"

Room* Rooms;

class Player{

public:
	char command[20];
	int curr_position;

public:
	void ChangePosition();
	void AskPlayer();
	void MovePlayer();
};