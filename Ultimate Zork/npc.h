#ifndef NPC_H
#define NPC_H

#include "Creature.h"

class npc : public Creature
{
public:
	npc(const char* name, const char* description, Room* creature_pos);
	virtual ~npc();
};

#endif