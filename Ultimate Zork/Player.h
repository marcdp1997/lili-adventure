#ifndef PLAYER_H
#define PLAYER_H

#define INV_CAPACITY 1

#include "Entity.h"
class Room;
class Item;

class Player : public Entity
{
public:
	Room* curr_pos;

	//Inventory ---
	uint capacity = INV_CAPACITY;
	Vector<Item*> inventory(uint capacity);
	int last_item = 0;

public: 
	Player(const char* name, const char* description, Room* curr_pos);
	virtual ~Player();

	void Player::Move(String& command, const Vector<Entity*>& Entities);
	void Player::LookPath(String& command, const Vector<Entity*>& Entities);
	void Player::Pick(String& command, const Vector<Entity*>& Entities);
};

#endif