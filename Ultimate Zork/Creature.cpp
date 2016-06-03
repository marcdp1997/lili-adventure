#include "Creature.h"
#include "Room.h"

Creature::Creature(const char* name, const char* description, Room* c_pos, uint c_hp, uint c_coins) : 
Entity(name, description), 
curr_pos(c_pos), hp(c_hp), coins(c_coins)
{
	curr_pos = c_pos;
	hp = c_hp;
	coins = c_coins;
}

Creature::~Creature()
{}