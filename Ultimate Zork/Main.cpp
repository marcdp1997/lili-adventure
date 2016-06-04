#include <stdio.h>
#include <conio.h>
#include "World.h"
#include "Player.h"
#include "Room.h"

int main()
{
	World Island;

	Island.Tutorial();

	int i = 0;
	do{
		if (i++ == 0) printf("> ");

		if (!_kbhit()) Island.Call_Update();
		else
		{
			Island.Ask();
			i = 0;
		}
		
	} while ((Island.player->curr_pos->name != "Makalu's Peak") && (Island.stop == 0) && (Island.player->hp > 0));

	printf("Thanks for playing!\n\n");

	getchar();
	return 0;
}