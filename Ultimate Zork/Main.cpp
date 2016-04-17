#include <stdio.h>
#include "World.h"
#include "Player.h"
#include "Room.h"

int main()
{
	World Island;

	Island.Tutorial();

	int i = 0;
	do{
		Island.Ask();
	} while ((Island.player->curr_pos->name != "Peak") && (Island.stop == 0));

	printf("Thanks for playing!\n\n");

	getchar();
	return 0;
}