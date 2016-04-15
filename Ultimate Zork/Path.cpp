#include "Path.h"

void Path::CreatePaths(const int num)
{
	switch (num)
	{
	case 0:
		description = "It seems to be water there...";
		door = 0;
		source = 0; // id of the curr room
		destination = 1; // id of the room we want to go
		direction = south;
		break;

	case 1:
		description = "There is a long path sorrounded by lots of trees.";
		door = 0;
		source = 0;
		destination = 12;
		direction = east;
		break;

	case 2:
		description = "There is smoke above the trees. Maybe something is burning?";
		door = 0;
		source = 1;
		destination = 0;
		direction = north;
		break;

	case 3:
		description = "Trees, trees and more trees.";
		door = 0;
		source = 1;
		destination = 2;
		direction = south;
		break;

	case 4:
		description = "Wow, there is a huge field with nothing important!";
		door = 0;
		source = 1;
		destination = 3;
		direction = east;
		break;

	case 5:
		description = "It seems to be water there...";
		door = 0;
		source = 2;
		destination = 1;
		direction = north;
		break;

	case 6:
		description = "Trees, trees and more trees.";
		door = 0;
		source = 2;
		destination = 5;
		direction = east;
		break;

	case 7:
		description = "Trees, trees and more trees.";
		door = 0;
		source = 2;
		destination = 15;
		direction = south;
		break;

	case 8:
		description = "It seems to be water there...";
		door = 0;
		source = 3;
		destination = 1;
		direction = west;
		break;

	case 9:
		description = "There are ruins all over the path.";
		door = 0;
		source = 3;
		destination = 4;
		direction = south;
		break;

	case 10:
		description = "Makalus Mountain is in front of you. There is a small tunnel where you can go to the next area.";
		door = 0;
		source = 3;
		destination = 9;
		direction = east;
		break;

	case 11:
		description = "Wow, there is a huge field with nothing important!";
		door = 0;
		source = 4;
		destination = 3;
		direction = north;
		break;

	case 12:
		description = "Trees, trees and more trees.";
		door = 0;
		source = 4;
		destination = 5;
		direction = south;
		break;

	case 13:
		description = "Trees, trees and more trees.";
		door = 0;
		source = 5;
		destination = 2;
		direction = west;
		break;

	case 14:
		description = "There are ruins all over the path.";
		door = 0;
		source = 5;
		destination = 4;
		direction = north;
		break;

	case 15:
		description = "There is a cliff with a warning signal.";
		door = 0;
		source = 7;
		destination = 1;
		direction = west;
		break;

	case 16:
		description = "There's a path that goes to the peak of the Mountain.";
		door = 0;
		source = 7;
		destination = 6;
		direction = north;
		break;

	case 17:
		description = "Dunedin Gates are in this way.";
		door = 2;
		source = 7;
		destination = 8;
		direction = south;
		break;

	case 18:
		description = "There's a path that goes to the peak of the Mountain.";
		door = 2;
		source = 8;
		destination = 7;
		direction = north;
		break;

	case 19:
		description = "Makalus Mountain is in front of you. There is a small tunnel where you can go to the next area.";
		door = 0;
		source = 9;
		destination = 3;
		direction = west;
		break;

	case 20:
		description = "There are stairs that go down somewhere.";
		door = 0;
		source = 10;
		destination = 11;
		direction = south;
		break;

	case 21:
		description = "The waterfalls do not let you see this way.";
		door = 0;
		source = 10;
		destination = 14;
		direction = east;
		break;

	case 22:
		description = "There are stairs that go up somewhere.";
		door = 0;
		source = 11;
		destination = 10;
		direction = north;
		break;

	case 23:
		description = "There is a long path sorrounded by lots of trees.";
		door = 0;
		source = 12;
		destination = 0;
		direction = west;
		break;

	case 24:
		description = "The sound of the water falling is louder.";
		door = 0;
		source = 12;
		destination = 13;
		direction = south;
		break;

	case 25:
		description = "Trees, trees and more trees.";
		door = 0;
		source = 12;
		destination = 15;
		direction = east;
		break;

	case 26:
		description = "Trees, trees and more trees.";
		door = 0;
		source = 13;
		destination = 12;
		direction = north;
		break;

	case 27:
		description = "There is a cliff where starts the waterfall and a rope hanging down.";
		door = 0;
		source = 13;
		destination = 14;
		direction = south;
		break;

	case 28:
		description = "There is a river.";
		door = 0;
		source = 14;
		destination = 8;
		direction = east;
		break;

	case 29:
		description = "The waterfalls do not let you see this way.";
		door = 0;
		source = 14;
		destination = 10;
		direction = west;
		break;

	case 30:
		description = "There is a rope hanging from the top of the waterfall.";
		door = 0;
		source = 14;
		destination = 13;
		direction = north;
		break;

	case 31:
		description = "Trees, trees and more trees.";
		door = 0;
		source = 15;
		destination = 2;
		direction = north;
		break;

	case 32:
		description = "Trees, trees and more trees.";
		door = 0;
		source = 15;
		destination = 12;
		direction = west;
		break;

	case 33:
		description = "Trees, trees and more trees.";
		door = 0;
		source = 15;
		destination = 15;
		direction = east;
		break;

	case 34:
		description = "Trees, trees and more trees.";
		door = 0;
		source = 15;
		destination = 15;
		direction = south;
		break;
	}
}