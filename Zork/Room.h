#ifndef ROOM_H
#define ROOM_H

class Room{

public:
	int id;
	char name[50];
	char description[200];
	int north;
	int south;
	int west;
	int east;

public:
	void CreateRooms(int num);
};

#endif