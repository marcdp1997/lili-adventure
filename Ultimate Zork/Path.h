#ifndef PATH_H
#define PATH_H

#include "Entity.h"

class Room;
enum Status { NO_DOOR, OPEN, CLOSE };

class Path : public Entity
{
public:
	Room* source;
	Room* destination;
	String direction;
	Status door;

public:
	Path(const char* name, const char* description, Room* source, Room* destination, const char* direction, Status door);
	virtual ~Path();
};

#endif