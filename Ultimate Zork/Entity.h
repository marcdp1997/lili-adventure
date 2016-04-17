#ifndef BASE_H
#define BASE_H

#include <stdio.h>
#include "String.h"
#include "Vector.h"

class Item;

enum Entity_type { PLAYER, ROOM, PATH, ITEM, ENTITY };

class Entity
{
public:
	String name;
	String description;
	Entity_type type;

	Vector<Item*>* inventory;

public:
	Entity::Entity(const char* name, const char* description);
	virtual ~Entity();
};

#endif