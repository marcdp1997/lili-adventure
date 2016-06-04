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
	state st_step;
	uint coins;
	uint hp;
	uint damage;

public:
	Creature(const char* name, const char* description, Room* c_pos, uint c_hp, uint c_coins, uint c_damage);
	virtual ~Creature();

	void Update(const Vector<Entity*>& Entities, Player* p);
	void Move(const Vector<Entity*>& Entities);
	void Combat(Player* p);
	void Player_Attack(Player* p);
	void Goblin_Attack(Player* p);
};

#endif