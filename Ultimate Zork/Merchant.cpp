#include "Player.h"
#include "Path.h"
#include "Item.h"
#include "Room.h"
#include "Merchant.h"

Merchant::Merchant(const char* name, const char* description, Room* c_pos) : Creature(name, description, c_pos, 0, 0, 0)
{
	type = MERCH;
	inventory = new Vector<Item*>(ITEMS_SHOP);
}

Merchant::~Merchant()
{}

void Merchant::Buy()
{
	if (inventory->num_elements == 0) printf("You already buy all the items.\n\n");
	else
	{
		printf("The merch has these items available: ");
		for (int i = 0; i < inventory->num_elements; i++)
			printf("\n   -%s (%s)", inventory->buffer[i]->name.string, inventory->buffer[i]->description.string);

		printf("\n\n");
	}
}