#include "Room.h"

void Room::CreateRooms(const int num)
{
	switch (num)
	{
	case 0:
		id = 0;
		name = "Crashed Airplane";
		description = "Your plane had landed here. First area of your adventure";
		break;

	case 1:
		id = 1;
		name = "Lake";
		description = "Big lake with some fish.\nA river ends with a strong current in the west part";
		break;

	case 2:
		id = 2;
		name = "Jungle";
		description = "Trees and two small paths.\nBehind those trees there is a river going from south to west, but you can't go there";
		break;

	case 3:
		id = 3;
		name = "Middle of Nowhere";
		description = "You are in a huge field.\nTo the east you can see a big mountain";
		break;

	case 4:
		id = 4;
		name = "Mayan Temple.";
		description = "There is a deteriorated Mayan temple but it is still looking good";
		break;

	case 5:
		id = 5;
		name = "Jungle";
		description = "Trees and two small paths.\nThere is a river to the south behind those trees, but you can't go there.\nYou can see a mountain from this area";
		break;

	case 6:
		id = 6;
		name = "Makalu's Peak";
		description = "You arrived at the end of the map, congratulations!\nA helicopter picked you up to take you home";
		break;

	case 7:
		id = 7;
		name = "Campsite";
		description = "Here you can rest and get warmed";
		break;

	case 8:
		id = 7;
		name = "Dunedin Gates";
		description = "This is the path that would guide you to the peak.\nThe river lets you here and you can't go back. The current is strong.\nA huge gates are in the north";
		break;

	case 9:
		id = 9;
		name = "Lookout";
		description = "Such a beautiful views! You can see practically all the island and, in the east, an amazing waterfalls";
		break;

	case 10:
		id = 10;
		name = "Cave";
		description = "You are in a cave located behind the waterfall. There are prehistoric paintings in the walls";
		break;

	case 11:
		id = 11;
		name = "Hidden chamber";
		description = "Small and cute chamber with nothing important";
		break;

	case 12:
		id = 12;
		name = "Jungle";
		description = "Trees";
		break;

	case 13:
		id = 12;
		name = "Waterfalls";
		description = "A majestic waterfalls are in the south of this area. They aren't so high to jump from";
		break;

	case 14:
		id = 12;
		name = "Bottom of the waterfalls";
		description = "There are lots of corpses floating.\nThe water creates a river to the east part.\nIt could end up in an interesting place";
		break;

	case 15:
		id = 15;
		name = "Jungle";
		description = "Trees";
		break;
	}
}