#ifndef WORLD_H
#define WORLD_H

#include "Entity.h"

class Player;
class Merchant;

class World
{
public:
	int stop;
	String command;
	Vector<String> tokens;
	Vector<Entity*> entities;
	Player* player;
	Merchant* merch;

public:
	World();
	virtual ~World();
	void Ask();
	void Help() const;
	void Tutorial() const;
	void Call_Update();
};

#endif