#ifndef BASE_H
#define BASE_H

#include "String.h"
#include "Vector.h"

enum Entity_type
{ 
	PLAYER,
	ROOM,
	PATH,
	ITEM 
};

class Entity
{
public:
	String name;
	String description;
	Vector<Entity*> entities;
};

#endif