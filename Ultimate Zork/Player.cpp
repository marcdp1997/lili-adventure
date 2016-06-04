#include "Player.h"
#include "Path.h"
#include "Item.h"
#include "Room.h"

Player::Player(const char* name, const char* description, Room* creature_pos) : Creature(name, description, creature_pos, 10, 0, 1)
{
	type = PLAYER;
	inventory = new Vector<Item*>(INV_CAPACITY); // Add to the destructor?
}

Player::~Player()
{}

bool Player::Move(const Vector <String>& tokens, const Vector<Entity*>& Entities)
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
				if (p->door == OPEN) printf("The gates are open. You can close them if you want.\n");
				if ((p->door == NO_DOOR) || (p->door == OPEN))
				{
					curr_pos = p->destination;
					Update(Entities);
				}
				return true;
			}
		}
	}
	return false;
}

bool Player::Look(const Vector <String>& tokens, const Vector<Entity*>& Entities)
{
	if (tokens.buffer[1] == "room")
	{
		Update(Entities);
		return true;
	}

	for (int i = 0; i < Entities.num_elements; i++)
	{
		Entity* aux = Entities[i];

		if (aux->type == PATH)
		{
			Path* p = (Path*)aux;

			if ((curr_pos == p->source) && (tokens.buffer[1] == p->direction))
			{
				printf("%s. %s.\n\n", p->name.string, p->description.string);
				return true;
			}
		}
	}
	return false;
}

bool Player::Pick(const Vector <String>& tokens, const Vector<Entity*>& Entities)
{
	for (int i = 0; i < Entities.num_elements; i++)
	{
		Entity* aux = Entities[i];

		if (aux->type == ITEM)
		{
			Item* i = (Item*)aux;

			if ((i->name == tokens.buffer[1]) && (i->location == curr_pos))
			{
				if (i->pick) printf("You added this item before.\n\n");
				if (!i->pick && inventory->num_elements == INV_CAPACITY) printf("Your inventory is full.\n\n");
				if (!i->pick && inventory->num_elements < INV_CAPACITY)
				{
					inventory->pushback(i);
					printf("You add %s in your inventory.\n\n", tokens.buffer[1].string);
					i->pick = true;
				}
				return true;
			}
		}
	}
	return false;
}

bool Player::Drop(const Vector <String>& tokens, const Vector<Entity*>& Entities)
{
	for (int i = 0; i < inventory->num_elements; i++)
	{
		if ((tokens.buffer[1] == inventory->buffer[i]->name) && (inventory->buffer[i]->pick))
		{
			inventory->buffer[i]->pick = false;
			inventory->buffer[i]->pick2 = false;
			inventory->buffer[i]->location = curr_pos;
			inventory->pop(i);
			printf("Now %s is NOT in your inventory.\n\n", tokens.buffer[1].string);
			return true;
		}
	}
	return false;
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
						p->door = door; 
						p2->door = door;

						if (door == OPEN)
						{
							printf("You have opened the gates.\n");
							curr_pos = p->destination;
							Update(Entities); // If the door it's open, then we can update the position.
						}
						else printf("You have closed the gates.\n\n");
					}
				}
			}
		}
	}
}

bool Player::Equip(const Vector <String>& tokens)
{
	for (int i = 0; i < inventory->num_elements; i++)
	{
		if (tokens.buffer[1] == inventory->buffer[i]->name)
		{
			if (inventory->buffer[i]->subtype == 0)
			{
				if (shield != nullptr && tokens.buffer[1] == shield->name) printf("This item is already equipped.\n\n");
				if (shield != nullptr && tokens.buffer[1] != shield->name) printf("You only can equip 1 type of shield.\n\n");
				if (shield == nullptr)
				{
					shield = inventory->buffer[i];
					printf("You equip %s in the shield slot.\n\n", tokens.buffer[1].string);
				}
			}
			else if (inventory->buffer[i]->subtype == 1)
			{
				if (weapon != nullptr && tokens.buffer[1] == weapon->name) printf("This item is already equipped.\n\n");
				if (weapon != nullptr && tokens.buffer[1] != weapon->name) printf("You only can equip 1 type of weapon.\n\n");
				if (weapon == nullptr)
				{
					weapon = inventory->buffer[i];
					printf("You equip %s in the weapon slot.\n\n", tokens.buffer[1].string);
				}
			}
			else if (inventory->buffer[i]->subtype == 2)
			{
				if (armor != nullptr && tokens.buffer[1] == armor->name) printf("This item is already equipped.\n\n");
				if (armor != nullptr && tokens.buffer[1] != armor->name) printf("You only can equip 1 type of armor.\n\n");
				if (armor == nullptr)
				{
					armor = inventory->buffer[i];
					printf("You equip %s in the armor slot.\n\n", tokens.buffer[1].string);
				}
			}
			else printf("This item can't be equipped.\n\n");

			return true;
		}
	}
	return false;
}

bool Player::Unequip(const Vector <String>& tokens)
{
	if (shield != nullptr && tokens.buffer[1] == shield->name)
	{
		shield = nullptr;
		printf("You unequip %s.\n\n", tokens.buffer[1].string);
		return true;
	}
	if (weapon != nullptr && tokens.buffer[1] == weapon->name)
	{
		weapon = nullptr;
		printf("You unequip %s.\n\n", tokens.buffer[1].string);
		return true;
	}
	if (armor != nullptr && tokens.buffer[1] == armor->name)
	{
		armor = nullptr;
		printf("You unequip %s.\n\n", tokens.buffer[1].string);
		return true;
	}

	return false;
}

void Player::Inventory(const Vector <String>& tokens) const
{
	if (inventory->num_elements == 0) printf("The inventory is empty.\n\n");
	else
	{
		printf("In the intventory you have: ");
		for (int i = 0; i < inventory->num_elements; i++)
		{
			if (tokens.buffer[0] == "look") printf("\n   -%s (%s)", inventory->buffer[i]->name.string, inventory->buffer[i]->description.string);
			else
			{
				printf("%s", inventory->buffer[i]->name.string);
				if (i < inventory->num_elements - 1) printf(", ");
				else printf(".");
			}
		}
		printf("\n\n");
	}
}

bool Player::Bag() const
{
	for (int i = 0; i < inventory->num_elements; i++)
	{
		if (inventory->buffer[i]->name == "bag")
		{
			if (inventory->buffer[i]->inventory->num_elements == 0) printf("Bag empty.");
			else
			{
				printf("In the bag you have: ");
				for (int j = 0; j < inventory->buffer[i]->inventory->num_elements; j++)
				{
					printf("%s", inventory->buffer[i]->inventory->buffer[j]->name.string);
					if (j < inventory->buffer[i]->inventory->num_elements - 1) printf(", ");
					else printf(".");
				}
			}
			printf("\n\n"); return true;
		}
	}
	return false;
}

bool Player::TurnOnGPS(const Vector<Entity*>& Entities) const
{
	for (int i = 0; i < inventory->num_elements; i++)
	{
		if (inventory->buffer[i]->name == "gps")
		{
			printf("The GPS is going to show you the name and desc of the rooms connected with this:");

			for (int j = 0; j < Entities.num_elements; j++)
			{
				Entity* aux = Entities[j];

				if (aux->type == PATH)
				{
					Path* p = (Path*)aux;

					if (p->source == curr_pos && p->direction == "north")
						printf(" - To the north: %s. %s.\n", p->destination->name.string, p->destination->description.string);
					if (p->source == curr_pos && p->direction == "south")
						printf(" - To the south: %s. %s.\n", p->destination->name.string, p->destination->description.string);
					if (p->source == curr_pos && p->direction == "east")
						printf(" - To the east: %s. %s.\n", p->destination->name.string, p->destination->description.string);
					if (p->source == curr_pos && p->direction == "west")
						printf(" - To the west: %s. %s.\n", p->destination->name.string, p->destination->description.string);
				}
			}
			return true;
		}
	}
	printf("\n\n"); return false;
}

bool Player::PutInto(const Vector <String>& tokens)
{
	for (int i = 0; i < inventory->num_elements; i++)
	{
		if (tokens.buffer[3] == inventory->buffer[i]->name && inventory->buffer[i]->inventory != nullptr)
		{
			for (int j = 0; j < inventory->num_elements; j++)
			{
				if (tokens.buffer[1] == inventory->buffer[j]->name)
				{
					if ((inventory->buffer[j]->pick2) && (inventory->buffer[i]->inventory->num_elements < MAX_ITEMS)) printf("You put %s into %s before.\n\n", tokens.buffer[1].string, tokens.buffer[3].string);
					if ((inventory->buffer[j]->pick2) && (inventory->buffer[i]->inventory->num_elements == MAX_ITEMS)) printf("Your %s is full.\n\n", tokens.buffer[3].string);
					if ((!inventory->buffer[j]->pick2) && (inventory->buffer[i]->inventory->num_elements < MAX_ITEMS))
					{
						inventory->buffer[i]->inventory->pushback(inventory->buffer[j]);
						inventory->buffer[j]->pick2 = 1;
						printf("You put %s into %s.\n\n", tokens.buffer[1].string, tokens.buffer[3].string);
					}
					return true;
				}
			}
		}
	}
	return false;
}

bool Player::GetFrom(const Vector <String>& tokens)
{
	for (int i = 0; i < inventory->num_elements; i++)
	{
		if (tokens.buffer[3] == inventory->buffer[i]->name && inventory->buffer[i]->inventory != nullptr)
		{
			for (int j = 0; j < inventory->buffer[i]->inventory->num_elements; j++)
			{
				if (tokens.buffer[1] == inventory->buffer[i]->inventory->buffer[j]->name)
				{
					if (inventory->buffer[j]->pick2) printf("You get %s from %s before.\n\n", tokens.buffer[1].string, tokens.buffer[3].string);
					if (inventory->buffer[i]->inventory->num_elements == 0) printf("Nothing is inside %s.\n\n", tokens.buffer[3].string);
					if (inventory->buffer[i]->inventory->buffer[j]->pick2)
					{
						inventory->buffer[i]->inventory->buffer[j]->pick2 = 0;
						inventory->buffer[i]->inventory->pop(j);
						printf("You get %s from %s.\n\n", tokens.buffer[1].string, tokens.buffer[3].string);
					}
					return true;
				}
			}
		}
	}
	return false;
}

void Player::Update(const Vector<Entity*>& Entities)
{
	printf("%s. %s.", curr_pos->name.string, curr_pos->description.string);

	for (int i = 0; i < Entities.num_elements; i++)
	{
		Entity* aux = Entities[i];

		if (aux->type == ITEM)
		{
			Item* i = (Item*)aux;

			if (i->location == curr_pos) printf("\nThere is a %s in this area.", i->name.string);
		}
	}
	printf("\n\n");
}

bool Player::CheckDoor(const Vector<Entity*>& Entities) const
{
	for (int i = 0; i < Entities.num_elements; i++)
	{
		Entity* aux = Entities[i];

		if (aux->type == PATH)
		{
			Path* p = (Path*)aux;

			if (p->source == curr_pos && p->door != NO_DOOR)
				return true;
		}
	}
	return false;
}





		


