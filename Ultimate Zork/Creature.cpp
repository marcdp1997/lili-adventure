#include "Creature.h"
#include "Room.h"
#include "Path.h"
#include "Player.h"
#include "Item.h"

Creature::Creature(const char* name, const char* description, Room* c_pos, uint c_hp, uint c_coins, uint c_damage) : 
Entity(name, description), 
curr_pos(c_pos), hp(c_hp), coins(c_coins), damage(c_damage)
{}

Creature::~Creature()
{}

