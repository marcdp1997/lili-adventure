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

void Merchant::LookItems()
{
	if (inventory->num_elements == 0) printf("You already buy all the items.\n\n");
	else
	{
		printf("The merch has these items available: ");
		for (int i = 0; i < inventory->num_elements; i++)
			printf("\n   -%s (%s) -> %i coins", inventory->buffer[i]->name.string, inventory->buffer[i]->description.string, inventory->buffer[i]->coins);

		printf("\n\n");
	}
}

bool Merchant::BuySell(const Vector <String>& tokens, Player* p)
{
	if (tokens.buffer[0] == "buy")
	{
		for (int i = 0; i < inventory->num_elements; i++)
		{
			if (tokens.buffer[1] == inventory->buffer[i]->name)
			{
				if (tokens.buffer[1] == inventory->buffer[i]->name && p->coins < inventory->buffer[i]->coins) printf("You don't have enough coins. You need %i more.\n\n", inventory->buffer[i]->coins - p->coins);
				else if (p->inventory->num_elements == INV_CAPACITY && p->coins >= inventory->buffer[i]->coins) printf("Your inventory is full.\n\n");
				else
				{
					p->coins -= inventory->buffer[i]->coins;
					inventory->buffer[i]->pick = true;
					p->inventory->pushback(inventory->buffer[i]);
					printf("You added %s in your inventory for %i coins.\n\n", inventory->buffer[i]->name.string, inventory->buffer[i]->coins);
					inventory->pop(i);
				}
				return true;
			}
		}
	}
	else
	{
		for (int i = 0; i < p->inventory->num_elements; i++)
		{
			if (tokens.buffer[1] == p->inventory->buffer[i]->name)
			{
					p->coins += p->inventory->buffer[i]->coins;
					p->inventory->buffer[i]->pick = false;
					p->inventory->buffer[i]->pick2 = false;
					inventory->pushback(p->inventory->buffer[i]);
					printf("You sold %s to the merch for %i coins.\n\n", p->inventory->buffer[i]->name.string, p->inventory->buffer[i]->coins);
					p->inventory->buffer[i]->coins *= 2;
					p->inventory->pop(i);
					return true;
			}
		}
	}
	return false;
}