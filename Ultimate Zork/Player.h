#ifndef PLAYER_H
#define PLAYER_H

#define INV_CAPACITY 3

#include "Entity.h"
class Room;

class Player : public Entity
{
public:
	Room* curr_pos;
	int last_item = 0;
public: 
	Player(const char* name, const char* description, Room* curr_pos);
	virtual ~Player();

	void Player::Move(String& command, const Vector<Entity*>& Entities);
};

#endif