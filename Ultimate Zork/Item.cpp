#include "Item.h"

void Item::CreateItems(const int num)
{
	switch (num)
	{
	case 0:
		name = "Item 1";
		description = "Random item 1";
		room = 0;
		picked = 0;
		break;

	case 1:
		name = "Item 2";
		description = "Random item 2";
		room = 0;
		picked = 0;
		break;

	case 2:
		name = "Item 3";
		description = "Random item 3";
		room = 0;
		picked = 0;
		break;

	case 3:
		name = "Item 4";
		description = "Random item 4";
		room = 0;
		picked = 0;
		break;

	case 4:
		name = "Item 5";
		description = "Random item 5";
		room = 0;
		picked = 0;
		break;
	}
}