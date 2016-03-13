#include <stdio.h>
#include <string.h>
#include "Room.h"

void Room::CreateRooms(int num){

	switch (num){

	case 0:
		id = 0;
		strcpy_s(name, 50, "Crashed Airplane. ");
		strcpy_s(description, 200, "You are in an area with a completely destroyed plane.\n");
		north = -1; // -1 = there is no path to connect with
		south = 0;
		east = 1;
		west = -1;
		break;

	case 1:
		id = 1;
		strcpy_s(name, 50, "Lake. ");
		strcpy_s(description, 200, "This lake seems to be created here because a river ends in the west part. The current is strong.\n");
		north = 2;
		south = 3;
		east = 4;
		west = -1;
		break;

	case 2:
		id = 2;
		strcpy_s(name, 50, "Jungle. ");
		strcpy_s(description, 200, "Trees and two small paths. There is a river going from south to west but you can't go there.\n");
		north = 5;
		south = 7;
		east = 6;
		west = -1;
		break;

	case 3:
		id = 3;
		strcpy_s(name, 50, "Middle of Nowhere. ");
		strcpy_s(description, 200, "You are in a huge field. To the east you can see far away a big mountain.\n");
		north = -1;
		south = 9;
		east = 10;
		west = 8;
		break;

	case 4:
		id = 4;
		strcpy_s(name, 50, "Mayan Temple. ");
		strcpy_s(description, 200, "There is a deteriorated Mayan temple but it is still looking good.\n");
		north = 11;
		south = 12;
		east = -1;
		west = -1;
		break;

	case 5:
		id = 5;
		strcpy_s(name, 50, "Jungle. ");
		strcpy_s(description, 200, "Trees and two small paths. There is a river to the south but you can't go there.\n");
		north = 14;
		south = -1;
		east = -1;
		west = 13;
		break;

	case 6:
		id = 6;
		strcpy_s(name, 50, "Makalu's Peak. ");
		strcpy_s(description, 200, "You arrived at the end of the map, congratulations!\n");
		north = -1;
		south = -1;
		east = -1;
		west = -1;
		break;

	case 7:
		id = 7;
		strcpy_s(name, 50, "Campsite. ");
		strcpy_s(description, 200, "Here you can rest and think if you are prepared to go further. There are two ways: jumping to the cliff (yes, you can!) or go to the peak!\n");
		north = 16;
		south = 17;
		east = -1;
		west = 15;
		break;

	case 8:
		id = 7;
		strcpy_s(name, 50, "Dunedin Gates. ");
		strcpy_s(description, 200, "You finally arrived to the path that would guide you to the peak. The river let you here and you can't go back. The current is so strong. Open the gates.\n");
		north = 18;
		south = -1;
		east = -1;
		west = -1;
		break;

	case 9:
		id = 9;
		strcpy_s(name, 50, "Lookout. ");
		strcpy_s(description, 200, "Such a beautiful views! You can see practically all the island and, in the east, an amazing waterfalls.\n");
		north = -1;
		south = -1;
		east = -1;
		west = 19;
		break;

	case 10:
		id = 10;
		strcpy_s(name, 50, "Cave. ");
		strcpy_s(description, 200, "You are in a cave located behind the waterfall. There are prehistoric paintings in the walls. \n");
		north = -1;
		south = 20;
		east = 21;
		west = -1;
		break;

	case 11:
		id = 11;
		strcpy_s(name, 50, "Hidden chamber. ");
		strcpy_s(description, 200, "Small and cute chamber with nothing important in this moment.\n");
		north = 22;
		south = -1;
		east = -1;
		west = -1;
		break;

	case 12:
		id = 12;
		strcpy_s(name, 50, "Jungle. ");
		strcpy_s(description, 200, "Trees.\n");
		north = -1;
		south = 24;
		east = 25;
		west = 23;
		break;

	case 13:
		id = 12;
		strcpy_s(name, 50, "Waterfalls. ");
		strcpy_s(description, 200, "A majestic waterfalls are in the south of this area. They aren't so high.\n");
		north = 26;
		south = 27;
		east = -1;
		west = -1;
		break;

	case 14:
		id = 12;
		strcpy_s(name, 50, "Bottom of the waterfalls. ");
		strcpy_s(description, 200, "The water creates a river to the east part. It could end up in an interesting place...\n");
		north = 31;
		south = -1;
		east = 29;
		west = 30;
		break;

	case 15:
		id = 15;
		strcpy_s(name, 50, "Jungle. ");
		strcpy_s(description, 200, "The water creates a river to the east part. It could end up in an interesting place...\n");
		north = 32;
		south = 34;
		east = 34;
		west = 33;
		break;
	}
}