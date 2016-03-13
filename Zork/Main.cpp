#include <stdio.h>
#include "Player.h"
#include "World.h"


int main(){

	World Makalu;
	Makalu.CreateWorld();

	Player One;
	do{
		One.AskPlayer(Makalu);
	} while (One.stopgame != 1);

	getchar();
	return 0;
}