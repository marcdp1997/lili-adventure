#ifndef WORLD_H
#define WORLD_H

#include "Entity.h"
class Player;

class World
{
public:
	int stop;
	String command;
	Vector<String> tokens;
	Vector<Entity*> entities;
	Player* player;

public:
	World();
	virtual ~World();
	void Ask();
	void Help() const;
};

#endif