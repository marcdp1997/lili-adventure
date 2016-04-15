#include <stdio.h>
#include "World.h"

int main()
{
	World Island;

	int i = 0;
	do{
		Island.Ask();
	} while (i == 0);

	getchar();
	return 0;
}