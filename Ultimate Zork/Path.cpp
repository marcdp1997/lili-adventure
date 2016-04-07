#include "Path.h"

void Path::CreatePaths(int num){

	switch (num){

	case 0:
		id = 0;
		description = "It seems to be water there...";
		door = 0;
		source = 0; // id of the curr room
		destination = 1; // id of the room we want to go
		break;

	case 1:
		id = 1;
		description = "There is a long path sorrounded by lots of trees.";
		door = 0;
		source = 0;
		destination = 12;
		break;

	case 2:
		id = 2;
		description = "There is smoke above the trees. Maybe something is burning?";
		door = 0;
		source = 1;
		destination = 0;
		break;

	case 3:
		id = 3;
		description = "Trees, trees and more trees.";
		door = 0;
		source = 1;
		destination = 2;
		break;

	case 4:
		id = 4;
		description = "Wow, there is a huge field with nothing important!";
		door = 0;
		source = 1;
		destination = 3;
		break;

	case 5:
		id = 5;
		description = "It seems to be water there...";
		door = 0;
		source = 2;
		destination = 1;
		break;

	case 6:
		id = 6;
		description = "Trees, trees and more trees.";
		door = 0;
		source = 2;
		destination = 5;
		break;

	case 7:
		id = 7;
		description = "Trees, trees and more trees.";
		door = 0;
		source = 2;
		destination = 15;
		break;

	case 8:
		id = 8;
		description = "It seems to be water there...";
		door = 0;
		source = 3;
		destination = 1;
		break;

	case 9:
		id = 9;
		description = "There are ruins all over the path.";
		door = 0;
		source = 3;
		destination = 4;
		break;

	case 10:
		id = 10;
		description = "Makalus Mountain is in front of you. There is a small tunnel where you can go to the next area.";
		door = 0;
		source = 3;
		destination = 9;
		break;

	case 11:
		id = 11;
		description = "Wow, there is a huge field with nothing important!";
		door = 0;
		source = 4;
		destination = 3;
		break;

	case 12:
		id = 12;
		description = "Trees, trees and more trees.";
		door = 0;
		source = 4;
		destination = 5;
		break;

	case 13:
		id = 13;
		description = "Trees, trees and more trees.";
		door = 0;
		source = 5;
		destination = 2;
		break;

	case 14:
		id = 14;
		description = "There are ruins all over the path.";
		door = 0;
		source = 5;
		destination = 4;
		break;

	case 15:
		id = 15;
		description = "There is a cliff with a warning signal.";
		door = 0;
		source = 7;
		destination = 1;
		break;

	case 16:
		id = 16;
		description = "There's a path that goes to the peak of the Mountain.";
		door = 0;
		source = 7;
		destination = 6;
		break;

	case 17:
		id = 17;
		description = "Dunedin Gates are in this way.";
		door = 2;
		source = 7;
		destination = 8;
		break;

	case 18:
		id = 18;
		description = "There's a path that goes to the peak of the Mountain.";
		door = 2;
		source = 8;
		destination = 7;
		break;

	case 19:
		id = 19;
		description = "Makalus Mountain is in front of you. There is a small tunnel where you can go to the next area.";
		door = 0;
		source = 9;
		destination = 3;
		break;

	case 20:
		id = 20;
		description = "There are stairs that go down somewhere.";
		door = 0;
		source = 10;
		destination = 11;
		break;

	case 21:
		id = 21;
		description = "The waterfalls do not let you see this way.";
		door = 0;
		source = 10;
		destination = 14;
		break;

	case 22:
		id = 22;
		description = "There are stairs that go up somewhere.";
		door = 0;
		source = 11;
		destination = 10;
		break;

	case 23:
		id = 23;
		description = "There is a long path sorrounded by lots of trees.";
		door = 0;
		source = 12;
		destination = 0;
		break;

	case 24:
		id = 24;
		description = "The sound of the water falling is louder.";
		door = 0;
		source = 12;
		destination = 13;
		break;

	case 25:
		id = 25;
		description = "Trees, trees and more trees.";
		door = 0;
		source = 12;
		destination = 15;
		break;

	case 26:
		id = 26;
		description = "Trees, trees and more trees.";
		door = 0;
		source = 13;
		destination = 12;
		break;

	case 27:
		id = 27;
		description = "There is a cliff where starts the waterfall and a rope hanging down.";
		door = 0;
		source = 13;
		destination = 14;
		break;

	case 28:
		id = 28;
		description = "There is a river.";
		door = 0;
		source = 14;
		destination = 8;
		break;

	case 29:
		id = 29;
		description = "The waterfalls do not let you see this way.";
		door = 0;
		source = 14;
		destination = 10;
		break;

	case 30:
		id = 30;
		description = "There is a rope hanging from the top of the waterfall.";
		door = 0;
		source = 14;
		destination = 13;
		break;

	case 31:
		id = 31;
		description = "Trees, trees and more trees.";
		door = 0;
		source = 15;
		destination = 2;
		break;

	case 32:
		id = 32;
		description = "Trees, trees and more trees.";
		door = 0;
		source = 15;
		destination = 12;
		break;

	case 33:
		id = 33;
		description = "Trees, trees and more trees.";
		door = 0;
		source = 15;
		destination = 15;
		break;
	}
}