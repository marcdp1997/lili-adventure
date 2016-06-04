#ifndef NPC_H
#define NPC_H

#include "Creature.h"

class Npc : public Creature
{
public:
	Npc(const char* name, const char* description, Room* creature_pos);
	virtual ~Npc();
};

#endif