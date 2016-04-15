#ifndef ROOM_H
#define ROOM_H

#include "Base.h"

class Room : public Base
{
public:
	int id;
	String name;

public:
	void CreateRooms(const int num);
};

#endif