#include "Player.h"
#include "Path.h"
#include "Item.h"
#include "Room.h"

Player::Player(const char* name, const char* description, Room* room) :
Entity(name, description, PLAYER),
curr_pos(room)
{
	Vector<Item*> bag(INV_CAPACITY);	
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

			if ((i->picked == 0) && (i->name == tokens.buffer[1]) && (i->location == curr_pos))
			{
				if (bag.num_elements < INV_CAPACITY)
				{
					bag.pushback(i);
					printf("You put %s in your bag.\n\n", tokens.buffer[1]);
					i->picked = 1;

				}
				else printf("Your inventory is full.\n\n");
				break;
			}
			else if ((i->picked == 1) && (i->name == tokens.buffer[1]) && (i->location == curr_pos))
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
	for (int i = 0; i < bag.num_elements; i++)
	{
		if ((tokens.buffer[1] == bag.buffer[i]->name) && (bag.buffer[i]->picked == 1))
		{
			bag.buffer[i]->picked = 0;
			bag.buffer[i]->location = curr_pos;
			bag.pop(i);
			printf("Now %s is NOT in your inventory.\n\n", tokens.buffer[1].string);
			break;
		}
		if (i == bag.num_elements - 1) printf("Can't find %s in your inventory.\n\n", tokens.buffer[1].string);
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

void Player::LookBag() const
{
	if (bag.num_elements == 0) printf("Your bag is empty.\n\n");
	else
	{
		printf("In the bag you have: ");
		for (int i = 0; i < bag.num_elements; i++)
		{
			printf("\n   -%s (%s)", bag.buffer[i]->name.string, bag.buffer[i]->description.string);
		}
		printf("\n\n");
	}
}



		


