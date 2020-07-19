#ifndef WORLD_H
#define WORLD_H

#include <time.h>  
#include <stdlib.h>
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
	void CallDad();
	void Tutorial();
	void CallUpdate();
	void SlowPrint(const char* message, uint milis_per_char = 35);
};

#endif