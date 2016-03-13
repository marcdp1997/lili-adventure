#include <stdio.h>
#include "Player.h"

void Player::AskPlayer(){

	printf(">");
	scanf_s("%s", command);

	if ((command == "move north") || (command == "move south") || (command == "move east") || (command == "move west")){
		MovePlayer();
	}


}

void Player::MovePlayer(){

	//Current room to path
	if (command == "move north"){

		curr_position = Rooms[curr_position].north;

		if (curr_position == 0){
			printf("You can't go there");
		}


	}

	//Path to next room
}