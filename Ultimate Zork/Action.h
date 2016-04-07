#ifndef ACTION_H
#define ACTION_H

#include "World.h"
#include "String.h"

class Action{
public:
	int stop;
private:
	String command;

public:
	void Tutorial(World &Island);
	void Ask(World &Island);
private:
	void Help();
	void Move(World &Island);
	void Look(World &Island);
	void CheckDoor(World &Island, const int i);
	void Update(World &Island, const int i);
};

#endif