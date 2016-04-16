#ifndef PLAYER_H
#define PLAYER_H

#define INV_CAPACITY 2

#include "Entity.h"
class Room;
class Item;

class Player : public Entity
{
public:
	Room* curr_pos;

	//Inventory ---
	Vector<Item*> bag;

public: 
	Player(const char* name, const char* description, Room* curr_pos);
	virtual ~Player();

	void Move(const String& command, const Vector<Entity*>& Entities);
	void LookPath(const String& command, const Vector<Entity*>& Entities);
	void Pick(const String& command, const Vector<Entity*>& Entities);
	void Drop(const String& command, const Vector<Entity*>& Entities);
	void Door(const enum Status& door, const Vector<Entity*>& Entities);
};

#endif