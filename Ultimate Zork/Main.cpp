#include <stdio.h>
#include "World.h"
#include "Action.h"

int main()
{
	World Island;
	Action Game;
	
	Game.Tutorial(Island);

	do{
		Game.Ask(Island);
	}while ((Game.stop == 0) && (Island.Rooms[Island.player->curr_pos].id != 6));

	getchar();
	return 0;
}