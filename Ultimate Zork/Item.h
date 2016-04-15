#ifndef ITEM_H
#define ITEM_H

#include "Base.h"

class Item : public Base
{
public:
	String name;
	int room; // Which room.id is located the item
	bool picked; // 1 == true, 0 == false
public:
	void CreateItems(const int num);
};

#endif