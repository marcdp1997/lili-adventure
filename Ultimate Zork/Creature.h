#ifndef CREATURE_H
#define CREATURE_H

#include "Entity.h"

enum state {WALK, COMBAT};

class Room;
class Player;

class Creature : public Entity
{
public:
	Room* curr_pos;
	uint coins;
	uint hp;
	uint damage;

public:
	Creature(const char* name, const char* description, Room* c_pos, uint c_hp, uint c_coins, uint c_damage);
	virtual ~Creature();

	virtual void Update(Vector<Entity*>& Entities, Player* p, uint i) {}
};

#endif