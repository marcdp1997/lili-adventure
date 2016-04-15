#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"

class Room : public Entity
{
public:
	Room(const char* title, const char* description);
	virtual ~Room();
};

#endif