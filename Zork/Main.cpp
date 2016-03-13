#include <stdio.h>
#include "World.h"
#include "Player.h"

int main(){

	World Makalu;
	Makalu.CreateWorld();

	Player One;
	One.MovePlayer();


	getchar();
	return 0;
}