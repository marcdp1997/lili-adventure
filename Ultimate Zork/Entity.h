#ifndef BASE_H
#define BASE_H

#include <stdio.h>
#include "String.h"
#include "Vector.h"

enum Entity_type { PLAYER, ROOM, PATH, ITEM };

class Entity
{
public:
	String name;
	String description;
	Entity_type type;
public:
	Entity(const char* name, const char* description, Entity_type type);
	~Entity();
};

#endif