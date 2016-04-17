#include "Player.h"
#include "Path.h"
#include "Item.h"
#include "Room.h"

Player::Player(const char* name, const char* description, Room* room) :
Entity(name, description, PLAYER),
curr_pos(room)
{
	Vector<Item*> inventory(INV_CAPACITY);
	equip_item = nullptr;
}

Player::~Player()
{}

void Player::Move(const Vector <String>& tokens, const Vector<Entity*>& Entities)
{
	for (int i = 0; i < Entities.num_elements; i++)
	{
		Entity* aux = Entities[i];

		if (aux->type == PATH)
		{
			Path* p = (Path*)aux;
			
			if ((curr_pos == p->source) && (tokens.buffer[1] == p->direction))
			{
				if (p->door == CLOSE) printf("The gates are closed. Open them to move forward.\n\n");
				if (p->door == OPEN) printf("The gates are open. You can close them if you want.\n\n");
				if ((p->door == NO_DOOR) || (p->door == OPEN)) Update(p);
				break;
			}
		}
		else if (i == Entities.num_elements - 1) printf("You can't go there.\n\n");
	}
}

void Player::LookPath(const Vector <String>& tokens, const Vector<Entity*>& Entities)
{
	for (int i = 0; i < Entities.num_elements; i++)
	{
		Entity* aux = Entities[i];

		if (aux->type == PATH)
		{
			Path* p = (Path*)aux;

			if ((curr_pos == p->source) && (tokens.buffer[1] == p->direction))
			{
				printf("%s. %s.\n\n", p->name.string, p->description.string);
				break;
			}
		}
		else if (i == Entities.num_elements - 1) printf("There isn't a path to look at.\n\n");
	}
}

void Player::Pick(const Vector <String>& tokens, const Vector<Entity*>& Entities)
{
	for (int i = 0; i < Entities.num_elements; i++)
	{
		Entity* aux = Entities[i];

		if (aux->type == ITEM)
		{
			Item* i = (Item*)aux;

			if ((i->pick == 0) && (i->name == tokens.buffer[1]) && (i->location == curr_pos))
			{
				if (inventory.num_elements < INV_CAPACITY)
				{
					inventory.pushback(i);
					printf("You add %s in your inventory.\n\n", tokens.buffer[1]);
					i->pick = 1;

				}
				else printf("Your inventory is full.\n\n");
				break;
			}
			else if ((i->pick == 1) && (i->name == tokens.buffer[1]) && (i->location == curr_pos))
			{
				printf("You added this item before.\n\n");
				break;
			}
		}
		else if (i == Entities.num_elements - 1) printf("No item found.\n\n");
	}
}

void Player::Drop(const Vector <String>& tokens, const Vector<Entity*>& Entities)
{
	for (int i = 0; i < inventory.num_elements; i++)
	{
		if ((tokens.buffer[1] == inventory.buffer[i]->name) && (inventory.buffer[i]->pick == 1))
		{
			inventory.buffer[i]->pick = 0;
			inventory.buffer[i]->location = curr_pos;
			inventory.pop(i);
			printf("Now %s is NOT in your inventory.\n\n", tokens.buffer[1].string);
			break;
		}
		if (i == inventory.num_elements - 1) printf("Can't find %s in your inventory.\n\n", tokens.buffer[1].string);
	}
}

void Player::Equip(const Vector <String>& tokens)
{
	for (int i = 0; i < inventory.num_elements; i++)
	{
		if (tokens.buffer[1] == inventory.buffer[i]->name)
		{
			if (inventory.buffer[i]->equip == 0 && equip_item == nullptr)
			{
				inventory.buffer[i]->equip = 1;
				equip_item = inventory.buffer[i];
				printf("You equip %s.\n\n", tokens.buffer[1].string);
			}
			else if (equip_item != nullptr) printf("You only can equip 1 item.\n\n");
			else if (inventory.buffer[i]->equip == -1) printf("You own this item but can't be equipped.\n\n");
			else if (inventory.buffer[i]->equip == 1 && equip_item != nullptr) printf("This item is already equipped.\n\n");
			else if (i == inventory.num_elements - 1) printf("This item is NOT in your inventory so you can't equip it.\n\n");
			break;
		}
		else if (tokens.buffer[1] != inventory.buffer[i]->name && i == inventory.num_elements - 1) printf("Can't find this item.\n\n");
	}
	if (inventory.num_elements == 0) printf("Your inventory is empty.\n\n");
}

void Player::Unequip(const Vector <String>& tokens)
{
	for (int i = 0; i < inventory.num_elements; i++)
	{
		if ((tokens.buffer[1] == equip_item->name))
		{
			inventory.buffer[i]->equip = 0;
			equip_item = nullptr;
			printf("You unequip %s.\n\n", tokens.buffer[1].string);
			break;
		}
		else if (i == inventory.num_elements - 1) printf("You aren't wearing this item so you can't unequip it.\n\n");
	}
}

void Player::Door(const enum Status& door, const Vector<Entity*>& Entities)
{
	for (int i = 0; i < Entities.num_elements; i++)
	{
		for (int j = 0; j < Entities.num_elements; j++)
		{
			Entity* aux = Entities[i];
			Entity* aux2 = Entities[j];

			if (aux->type == PATH)
			{
				Path* p = (Path*)aux;

				if ((aux2->type == PATH) && (p->door != NO_DOOR) && (p->door != door))
				{
					Path* p2 = (Path*)aux2;

					if ((curr_pos == p->source) && (p->destination == p2->source) && (p2->destination == p->source))
					{
						p->door = door; p2->door = door;
						if (door == OPEN) Update(p);
						break;
					}
				}
			}
		}
	}
}

void Player::Update(const Path* p)
{
	curr_pos = p->destination;
	printf("%s. %s.\n\n", curr_pos->name.string, curr_pos->description.string);
}

void Player::Inventory(const Vector <String>& tokens) const
{
	if (inventory.num_elements == 0) printf("The inventory is empty.\n\n");
	else
	{
		printf("You have: ");
		for (int i = 0; i < inventory.num_elements; i++)
		{
			if (tokens.buffer[0] == "look") printf("\n   -%s (%s)", inventory.buffer[i]->name.string, inventory.buffer[i]->description.string);
			else
			{
				printf("%s", inventory.buffer[i]->name.string);
				if (i < inventory.num_elements - 1) printf(", ");
				else printf(".");
			}
		}
		printf("\n\n");
	}
}



		


