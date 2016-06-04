#include <stdlib.h>
#include <time.h>  
#include "Creature.h"
#include "Room.h"
#include "Path.h"

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

void Creature::Update(const Vector<Entity*>& Entities)
{
	switch (st_step)
	{
	case IDLE:
		Move(Entities);
		break;
	case ATTACK:
		break;
	}
}

void Creature::Move(const Vector<Entity*>& Entities)
{
	srand(time(NULL));

	for (int j = 0; j < Entities.num_elements; j++)
	{
		Entity* aux = Entities[j];

		if (aux->type == PATH)
		{
			Path* p = (Path*)aux;
			int decision = rand() % 2;

			// The enemy is in each room a different period of time because of the condition.
			if (p->source == curr_pos && decision == 1)
				curr_pos = p->destination;
		}
	}
}