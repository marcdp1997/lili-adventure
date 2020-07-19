#include "Player.h"
#include "Path.h"
#include "Item.h"
#include "Room.h"
#include "Enemy.h"

#include <stdlib.h>
#include <time.h>  

Enemy::Enemy(const char* name, const char* description, Room* c_pos) : Creature(name, description, c_pos, 5, 20, 3)
{
	type = ENEMY;
	inventory = nullptr;
	st_step = WALK;
}

Enemy::~Enemy()
{}

// We will enter this method as goblin so we need the player stats to do the combat.
void Enemy::Update(Vector<Entity*>& Entities, Player* p, uint i)
{
	if (p->curr_pos == curr_pos && st_step == WALK) st_step = COMBAT;

	switch (st_step)
	{
	case WALK:
		Move(Entities);
		break;
	case COMBAT:
		Combat(Entities, p, i);
	}
}

void Enemy::Move(const Vector<Entity*>& Entities)
{
	srand(time(NULL));

	for (int j = 0; j < Entities.num_elements; j++)
	{
		Entity* aux = Entities[j];

		if (aux->type == PATH)
		{
			Path* p = (Path*)aux;
			int decision = rand() % 20;

			// The enemy is in each room a different period of time because of the condition.
			if (p->source == curr_pos && decision == 1 && p->destination->name != "Crashed Airplane" && p->destination->name != "Dunedin Gates")
				curr_pos = p->destination;
		}
	}
}

void Enemy::Combat(Vector<Entity*>& Entities, Player* p, uint i)
{
	printf("%s has appeared in the same area than you.\nYou must fight with him to move!\n", name.string);

	while (p->hp > 0 && hp > 0)
	{
		if (p->hp > 0) Player_Attack(p, 1);
		if (hp > 0) Goblin_Attack(p, 1);
	}

	if (p->hp == 0 && hp > 0) printf("You are dead!\nGAME OVER\n\n");
	if (hp == 0 && p->hp > 0)
	{
		if (p->clothes != nullptr && p->clothes->name == "amulet") printf("You have defeated %s. +%i coins!\n\n", name.string, coins * 2);
		else printf("You have defeated %s. +%i coins!\n\n", name.string, coins);

		Entities.pop(i);
	}
}

void Enemy::Player_Attack(Player* p, float delay)
{
	clock_t end_time = delay * 1000 + clock(); // 1st num == seconds of delay
	while (clock() < end_time){}

	if (hp > p->damage) hp -= p->damage;
	else
	{
		hp = 0;
		if (p->clothes != nullptr && p->clothes->name == "amulet") p->coins += (coins * 2);
		else p->coins += coins;
	}

	if (p->weapon != nullptr) printf("You attack %s for %i with your %s! %s has %i left.\n", name.string, p->damage, p->weapon->name.string, name.string, hp);
	else printf("You punch %s for %i! %s has %i left.\n", name.string, p->damage, name.string, hp);

}

void Enemy::Goblin_Attack(Player* p, float delay)
{
	clock_t end_time = delay * 1000 + clock();
	while (clock() < end_time){}

	// Set damage depending on the item equipped
	if (p->clothes != nullptr && p->clothes->name == "hood") damage = 0;
	else if (p->shield != nullptr && p->shield->name == "wshield") damage = 2;
	else if (p->shield != nullptr && p->shield->name == "mshield") damage = 1;

	// Attack
	if (p->hp > damage) p->hp -= damage;
	else p->hp = 0;

	// Different printfs
	if (p->clothes != nullptr && p->clothes->name == "hood") printf("You are invisible with this hood. %s miss.\n", name.string);
	else if (p->shield != nullptr && p->shield->name == "wshield") printf("The wood shield will reduce the damage received.\n%s attack you for %i! You have %i HP left.\n", name.string, damage, p->hp);
	else if (p->shield != nullptr && p->shield->name == "mshield") printf("The metal shield will reduce a lot the damage received.\n%s attack you for %i! You have %i HP left.\n", name.string, damage, p->hp);
	else printf("%s attack you for %i! You have %i HP left.\n", name.string, damage, p->hp);
}