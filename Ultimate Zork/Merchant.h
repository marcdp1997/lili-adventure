#ifndef MERCHANT_H
#define MERCHANT_H

#include "Creature.h"

#define ITEMS_SHOP 10

class Merchant : public Creature
{
public:
	Merchant(const char* name, const char* description, Room* creature_pos);
	virtual ~Merchant();

	void Buy();
};

#endif