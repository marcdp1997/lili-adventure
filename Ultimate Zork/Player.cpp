#include "Player.h"
#include "Path.h"

Player::Player(const char* name, const char* description, Room* curr_pos) :
Entity(name, description, PLAYER),
curr_pos(curr_pos)
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
				}
				//else p.CheckDoor(p[i]);
				break;
			}
		}
		else if (i == Entities.num_elements - 1) printf("You can't go there.\n\n");
	}
}