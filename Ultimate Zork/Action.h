#ifndef ACTION_H
#define ACTION_H

#include "World.h"
#include "String.h"

#define POS_PLAYER Island.player->curr_pos
#define LAST_ITEM Island.player->last_item

class Action
{
public:
	int stop;
private:
	String command;
public:
	void Tutorial(const World &Island);
	void Ask(World &Island);
private:
	void Help() const;
	void Move(World &Island, const enum coords &coord);
	void Look(World &Island, const enum coords &coord);
	void Pick(World &Island);
	void Drop(World &Island);
	void CheckDoor(World &Island, const int i);
};

#endif