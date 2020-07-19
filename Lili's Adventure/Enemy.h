#ifndef ENEMY_H
#define ENEMY_H

#include "Creature.h"

class Enemy : public Creature
{
public:
	state st_step;

public:
	Enemy(const char* name, const char* description, Room* creature_pos);
	virtual ~Enemy();

	void Update(Vector<Entity*>& Entities, Player* p, uint i);

private:
	void Move(const Vector<Entity*>& Entities);
	void Combat(Vector<Entity*>& Entities, Player* p, uint i);

	void Player_Attack(Player* p, float delay);
	void Goblin_Attack(Player* p, float delay);
};

#endif