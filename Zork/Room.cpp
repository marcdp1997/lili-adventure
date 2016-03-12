#include <stdio.h>
#include <string.h>
#include "Room.h"

void Room::CreateRooms(int num){

	switch (num){
	case 0:
		id = 0;
		strcpy_s(name, 20, "Crashed Airplane");
		strcpy_s(description, 200, "You are in an area with a completely destroyed plane.");
		south = 01;
		east = 012;

	}
}