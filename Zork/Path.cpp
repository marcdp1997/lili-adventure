#include <stdio.h>
#include <string.h>
#include "Path.h"

void Path::CreatePaths(int num){

	switch (num){

	case 0:
		id = 0;
		strcpy_s(description, 200, "It seems to be water there...\n");
		open = 1;
		source = 0;
		destination = 1;
		break;

	case 1:
		id = 1;
		strcpy_s(description, 200, "There is a long path sorrounded by lots of trees.\n");
		open = 1; // 0 == false, true == 1;
		source = 0;
		destination = 12;
		break;

	case 2:
		id = 2;
		strcpy_s(description, 200, "There is smoke above the trees. Maybe something is burning?\n");
		open = 1;
		source = 1;
		destination = 0;
		break;

	case 3:
		id = 3;
		strcpy_s(description, 200, "Trees, trees and more trees.\n");
		open = 1;
		source = 1;
		destination = 2;
		break;

	case 4:
		id = 4;
		strcpy_s(description, 200, "Wow, there is a huge field with nothing important!");
		open = 1;
		source = 1;
		destination = 3;
		break;

	case 5:
		id = 5;
		strcpy_s(description, 200, "It seems to be water there...\n");
		open = 1;
		source = 2;
		destination = 1;
		break;

	case 6:
		id = 6;
		strcpy_s(description, 200, "Trees, trees and more trees.\n");
		open = 1;
		source = 2;
		destination = 5;
		break;

	case 7:
		id = 7;
		strcpy_s(description, 200, "Trees, trees and more trees.\n");
		open = 1;
		source = 2;
		destination = 15;
		break;

	case 8:
		id = 8;
		strcpy_s(description, 200, "It seems to be water there...\n");
		open = 1;
		source = 3;
		destination = 1;
		break;

	case 9:
		id = 9;
		strcpy_s(description, 200, "There are ruins all over the path.\n");
		open = 1;
		source = 3;
		destination = 4;
		break;

	case 10:
		id = 10;
		strcpy_s(description, 200, "Makalus Mountain is in front of you. There is a small tunnel where you can go to the next area.\n");
		open = 1;
		source = 3;
		destination = 9;
		break;

	case 11:
		id = 11;
		strcpy_s(description, 200, "Wow, there is a huge field with nothing important!");
		open = 1;
		source = 4;
		destination = 3;
		break;

	case 12:
		id = 12;
		strcpy_s(description, 200, "Trees, trees and more trees.\n");
		open = 1;
		source = 4;
		destination = 5;
		break;

	case 13:
		id = 13;
		strcpy_s(description, 200, "Trees, trees and more trees.\n");
		open = 1;
		source = 5;
		destination = 2;
		break;

	case 14:
		id = 14;
		strcpy_s(description, 200, "There are ruins all over the path.\n");
		open = 1;
		source = 5;
		destination = 4;
		break;

	case 15:
		id = 15;
		strcpy_s(description, 200, "There is a cliff with a warning signal.\n");
		open = 1;
		source = 7;
		destination = 2;
		break;

	case 16:
		id = 16;
		strcpy_s(description, 200, "There's a path that goes to the peak of the Mountain\n");
		open = 1;
		source = 7;
		destination = 6;
		break;

	case 17:
		id = 17;
		strcpy_s(description, 200, "Dunedin Gate is in this way.\n");
		open = 1;
		source = 7;
		destination = 8;
		break;

	case 18:
		id = 18;
		strcpy_s(description, 200, "There's a path that goes to the peak of the Mountain.\n");
		open = 0;
		source = 8;
		destination = 7;
		break;

	case 19:
		id = 19;
		strcpy_s(description, 200, "Makalus Mountain is in front of you. There is a small tunnel where you can go to the next area.\n");
		open = 1;
		source = 9;
		destination = 3;
		break;

	case 20:
		id = 20;
		strcpy_s(description, 200, "There are stairs that go down somewhere.\n");
		open = 1;
		source = 10;
		destination = 11;
		break;

	case 21:
		id = 21;
		strcpy_s(description, 200, "The waterfalls do not let you see this way.\n");
		open = 1;
		source = 10;
		destination = 14;
		break;

	case 22:
		id = 22;
		strcpy_s(description, 200, "There are stairs that go up somewhere.\n");
		open = 1;
		source = 11;
		destination = 10;
		break;

	case 23:
		id = 23;
		strcpy_s(description, 200, "There is a long path sorrounded by lots of trees.");
		open = 1;
		source = 12;
		destination = 0;
		break;

	case 24:
		id = 24;
		strcpy_s(description, 200, "The sound of the water falling is louder.\n");
		open = 1;
		source = 12;
		destination = 13;
		break;

	case 25:
		id = 25;
		strcpy_s(description, 200, "Trees, trees and more trees.\n");
		open = 1;
		source = 12;
		destination = 15;
		break;

	case 26:
		id = 26;
		strcpy_s(description, 200, "Trees, trees and more trees.\n");
		open = 1;
		source = 13;
		destination = 12;
		break;

	case 27:
		id = 27;
		strcpy_s(description, 200, "There is a cliff where starts the waterfall and a rope hanging down.\n");
		open = 1;
		source = 13;
		destination = 14;
		break;
/*
	case 28:
		id = 28;
		strcpy_s(description, 200, "");
		open = 1;
		source = 14;
		destination = 1;
		break;
*/
	case 29:
		id = 29;
		strcpy_s(description, 200, "There is a river.\n");
		open = 1;
		source = 14;
		destination = 8;
		break;

	case 30:
		id = 30;
		strcpy_s(description, 200, "The waterfalls do not let you see this way.\n ");
		open = 1;
		source = 14;
		destination = 10;
		break;

	case 31:
		id = 31;
		strcpy_s(description, 200, "There is a rope hanging from the top of the waterfall.\n");
		open = 1;
		source = 14;
		destination = 13;
		break;

	case 32:
		id = 32;
		strcpy_s(description, 200, "Trees, trees and more trees.\n");
		open = 1;
		source = 15;
		destination = 2;
		break;

	case 33:
		id = 33;
		strcpy_s(description, 200, "Trees, trees and more trees.\n");
		open = 1;
		source = 15;
		destination = 12;
		break;

	case 34:
		id = 34;
		strcpy_s(description, 200, "Trees, trees and more trees.\n");
		open = 1;
		source = 15;
		destination = 15;
		break;
	}
}