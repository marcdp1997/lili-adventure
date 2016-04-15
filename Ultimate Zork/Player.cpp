#include "Player.h"
#include "Path.h"
#include "Item.h"

Player::Player(const char* name, const char* description, Room* room) :
Entity(name, description, PLAYER),
curr_pos(room)
{}

Player::~Player()
{}

void Player::Move(String& command, const Vector<Entity*>& Entities)
{
	for (int i = 0; i < Entities.num_elements; i++)
	{
		Entity* aux = Entities[i];

		if (aux->type == PATH)
		{
			Path* p = (Path*)aux;
			
			if ((curr_pos == p->source) && (command == p->direction))
			{
				if (p->door == NO_DOOR)
				{
					curr_pos = p->destination;
					//printf("%s. %s." curr_pos->name, curr_pos.string->description.string) 
				}
				//else p.CheckDoor(p[i]);
				break;
			}
		}
		else if (i == Entities.num_elements - 1) printf("You can't go there.\n\n");
	}
}


void Player::LookPath(String& command, const Vector<Entity*>& Entities)
{
	for (int i = 0; i < Entities.num_elements; i++)
	{
		Entity* aux = Entities[i];

		if (aux->type == PATH)
		{
			Path* p = (Path*)aux;

			if ((curr_pos == p->source) && (command == p->direction))
			{
				printf("%s.\n\n", p->description.string);
				break;
			}
		}
		else if (i == Entities.num_elements - 1) printf("There isn't a path to look at.\n\n");
	}
}


void Player::Pick(String& command, const Vector<Entity*>& Entities)
{
	for (int i = 0; i < Entities.num_elements; i++)
	{
		Entity* aux = Entities[i];

		if (aux->type == ITEM)
		{
			Item* i = (Item*)aux;

			if ((last_item < INV_CAPACITY) && (command == i->name))
			{
				//inventory[last_item] = i;
				last_item++;
				printf("%s is added to your inventory.\n\n", i->name.string);
				i->picked = 1;
			}
			else printf("Your inventory is full.\n\n");
			break;
		}
		else if (i == Entities.num_elements - 1) printf("No item found.\n\n");
	}
}