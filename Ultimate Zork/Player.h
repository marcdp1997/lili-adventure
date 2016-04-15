#ifndef PLAYER_H
#define PLAYER_H

#define INV_CAPACITY 3

#include "Item.h"

class Player
{
public:
	int curr_pos;
	Item* inventory;
	int last_item;
public: 
	Player();
	virtual ~Player();
};

#endif