#ifndef CREATURE_H
#define CREATURE_H

#include "Entity.h"

class Room;

class Creature : public Entity
{
public:
	Room* curr_pos;
	uint coins;
	uint hp;

public:
	Creature(const char* name, const char* description, Room* c_pos, uint c_hp, uint c_coins);
	virtual ~Creature();
};

#endif