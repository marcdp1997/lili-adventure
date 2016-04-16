#include "Player.h"
#include "Path.h"
#include "Item.h"

Player::Player(const char* name, const char* description, Room* room) :
Entity(name, description, PLAYER),
curr_pos(room)
{
	Vector<Item*> bag(INV_CAPACITY);	
}

Player::~Player()
{}

void Player::Move(const String& command, const Vector<Entity*>& Entities)
{
	for (int i = 0; i < Entities.num_elements; i++)
	{
		Entity* aux = Entities[i];

		if (aux->type == PATH)
		{
			Path* p = (Path*)aux;
			
			if ((curr_pos == p->source) && (command == p->direction))
			{
				if ((p->door == NO_DOOR) || (p->door == OPEN)) curr_pos = p->destination;
				else if (p->door == CLOSE) printf("The gates are close. Open them to move forward.\n\n");
				if (p->door == OPEN) printf("The gates are open. You can close them if you want.\n\n");
				break;
			}
		}
		else if (i == Entities.num_elements - 1) printf("You can't go there.\n\n");
	}
}

void Player::LookPath(const String& command, const Vector<Entity*>& Entities)
{
	for (int i = 0; i < Entities.num_elements; i++)
	{
		Entity* aux = Entities[i];

		if (aux->type == PATH)
		{
			Path* p = (Path*)aux;

			if ((curr_pos == p->source) && (command == p->direction))
			{
				printf("%s. %s.\n\n", p->name.string, p->description.string);
				break;
			}
		}
		else if (i == Entities.num_elements - 1) printf("There isn't a path to look at.\n\n");
	}
}

void Player::Pick(const String& command, const Vector<Entity*>& Entities)
{
	for (int i = 0; i < Entities.num_elements; i++)
	{
		Entity* aux = Entities[i];

		if (aux->type == ITEM)
		{
			Item* i = (Item*)aux;

			if ((i->picked == 0) && (command == i->name) && (i->location == curr_pos))
			{
				if (bag.num_elements < INV_CAPACITY)
				{
					bag.pushback(i);
					printf("You put %s in your bag.\n\n", command.string);
					i->picked = 1;
				}
				else printf("Your inventory is full.\n\n");
				break;
			}
		}
		else if (i == Entities.num_elements - 1) printf("No item found.\n\n");
	}
}

void Player::Drop(const String& command, const Vector<Entity*>& Entities)
{
	for (int i = 0; i < Entities.num_elements; i++)
	{
		// If name of the item that is in the vector == command && picked == 1
		// bag.pop(i)

		if (i == Entities.num_elements - 1) printf("%s is not in your inventory\n\n", command.string);
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
						if (door == OPEN) curr_pos = p->destination;
						break;
					}
				}
			}
		}
	}
}



		


