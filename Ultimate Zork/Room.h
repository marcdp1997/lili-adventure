#ifndef ROOM_H
#define ROOM_H

#include "String.h"

class Room{
public:
	int id;
	String name;
	String description;
	int north, south, west, east;

public:
	void CreateRooms(const int num);
};

#endif