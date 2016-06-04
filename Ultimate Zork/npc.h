#ifndef NPC_H
#define NPC_H

#include "Creature.h"

class Npc : public Creature
{
public:
	state st_step;

public:
	Npc(const char* name, const char* description, Room* creature_pos);
	virtual ~Npc();

	void Update(Vector<Entity*>& Entities, Player* p, uint i);
	void Move(const Vector<Entity*>& Entities);
	void Combat(Vector<Entity*>& Entities, Player* p, uint i);
	void Player_Attack(Player* p);
	void Goblin_Attack(Player* p);
};

#endif