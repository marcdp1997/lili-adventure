#ifndef CREATURE_H
#define CREATURE_H

#include "Entity.h"
#define MAX_NPC 4

enum state {IDLE, ATTACK};

class Room;

class Creature : public Entity
{
public:
	Room* curr_pos;
	state st_step;
	uint coins;
	uint hp;

public:
	Creature(const char* name, const char* description, Room* c_pos, uint c_hp, uint c_coins);
	virtual ~Creature();

	void Update(const Vector<Entity*>& Entities);
	void Move(const Vector<Entity*>& Entities);
};

#endif