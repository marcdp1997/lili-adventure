#include "Player.h"

Player::Player()
{
	inventory = new Item[INV_CAPACITY];
	curr_pos = 0;
	last_item = 0;
}

Player::~Player()
{
	delete[] inventory;
}