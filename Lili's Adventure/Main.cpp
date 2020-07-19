#include <stdio.h>
#include <conio.h>
#include "World.h"
#include "Player.h"
#include "Room.h"

int main()
{
	World Island;

	Island.Tutorial();

	do{
		if (!_kbhit()) Island.CallUpdate();
		else Island.Ask();
		
	} while ((Island.player->curr_pos->name != "Makalu's Peak") && (Island.stop == 0) && (Island.player->hp > 0));

	printf("Thanks for playing!\n\n");

	getchar();
	return 0;
}