#include <stdio.h>
#include "Functions.h"

int main(){

	int quit = 0;
	char coord;
	curr_room = dinning_room;

	do{
		// Initialize spot
		init_room();

		// Print desc
		printf("%s", curr.description);

		// Ask for new room & change curr_room

		do{
			printf("\nIntroduce where you want to go: north(n), south(s), east(e), west(w) or quit(q).");
			scanf_s("%c", &coord, 1);
			getchar();

			curr_room = which_room(coord, curr_room);
			quit = finish(coord, quit);

			if (curr_room == wall) printf("It's a wall, you can't go there");

		} while ((curr_room == wall) || ((coord != 'n') && (coord != 's') && (coord != 'e') && (coord != 'w') && (coord != 'q')));

	} while (!quit);

	system("pause");
	return 0;
}