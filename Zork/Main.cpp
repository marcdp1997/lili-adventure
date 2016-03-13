#include <stdio.h>
#include "Player.h"
#include "World.h"


int main(){

	printf("Welcome survivor!\nYour plane had landed here a few days ago.\nYou were unconscious but now you have woken up.\nIt's time to explore this island and arrive to the peak.\nGood luck!\n\n");
	printf("Type help if you don't know what to do.\n\n");

	// Creating world Makalu
	World Makalu;
	Makalu.CreateWorld();

	// Creating player One
	Player One;
	One.curr_position = 0;
	printf("%s %s\n\n", Makalu.Rooms[One.curr_position].name, Makalu.Rooms[One.curr_position].description);

	//Game loop; you can end with quit or arriving to Room 6.
	do{
		One.AskPlayer(Makalu);
	} while ((One.stopgame != 1) && (Makalu.Rooms[One.curr_position].id != 6));

	getchar();
	return 0;
}