#include "Player.h"
#include "Path.h"
#include "Item.h"
#include "Room.h"
#include "Npc.h"

Npc::Npc(const char* name, const char* description, Room* c_pos) : Creature(name, description, c_pos, 4, 20, 2)
{
	type = NPC;
	inventory = nullptr;
	st_step = WALK;
}

Npc::~Npc()
{}