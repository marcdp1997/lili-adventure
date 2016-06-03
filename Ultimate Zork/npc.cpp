#include "Player.h"
#include "Path.h"
#include "Item.h"
#include "Room.h"
#include "npc.h"

npc::npc(const char* name, const char* description, Room* creature_pos) : Creature(name, description, NPC, creature_pos, 2, 20)
{
	type = NPC;
	inventory = nullptr;
}

npc::~npc()
{}