#ifndef WORLD_H
#define WORLD_H

#include "Entity.h"
class Player;

class World
{
public:
	String command;
	Player* player;
	Vector<Entity*> Entities;

public:
	World();
	virtual ~World();
	void Ask();
};

#endif