#ifndef PLAYER_H
#define PLAYER_H

#define INV_CAPACITY 4

#include "Entity.h"

class Room;
class Item;
class Path;

class Player : public Entity
{
public:
	Room* curr_pos;
	Item* equip_item = nullptr; // Item equipped

public: 
	Player(const char* name, const char* description, Room* curr_pos);
	virtual ~Player();

	bool Move(const Vector <String>& tokens, const Vector<Entity*>& Entities);
	bool Look(const Vector <String>& tokens, const Vector<Entity*>& Entities);
	bool Pick(const Vector <String>& tokens, const Vector<Entity*>& Entities);
	bool Drop(const Vector <String>& tokens, const Vector<Entity*>& Entities);
	bool Equip(const Vector <String>& tokens);
	bool Unequip(const Vector <String>& tokens);
	void Door(const enum Status& door, const Vector<Entity*>& Entities);
	void Inventory(const Vector <String>& tokens) const;
	bool Bag() const;
	bool PutInto(const Vector <String>& tokens);
	bool GetFrom(const Vector <String>& tokens);
	bool TurnOnGPS(const Vector<Entity*>& Entities) const;
	void Update(const Vector<Entity*>& Entities);
};

#endif